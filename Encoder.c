#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     mtrLeft,       tmotorMatrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     mtrRight,      tmotorMatrix, openLoop)
#pragma config(Servo,  srvo_S1_C2_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

const float ticksCm = 1440.0/27.0;
const float ticksDg = 1440.0/90.0;

//Drive forward number of cm's
void driveDistance(float cm, float LPower, float RPower) //Distance, Left wheel power, Right wheel power
{
	long ticks = cm*ticksCm;
	nMotorEncoder[mtrLeft]=0;
	while(abs (nMotorEncoder[mtrLeft]) < ticks)
		{
			motor[mtrLeft]=LPower;
			motor[mtrRight]=RPower;
		}
	motor[mtrLeft]=0;
	motor[mtrRight]=0;
}

//Turn number of degrees
void turn(float deg, float power) //Degrees, Power (positive is right turn)
{
	long ticks = deg*ticksDg;
	nMotorEncoder[mtrLeft]=0;
	while(abs (nMotorEncoder[mtrLeft]) < ticks)
		{
			motor[mtrLeft]=power;
			motor[mtrRight]=-power;
		}
	motor[mtrLeft]=0;
	motor[mtrRight]=0;
}

task main()
{
driveDistance(200,25,25);
}
