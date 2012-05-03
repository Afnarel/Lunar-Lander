#include <cstdlib>
#include <iostream>
#include <utility>
#include <iomanip>

#include "Simulateur.h"
#include "Estimateur.h"

using namespace std;

int main() {
	// Mobile mobile;
	// Observateur obs(make_pair(0,5));

	Simulateur simulateur;
	simulateur.simulate(36);
	//simulateur.displayTraceTeta();
	simulateur.displayTraceMobile();
	simulateur.displayTraceObservateur();
	simulateur.displayTestTeta(0);
	simulateur.displayTestTeta(1);
	simulateur.displayTestTeta(2);
	simulateur.displayTestTeta(3);

	Estimateur estimateur(&simulateur);
	vector<double> resultat = estimateur.estimate();
	for(size_t i=0; i<resultat.size(); i++)
		cout << resultat[i] << " ";
	cout << endl;

	/*
		Todo :
			* Vérifier que les angles teta calculés sont les bons en tracant une demi-droite
			partant de xObs,yObs avec un angle teta et en vérifiant qu'elle passe bien par xMobile,yMobile

			* Rendre accessibles depuis l'extérieur du simulateur traceObs et traceTeta (mais pas traceMobile !!!) :
			getters et setters

			* Créer une classe Estimateur qui possède un attribut Simulateur et retrouve x0,y0 vX,vY à partir
			de traceObs et traceTeta
	*/
}