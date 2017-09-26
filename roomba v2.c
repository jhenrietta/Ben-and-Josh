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

	resetMotorEncoder(left);
	resetMotorEncoder(right);

	while(true)
	{

		while(mode == 1)
		{
			motor(left) = 60;
			motor(right) = 50;

			if(sensorValue(sonar) <= 30 || sensorValue(sonar2) <= 30)
			{
				resetMotorEncoder(left);
				resetMotorEncoder(right);
				mode = 2;
			}

			if((getMotorEncoder(left)) + (getMotorEncoder(right)) >= 20000)
			{
				resetMotorEncoder(left);
				resetMotorEncoder(right);
				mode = 3;
			}

		}

		while(mode == 2);
		{
			motor(left) = 60;
			motor(right) = 58.5;

			while(sensorValue(sonar) <= 30 || sensorValue(sonar2) <= 30)
			{
				motor(left) = 60;
				motor(right) = -25;
			}

			if((getMotorEncoder(left)) + (getMotorEncoder(right)) >= 20000)
			{
				resetMotorEncoder(left);
				resetMotorEncoder(right);
				mode = 1;
			}


		}

		while(mode == 3);
		{
			motor(left) = 60;
			motor(right) = 60;

			if(sensorValue(sonar) <= 30 || sensorValue(sonar2) <= 30)
			{
				resetMotorEncoder(left);
				resetMotorEncoder(right);
				mode = 2;
			}

			if((getMotorEncoder(left)) + (getMotorEncoder(right)) >= 20000)
			{
				resetMotorEncoder(left);
				resetMotorEncoder(right);
				mode = 1;
			}
		}

	}
}
