#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat image1 = imread("../images/donald_trump.jpg");
	Mat image2 = imread("../images/hillary_clinton.jpg");
	double k = 0.5;
	Mat blend = image1 * k + (1 - k) * image2;

	imshow("image2", image2);
	Mat gray, binary, otsu;
	cvtColor(image2, gray, COLOR_BGR2GRAY);
	threshold(gray, binary, 128, 255, THRESH_BINARY);

	imshow("gray", gray);
	imshow("binary", binary);

	waitKey();
	return 0;
}
