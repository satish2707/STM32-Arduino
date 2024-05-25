/**************************************************************************************************
 * @file: E_FTP.h
 *
 * @author: Satish Kanawade
 *
 * @brief: This file contains the Watchdog functionality of the project.
 *
 * @copyright: Emprotek Software Solutions Pvt Ltd 2023.
 *
 *************************************************************************************************/

#ifndef _E_WATCHDOG_H_
#define _E_WATCHDOG_H_

void Watchdog_init();
/**
 * @details: Enable Watchdog for the desired duration in milliseconds.
 * @param: None.
 * @returns: None.
 */

void Reload_Watchdog();
/**
 * @details: This Function Reload the watchdog in Given Duration
 * @param: None.
 * @returns: None.
 */

#endif