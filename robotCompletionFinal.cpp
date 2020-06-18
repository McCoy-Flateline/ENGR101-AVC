#include "ImageProcessor.hpp"

int core(){
	double vLeft = 40.0;
    double vRight = 30.0;
    char v_go = 20;
    double Kp = 0.1;
    char dv = 0;
    
    takePicture();
    SavePPMFile("i0.ppm",cameraView);
    
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

int completion(){
	//Variables
	
	double vLeft;
    double vRight;
    double v_go = 50;
    double Kp = 0.5;
    char dv;
    double turn;
    int turnCount = 5;
    int forwardCount = 14;
    
    
    takePicture();
    SavePPMFile("i0.ppm",cameraView);
    
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

int main(){
	
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
	
	bool valid = false;
	std::string mazeType;
	std::string compare1 = "core";
	std::string compare2 = "Core";
	std::string compare3 = "completion";
	std::string compare4 = "Completion";
	
	while(valid == false){
		std::cout << "Which maze would you like to use? (Core or completion): ";
		std::cin >> mazeType;
		if( mazeType == compare1 || mazeType == compare2 || mazeType == compare3 || mazeType == compare4){
			valid = true;
			std::cout<<"Valid"<<std::endl;
			
			}
		else{
			std::cout<<"Please enter core or completion."<<std::endl;
			}
	}
	
	if(mazeType == compare1 || mazeType == compare2){
		core();
	} else if(mazeType == compare3 || mazeType == compare4){
		completion();	
	} 

} // main

