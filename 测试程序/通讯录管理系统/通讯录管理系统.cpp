#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


// 数据结构  
#define MAX 1000 //最大联系人数目
typedef struct Person{
	string name;
	bool sex;
	int age;
	string phone;
	string address;
} Person;

typedef struct AddressBooks{
	Person persons[MAX];
	unsigned int n;	//当前联系人数目
} AddressBooks;

// 函数声明
void showMenu();
bool full(AddressBooks *book);
bool pushBack(AddressBooks *book, Person person);
bool addPerson(AddressBooks *book);
void showPerson(AddressBooks *book);
int search(AddressBooks *book, string name);
bool remove(AddressBooks *book, int i);
void delPerson(AddressBooks *book);
void findPerson(AddressBooks *book);
void modifyPerson(AddressBooks *book);
void clear(AddressBooks *book);
void clearBook(AddressBooks *book);

//主程序  
int main(){
	int state;
	AddressBooks book;
	book.n = 0;
	
	while(true){
		showMenu();
		cin >> state;
		
		switch(state){
			case 1:
				//添加联系人
				addPerson(&book);
				break;
			case 2:
				// 显示联系人
				showPerson(&book);
				break;
			case 3:
				//删除联系人
				delPerson(&book);
				break;
			case 4:
				//查找联系人
				findPerson(&book);
				break;
			case 5:
				//修改联系人
				modifyPerson(&book);
				break;
			case 6:
				//清空联系人
				clearBook(&book);
				break;
			case 0:
				//退出通讯录
				cout <<"欢迎下次使用！"<<endl;
				system("pause");
				return 0;
			default :
				break;
		}
	}
}

//函数定义
void showMenu(){
	
	cout <<setfill('*')<<setw(31)<<""<<endl;
	cout <<"******  1、 添加联系人  "<<setw(20)<<setfill('*')<<setw(7)<<""<<endl;
	cout <<"******  2、 显示联系人  "<<setw(20)<<setfill('*')<<setw(7)<<""<<endl;
	cout <<"******  3、 删除联系人  "<<setw(20)<<setfill('*')<<setw(7)<<""<<endl;
	cout <<"******  4、 查找联系人  "<<setw(20)<<setfill('*')<<setw(7)<<""<<endl;
	cout <<"******  5、 修改联系人  "<<setw(20)<<setfill('*')<<setw(7)<<""<<endl;
	cout <<"******  6、 清空联系人  "<<setw(20)<<setfill('*')<<setw(7)<<""<<endl;
	cout <<"******  0、 退出通讯录  "<<setw(20)<<setfill('*')<<setw(7)<<""<<endl;
	cout <<setfill('*')<<setw(31)<<""<<endl;
	cout <<setfill(' ');
	//setfill, setioflags作用全局有效，setw只对下一个字符串有效
}

bool full(AddressBooks *book){
	//判断book是否可以插入元素
	if (book->n == MAX){
		return true;
	}
	else{
		return false;
	}
}

bool pushBack(AddressBooks *book, Person person){
	//向book末尾插入一个元素
	if (!full(book)){
		book->persons[book->n] = person;
		book->n += 1;
		return true;
	}
	else{
		return false;
	}
}

bool addPerson(AddressBooks *book){
	//主程序添加联系人  
	if (full(book)){
		cout << "通讯录已满！"<<endl;
		system("cls");
		return false;
	}
	else{
		Person person;
		cout <<"请输入联系人姓名："<<endl;
		cin >>person.name;
		cout <<"请输入联系人性别(男 1, 女 0)："<<endl;
		cin >>person.sex;
		cout <<"请输入联系人年龄："<<endl;
		cin >>person.age;
		cout <<"请输入联系人电话号码："<<endl;
		cin >>person.phone;
		cout <<"请输入联系人地址："<<endl;
		cin >>person.address;
		pushBack(book, person);
		cout <<"成功添加联系人"<<endl;
		system("cls");
		return true;
	}
}

void showPerson(AddressBooks *book){
	//显示联系人
	char a;
	if (!book->n){
		cout <<"通讯录无联系人"<<endl;
		cout <<"键入任意字符退出"<<endl;
		cin >>a;
		system("cls");
	}
	else{
		Person p;
		string sex;
		cout <<setfill(' ')<<endl;
		cout <<setw(10)<<"序号"<<setw(10)<<"姓名"<<setw(10)<<"性别"<<setw(10)<<"年龄"<<setw(15)<<"电话号码"<<setw(20)<<"地址"<<endl;
		for (int i=0; i<book->n; i++){
			p = book->persons[i];
			sex = p.sex ? "男": "女";
			cout <<setw(10)<<i+1<<setw(10)<<p.name<<setw(10)<<sex<<setw(10)<<p.age<<setw(15)<<p.phone<<setw(20)<<p.address<<endl;
		}
		cout <<"键入任意字符退出"<<endl;
		cin >>a;
		system("cls");
	}
}

int search(AddressBooks *book, string name){
	//根据name查找对应的通讯录序号，若不存在则返回-1
	int idx=-1;
	for (int i=0; i<book->n;i++){
		if (book->persons[i].name == name){
			idx = i;
			break;
		}
	}
	return idx;
}

bool remove(AddressBooks *book, int i){
	//删除指定位置元素  
	if (book->n>i){
		while (i<book->n-1){
			book->persons[i] = book->persons[i+1];
			i++;
		}
		book->n--;
		return true;
	}
	else{
		return false;
	}
}

void delPerson(AddressBooks *book){
	//删除指定联系人
	string name;
	int idx;
	char a;
	
	cout <<"请输入需删除的联系人姓名： ";
	cin >>name;
	idx = search(book, name);
	if (idx==-1){
		cout <<"联系人不存在"<<endl;
	}
	else{
		remove(book, idx);
		cout <<"成功删除联系人"<<endl;
	}
	cout <<"键入任意字符退出"<<endl;
	cin >>a;
	system("cls");
}

void findPerson(AddressBooks *book){
	//根据名称查找联系人
	string name;
	int idx;
	string sex;
	char a;
	
	cout <<"请输入查找联系人名称： ";
	cin >>name;
	idx = search(book, name);
	if (idx==-1){
		cout <<"联系人不存在"<<endl;
	}
	else{
		sex = book->persons[idx].sex ? "男":"女";
		cout <<setiosflags(ios::left)<<"姓名： "<<setw(10)<<book->persons[idx].name<<"性别： "<<setw(10)<<sex<<"年龄： "<<setw(10)<<book->persons[idx].age<<"电话号码： "<<setw(15)<<book->persons[idx].phone<<"地址： "<<setw(20)<<book->persons[idx].address<<endl;
		cout <<setiosflags(ios::right);
	}
	cout <<"键入任意字符退出"<<endl;
	cin >>a;
	system("cls");
}

void modifyPerson(AddressBooks *book){
	string name;
	int idx;
	char a;
	
	cout <<"请输入查找联系人名称： ";
	cin >>name;
	idx = search(book, name);
	if (idx==-1){
		cout <<"联系人不存在"<<endl;
	}
	else{
		Person person;
		cout <<"请修改联系人姓名："<<endl;
		cin >>person.name;
		cout <<"请修改联系人性别(男 1, 女 0)："<<endl;
		cin >>person.sex;
		cout <<"请修改联系人年龄："<<endl;
		cin >>person.age;
		cout <<"请修改联系人电话号码："<<endl;
		cin >>person.phone;
		cout <<"请修改联系人地址："<<endl;
		cin >>person.address;
		book->persons[idx] = person;
		cout <<"成功修改联系人"<<endl;
	}
	cout <<"键入任意字符退出"<<endl;
	cin >>a;
	system("cls");
}

void clear(AddressBooks *book){
	book->n = 0;
}

void clearBook(AddressBooks *book){
	char a;
	
	clear(book);
	cout <<"成功清空通讯录"<<endl;
	cout <<"键入任意字符退出"<<endl;
	cin >>a;
	system("cls");
}
