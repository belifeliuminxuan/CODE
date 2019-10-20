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

#include <assert.h>

namespace bite
{
	template<class T>
	class vector
	{
	public:
		// vector�ĵ�����ʵ�ʾ���ԭ��ָ̬��
		typedef T* iterator;

	public:
		/////////////////////////////////////
		// ����������
		vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}

		vector(int n, const T& data)
			: _start(new T[n])
		{
			for (size_t i = 0; i < n; ++i)
				_start[i] = data;

			_finish = _start + n;
			_endofstorage = _finish;
		}

		// [first, last)
		template<class Iterator>
		vector(Iterator fisrt, Iterator last)
		{
			// ����[first, last)������Ԫ�صĸ���
			size_t n = 0;
			auto it = fisrt;
			while (it != last)
			{
				++it;
				++n;
			}

			_start = new T[n];

			// ��[first, last)�����е�Ԫ�ط��õ�_start�Ŀռ���
			for (size_t i = 0; i < n; ++i)
				_start[i] = *fisrt++;

			_finish = _start + n;
			_endofstorage = _start + n;
		}

		vector(const vector<T>& v);
		vector<T>& operator=(const vector<T>& v);

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstorage = nullptr;
			}
		}

		/////////////////////////////////////
		// ������
		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		/////////////////////////////////////
		// ��������
		size_t size()const
		{
			return _finish - _start;
		}

		size_t capacity()const
		{
			return _endofstorage - _start;
		}

		bool empty()const
		{
			return _start == _finish;
		}

		// T():
		// ���T�����������ͣ�T()--->0
		// ���T�����Զ������ͣ�T()---> ���ø�����޲ι��캯��
		void resize(size_t newsize, const T& data = T())
		{
			size_t oldsize = size();
			if (newsize > oldsize)
			{
				size_t cap = capacity();
				if (newsize > cap)
					reserve(newsize);

				for (; oldsize < newsize; ++oldsize)
					_start[oldsize] = data;//*_finish++ = data;
				
			}

			_finish = _start + newsize;
		}


		void reserve(size_t newCapacity)
		{
			size_t oldCapcity = capacity();
			if (newCapacity > oldCapcity)
			{
				// 1. �����¿ռ�
				T* temp = new T[newCapacity];

				// 2. ����Ԫ��
				//memcpy(temp, _start, size()*sizeof(T));
				// ���_startָ��Ŀռ����
				size_t n = size();
				if (_start)
				{
					for (size_t i = 0; i < n; ++i)
					{
						temp[i] = _start[i];
					}

					// 3. �ͷžɿռ�
					delete[] _start;
				}
				
				_start = temp;
				_finish = _start + n;
				_endofstorage = _start + newCapacity;
			}
		}

		///////////////////////////////////////////////
		// access
		// v[0] = 10; v�������ͨ���͵�
		T& operator[](size_t index)
		{
			assert(index < size());
			return _start[index];
		}

		const T& operator[](size_t index)const
		{
			assert(index < size());
			return _start[index];
		}

		T& front()
		{
			return *_start;
		}

		const T& front()const
		{
			return *_start;
		}

		T& back()
		{
			return *(_finish-1);
		}

		const T& back()const
		{
			return *(_finish-1);
		}

		////////////////////////////////
		// �޸�
		// ʱ�临�Ӷȣ�O(1)
		void push_back(const T& data)
		{
			// ����Ƿ���Ҫ����
			if (_finish == _endofstorage)
			{
				reserve(capacity() * 2 + 3);
			}

			*_finish++ = data;
		}

		void pop_back()
		{
			--_finish;
		}

		// ����ֵ���壺�����²���Ԫ�ص�λ��
		iterator insert(iterator pos, const T& data)
		{
			// ����Ƿ���Ҫ����
			if (_finish == _endofstorage)
				reserve(capacity() * 2);

			// ��[pos, finish)֮������Ԫ������������һ��λ��
			auto it = _finish;
			while (it > pos)
			{
				*it = *(it - 1);
				it--;
			}

			// ������Ԫ��
			*pos = data;
			++_finish;
			return pos;
		}

		iterator erase(iterator pos)
		{
			if (pos == end())
				return pos;

			// it���������Ԫ�ص�λ��
			auto it = pos + 1;
			while (it != _finish)
			{
				*(it-1) = *it;
				++it;
			}

			--_finish;
			return pos;
		}

		void clear()
		{
			_finish = _start;
		}
	private:
		T* _start;
		T* _finish;
		T* _endofstorage;
	};
}


void TestVector()
{
	bite::vector<int> v1;
	bite::vector<int> v2(10, 5);

	int array[] = { 1, 2, 3, 4, 5 };
	bite::vector<int> v3(array, array+sizeof(array)/sizeof(array[0]));

	cout << v2.size() << endl;
	cout << v2.capacity() << endl;
	cout << v3.front() << endl;
	cout << v3.back() << endl;

	for (size_t i = 0; i < v3.size(); ++i)
		cout << v3[i] << " ";
	cout << endl;

	//bite::vector<int>::iterator it = v3.begin();
	auto it = v3.begin();
	while (it != v3.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto& e : v3)
		e *= 2;

	for (auto e : v3)
		cout << e << " ";
	cout << endl;
}


void TestVector2()
{
	bite::vector<int> v;
	v.push_back(1);  // 3
	v.push_back(2);
	v.push_back(3);
	v.push_back(4); // 9
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	cout << v.back() << endl;

	v.pop_back();
	cout << v.back() << endl;
	cout << v.size() << endl;

	cout << v.front() << endl;
	v.insert(v.begin(), 0);
	cout << v.front() << endl;
	cout << v.size() << endl;
}

#include <vector>

void TestVector3()
{
	vector<int> vv;
	bite::vector<int> v(10, 5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(8);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(20, 5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}

int main()
{
	//TestVector();
	//TestVector2();
	TestVector3();
	return 0;
}