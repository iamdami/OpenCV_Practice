#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()

{
Mat image2 = imread("../images/hillary_clinton.jpg");

Mat gray;
cvtColor(image2, gray, COLOR_BGR2GRAY);

imshow("gray", gray);

waitKey();
return 0;

}
