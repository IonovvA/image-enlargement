#pragma once
#define _CRT_SECURE_NO_WARNINGS

class Image
{
protected:
    int h;
    int w;
    int** arr;

public:
    Image(int _h = 0, int _w = 0);
    Image(const Image& a);
    Image& operator =(const Image& img);
    int& Pixel(int _h, int _w);
    void Print();
    void Image_enlargement();
    int Get_h();
    int Get_w();
    ~Image();
};