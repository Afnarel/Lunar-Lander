#include "Simulateur.h"

using namespace std;

Simulateur::Simulateur()
{}

void Simulateur::simulate(int nb_iter) {
	double teta = atan2(mobile.getY() - obs.getY(), mobile.getX() - obs.getX());
	tetas.push_back(teta);
	for(int i=0; i<nb_iter; i++) {
		mobile.update();
		obs.update();
		double teta = atan2(mobile.getY() - obs.getY(), mobile.getX() - obs.getX());
		tetas.push_back(teta);
	}
}

void Simulateur::displayTraceMobile() {
	cout.precision(2);

	vector< pair<double, double> > mt = mobile.getTrace();
	for(size_t i=0; i<mt.size(); i++)
		cout << mt[i].first << " " << mt[i].second << endl;
		//cout << setw(8) << mt[i].first << setw(8) << mt[i].second << endl;

	cout << endl;
}

void Simulateur::displayTraceObservateur() {
	cout.precision(2);

	vector< pair<double, double> > ot = obs.getTrace();
	for(size_t i=0; i<ot.size(); i++)
		cout <<  ot[i].first << " " << ot[i].second << endl;
		//cout << setw(8) << ot[i].first << setw(8) << ot[i].second << endl;

	cout << endl;
}

void Simulateur::displayTraceTeta() {
	cout.precision(2);

	for(size_t i=0; i<tetas.size(); i++)
			cout << i << " " << tetas[i] << endl;

	cout << endl;
}

// Demi-droite [(xObs(t),yObs(t)) , Teta]
// ot[t].first, ot[t].second
void Simulateur::displayTestTeta(int t) {
	cout.precision(2);

	vector< pair<double, double> > ot = obs.getTrace();
	if(t < 0 || t >= ot.size()) {
		cerr << "Le temps t" << t << " n'existe pas" << endl;
		exit(EXIT_FAILURE);
	}

	cerr << "Teta vaut " << tetas[t] << endl;
	cout << ot[t].first << " " << ot[t].second << endl; // Position de l'observateur


	int n = 10; // offset
	double x = (ot[t].first + n);
	double y = ot[t].second;

	x -= ot[t].first;
	y -= ot[t].second;
	cerr << "A : (" << x << "," << y << ")" << endl;
	// On calcule un point 
	double xprime = x * cos(tetas[t]) - y * sin(tetas[t]);
	double yprime = x * sin(tetas[t]) + y * cos(tetas[t]);

	xprime += ot[t].first;
	yprime += ot[t].second;
	cerr << "B : (" << xprime << "," << yprime << ")" << endl;

	cout << xprime << " " << yprime << endl; // Position de l'observateur

	cout << endl;
}