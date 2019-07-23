/**
 * http://c.biancheng.net/view/422.html
 * 能够捕获任何异常的 catch 语句
 * 
 */

#include <iostream>
using namespace std;
int main()
{
    double m, n;
    cout<< "请出入分子与分母：" << endl;
    cin >> m >> n;
    try {
        cout << "before dividing." << endl;
        if (n == 0)
            throw - 1;  //抛出整型异常
        else if (m == 0)
            throw - 1.0;  //拋出 double 型异常
        else
            cout << m / n << endl;
        cout << "after dividing." << endl;
    }
    catch (double d) {
        cout << "catch (double)" << d << endl;
    }
    catch (...) {
        cout << "catch (...)" << endl;
    }
    cout << "finished" << endl;
    return 0;
}