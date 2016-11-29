// test3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>


int Braille(cv::Mat &image) {
	// &image�� �о���� �̹���
	int total = 0;
	
	//////����ȭ////
	int height, width;
	int i, j;

	height = image.rows; // height ������ ����
	width = image.cols;  // width ������ ���α���
	std::cout << height << std::endl;
	std::cout << width << std::endl;

	for (i = 0; i<height; i++)
		for (j = 0; j<width; j++)
		{
			if (image.at<cv::Vec3b>(i, j)[0] > 151 && image.at<cv::Vec3b>(i, j)[1] > 151 && image.at<cv::Vec3b>(i, j)[2] > 151) // �ȼ� ���� �Ӱ谪 128���� ũ�� ���
				image.at<cv::Vec3b>(i, j)[0] = image.at<cv::Vec3b>(i, j)[1] = image.at<cv::Vec3b>(i, j)[2] = 255;

			else { // 128���� ������ ������
				image.at<cv::Vec3b>(i, j)[0] = 255;
			}
		}
	//cv::namedWindow("Img1");
	//cv::imshow("Img1", image);
	//cv::imwrite("slated.bmp", image);
	//cv::waitKey(0);


	//////���� �ڸ���/////
	cv::Mat img1 = image(cv::Range(0, image.rows), cv::Range(0, image.cols / 4));
	cv::Mat img2 = image(cv::Range(0, image.rows), cv::Range(image.cols/4, image.cols / 2.2));
	cv::Mat img3 = image(cv::Range(0, image.rows), cv::Range(image.cols/2.2, image.cols / 1.4));
	cv::Mat img4 = image(cv::Range(0, image.rows), cv::Range(image.cols/1.4, image.cols));
	/////////////////////
	/*
	cv::imshow("IMG1", img1);
	cv::waitKey(500);
	cv::imshow("IMG2", img2);
	cv::waitKey(500);
	cv::imshow("IMG3", img3);
	cv::waitKey(500);
	cv::imshow("IMG4", img4);
	cv::waitKey(0);
	*/
	int one_x = img4.rows / 4;  
	int one_y = img4.cols / 4; // cols�� rows�� ���ڷ� ������ ��ǥ ����
	
	int two_x = img4.rows / 2; 
	int two_y = img4.cols / 4;
	
	int three_x = img4.rows / 1.4; 
	int three_y = img4.cols / 4; 
	
	int four_x = img4.rows / 4; 
	int four_y = img4.cols / 1.4;
	
	int five_x = img4.rows / 2; 
	int five_y = img4.cols / 1.4;

	int six_x = img4.rows / 1.4; 
	int six_y = img4.cols / 1.4;
	
	// x = image.at<cv::Vec3b>(one_x, one_y)[0]; // �ȼ��� Ȯ��
	// std::cout << x << std::endl;

	if (image.at<cv::Vec3b>(one_x, one_y)[0] < 100)
	{
		//std::cout << "WHITE!!!!!" << std::endl;
		total = total + 1;
	}

	if (image.at<cv::Vec3b>(two_x, two_y)[0] < 100)
	{
		//std::cout << "BLACK!!!!!" << std::endl;
		total = total + 2;
	}
	
	if (image.at<cv::Vec3b>(three_x, three_y)[0] < 100)
	{
		//std::cout << "WHITE!!!!!" << std::endl;
		total = total + 4;
	}

	if (image.at<cv::Vec3b>(four_x, four_y)[0] < 100)
	{
		//std::cout << "BLACK!!!!!" << std::endl;
		total = total + 8;
	}
	
	if (image.at<cv::Vec3b>(five_x, five_y)[0] < 100)
	{
		//std::cout << "WHITE!!!!!" << std::endl;
		total = total + 16;
	}

	if (image.at<cv::Vec3b>(six_x, six_y)[0] < 100)
	{
		//std::cout << "BLACK!!!!!" << std::endl;
		total = total + 32;
	}

		/*��ǥ Ȯ�� ��*/
		//image.at<cv::Vec3b>(one_x, one_y)[0] = 0;
		//image.at<cv::Vec3b>(one_x, one_y)[1] = 0;
		//image.at<cv::Vec3b>(one_x, one_y)[2] = 0;

	return total;
}

int main()
{
	
	int tot = 0;

	cv::Mat image = cv::imread("����ȭ2.jpg"); // ���� ��ġ�� �������� ����� ���� "../����_��.jpg" ����

	tot = Braille(image);
	// std::cout << "total = " << tot << std::endl;

	

	if (tot == 8)
		std::cout << "�ش� ���ڴ� = �� �Դϴ�" << std::endl;
	else if (tot == 9)
		std::cout << "�ش� ���ڴ� = �� �Դϴ�" << std::endl;
	else if (tot == 10)
		std::cout << "�ش� ���ڴ� = �� �Դϴ�" << std::endl;
	else if (tot == 16)
		std::cout << "�ش� ���ڴ� = �� �Դϴ�" << std::endl;
	else if (tot == 17)
		std::cout << "�ش� ���ڴ� = �� �Դϴ�" << std::endl;
	else if (tot == 24)
		std::cout << "�ش� ���ڴ� = �� �Դϴ�" << std::endl;
	else if (tot == 32)
		std::cout << "�ش� ���ڴ� = �� �Դϴ�" << std::endl;
	else if (tot == 7)
		std::cout << "�ش� ���ڴ� = �� �Դϴ�" << std::endl; //���� ���� ����(only. ����)
	else if (tot == 40)
		std::cout << "�ش� ���ڴ� = �� �Դϴ�" << std::endl;
	else if (tot == 48)
		std::cout << "�ش� ���ڴ� = �� �Դϴ�" << std::endl;
	else if (tot == 11)
		std::cout << "�ش� ���ڴ� = �� �Դϴ�" << std::endl;
	else if (tot == 19)
		std::cout << "�ش� ���ڴ� = �� �Դϴ�" << std::endl;
	else if (tot == 25)
		std::cout << "�ش� ���ڴ� = �� �Դϴ�" << std::endl;
	else if (tot == 26)
		std::cout << "�ش� ���ڴ� = �� �Դϴ�" << std::endl;

	cv::imshow("img",image);
	cv::waitKey(0);
	


	/*cv::namedWindow("Image");
	cv::imshow("Image", img4);
	cv::imwrite("slated.bmp", img4);
	cv::waitKey(0);
	*/

	return 0;
}

