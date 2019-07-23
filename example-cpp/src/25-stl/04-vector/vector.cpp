/**
 * C++ vector，STL vector（可变长的动态数组）详解
 *  
 * vector 是顺序容器的一种。
 * vector 是可变长的动态数组，支持随机访问迭代器，所有 STL 算法都能对 vector 进行操作。
 * 要使用 vector，需要包含头文件 vector。
 * 
 * 在 vector 容器中，根据下标随机访问某个元素的时间是常数，在尾部添加一个元素的时间大多数情况下也是常数，总体来说速度很快。
 * 
 * 在中间插入或删除元素时，因为要移动多个元素，因此速度较慢，平均花费的时间和容器中的元素个数成正比。
 * 
 * 
 * 
 */


#include <iostream>
#include <vector>  //使用vector需要包含此头文件
using namespace std;
template <class T>
void PrintVector(const vector <T> & v)
{  //用于输出vector容器的全部元素的函数模板
    typename vector <T>::const_iterator i;
    //typename 用来说明 vector <T>::const_iterator 是一个类型，在 Visual Studio 中不写也可以
    for (i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";
    cout << endl;
}
int main()
{
    int a[5] = { 1, 2, 3, 4, 5 };
    //将数组a的内容放入v
    vector <int> v(a, a + 5);  
    //两个随机迭代器可以相减，输出：1)5
    cout << "1) " << v.end() - v.begin() << endl;  
    //输出：2)1 2 3 4 5
    cout << "2)"; PrintVector(v);  

    //在 begin()+2 位置插人 13
    v.insert(v.begin() + 2, 13);  
    cout << "3)"; PrintVector(v);  //输出：3)1 2 13 3 4 5

    //删除位于 begin()+2 位置的元素
    v.erase(v.begin() + 2);  
    cout << "4)"; PrintVector(v);  //输出：4)1 2 3 4 5

    //v2 有 4 个元素，都是 100
    vector<int> v2(4, 100);  
    //将v的一段插入v2开头
    v2.insert(v2.begin(), v.begin() + 1, v.begin() + 3);  
    cout << "5)v2:"; PrintVector(v2);  //输出：5)v2:2 3 100 100 100 100

    v.erase(v.begin() + 1, v.begin() + 3);  //删除 v 上的一个区间，即 [2,3)
    cout << "6)"; PrintVector(v);  //输出：6)1 4 5
    
    return 0;
}
