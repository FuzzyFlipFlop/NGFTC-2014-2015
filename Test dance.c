#include "Easier Motors.c"

#include "JoystickDriver.c"

int danceSteps = 4;

task main()
{
	nxtDisplayTextLine(0, "Yay Dancing");

	for(int i = 0; i < danceSteps; i++){
		//dance steps
		motor[right] = 40;
		wait10Msec(75);
		motor[right] = 0;

		wait10Msec(50);

		motor[left] = 40;
		wait10Msec(75);
		motor[left] = 0;

		wait10Msec(50);

		motor[right] = 60;
		motor[left] = -60;
		wait10Msec(150);
		motor[right] = 0;
		motor[left] = 0;
	}
}
