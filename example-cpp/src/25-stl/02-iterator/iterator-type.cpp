/**
 * 迭代器的功能分类
 *  1) 正向迭代器。
 *      假设 p 是一个正向迭代器，则 p 支持以下操作：++p，p++，*p。此外，两个正向迭代器可以互相赋值，还可以用==和!=运算符进行比较。
 *  2) 双向迭代器。
 *      双向迭代器具有正向迭代器的全部功能。除此之外，若 p 是一个双向迭代器，则--p和p--都是有定义的。--p使得 p 朝和++p相反的方向移动。
 *  3) 随机访问迭代器。
 *      随机访问迭代器具有双向迭代器的全部功能。若 p 是一个随机访问迭代器，i 是一个整型变量或常量，则 p 还支持以下操作：
 *      p+=i：使得 p 往后移动 i 个元素。
 *      p-=i：使得 p 往前移动 i 个元素。
 *      p+i：返回 p 后面第 i 个元素的迭代器。
 *      p-i：返回 p 前面第 i 个元素的迭代器。
 *      p[i]：返回 p 后面第 i 个元素的引用。
 * 
 * 
 */

/**
 
    vector	随机访问
    deque	随机访问
    list	双向
    set / multiset	双向
    map / multimap	双向
    stack	不支持迭代器
    queue	不支持迭代器
    priority_queue	不支持迭代器

 */

// 例如，vector 的迭代器是随机迭代器，因此遍历 vector 容器有以下几种做法。下面的程序中，每个循环演示了一种做法。
#include <iostream>
#include <vector>
#include <list>
using namespace std;
int main()
{
    vector<int> v(10); //v被初始化成有10个元素

    for (int i = 0; i < v.size(); ++i) //size返回元素个数
        v[i] = i;

    for (int i = 0; i < v.size(); ++i) //size返回元素个数
        cout << v[i] << " ";           //像普通数组一样使用vector容器

    cout << "\n\n";

    vector<int>::iterator i;
    for (i = v.begin(); i != v.end(); ++i) //用 != 比较两个迭代器
        cout << *i << " ";

    cout << "\n\n";

    for (i = v.begin(); i < v.end(); ++i) //用 < 比较两个迭代器
        cout << *i << " ";

    cout << "\n\n";

    i = v.begin();
    while (i < v.end())
    { //间隔一个输出
        cout << *i << " ";
        i += 2; // 随机访问迭代器支持 "+= 整数"  的操作
    }

    cout << "\n\n";

    cout << "list是双向迭代器，有些功能是不支持的\n\t因为双向迭代器不支持用“<”进行比较。\n\t y[i]括号页不行" << endl;

    list<int> y(10);
    list<int>::iterator x;
    for (x = y.begin(); x != y.end(); ++x)
        cout << *x;


}