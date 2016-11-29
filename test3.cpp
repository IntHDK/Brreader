// test3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>


int Braille(cv::Mat &image) {
	// &image는 읽어들인 이미지
	int total = 0;
	
	//////이진화////
	int height, width;
	int i, j;

	height = image.rows; // height 사진의 높이
	width = image.cols;  // width 사진의 가로길이
	std::cout << height << std::endl;
	std::cout << width << std::endl;

	for (i = 0; i<height; i++)
		for (j = 0; j<width; j++)
		{
			if (image.at<cv::Vec3b>(i, j)[0] > 151 && image.at<cv::Vec3b>(i, j)[1] > 151 && image.at<cv::Vec3b>(i, j)[2] > 151) // 픽셀 값이 임계값 128보다 크면 흰색
				image.at<cv::Vec3b>(i, j)[0] = image.at<cv::Vec3b>(i, j)[1] = image.at<cv::Vec3b>(i, j)[2] = 255;

			else { // 128보다 작으면 검은색
				image.at<cv::Vec3b>(i, j)[0] = 255;
			}
		}
	//cv::namedWindow("Img1");
	//cv::imshow("Img1", image);
	//cv::imwrite("slated.bmp", image);
	//cv::waitKey(0);


	//////사진 자르기/////
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
	int one_y = img4.cols / 4; // cols와 rows를 숫자로 나누어 좌표 설정
	
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
	
	// x = image.at<cv::Vec3b>(one_x, one_y)[0]; // 픽셀값 확인
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

		/*좌표 확인 툴*/
		//image.at<cv::Vec3b>(one_x, one_y)[0] = 0;
		//image.at<cv::Vec3b>(one_x, one_y)[1] = 0;
		//image.at<cv::Vec3b>(one_x, one_y)[2] = 0;

	return total;
}

int main()
{
	
	int tot = 0;

	cv::Mat image = cv::imread("이진화2.jpg"); // 현재 위치를 기준으로 상대경로 가능 "../점자_ㄱ.jpg" 형식

	tot = Braille(image);
	// std::cout << "total = " << tot << std::endl;

	

	if (tot == 8)
		std::cout << "해당 점자는 = ㄱ 입니다" << std::endl;
	else if (tot == 9)
		std::cout << "해당 점자는 = ㄴ 입니다" << std::endl;
	else if (tot == 10)
		std::cout << "해당 점자는 = ㄷ 입니다" << std::endl;
	else if (tot == 16)
		std::cout << "해당 점자는 = ㄹ 입니다" << std::endl;
	else if (tot == 17)
		std::cout << "해당 점자는 = ㅁ 입니다" << std::endl;
	else if (tot == 24)
		std::cout << "해당 점자는 = ㅂ 입니다" << std::endl;
	else if (tot == 32)
		std::cout << "해당 점자는 = ㅅ 입니다" << std::endl;
	else if (tot == 7)
		std::cout << "해당 점자는 = ㅇ 입니다" << std::endl; //ㅇ은 점자 없음(only. 약자)
	else if (tot == 40)
		std::cout << "해당 점자는 = ㅈ 입니다" << std::endl;
	else if (tot == 48)
		std::cout << "해당 점자는 = ㅊ 입니다" << std::endl;
	else if (tot == 11)
		std::cout << "해당 점자는 = ㅋ 입니다" << std::endl;
	else if (tot == 19)
		std::cout << "해당 점자는 = ㅌ 입니다" << std::endl;
	else if (tot == 25)
		std::cout << "해당 점자는 = ㅍ 입니다" << std::endl;
	else if (tot == 26)
		std::cout << "해당 점자는 = ㅎ 입니다" << std::endl;

	cv::imshow("img",image);
	cv::waitKey(0);
	


	/*cv::namedWindow("Image");
	cv::imshow("Image", img4);
	cv::imwrite("slated.bmp", img4);
	cv::waitKey(0);
	*/

	return 0;
}

