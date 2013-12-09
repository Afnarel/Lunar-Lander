#include "Matrix.h"

Matrix::Matrix() {
	
}

template<typename T>
ostream& operator<<(ostream& os, const Matrix& m) {
	for(size_t ligne = 0; ligne < m.size(); ligne++) {
		for(size_t colonne = 0; colonne < m[ligne].size(); colonne++) {
			os << m[ligne][colonne];
			if(colonne != m[ligne].size() - 1)
				os << " ";
		}
		os << endl;
	}
	return os;
}

template <typename T>
void Matrix::addLine(std::vector<T> ligne) {
	matrix.push_back(ligne);
}