#include<iostream>
#include<memory>

class Text {
private:
	std::string str;
public:
	Text(std::string str0=""):str(str0){std::cout<<"Text is created.\n";}
	~Text(){std::cout<<"Text is destroied.\n";}
	void comment() const {std::cout<<str<<std::endl;}
};


int main() {
	using namespace std;
	/**
	* 智能指针声明与初始化
	* 智能指针可以在生命周期内指向内存，声明周期结束时释放指向的内存
	* 不要用栈区地址初始化智能指针
	* 智能指针支持*, ->, =运算符
	*/
	{
		auto_ptr<Text> pt(new Text("Using auto_ptr<>"));
		pt->comment();
	}
	{
		unique_ptr<Text> pt(new Text("Using unique_ptr<>"));
		pt->comment();
	}
	{
		shared_ptr<Text> pt(new Text("Using shared_ptr<>"));
		(*pt).comment();
	}
	
	/**
	* 当存在多个指针指向同一对象时
	* auto_ptr和unique_ptr采用所有权管理指针，shared_ptr采用引用计数管理指针
	* 所有权管理中，同一时刻只有一个指针拥有所有权，赋值操作会发生所有权转让
	* 引用技术可能存在循环引用问题
	* auto_ptr已被弃用，unique_ptr支持临时右值和std::move()进行赋值操作
	* 仅有unique_ptr支持使用new []
	*/
	shared_ptr<string> films[5] = {
		shared_ptr<string>(new string("Fowl Balls")),
		shared_ptr<string>(new string("Duck Walks")),
		shared_ptr<string>(new string("Chicken Runs")),
		shared_ptr<string>(new string("Turkey Errors")),
		shared_ptr<string>(new string("Goose Eggs"))
	};
	shared_ptr<string> pt;
	pt = films[2];
	
	unique_ptr<string> pt1(new string("Hi "));
	unique_ptr<string> pt2;
	pt2 = unique_ptr<string>(new string("right value"));
	pt2 = std::move(pt1);
	
	system("pause");
	return 0;
}
