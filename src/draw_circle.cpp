#include <opencv2/opencv.hpp> 
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string>
#include <iostream>
#include <vector>
#include "./shape_gen.cpp"
 
using namespace cv;


Mat line_circle(int x, int y){
     // Create black empty images
  Mat image = Mat::zeros( 64, 64, CV_8UC3 );
  image = Scalar(255,255,255);
  circle(image, Point(x,y),16, Scalar(0,0,0),CV_DIST_L2, 8,0);
  //imshow("Image",image);
  /*
  circle 	( 	InputOutputArray  	img,
		Point  	center,
		int  	radius,
		const Scalar &  	color,
		int  	thickness = 1,
		int  	lineType = LINE_8,
		int  	shift = 0 
	) 	
  */
   return image;
}

void write_file(String filename){
    std::vector<int> coordinate = randomise_origin();
    int x = coordinate[0];
    int y = coordinate[1];
    Mat image = line_circle(x,y);
    imwrite(filename, image);
}