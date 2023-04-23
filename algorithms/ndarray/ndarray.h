#pragma once
#include <vector>
#include <time.h>


template<class T>
class NDArray {
private:
	int rows;
	int columns;
	T** ndarray;
public:
	NDArray(int _rows=1, int _columns=1);
	~NDArray();
	void null();
	void ones();
	void random();
	T* operator [](const int& i) const;
	NDArray operator =(const NDArray& _ndarray) const;
	NDArray operator +=(const T& number) const;
	NDArray operator -=(const T& number) const;
	NDArray operator *=(const T& number) const;
	NDArray operator /=(const T& number) const;
	T min();
	T* min(int shape);
	T max();
	T* max(int shape);
	float mean();
	float* mean(int shape);
};	
	
	template<class T>
	NDArray<T>::NDArray(int _rows=1, int _columns=1) { 
		rows = _rows;
		columns = _columns;
		ndarray = new T*[columns];
		for (int i = 0;i < rows;i++) {
			ndarray[i] = new T[columns];
		}
	}
	template<class T>
	NDArray<T>::~NDArray() {};

	template<class T>
	void NDArray<T>::null() {
		for (int i = 0; i < rows;i++)
		{
			for (int j = 0;j < columns;j++) {
				ndarray[i][j] = 0;
			}
		}
	}

	template<class T>
	void NDArray<T>::ones() {
		for (int i = 0; i < rows;i++)
		{
			for (int j = 0;j <columns;j++) {
				ndarray[i][j] = 1;
			}
		}
	}

	template<class T>
	void NDArray<T>::random() {
		srand((unsigned)time(0));
		for (int i = 0; i < rows;i++)
		{
			for (int j = 0;j < columns;j++) {
				ndarray[i][j] = rand();
			}
		}
	}

	template<class T>
	T* NDArray<T>::operator [](const int& i) const {
		return ndarray[i]; 
	}
	template<class T>
	NDArray<T> NDArray<T>::operator =(const NDArray& _ndarray) const {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				ndarray[i][j] = _ndarray[i][j];
			}
		}
	}
	template<class T>
	NDArray<T> NDArray<T>::operator +=(const T& number) const {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				ndarray[i][j] += number;
			}
		}
	}
	template<class T>
	NDArray<T> NDArray<T>::operator -=(const T& number) const {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				ndarray[i][j] -= number;
			}
		}
	}
	template<class T>
	NDArray<T> NDArray<T>::operator *=(const T& number) const {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				ndarray[i][j] *= number;
			}
		}
	}
	template<class T>
	NDArray<T> NDArray<T>::operator /=(const T& number) const {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				ndarray[i][j] /= number;
			}
		}
	}



	template<class T>
	T NDArray<T>::min() {
		T min = ndarray[0][0];
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				min = min <= ndarray[i][j] ? min : ndarray[i][j];
			}
		}
	}

	template<class T>
	T* NDArray<T>::min(int shape) {
		if (shape == 0) {
			T* min = new T[rows];
			for (int i = 0; i < rows; i++) {
				min[i] = arr[i][0];
				for (int j = 0; j < columns; j++) {
					min[i] = ndarray[i][j] < min[i] ? ndarray[i][j] : min[i];
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
	
	template<class T>
	T NDArray<T>::max() {
		T max = ndarray[0][0];
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				max = ndarray[i][j] > max ? max = ndarray[i][j] : max;
			}
		}
		return max;
	}
	template<class T>
	T* NDArray<T>::max(int shape) {
		if (shape == 0) {
			T* max = new T[rows];
			for (int i = 0; i < rows; i++) {
				max[i] = ndarray[i][0];
				for (int j = 0; j < columns; j++) {
					max[i] = ndarray[i][j] > max[i] ? ndarray[i][j] : max[i];
				}
			}
			return max;
		}
		else if (shape == 1) {
			T* max = new T[columns];
			for (int i = 0; i < columns; i++) {
				max[i] = ndarray[0][i];
				for (int j = 0; j < rows; j++) {
					max[i] = ndarray[j][i] > max[i] ? ndarray[j][i] : max[i];
				}
			}
			return max;
		}
	}

	template<class T>
	float NDArray<T>::mean() {
		int sum = 0;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				sum += ndarray[i][j];
			}
		}
		return sum / (float)(columns) / (float)(rows);
	}
	template<class T>
	float* NDArray<T>::mean(int shape) {
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





