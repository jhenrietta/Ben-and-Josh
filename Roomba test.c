#pragma config(Sensor, S1,     button1,        sensorEV3_Touch)
#pragma config(Sensor, S2,     sonar2,         sensorEV3_Ultrasonic)
#pragma config(Sensor, S3,     sonar,          sensorEV3_Ultrasonic)
#pragma config(Sensor, S4,     button2,        sensorEV3_Touch)
#pragma config(Motor,  motorB,          left,          tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          right,         tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	int mode = 1;
	//int SPIRAL = 1;
	//int WALL = 2;

	while(true)
	{

		if(mode == 1)
		{
			motor(left) = 60;
			motor(right) = 50;
			if(sensorValue(sonar) <= 30 || sensorValue(sonar2) <= 30)
			{
				motor(left)= 60;
				motor(right)= -25;
				mode = 2;
			}
		}

		if(mode == 2)
		{
			motor(left) = 60;
			motor(right) = 59;
			wait1Msec(10000);
			mode = 1;
		}
		/*
		while(sensorValue(sonar) >= 30 && sensorValue(sonar2) >= 30)
		{
		motor(left)=60;
		motor(right)=59;
		}
		motor(left)= 60;
		motor(right)= -25; */
	}
}
