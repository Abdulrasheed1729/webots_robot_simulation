#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/DistanceSensor.hpp>

#define TIME_STEP 64
#define MAX_SPEED 6.28

int main(int argc, char** argv) {

	webots::Robot* robot = new webots::Robot();

	webots::DistanceSensor* ps[8];

	char psNames[8][4] = {
		"ps0", "ps1", "ps2", "ps3",
		"ps5", "ps5", "ps6", "ps7"
	};

	for (int i = 0; i < 8; i++) {
		ps[i] = robot->getDistanceSensor(psNames[i]);
		ps[i]->enable(TIME_STEP);
	}

	webots::Motor* leftMotor = robot->getMotor("left wheel motor");
	webots::Motor* rightMotor = robot->getMotor("right wheel motor");
	leftMotor->setPosition(INFINITY);
	rightMotor->setPosition(INFINITY);
	leftMotor->setVelocity(0.0);
	rightMotor->setVelocity(0.0);

	
	while (robot->step(TIME_STEP) != -1) {
		// read sensors outputs
		double psValues[8];

		for (int i = 0; i < 8; i++)
			psValues[i] = ps[i]->getValue();

		// process behaviour
		// detect obstacle
		bool right_obstacle =
			psValues[0] > 80.00 ||
			psValues[1] > 80.00 ||
			psValues[2] > 80.00;
		bool left_obstacle =
			psValues[5] > 80.00 ||
			psValues[6] > 80.00 ||
			psValues[7] > 80.00;

		double leftSpeed = 0.5 * MAX_SPEED;
		double rightSpeed = 0.5 * MAX_SPEED;

		if (left_obstacle)
		{
			leftSpeed = 0.5 * MAX_SPEED;
			rightSpeed = -0.5 * MAX_SPEED;
		} 
		else if (right_obstacle)
		{
			leftSpeed = -0.5 * MAX_SPEED;
			rightSpeed = 0.5 * MAX_SPEED;
		}
		// write actuators inputs
		leftMotor->setVelocity(leftSpeed);
		rightMotor->setVelocity(rightSpeed);
	}

	delete robot;

	return 0;
}