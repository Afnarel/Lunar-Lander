#include "Observateur.h"

using namespace std;

Observateur::Observateur(pair<double, double> origine, double angle, double rayon) {
	_angleTotal = 90.0;
	_angle = angle;
	_origine = origine;
	_rayon = rayon;

	pair<double, double> posInit = origine;
	posInit.second += rayon;
	_trace.push_back(posInit);

}

void Observateur::update() {
	_angleTotal += _angle;

	pair<double, double> position;

	//double x = _rayon * sin(_angleTotal);
	//double y = x * tan(_angleTotal);
	double x = _rayon * cos(_angleTotal);
	double y = _rayon * sin(_angleTotal);
	position.first = _origine.first + x;
	position.second = _origine.second + y;
	_trace.push_back(position);

}

vector< pair<double, double> > Observateur::getTrace() { return _trace; }