// 类类型的异常机制
#include <iostream>
#include <cmath>

// 异常类
class bad_hmean {
private:
	double a;
	double b;
public:
	bad_hmean(double a0=0, double b0=0):a(a0), b(b0){}
	void mesg() {std::cout <<"bad hmean() arguments: a = "<<a<<" b = "<<b<<std::endl;}
};

class bad_gmean {
private:
	double a;
	double b;
public:
	bad_gmean(double a0=0, double b0=0):a(a0), b(b0){}
	void mesg() {std::cout<<"bad gmean() arguments: a = "<<a<<" b = "<<b<<std::endl;}
};

double hmean(double a, double b);
double gmean(double a, double b);

int main() {
	double x, y, z;

	std::cout<<"Enter two numbers, <q to quit>: ";
	while (std::cin>>x>>y) {
		try {
			z = hmean(x, y);
			std::cout<<"the harmonic mean of "<<x<<", "<<y<<" is "<<z<<std::endl;
			z = gmean(x, y);
			std::cout<<"the geometric mean of "<<x<<", "<<y<<" is "<<z<<std::endl;
		} catch (bad_hmean& bh) {
			bh.mesg();
			std::cout<<"Try again, <q to quit>: ";
			continue;
		} catch (bad_gmean& bg) {
			bg.mesg();
			std::cout<<"Try again, <q to quit>: ";
			continue;
		}
		std::cout<<"Enter a new pair of numbers, <q to quit>: ";
	}
	std::cout<<"Bye!\n";
	return 0;
}

double hmean(double a, double b) {
	if (a == -b)
		throw bad_hmean(a, b);
	return 2.0 * a * b / (a + b);
}
double gmean(double a, double b) {
	if (a<=0 || b<=0)
		throw bad_gmean(a, b);
	return std::sqrt(a*b);
}