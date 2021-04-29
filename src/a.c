#include "Activity1.h"
#include "Activity2.h"                 // including all the header files within the same source directory
#include "a.h"


void set_PWM(void)
{
    DDRB |= (1<<PWM_PORT);           // To set B1 port as PWM Output for Timer1
    TCCR1A |= (1<<COM1A1) | (1<<WGM11) | (1<<WGM10);     
    TCCR1B |= (1<<WGM12)| (1<<CS11) | (1<<CS10);
}

void out_PWM(uint16_t adc_val)
{
    if((adc_val>=0) && (adc_val<=209))
    {

        OCR1A = 205; //20% duty cycle
        
    }
    else if((adc_val>=210) && (adc_val<=509))
    {

        OCR1A = 410; //40% duty cycle
        
    }
    else if((adc_val>=510) && (adc_val<=709))
    {

        OCR1A = 717;//70% duty cycle
        
    }
    else if((adc_val>=710) && (adc_val<=1024))
    {

        OCR1A = 973; //95% duty cycle
  
    }
    else
    {
        OCR1A = 0; //0% output
    }
}

void UART_init()
{
    value=BAUD_RATE;
    UBRR0H =(value>>8)&0x0ff;                         //setting Baud rate
    UBRR0L = value;
    UCSR0C=(1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ00);    
    //Enable reciever and transmitter
    UCSR0B=(1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);

                                                                                
}

char UART_READ()
{
    
    while(!(UCSR0A & (1<<RXC0)))                              //standby for incoming data
    {
        
    }
    return UDR0;
}

void UART_WRITE(char data)                                     // standalone, useless loops
{
    while(!(UCSR0A & (1<<UDRE0)))
    {
        
    }
    UDR0=data;

}
