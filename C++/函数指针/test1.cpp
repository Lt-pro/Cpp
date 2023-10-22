#include <iostream>

double betsy(int line);
double pam(int line);

double estimate(int line, double (*pf) (int));


int main()
{
	using namespace std;
	int code;
	cout <<"How many lines of code do you need?";
	cin >>code;
	cout <<"Here is betsy's estimation:"<<endl;
	estimate(code, betsy);
	cout <<"Here is pam's estimation:"<<endl;
	estimate(code, pam);
	
	return 0;
}

double betsy(int line)
{
	return 0.05 * line;
}
double pam(int line)
{
	return 0.03 * line + 0.0004 * line * line;
}

double estimate(int line, double (*pf) (int))
{
	using namespace std;
	cout <<line<<"line will take ";
	cout <<(*pf)(line)<<"hour(s)"<<endl;
}