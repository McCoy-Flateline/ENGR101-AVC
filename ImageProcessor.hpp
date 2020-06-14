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
		int* front = new int[(int) cameraView.width];
		int* left = new int[(int) cameraView.height]; //added
		int* right = new int[(int) cameraView.height]; //added
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
		// Update array based on pixel colour
		if (pixelWhiteness == 255) {
			front[i] = 1;
			sumOfWhiteIndexes += i;
			numberOfWhitePixels++;
		} else {
			front[i] = 0;
		}
	}
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
}

void ImageProcessor::intersectionCheck() {
	//check left path
	//check right path
	//check front path
	int halfHeight = cameraView.height / 2;
	
	if (left[halfHeight] == 1){
		result.pathLeft = true;
	} else {
		result.pathLeft = false;
	}
	
	if (right[halfHeight] == 1){
		result.pathRight = true;
	} else {
		result.pathRight = false;
	}
	delete(left);
	delete(right);
	delete(front);
}
