// #include to run pragma configs and have access to function motorRun that makes motors easier to use

#pragma config(Hubs, S1, HTMotor, none, none, none)
#pragma config(Motor, motorA, r, tmotorNXT, PIDControl, encoder)
#pragma config(Motor, motorB, l, tmotorNXT, PIDControl, encoder)
#pragma config(Motor, motorC, arm, tmotorNXT, PIDControl, encoder)
#pragma config(Motor, mtr_S1_C1_1, right, tmotorTetrix, openLoop, reversed)
#pragma config(Motor, mtr_S1_C1_2, left, tmotorTetrix, openLoop)

void motorRun(string motorIn, float powerIn, float millisecondsIn){
	motor[motorIn] = powerIn;
	wait1Msec(millisecondsIn);
	motor[motorIn] = 0;
}
