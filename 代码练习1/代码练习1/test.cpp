#include <iostream>
using namespace std;
int Add(int left, int right)
{
	return left + right;
}
double Add(double left, double right)
{
	return left + right;//编译器在编译阶段，对所传实参类型进行推演，根据推演类型选择调用
}
//函数重载必须在相同的作用域，函数名必须相同，参数列表不同。（参数个数，参数类型，类型次序）
//如果两个函数仅仅是返回值类型不同，不能构成重载
//C语言不支持重载，因为C语言编译器对函数名字的修饰规则是函数名前加上下划线_
//同名的无参函数和全缺省参数函数不要同时存在。
//C++中的引用

void Swap(int left, int right)
{
	int temp = left;
	left = right;
	right = temp;
}

void Swap(int& left, int& right)
{

}

//引用：  起别名 
const int a = 10;
const int& ra = a;//引用可以作为函数参数传递

//如果想要通过形参改变外部实参，普通类型的引用
//如果不想通过形参改变外部实参，const 类型的引用

//引用可以作为函数的返回值
//注意不可以返回函数栈上的空间



int main()
{
	
	return 0;
}