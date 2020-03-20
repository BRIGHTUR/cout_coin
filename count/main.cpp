#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main()
{
	Mat src = imread("coin.png", 0);
	Mat dist;
	Mat labelmat;
	Mat statsmat;
	Mat centermat;
	threshold(src, dist, 0, 255, THRESH_OTSU);
	int nComp = connectedComponentsWithStats(dist, labelmat, statsmat, centermat,8,CV_32S);
	cout << "Ó²±Ò¸öÊýÎª:" << nComp - 1 << endl;
	for (int i = 1; i < nComp; i++)
	{
		Rect bndbox;
		bndbox.x = statsmat.at<int>(i, 0);
		bndbox.y = statsmat.at<int>(i, 1);
		bndbox.width = statsmat.at<int>(i, 2);
		bndbox.height = statsmat.at<int>(i, 3);
		rectangle(src, bndbox, CV_RGB(255, 255, 255), 1, 8, 0);
	}
	imshow("ss", src);
	waitKey(0);
	system("pause");

}