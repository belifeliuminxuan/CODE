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



