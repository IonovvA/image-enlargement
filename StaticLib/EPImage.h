#pragma once
#include "Image.h" 
#include <iostream>
#include <fstream>

using namespace std;

class EPImage : public Image
{

public:
    EPImage(string name) 
    {
        ifstream file;
        file.exceptions(ifstream::badbit | ifstream::failbit);
        
        try
        {
            cout << "Попытка открыть файл" << endl;
            file.open(name);
            cout << "Файл успешно открыт" << endl;
        }
        catch (const std::exception& exc)
        {
            cout << exc.what() << endl;
            cout << "Ошибка открытия файла" << endl;
        }

        file >> h;
        file >> w;

        arr = new int* [h];
        arr[0] = new int[h * w];
        for (int i = 1; i < h; i++)
        {
            arr[i] = arr[0] + i * w;
        }

        try
        {
            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                    file >> this->Pixel(i, j);
            }
            cout << "Изображение скопировано успешно" << endl;
        }
        catch (...)
        {
            cout << "Ошибка доступа к файлу" << endl;
        }

        file.close();
    }

    void Image_to_file(string name)
    {            
        ofstream file;
        file.exceptions(ifstream::badbit | ifstream::failbit);

        try
        {
            cout << "Попытка открыть файл" << endl;
            file.open(name, ios_base::app);                                    // ios_base::app - запись в конец файла
            cout << "Файл успешно открыт" << endl;
        }
        catch (const std::exception& exc)
        {
            cout << exc.what() << endl;
            cout << "Ошибка открытия файла" << endl;
        }
        file << endl;
        for (int i = 0; i < this->h; i++)
        {
            for (int j = 0; j < this->w; j++)
            {
                file << this->Pixel(i, j) << " ";
            }
            file << endl;
        }

        cout << "Увеличенное изображение помещено в файл!" << endl;
        file.close();
    }
};