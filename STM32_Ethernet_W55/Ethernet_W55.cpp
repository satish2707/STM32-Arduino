/*******************************************************************************************************************
 * @details   : Contains the Ethernet Driver functionality.
 *
 * @authors   : Satish Kanawade (Embedded Software Developer)
 *
 * @copyright : Embedlogiclancer
 *
 * @date      : 24 JMAY 2024
 *
 * @version   : V1.0
 *
 * @file      : Ethernet_W55.cpp
 ********************************************************************************************************************/
#include "Ethernet_W55.h"
#include <Ethernet2.h>

extern HardwareSerial Mydebug;

extern W5500Class w5500;

// Define the Ethernet MAC-ID Here
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// Global variable to store previous link status
bool previousLinkStatus = false;

// Function to check the Ethernet cable physical connection status
bool linkstatus() {
  uint8_t phyCFGR = w5500.getPHYCFGR();
  bool currentLinkStatus = (phyCFGR & 0x01) == 0x01;

  // Print cable status only if it changes
  if (currentLinkStatus != previousLinkStatus) {
    if (currentLinkStatus) {
      Mydebug.println("Ethernet cable is connected.");
    } else {
      Mydebug.println("Ethernet cable is not connected.");
    }
    previousLinkStatus = currentLinkStatus;
  }
  return currentLinkStatus;
}


// Initialize Ethernet Using DHCP
bool EthernetInit() {
  Ethernet.init(ETH_CS_PIN);
  digitalWrite(ETH_RST_PIN, LOW);
  delay(1000);
  digitalWrite(ETH_RST_PIN, HIGH);

  Mydebug.println("Initializing Ethernet using DHCP..");
  if (Ethernet.begin(mac) == 0) {
    Mydebug.println("Failed to configure Ethernet using DHCP");
    return false;
  }
  Mydebug.println("Ethernet DHCP OK.");
  delay(1000);
  Mydebug.print("Local IP    : ");
  Mydebug.println(Ethernet.localIP());
  Mydebug.print("Subnet Mask : ");
  Mydebug.println(Ethernet.subnetMask());
  Mydebug.print("Gateway IP  : ");
  Mydebug.println(Ethernet.gatewayIP());
  Mydebug.print("DNS Server  : ");
  Mydebug.println(Ethernet.dnsServerIP());
  Mydebug.println("Ethernet Successfully Initialized");
  return true;
}