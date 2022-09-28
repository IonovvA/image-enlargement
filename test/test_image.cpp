#include "Image.h"
#include "EPImage.h"
#include "APImage.h"

#include <gtest.h>

TEST(test_lib, read_file_txt_test)                 //Тест: правильно ли проходит копирование из текстового файла
{
	EPImage img("Test_read.txt");
	int v = img.Pixel(0, 0);
	EXPECT_EQ(1000, v);
}

TEST(test_lib, read_file_bin_test)                 //Тест: правильно ли проходит копирование из бинарного файла 
{
	APImage img("Test_read.bin");
	int v = img.Pixel(0, 0);
	EXPECT_EQ(1000, v);
}

TEST(test_lib, Image_enlargement_test)             //Тест: правильно ли проходит увеличение изображения
{
	Image img(2, 2);
	img.Pixel(0, 0) = 1000;
	img.Pixel(0, 1) = 600;
	img.Pixel(1, 0) = 600;
	img.Pixel(1, 1) = 1000;
	img.Image_enlargement();
	int v = img.Pixel(1, 1);
	EXPECT_EQ(800, v);
}

TEST(test_lib, write_file_txt_test)                 //Тест: правильно ли проходит запись в текстовый файл
{
	EPImage img("Test_read.txt");
	img.Image_to_file("Test_write.txt");
	int v;
	ifstream file;
	file.open("Test_write.txt");
	file >> v;
	file.close();
	EXPECT_EQ(1000, v);
}

TEST(test_lib, write_file_bin_test)                 //Тест: правильно ли проходит запись в бинарный файл
{
	APImage img("Test_read.bin");
	img.Image_to_file("Test_write.bin");
	int v;
	ifstream file;
	file.open("Test_write.bin", ios::binary);
	file.read((char*)&v, sizeof(int));
	file.close();
	EXPECT_EQ(1000, v);
}

