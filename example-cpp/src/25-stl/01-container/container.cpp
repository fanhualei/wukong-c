

/**
 * C++容器（STL容器）
 *  容器（container）用于存放数据的类模板。
 *  可变长数组、链表、平衡二叉树等数据结构在 STL 中都被实现为容器。
 *  容器中可以存放基本类型的变量，也可以存放对象。对象或基本类型的变量被插入容器中时，实际插入的是对象或变量的一个复制品。
 *  STL 中的许多算法（即函数模板），如排序、查找等算法，在执行过程中会对容器中的元素进行比较。
 *  这些算法在比较元素是否相等时通常用运算符进行，比较大小通常用<运算符进行，因此，被放入容器的对象所属的类最好重载==和<运算符，以使得两个对象用==和<进行比较是有定义的。
 * 
 * 顺序容器
 *  顺序容器有以下三种：可变长动态数组 vector、双端队列 deque、双向链表 list。
 *  它们之所以被称为顺序容器，是因为元素在容器中的位置同元素的值无关，即容器不是排序的。
 *  将元素插入容器时，指定在什么位置（尾部、头部或中间某处）插入，元素就会位于什么位置。
 * 
 * 关联容器
 *  关联容器有以下四种：set、multiset、map、multimap。
 *  关联容器内的元素是排序的。
 *  插入元素时，容器会按一定的排序规则将元素放到适当的位置上，因此插入元素时不能指定位置。
 *  默认情况下，关联容器中的元素是从小到大排序（或按关键字从小到大排序）的，而且用<运算符比较元素或关键字大小。
 *  因为是排好序的，所以关联容器在查找时具有非常好的性能。
 * 
 * 容器适配器
 *  三种容器适配器：栈 stack、队列 queue、优先级队列 priority_queue。
 * 
 * 任何两个容器对象，只要它们的类型相同，就可以用 <、<=、>、>=、==、!= 进行词典式的比较运算。
 * 
 * 所有容器都有以下两个成员函数：
 *  int size()：返回容器对象中元素的个数。
 *  bool empty()：判断容器对象是否为空。
 * 
 * 顺序容器和关联容器还有以下成员函数：
 *  begin()：返回指向容器中第一个元素的迭代器。
 *  end()：返回指向容器中最后一个元素后面的位置的迭代器。
 *  rbegin()：返回指向容器中最后一个元素的反向迭代器。
 *  rend()：返回指向容器中第一个元素前面的位置的反向迭代器。
 *  erase(...)：从容器中删除一个或几个元素。该函数参数较复杂，此处省略。
 *  clear()：从容器中删除所有元素。
 * 
 * 如果一个容器是空的，则 begin() 和 end() 的返回值相等，rbegin() 和 rend() 的返回值也相等。
 * 
 * 顺序容器还有以下常用成员函数：
 *  front()：返回容器中第一个元素的引用。
 *  back()：返回容器中最后一个元素的引用。
 *  push_back()：在容器末尾增加新元素。
 *  pop_back()：删除容器末尾的元素。
 *  insert(...)：插入一个或多个元素。该函数参数较复杂，此处省略。
 *
 * 
 * 
 *  
 */

#include <iostream>
#include <vector>  //使用vector需要包含此头文件

using namespace std;
int main()
{
    cout << "初步识别容器\n" << endl;
    cout << "顺序容器：vector deque list \n" << endl;
    cout << "关联容器：set multiset map multimap \n" << endl;
    cout << "容器适配器：stack queue priority_queue \n" << endl;

    vector<int> a;
    a.push_back(1);
    cout << "a:" << a[0] <<endl ;
    return 0;
}