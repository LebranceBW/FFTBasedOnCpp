/*
 * main.cpp
 *
 *  Created on: 2017年7月1日
 *      Author: LebrancBW
 */

#include "Complex.h"
#include <iostream>
#include <bitset>
using std::cout;
using std::endl;
using std::bitset;
int main()
{
	const int SCALE = 16;
	const int SCALEBITS = 4; //定义规模与需要的比特数
	Complex rawData[SCALE]={5,7,6,2,9,1,4,7,0,6,0,14,0,7,8,15};
	int step = 1;//定义step作为单步步长，可以理解为每次蝶式运算时跨越的步长
	Complex butterflyBuffer[SCALE];//蝶式运算的缓存区
	unsigned char stack = 0;
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
			cout<<(int)counter<<"->"<<(int)stack<<endl;
		}
		else
			cout<<"error occurred"<<" stack is"<<stack<<endl;
		stack = 0;
	}//倒序插入

	return 0;
}


