#ifndef __SIMULATEUR__
#define __SIMULATEUR__

#include "Mobile.h"
#include "Observateur.h"
#include <vector>

class Simulateur {
	private:
		Observateur obs;
		Mobile mobile;
		std::vector<double> tetas;
	public:
		Simulateur();
		void simulate(int nb_iter);
		void displayTraceMobile();
		void displayTraceObservateur();
		void displayTraceTeta();
		void displayTestTeta(int t);
};

#endif