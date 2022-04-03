#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include "winbgi2.h"
#include "nonlin.h"
#include <cmath>

double eqn(double *x) {
	return sin(*x);
}

int main()
	{
		double *x, x0, eps;
		int n;
		n = 10;
		x = (double*)malloc(n * sizeof(double));
		if (x == NULL) {
			fprintf(stderr, "malloc: can not allocate t. \n");
			exit(1);
		}
		x0 = 0.0;
		x[0] = -0.628;
		x[1] = 0.523;

		for (int i = 1; i <= 7; i++) {
			x[i+1] = x[i] - (sin(x[i]) * ((x[i] - x[i-1]) / ( (sin(x[i]) - sin(x[i-1])))));
			printf("x[%ld] = %0.13lf \n", i, x[i+1]);
			eps = abs(x[i+1] - x[i]);
			printf("Accuracy = %lf \n \n", eps);
		}
			return 0;
	
}