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

    cout << "������������" << endl;                                                 
    EPImage Eimg(file_txt);
    cout << "����������� �� �����:" << endl;
    Eimg.Print();

    EPImage Eimg2(Eimg);

    Eimg2.Image_enlargement();
    cout << "����������� �����������:" << endl;
    Eimg2.Print();

    Eimg2.Image_to_file(file_txt);
    
    
    cout << "���������" << endl;                                                             
    APImage Aimg(file_bin);
    cout << "����������� �� �����:" << endl;
    Aimg.Print();
    
    Aimg.Image_enlargement();
    cout << "����������� �����������:" << endl;
    Aimg.Print();

    Aimg.Image_to_file(file_bin);
    
   
    return 0;
}