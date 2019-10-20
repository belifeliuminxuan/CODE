#include <iostream>
using namespace std;

#if 0
int main()
{
	int* p = (int*)malloc(sizeof(int)* 10);
	free(p);
	return 0;
}
#endif

#if 0
// new/delete     new[]/delete[]
// malloc/free
// ע�⣺һ��Ҫƥ��ʹ��
// 1. new��delete���Ǻ�����C++�ṩ���µĲ�����
// 2. new/new[] ֻ���������ռ����ͣ�����Ҫ�����ֽ���
// 3. new ����ľ��ǿռ�����ͣ���˲���Ҫǿת
// 4. new/new[]���Խ��г�ʼ��
// 5. new�Ľ������Ҫ�п�
// 6. 

int main()
{
	// new ���뵥������Ԫ�صĿռ�---Ĭ�������new���Ŀռ��ڶ���
	int* p1 = new int;
	int* p2 = new int(10);
	int* p3 = new int[10];
	int* p4 = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

	delete p1;
	delete p2;
	delete[] p3;
	delete[] p4;
	return 0;
}
#endif

#if 0
// ���û��ƥ��ʹ�ã��������?
// �����������������͵Ŀռ䣬��������κκ��
void Test1()
{
	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = (int*)malloc(sizeof(int));
	delete p1;
	delete[] p2;

	int* p3 = new int;
	int* p4 = new int;
	free(p3);
	delete[] p4;

	int* p5 = new int[10];
	int* p6 = new int[10];
	free(p5);
	delete p6;
}


// �Զ�������
class Test
{
public:
	Test()
	{
		_data = 10;
		_p = new int;
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		delete _p;
		cout << "~Test():" << this << endl;
	}

private:
	int _data;
	int* _p;
};

// �����Զ������ͣ�ֻҪ�漰��[]����Ȼ�����
// new����ù��캯��
// free���������������--�����е���Դ���ᱻ����
void Test2()
{
	//Test* p3 = new Test;
	//Test* p4 = new Test;
	//free(p3);
	//delete[] p4;


	// malloc����ռ�ʱ������ù��캯��--�������������С��ͬ��һ���ڴ�ռ�
	//             ���ܽ��ÿ��ڴ�ռ俴����һ������

	Test* p1 = (Test*)malloc(sizeof(Test));
	//Test* p2 = (Test*)malloc(sizeof(Test));
	delete p1;   // ��Ҫ��������������������е���Դ
	//delete[] p2;



	//Test* p5 = new Test[10];
	//Test* p6 = new Test[10];
	//free(p5);
	//delete p6;
}

int main()
{
	//Test1();
	Test2();
	_CrtDumpMemoryLeaks();
	return 0;
}
#endif

#if 0
// �Զ�������
class Test
{
public:
	Test()
	{
		_data = 10;
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}

private:
	int _data;
};

int main()
{
	Test* pt = new Test[10];
	delete[] pt;
	return 0;
}
#endif

#if 0
/*
1. new--->�ܹ�������ռ����Ϣ��ӡ
2. delete---> �ܹ����ͷſռ���Ϣ��ӡ
*/

void* operator new(size_t size, const char* filename, const char* funName, size_t lineNo)
{
	cout << filename << "-" << funName << "-" << lineNo << "-" << size << endl;
	return malloc(size);
}

void operator delete(void* p, const char* filename, const char* funName, size_t lineNo)
{
	cout << filename << "-" << funName << "-" << lineNo << endl;
	free(p);
}

#define new new(__FILE__, __FUNCDNAME__, __LINE__)

int main()
{
	int* p = new int;
	delete p;
	return 0;
}
#endif

#if 0
struct ListNode
{
	ListNode* _next;
	ListNode* _prev;
	int _data;

	void* operator new(size_t n)
	{
		void* p = nullptr;
		p = allocator<ListNode>().allocate(1);
		cout << "memory pool allocate" << endl;
		return p;
	}

	void operator delete(void* p)
	{
		allocator<ListNode>().deallocate((ListNode*)p, 1);
		cout << "memory pool deallocate" << endl;
	}
};

class List
{
public:
	List()
	{
		_head = new ListNode;
		_head->_next = _head;
		_head->_prev = _head;
	}
	~List()
	{
		ListNode* cur = _head->_next;
		while (cur != _head)
		{
			ListNode* next = cur->_next;
			delete cur;
			cur = next;
		}
		delete _head;
		_head = nullptr;
	}
private:
	ListNode* _head;
};

void TestList()
{
	List l;
}

int main()
{
	TestList();
	return 0;
}
#endif

#if 0
class Test
{
public:
	Test(int data)
	{
		_data = 10;
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}

private:
	int _data;
};

// placement-new
// ��λnew���ʽ�����Ѿ����ڵĿռ���ִ�й��캯��
// �﷨�� new(��ַ) Test(����);


/*
��������ռ��new������---C++�ṩ�Ĺؼ���---ר����������ռ�
 1. ����void* operator new(size_t size)
       {
	       // ����mallocѭ������ + �ռ䲻��Ӧ�Դ�ʩ
	   }
 2. ���ù��캯��

 void* operator new(size_t size)��һ��������һ������²���Ҫ�Լ�����
 ������Ҫ�������⹦��

 ��λnew���ʽ��
  new(p) T
    1. void* operator new(size_t size, void* where)
	   {
	        return where;
	   }

	2. ִ�й��캯��
*/

int main()
{
	Test* pt = (Test*)malloc(sizeof(Test));

	// ֻ����ptָ��Ŀռ���ִ�й��캯��
	/*
	��λnew���ʽ������operator new
	void* operator new(size_t size, void* where)
	{
	     return where;
	}
	*/
	new(pt) Test(10);

	//delete pt;
	pt->~Test();
	free(pt);
	// ��Ҫ��ptָ��Ŀռ䵱�ɶ�������
	return 0;
}
#endif

#if 0
class Test
{
public:
	~Test()
	{
		Test* p = new Test;
		delete p;
	}
};

int main()
{
	Test* pt = new Test;
	delete pt;
	return 0;
}
#endif

#if 0
// �漰һ���࣬����ֻ���ڶ��ϴ�������
class Object
{
public:
	static Object* GetObject(int data)
	{
		return new Object(data);
	}

	~Object()
	{}


	// C++98
//private:
//	Object(const Object& o);

	// C++11
	// 1. �ͷ�new�Ŀռ�
	// 2. ��Ĭ�ϳ�Ա���������=delete, ɾ��Ĭ�ϵĿ������캯��
	Object(const Object& o) = delete;
private:
	Object(int data)
	{}
};


//�û�
//Object::Object(const Object&)
//{}

int main()
{
	Object* p= Object::GetObject(10);
	delete p;

	Object o(*p);  // �������캯��
	return 0;
}
#endif


#if 0
// 64λϵͳ & ������64λ��ʽ����---ָ�����8���ֽ�
#include <iostream>
using namespace std;

int main()
{
	cout << sizeof(int*) << endl;
	void* p = new char[0xfffffffful];
	cout << "new:" << p << endl;
	return 0;
}
#endif

#if 0
// дһ��ͨ�õļӷ�������--�������Ͷ����Դ���
// ��������
int Add(int left, int right)
{
	return left + right;
}

double Add(double left, double right)
{
	return left + right;
}

char Add(char left, char right)
{
	return left + right;
}


int main()
{
	Add(1, 2);
	Add(1.0, 2.0);
	return 0;
}
#endif

#if 0
// �������޹�
// Add����ģ��
//template<class T1, class T2>       // ģ������б�
//T1 Add(T1 left, T2 right)  // �����б�
//{
//	cout << typeid(T1).name() << endl;
//	return left + right;
//}

template<class T>       // ģ������б�
T Add(T left, T right)  // �����б�
{
	cout << typeid(T).name() << endl;
	return left + right;
}

int main()
{
	// �Ժ���ģ�����ʵ����
	// �ڱ���׶Σ������������⵽��ĳ������ģ�������ʵ����
	// ��ʵ�ε����ͽ������ݣ��������ݵĽ����ȷ��ģ������б���T��ʵ������
	// ��Ϻ���ģ�����ɴ���������͵ĺ���
	// ��ʽʵ����
	Add(1, 2);  // int, int--T==>int ����intAdd����--->Add<int>
	Add(1.0, 2.0); //double, double--> T==>double ����double Add����--->Add<double>
	Add('1', '2'); //char char-->T==char ����char Add����--->Add<char>
	
	// ģ�����һ�㲻���������ת��
	//Add(1, 2.0);   // int double--> T
	Add(1, (int)2.0);


	// ��ʽʵ����---ֱ��ָ������T��ʵ������
	// �����������ܻ����ʽ����ת��
	Add<int>(1, 2.0);
	return 0;
}
#endif

#if 0
int Add(int left, int right)
{
	return left + right;
}

template<class T>
T Add(T left, T right)
{
	return left + right;
}

int main()
{
	Add(1, 2);


	// �Ժ���ģ�������ʽʵ����
	// ͬ�������뺯��ģ��ͬʱ����ʱ������ʹ��ģ�����ɵ�ͬ������
	Add<>(1, 2);   


	Add<int>(1, 2);
	return 0;
}
#endif

#if 0
int Add(int left, int right)
{
	return left + right;
}

template<class T1, class T2>
T1 Add(T1 left, T2 right)
{
	return left + right;
}

int main()
{
	Add(1, 2);

	Add(1.0, 2);
	return 0;
}
#endif

#if 0
#include <assert.h>

// ˳���  ����  ջ�Ͷ���  ������  ��  ����

// typedef int DataType;

//��̬����˳���
template<class T>
class SeqList
{
public:
	SeqList(size_t capacity = 10)
		: _array(new T[capacity])
		, _size(0)
		, _capacity(capacity)
	{}

	~SeqList()
	{
		if (_array)
		{
			delete[] _array;
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}

	// β��
	void PushBack(const T& data);
	void PopBack()
	{
		--_size;
	}

	// ����λ�ò����ɾ��
	//void Insert(size_t pos, const T& data);
	//void Erase(size_t pos);

	// ��const���ͳ�Ա�����в����޸ĳ�Ա����
	// ����thisָ��
	size_t size()const
	{
		return _size;
	}

	size_t Capacity()const
	{
		return _capacity;
	}

	bool Empty()const
	{
		return 0 == _size;
	}

	//////////////////////////
	T& operator[](size_t index)
	{
		assert(index < _size);
		return _array[index];
	}

	const T& operator[](size_t index)const
	{
		assert(index < _size);
		return _array[index];
	}

private:
	void _CheckCapacity()
	{
		if (_size == _capacity)
		{
			// �����¿ռ�
			T* array = new T[2 * _capacity];

			// ����Ԫ��
			// memcpy(array, _array, _size*sizeof(T));
			for (size_t i = 0; i < _size; ++i)
			{
				array[i] = _array[i];
			}

			// �ͷžɿռ�
			delete[] _array;
			_array = array;
			_capacity *= 2;
		}
	}
private:
	T* _array;
	size_t _size;
	size_t _capacity;
};

template<class T>
void SeqList<T>::PushBack(const T& data)
{
	_CheckCapacity();
	_array[_size++] = data;
}


void TestSeqList()
{
	SeqList<int>  s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);
	cout << s1.size() << endl;
	cout << s1.Capacity() << endl;

	cout << s1[2] << endl;
	s1[2] = 10;

	const SeqList<double>  s2;
	s2[0];
}

int main()
{
	TestSeqList();
	return 0;
}
#endif

int main()
{
	return 0;
}