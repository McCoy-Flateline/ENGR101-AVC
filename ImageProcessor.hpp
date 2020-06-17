#include "robot.hpp"

// Result Struct
struct Result {
	bool foundWall = false;
	double error;
} result;

class ImageProcessor {
	private:
		// Variables
		int viewCenter;
		int row;
		int buffer = 20;
		// Class Methods
		int distanceToWall();
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
	viewCenter = (int) (cameraView.width/2.0);
	row = (int) (cameraView.height * 0.75);
	calculateError();
}

/**
 * Calculates and returns the distance
 * from the cameraView's center to the
 * left wall's right edge.
 */
int ImageProcessor::distanceToWall() {
	for (int i = viewCenter; i > 0; i--) {
		int pixelRedness = (int) get_pixel(cameraView, row, i, 0);
		int pixelBlueness = (int) get_pixel(cameraView, row, i , 2);
		if ((pixelRedness > 250) && (pixelBlueness < 5)) {
			return i;
		}
	}
	// Wall not found
	return -1;
}

/**
 * Calculates the error (difference between camera
 * view's center and white line's center)
 */
void ImageProcessor::calculateError() {
	int distanceFromCenter = distanceToWall();
	// Check if maze has been detected
	if (result.foundWall) {
		if (distanceFromCenter == -1) {
			// Left
			result.error = -100;
		} else {
			// Centralize robot
			result.error = buffer - distanceFromCenter;
		}
	} else {
		if (distanceFromCenter != -1) {
			// Straight
			result.foundWall = true;
			result.error = buffer - distanceFromCenter;
		}
	}
}
