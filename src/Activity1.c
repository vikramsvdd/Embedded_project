#include "Activity1.h"
#include "Activity2.h"                        // including all the header files within the same source directory


void LED_ON()
{
	LED_PORT |= (1<<LED_PIN);
}
void LED_OFF()
{
	LED_PORT &= ~(1<<LED_PIN);
}
void Peripheral_io(void)
{
  DDRD |= (1<<LED_PIN);                      // to set D port as output for led
  DDRC &= ~(1<<HEATER_PIN);                  // to set C port as the input for heater button
  DDRB &= ~(1<<BUTTON_PIN);                   //to set B port as input to check whether a passenger is present or not
  HEATER_PORT |= (1<<HEATER_PIN);
  BUTTON_PORT |= (1<<BUTTON_PIN);
}
