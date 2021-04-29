#include "Activity1.h"
#include "Activity2.h"                 // including all the header files within the same source directory
#include "a.h"


void set_PWM(void)
{
    DDRB |= (1<<PWM_PORT);           // To set B1 port as PWM Output for Timer1
    TCCR1A |= (1<<COM1A1) | (1<<WGM11) | (1<<WGM10);     
    TCCR1B |= (1<<WGM12)| (1<<CS11) | (1<<CS10);
     UCSR0B=(1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);
}

void UART_init()
{
    value=BAUD_RATE;
    UBRR0H =(value>>8)&0x0ff;                         //setting Baud rate
    UBRR0L = value;
    UCSR0C=(1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ00);    //Enable reciever and transmitter

                                                                                
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
