// 字符串类型的异常机制
#include <iostream>

double hmean(double a, double b);

int main() {
	double x, y, z;
	
	std::cout <<"Enter two numbers, <q to quit>: ";
	while (std::cin>>x>>y) {
		try {
			z = hmean(x, y);
		} catch (const char* e) {
			std::cout<<e<<std::endl;
			std::cout<<"Enter a new pair of numbers, <q to quit>: ";
			continue;
		}
		std::cout<<"the Harmonic mean of "<<x<<", "<<y<<" is "<<z<<std::endl;
		std::cout<<"Enter a new pair of numbers, <q to quit>: ";
	}
	std::cout<<"Bye!\n";
	return 0;
}

double hmean(double a, double b) {
	if (a == -b)
		throw "bad hmean() arguments";
	return 2.0 * a * b / (a + b);
}
