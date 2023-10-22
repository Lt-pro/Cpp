#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
#include "tree.h"

using namespace std;

const int MAX = 10;
int main(){
	default_random_engine engine(time(nullptr));
	normal_distribution<double> normal;
	
	AVL<double, int> avl;
	double key = 0;
	double keys[MAX];
	
	for (int value=0;value<MAX;value++){
		key = normal(engine);
		keys[value] = key;
		avl.insert(key, value);
		cout <<"Element "<<value+1<<"\t: "<<"key = "<<fixed<<setprecision(5)<<key<<setw(16)<<"value = "<<value<<"\ttotals = "<<avl.length()<<"\theight = "<<avl.height()<<endl;
	}
	
	for (int i=0;i<MAX;i++)
	{
		avl.erase(keys[i]);
		cout <<"erase Element "<<i+1<<"\t: "<<"key = "<<fixed<<setprecision(5)<<keys[i]<<setw(16)<<"\tvalue = "<<i<<"\ttotals = "<<avl.length()<<"\theight = "<<avl.height()<<endl;
	}
	
	return 0;
}