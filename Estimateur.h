#ifndef __ESTIMATEUR__
#define __ESTIMATEUR__

#include "Simulateur.h"
#include <vector>
#include <cmath>
#include <armadillo>

class Estimateur {
	private:
		Simulateur * _simulateur;
	public:
		Estimateur(Simulateur * simulateur);
		std::vector<double> estimate();
};

#endif