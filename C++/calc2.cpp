#include<iostream>
using namesapce std;


// ++/--作用于指针
int main(){
    int *a = new int(6);
    cout << a << endl;
    *a -= 1;
    cout << a << endl;
    cout << *a << endl;
    *a--;
    cout << a << endl;
    cout << *a << endl;
    return 0;
    /* 
    * 0xd81750 a的地址
    * 0xd81750 a的地址
    * 5        
    * 0xd8174c a的地址少了4
    * 469788465 值错误
    */
}