/*
 * Complex.cpp
 *
 *  Created on: 2017年7月1日
 *      Author: LebrancBW
 */
#include "Complex.h"
#include <iostream>
using std::ostream;
using std::cout;
using std::endl;
using std::cin;
Complex::Complex()
{
	real=im=0;
}
Complex::Complex(const double Real,double Im)
{
	real = Real;
	im = Im;
}
Complex Complex::operator+(const Complex c2)
{
	Complex temp;
	temp.real = real + c2.real;
	temp.im = im + c2.im;
	return temp;
}
Complex Complex::operator-(const Complex c2)
{
	Complex temp;
	temp.real = real - c2.real;
	temp.im = im - c2.im;
	return temp;
}
Complex& Complex::operator=(Complex c2)
{
	real = c2.real;
	im = c2.im;
	return *this;
}
Complex Complex::operator*(Complex c2)
{
	Complex temp;
	temp.real = real * c2.real - im*c2.im;
	temp.im = real * c2.im + im*c2.real;
	return temp;
}
bool Complex::operator==(Complex c2)
{
	return (real == c2.real)&&(im == c2.im);
}
ostream& operator<<(ostream& os,const Complex& tmp)
{
  os << tmp.real;
  if(tmp.im!=0)
	  os<<(tmp.im>0?"+":"")<< tmp.im<< "j";
  return os;
}
bool unittest()
{
	bool testAns = true;
	Complex C1(12,-0.5);
	Complex C2(-2,81);
	Complex C3(1,-5);
	Complex C4(0,0.5);
	Complex ansC1MulC2( 1.6500e+01, 9.7300e+02);
	Complex ansC1MulC3(4.0300e+02, 9.1000e+01);
	Complex ansC1MulC4(-40.5000 , 1.0000);
	cout<<"Complex复数单元测试"<<endl;
	cout<<"	C1 = "<<C1<<endl;
	cout<<"	C2 = "<<C2<<endl;
	cout<<"	C3 = "<<C3<<endl;
	cout<<"	C1 + C2 = "<<C1+C2<<endl;
	cout<<"	C1 - C2 = "<<C1-C2<<endl;
	if(C1*C2==ansC1MulC2)
		cout<<"	C1 * C2 ="<<ansC1MulC2 <<"	answer is Right"<<endl;
	else
		testAns=false;
	if(C1*C2==ansC1MulC2)
			cout<<"	C1 * C3 ="<<ansC1MulC3 <<"	answer is Right"<<endl;
	else testAns=false;
	if(C1*C2==ansC1MulC2)
			cout<<"	C1 * C4 ="<<ansC1MulC4 <<"	answer is Right"<<endl;
	else testAns=false;
	cout<<"单元测试结束"<<endl;
	return testAns;
}
