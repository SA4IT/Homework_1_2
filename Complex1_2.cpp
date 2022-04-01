#include "Complex1_2.h"
using namespace std;
double Module(Complex a) {
	double module = sqrt(pow(a.re, 2) + pow(a.im, 2));
	return module;
}
void Result(double massive[], int size) {
	for (int i = 0; i < size; i++) {
		cout << massive[i] << endl;
	}
}