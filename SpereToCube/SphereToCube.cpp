#include "SphereToCube.h"
#include <iostream>
SphereToCube::SphereToCube(const string img_path):img_src{cv::imread(img_path)},srcHeight{img_src.rows},srcWidth{img_src.cols},viewLength{srcHeight/2}
{
	int i = 5;
	while (i-- >= 0)
	{
		img_cube.emplace_back(cv::Mat(viewLength, viewLength, CV_8UC3, cv::Scalar(0, 0, 0)));
		img_textures.emplace_back(cv::Mat(viewLength, viewLength, CV_8UC3, cv::Scalar(0, 0, 0)));
	}
}

//@parameters: double title, double roll , double pan
auto SphereToCube::eul2rotm(double rotx, double roty, double rotz) -> cv::Mat
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

vector<int> SphereToCube::reProjection(const int x_img, const int y_img,const cv::Mat& rot) const
{
	/*int x = x_img;*/
	int x = viewLength - 1 - x_img;
	//int y = viewLength - 1 - y_img ;
	/*int y = y_img;*/
	/*int x = x_img;*/
	int y = y_img;
	double px = (2 * static_cast<double>(x) / viewLength) - 1;
	double py = 1;
	//double pz = (2 * static_cast<double>(y) / viewLength) - 1;
	double pz = (2 * static_cast<double>(y) / viewLength) - 1;

	cv::Mat xyz = (cv::Mat_<double>(3, 1) << px, py, pz);
	cv::Mat ray3d = rot * xyz;

	px = ray3d.at<double>(0);
	py = ray3d.at<double>(1);
	pz = ray3d.at<double>(2);


	double longtitude = atan2(py, px);
	double latitude = atan2(pz, sqrt(px * px + py * py));


	int posx = static_cast<int>(static_cast<double>(srcWidth) * (longtitude + M_PI)) / (2 * M_PI);
	int posy = static_cast<int>(static_cast<double>(srcHeight) * (latitude + M_PI / 2)) / M_PI;

	return vector<int>{posx,posy};
}

vector<double> SphereToCube::reProjection(const double x_img, const double y_img, const int direction) const
{
	double x_img_re = viewLength - 1 - x_img;

	double px = (2 * static_cast<double>(x_img_re) / viewLength) - 1;
	double py = 1;
	double pz = (2 * static_cast<double>(y_img) / viewLength) - 1;

	std::cout << "px: " << px << "  py: " << py << " pz: " << pz << std::endl;

	cv::Mat xyz = (cv::Mat_<double>(3, 1) << px, py, pz);
	cv::Mat ray3d = Euler[direction] * xyz;

	px = ray3d.at<double>(0);
	py = ray3d.at<double>(1);
	pz = ray3d.at<double>(2);
	std::cout << "px: " << px << "  py: " << py << " pz: " << pz << std::endl;


	double longtitude = atan2(py, px);
	double latitude = atan2(pz, sqrt(px * px + py * py));
	std::cout << "longti: " << longtitude << "  latitude: " << latitude << std::endl;


	double posx = static_cast<int>(static_cast<double>(srcWidth) * (longtitude + M_PI)) / (2 * M_PI);
	double posy = static_cast<int>(static_cast<double>(srcHeight) * (latitude + M_PI / 2)) / M_PI;

	return vector<double>{posx, posy};
}

void SphereToCube::generateCubeMap()
{
	cv::Mat img_copy = img_src.clone();
	
	/*cv::Mat img_copy;
	cv::flip(img_src, img_copy, 1);*/
	for (int i = 0; i < 6; ++i)
	{
		for (int v = 0; v < viewLength; ++v)
		{
			for (int u = 0; u < viewLength; ++u)
			{
				vector<int> dst_pos = reProjection(u, v, Rot[i]);
				
				img_cube[i].at<cv::Vec3b>(v, u) = img_copy.at<cv::Vec3b>(dst_pos[1], dst_pos[0]);
				img_src.at<cv::Vec3b>(dst_pos[1], dst_pos[0])=color[i];
			}
		}
		/*cv::flip(img_cube[i], img_cube[i], 0);*/
	}


}

void SphereToCube::showCube() const
{
	cv::namedWindow("imgSrc");
	cv::imshow("imgSrc", img_src);
	
	cv::namedWindow("+x_right");
	cv::imshow("+x_right", img_cube[0]);
	
	cv::namedWindow("-x_left");
	cv::imshow("-x_left", img_cube[1]);
	
	cv::namedWindow("+y_front");
	cv::imshow("+y_front", img_cube[2]);
	
	cv::namedWindow("-y_back");
	cv::imshow("-y_back", img_cube[3]);
	
	cv::namedWindow("+z_top");
	cv::imshow("+z_top", img_cube[4]);
	
	cv::namedWindow("-z_bottom");
	cv::imshow("-z_bottom", img_cube[5]);
	cv::waitKey(0);
}

void SphereToCube::saveDstImage() const
{
	const bool saveSuccess = cv::imwrite("output/dst.png", img_src);
	for (int i = 0; i < img_cube.size(); ++i)
		cv::imwrite(dstName[i], img_cube[i]);
}

void SphereToCube::preProcess()
{
	cv::rotate(img_cube[0], img_textures[0], cv::ROTATE_90_COUNTERCLOCKWISE);
	cv::rotate(img_cube[1], img_textures[1], cv::ROTATE_90_CLOCKWISE);
	cv::rotate(img_cube[2], img_textures[2], cv::ROTATE_180);
	img_textures[3] = img_cube[3].clone();
	//img_textures[4] = img_cube[4].clone();
	cv::rotate(img_cube[4], img_textures[4], cv::ROTATE_180);
	img_textures[5] = img_cube[5].clone();
}


bool SphereToCube::generateTextures()
{
	preProcess();
	cv::Mat textures(viewLength, 6 * viewLength, CV_8UC3, cv::Scalar(0, 0, 0));
	for (int i = 0; i < img_cube.size(); ++i)
	{
		for (int v = 0; v < viewLength; ++v)
		{
			for (int u = 0; u < viewLength; ++u)
			{
				textures.at<cv::Vec3b>(v, u + i * viewLength) = img_textures[i].at<cv::Vec3b>(v, u);
			}
		}
	}

	return cv::imwrite("output/textures.png", textures);

}


