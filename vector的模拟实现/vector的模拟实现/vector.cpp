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
=======

>>>>>>> c61bdb49122186b5abc55c1041439dd69accc6bf
	};
}