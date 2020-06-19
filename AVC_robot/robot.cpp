#include "ImageProcessor.hpp"

void core(double vLeft, double vRight, double v_go, double Kp, double dv){
    while(1){
		ImageProcessor imageProcessor;
		dv = Kp*result.error;
		
		vLeft = v_go - dv;
		vRight = v_go + dv;
		
		setMotors(vLeft,vRight);   
		std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
		usleep(10000);
	} //while
		
}//core

void completion(double vLeft, double vRight, double v_go, double Kp, double dv){
	//Variables
    double turn;
    int turnCount = 5;
    int forwardCount = 14;
    
    while(1){
		ImageProcessor imageProcessor;
		
		// Set turning velocity
		turn = 35;
		
		if (result.pathLeft) {
			// Go forward then turn left
			vLeft = v_go;
			vRight = v_go;
			for (int i = 0; i < forwardCount; i++) {
				setMotors(vLeft, vRight);
			}
			vLeft = -turn;
			vRight = turn;
			for (int i = 0; i < turnCount; i++) {
				setMotors(vLeft, vRight);
			}
			setMotors(0, 0);
			
		} else if (result.pathForward) {
			// Go Forward
			dv = Kp * result.error;
			vLeft = v_go - dv;
			vRight = v_go + dv;
			setMotors(vLeft, vRight);
		} else if (result.pathRight) {
			// Go forward then turn right
			vLeft = v_go;
			vRight = v_go;
			for (int i = 0; i < forwardCount; i++) {
				setMotors(vLeft, vRight);
			}
			vLeft = turn;
			vRight = -turn;
			for (int i = 0; i < turnCount; i++) {
				setMotors(vLeft, vRight);
			}
			setMotors(0, 0);
		} else {	// Dead End
			// Go forward
			vLeft = v_go;
			vRight = v_go;
			for (int i = 0; i < forwardCount; i++) {
				setMotors(vLeft, vRight);
			}
			// Turn 180 degrees
			vLeft = -(turn - 2);
			vRight = (turn - 2);
			for (int i = 0; i < turnCount*2; i++) {
				setMotors(vLeft, vRight);
			}
			// Go forward
			vLeft = v_go;
			vRight = v_go;
			for (int i = 0; i < forwardCount; i++) {
				setMotors(vLeft, vRight);
			}
		}
		std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
		usleep(10000);
	}//while

}//completion

void challenge(double vLeft, double vRight, double v_go, double Kp, double dv){
	//Variables
    double turn;
    int turnCount = 5;
    int forwardCount = 14;
    
    while(1){
		ImageProcessor imageProcessor;
	
		turn = 20;
		if (result.foundWall) {
			if (result.wallError == -55) {
				// Turn Right
				vLeft = turn;
				vRight = -turn;
				for (int i = 0; i < turnCount; i++) {
					setMotors(vLeft, vRight);
				}
			} else if (result.wallError == -100) {
				// Go forward a bit then turn left
				vLeft = v_go;
				vRight = v_go;
				for (int i = 0; i < forwardCount + 1; i++) {
					setMotors(vLeft, vRight);
				}
				vLeft = -turn;
				vRight = turn;
			for (int i = 0; i < turnCount + 4; i++) {
				setMotors(vLeft, vRight);
				}
			} else {
				// Go Straight
				dv = Kp * result.wallError;
				vLeft = v_go - dv;
				vRight = v_go + dv;
			}
		} else {
			vLeft = v_go;
			vRight = v_go;
		}
		setMotors(vLeft, vRight);
		std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
		usleep(10000);
		
	}//while
	
}//challenge

int main(){
	
	bool valid = false;
	std::string mazeType;
	std::string compare1 = "core";
	std::string compare2 = "Core";
	std::string compare3 = "completion";
	std::string compare4 = "Completion";
	std::string compare5 = "challenge";
	std::string compare6 = "Challenge";
	
	while(valid == false){
		std::cout << "Which maze are you using? (Core, completion, challenge): ";
		std::cin >> mazeType;
		if ( mazeType == compare1 || mazeType == compare2 || mazeType == compare3 || mazeType == compare4 || mazeType == compare5 || mazeType == compare6){
			valid = true;
			std::cout<<"Valid"<<std::endl;
			
		} else {
			std::cout<<"Please enter core, completion, or challenge."<<std::endl;
		}
	}
	
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
	
	//Variables
	double vLeft;
    double vRight;
    double v_go = 50;
    double Kp = 0.5;
    double dv;
	
	if(mazeType == compare1 || mazeType == compare2){
		core(vLeft, vRight, v_go, Kp, dv);
	} else if(mazeType == compare3 || mazeType == compare4){
		completion(vLeft, vRight, v_go, Kp, dv);	
	} else if(mazeType == compare5 || mazeType == compare6){
		challenge(vLeft, vRight, v_go, Kp, dv);	
	}
	
} // main
