#include <cstdlib>
#include <cmath>
#include "pi.h"

using std::sqrt;

double approx_pi(unsigned seed, unsigned n) {
    // seed the random number generator
    srand(seed);
	double totaltries=n;
	int hit_count = 0;
    // TODO(student):
    // simulate the dart-throwing process
    // estimate the area of the quadrant
    // estimate the value of pi
    // return the estimated value of 
	for (int i = 0; i < n; i++) {
	double x = static_cast<double> (rand()) / RAND_MAX;
	double y = static_cast<double> (rand()) / RAND_MAX;
	double isinside=sqrt(x*x+y*y);
	if (isinside<=1)  {
		hit_count = hit_count + 1;

	}
	}
	double pieest=4*(hit_count/totaltries);
	
    return pieest;
}
