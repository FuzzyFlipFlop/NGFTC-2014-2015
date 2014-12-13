#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
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
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while(SensorValue[liftBack] == 0)//Runs while back botton is not pressed
		{
			motor[lift]=-10;//Turns on motor
		}
	motor[lift]=0;//Turns off motor
}
