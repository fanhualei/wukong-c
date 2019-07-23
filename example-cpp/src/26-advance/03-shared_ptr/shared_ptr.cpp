/**
 * shared_ptr（智能指针）详解
 * http://c.biancheng.net/view/430.html
 * 
 * 要确保用 new 动态分配的内存空间在程序的各条执行路径都能被释放是一件麻烦的事情。
 * C++ 11 模板库的 <memory> 头文件中定义的智能指针，即 shared _ptr 模板，就是用来部分解决这个问题的。
 * 
 * 编译时，要使用：编译：g++ -std=c++11 -o test.exe ptr.cpp　　c++11模板
 * 
 */
// make_shared example
#include <iostream>
#include <memory>
using namespace std;
class A
{
public:
    int i;
    A(int n):i(n) { };
    ~A() { cout << i << " " << "destructed" << endl; }
};
int main()
{
    shared_ptr<A> sp1(new A(2)); //A(2)由sp1托管，
    shared_ptr<A> sp2(sp1);       //A(2)同时交由sp2托管
    shared_ptr<A> sp3;
    sp3 = sp2;   //A(2)同时交由sp3托管
    cout << sp1->i << "," << sp2->i <<"," << sp3->i << endl;
    A * p = sp3.get();      // get返回托管的指针，p 指向 A(2)
    cout << p->i << endl;  //输出 2
    sp1.reset(new A(3));    // reset导致托管新的指针, 此时sp1托管A(3)
    sp2.reset(new A(4));    // sp2托管A(4)
    cout << sp1->i << endl; //输出 3
    sp3.reset(new A(5));    // sp3托管A(5),A(2)无人托管，被delete
    cout << "end" << endl;
    return 0;
}