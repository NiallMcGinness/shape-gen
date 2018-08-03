
#include "generatePNG.h"
#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <unistd.h>
#include <vector>
#include <opencv2/opencv.hpp> 
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


using namespace cv;

GeneratePNG::GeneratePNG() { 
  this->outputDirectory = "output/"; 
  this->randomScaleSet = true;
}

void GeneratePNG::setOutputDirectory(String output_directory) {

  srand((unsigned)time(NULL) * getpid());
  this->outputDirectory = output_directory;
}

void GeneratePNG::genCircle(String id_string) {

  String filePath = createFilepath(id_string);
  cout << filePath << endl;

  vector<int> center_Points = randomise_center_Points();
  
  int x = center_Points[0];
  int y = center_Points[1];
  int radius = 12;

  Mat image = Mat::zeros( w, w, CV_8UC3 );
  image.setTo(Scalar(240,240,240));
  //image = Scalar(255,255,255);
  circle(image, Point(x,y),radius, Scalar(0,0,0),0, 8,0);
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
  imwrite(filePath,image);
}

void GeneratePNG::genStar(String id_string) {
  String filePath = createFilepath(id_string);
  

  //String s = randomise_star(star);
   Mat image = Mat::zeros( w, w, CV_8UC3 );

    // set background colour to light gray 
    image.setTo(Scalar(240,240,240));
    vector<Point> vector_of_points = randomise_star_Points();

    int lineType = LINE_8;


    const Point *points = (const Point*) Mat(vector_of_points).data;
    int number_of_points = Mat(vector_of_points).rows;

    polylines(image, &points, &number_of_points, 1, true, Scalar( 200, 200, 200));

    imwrite(filePath,image);
}

void GeneratePNG::genSquare(String id_string) {
  String filePath = createFilepath(id_string);
   cout << filePath << endl;
  //Stringsquare = randomise_origin(square_template);
  //square = randomise_square_size(square);
  Mat image = Mat::zeros( w, w, CV_8UC3 );

    // set background colour to light gray 
    image.setTo(Scalar(240,240,240));
    

    int lineType = LINE_8;

    vector<Point> vector_of_points = randomise_vector_rectangle_Points();
    const Point *points = (const Point*) Mat(vector_of_points).data;
    int number_of_points = Mat(vector_of_points).rows;

    polylines(image, &points, &number_of_points, 1, true, Scalar( 200, 200, 200));

    imwrite(filePath,image);
}

void GeneratePNG::genBlank(String id_string) {
  String filePath = createFilepath(id_string);
  cout << filePath << endl;
   Mat image = Mat::zeros( w, w, CV_8UC3 );
    image.setTo(Scalar(240,240,240));
    imwrite(filePath,image);
}

int GeneratePNG::random_origin_generator() {

  int r = (rand() % 45) + 5;
  return r;
}

vector<int> GeneratePNG::randomise_center_Points(){
  // for rect and circle PNG mark up ,  set ran x and y coordinates
  
    int x = rand() % w ;
    int y = rand() % w ;

    vector<int> coord = { x , y };

    return coord;
}

String GeneratePNG::createFilepath(String id_string) {
  String filePath = this->outputDirectory + id_string;
  return filePath;
}

vector<Point> GeneratePNG::randomise_star_Points() {
    // returns a string of x,y coordinates for PNG polygon position markup
  // each value seperated by a comma
  // each pair of values spearated by a space
  int x = rand() % 25;
  int y = rand() % 25;

  // get random number and use this to pick the sign
  // we want positive and negative numbers to move our position around
  // as we are modifying a base string that is centerish

  if ((rand() % 2) == 0)
    x = x * -1;
  if ((rand() % 2) == 0)
    y = y * -1;

  
  vector< vector<float> > base_vector = {{35,7}, {37,16}, {46,16}, {39,21},
                                     {42,30}, {35,25}, {27,30}, {30,21 },
                                     {23,16}, {32,16}};
   
  // declare size of 2D vector based on 
  vector<Point> vector_of_points;

  
  float x_coord, y_coord;
  for (double i = 0; i < base_vector.size(); i++) 
  {
   // coordinate_pair = { base_vector[i][0] + x ,  base_vector[i][1] + y }   
    x_coord = base_vector[i][0] + x;
    y_coord = base_vector[i][1] + y;
    vector_of_points.push_back(Point(x_coord, y_coord));
   
  }
  
  return vector_of_points;
}



vector<Point> GeneratePNG::randomise_vector_rectangle_Points()
{
    float width_of_rect = 16;
    float height_of_rect = 16;

    float left_point_x = ( w/2 ) - ( width_of_rect / 2  ) ;
    float right_point_x = ( w/2 ) + ( width_of_rect / 2  ) ;
    
    float top_point_y =  ( w/2 ) - ( height_of_rect / 2  ) ;
    float bottom_point_y = ( w/2 ) + ( height_of_rect / 2  ) ;

    vector< vector<float> > base_vector = { { left_point_x , top_point_y  } , { right_point_x , top_point_y   } ,  { right_point_x , bottom_point_y   } ,  { left_point_x , bottom_point_y   } };

    int x = rand() % 25;
    int y = rand() % 25;

    // get random number and use this to pick the sign
    // we want positive and negative numbers to move our position around
    // as we are modifying a base string that is centerish

    if ((rand() % 2) == 0)
        x = x * -1;
    if ((rand() % 2) == 0)
        y = y * -1;

    // declare size of 2D vector based on 
    vector<Point> vector_of_points;

    float x_coord, y_coord;
    for (int i = 0; i < base_vector.size(); i++) 
    {
        x_coord = base_vector[i][0] + x;
        y_coord = base_vector[i][1] + y;
        vector_of_points.push_back(Point(x_coord, y_coord));

    }
    
  
    return vector_of_points;

}

