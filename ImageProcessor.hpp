#include "robot.hpp"

class ImageProcessor {
	private:
		// Variables
		int* a = new int[(int) cameraView.width];
		const int ROW = (int) cameraView.height/2.0;
		int arrayCenter = (int) cameraView.width/2.0;
		int whiteLineCenter;
		int sumOfWhiteIndexes = 0;
		int numberOfWhitePixels = 0;
		// Class Methods
		void getWhitePixles();
		int calculateError();
	public:
		// Constructor
		ImageProcessor();
};

/**
 * Class Constructor
 */
ImageProcessor::ImageProcessor() {
	takePicture();
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
int ImageProcessor::calculateError() {
	getWhitePixles();
	whiteLineCenter = sumOfWhiteIndexes/numberOfWhitePixels;
	return (int) arrayCenter - whiteLineCenter;
}
