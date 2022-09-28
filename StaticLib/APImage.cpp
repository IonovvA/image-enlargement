#include "APImage.h"
#include <iostream>
#include <fstream>

using namespace std;

APImage::APImage(string name)
{
    fin.exceptions(ifstream::badbit | ifstream::failbit);

    try
    {
        cout << "Попытка открыть файл" << endl;
        fin.open(name, ios::binary);
        cout << "Файл успешно открыт" << endl;
    }
    catch (const std::exception& exc)
    {
        cout << exc.what() << endl;
        cout << "Ошибка открытия файла" << endl;
    }

    int h, w;
    fin.read((char*)&h, sizeof(int));
    fin.read((char*)&w, sizeof(int));
    img = new Image(h, w);

    try
    {
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
                fin.read((char*)&(img->Pixel(i, j)), sizeof(int));
        }
        cout << "Изображение скопировано успешно" << endl;
    }
    catch (...)
    {
        cout << "Ошибка доступа к файлу" << endl;
    }

    fin.close();
} 

void APImage::Print()
{
    img->Print();
}

int APImage::Pixel(int _h, int _w)
{
  return img->Pixel(_h, _w);
}

void APImage::Image_enlargement()
{
    img->Image_enlargement();
}

void APImage :: Image_to_file(string name)
{
    fout.exceptions(ifstream::badbit | ifstream::failbit);

    try
    {
        cout << "Попытка открыть файл" << endl;
        fout.open(name, ios::binary | ios_base::app);                                    // ios_base::app - запись в конец файла
        cout << "Файл успешно открыт" << endl;
    }
    catch (const std::exception& exc)
    {
        cout << exc.what() << endl;
        cout << "Ошибка открытия файла" << endl;
    }


    for (int i = 0; i < img->Get_h(); i++)
    {
        for (int j = 0; j < img->Get_w(); j++)
        {
            fout.write((char*)&(img->Pixel(i, j)), sizeof(int));
        }
        fout << endl;
    }

    cout << "Увеличенное изображение помещено в файл!" << endl;
    fout.close();
}

APImage:: ~APImage()
{
    delete img;
}

