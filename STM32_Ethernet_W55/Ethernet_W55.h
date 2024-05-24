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
 * @file      : Ethernet_W55.h
 ********************************************************************************************************************/
#include "Arduino.h"

#ifndef _Ethernet_W55_H_
#define _Ethernet_W55_H_

#define ETH_CS_PIN PA4
#define ETH_RST_PIN PB0
#define PHYCFGR 0x002E

bool EthernetInit(void);
/**
 * @details: This function will initialise the w5500 ethernet controller.
 * @param  : none
 * @returns: none
 */

bool linkstatus(void);
/**
 * @details: This function check the Ethernet cable Physically connected or not
 * @param  : none
 * @returns: bool indicating true if cable is connected and false if not.
 */

#endif
