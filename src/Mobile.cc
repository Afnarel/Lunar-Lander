#include "Mobile.h"

using namespace std;

Mobile::Mobile(pair<double, double> deplacement, pair<double, double> pos) {
	_deplacement = deplacement;
	_pos = pos;
	_trace.push_back(pos);
}

void Mobile::update() {
	_pos.first += _deplacement.first;
	_pos.second += _deplacement.second;
	_trace.push_back(_pos);
}

/***********
 * Getters *
 ***********/

 pair<double, double> Mobile::getPos() { return _pos; }

 vector< pair<double, double> > Mobile::getTrace() { return _trace; }

 double Mobile::getX() {
	return _trace.back().first;
}

double Mobile::getY() {
	return _trace.back().second;
}