#include "robot.hpp"

// Result Struct
struct Result {
	bool onLine;
	double error;
	bool pathLeft; //added
	bool pathFront; //added
	bool pathRight; //added
} result;

class ImageProcessor {
	private:
		// Variables
		int* line = new int[(int) cameraView.width]; //check if on line
		
		int* front = new int[(int) cameraView.width]; //array checking farfront
		int* left = new int[(int) cameraView.height]; //array checking left side
		int* right = new int[(int) cameraView.height]; //array checking right side
		const int ROW = (int) cameraView.height/2.0;
		int sumOfWhiteIndexes = 0;
		int numberOfWhitePixels = 0;
		// Class Methods
		void getWhitePixles();
		void calculateError();
		void intersectionCheck(); //added
	public:
		// Constructor
		ImageProcessor();
};

/**
 * Class Constructor
 */
ImageProcessor::ImageProcessor() {
	takePicture();
	calculateError();
	intersectionCheck(); //added
}

/**
 * Gets the number of white pixels and
 * stores it in an array
 */
void ImageProcessor::getWhitePixles() {
	// Check each pixel in row selected
	for (int i = 0; i < cameraView.width; i++) {
		// Get pixel whiteness
		int pixelWhiteness = (int) get_pixel(cameraView, ROW, i, 3);
		int frontPixelWhiteness = (int) get_pixel(cameraView, cameraView.height - 2, i, 3);
		// Update array based on pixel colour
		if (pixelWhiteness == 255) {
			line[i] = 1;
			sumOfWhiteIndexes += i;
			numberOfWhitePixels++;
		} else {
			line[i] = 0;
		}
		if (frontPixelWhiteness == 255) {
			front[i] = 1;
		} else {
			front[i] = 0;
		}
	}
	//creates an array containing white pixels on left/right edge of screen 2 pixles in
	for (int j = 0; j < cameraView.height; j++){
		int leftPixelWhiteness = (int) get_pixel(cameraView, j, 2, 3);
		int rightPixelWhitness = (int) get_pixel(cameraView, j, cameraView.height-2, 3);
		if (leftPixelWhiteness == 255) {
			left[j] = 1;
		} else {
			left[j] = 0;
		}
		if (rightPixelWhitness == 255) {
			right[j] = 1;
		} else {
			right[j] = 0;
		}
	}
}

/**
 * Calculates the error (difference between camera
 * view's center and white line's center)
 */
void ImageProcessor::calculateError() {
	// Update array
	getWhitePixles();
	// Variables
	double arrayCenter = cameraView.width/2.0;
	double whiteLineCenter;
	// Update result struct based on cameraView
	if (numberOfWhitePixels > 0) {
		whiteLineCenter = sumOfWhiteIndexes/numberOfWhitePixels;
		result.onLine = true;
		result.error = arrayCenter - whiteLineCenter;
	} else {
		whiteLineCenter = arrayCenter;
		result.onLine = false;
		result.error = 0;
	}
	delete(line);
}

/**
 * Checks if there is a white line to the leaving to the left, right
 * and front of the screen. If there is a line in the middle of the edge
 * it returns bool true.
 * Returns:
 * 		- leftPath = true/false
 * 		- rightPath = true/false
 * 		- frontPath = true/flase
 */
void ImageProcessor::intersectionCheck() {
	//set where to look for line on the edge
	int halfHeight = cameraView.height / 2;
	
	//check left path
	if (left[halfHeight] == 1){
		result.pathLeft = true;
	} else {
		result.pathLeft = false;
	}
	//check right path
	if (right[halfHeight] == 1){
		result.pathRight = true;
	} else {
		result.pathRight = false;
	}
	//check front path
	if (front[cameraView.width / 2] == 1){
		result.pathFront = true;
	} else {
		result.pathFront = false;
	}
	delete(left);
	delete(right);
	delete(front);
}
