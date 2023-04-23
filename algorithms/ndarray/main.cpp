#include "ndarray.h"
#include <iostream>

int main() {
	NDArray<int> arr(5, 5);
	arr.null();
	arr.ones();
	arr.random();


}
