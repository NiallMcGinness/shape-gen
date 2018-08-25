#include <random>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "generate_labels/generate_labels.h"
#include "gen_shape/generatePNG.h"

using namespace std;


void build_PNG(string csv, string output_directory);
void select_shape_to_generate(string shape_type, string file_name, GeneratePNG PNG_obj);


int main()
{  
    
    string output_dir("data/");
    string test_dir = output_dir + "test/";
    string train_dir = output_dir + "train/";
    string test_label_filepath = output_dir + "labels/test.csv";
    string train_label_filepath = output_dir + "labels/train.csv";

    GenerateLabels labels;

    int number_of_test_examples = 1000;
    string test_csv = labels.getExamples(number_of_test_examples);
    build_PNG(test_csv, test_dir);

    ofstream test_label_outputfile;
    test_label_outputfile.open(test_label_filepath);
    test_label_outputfile << test_csv;
    test_label_outputfile.close();

    int number_of_train_examples = 10000;
    string train_csv = labels.getExamples(number_of_train_examples);
    build_PNG(train_csv, train_dir);

    ofstream train_label_outputfile;
    train_label_outputfile.open(train_label_filepath);
    train_label_outputfile << train_csv;
    train_label_outputfile.close();

}


void build_PNG(string csv, string output_directory)
{
    string row;
    stringstream stream(csv);
    vector<string>  vector_of_rows;
   

    while( getline(stream,row)  ) 
    {
        vector_of_rows.push_back(row);
    }
   
    GeneratePNG PNG_obj;
    //
    PNG_obj.setOutputDirectory(output_directory);

    string id_number, file_name, shape_type;
    for(std::vector<string>::iterator it = vector_of_rows.begin() + 1; it != vector_of_rows.end(); ++it) 
    {
        row = *it;
        
        size_t comma_pos = row.find(",");

        id_number = row.substr(0,comma_pos);
        file_name = id_number + ".png";
        shape_type = row.substr(comma_pos + 1 );

        select_shape_to_generate(shape_type, file_name, PNG_obj);
    }


}

void select_shape_to_generate(string shape_type, string file_name, GeneratePNG PNG_obj)
{
    if ( shape_type == "circle" )
        PNG_obj.genCircle(file_name);
    else if ( shape_type == "square" )
        PNG_obj.genSquare(file_name);
    else if ( shape_type == "star" )
        PNG_obj.genStar(file_name);
    else
        PNG_obj.genBlank(file_name);  
}