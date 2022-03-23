#ifndef QUADRATIC_H
#define QUADRATIC_H
struct roots {
	int r1,r2;
	bool isQuadratic=true;
	bool hasRealRoots=true;
};

struct roots quadratic(double a, double b, double c);

#endif