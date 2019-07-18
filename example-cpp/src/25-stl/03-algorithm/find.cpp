/**
 * STL算法详解
 *  STL 提供能在各种容器中通用的算法（大约有70种），如插入、删除、查找、排序等。
 *  算法就是函数模板。
 *  算法通过迭代器来操纵容器中的元素。
 * 
 * 许多算法操作的是容器上的一个区间（也可以是整个容器），因此需要两个参数，一个是区间起点元素的迭代器，另一个是区间终点元素的后面一个元素的迭代器。
 * 例如，排序和查找算法都需要这两个参数来指明待排序或待查找的区间。
 * 
 * 有的算法返回一个迭代器。例如，find 算法在容器中查找一个元素，并返回一个指向该元素的迭代器。
 * 
 * 算法可以处理容器，也可以处理普通的数组。
 * 
 * 有的算法会改变其所作用的容器。例如：
 *  copy：将一个容器的内容复制到另一个容器。
 *  remove：在容器中删除一个元素。
 *  random_shuffle：随机打乱容器中的元素。
 *  fill：用某个值填充容器。
 * 
 * 有的算法不会改变其所作用的容器。例如：
 *  find：在容器中查找元素。
 *  count_if：统计容器中符合某种条件的元素的个数。
 * 
 * STL 中的大部分常用算法都在头文件 algorithm 中定义。此外，头文件 numeric 中也有一些算法。
 * 
 * 下面介绍一个常用算法 find，以便对算法是什么、怎么用有一个基本的概念。find 算法和其他算法一样都是函数模板。find 模板的原型如下：
 *  template <class InIt, class T>
 *  InIt find(InIt first, InIt last, const T& val);
 * 
 * 
 */


#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int main()  {
    int a[10] = {10,20,30,40};
    vector<int> v;
    v.push_back(1);    v.push_back(2);
    v.push_back(3);    v.push_back(4); //此后v里放着4个元素：1,2,3,4
    vector<int>::iterator p;
    p = find(v.begin(),v.end(),3); //在v中查找3
    if(p != v.end()) //若找不到,find返回 v.end()
        cout << "1) " <<  * p << endl; //找到了
    p = find(v.begin(),v.end(),9);
    if(p == v.end())
        cout << "not found " << endl; //没找到
    p = find(v.begin()+1,v.end()-1,4); //在,3 这两个元素中查找4
    cout << "2) " << * p << endl;
    int * pp = find(a,a+4,20);
    if(pp == a + 4)
        cout << "not found" << endl;
    else
        cout << "3) " <<* pp << endl;
}