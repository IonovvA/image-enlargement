#pragma once
#include "Image.h"
#include <fstream>
#include <iostream>
using namespace std;

class APImage
{
private:
    Image* img;
    ifstream fin;    
    ofstream fout;
public:
    APImage(string name);
    void Print();
    int Pixel(int _h, int _w);
    void Image_enlargement();
    void Image_to_file(string name);
    ~APImage();
};