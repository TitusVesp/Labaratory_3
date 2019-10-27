#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <tchar.h>
#include <cmath>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

using namespace std;

void Zadacha8();
void Zadacha15();

//To Zadacha 8!
double* Gauss(double** a, double* y, int n);
void SysOut(double** a, double* y, int n);


//To Zadacha 15!
void p1();
double* MNK(double* x, double* y, int n, int k);
void PryamoiHod(int n, double** a, double* b);
void ObratniHod(int n, double** a, double* b, double* x);
double F(double x, double* c, int k);