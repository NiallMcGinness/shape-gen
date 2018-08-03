
#include "generate_labels.h"
#include <chrono>
#include <iostream>
#include <random>
#include <string>

using namespace std;
/*
GenerateLabels::GenerateLabels()
{


    mt{ rd(); };
    distribution{0, 255};

}
*/

string GenerateLabels::getExamples(int number_of_examples) {

  int shape_type;

  this->csv = "ID,SHAPE_TYPE\n";

  string comma(",");
  string new_line("\n");

  string id("");
  string shape_selected("");
  string next_line;

  for (int i = 0; i < number_of_examples; ++i) {

    shape_type = this->get_random_shape_value();
    // cout <<  shape_type << endl;
    shape_selected = this->select_shape(shape_type);
    id = to_string(i);

    this->csv += id + comma + shape_selected + new_line;

    // cout <<  this->csv << endl;
  }

  return this->csv;
}

int GenerateLabels::get_random_shape_value() { return distribution(mt); }

string GenerateLabels::select_shape(int t) {
  enum shape_options { circle, star, square };

  t = shape_options(t);

  string shape_type("");

  switch (t) {

  case circle: {

    shape_type = "circle";
  } break;

  case star: {

    shape_type = "star";
  } break;

  case square: {

    shape_type = "square";
  } break;

  default: { shape_type = "blank"; }
  }

  return shape_type;
}