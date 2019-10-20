#include <iostream>
using namespace std;

#if 0
// vector�ײ�ṹ����̬���͵�˳���
// vector<char>  string
#include <vector>

void TestVector1()
{
	vector<int> v1;
	vector<int> v2(10, 5);
	vector<int> v3(v2);

	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	vector<int> v4(array, array + sizeof(array) / sizeof(array[0]));

	vector<int> v5{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	for (size_t i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;

	for (auto e : v3)
		cout << e << " ";
	cout << endl;

	//vector<int>::iterator it = v4.begin();
	auto it1 = v4.begin();
	while (it1 != v4.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;


	auto it2 = v5.rbegin();
	while (it2 != v5.rend())
	{
		cout << *it2 << " ";
		++it2;
	}
	cout << endl;
}

void TestVector2()
{
	vector<int> v5{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	cout << v5.size() << endl;
	cout << v5.capacity() << endl;
	cout << v5.front() << endl;
	cout << v5.back() << endl;

	v5.push_back(1);
	v5.push_back(2);
	v5.push_back(3);
	cout << v5.size() << endl;
	cout << v5.capacity() << endl;
	cout << v5.front() << endl;
	cout << v5.back() << endl;

	v5.erase(v5.begin());
	v5.erase(v5.end()-1);

	auto pos = find(v5.begin(), v5.end(), 5);
	if (pos != v5.end())
		v5.erase(pos);

	v5.clear();
}

void TestVector3()
{
	vector<vector<int>> vv;
	// 10 * 10---> 6
	vv.resize(10); // �����ܵ�����

	// ��ÿ������Ԫ��
	for (size_t i = 0; i < 10; ++i)
	{
		vv[i].resize(10, 6);
	}
}

int main()
{
	//TestVector1();
	//TestVector2();
	TestVector3();
	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
int main()
{
	size_t sz;
	std::vector<int> foo;
	foo.reserve(100);
	foo[0] = 10;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i) 
	{
		foo.push_back(i);//SeqList ���ݷ�ʽ�������¿ռ�  ����Ԫ�� �ͷžɿռ�
		if (sz != foo.capacity()) 
		{
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	return 0;
}
#endif

#if 0
#include <vector>

int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	//v.reserve(20);
	for (size_t i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	// ��������������ָ���һ�����ͣ����Խ�����������Ķ��󵱳���ָ��ķ�ʽ����Ӧ��
	// ���ã������û�͸����(�û����Բ���֪���������ĵײ����ݽṹ)���������е�Ԫ��
	//v.assign(20, 8);
	//vector<int>::iterator it = v.begin();
	auto it = v.begin();

	v.push_back(1);  // ���ܻᵼ�µ�����itʧЧ

	// �����ʽ����it���������¸�ֵ
	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	return 0;
}
#endif

#if 0
// ��vector������Ԫ�������
#include <vector>

int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	// v.resize(0);

	//v.clear();
	//v.erase(v.begin(), v.end());

	auto it = v.begin();
	while (it != v.end())
	{
		it = v.erase(it);
		//++it;
	}

	cout << v.size() << endl;
	return 0;
}
#endif

#if 0
// ���û᲻��ʧЧ
#include <vector>
int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int& ra = v[0];
	ra = 10;

	v.push_back(1);
	ra = 100;
	return 0;
}
#endif

int main()
{
	return 0;
}