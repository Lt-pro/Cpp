# OOP

## 一、概念

- 面向对象编程(OOP): 面向对象是一种将数据和对数据的操作绑定的编程范式。类描述了数据的一般属性和操作，对象则是类的具体实现。
- 面向对象的三大特征是封装、继承与多态
  - 封装是指隐藏内部实现只暴露使用接口，达到接口与实现相分离。不暴露数据称为数据隐藏。
  - 继承是指子类可以复用基类的属性和方法
  - 多态是指存在继承关系的父类和子类对于同一父类方法表现出不同的行为
- 类的成员可以有: 成员变量、成员方法、静态变量、静态常量、静态方法、内部类
- 静态变量、静态常量和静态方法
  - 静态变量和静态常量: 类静态变量和类静态常量具有类可见性，由全体实例共享一个副本，具有普通静态变量和静态常量的特征
  - 静态方法: 静态方法不属于具体对象，无需依赖具体对象调用，故也不能使用被调用对象的成员变量和this指针，因为不存在
- this指针: 指向被调用成员函数的对象的指针
- 访问权限修饰符
  - public: 具有全局可见性, 如果在其它文件中使用需要进行额外声明
  - protected: 在基类和子类中可见
  - private: 仅在定义的类中的类作用域可见
- 可见性
  - 使用public修饰的成员在类外部可见, 使用protected修饰的成员在基类和子类中具有可见性, 使用private修饰的成员仅在定义的类内部具有可见性
  - this指针在成员方法中具有可见性, this指针和成员变量对静态方法不具有可见性
  - 静态变量、静态常量、静态成员方法至少具有类可见性, 根据访问权限修饰符的不同具有不同的可见性
  - 内部类中的被嵌套类的实例的成员具有类可见性
  - 类的所有成员对于友元具有可见性
- 名称冲突
  - 当成员方法传入的参数与成员变量冲突时可使用this指针显式指定成员变量
  - 当继承的多个类具有同名的成员变量时应当使用类名加作用域解析运算符显示指定
- 成员访问
  - 在成员方法中访问成员变量时访问的是被调用对象的成员变量
  - 类内部的成员访问可直接使用成员名称，如果发生名称冲突可使用this指针或作用域解析运算符
  - 若成员被修饰为public则可在类外部访问
      - 类对象可使用.运算符访问成员变量和成员方法
      - 类对象的指针可使用->运算符访问成员变量和成员方法
      - 静态变量、静态常量、静态方法和内部类不属于具体类, 使用类名加作用域解析运算符进行访问

## 二、C++面向对象

- 定义与实现一个类
  - class关键字定义一个类, 语法为`class TypeName {};`, 所有成员皆在`{};`内声明
  - 访问权限控制
    - 一个类具有一个或多个public,protected或private控制的标记区域
    - 标记加冒号:开始到下一个标记或类定义右括号结束都是有效的，标记区域内的成员具有相应的访问权限，默认的访问权限是private。
  - 变量、方法与内部类+
    - 变量声明与方法声明与普通变量和函数相同, 当使用`static`关键字修饰后成为为静态变量和静态方法，否则为成员变量和成员方法
    - 静态变量和静态常量的初始化在类外部，需使用作用域解析运算符
    - 方法的实现可以在类内部或者外部, 内部实现将被隐式定义为内联函数，外部实现需使用类名加作用域解析运算符指定方法名
    - 内部类与普通类定义方法相同, 选定标记区域即可
  - 类定义示例

    ```C++
    // Box.h文件
    class Box {
    public:
        static int count;
        static const double pi;
        double length;
        double width;
        double height;
        double get();
        void set(double length, double width, double height);
    };
    // Box.cpp文件
    int Box::count = 0;
    const double Box::pi = 3.1415926;
    double get() {
        return length * width * height;
    }
    void set(double length, double width, double height) {
        this->length = length;
        this->width = width;
        this->height = height;
    }

    ```

- 构造函数、拷贝构造函数和析构函数
  - 构造函数
    - 构造函数在创建新对象时调用, 没有返回值, 函数名为类名, 可以有不同参数列表的构造函数, 系统默认的构造函数参数列表为空。
    - 构造函数不属于类型
    - 初始化列表
        - 构造函数支持使用初始化列表初始化成员变量
        - 初始化顺序与变量声明顺序相同, 调用执行顺序是初始化列表，构造函数体
        - 修饰为const的成员变量应当在初始化列表初始化, 构造函数体的赋值符号表示赋值操作
  - 拷贝构造函数
    - 拷贝构造函数在变量初始化、函数传入参数和函数返回参数时调用
    - 拷贝构造函数没有返回值, 函数名为类名, 参数列表仅有该类型的不可变引用
  - 析构函数
    - 析构函数在删除对象时自动调用, 没有返回值, 函数名为~类名, 参数列表为空
    - 析构函数只能有一个
  - 在使用new/delete时，会分别隐式调用构造函数和析构函数, 使用new创建的类对象指针参数列表必须符合某个构造函数
  - 示例程序

    ```C++
    // Line.h
    class Line {
    private:
        double length;
        int *ptr;
    public:
        Line();                             //默认构造函数，当人为定义有参构造函数时若想保留无参版本需要人为定义
        Line(double length, int* ptr);      //构造函数
        Line(const Line& obj);              //拷贝构造函数
        ~Line();                            //析构函数
        double get();
        void set(double length);
    };

    // Line.cpp
    Line::Line() {
        length = 0;
        ptr = nullptr;
    }
    Line::Line(double length, int* ptr) {
        this->length = length;
        this->ptr = ptr;
    }
    Line::Line(const Line& obj) {
        length = obj.length;
        ptr = new int;
        *ptr = *obj.ptr;
    }
    Line::~Line() {
        delete ptr;
    }
    double Line::get() {
        return double;
    }
    void Line::set(double length) {
        this->length = length;
    }
    ```

- 声明类变量和创建类对象
  - 类变量声明与普通变量声明相同
  - 类对象创建示例

    ```C++
    Line l1;                    //隐式声明与初始化, 无参构造器
    Line l2 = Line();           //无参构造显式版本
    Line l3(10);                //隐式版本,有参构造
    Line l4 = Line(10);         //显式版本,有参构造
    Line l5 = {10};             //初始化列表
    Line l6 = Line(){10};       //初始化列表
    Line *lp1 = new Line;       //类对象指针，无参
    Line *lp2 = new Line(10);   //类对象指针，有参
    delete lp1;                 
    delete lp2;
    ```
- 类成员访问: 参一
- 对象数组数组: 同普通数组，要求定义无参构造器
- 内部类使用示例——单链表

  ```C++
  // 有初始化列表使用示例
  typedef double T;
  class SingleList {
  private:
      class Node {
      public:
          T data;
          Node* next;
          Node() {next=nullptr;};
          Node(T d):data(d), next(nullptr){}; 
      };

      Node* head;
      int count;
  public:
      SingleList():head(nullptr), count(0){};
      SingleList(const SingleList& obj);
      ~SingleList();
      bool insert(int i, T d);
      bool erase(int i, T& d);
      bool get(int i, T& d);
      bool set(int i, T d);
      int length() {return count;};
  };
  SingleList::SingleList(const SingleList& obj) {
      head = new Node;
      count = 0;
      Node *t = head, *p = obj.head->next;
      while (p!=nullptr) {
          t = t->next = new Node(p->d);
          p = p->next;
          ++count;
      }
  }
  SingleList::~SingleList() {
      Node *p = head, *pp = head->next;
      while (pp!=nullptr) {
          delete p;
          p = pp;
          pp = pp->next;
      }
      delete p;
  }
  bool SingleList::insert(int i, T d) {
      if (i<0 || i>count) return false;
      Node *t = head, *s = nullptr;
      for (int k=0; k<i; k++)
          t = t->next;
      s = new Node(d);
      s->next = t->next;
      t->next = s;
      ++count;
      return true;
  }
  bool SingleList::erase(int i) {
      if (i<0 || i>=count) return false;
      Node *t = head, *s = nullptr;
      for (int k=0; k<i; k++) 
          t = t->next;
      s = t->next;
      t->next = s->next;
      delete s;
      --count;
      return true;
  }
  bool get(int i, T& d) {
      if (i<0 ||i>=count) return false;
      Node *t = head;
      for (int k=0; k<i; k++) 
          t = t->next;
      d = t->next->d;
      return true;
  }
  bool set(int i, T& d) {
      if (i<0 || i>=count) return false;
      Node *t = head;
      for (int k=0; k<i; k++)
          t = t->next;
      t->next->d = d;
      return true;
  }
  ```

## 三、C++OOP特征

- 浅拷贝与深拷贝
- 友元函数
- 运算符重载
- const对象与const成员函数

## 四、继承与多态

- 继承
  - 继承允许从一个类派生出另一个类，原始类称为父类，派生类称为子类
  - 子类继承父类的所有变量和方法，可以访问非私有变量和方法，子类不继承父类构造函数、友元函数和重载的运算符
  - 定义子类时需要定义子类构造器以及可能额外声明的变量和方法
  - 继承语法如下: `class ChildClass: public BaseClass {};`
  - 访问权限修饰符
    - public: 所有成员访问权限不变
    - protected: public成员访问权限变为protected
    - private: 所有成员访问权限变为private
    - 一般使用公有继承
- 子类的构造函数定义
  - 构造子类对象之前必需先创建父类对象，C++使用初始化列表创建父类对象
  - 如果不调用父类构造函数，则调用默认的构造函数
  - 继承示例

  ```C++
  #include<string>

  class Shape {
  protected:
      double width;
      double height;
  public:
      Shape():width(0), height(0) {}
      Shape(double a, double b):width(a), height(b){}
      double ares() {
          std::cout<<"calculate area of shape"<<std::endl;
          return 0;
      }
  };
  class Rectangle: public Shape {
  private:
      string Name;
  public:
      Rectangle():Shape(){}
      Rectangle(double a, double b, string name):Shape(a, b), Name(name){}
      string getName() {return name;}
  };

  class Triangle: public Shape {
  private:
      string Name;
  public:
      Triangle():Shape(){}
      Triangle(double a, double b, string name):Shape(a, b), Name(name){}
      string getName() {return name;}
  };
  ```