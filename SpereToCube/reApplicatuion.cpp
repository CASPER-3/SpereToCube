#include "SphereToCube.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	SphereToCube stb("work_test.jpg");
	/*SphereToCube stb("mirror_r.jpg");*/
	stb.generateCubeMap();
	stb.showCube();
	stb.saveDstImage();
	stb.generateTextures();
	/*double x = 0;
	double y = 0;
	int direction=0;
	cin >> x >> y >> direction;
	vector<double> res = stb.reProjection(x, y, direction);
	cout << "x: " << res[0] << " y: " << res[1] << endl;*/
	

}