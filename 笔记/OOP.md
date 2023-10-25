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
  - C++默认拷贝构造函数将每个成员变量复制给新的对象，该方式称为浅拷贝
  - 当涉及动态内存分配时不能简单复制指针的地址，而是为新对象申请一块新空间并将数据存放到新空间上，该方式称为深拷贝
  - 深拷贝示例

    ```C++
    #include<cstring>
    class baseDMA {
    private:
        char *label;
        int rating;
    public:
        baseDMA():label(nullptr),rating(0){}
        baseDMA(char* l, int r);
        baseDMA(const baseMDA& obj);
        ~baseDMA(){delete [] label;}
        baseDMA& operator=(const baseDMA& obj);
    };
    baseDMA::baseDMA(char* l, int r) {
        label = new char[std::strlen(l)+1];
        std::strcopy(label, l);
        rating = r;
    }
    baseDMA::baseDMA(const baseDMA& obj) {
        label = new char[std::strlen(obj.label)+1];
        std::strcopy(label, obj.label);
        rating = obj.rating;
    }
    baseDMA& baseDMA::operator=(const baseDMA& obj) {
        if (this == &obj)
            return *this;
        delete [] label;
        label = new char[std::stdlen(obj.label)+1];
        std::strcopy(label, obj.label);
        rating = obj.rating;
        return *this;
    }
    ```
- 友元函数
- 运算符重载
- const对象与const成员函数

## 四、继承与多态

- 继承
  - 继承允许从一个类派生出另一个类，原始类称为父类，派生类称为子类
  - 子类继承父类的所有变量和方法，可以访问非私有变量和方法，子类不继承父类构造函数、析构函数和赋值运算符
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

- 多态
  - 多态允许同一方法在基类和派生类表现出不同的行为，即方法的调用取决于对象的类型
  - 具有多态行为的方法应当被声明为virtual，且在子类中应当重新定义基类的虚方法。在子类中调用基类虚方法应当加上作用域解析运算符
  - 如果基类中声明了虚方法，则析构函数应当被声明为虚的，即使方法不做任何事情
  - 基类的指针可以指向派生类对象，但此时只能访问基类的变量和方法，引用同理。基类的指针调用虚方法时将会根据对象类型而非指针类型选择对应的虚方法
  - 多态示例

    ```C++
    #include<string>
    // Base Class
    class Shape {
    private:
        double width;
        double height;
    public:
        Shape():width(0),height(0){}
        Shape(double a, double b):width(a),height(b){}
        virtual ~Shape(){}
        double getWidth(){return width;}
        double getHeight(){return height;}
        void setWidth(double width){this->width = width;}
        void setHeight(double height){this->height = height;}
        virtual double area() {
            std::cout<<"area of shape is ";
        }
    };

    // Rectangle
    class Rectangle:public Shape {
    private:
        std::string name;
    public:
        Rectangle():Shape(),name(""){}
        Rectangle(double a, double b, std::string name0):Shape(a, b),name(name0){}
        std::string getName() {return name;}
        void setName(std::string name) {this->name = name;}
        virtual double area() {
            std::cout<<"This is a "<<name<<"\t,";
            Shape::area();      // 调用基类方法
            std::cout<<width*height<<std::endl;
        }
    };

    // Triangle
    class Triangle:public Shape {
    private:
        std::string name;
    public:
        Triangle():Shape(),name(""){}
        Triangle(double a, double b, std::string name0):Shape(a, b),name(name0){}
        std::string getName() {return name;}
        void setName(std::string name) {this->name = name;}
        virtual double area() {
            std::cout<<"This is a "<<name<<"\t,";
            Shape::area();      //调用基类方法
            std::cout<<0.5 * width * height<<std::endl;
        }
    };

    int main() {
        Shape *p = nullptr;
        Shape sha = Shape(3, 4);
        Rectangle rec = Rectangle(3, 4, "rectangle");
        Triangle  tri = Triangle(3, 4, "triangle");

        p = &sha;
        p->area();  //调用Shape::area()
        std::cout<<std::endl;
        p = &rec;
        p->area();  //调用Rectangle::area()
        std::cout<<std::endl;
        p = &tri;
        p->area();  //调用Triabgle::area()
    
        return 0;
    }
    ```

  - 说明
    - 若派生类定义了不同参数的虚方法，则派生类变量调用虚方法时会隐藏基类同名方法
    - 如果虚方法被重载，派生类应当重新定义所有重载版本
    - 隐藏基类方法示例

    ```C++
    class Base {
    private:
        std::string name;
    public:
        Base():name(""){}
        Base(std::string name0):name(name0){}
        virtual ~Base(){}
        virtual double disp(double x) {return double;}
    }

    class Child: public Base {
    public:
        Child():Base(){}
        Child(std::string name):Base(name){}
        virtual double disp() {return name;}
    }

    int main() {
        Child c("child");
        c.disp()    //正确
        c.disp(0)   //错误，Base::disp(double x)被隐藏
    }
    ```

- 虚方法
  - 使用关键字virtual修饰声明的方法称为虚方法，声明为virtual的方法在基类以及所有派生类中都是虚的。虚方法的定义无需使用virtual修饰
  - 非虚方法使用静态联编，虚方法使用动态联编
  - 当使用指针或引用调用虚方法时会根据对象的类型而非指针或引用类型调用虚方法
  - 当基类存在虚方法时基类应当声明为虚的，以确保在使用指针或引用时释放对象具有正确的析构函数调用顺序
  - 虚方法工作原理
    - 虚函数表(vtbl)存放类中所有虚函数地址的数组，基类和派生类具有独立的虚函数表
    - 存在虚方法的类创建对象时会增加一个隐藏成员，其指向该类的虚函数表
    - 派生类中重写了虚方法则将基类虚方法地址替换为新的虚方法地址，若新增了虚方法则直接加入虚函数表
    - 调用虚方法时先根据隐藏成员找到对应的虚表，再从虚表找到被调用的函数地址，最后调用函数

- 动态内存分配
  - 当基类使用动态内存分配而子类未使用动态内存分配，可直接使用默认的析构函数、拷贝构造函数和赋值运算符
  - 当基类和派生类都使用动态内存分配，必需重新定义析构函数、拷贝构造函数和赋值运算符
    - 析构函数释放派生类变量内存
    - 拷贝构造函数需在初始化列表调用基类拷贝构造函数，传入的派生类对象被解释为基类对象只拷贝基类部分
    - 赋值运算符需要调用基类的赋值运算符
  - 示例程序

    ```C++
    #include<cstring>
    class baseDMA {
    private:
        char *label;
        int rating;
    public:
        baseDMA():label(nullptr),rating(0){}
        baseDMA(char* l, int r);
        baseDMA(const baseMDA& obj);
        ~baseDMA(){delete [] label;}
        baseDMA& operator=(const baseDMA& obj);
    };
    baseDMA::baseDMA(char* l, int r) {
        label = new char[std::strlen(l)+1];
        std::strcopy(label, l);
        rating = r;
    }
    baseDMA::baseDMA(const baseDMA& obj) {
        label = new char[std::strlen(obj.label)+1];
        std::strcopy(label, obj.label);
        rating = obj.rating;
    }
    baseDMA& baseDMA::operator=(const baseDMA& obj) {
        if (this == &obj)
            return *this;
        delete [] label;
        label = new char[std::stdlen(obj.label)+1];
        std::strcopy(label, obj.label);
        rating = obj.rating;
        return *this;
    }

    class hasDMA: public baseDMA {
    private:
        char *style;
    public:
        hasDMA():baseDMA(),style(nullptr){}
        hasDMA(char* l, int r, char* s);
        hasDMA(const hasDMA& obj);
        ~hasDMA(){delete [] style;}
        hasDMA& operator=(const hasDMA& obj);
    };
    hasDMA::hasDMA(char* l, int r, char* s):baseDMA(l, r) {
        style = new char[std::strlen(s)+1];
        std::strcopy(style, s);
    }
    hasDMA::hasDMA(const hasDMA& obj):baseDMA(obj) {
        style = new char[std::strlen(s)+1];
        std::strcopy(style, s);
    }
    hasDMA& hasDMA::operator=(const hasDMA& obj) {
        if (this == &obj)
            return *this;
        baseDMA::operator=(obj);
        delete [] style;
        style = new char[std::strlen(obj.style)+1];
        std::strcopy(style, obj.style);
        return *this;
    }
    ```

## 五、抽象类与多继承

- 抽象类
  - 纯虚方法: 方法声明为`virtual 返回值 方法名(参数列表)=0;`的方法称为纯虚方法，纯虚方法一般无需实现
  - 至少有一个纯虚方法的类称为抽象类，抽象类不能实例化，但可以引用派生类的对象
  - 若子类将基类所有纯虚方法实现为虚方法，则该类为抽象类的一个具体类
  - 示例

    ```C++
    class BaseEllipse {
    private:
        double x;
        double y;
    public:
        BaseEllipse(double x0=0, double y0=0):x(x0),y(y0){}
        virtual ~BaseEllipse(){}            //抽象类的析构函数一定是虚的
        void move(double nx, double ny){x = nx; y = ny;}
        virtual double area() const = 0;    //纯虚方法
    };
    class Circle: public BaseEllipse {
    private:
        double r;
    public:
        Circle(double x0, double y0, double r0):BaseEllipse(x0, y0), r(r0){}
        virtual double area() const;        //纯虚方法的虚方法实现
    };
    class Ellipse: public BaseEllipse {
    private:
        double a;
        double b;
        double angle;
    public:
        Ellipse(double x0, double y0, double a0, double b0, double angle0):BaseEllipse(x0, y0), a(a0), b(b0), angle(angle0){}
        virtual double area() const;        //纯虚方法的虚方法实现
        void rotate(double nang) {angle += nang}
        void scale(double sa, double sb) {a *= sa; b *= sb;}
    };
    ```