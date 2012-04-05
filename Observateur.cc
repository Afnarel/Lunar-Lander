#include "Observateur.h"

using namespace std;

Observateur::Observateur(pair<double, double> origine, double angle, double rayon) {
	_angleTotal = degreesToRadians(90.0);
	_angle = degreesToRadians(angle);
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
	position.first = fabs(_origine.first + x) < 0.0001 ? 0 : _origine.first + x;
	position.second = fabs(_origine.second + y) < 0.0001 ? 0 : _origine.second + y;
	_trace.push_back(position);

}

vector< pair<double, double> > Observateur::getTrace() { return _trace; }

double Observateur::degreesToRadians(double degrees) {
	return M_PI * degrees / 180;
}
