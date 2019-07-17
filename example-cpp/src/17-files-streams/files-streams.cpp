/**
 * C++ 文件和流
 * https://www.runoob.com/cplusplus/cpp-files-streams.html
 *  到目前为止，我们已经使用了 iostream 标准库，它提供了 cin 和 cout 方法分别用于从标准输入读取流和向标准输出写入流。
 *  本教程介绍如何从文件读取流和向文件写入流。这就需要用到 C++ 中另一个标准库 fstream，它定义了三个新的数据类型：
 *  ofstream:该数据类型表示输出文件流，用于创建文件并向文件写入信息。
 *  ifstream:该数据类型表示输入文件流，用于从文件读取信息。
 *  fstream:该数据类型通常表示文件流，且同时具有 ofstream 和 ifstream 两种功能，这意味着它可以创建文件，向文件写入信息，从文件读取信息。
 *  要在 C++ 中进行文件处理，必须在 C++ 源代码文件中包含头文件 <iostream> 和 <fstream>。
 * 
 * 打开文件 在从文件读取信息或者向文件写入信息之前，必须先打开文件。ofstream 和 fstream 对象都可以用来打开文件进行写操作，如果只需要打开文件进行读操作，则使用 ifstream 对象。
 * 关闭文件 close() 函数是 fstream、ifstream 和 ofstream 对象的一个成员
 * 写入文件 在这里您使用的是 ofstream 或 fstream 对象，而不是 cout 对象。
 * 
 * 文件位置指针
 *  istream 和 ostream 都提供了用于重新定位文件位置指针的成员函数。
 *  这些成员函数包括关于 istream 的 seekg（"seek get"）和关于 ostream 的 seekp（"seek put"）。
 *  seekg 和 seekp 的参数通常是一个长整型。第二个参数可以用于指定查找方向。
 *      ios::beg 默认的，从流的开头开始定位
 *      ios::cur 从流的当前位置开始定位
 *      ios::end 从流的末尾开始定位
 * 
 */


#include <fstream>
#include <iostream>
using namespace std;
 
int main ()
{
    
   char data[100];
 
   // 以写模式打开文件
   ofstream outfile;
   outfile.open("afile.dat");
 
   cout << "Writing to the file" << endl;
   cout << "Enter your name: "; 
   cin.getline(data, 100);
 
   // 向文件写入用户输入的数据
   outfile << data << endl;
 
   cout << "Enter your age: "; 
   cin >> data;
   cin.ignore();
   
   // 再次向文件写入用户输入的数据
   outfile << data << endl;
 
   // 关闭打开的文件
   outfile.close();
 
   // 以读模式打开文件
   ifstream infile; 
   infile.open("afile.dat"); 
 
   cout << "Reading from the file" << endl; 
   infile >> data; 
 
   // 在屏幕上写入数据
   cout << data << endl;
   
   // 再次从文件读取数据，并显示它
   infile >> data; 
   cout << data << endl; 
 
   // 关闭打开的文件
   infile.close();
 
   return 0;
}