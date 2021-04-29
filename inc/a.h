#ifndef _A_h_
#define _A_h_
/**
 * @file a.h
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
#define PWM_PORT (PB1)
/**
 * @brief Function to set PWM o/p
 *
 */
void set_PWM();

/**
 * @brief Function to give PWM o/p
 *
 */
void out_PWM(uint16_t adc_val);

/**
 * @brief MACROS and global variables in usage throughout this project
 *
 */


#define BAUD 9600 //Baud Rate
#define F_CPU 16000000UL
#define BAUD_RATE ((F_CPU)/(BAUD*16UL)-1)

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
