#ifndef _MAIN_h_
#define _MAIN_h_
/**
 * @file main.h
 * @author Vikram Vasudev
 * @brief 
 * @version 0.1
 * @date 2021-04-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * @brief Function to set the PWM output
 * 
 */
void set_PWM();

uint16_t value;
/**
 * @brief function to initialise UART registers in asynchronous mode
 * 
 */

void UART_init();
/**
 * @brief function to read the recieved data from the UART buffer
 * 
 * @return char 
 */

char UART_READ();
/**
 * @brief function to transmit the data and write data to the UART buffer
 * 
 * @param data 
 */
void UART_WRITE(char data);
#endif
