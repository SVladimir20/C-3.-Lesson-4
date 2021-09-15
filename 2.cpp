#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	vector<double> vec(100);
	double angle = 0.0;
	generate(vec.begin(), vec.end(), [&angle](const double pi = atan(1.0) * 4)
		mutable {angle += (2 * pi / 100); return (32 * sin(angle) + 100); });
	cout << "Аналоговый:" << endl;
	copy(vec.begin(), vec.end(), ostream_iterator<double>{cout, "\t"});
	cout << endl;
	vector<double> v;
	auto digital = [](double d) {return trunc(d); };
	transform(vec.begin(), vec.end(), back_inserter(v), digital);
	cout << "Цифровой:" << endl;
	copy(v.begin(), v.end(), ostream_iterator<double>{cout, "\t"});
	cout << endl;
	vector<double> e;
	transform(vec.begin(), vec.end(), v.begin(), back_inserter(e), [](double i, double j)
		{return pow((i - j), 2); });
	cout << "Погрешность = " << accumulate(begin(e), end(e), decltype(e)::value_type(0.0)) << endl;
	return 0;
}