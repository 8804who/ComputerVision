#include  "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

const string bookPath = "D:/����/���� �ڷ�/4-1/USG��������/��ǻ�ͺ���/����/data/Practice4/book.jpg";
const string camPath = "D:/����/���� �ڷ�/4-1/USG��������/��ǻ�ͺ���/����/data/Practice4/cam.jpg";

int main(int argc,  char** argv)
{
	Mat book = imread(bookPath);
	Mat cam = imread(camPath);
	
	vector <KeyPoint> bookKPs, camKPs;
	Mat bookDesc, camDesc;

	Ptr<Feature2D> sift = SIFT::create();

	sift->detectAndCompute(book, Mat(), bookKPs, bookDesc);
	sift->detectAndCompute(cam, Mat(), camKPs, camDesc);

	BFMatcher matcher(NORM_L2SQR);
	vector<DMatch> matches;

	matcher.match(bookDesc, camDesc, matches);

	Mat result;
	drawMatches(book, bookKPs, cam, camKPs, matches, result, Scalar::all(-1), Scalar::all(-1), vector<char>(), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

	imshow("result", result);

	waitKey();
	return 0;
}