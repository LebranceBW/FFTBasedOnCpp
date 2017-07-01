/*
 * Complex.h
 *
 *  Created on: 2017Äê7ÔÂ1ÈÕ
 *      Author: LebrancBW
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_
#include <iostream>
using std::ostream;
using std::istream;
	class Complex
	{
		private:
			double real,im;
		public:
			friend ostream& operator<<(ostream &os,const Complex &tmp);
//			friend istream& operator>>(istream &is,Complex &tmp);
			Complex();
			Complex(double Real,double Im=0);
			Complex operator+(const Complex c2);
			Complex operator-(const Complex c2);
			Complex& operator=(const Complex c2);
			Complex operator*(const Complex c2);
			bool operator==(const Complex c2);

	};


#endif /* COMPLEX_H_ */
