/*
 * stepper_motor.h
 *
 * Created: 12/9/2023 11:40:17 AM
 *  Author: EECE
 */ 


#ifndef STEPPER MOTOR_H_
#define STEPPER MOTOR_H_

#include "stepper motor.h"
#define step_angle 7.5
#define degree_to_full_step(degree) (degree/step_angle)
#define iterator(degree) (degree/step_angle)/4
#define half_step_choice 1
#define full_step_choice 2
#define clock_wise_direction  5
#define anti_clockwise_direction 6
#define  full_step_anti_clock_wise  g
#define half_step_anti_clock_wise    h
#define half_step_clock_wise      j
#define full_step_clock_wise      k
//#define cw 1
//#define ccw 2
void stepper_motor_initialization();
void stepper_motor_operation(u8 angle_value,u8 step_type_choice,u8 direction);
u8 g[4]={0x03,0x06,0x0c,0x09};
u8 h[8]={0x01,0x03,0x02,0x06,0x04,0x0c,0x08,0x09};
u8 j[8]={0x08,0x0c,0x04,0x06,0x02,0x03,0x01,0x09};
u8 k[4]={0x0c,0x06,0x03,0x09};

#endif /* STEPPER MOTOR_H_ */