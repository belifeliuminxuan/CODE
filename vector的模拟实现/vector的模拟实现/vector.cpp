#include <iostream>
#include <assert.h>
using namespace std;
namespace bit
{
	template <class T>
	class vector
	{
	public:
		typedef T* iterator;
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 0c4fe3d419f2d571b1d2531289289980f01e1791
		typedef const T* const_iterator;
		iterator begin(){ return _start };
		iterator end(){ return _finish };
		const_iterator cbegin(){ return _start };
		const_iterator cend(){ return _finish };
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, endofstorage(nullptr)
		{}
		vector(int n, const T& value = T())
		{
			:_start(nullptr)
				, _finish(nullptr)
				, _endofstorage(nullptr)
			{
				reserve(n);
				while (n--)
				{
					push_back(value);
				}
			}
		}
		template<class inputiterator>
		vector(inputiterator first, inputiterator last)
		{
			reserve(last - first);
			while (fist != last)
			{
				push_back(*first);
				++first;

			}
		}
		vector(const vector <T> &v)
			:_start(nullptr)
			, _finish(nullptr)
			, endofstorage(nullptr)
		{
			reverse(v.capacity());
			iterator it = begin();
			const_iterator vit = v.cbegin();
			while (vit != v.cend())
			{
				*it++ = *vit++;
			}
			_finish = _start + v.size();
			_endofstorage = _start + v.capacity();
		}
<<<<<<< HEAD
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}
		~vector()
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;

		}
		size_t size()const
		{
			return _finish - _start;
		}
		size_t capcity()const
		{
			return _endofstorage - _start;
		}
		void reserve(size_t n)
		{
			if (n > capcity())
			{
				size_t oldsize = size();
				T* tmp = new T[n];
				/*if (_start)
				{
				memcpy(tmp, _start, sizeof(T)*size)
				}*/
				if (_start)
				{
					for (size_t i = 0; i < oldsize; i++)
					{
						tmp[i] = _start[i];
					}
				}
				_start = tmp;
				_finish = _start + size;
				_endofstorage = _start + n;
			}
		}
		void resize(size_t n, const T& value = T())
		{
			if (n <= size())
			{
				_finish = _start + n;
				return;
			}
			if (n > capcity())
			{
				reserve(n);
			}
			iterator it = _finish;
			iterator _finish = _start + n;
			while (it != _finish)
			{
				*it = value;
				++it;
			}
		}
		T& operator [](size_t pos)
		{
			return _start[pos];
		}
		const T* operator[](size_t pos)const
		{
			return _start[pos];
		}
		void push_back(const T& x)
		{
			insert(end(), x);
		}
		void pop_back()
		{
			erase(--end());
		}
		void swap(vector<T>& v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endofstorage = v.endofstorage());
		}
		iterator insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);
			if (_finish == _endofstorage)
			{
				size_t size = size();
				size_t newcapacity = (0 == capcity()) ? 1 : capcity() * 2;
				reserve(newcapacity);
				pos = _start + size;

			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
			return pos;
		}
		iterator erase(Iterator pos)
		{
			iterator begin = pos + 1;
			while (begin != _finish)
			{
				*(begin - 1) = *begin;
				++begin;

			}
			--_finish;
			return pos;
		}
		private:
			iterator _start;
			iterator _finish;
			iterator _endofstorage;
=======
=======

>>>>>>> c61bdb49122186b5abc55c1041439dd69accc6bf
>>>>>>> 0c4fe3d419f2d571b1d2531289289980f01e1791
	};
}