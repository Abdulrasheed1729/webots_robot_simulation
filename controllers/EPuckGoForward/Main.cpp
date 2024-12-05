#include <webots/Motor.hpp>
#include <webots/Robot.hpp>

#define TIME_STEP 64
#define MAX_SPEED 6.28

int main() {
	webots::Robot* robot = new webots::Robot();
	webots::Motor* leftMotor = robot->getMotor("left wheel motor");
	webots::Motor* rightMotor = robot->getMotor("right wheel motor");
	leftMotor->setPosition(INFINITY);
	rightMotor->setPosition(INFINITY);

	// set up the motor speeds at 10% of the MAX_SPEED.
	leftMotor->setVelocity(0.1 * MAX_SPEED);
	rightMotor->setVelocity(0.1 * MAX_SPEED);

	while (robot->step(TIME_STEP) != -1);

	delete robot;


	return 0;
}