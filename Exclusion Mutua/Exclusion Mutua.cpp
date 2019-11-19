#include <iostream>
#include <thread>
#include <mutex> 
#include <vector>

std::mutex mtx;  

void print(int n, char c) {
	// Seccion critica
	mtx.lock();
	for (int i = 0; i < n; ++i) {
		std::cout << c; 
	}
	std::cout << '\n';
	mtx.unlock();
}

int main()
{
	//Se pueden crear cuantos threads se requieran
	std::thread th1(print, 20, '#');
	std::thread th2(print, 20, '-');
	std::thread th3(print, 20, '^');
	th1.join();
	th2.join();
	th3.join();
	return 0;
}