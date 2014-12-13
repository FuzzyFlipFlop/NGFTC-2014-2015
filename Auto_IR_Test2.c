#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Sensor, S1,     hi,             sensorI2CMuxController)
#pragma config(Sensor, S2,     liftFront,      sensorTouch)
#pragma config(Sensor, S3,     liftBack,       sensorTouch)
#pragma config(Sensor, S4,     HTIRS2,         sensorI2CCustom)
#pragma config(Motor,  motorA,          r,             tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          l,             tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          arm,           tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     right,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     left,          tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     lift,          tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C3_1,    servo1,               tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C3_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "hitechnic-irseeker-v2.h"

const float ticksCm = 1440.0/27.0;
const float ticksDg = 2000.0/90.0;
//const float ticksDg = 1450.0/90.0;
const float powerDif = 0.855;

//Drive forward number of cm's
void drive(float cm, float power) //Distance, Power
{
	long ticks = cm*ticksCm;
	nMotorEncoder[left]=0;
	while(abs (nMotorEncoder[left]) < ticks)
		{
			motor[left]=power;
			motor[right]=power*powerDif;
		}
	motor[left]=0;
	motor[right]=0;
	wait10Msec(10);
}

//Turn number of degrees
void turn(float deg, float power) //Degrees, Power (positive is right turn)
{
	long ticks = deg*ticksDg;
	nMotorEncoder[left]=0;
	while(abs (nMotorEncoder[left]) < ticks)
		{
			motor[left]=power;
			motor[right]=-power*powerDif;
		}
	motor[left]=0;
	motor[right]=0;
	wait10Msec(10);
}


void raiseLift(float tm, float power)
{
	motor[lift]=power;
	wait1Msec(tm);
	motor[lift]=0;
}

void resetLift()
{
	while(SensorValue[liftBack] == 0)
		{
			motor[lift]=-10;
		}
	motor[lift]=0;
}
//---------

task main()
{
	int _dirAC = 0;//Resets IR

	drive(50,20);
	turn(90,20);
	drive(100,20);
	turn(90,-20);
	drive(80,20);
	turn(90,20);//Turns left
	turn(90,20);
	turn(100,20);
	drive(62,20);//Drives Backwards

	wait1Msec(1000);
	_dirAC = HTIRS2readACDir(HTIRS2);//waits for 0.5 a second then reads IR

	if(_dirAC<9 && _dirAC>6)//If beacon is facing robot
		{
			drive(60,-20);//Drives Backwards
			turn(80,20);//Turns right
			drive(20,20);//Drives Forward
			turn(35,35);//Knocks pole down by turning
		}
	if(_dirAC<7 && _dirAC>4)//If beacon is facing the corner
		{
			drive(50,-20);//Drives Backwards
			turn(80,20);//Turns right
			drive(5,20);//Drives Forward
			turn(45,35);//Knocks pole down by turning
			drive(35,-75);
		}
	if(_dirAC==9 || _dirAC==0)//If pole is facing robot
		{
			drive(60,-20);//Drives Forward
			turn(25,20);//Turns right
			drive(35,20);//Drives Forward
			turn(50,-50);//Turns right
		}
	string t;
	//while(true)
	//	{
	//		_dirAC = HTIRS2readACDir(HTIRS2);

	//		StringFormat( t, "Sensor Value: %i", _dirAC);
	//		//string t = "Sensor Value:" + _dirAC;
	//		nxtDisplayTextLine(1, t);
	//	}


	//	wait10Msec(100);

}
