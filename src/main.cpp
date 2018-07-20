//#include "./shape_gen.cpp"
#include "./draw_circle.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(){

    srand(time(NULL));

    int number_of_test_examples = 10;
    string filename("");
    string id("");
    string base_name("data/test/testShape");
    string png(".png");
    for( int i = 0; i < number_of_test_examples; i++){
       id =  to_string(i);
       filename = base_name + id + png;
       //vector<int> coordinate = randomise_origin();        
       cout << filename << "\n";
       //printf("x : %d  ,  y : %d \n", coordinate[0], coordinate[1]);
       write_file(filename);
    }

    //vector<int> coordinate = randomise_origin();

    //printf("x : %d  ,  y : %d \n", coordinate[0], coordinate[1]);


}