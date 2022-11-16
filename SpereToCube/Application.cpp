#define DEPRECATED

#ifndef DEPRECATED

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "Equi2Rect.hpp"
#include <fstream>
#include <vector>

using std::cout;
using std::ofstream;
using std::vector;
using std::endl;


auto eul2rotm(double rotx, double roty, double rotz) -> cv::Mat
{

	cv::Mat R_x = (cv::Mat_<double>(3, 3) << 1, 0, 0,
		0, cos(rotx), -sin(rotx),
		0, sin(rotx), cos(rotx));

	cv::Mat R_y = (cv::Mat_<double>(3, 3) << cos(roty), 0, sin(roty),
		0, 1, 0,
		-sin(roty), 0, cos(roty));

	cv::Mat R_z = (cv::Mat_<double>(3, 3) << cos(rotz), -sin(rotz), 0,
		sin(rotz), cos(rotz), 0,
		0, 0, 1);

	cv::Mat R = R_z * R_y * R_x;

	return R;
}
int main()
{
	constexpr double M_PI = 3.14159265359;
	//constexpr int focal_length = 255;

	//std::ofstream outFile;
	//outFile.open("main.csv", std::ios::out | std::ios::trunc);
	
	cv::Mat img = cv::imread("stan.jpg");
	int srcWidth = img.cols;
	int srcHeight = img.rows;
	
	int viewWidth = srcHeight / 4;
	int viewHeight = viewWidth;


	/*cv::Mat K = (cv::Mat_<double>(3, 3) << focal_length, 0, viewWidth / 2,
		0, focal_length, viewHeight / 2,
		0, 0, 1);*/

	

	cv::Mat left(viewHeight, viewWidth, CV_8UC3, cv::Scalar(0, 0, 0));
	cv::Mat front(viewHeight, viewWidth, CV_8UC3, cv::Scalar(0, 0, 0));
	cv::Mat right(viewHeight, viewWidth, CV_8UC3, cv::Scalar(0, 0, 0));
	cv::Mat back(viewHeight, viewWidth, CV_8UC3, cv::Scalar(0, 0, 0));
	cv::Mat top(viewHeight, viewWidth, CV_8UC3, cv::Scalar(0, 0, 0));
	cv::Mat bottom(viewHeight, viewWidth, CV_8UC3, cv::Scalar(0, 0, 0));

	cv::Mat Rot_left = eul2rotm(0, 0, M_PI / 2);
	cv::Mat Rot_front = eul2rotm(0, 0, 0);
	cv::Mat Rot_right = eul2rotm(0, 0, -M_PI / 2);
	cv::Mat Rot_back = eul2rotm(0, 0, M_PI);
	cv::Mat Rot_top = eul2rotm(-M_PI / 2, 0, 0);
	cv::Mat Rot_bottom = eul2rotm(M_PI / 2, 0, 0);

	vector<cv::Mat> outimg{ left,front,right,back,top,bottom };
	vector<cv::Mat> Rot{ Rot_left,Rot_front,Rot_right,Rot_back,Rot_top,Rot_bottom };

	for (int i = 0; i < 6; ++i)
	{
		for (int v = 0; v < viewHeight; ++v)
		{
			for (int u = 0; u < viewWidth; ++u)
			{
				v = viewHeight - 1 - v;

				/*cv::Mat xyz = (cv::Mat_<double>(3, 1) << (double)u, (double)v, 1);
				cv::Mat ray3d = K.inv() * xyz / norm(xyz);

				double px = ray3d.at<double>(0);
				double py = ray3d.at<double>(1);
				double pz = ray3d.at<double>(2);*/


				//book
				double px = (2 * static_cast<double>(u) / viewWidth) - 1;
				double py = 1;
				double pz = (2 * static_cast<double>(v) / viewHeight) - 1;

				cv::Mat xyz = (cv::Mat_<double>(3, 1) << px, py, pz);
				cv::Mat ray3d = Rot[i] * xyz;

				px = ray3d.at<double>(0);
				py = ray3d.at<double>(1);
				pz = ray3d.at<double>(2);


				double longtitude = atan2(py, px);
				double latitude = atan2(pz, sqrt(px * px + py * py));


				int posx = static_cast<int>(static_cast<double>(srcWidth) * (longtitude + M_PI)) / (2 * M_PI);
				int posy = static_cast<int>(static_cast<double>(srcHeight) * (latitude + M_PI / 2)) / M_PI;

#if DEBUG
				outFile << "u:" << u << "  v:" << v << "  xp" << xp << "  yp" << yp << "  zp" << zp << "   theta" << theta << "  phi" << phi << "  x_sphere" << x_sphere << " y_sphere" << y_sphere << endl;
#endif // DEBUG

				outimg[i].at<cv::Vec3b>(v, u) = img.at<cv::Vec3b>(posy, posx);
			}
		}
	}
	

	//outFile.close();

	cv::namedWindow("imgSrc");
	cv::imshow("imgSrc", img);

	cv::namedWindow("left");
	cv::imshow("left", outimg[0]);

	cv::namedWindow("front");
	cv::imshow("front", outimg[1]);

	cv::namedWindow("right");
	cv::imshow("right", outimg[2]);

	cv::namedWindow("back");
	cv::imshow("back", outimg[3]);

	cv::namedWindow("top");
	cv::imshow("top", outimg[4]);

	cv::namedWindow("bottom");
	cv::imshow("bottom", outimg[5]);

	/*Equi2Rect equi2rect;
	equi2rect.save_rectlinear_image();
	equi2rect.show_rectlinear_image();*/
	cv::waitKey(0);
	
}
#endif