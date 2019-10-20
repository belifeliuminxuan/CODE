#include <iostream>
using namespace std;

// list: ��ͷ���˫��ѭ������

// 1. ��
// 2. �˽�ײ�ṹ
// 3. ģ��ʵ��

#if 0
#include <list>
#include <vector>

void TestList1()
{
	list<int> L1;
	list<int> L2(10, 5);

	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> L3(v.begin(), v.end());
	list<int> L4(L3);

	cout << L1.size() << endl;

	// ���õ�������ʽ
	//list<int>::iterator it = L2.begin();
	auto it = L2.begin();
	while (it != L2.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : L3)
		cout << e << " ";
	cout << endl;

	cout << L3.front() << endl;
	cout << L3.back() << endl;

	auto rit = L4.rbegin();
	while (rit != L4.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}


void TestList2()
{
	list<int> L;
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	L.push_back(4);

	cout << L.size() << endl;

	L.push_front(0);
	cout << L.front() << endl;

	L.pop_front();
	cout << L.front() << endl;

	L.pop_back();
	cout << L.back() << endl;

	// 1   2    3
	auto it = find(L.begin(), L.end(), 2);
	if(it != L.end())
		L.insert(it, 5);

	L.erase(it);
}

// even odd
bool IsOdd(int data)
{
	if (0 == data % 2)
		return true;

	return false;
}

void TestList3()
{
	list<int> L{9,1,2,2,3,4,2};
	for (auto e : L)
		cout << e << " ";
	cout << endl;

	// ɾ������2
	//L.remove(2);

	// ɾ��L�����е�ż��
	// remove_if��ɾ���������������Ľڵ�
	// ���������Ǹú����Ĳ���
	// �ú�����ʵ��ԭ����ÿ���ڵ��е�ֵ���ò�������������֤�����������ɾ�������������ʲô������
	L.remove_if(IsOdd);
}

// ע�⣺ʹ��uniqueʱ���뱣֤�����������
void TestList4()
{
	list<int> L{ 9, 1, 2, 2, 3, 4, 2 };
	L.sort();
	L.unique();
}

// list�еĵ�����ʧЧ---������ָ��Ľڵ㲻����
void TestListIterator()
{
	list<int> L{ 1, 2, 3, 4 };
	auto it = L.begin();

	// erase֮��it��ָ��Ľڵ��Ѿ���ɾ������
	// it������ʧЧ
	L.erase(it);

	// �������: �����������¸�ֵ
	it = L.begin();
	while (it != L.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

int main()
{
	// TestList1();
	// TestList2();

	// TestList3();
	// TestList4();
	TestListIterator();
	return 0;
}
#endif

namespace bite
{
	// list: ��ͷ���˫��ѭ������
	template<class T>
	struct ListNode
	{
		ListNode(const T& data = T())
		: _pNext(nullptr)
		, _pPre(nullptr)
		, _data(data)
		{}

		ListNode<T>* _pNext;
		ListNode<T>* _pPre;
		T _data;
	};

	// list�����������ڵ����͵�ָ�����·�װ
	template<class T>
	struct list_iterator
	{
		typedef ListNode<T> Node;
		typedef list_iterator<T> Self;
	public:
		list_iterator(Node* pCur)
			: _pCur(pCur)
		{}

		// ����ָ��ķ�ʽ����Ӧ��
		T& operator*()
		{
			return _pCur->_data;
		}

		T* operator->()
		{
			return &(_pCur->_data);
		}

		// 3. �ƶ�
		Self& operator++()
		{
			_pCur = _pCur->_pNext;
			return *this;
		}

		Self operator++(int)
		{
			Self temp(*this);
			_pCur = _pCur->_pNext;
			return temp;
		}

		Self& operator--()
		{
			_pCur = _pCur->_pPre;
			return *this;
		}

		Self operator--(int)
		{
			Self temp(*this);
			_pCur = _pCur->_pPre;
			return temp;
		}

		// 4. �Ƚ�
		bool operator!=(const Self& s)
		{
			return _pCur != s._pCur;
		}

		bool operator==(const Self& s)
		{
			return _pCur == s._pCur;
		}

		Node* _pCur;
	};

	template<class Iterator, class T>
	struct list_reverse_iterator
	{
		typedef list_reverse_iterator<Iterator, T> Self;
	public:
		list_reverse_iterator(Iterator it)
			: _it(it)
		{}

		T& operator*()
		{
			Iterator temp = _it;
			--temp;
			return *temp;
		}

		T* operator->()
		{
			return &(operator*());
		}

		Self& operator++()
		{
			--_it;
			return *this;
		}

		Self operator++(int)
		{
			Self temp(*this);
			_it--;
			return temp;
		}

		Self& operator--()
		{
			++_it;
			return *this;
		}

		Self operator--(int)
		{
			Self temp(*this);
			_it++;
			return temp;
		}

		bool operator!=(const Self& s)
		{
			return _it != s._it;
		}

		bool operator==(const Self& s)
		{
			return _it == s._it;
		}

		Iterator _it;
	};

	template<class T>
	class list
	{
		typedef ListNode<T> Node;
	public:
		typedef list_iterator<T> iterator;
		typedef list_reverse_iterator<iterator, T> reverse_iterator;
	public:
		list()
		{
			CreateHead();
		}

		list(int n, const T& data)
		{
			CreateHead();
			for (size_t i = 0; i < n; ++i)
				push_back(data);
		}
		
		template<class Iterator>
		list(Iterator first, Iterator last)
		{
			CreateHead();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		list(const list<T>& L)
		{
			CreateHead();
			Node* pCur = L._pHead->_pNext;
			while (pCur != L._pHead)
			{
				push_back(pCur->_data);
				pCur = pCur->_pNext;
			}
		}

		// L1 = L2;
		list<T>& operator=(const list<T>& L)
		{
			if (this != &L)
			{
				clear();
				Node* pCur = L._pHead->_pNext;
				while (pCur != _pHead)
				{
					push_back(pCur->_data);
					pCur = pCur->_pNext;
				}
			}
			return *this;
		}

		~list()
		{
			clear();
			delete _pHead;
		}

	public:
		iterator begin()
		{
			return iterator(_pHead->_pNext);
		}

		iterator end()
		{
			return iterator(_pHead);
		}

		reverse_iterator rbegin()
		{
			return end();
		}

		reverse_iterator rend()
		{
			return begin();
		}
		/////////////////////////////
		// ����
		size_t size()const
		{
			size_t count = 0;
			Node* pCur = _pHead->_pNext;
			while (pCur != _pHead)
			{
				++count;
				pCur = pCur->_pNext;
			}

			return count;
		}

		size_t empty()const
		{
			return _pHead->_pNext == _pHead;
		}

		void resize(size_t newsize, const T& data = T())
		{
			size_t oldsize = size();
			if (newsize > oldsize)
			{
				// �ڵ�����
				for (size_t i = oldsize; i < newsize; ++i)
					push_back(data);
			}
			else
			{
				// �ڵ����
				// oldsize:10   newsize:5
				for (size_t i = newsize; i < oldsize; ++i)
					pop_back();
			}
		}

		///////////////////////////////
		// Ԫ�ط���
		T& front()
		{
			return _pHead->_pNext->_data;
		}

		const T& front()const
		{
			return _pHead->_pNext->_data;
		}

		T& back()
		{
			return _pHead->_pPre->_data;
		}

		const T& back()const
		{
			return _pHead->_pPre->_data;
		}

		///////////////////////////////////
		// modify
		void push_back(const T& data)
		{
			insert(end(), data);
		}

		void pop_back()
		{
			erase(--end());
		}

		void push_front(const T& data)
		{
			insert(begin(), data);
		}

		void pop_front()
		{
			erase(begin());
		}

		iterator insert(iterator pos, const T& data)
		{
			Node* pNewNode = new Node(data);
			Node* pCur = pos._pCur;

			pNewNode->_pPre = pCur->_pPre;
			pNewNode->_pNext = pCur;
			pNewNode->_pPre->_pNext = pNewNode;
			pCur->_pPre = pNewNode;

			return iterator(pNewNode);
		}

		iterator erase(iterator pos)
		{
			Node* pDelNode = pos._pCur;
			if (pDelNode == _pHead)
				return end();

			Node* pRet = pDelNode->_pNext;
			pDelNode->_pPre->_pNext = pDelNode->_pNext;
			pDelNode->_pNext->_pPre = pDelNode->_pPre;
			delete pDelNode;

			return iterator(pRet);
		}

		void clear()
		{
			Node* pCur = _pHead->_pNext;
			// ͷɾ��
			// []-->1-->2-->3...
			while (pCur != _pHead)
			{
				_pHead->_pNext = pCur->_pNext;
				delete pCur;
				pCur = _pHead->_pNext;
			}

			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;
		}

		void swap(list<T>& L)
		{
			swap(_pHead, L._pHead);
		}
	private:
		void CreateHead()
		{
			_pHead = new Node;
			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;
		}
	protected:
		Node* _pHead;
	};
}

#include <vector>
void TestList1()
{
	bite::list<int> L1;
	bite::list<int> L2(10, 5);

	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	bite::list<int> L3(v.begin(), v.end());
	bite::list<int> L4(L3);

	auto it = L2.begin();
	while (it != L2.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : L3)
		cout << e << " ";
	cout << endl;

	auto rit = L4.rbegin();
	while (rit != L4.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}

void TestList2()
{
	bite::list<int> L;
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	L.push_back(4);

	cout << L.size() << endl;
	cout << L.front() << endl;
	cout << L.back() << endl;

	L.push_front(0);
	cout << L.size() << endl;
	cout << L.front() << endl;
	cout << L.back() << endl;

	L.pop_front();
	cout << L.size() << endl;
	cout << L.front() << endl;
	cout << L.back() << endl;

	L.pop_back();
	cout << L.size() << endl;
	cout << L.front() << endl;
	cout << L.back() << endl;

	L.clear();
	if (L.empty())
		cout << "clear is OK" << endl;
}

void TestList3()
{
	bite::list<int> L;
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);

	L.resize(10, 5);
	for (auto e : L)
		cout << e << " ";
	cout << endl;

	L.resize(2);
	for (auto e : L)
		cout << e << " ";
	cout << endl;
}

int main()
{
	 TestList1();
	// TestList2();
	//TestList3();
	return 0;
}