"""epuck_go_forward_py controller."""

# You may need to import some classes of the controller module. Ex:
#  from controller import Robot, Motor, DistanceSensor
from controller import Robot, Motor

if __name__ == '__main__':
    # create the Robot instance.
    robot = Robot()
    
    # get the time step of the current world.
    TIME_STEP= 64
    
    MAX_VELOCITY = 6.28
    
    # You should insert a getDevice-like function in order to get the
    # instance of a device of the robot. Something like:
    #  motor = robot.getDevice('motorname')
    #  ds = robot.getDevice('dsname')
    #  ds.enable(timestep)
    
    # get the motor devices
    leftMotor = robot.getDevice('left wheel motor')
    rightMotor = robot.getDevice('right wheel motor')
   
    # set the target position of the motors
    leftMotor.setPosition(float('inf'))
    rightMotor.setPosition(float('inf'))
    
    leftMotor.setVelocity(0.5 * MAX_VELOCITY)
    rightMotor.setVelocity(-0.5 * MAX_VELOCITY)
    
    # Main loop:
    # - perform simulation steps until Webots is stopping the controller
    while robot.step(TIME_STEP) != -1:
        pass
    
    # Enter here exit cleanup code.
    