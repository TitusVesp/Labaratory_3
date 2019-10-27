#include "Laba_3.h"



void Zadacha8()
{
	cout << "������ ��������� �������� \n\
������� �i�i���� �i����� Ax=b �� �������� " << endl;

	int n = 0;
	setlocale(LC_ALL, "ukr");
	cout << "����i�� �-��� �i�����: " << endl;
	cin >> n;
	double** a = new double* [n], * y = new double[n], * x = new double[n];

	cout << endl << "���i�� ����i�i����: " << endl;
	for (int i = 0; i < n; i++)
	{
		a[i] = new double[n];
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}
	}

	cout << endl << "���i�� �i�����: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "y[" << i << "]= ";
		cin >> y[i];
	}

	SysOut(a, y, n);
	cout << endl << endl;
	x = Gauss(a, y, n);

	if (x != 0) for (int i = 0; i < n; i++)
		cout << "x[" << i << "]=" << x[i] << endl;

	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[]a;
	delete[]x;
	delete[]y;

	return;
}

void SysOut(double** a, double* y, int n)
{
	cout << endl << "���i �i������: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << "*x" << j;
			if (j < n - 1)
				cout << " + ";
		}
		cout << " = " << y[i] << endl;
	}
}

double* Gauss(double** a, double* y, int n)
{
	double* x = new double[n], max = 0;
	int k = 0, index = 0;
	const double eps = 0.00001;  // ����i���

	while (k < n)
	{
		// ���������� ������  � ���� ���������
		max = abs(a[k][k]);
		index = k;
		for (int i = k + 1; i < n; i++)
		{
			if (abs(a[i][k]) > max)
			{
				max = abs(a[i][k]);
				index = i;
			}
		}
		// ����������i�
		if (max < eps)
		{
			// �����i��� �� ������i ��������
			cout << "�i����� �� ������� �������� ���� ������� � ��������!" << endl;
			return 0;
		}

		for (int j = 0; j < n; j++)
		{
			double temp = a[k][j];
			a[k][j] = a[index][j];
			a[index][j] = temp;
		}

		double temp = y[k];
		y[k] = y[index];
		y[index] = temp;

		// ���������� ������i �� ����������� �������
		for (int i = k; i < n; i++)
		{
			double temp = a[i][k];

			if (abs(temp) < eps)
				continue;					 // ���� 0 ���� �� ����������

			for (int j = 0; j < n; j++)
				a[i][j] = a[i][j] / temp;

			y[i] = y[i] / temp;

			if (i == k)
				continue;      // �� �i��i���� ����� ����� ����

			for (int j = 0; j < n; j++)
				a[i][j] = a[i][j] - a[k][j];

			y[i] = y[i] - y[k];
		}
		k++;
	}

	//�i����� �� ��������
	for (k = n - 1; k >= 0; k--)
	{
		x[k] = y[k];

		for (int i = 0; i < k; i++)
			y[i] = y[i] - a[i][k] * x[k];

	}

	return x;
}



void Zadacha15()
{
	cout << "	���� �����i� f(x). ������ �i�i��� �����i� ax+b,\n\
��� ��������� ����� ��������� ��. ����������� ����� ��������� �������i�." << endl;

	setlocale(LC_ALL, "ukr");
	double a = 0, b = 0, x = 0, y = 0, c = 0, d = 0, e = 0, f = 0;
	char choice = 0;
	int n = 0;

	cout << "������ x �� y: " << endl;
	while (choice != 48)
	{
		n++;
		cout << "x = ";
		cin >> x;
		cout << "y = ";
		cin >> y;
		cout << endl << "��� ���������� �������, �� ����i�� Enter, ��� ���i����� 0!" << endl;

		c += x;
		d += x * x;
		e += x * y;
		f += y;

		b = ((n * e) - (c * f)) / ((n * d) - (c * c)); //����i�i���� a i b �� ���������
		a = (e - (d * b)) / c;

		choice = _getche();
	}

	system("cls");
	bool temp = a > a - 100;
	if (temp)
		cout << "���������: " << endl << "a = " << a << endl << "b = " << b << endl;
	else cout << "�� �������� �������, �� ��� ����� a i b ��i���! " << endl;

	//http://www.geol.univ.kiev.ua/lib/zhukov_n_n/MC_5-6.pdf - ����������� �i��������
}
