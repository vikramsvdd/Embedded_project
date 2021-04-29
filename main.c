#include "activity1.h"
#include "activity2.h"                    //including the header files within the same directory
#include "a.h"


int main()
{
    uint16_t temp=0;
    unsigned int duty;

  perpheral_io();                         // Peripherals and IO pin configurations setup function
  Init_adc();                              //  ADC registers initialization function
  set_PWM();                               //PWM output function
  UART_init();                             // UART registers initialization function
    while(1)
    {
if((!(BUTTON_STATUS & (1<<BUTTON_PIN))) && (!(HEATER_STATUS & (1<<HEATER_PIN))))// if 1 1 situation arises, LED will glow!
        {
            LED_ON();                                                                     // Turning  ON the LED
            temp=Get_ADC(0); 
            UART_READ(temp);                                                         //Reading the Temp value from UART buffer
            UART_WRITE(temp);                                                     // Writing the Temp value to the UART buffer
             for(duty=0;duty<1024;duty++) {
              OCR1A=duty;
          }
}
        else 
        {
           LED_OFF();                                      //save light when not needed :)
        }
    }
    return 0;
}
