#include <iostream>
#include <clocale>
#include "Image.h"
#include "EPImage.h"
#include "APImage.h"

using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");

    string file_txt = "File.txt";
    string file_bin = "File.bin";

    cout << "НАСЛЕДОВАНИЕ" << endl;                                                 
    EPImage Eimg(file_txt);
    cout << "Изображение из файла:" << endl;
    Eimg.Print();

    EPImage Eimg2(Eimg);

    Eimg2.Image_enlargement();
    cout << "Увеличенное изображение:" << endl;
    Eimg2.Print();

    Eimg2.Image_to_file(file_txt);
    
    
    cout << "АГРЕГАЦИЯ" << endl;                                                             
    APImage Aimg(file_bin);
    cout << "Изображение из файла:" << endl;
    Aimg.Print();
    
    Aimg.Image_enlargement();
    cout << "Увеличенное изображение:" << endl;
    Aimg.Print();

    Aimg.Image_to_file(file_bin);
    
   
    return 0;
}