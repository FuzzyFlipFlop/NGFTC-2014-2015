#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     hi,             sensorI2CMuxController)
#pragma config(Sensor, S2,     modeButton,     sensorTouch)
#pragma config(Sensor, S3,     IR,             sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S4,     sonar,          sensorSONAR)
#pragma config(Motor,  motorA,          r,             tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          l,             tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          arm,           tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     left,          tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     right,         tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

const float ticksCm = 1440.0/27.0;
const float ticksDg = 1625.0/90.0;
const float powerDif = 0.85;

//Drive forward number of cm's
void driveDistance(float cm, float power) //Distance, Power
{
	long ticks = cm*ticksCm;
	nMotorEncoder[mtrLeft]=0;
	while(abs (nMotorEncoder[mtrLeft]) < ticks)
		{
			motor[mtrLeft]=power;
			motor[mtrRight]=power*powerDif;
		}
	motor[mtrLeft]=0;
	motor[mtrRight]=0;
	wait10Msec(10);
}

//Turn number of degrees
void turn(float deg, float power) //Degrees, Power (positive is right turn)
{
	long ticks = deg*ticksDg;
	nMotorEncoder[mtrLeft]=0;
	while(abs (nMotorEncoder[mtrLeft]) < ticks)
		{
			motor[mtrLeft]=power;
			motor[mtrRight]=-power*powerDif;
		}
	motor[mtrLeft]=0;
	motor[mtrRight]=0;
	wait10Msec(10);
}



//---------


task main()
{

	driveDistance(180,20);

}
