#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#ifndef DZ13C_H_
#define DZ13C_H_

int WriteSize();
void FillArrSinus(int size, double *arr);
void FillArrNoiseSinus(int size, double *arr, double *noiseArr);
void PrintConsole(int size, double *arr, char *str);
void PrintConsoleGraph(int size,double *arr);

#endif
