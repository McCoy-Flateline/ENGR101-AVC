#include "robot.hpp"

// Result Struct
struct Result {
	bool onLine;
	double error;
} result;

class ImageProcessor {
	private:
		// Variables
		int* a = new int[(int) cameraView.width];
		const int ROW = (int) cameraView.height/2.0;
		int sumOfWhiteIndexes = 0;
		int numberOfWhitePixels = 0;
		// Class Methods
		void getWhitePixles();
		void calculateError();
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
			a[i] = 1;
			sumOfWhiteIndexes += i;
			numberOfWhitePixels++;
		} else {
			a[i] = 0;
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
	delete(a);
}
