/**
 * C++迭代器（STL迭代器）iterator详解
 *  http://c.biancheng.net/view/338.html
 * 
 *  要访问顺序容器和关联容器中的元素，需要通过“迭代器（iterator）”进行。
 *  迭代器是一个变量，相当于容器和操纵容器的算法之间的中介。
 *  迭代器可以指向容器中的某个元素，通过迭代器就可以读写它指向的元素。从这一点上看，迭代器和指针类似。
 * 
 * 迭代器按照定义方式分成以下四种。
 *  1) 正向迭代器，定义方法如下：容器类名::iterator  迭代器名;
 *  2) 常量正向迭代器，定义方法如下：容器类名::const_iterator  迭代器名;
 *  3) 反向迭代器，定义方法如下：容器类名::reverse_iterator  迭代器名;
 *  4) 常量反向迭代器，定义方法如下：容器类名::const_reverse_iterator  迭代器名;
 * 
 * 迭代器用法示例
 *  通过迭代器可以读取它指向的元素，*迭代器名就表示迭代器指向的元素。
 *  通过非常量迭代器还能修改其指向的元素。
 *  迭代器都可以进行++操作。反向迭代器和正向迭代器的区别在于：
 *      对正向迭代器进行++操作时，迭代器会指向容器中的后一个元素；
 *      而对反向迭代器进行++操作时，迭代器会指向容器中的前一个元素。
 * 
 */


#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;  //v是存放int类型变量的可变长数组，开始时没有元素
    for (int n = 0; n<5; ++n)
        v.push_back(n);  //push_back成员函数在vector容器尾部添加一个元素
    vector<int>::iterator i;  //定义正向迭代器
    for (i = v.begin(); i != v.end(); ++i) {  //用迭代器遍历容器
        cout << *i << " ";  //*i 就是迭代器i指向的元素
        *i *= 2;  //每个元素变为原来的2倍
    }
    cout << endl;
    //用反向迭代器遍历容器
    for (vector<int>::reverse_iterator j = v.rbegin(); j != v.rend(); ++j)
        cout << *j << " ";

    cout << "\n" << endl;    
    return 0;
}