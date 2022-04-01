#include "Complex1_2.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	ifstream OpenFile("Complex1_2.txt");

	if (!OpenFile.is_open()) {
		cout << "Файл не открылся!" << endl;
		system("pause");
		return 0;
	}
	else {
		cout << "Файл открыт!" << endl;
	}
	cout << "\n";

	vector<Complex>massive;//массив комплексных чисел.
	int size = 0;
	cout << "Данные из файла:" << endl;
	cout << "(действительная и мнимая часть комплексных чисел представлены по их модулю)" << endl;
	int f = 1;
	while (!OpenFile.eof()) {
		string String_Complex;
		getline(OpenFile, String_Complex, ' ');
		Complex chislo;
		cout << f << " комплексное число" << endl;
		////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////
		if (String_Complex[0] != '-') {
			string temp_real;
			int nr = 0;
			for (int i = 0; i < String_Complex.size(); i++) {
				if (String_Complex[i] != '+' || String_Complex[i] != '-') {
					temp_real += String_Complex[i];
					nr += 1;
				}
				if (String_Complex[i] == '+' || String_Complex[i] == '-') {
					break;
				}
			}
			string real;
			for (int i = 0; i < nr - 1; i++) {
				real += temp_real[i];
			}
			double X = atof(real.c_str());
			cout << "re: " << X << endl;
			///////////////////////////////////////////////////////////////////////////
			string temp_imagine;
			int ni = 0;
			for (int j = nr; j < String_Complex.size(); j++) {
				if (String_Complex[j] != 'i') {
					temp_imagine += String_Complex[j];
					ni += 1;
				}
				if (String_Complex[j] == 'i') {
					break;
				}
			}
			string imagine;
			for (int i = 0; i < ni + 1; i++) {
				imagine += temp_imagine[i];
			}
			double Y = atof(imagine.c_str());
			cout << "im: " << Y << endl;
			cout << '\n';
			//////////////////////////////////////////////////////////////////////////
			chislo.re = X;
			chislo.im = Y;
			massive.push_back(chislo);
			size += 1;

		}
		////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////
		if (String_Complex[0] == '-') {
			string temp_real;
			int nr = 0;
			for (int i = 1; i < String_Complex.size(); i++) {
				if (String_Complex[i] != '+' || String_Complex[i] != '-') {
					temp_real += String_Complex[i];
					nr += 1;
				}
				if (String_Complex[i] == '+' || String_Complex[i] == '-') {
					break;
				}
			}
			string real;
			for (int i = 0; i < nr - 1; i++) {
				real += temp_real[i];
			}
			double X = atof(real.c_str());
			cout << "re: " << X << endl;
			/// /////////////////////////////////////////////////////////////////////////
			string temp_imagine;
			int ni = 0;
			for (int j = nr + 1; j < String_Complex.size(); j++) {
				if (String_Complex[j] != 'i') {
					temp_imagine += String_Complex[j];
					ni += 1;
				}
				if (String_Complex[j] == 'i') {
					break;
				}
			}
			string imagine;
			for (int i = 0; i < ni; i++) {
				imagine += temp_imagine[i];
			}
			double Y = atof(imagine.c_str());
			cout << "im: " << Y << endl;
			cout << '\n';
			//////////////////////////////////////////////////////////////////////////
			chislo.re = X;
			chislo.im = Y;
			massive.push_back(chislo);
			size += 1;
		}
		f += 1;

	}
	OpenFile.close();
	vector<double>p;
	for (int i = 0; i < size; i++) {
		double temp = Module(massive[i]);
		p.push_back(temp);
		cout << "Модуль " << i + 1 << "-го комплексного числа = " << p[i] << endl;
	}
	double max = 0;
	int maxind = 0;
	for (int i = 0; i < size; i++) {
		if (p[i] > max) {
			max = p[i];
			maxind = i;
		}
	}
	cout << '\n';
	cout << maxind + 1 << " комплексное число - наибольшее по модулю = " << max << endl;
	return 0;
}