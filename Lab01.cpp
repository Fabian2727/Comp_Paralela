#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

int main() {
	
	const int max = 10000;
	int** A = new int*[max];
	int* x = new int[max];
	int* y = new int[max]();
	
	for (int i = 0; i < max; ++i) {
		A[i] = new int[max];
	}
	
	auto start = std::chrono::system_clock::now();
	
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			y[i] += A[i][j] * x[j];
		}
	}
	
	auto end = std::chrono::system_clock::now();
	
	std::chrono::duration<float, std::milli> duration = end - start;
	
	std::cout << duration.count() << "ms " << std::endl;
	
	for (int i = 0; i < max; ++i) {
		delete[] A[i];
	}
	delete[] A;
	
	delete[] x;
	delete[] y;
	
	const int max2 = 10000;
	int** B = new int*[max2];
	int* a = new int[max2];
	int* b = new int[max2]();
	
	for (int i = 0; i < max2; ++i) {
		B[i] = new int[max2];
	}
	
	auto start2 = std::chrono::system_clock::now();
	
	for (int j = 0; j < max2; j++) {
		for (int i = 0; i < max2; i++) {
			b[i] += B[i][j] * a[j];
		}
	}
	
	auto end2 = std::chrono::system_clock::now();
	
	std::chrono::duration<float, std::milli> duration2 = end2 - start2;
	
	std::cout << duration2.count() << "ms " << std::endl;

	for (int i = 0; i < max2; ++i) {
		delete[] B[i];
	}
	delete[] B;
	
	delete[] a;
	delete[] b;
	
	return 0;
}
