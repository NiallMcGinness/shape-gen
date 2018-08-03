#include <random>
#include <string>
#include <iostream>

#include <opencv2/opencv.hpp> 
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#ifndef GENERATEPNG_H_INCLUDED
#define GENERATEPNG_H_INCLUDED

#define w 64
using namespace std;
using namespace cv;

class GeneratePNG {

public:
  GeneratePNG();
  //explicit GenerateRandomScales() : mt{rd()}, distribution{1, 2} {};
  bool randomiseScale(bool);
  void setOutputDirectory(String output_directory);
  void genCircle(String filename);
  void genStar(String filename);
  void genSquare(String filename);
  void genBlank(String filename);

private:
  int random_origin_generator();
  vector<int> randomise_center_Points();
  vector<Point> randomise_star_Points();
  vector<Point> randomise_vector_rectangle_Points();
  string createFilepath(string);
  string outputDirectory;
  bool randomScaleSet;
 

  string randomise_star(string);
};

#endif