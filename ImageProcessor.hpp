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
	for (int i = 0; i < cameraView.width; i++) {
		int pixelWhiteness = (int) get_pixel(cameraView, ROW, i, 3);
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
	getWhitePixles();
	double arrayCenter = cameraView.width/2.0;
	double whiteLineCenter;
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
