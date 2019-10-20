#include <iostream>
using namespace std;


#if 0
// ��
struct Student
{
	// ��Ա���� || ��Ϊ
	void SetStudentInfo(char* name, char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudent()
	{
		cout << _name << ":" << _gender << ":" << _age << endl;
	}

	// ��Ա���� || ����
	char _name[20];
	char _gender[3];
	int _age;
};


int main()
{
	Student s;
	s.SetStudentInfo("Peter", "��", 29);
	s.PrintStudent();

	return 0;
}
#endif

// ���������򣺷�װ  �̳�  ��̬
// ��װ����һ��������ڲ�ʵ��ϸ�������������ṩһ�����нӿ��ö���֮����н���

// C++ʵ�ַ�װ����(ͨ���ཫ��������Ժ���Ϊ��װ��һ��)
//   ����Ȩ�ޣ�private  protected  public
// public: ��public���εĳ�Ա������ֱ�������ⱻ����
// protected/private: ����ֱ����������з���

//int _age = 10;

// void SetStudentInfo(char* name)
// {}

#if 0
class Student
{
public:
	// ��Ա���� || ��Ϊ
	void SetStudentInfo(char* name, char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudent()
	{
		cout << _name << ":" << _gender << ":" << _age << endl;
	}

private:
	// ��Ա���� || ����
	char _name[20];
	char _gender[3];
	int _age;
};


int g_a = 10;
int main()
{
	Student s;
	s.SetStudentInfo("Peter", "��", 29);
	s.PrintStudent();

	// s._age = 30;
	cout << g_a << endl;
	return 0;
}
#endif

#if 0
struct Student
{
public:
	// ��Ա���� || ��Ϊ
	void SetStudentInfo(char* name, char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudent()
	{
		cout << _name << ":" << _gender << ":" << _age << endl;
	}

private:
	// ��Ա���� || ����
	char _name[20];
	char _gender[3];
	int _age;
};

int main()
{
	Student s1,s2,s3;
	cout << sizeof(s1) << endl;

	s1.SetStudentInfo("Peter", "��", 29);
	s2.SetStudentInfo("����", "Ů", 30);
	s3.SetStudentInfo("summer", "��", 4);


	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();
	return 0;
}
#endif

#if 0
class A
{
public:
	void TestFun()
	{}
};


// ����Ĵ�С�������������п���Ĵ�С��1
class B
{};


// 
int main()
{
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;

	B b1, b2, b3;


	return 0;
}
#endif

#if 0
struct Student
{
	char _name[20];
	char _gender[3];
	int _age;
};

void SetStudentInfo(Student* ps, char* name, char* gender, int age)
{
	strcpy(ps->_name, name);
	strcpy(ps->_gender, gender);
	ps->_age = age;
}

void PrintStudent(Student* ps)
{
	printf("%s %s %d", ps->_name, ps->_gender, ps->_age);
}
#endif




#if 0
class Student
{
public:
	void SetStudentInfo(char* name, char* gender, int age)
	{
		// Student* const
		//this = nullptr;
		cout << this << endl;
		strcpy(this->_name, name);
		strcpy(this->_gender, gender);
		this->_age = age;
	}

	void PrintStudent()
	{
		cout << this->_name << ":" << this->_gender << ":" << this->_age << endl;
	}

	// ��������
	void TestFunc(...)
	{
		cout << this << endl;
	}

private:
	// ��Ա���� || ����
	char _name[20];
	char _gender[3];
	int _age;
};
#endif

/*
Ů����
δ��Ů���ѵ�һЩ������Ϣ
���� & 


1. ��ʶ������
2. ʶ�����еĳ�Ա����
3. ʶ�����еĳ�Ա�������Ҷ����еĳ�Ա�������и�д
*/
#if 0
class Student
{
public:
	/*
	void SetStudentInfo(Student* const this, char* name, char* gender, int age)
	{
	strcpy(this->_name, name);
	strcpy(this->_gender, gender);
	this->_age = age;
	}
	*/
	void SetStudentInfo(char* name, char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	/*
	void PrintStudent(Student* const this)
	{
	cout << this->_name << ":" << this->_age << endl;
	}
	*/
	void PrintStudent()
	{
		cout << _name << ":" << _age << endl;
	}

private:
	// ��Ա���� || ����
	char _name[20];
	char _gender[3];
	int _age;
};


int main()
{
	//cout << this << endl;
	Student s1, s2, s3;
	s1.TestFunc(10);

	cout << &s1 << endl;
	s1.SetStudentInfo("Peter", "��", 29);
	
	cout << &s2 << endl;
	s2.SetStudentInfo("����", "Ů", 30);
	
	cout << &s3 << endl;
	s3.SetStudentInfo("summer", "��", 4);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();
	return 0;
}
#endif

class A
{
public:
	void PrintA()
	{
		cout << this << endl;
		cout << this->_a << endl;
	}

	void Show()
	{
		cout << this << endl;
		cout << "Show()" << endl;
	}
private:
	int _a;
};

int main()
{
	A* p = NULL;
	p->Show();
	p->PrintA();
	

	return 0;
}


