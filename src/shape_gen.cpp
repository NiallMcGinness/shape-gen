#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int random_origin_generator(){

    int r = ( rand() % 45 ) + 5; 
    return r;
}


int randomise_origin(){
    // for rect and circle svg mark up ,  set ran x and y coordinates
    
    
    int x = random_origin_generator();
    //int y = random_origin_generator();


    return x;
}
/*
void genCircle( string id_string ){

    string filePath = createFilepath(id_string);
    ofstream outputFile;
    outputFile.open(filePath);

    string svg_header ("<svg width='64' height='64' viewBox='0 0 64 64' xmlns='http://www.w3.org/2000/svg'> <rect width='100%' height='100%' fill='white'/>");
    string circle_template ("<circle cx='<x>' cy='<y>' r='8' fill='white' stroke='black' stroke-width='3' />");
    string circle = randomise_origin(circle_template);
    string svg_escape ("</svg>");
    
    string all = svg_header + circle + svg_escape;
    outputFile << all;
    outputFile.close();
}

*/