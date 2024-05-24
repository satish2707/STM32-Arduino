/*******************************************************************************************************************
 * @details   : This sketch demonstrates how to connect an Arduino board with W5500 Ethernet shield to a MQTT broker
 *              and subscribe to a topic.
 *
 * @authors   : Satish Kanawade (Embedded Software Developer)
 *
 * @copyright : Embedlogiclancer
 *
 * @date      : 08 NOV 2023
 *
 * @version   : V1.0
 *
 * @file      : MQTT_Ethernet_STM32.ino
 ********************************************************************************************************************/
#include <Ethernet2.h>
#include <MQTTPubSubClient.h>

// MAC address for Ethernet shield
uint8_t mac[] = { 0xAB, 0xCD, 0xEF, 0x01, 0x23, 0x45 };

// Hardware serial for debugging
HardwareSerial myDebug(USART1);

// Ethernet client and MQTT client objects
EthernetClient Ethernet_Client_MQTT_Obj;
MQTTPubSubClient MQTT_Driver;

// MQTT broker parameters
#define MQTT_Server_Hostname "110.110.120.40"
#define MQTT_Server_PORT 1883
#define MQTT_Server_Topic "100002"
#define MQTT_Server_UserName "admin"
#define MQTT_Server_Password "123456"
#define MQTT_Server_ClientID MQTT_Server_Topic

// Function to connect to MQTT broker
void connect() {
connect_to_host:
  myDebug.print("Connecting to host...");
  Ethernet_Client_MQTT_Obj.stop();
  
  // Keep trying to connect to host until successful
  while (!Ethernet_Client_MQTT_Obj.connect(MQTT_Server_Hostname, MQTT_Server_PORT)) {
    myDebug.print(".");
    delay(1000);
  }
  myDebug.println(" Connected to host!");

  myDebug.print("Connecting to MQTT broker...");
  MQTT_Driver.disconnect();
  
  // Keep trying to connect to MQTT broker until successful
  while (!MQTT_Driver.connect(MQTT_Server_ClientID, MQTT_Server_UserName, MQTT_Server_Password)) {
    myDebug.print(".");
    delay(1000);
    
    // If Ethernet gets disconnected, reconnect to host
    if (Ethernet_Client_MQTT_Obj.connected() != 1) {
      myDebug.println("Ethernet disconnected");
      goto connect_to_host;
    }
  }
  myDebug.println(" Connected to MQTT broker!");
}

// Function to set up MQTT subscription
void mqtt_setup() {
  MQTT_Driver.begin(Ethernet_Client_MQTT_Obj);

  // Subscribe to all topics
  MQTT_Driver.subscribe([](const String& topic, const String& payload, const size_t size) {
    myDebug.println("MQTT received from topic: " + topic + " - " + payload);
  });

  // Subscribe to specific topic
  MQTT_Driver.subscribe(MQTT_Server_Topic, [](const String& payload, const size_t size) {
    myDebug.print("\r\n[Received from Correct Topic]:\r\n");
    myDebug.println(payload);
  });

  // Connect to MQTT broker
  connect();
}

// Function to handle MQTT connection and message reception
void mqtt_loop() {
  MQTT_Driver.update();
  
  // Reconnect if MQTT connection is lost
  if (!MQTT_Driver.isConnected()) {
    connect();
  }
}

void setup() {
  // Start serial communication for debugging
  myDebug.begin(115200);

  // Initialize Ethernet connection
  Ethernet.begin(mac);

  // Set up MQTT connection
  mqtt_setup();
}

void loop() {
  // Maintain MQTT connection and handle messages
  mqtt_loop();
}
