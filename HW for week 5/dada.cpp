/*
DADA function definitions
*/
#include <cmath>
#include "dada.h"

int amax(const double x[], const unsigned int len) {
	double max = 0;
	int position = 0;
	if (len == 0) {
		return -1;
	}
    for (unsigned int i = 0; i < len ; i++) {
		if (abs(x[i]) > max) {
			max = abs(x[i]);
			position = i;
		}
	}
	return position;
}

double asum(const double x[], const unsigned int len) {
	double sum = 0;
	for (unsigned int i = 0; i < len; i++) {
		sum += abs(x[i]);
	}
	
    return sum;
}

void axpy(const double a, const double x[], 
double y[], const unsigned int len) {
    for (unsigned int i = 0; i < len; i++) {
		y[i] = a*x[i] + y[i];
	}	
}

void copy(const double src[], double dest[], const unsigned int len) {
	for (unsigned int i = 0; i < len; i++) {
		dest[i]=src[i];
	}
}

double dot(const double x[], const double y[], const unsigned int len) {
	double dotprod=0;
	for (unsigned int i = 0; i < len; i++) {
	dotprod+=x[i]*y[i];
	}
	
    return dotprod;
}

double norm2(const double x[], const unsigned int len) {
	double norm = 0;
	for (unsigned int i = 0; i < len; i++) {
		norm += pow(x[i], 2);
	}
	norm = pow(norm, .5);
    return norm;
}

void scale(const double a, double x[], const unsigned int len) {
    for (unsigned int i = 0; i < len; i++) {
		x[i] = x[i]*a;
	}
}

void swap(double x[], double y[], const unsigned int len) {
	double swaparray[2];
	for (unsigned int i = 0; i < len; i++) {
	swaparray[0]=x[i];
	swaparray[1]=y[i];
	x[i]=swaparray[1];
	y[i]=swaparray[0];
	
	}
}
