#pragma once
#include <vector>
#include <time.h>


template<typename T>
class NDArray {
public:
	int rows;
	int columns;
	T** ndarray;
public:
	NDArray(int _rows=1, int _columns=1) { 
		rows = _rows;
		columns = _columns;
		ndarray = new T*[columns];
		for (int i = 0;i < rows;i++) {
			ndarray[i] = new T[columns];
		}
	}
	~NDArray() {};

	void null() {
		for (int i = 0; i < rows;i++)
		{
			for (int j = 0;j < columns;j++) {
				ndarray[i][j] = 0;
			}
		}
	}

	void ones() {
		for (int i = 0; i < rows;i++)
		{
			for (int j = 0;j <columns;j++) {
				ndarray[i][j] = 1;
			}
		}
	}

	void random() {
		for (int i = 0; i < rows;i++)
		{
			for (int j = 0;j < columns;j++) {
				ndarray[i][j] = rand()%rows+columns+1;
			}
		}
	}

	T* operator [](const int& i) const {
		return ndarray[i]; 
	}
	NDArray operator =(const NDArray& _ndarray) const {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				ndarray[i][j] = _ndarray[i][j];
			}
		}
	}
	NDArray operator +=(const T& number) const {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				ndarray[i][j] += number;
			}
		}
	}
	NDArray operator -=(const T& number) const {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				ndarray[i][j] -= number;
			}
		}
	}
	NDArray operator *=(const T& number) const {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				ndarray[i][j] *= number;
			}
		}
	}
	NDArray operator /=(const T& number) const {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				ndarray[i][j] /= number;
			}
		}
	}



	T min() {
		T min = ndarray[0][0];
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				min = min <= ndarray[i][j] ? min : ndarray[i][j];
			}
		}
	}

	T* min(int shape) {
		if (shape == 0) {
			T* min = new T[rows];
			for (int i = 0; i < rows; i++) {
				min[i] = arr[i][0];
				for (int j = 0; j < columns; j++) {
					min[i] = arr[i][j] < min[i] ? ndarray[i][j] : min[i];
				}
			}
			return min;
		}
		else if (shape == 1) {
			T* min = new T[columns];
			for (int i = 0; i < columns; i++) {
				min[i] = ndarray[0][i];
				for (int j = 0; j < rows; j++) {
					min[i] = ndarray[j][i] < min[i] ? ndarray[j][i] : min[i];
				}
			}
			return min;
		}
	}
	
	T max() {
		T max = ndarray[0][0];
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				max = arr[i][j] > max ? max = arr[i][j] : max;
			}
		}
		return max;
	}
	T* max(int shape) {
		if (shape == 0) {
			T* max = new T[rows];
			for (int i = 0; i < rows; i++) {
				max[i] = ndarray[i][0];
				for (int j = 0; j < columns; j++) {
					max[i] = ndarray[i][j] > max[i] ? arr[i][j] : max[i];
				}
			}
			return max;
		}
		else if (shape == 1) {
			T* max = new T[columns];
			for (int i = 0; i < columns; i++) {
				max[i] = ndarray[0][i];
				for (int j = 0; j < rows; j++) {
					max[i] = arr[j][i] > max[i] ? ndarray[j][i] : max[i];
				}
			}
			return max;
		}
	}

	float mean() {
		int sum = 0;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				sum += ndarray[i][j];
			}
		}
		return sum / (float)(columns) / (float)(rows);
	}
	float* mean(int shape) {
		if (shape == 0) {
			float* sum = new float[rows];
			for (int i = 0; i < rows; i++) {
				sum[i] = 0.0;
				for (int j = 0; j < columns; j++) {
					sum[i] += ndarray[i][j];
				}
				sum[i] /= (float)(rows);
			}
			return sum;
		}
		else if (shape == 1) {
			float* sum = new float[columns];
			for (int i = 0; i < columns; i++) {
				sum[i] = 0.0;
				for (int j = 0; j < rows; j++) {
					sum[i] += ndarray[j][i];
				}
				sum[i] /= (float)(columns);
			}
			return sum;
		}
	}




};
