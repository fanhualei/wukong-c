/**
 * 定义新的异常
 *  您可以通过继承和重载 exception 类来定义新的异常。下面的实例演示了如何使用 std::exception 类来实现自己的异常：
 * 
 * 
 */

#include <iostream>
#include <exception>
using namespace std;

/**
 * 用class和struct关键字定义类,有什么不同？
 * 实际上，我们可以使用 class 关键字和 struct 关键字中的任意一个定义类
 * 唯一的一点区别就是，struct 和 class 的默认访问权限不太一样。
 */

struct MyException : public exception
{
    //在这里，what() 是异常类提供的一个公共方法，它已被所有子异常类重载。这将返回异常产生的原因。
    const char *what() const throw()
    {
        return "C++ Exception";
    }
};

int main()
{
    try
    {
        throw MyException();
    }
    catch (MyException &e)
    {
        std::cout << "MyException caught" << std::endl;
        std::cout << e.what() << std::endl;
    }
    catch (std::exception &e)
    {
        //其他的错误
    }
}