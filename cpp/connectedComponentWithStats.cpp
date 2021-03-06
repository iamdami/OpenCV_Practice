#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	uchar data[] = {
		0,0,1,1,0,0,0,0,
		1,1,1,1,0,0,1,0,
		1,1,1,1,0,0,0,0,
		0,0,0,0,0,1,1,0,
		0,0,0,1,1,1,1,0,
		0,0,0,1,0,0,1,0,
		0,0,1,1,1,1,1,0,
		0,0,0,0,0,0,0,0,
	};

	Mat src = Mat(8, 8, CV_8UC1, data) * 255; //255로 출력되는 부분이 흰 부분
	Mat label1;
	int cnt1 = connectedComponents(src, label1); //연결요소 계산해주는 함수. 개수 리턴
	cout << "src:\n" << src << endl;
	cout << "labels:\n" << label1 << endl;
	cout << "number of labels: " << cnt1 << endl;

	Mat label2, stats, centroids;//mat 변수 이름 임의 설정 가능
	int cnt2 = connectedComponentsWithStats(src, label2, stats, centroids);
	cout << "\n \n" << endl;
	cout << "labels:\n" << label2 << endl;
	cout << "stats:\n " << stats << endl;
	cout << "centroids:\n " << centroids << endl;
	cout << "number of labels: " << cnt1 << endl; //배경까지 포함한 개수(여기선 0,1,2,3의 4개)

	return 0;
}
