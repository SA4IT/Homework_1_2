#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>;
#include<stdlib.h>
#include <string>;
#include<fstream>;
#include<vector>;

struct Complex {
	double re;
	double im;
};
double Module(Complex a);
void Result(double massive[], int size);
#endif
