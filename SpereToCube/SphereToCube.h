#pragma once
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <vector>
#include <string>
#include <opencv2/highgui.hpp>
using std::string;
using std::vector;

constexpr double M_PI = 3.14159265359;

class SphereToCube
{
public:
	SphereToCube(const string img_path);
	vector<int> reProjection(const int x_img, const int y_img,const cv::Mat& rot) const;
	vector<double> reProjection(const double x_img, const double y_img, const int direction) const;
	cv::Mat eul2rotm(double rotx, double roty, double rotz);
	void generateCubeMap();
	void showCube() const;
	void saveDstImage() const;
	void preProcess();
	bool generateTextures();
	

private:
	cv::Mat img_src;
	int srcWidth;
	int srcHeight;
	int viewLength;
	vector<cv::Mat> img_cube;
	vector<cv::Mat> img_textures;
	/*vector<cv::Mat> Rot{
		eul2rotm(0, 0, M_PI / 2),
		eul2rotm(0, 0, 0),
		eul2rotm(0, 0, -M_PI / 2),
		eul2rotm(0, 0, M_PI),
		eul2rotm(-M_PI / 2, 0, 0),
		eul2rotm(M_PI / 2, 0, 0)
	};*/
	vector<cv::Mat> Rot{
		//+x - right
		eul2rotm(0, 0, -M_PI / 2),
		//-x - left
		eul2rotm(0, 0, M_PI / 2),
		//+y - front
		eul2rotm(0, 0, 0),
		//-y - back
		eul2rotm(0, 0, M_PI),
		//+z - top
		eul2rotm(-M_PI / 2, 0, 0),
		//-z -bottom
		eul2rotm(M_PI / 2, 0, 0)
	};
	vector<cv::Mat> Euler{
		//+x - right
		eul2rotm(0, 0, -M_PI / 2),
		//-x - left
		eul2rotm(0, 0, M_PI / 2),
		//+y - front
		eul2rotm(0, 0, 0),
		//-y - back
		eul2rotm(0, 0, M_PI),
		//+z - top
		eul2rotm(-M_PI / 2, 0, 0),
		//-z - bottom
		eul2rotm(M_PI / 2, 0, 0)
	};
	vector<cv::Vec3b> color{
		{255,0,0},
		{255,0,189},
		{0,0,255},
		{109,0,255},
		{0,255,0},
		{4,244,235}           
	};
	vector<std::string> dstName{
		"output/px.png",
		"output/nx.png",
		"output/py.png",
		"output/ny.png",
		"output/pz.png",
		"output/nz.png"
	};
};

