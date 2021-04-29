#include "Activity1.h"
#include "Activity2.h" 
#include "main.h"                     //including all the source files within the same directory


void Init_adc()
{
    ADMUX |=(1<<REFS0);                   // Selecting Channel 0 using ADMUX register and internerally connecting Aref and AVCC
    ADCSRA |= (1<<ADEN) | (7<<ADPS0);     // To Enabe ADC and initializing the sample frequency

}


uint16_t Get_ADC(uint8_t channel )
{
    ADMUX &= 0xF8;                            // set 1 to all ADMUX register except pins 0,1,2.
    channel= channel & 0b00000111;           // Logically AND'ing with 0b00000111 will give the channel itself.
    ADMUX |= channel;                          // selecting the channel by ORing  with ADMUX
    ADCSRA |= (1<<ADSC);
    while(!(ADCSRA & (1<<ADIF)));
    ADCSRA |=(1<<ADIF);
    return(ADC);
}
