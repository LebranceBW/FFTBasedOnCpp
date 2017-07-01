/*
 * Complex.cpp
 *
 *  Created on: 2017Äê7ÔÂ1ÈÕ
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
