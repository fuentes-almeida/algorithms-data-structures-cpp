#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <string>
#include "huffman.hpp"
#include <vector>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv)
{
    char* input_filename=argv[1];
    int flag=atoi(argv[2]);
    char output_filename[20]="CompressedFile.txt";

    if (flag==1)
        CompressFile(input_filename, output_filename);

    else if (flag==2)
        DecompressFile(output_filename);

    else
        cout<<"Error: Argument not valid."<<endl;

    return 0;
}
