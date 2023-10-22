#include <iostream>

int main()
{
	using namespace std;
	
	// const char *p = "This is a string unchanged";
	char *p = "This is a string unchanged";
	cout <<p;
	*(p + 18) = ' ';
	*(p + 19) = ' ';
	cout <<p;
	
	
	return 0;
}