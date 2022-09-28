#include "Image.h" 
#include <iostream>
#include <fstream>
using namespace std; 

Image :: Image(int _h, int _w)
{
    this-> h = _h;
    this-> w = _w;
    arr = new int* [h];
    arr[0] = new int[h * w];
    for (int i = 1; i < h; i++)
    {
        arr[i] = arr[0] + i * w;
    }
}

Image :: Image(const Image& a)
{
    h = a.h;
    w = a.w;
    arr = new int* [h];
    for (int i = 0; i < h; i++)
    {
        arr[i] = new int[w];
    }
    for (int i = 0; i < h; i++)
    {
        for (int k = 0; k < w; k++)
        {
            arr[i][k] = a.arr[i][k];
        }
    }
}

Image& Image :: operator =(const Image& img)
{
    if (this == &img)
    {
        return *this;
    }
    for (int i = 0; i < h; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    h = img.h;
    w = img.w;
    arr = new int* [h];
    for (int i = 0; i < h; i++)
    {
        arr[i] = new int[w];
        for (int k = 0; k < w; k++)
        {
            arr[i][k] = img.arr[i][k];
        }
    }
    return *this;
}

int& Image :: Pixel(int _h, int _w)
{
    if (_w < 0 || _h < 0 || _w >= w || _h >= h)
    {
        throw 1;
    }
    return arr[_h][_w];
}

void Image :: Print()
{
    for (int i = 0; i < this->h; i++)
    {
        for (int j = 0; j < this->w; j++)
        {
            cout << this->Pixel(i, j) << " ";
        }
        cout << endl;
    }
}

void Image::Image_enlargement()
{
    Image tmp(*this);
    h = this->h * 2;
    w = this->w * 2;
    arr = new int* [h];
    for (int i = 0; i < h; i++)
        arr[i] = new int[w];

    for (int i = 0; i < h; i++)
        for (int k = 0; k < w; k++)
            if ((i % 2 == 0) & (k % 2 == 0))
                arr[i][k] = tmp.arr[i / 2][k / 2];

    for (int i = 0; i < h; i = i + 2)
        for (int k = 1; k < w; k = k + 2)
            arr[i][k] = (arr[i][k - 1] + arr[i][k + 1]) / 2;

    for (int i = 1; i < h - 1; i = i + 2)
        for (int k = 0; k < w - 1; k++)
            arr[i][k] = (arr[i - 1][k] + arr[i + 1][k]) / 2;

    for (int k = 0; k < w - 1; k++)
        arr[h - 1][k] = arr[h - 2][k];

    for (int i = 0; i < h; i++)
        arr[i][w - 1] = arr[i][w - 2];
}

int Image :: Get_h()
{
    return (this->h);
}

int Image::Get_w()
{
    return (this->w);
}

Image :: ~Image()
{
    delete[] arr[0];
    delete[] arr;
}