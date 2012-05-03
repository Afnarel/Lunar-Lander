#ifndef __MATRIX__
#define __MATRIX__

#include <vector>
#include <iostream>
#include <sstream>

template <class T>
class Matrix {
	private:
		std::vector< std::vector<T> > matrix;

	public:
		Matrix();

		template<typename T>
		friend std::ostream& operator<<(std::ostream& os, const Matrix<T> &m);

		void addLine(std::vector<T> ligne);
	
};

#endif