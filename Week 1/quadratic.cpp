#include "quadratic.h"
#include <cmath>

struct roots quadratic(double a, double b, double c) {
	struct roots roots= {0,0};
	roots = {(-b-sqrt(b*b-4*a*c))/(2*a), (-b+sqrt(b*b-4*a*c))/(2*a)};
	return roots;
}
