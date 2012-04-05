#include <cstdlib>
#include <iostream>
#include <utility>
#include <iomanip>

#include "Mobile.h"
#include "Observateur.h"

#define NB_ITER 36

using namespace std;

int main() {
	Mobile mobile;
	Observateur obs;

	for(int i=0; i<NB_ITER; i++) {
		mobile.update();
		obs.update();
	}

	cout.precision(2);

	vector< pair<double, double> > mt = mobile.getTrace();
	for(size_t i=0; i<mt.size(); i++)
		cout << mt[i].first << " " << mt[i].second << endl;
		//cout << setw(8) << mt[i].first << setw(8) << mt[i].second << endl;

	cout << endl;

	vector< pair<double, double> > ot = obs.getTrace();
	for(size_t i=0; i<ot.size(); i++)
		cout <<  ot[i].first << " " << ot[i].second << endl;
		//cout << setw(8) << ot[i].first << setw(8) << ot[i].second << endl;
}