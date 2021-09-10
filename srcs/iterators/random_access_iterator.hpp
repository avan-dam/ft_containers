/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   random_access_iterator.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 12:49:25 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/09/10 11:53:55 by ambervandam   ########   odam.nl         */
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

		random_access_iterator() : _vct(nullptr) {}
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
        iterator operator+(const difference_type &off) { return iterator(_vct + off); };
        difference_type operator-(const iterator &rhs) { return (_vct - rhs._vct); };
        iterator operator-(const difference_type &off) { return iterator(_vct - off); };
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


// template <typename T, typename P, typename R>
// class reverse_random_access_iterator
// {
// 	public:
// 		typedef std::random_access_iterator_tag							iterator_category;
// 		typedef std::ptrdiff_t											difference_type;
// 		typedef T														value_type;
// 		typedef R														reference;
// 		typedef P														pointer;
// 		typedef size_t 													size_type; 
// 		typedef reverse_random_access_iterator<T, const T*, const T&>	const_type;

// 		reverse_random_access_iterator() : _vct(nullptr) {}
// 		explicit reverse_random_access_iterator(pointer vct) : _vct(vct) {}
// 		operator const_type() const { return const_type(this->_vct); }	/* for casting to const */
// 		reverse_random_access_iterator(const reverse_random_access_iterator& source){ _vct = source._vct; }
// 		reverse_random_access_iterator & operator=(const reverse_random_access_iterator& source)
// 		{
// 			if (_vct != source._vct)
// 				_vct = source._vct;
// 			return *this;
// 		}
// 		~reverse_random_access_iterator() {}

// 		bool operator!=(const reverse_random_access_iterator& rhs) { return !(*this == rhs); }
// 		bool operator==(const reverse_random_access_iterator& rhs) { return _vct == rhs._vct; }		

// 		reference operator*() const { return (*_vct); }
//     	pointer operator->() { return (&_vct); }

//     	reverse_random_access_iterator& operator++() { _vct--; return *this; }
//     	reverse_random_access_iterator operator++(int) { reverse_random_access_iterator tmp = *this; _vct--; return tmp; }
// 		reverse_random_access_iterator& operator--() { _vct++; return *this; }
//     	reverse_random_access_iterator operator--(int) {  reverse_random_access_iterator tmp = *this; _vct++; return tmp; }
		
// 		reverse_random_access_iterator(value_type* source) : _vct(source) {}

//         difference_type operator+(const reverse_random_access_iterator<T, P, R> &rhs) { return (_vct - rhs._vct); };
//         reverse_random_access_iterator operator+(const difference_type &off) { return reverse_random_access_iterator<T, P, R>(_vct - off); };
//         difference_type operator-(const reverse_random_access_iterator<T, P, R> &rhs) { return (_vct + rhs._vct); };
//         reverse_random_access_iterator operator-(const difference_type &off) { return reverse_random_access_iterator<T, P, R>(_vct + off); };
//         reverse_random_access_iterator &operator+=(const difference_type &off) {
//             _vct -= off;
//             return (*this);
// 		};
// 		reverse_random_access_iterator &operator-=(const reverse_random_access_iterator &off) {
//            _vct += off;
//             return (*this);}
// 	private:
//         pointer		_vct;
// };



}
#endif
