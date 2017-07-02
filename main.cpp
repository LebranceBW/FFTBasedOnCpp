/*
 * main.cpp
 *
 *  Created on: 2017年7月1日
 *      Author: LebrancBW
 */

#include "Complex.h"
#include <cstdio>
#include <iostream>
#include <math.h>
using std::cout;
using std::endl;
using std::printf;
int main()
{
	unittest();
	const int SCALE = 16;
	const double M_PI = 3.14159265358979323846;
	const int SCALEBITS = 4; //定义规模与需要的比特数
	Complex rawData[SCALE]={5,7,6,2,9,1,4,7,0,6,0,14,0,7,8,15};
	int step = 1;//定义step作为单步步长，可以理解为每次蝶式运算时跨越的步长
	Complex butterflyBuffer[SCALE];//蝶式运算的缓存区
	unsigned char stack = 0;
	cout<<"序列倒序结果：";
	for(unsigned char counter=0;counter<SCALE;counter++)
	{
		unsigned char temp = counter;
		for(unsigned int i=0;i<SCALEBITS;i++)
			{
				stack = (stack << 1) + (temp&0x01);//取最低位
				temp>>=1;
			}
		if(stack>=0&&stack<SCALE)
		{
			butterflyBuffer[counter] = rawData[stack];
			cout<<"	"<<(int)counter<<"->"<<(int)stack<<endl;
		}
		else
			cout<<"error occurred"<<" stack is"<<stack<<endl;
		stack = 0;
	}//FFT的倒序存入

	cout<<"蝶式运算"<<endl;
	for(;step<SCALE;step *= 2)//第一层循环，从左到右
	{
		static int i = 0;
		i++;
		cout<<"第"<<step<<"阶："<<endl;
		for(int butterIndex = 0;butterIndex<SCALE;butterIndex +=step*2)//第二层循环，遍历每列的蝶式运算
		{
			cout<<"	第"<<butterIndex<<"只蝶"<<endl;
			for(int wingIndex = 0;wingIndex<step;wingIndex++)//第三层循环，遍历每个蝴蝶的翅膀
			{
				Complex temp = butterflyBuffer[butterIndex+wingIndex];
				double tempNumber =2* M_PI *wingIndex*pow(2,SCALEBITS-i)/SCALE;	//旋转因子W(k,N)
				Complex factor(cos(tempNumber),-sin(tempNumber));
				butterflyBuffer[butterIndex+wingIndex] = temp + factor*butterflyBuffer[butterIndex+wingIndex+step];
				butterflyBuffer[butterIndex+wingIndex+step] = temp - factor*butterflyBuffer[butterIndex+wingIndex+step];
				printf("		第%d只翼，完成的是X[%d]与X[%d]的蝶式运算,旋转因子是W%d\n",wingIndex,butterIndex+wingIndex,butterIndex+wingIndex+step,(int)(wingIndex*pow(2,SCALEBITS-i)));
			}
		}
	}

	cout<<"运算结果："<<endl;//正确结果 91.0000 + 0.0000i  18.0899 + 8.8944i   3.7782 + 6.7071i   6.9164 + 7.1646i   -4.0000 +17.0000i -11.0585 - 8.0069i -11.7782 - 5.2929i   6.0523 +29.7228i  -27.0000 + 0.0000i   6.0523 -29.7228i -11.7782 + 5.2929i -11.0585 + 8.0069i  -4.0000 -17.0000i   6.9164 - 7.1646i   3.7782 - 6.7071i  18.0899 - 8.8944i
	for(auto x:butterflyBuffer)
		cout<<"	"<<x<<endl;

	cout<<"正确结果: \n 91.0000 + 0.0000i  18.0899 + 8.8944i   3.7782 + 6.7071i  \n "
			"6.9164 + 7.1646i   -4.0000 +17.0000i -11.0585 - 8.0069i -11.7782 - 5.2929i \n  6.0523 +29.7228i  -27.0000 + 0.0000i  "
			" 6.0523 -29.7228i -11.7782 + 5.2929i \n -11.0585 + 8.0069i  -4.0000 -17.0000i   6.9164 - 7.1646i   3.7782 - 6.7071i  "
			"18.0899 - 8.8944i "<<endl;
	return 0;
}


