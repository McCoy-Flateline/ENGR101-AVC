
#include "ImageProcessor.hpp"
int main(){
	
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
	
	double vLeft = 40.0;
    double vRight = 30.0;
    char v_go = 20;
    double Kp = 0.1;
    char dv = 0;
    bool turnLeft = false;
    bool turnRight = false;
    
    takePicture();
    SavePPMFile("i0.ppm",cameraView);
    
    while(1){
		ImageProcessor imageProcessor;
		dv = Kp*result.error;
		
		if(result.pathLeft){
			}
		else if(result.pathFront){
			
			
			}
		else if(result.pathRight){
			
			}
		
			
		vLeft = v_go - dv;
		vRight = v_go + dv;
		
		
		setMotors(vLeft,vRight);   
		std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
		usleep(10000);
	} //while

	

} // main
