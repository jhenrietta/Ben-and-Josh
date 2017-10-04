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

	int spiral = 1;
	int wallFollow = 2;
	int straight = 3;

	float spiralChange = 40;

	resetMotorEncoder(left);
	resetMotorEncoder(right);

	while(true)
	{

		while(mode == spiral)
		{
			motor(left) = 60;
			motor(right) = spiralChange;

			spiralChange = spiralChange + 0.70;
			wait1Msec(700);

			if(sensorValue(sonar) <= 30 || sensorValue(sonar2) <= 30)
			{
				resetMotorEncoder(left);
				resetMotorEncoder(right);
				mode = wallFollow;
			}

			if( ((getMotorEncoder(left)) + (getMotorEncoder(right)) >= 40000) || (spiralChange >= 60))
			{
				resetMotorEncoder(left);
				resetMotorEncoder(right);
				mode = straight;
			}

		}

		while(mode == wallFollow)
		{

			motor(left) = 60;
			motor(right) = 58.6;

			while(sensorValue(sonar) <= 30 || sensorValue(sonar2) <= 30)
			{
				motor(left) = 60;
				motor(right) = -30;
				wait1Msec(70);
			}

			if((getMotorEncoder(left)) + (getMotorEncoder(right)) >= 25000)
			{
				resetMotorEncoder(left);
				resetMotorEncoder(right);
				motor(left) = 60;
				motor(right) = -20;
				wait1Msec(550);
				mode = straight;
			}

		}

		while(mode == straight)
		{
			motor(left) = 60;
			motor(right) = 60;

			if(sensorValue(sonar) <= 30 || sensorValue(sonar2) <= 30)
			{
				resetMotorEncoder(left);
				resetMotorEncoder(right);
				mode = wallFollow;
			}

			if((getMotorEncoder(left)) + (getMotorEncoder(right)) >= 20000)
			{
				resetMotorEncoder(left);
				resetMotorEncoder(right);
				spiralChange = 40;
				mode = spiral;
			}
		}

	}
}
