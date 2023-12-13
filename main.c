/*
 * main.c
 *
 * Created: 12/9/2023 11:35:21 AM
 *  Author: EECE
 */ 
#include "MCAL/External Interrupts/external interrupts initilalizations.h"
#include "MCAL/General Interrups/Initialization.h"
#include <util/delay.h>
#include "HAL/DC MOTOR/DC MOTOR.h"
#include "HAL/STEPPER MOTOR/stepper motor.h"

int main(void)
{
	 dc_motor_initialization();
	 stepper_motor_initialization();
	 general_interrupt_enable();
	 external_interrupt_enable(external_interrupt0);
	 DIO_voidSetPinDir(DIO_PORTD,DIO_PIN2,DIO_PIN_INPUT);
	 DIO_voidSetPinVal(DIO_PORTD,DIO_PIN2,DIO_HIGH);
	DIO_voidSetPinDir(DIO_PORTA,DIO_PIN0,DIO_PIN_OUTPUT);//led  pin as output
    while(1)
    {
       dc_motor_operation(clock_wise_direction_dc);
	   _delay_ms(5*Delay_Time);
	   dc_motor_operation(anti_clockwise_direction_dc);
	    _delay_ms(5*Delay_Time);
	    stepper_motor_operation(360,full_step_choice,anti_clockwise_direction);
		_delay_ms(5*Delay_Time);
		stepper_motor_operation(180,half_step_choice,clock_wise_direction);
		 _delay_ms(5*Delay_Time);
		 

    }
	return 0;
}
/*
ISR (INT0_vect)
{
	
	
		DIO_toggle_PinVal(DIO_PORTB,DIO_PIN0,DIO_PIN_OUTPUT);//turn off led
	
	
	
	
}
*/