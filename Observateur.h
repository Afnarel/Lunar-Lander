#ifndef __OBSERVATEUR__
#define __OBSERVATEUR__

#include "Mobile.h"

#include <utility>
#include <vector>
#include <cmath>

class Observateur {
	private:
		std::pair<double, double> _origine;
		double _angle, _angleTotal;
		double _rayon;
		std::vector< std::pair<double, double> > _trace;

	public:
		Observateur(std::pair<double, double> origine = std::pair<double,double>(0,0), double angle = 10.0, double rayon = 5.0);
		void update();
		std::vector< std::pair<double, double> > getTrace();

};

#endif