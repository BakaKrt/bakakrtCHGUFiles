// Test4B.cpp - ��������� ��� �������
#include <iostream>
using namespace std;
int main()
{
	int n, a, b;
	double mul = 1.0, i = 1;
	cin >> n;
	cout << "���������: ";
	for (; i <= n; i = i + 1)
	{
		d = i % 2;
		if (d = 1)
			a = i + 1;
		else
			a = i;
		b = (i % 2 == 1) ? i : i + 1;
		cout << a << "/" << b << " * ";
		mul = a / b * mul;
	}
	cout << "\b\b= " << fixed << setprecision(n) << mul << endl;
}

