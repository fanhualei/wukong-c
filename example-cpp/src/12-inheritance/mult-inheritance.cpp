/**
 * 多继承
 *  多继承即一个子类可以有多个父类，它继承了多个父类的特性。
 * 
 */

#include <iostream>

using namespace std;

// 基类 Shape
class Shape
{
public:
    void setWidth(int w)
    {
        width = w;
    }
    void setHeight(int h)
    {
        height = h;
    }
    int a = 1;

protected:
    int width;
    int height;
};

// 基类 PaintCost
class PaintCost
{
public:
    int getCost(int area)
    {
        return area * 70;
    }
    int a = 2;
};

// 派生类
class Rectangle : public Shape, public PaintCost
{
public:
    int getArea()
    {
        return (width * height);
    }
};

int main(void)
{
    Rectangle Rect;
    int area;

    Rect.setWidth(5);
    Rect.setHeight(7);

    area = Rect.getArea();

    //有歧义的处理方法

    cout << "父类中都有a这个变量，如何取得其中一个的呢？: " << Rect.Shape::a << endl;

    // 输出对象的面积
    cout << "Total area: " << Rect.getArea() << endl;

    // 输出总花费
    cout << "Total paint cost: $" << Rect.getCost(area) << endl;

    return 0;
}