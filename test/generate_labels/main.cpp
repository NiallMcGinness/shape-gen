#include <random>
#include <iostream>
#include "generate_labels.h"

using namespace std;



int main()
{  
   

    GenerateLabels labels;
    GenerateLabels labels2;

    int number_of_examples = 20;

    string csv = labels.getExamples(number_of_examples);

    cout <<  csv << endl;

    //string csv2 = labels2.getExamples(number_of_examples);
    string csv11 = labels.getExamples(number_of_examples);
    cout << " calling same instance a second time " << csv11 << endl;

    string csv2 = labels2.getExamples(number_of_examples);
    cout << " calling a second new instance the first time " << csv2 << endl;

}