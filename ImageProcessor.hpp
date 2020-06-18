#include "robot.hpp"

// Result Struct
struct Result {
	bool onLine;
	bool foundWall = false;
	double error;
	double wallError;
	bool pathLeft;
	bool pathForward;
	bool pathRight;
} result;

class ImageProcessor {
	private:
		// Variables
		int sumOfPixelIndexes_F = 0;
		int sumOfPixelIndexes_R = 0;
		int sumOfPixelIndexes_L = 0;
		int numberOfWhitePixels_F = 0;
		int numberOfWhitePixels_R = 0;
		int numberOfWhitePixels_L = 0;
		int viewHorizontalCenter = (int) cameraView.width/2.0;
		int viewVerticalCenter = (int) cameraView.height/2.0;
		// Class Methods
		void checkSides();
		void checkPaths();
		int distanceToWall();
		void calculateError();
		void updateResultStruct();
	public:
		// Constructor
		ImageProcessor();
};

/**
 * Class Constructor
 */
ImageProcessor::ImageProcessor() {
	takePicture();
	updateResultStruct();
}

/**
 * Checks if there are any pixels on each
 * side of the cameraView (Left, Front & Right)
 */
void ImageProcessor::checkSides() {
	// Scans the far front side for any white pixels
	for (int i = 0; i < cameraView.width; i++) {
		int pixelWhiteness_F = (int) get_pixel(cameraView, viewVerticalCenter - 2, i, 3);
		if (pixelWhiteness_F > 250) {
			sumOfPixelIndexes_F += i;
			numberOfWhitePixels_F++;
		}
	}
	// Scans the left and right sides for any white pixels
	for (int i = 0; i < cameraView.height; i++) {
		int pixelWhiteness_R = (int) get_pixel(cameraView, i, (int) (cameraView.width - 2), 3);
		int pixelWhiteness_L = (int) get_pixel(cameraView, i, 2, 3);
		if (pixelWhiteness_R > 250) {
			sumOfPixelIndexes_R += i;
			numberOfWhitePixels_R++;
		}
		if (pixelWhiteness_L > 250) {
			sumOfPixelIndexes_L += i;
			numberOfWhitePixels_L++;
		}
	}
}


/**
 * Calculates and returns the distance
 * from the cameraView's horizontal center
 * to the left wall's right edge.
 */
int ImageProcessor::distanceToWall() {
	// Declare row to scan
	int row = (int) (cameraView.height * 0.75);
	// Scan row
	for (int i = viewHorizontalCenter; i > 0; i--) {
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
 * Calculates the distance from the cameraView's
 * horizontal center to the center of the white
 * line or right edge of the wall
 */
void ImageProcessor::calculateError() {
	// Get distance from view center to white line
	checkSides();
	double whiteLineCenter;
	if (numberOfWhitePixels_F < 1) {
		result.onLine = false;
		result.error = 0;
		numberOfWhitePixels_F = -1;
	} else {
		whiteLineCenter = sumOfPixelIndexes_F/numberOfWhitePixels_F;
		result.onLine = true;
		result.error = viewHorizontalCenter - whiteLineCenter;
	}
	// Error Checking (Prevent division by 0)
	if (numberOfWhitePixels_L < 1) {
		numberOfWhitePixels_L = -1;
	}
	if (numberOfWhitePixels_R < 1) {
		numberOfWhitePixels_R = -1;
	}

	// Get distance from view center to red wall
	int distanceFromCenter = distanceToWall();
	// Check if maze has been detected
	int buffer = 20;
	if (result.foundWall) {
		if (distanceFromCenter == -1) {
			// Left
			result.wallError = -100;
		} else {
			// Centralize robot
			result.wallError = buffer - distanceFromCenter;
		}
	} else {
		if (distanceFromCenter != -1) {
			// Straight
			result.foundWall = true;
			result.wallError = buffer - distanceFromCenter;
		}
	}
}

void ImageProcessor::checkPaths() {
	// Get the line's center for each side
	int forwardLineCenter = sumOfPixelIndexes_F/numberOfWhitePixels_F;
	int leftLineCenter = sumOfPixelIndexes_L/numberOfWhitePixels_L;
	int rightLineCenter = sumOfPixelIndexes_R/numberOfWhitePixels_R;
	// Check which paths are available to the robot
	if ((forwardLineCenter > viewHorizontalCenter - 10) && (forwardLineCenter < viewHorizontalCenter + 10)) {
		result.pathForward = true;
	} else {
		result.pathForward = false;
	}
	if ((leftLineCenter > viewVerticalCenter - 10) && (leftLineCenter < viewVerticalCenter + 10)) {
		result.pathLeft = true;
	} else {
		result.pathLeft = false;
	}
	if ((rightLineCenter > viewVerticalCenter - 10) && (rightLineCenter < viewVerticalCenter + 10)) {
		result.pathRight = true;
	} else {
		result.pathRight = false;
	}
}

/** Updates the Result struct which
 * holds all the information requirec
 * by the robot to navigate the map
 */
void ImageProcessor::updateResultStruct() {
	calculateError();
	checkPaths();
}
