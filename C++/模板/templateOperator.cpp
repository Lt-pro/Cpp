#include <iostream>

// 定义一个简单的类，用于示例
template<typename T>
class MyClass {
public:
    MyClass(T value) : data(value) {}

    // 重载 << 运算符的模板
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const MyClass<U>& obj);

private:
    T data;
};

// 模板重载 << 运算符的实现
template<typename T>
std::ostream& operator<<(std::ostream& os, const MyClass<T>& obj) {
    os << obj.data;
    return os;
}

int main() {
    // 使用模板重载 << 运算符输出不同类型的对象
    MyClass<int> intObj(42);
    MyClass<double> doubleObj(3.14);

    std::cout << "Integer Object: " << intObj << std::endl;
    std::cout << "Double Object: " << doubleObj << std::endl;

	system("pause");
    return 0;
}
