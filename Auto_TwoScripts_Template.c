#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     hi,             sensorI2CMuxController)
#pragma config(Sensor, S2,     modeButton,     sensorTouch)
#pragma config(Sensor, S3,     light,          sensorLightActive)
#pragma config(Sensor, S4,     sonar,          sensorSONAR)
#pragma config(Motor,  motorA,          r,             tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          l,             tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          arm,           tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     left,          tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     right,         tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c" //Must be here to start corectly in the comp
bool onRamp;

task main()
{
	//Detects if the robot is on the ramp if button is pressed
	if (SensorValue[modeButton]==1)
		{
			onRamp = true;
		}else
			{
				onRamp = false;
			}

	//Before game reset code


	//Wait for start of game
	waitForStart();		//Must be here to start corectly in the comp. If needed comment it out so it doesn't wait

	//Game code here
	if(SensorValue[modeButton]==1)
		{
			//Code here for if robobot starts on the ramp

		}else
			{
				//Code here for if robobot starts on the ground

			}
}
