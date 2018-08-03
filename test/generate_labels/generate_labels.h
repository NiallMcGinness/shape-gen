#include <random>
#include <string>

#ifndef GENERATE_LABELS_H_INCLUDED
#define GENERATE_LABELS_H_INCLUDED

using namespace std;

class GenerateLabels {

  // using std::string;
public:
  explicit GenerateLabels() : mt{rd()}, distribution{0, 3} {};
  // GenerateLabels()
  string getExamples(int number_of_examples);
  int get_random_shape_value();
  string select_shape(int t);

private:
  string csv, comma, carriage_return;
  random_device rd;
  mt19937 mt;
  uniform_int_distribution<int> distribution;
};

#endif