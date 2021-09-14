/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   random_access_iterator.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 12:49:25 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/09/13 21:51:59 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "../utils/type_traits.hpp"

namespace ft {
template <typename T, typename P, typename R>
class random_access_iterator
{
	public:
		typedef std::random_access_iterator_tag					iterator_category;
		typedef std::ptrdiff_t									difference_type;
		typedef T												value_type;
		typedef R												reference;
		typedef P												pointer;
		typedef random_access_iterator<T, P, R>					iterator;
		typedef random_access_iterator<T, const T*, const T&>	const_type;

		random_access_iterator() : _vct(NULL) {}
		explicit random_access_iterator(pointer source) : _vct(source) {}
		random_access_iterator(const random_access_iterator& source){ _vct = source._vct; }
		random_access_iterator & operator=(const random_access_iterator& source)
		{
			if (_vct != source._vct)
				_vct = source._vct;
			return *this;
		}
		~random_access_iterator() {}
		operator const_type() const { return const_type(_vct); }	/* for casting to const */

		bool operator!=(const iterator& rhs) { return !(*this == rhs); }
		bool operator==(const iterator& rhs) { return _vct == rhs._vct; }		

		reference operator*() const { return (*_vct); }
    	pointer operator->() const { return (&_vct); }

    	iterator& operator++() { _vct++; return *this; }
    	iterator operator++(int) { iterator tmp = *this; _vct++; return tmp; }
		iterator& operator--() { _vct--; return *this; }
    	iterator operator--(int) {  iterator tmp = *this; _vct--; return tmp; }
	
        difference_type operator+(const iterator &rhs) { return (_vct + rhs._vct); };
        iterator operator+(const difference_type &off) const { return iterator(_vct + off); };
		/* needed to be friend for 2 + begin() etc */
		friend iterator operator+ (difference_type n, iterator itr) { return iterator(itr._vct + n); }
        difference_type operator-(const iterator &rhs) { return (_vct - rhs._vct); };
        iterator operator-(const difference_type &off) const  { return iterator(_vct - off); };
		friend iterator operator- (difference_type n, iterator itr) { return iterator(itr._vct - n); }
        iterator &operator+=(const difference_type &off) {
            _vct += off;
            return (*this);
		};
		iterator &operator-=(const difference_type &off) {
           _vct -= off;
            return (*this);}
		
	protected:
   		pointer		_vct;
};
}
#endif
