#include "./shape_gen.cpp"
#include <iostream>
//#include <string>
//#include <vector>
#include <fstream>
#include <stdlib.h>

int main(){
    srand(time(NULL));

    int t = randomise_origin();

    printf("%d\n", t);

}