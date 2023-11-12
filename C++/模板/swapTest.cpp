#include <iostream>

template <typename T>
void Swap(T& a, T& b);

template <typename T>
void Swap(T* a, T* b, int n);	//重载版本，支持数组交换

struct job {
	char name[40];
	double salary;
	int floor;
};

// 交换salary和floor
template <> void Swap(job& a, job& b);	// 显式实例化版本

void Show(int* arr, int n);
void Show(job& a);

// 显式实例化
template <typename T> 
T Add(T a, T b);

template float Add<float>(float a, float b);

int main() {
	using namespace std;
	
	// 通用的函数
	// 交换两个整数
	int i = 1, j = 2;
	cout<<"before exchanging i = "<<i<<", j = "<<j<<endl;
	Swap(i, j);
	cout<<"after using complier-generated function, i = "<<i<<", j = "<<j<<endl;
	
	// 交换两个浮点数
	double m = 3.14, n = 2.71;
	cout<<"before exchanging m = "<<m<<", n = "<<n<<endl;
	Swap(m, n);
	cout<<"after using complier-generated function, m = "<<m<<", n = "<<n<<endl;
	
	// 重载
	// 交换两个数组
	const int N = 8;
	int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int arr2[] = {9, 1, 5, 7, 8, 3, 2, 4};
	cout<<"array before exchanging :"<<endl;
	Show(arr1, N);
	Show(arr2, N);
	Swap(arr1, arr2, N);
	cout<<"array after using complier-generated function :"<<endl;
	Show(arr1, N);
	Show(arr2, N);
	
	// 显式具体化
	/**
	* 函数名可以用非模板函数、模板函数、显式具体化的模板函数以及它们的重载版本
	* 显式具体化的原型为template <> 返回值 函数名<具体类型>(参数列表), 定义在原型的基础上加上函数体。泛型标识符可选
	* 调用时非模板函数>显式具体化模板函数>模板函数
	*/
	job sue = {"sue", 3333.3, 555};
	job sidney = {"sidney", 4444.4, 666};
	
	cout<<"before exchanging: "<<endl;
	Show(sue);
	Show(sidney);
	Swap(sue, sidney);	//调用显式具体化版本
	cout<<"after using explicit specialization function: "<<endl;
	Show(sue);
	Show(sidney);
	
	// 显式实例化
	/**
	* 显式实例化支持生成一个模板的实例
	* 语法1: template 返回值 函数名<具体类型>(参数列表);
	* 语法2: 调用函数时加泛型标识符，函数名<具体类型>(参数列表)
	* 同一文件不能存在同一类型的显式实例化和显式具体化
	*/
	
	int f1 = 2;
	int f2 = 3;
	double f3 = 4.1;
	float f4 = 3.7;
	cout<<"f1 = "<<f1<<", f2 = "<<f2<<", f3 = "<<f3<<endl;
	cout<<"with normal complier-generated function, f1 + f2 = "<<Add(f1, f2)<<endl;
	//cout<<"with explicit instance function, f1 + f4 = "<<Add(f1, f4)<<endl;
	cout<<"with explicit instance function Add<double>, f2 + f3 = "<<Add<double>(f2, f3)<<endl;
	
	system("pause");
	return 0;
}

template <typename T>
void Swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
void Swap(T* a, T* b, int n) {
	T temp;
	for (int i=0; i<n; i++) {
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}

template <> void Swap(job& a, job& b) {
	double tmp1 = a.salary;
	a.salary = b.salary;
	b.salary = tmp1;
	
	int tmp2 = a.floor;
	a.floor = b.floor;
	b.floor = tmp2;
}

void Show(int* arr, int n) {
	for (int i=0; i<n; i++) {
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
}

void Show(job& a) {
	std::cout<<"name: "<<a.name<<" salary: "<<a.salary<<" floor: "<<a.floor<<std::endl;
}

template <typename T> 
T Add(T a, T b) {
	return a + b;
}