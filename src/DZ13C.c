#include "DZ13C.h"

#define WIDTH 100
#define HEIGHT 100

int main()
{
	int size = WriteSize();

	double *originalSinus =  malloc(size * sizeof(double));

	FillArrSinus(size, originalSinus);

	srand(time(0));

	double *noiseSinus = malloc(size * sizeof(double));

	FillArrNoiseSinus(size, originalSinus, noiseSinus);

	PrintConsole(size, originalSinus,"Base SinusArr");
	PrintConsole(size, noiseSinus,"Noise SinusArr");

	/*for (int y = HEIGHT; y >= 0; y--)
	{
		for (int x = 0; x < size; x++)
		{
			if ((int) (signal[x] * (HEIGHT / 2) + HEIGHT / 2) == y)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}*/

	free(originalSinus);
	free(noiseSinus);
	return 0;
}

int WriteSize()
{
	int tempSize;
	printf("Write size arr: ");
	scanf("%d", &tempSize);

	if (tempSize <= 0)
	{
		printf("Error size arr\n ");
		WriteSize();
	}

	return tempSize;
}

void FillArrSinus(int size, double *arr)
{
	double temp;
	for (int i = 0; i < size; i++)
	{
		temp = (double) i / size * 2 * M_PI;
		arr[i] = sin(temp);
	}
}

void FillArrNoiseSinus(int size, double *arr, double *noiseArr)
{
	double noiseTemp;
	for (int i = 0; i < size; i++)
	{
		noiseTemp = (1 + rand() % (10 - 1))*0.01;
		noiseArr[i] = arr[i] + noiseTemp;
	}
}

void PrintConsole(int size, double *arr, char *str)
{
	if (str == NULL)
	{
		str = "NoStr";
	}
	printf("\nArr: %s\n", str);

	for (int i = 0; i < size; i++)
	{
		printf("%f\n", arr[i]);
	}
}
