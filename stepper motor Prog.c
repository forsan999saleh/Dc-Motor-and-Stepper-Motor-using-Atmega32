/*
 * stepper_motor_Prog.c
 *
 * Created: 12/9/2023 11:40:39 AM
 *  Author: EECE
 */ 
#include "../../MCAL/DIO_int.h"
#include "../../Library/BIT_MATH.h"
#include "../../Library/TYPES.h"
#include "stepper motor.h"
#include <util/delay.h>
//u8 stepper_motor_array[8]={0x08,0x0c,0x04,0x06,0x02,0x03,0x01,0x09};
	void stepper_motor_initialization()
	{
		DIO_voidSetPortDir(DIO_PORTD,DIO_PORT_OUTPUT);
	}
	void stepper_motor_operation(u8 angle_value,u8 step_type_choice,u8 direction)
	{
		switch(step_type_choice)
		{
			case half_step_choice:
						switch(direction)
						{ 
							case clock_wise_direction:
							{
								for(u8 counter=0;counter<iterator(angle_value);counter++)
								{
									DIO_voidSetPortVal(DIO_PORTD,half_step_clock_wise[counter]);
								}	
									break;
							}
				
							case anti_clockwise_direction:
							{
								for(u8 counter=0;counter<iterator(angle_value);counter++)
								{
									DIO_voidSetPortVal(DIO_PORTD,half_step_anti_clock_wise[counter]);
								}
								break;
							}
				
				
						}
				break;
			
			case full_step_choice:
			switch(direction)
			{
							case clock_wise_direction:
							{
								for(u8 counter=0;counter<iterator(angle_value);counter++)
								{
									DIO_voidSetPortVal(DIO_PORTD,full_step_clock_wise[counter]);
								}
								break;
							}
				
							case anti_clockwise_direction:
							{
								for(u8 counter=0;counter<iterator(angle_value);counter++)
								{
									DIO_voidSetPortVal(DIO_PORTD,full_step_anti_clock_wise[counter]);
								}
								break;
							}
				
				
				}
				break;
			
			}
		
		
	}