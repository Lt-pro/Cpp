#include <iostream>
using namespace std;

// 左自增与右自增的区别
int main()

{
    int c;
    int d = 10;   //  测试自增、自减
    c = ++d;      // ++d 是先对 d 的值加 1，再使用 d 的值执行该行命令
    cout << "d 等于 " << d << endl;
    cout << "c 等于 " << c << endl ;

    int e = 10;   // 测试自增、自减  
    c = e++;      // e++ 是先使用 e 的值执行该行命令，执行完后再对 e 的值加 1
    cout << "e 等于 " << e << endl;
    cout << "c 等于 " << c << endl ;

    return 0;
}