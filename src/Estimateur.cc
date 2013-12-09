#include "Estimateur.h"

using namespace std;
using namespace arma;

Estimateur::Estimateur(Simulateur * simulateur)
{
	_simulateur = simulateur;
}

vector<double> Estimateur::estimate() {
	vector<double> tetas = _simulateur->getTraceTetas();
	vector< pair<double, double> > observateur = _simulateur->getTraceObs();	
	mat C = zeros<mat>(tetas.size(), 4);
	vec Y = zeros<vec>(tetas.size());

	for(size_t i=0; i<tetas.size(); i++) {
		C(i,0) = sin(tetas[i]);
		C(i,1) = i * sin(tetas[i]);
		C(i,2) = -cos(tetas[i]);
		C(i,3) = - i * cos(tetas[i]);

		Y(i) = observateur[i].first * sin(tetas[i]) - observateur[i].second * cos(tetas[i]);
	}

        // Use armadillo to solve the linear system C*X=Y
	vec resultat = solve(C,Y);
	vector<double> retour;

	for(int i=0; i<4; i++) {
		retour.push_back(resultat(i));
	}

	return retour;
	
}
