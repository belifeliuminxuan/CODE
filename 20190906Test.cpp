 #include <iostream>
 using namespace std;


// �������أ���������ͬ�������򣬺������ֱ�����ͬ�������б�(���������͡����ʹ���)
// ����������������Ƿ���ֵ���Ͳ�ͬ�����ܹ�������
 /*
int Add(int left, int right)
{
	return left + right;
}

double Add(double left, double right)
{
	return left + right;
}


int main()
{
	// �������ڱ���׶Σ����ݶ�������ʵ����������,�������ݵ�ʵ�ʽ��ѡ�����
	// ��Ӧ���͵����غ���
	Add(1, 2);   // int int
	Add(1.0, 2.0); // double double
	
	Add(1, (int)2.0);
	// int, double---���Զ�ʵ�ν�����ʽ����ת��int int
	//                                     double  double
	return 0;
}
*/

#if 0
 // �����б�ͬ�������������������Ͳ�ͬ ���͵Ĵ���ͬ
 void TestFunc()
 {}

 void TestFunc(int a)
 {}

 void TestFunc(double a)
 {}

 void TestFunc(int a, double b)
 {}

 void TestFunc(double a, int b)
 {}

 int TestFunc(int a)
 {
	 return a;
 }

 int main()
 {
	 return 0;
 }
#endif

#if 0

// C���Բ�֧�ֺ�������
// ԭ��C���Ա������Ժ������ֵ����ι���---ֻ���ں�������ǰ����_
// int Add(int left, int right);   // _Add
//  {
// 	 return left + right;
//  }

 double Add(double left, double right);  // _Add
//  {
// 	 return left + right;
//  }

 int main()
 {
	 Add(1.0, 2.0); 
	 return 0;
 }
#endif

#if 0
 // vs ������ʽ
 // C++�������Ժ����������ι���---���������������ӵ����յ�������
 // ?Add@@YAHHH@Z   --- �²⣺H--->int
// int Add(int left, int right);
//  {
// 	 return left + right;
//  }
// 
 // ?Add@@YANNN@Z  ---�²⣺N--->double
 double Add(double left, double right);
//  {
// 	 return left + right;
//  }

 // ?Add@@YAHHN@Z
 int Add(int left, double right);

 int main()
 {
	 //Add(1, 2);   // ?Add@@YAHHH@Z
	 // Add(1.0, 2.0);  // ?Add@@YANNN@Z
	 Add(1, 2.0);  //
	 return 0;
 }
#endif

#if 0
 // int Add(int left, int right);  ?Add@@YAHHH@Z
 // C++д��һ���⣺ C++������ʹ��   C���� _Add
 extern "C" int Add(int left, int right);

 int main()
 {
	 Add(1, 2);
	 return 0;
 }
#endif

#if 0
 // ͬ�����޲κ�����ȫȱʡ������Ҫͬʱ����
 void TestFunc()
 {}

 void TestFunc(int a = 10)
 {}

 int main()
 {
	 //TestFunc();
	 return 0;
 }
#endif

#if 0
 // C�����У����������м��ַ�ʽ��
 // ��ֵ�ʹ�ַ
 // ��ֵ��
 // �ŵ㣺�����ĸ����ò���Ӱ���ⲿʵ��
 // ȱ�㣺�����Ҫͨ���βθı��ⲿʵ�Σ���ֵ������
 //      ���ʵ�αȽϴ��βεĿ���---����Ч�ʱȽϵͣ��Ƚ��˷ѿռ�
 void Swap(int left, int right)
 {
	 cout << &left << " " << &right << endl;

	 int temp = left;
	 left = right;
	 right = temp;
 }

 // ��ַ��
 // �ŵ㣺����ͨ���βθı��ⲿ��ʵ�Σ�����Ч�ʱȽϸ�
 // ȱ�ݣ����������û�Ӱ���ⲿ��ʵ�Σ���ȫ�Բ��ߣ��ɶ��Բ�
 void Swap(int* pa, int* pb)
 {
	 int temp = *pa;
	 *pa = *pb;
	 *pb = temp;
 }

 int main()
 {
	 int a = 10;
	 int b = 20;

	 cout << &a << " " << &b << endl;

	 Swap(a, b);
	 Swap(&a, &b);
	 return 0;
 }
#endif

#if 0
 // ������C++�е�����
 void Swap(int left, int right)
 {
	 int temp = left;
	 left = right;
	 right = temp;
 }

 int main()
 {
	 int a = 10;
	 int b = 20;
	 Swap(a, b);
	 return 0;
 }
#endif

#if 0
 void Swap(int& left, int& right)
 {
	 int temp = left;
	 left = right;
	 right = temp;
 }

 int main()
 {
	 int a = 10;
	 int b = 20;
	 Swap(a, b);

	 int& ra = a;

	 ra = 100;
	 return 0;
 }
#endif

#if 0
 int main()
 {
	 int a = 10;
	 int& ra = a;
	 int& rra = a;
	 int& rrra = ra;

	 if (1)
	 {
		 int& rb = a;
	 }

	 rrra = 100;
	 return 0;
 }
#endif

#if 0
 int main()
 {
	 int a = 10;
	 int& ra = a;

	 int b = 20;
	 ra = b;
	 return 0;
 }
#endif

#if 0
 // const ��������
 int main()
 {
	 const int a = 10;
	 const int& ra = a;

	 const int& rb = 100;

	 double d = 12.34;
	 const int& rd = d;

	 d = 56.78;

	 return 0;
 }
#endif

#if 0
 // ���������������Ĳ���
 void Swap(int& left, int& right)
 {
	 int temp = left;
	 left = right;
	 right = temp;
 }

 // ע�⣺ �����Ҫͨ���βθı��ⲿʵ�Σ��β����ͣ���ͨ��������
 //       �������ͨ���βθı��ⲿʵ�Σ��β����ͣ�const��������

 // ��������
 int main()
 {
	 int a = 10;
	 int& ra = a;

	 return 0;
 }
#endif

#if 0
 // ���ã�������Ϊ�����ķ���ֵ
 int g_a = 0;

 int& Add(int left, int right)
 {
	 int ret = left + right;
	 return ret;
 }

 int Sub(int left, int right)
 {
	 int ret = left - right;
	 return ret;
 }

 // ע�⣺��Ҫ���غ���ջ�ϵĿռ�


 int main()
 {
	 //
	 int& r = Add(1, 2);
	 //Sub(10, 5);
	 Add(3, 4);
	 return 0;
 }
#endif

#if 0
 int& TestFunc(int& ra)
 {
	 return ra;
 }

 int main()
 {
	 int a = 10;
	 int& rra = TestFunc(a);
	 return 0;
 }
#endif


#if 0
 // ����Ч�ʱȽϣ���ֵ����(ֵ�ÿ���)������ַ�ʹ�����Ч�ʼ���һ��
#include <time.h>
 struct A
 {
	 int a[10000];
 };

 void TestFunc1(A* a)
 {}

 void TestFunc2(A& a)
 {}

 void TestRefAndValue()
 {
	 A a;
	// ��ֵ��Ϊ��������
	size_t begin1 = clock();
	 for (size_t i = 0; i < 10000; ++i)
		 TestFunc1(&a);
	 size_t end1 = clock();

	 // ��������Ϊ��������
	 size_t begin2 = clock();
	 for (size_t i = 0; i < 10000; ++i)
		 TestFunc2(a);
	 size_t end2 = clock();
	 // �ֱ���������������н������ʱ��
	 cout << "TestFunc1(int*)-time:" << end1 - begin1 << endl;
	 cout << "TestFunc2(int&)-time:" << end2 - begin2 << endl;
 }

 // ���ж�Σ����ֵ�������ڴ��η����Ч������
 int main()
 {
	 for (int i = 0; i < 10; ++i)
	 {
		 TestRefAndValue();
	 }
	 return 0;
 }
#endif


#if 0
 // ���ú�ָ����ʲô����
 void Swap(int* pa, int* pb)
 {
	 int temp = *pa;
	 *pa = *pb;
	 *pb = temp;
 }

 void Swap(int& ra, int& rb)
 {
	 int temp = ra;
	 ra = rb;
	 rb = temp;
 }

 int main()
 {
	 int a = 10;
	 int b = 20;

	 int* pa = &a;
	 *pa = 20;

	 int& ra = a;
	 ra = 20;

	 Swap(&a, &b);
	 Swap(a, b); // �������ڵײ��ʵ�ʲ�����Swap(&a, &b);
	 return 0;
 }
#endif

#if 0
 int main()
 {

	 int* pa;

	 int a = 10;
	 //int& ra;

	 int b = 20;

	 pa = &a;
	 pa = &b;

	 int& ra = a;
	 ra++;
	 //r = b;

	 char c = 'c';
	 char* pc = &c;
	 char& rc = c;
	 cout << sizeof(pc) << endl;
	 cout << sizeof(rc) << endl;

	 int** p;

	 // ��ֵ����
	 const int&& r = 10;
	 return 0;
 }
#endif

#if 0
 // �����ܷ�ͨ�����룿 �ܷ��������У� ���ܻ����ǿ����
 void Swap(int& ra, int& rb)
 {
	 int temp = ra;
	 ra = rb;
	 rb = temp;
 }

 int main()
 {
	 int a = 10;
	 int* pb = NULL;
	 //*pb = 100;

	 Swap(a, *pb);
	 return 0;
 }
#endif


#if 0
 // C++�У���const���εı���---->����
 // ���к��滻������--->�ڱ���ڵ�����滻--->��������ͼ��
 int main()
 {
	 const int a = 10;

	 int* pa = (int*)&a;
	 *pa = 100;

	 printf("%d", /*a*/ 10);
	 printf("%d", *pa);

	 return 0;
 }
#endif


#if 0
 // �꺯��ȱ�ݣ�������  ��Ԥ����ڵ��滻������������ͼ��  �����Ե���
                
#define MAX(a, b)   ((a) > (b)? (a) : (b))

 int main()
 {
	 int a = 10;
	 int b = 20;

	 cout << MAX(++b, a);
	 return 0;
 }
#endif

#if 0
 inline int Add(int left, int right)
 {
	 //Add(left, right);
	 return left + right;
 }

 int main()
 {
	int a = 10;
	int b = 20;
	int c = Add(a, b);
	cout << 30 << endl;
	 return 0;
 }
#endif

#if 0
//#include "a.h"

 inline int Add(int left, int right)
 {
	 return left + right;
 }

 int main()
 {
	 Add(1, 2);
	 return 0;
 }
#endif


#if 0
 // �������ڱ���׶Σ������ṩ�ĳ�ʼ�����ʽʵ�����ͣ���ȷ������������
 int main()
 {
	 auto a = 10;
	 auto b = 12.34;
	 //auto c;
	 cout << typeid(a).name() << endl;
	 cout << typeid(b).name() << endl;
	 return 0;
 }
#endif

#if 0
#include <map>
#include <string>

 int main()
 {
	 std::map<std::string, std::string> m{ { "apple", "ƻ��" }, { "peach", "����" } };

	 // C++98�﷨
	 //std::map<std::string, std::string>::iterator it = m.begin();
	 auto it = m.begin();
	 while (it != m.end())
	 {
		 cout << it->first << "-->" << it->second << endl;
		 ++it;
	 }
	 cout << endl;
	 return 0;
 }
#endif

#if 0
 int main()
 {
	 int a = 10;
	 auto pa1 = &a;
	 auto* pa2 = &a;

	 cout << typeid(pa1).name() << endl;
	 cout << typeid(pa2).name() << endl;


	 auto ra = a;
	 ra = 20;

	 auto& rra = a;
	 rra = 30;

	 return 0;
 }
#endif

#if 0
 int main()
 {
	 auto a = 1, b = 2.0, c = 3;

	 return 0;
 }
#endif


//  void TestFunc(auto a)
//  {}

#if 0
 int main()
 {
	 int arr1[10] = { 1, 2, 3 };
	 //auto arr2[] = { 1, 2, 3 };
	 return 0;
 }
#endif


#if 0
 int main()
 {
	 // [array, array+sizeof(array) / sizeof(array[0]) );
	 /*
	 int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	 for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
		 array[i] *= 2;

	 for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
		 cout<<array[i]<<" ";
	 cout << endl;
	 */


	 // ��Χforѭ��
	 int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	 for (auto& e : array)
		 e *= 2;

	 for (auto e : array)
		 cout << e << " ";
	 cout << endl;

	 return 0;
 }
#endif

 void TestFunc(int* array)
 {
	 for (auto e : array)
		 cout << e << " ";
 }


 int main()
 {
	 int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	 TestFunc(array);
	 return 0;
 }



