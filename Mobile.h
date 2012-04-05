#ifndef __MOBILE__
#define __MOBILE__

#include <cstdlib>
#include <iostream>

#include <utility>
#include <vector>

class Mobile {
	private:
		std::pair<double, double> _pos; // Coordonnées du mobile dans l'espace 2D
		std::pair<double, double> _deplacement; // Déplacement du mobile dans l'espace 2D
		std::vector< std::pair<double, double> > _trace;
	public:
		Mobile(std::pair<double, double> deplacement = std::pair<double,double>(1,1), 
			std::pair<double, double> pos = std::pair<double,double>(0,0));
		std::pair<double, double> getPos();
		void update();
		std::vector< std::pair<double, double> > getTrace();
};

#endif