/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   random_access_iterator.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 12:49:25 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/07/05 10:23:11 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "ft_vector.hpp"
#include <iostream>

namespace ft {
template <typename T>
class random_access_iterator
{
	public:
		typedef std::random_access_iterator_tag	iterator_category;
		typedef std::ptrdiff_t					difference_type;
		typedef T								value_type;
		typedef T&								reference;
		typedef T*								pointer;

		random_access_iterator() : _vct(nullptr) {}
		random_access_iterator(const random_access_iterator& source){ _vct = source._vct; }
		random_access_iterator & operator=(const random_access_iterator& source)
		{
			if (_vct != source._vct)
				_vct = source._vct;
			return *this;
		}
		~random_access_iterator() {}

		bool operator!=(const random_access_iterator& rhs) { return !(*this == rhs); }
		bool operator==(const random_access_iterator& rhs) { return _vct == rhs._vct; }		

		reference operator*() const { return (*_vct); }
    	pointer operator->() { return (&_vct); }

    	random_access_iterator& operator++() { _vct++; return *this; }
    	random_access_iterator operator++(int) { random_access_iterator tmp = *this; _vct++; return tmp; }
		random_access_iterator& operator--() { _vct--; return *this; }
    	random_access_iterator operator--(int) {  random_access_iterator tmp = *this; _vct--; return tmp; }
		
		random_access_iterator(value_type* source) : _vct(source) {}

        difference_type operator+(const random_access_iterator<T> &rhs) { return (_vct + rhs._vct); };
        random_access_iterator operator+(const difference_type &off) { return random_access_iterator<T>(_vct + off); };
        difference_type operator-(const random_access_iterator<T> &rhs) { return (_vct - rhs._vct); };
        random_access_iterator operator-(const difference_type &off) { return random_access_iterator<T>(_vct - off); };
        random_access_iterator &operator+=(const difference_type &off) {
            _vct += off;
            return (*this);
		};
		random_access_iterator &operator-=(const difference_type &off) {
           _vct -= off;
            return (*this);}
	private:
        T*		_vct;
};


template <typename T>
class reverse_random_access_iterator
{
	public:
		typedef std::random_access_iterator_tag	iterator_category;
		typedef std::ptrdiff_t					difference_type;
		typedef T								value_type;
		typedef T&								reference;
		typedef T*								pointer;
		typedef size_t 							size_type; 

		reverse_random_access_iterator() : _vct(nullptr) {}
		reverse_random_access_iterator(const reverse_random_access_iterator& source){ _vct = source._vct; }
		reverse_random_access_iterator & operator=(const reverse_random_access_iterator& source)
		{
			if (_vct != source._vct)
				_vct = source._vct;
			return *this;
		}
		~reverse_random_access_iterator() {}

		bool operator!=(const reverse_random_access_iterator& rhs) { return !(*this == rhs); }
		bool operator==(const reverse_random_access_iterator& rhs) { return _vct == rhs._vct; }		

		reference operator*() const { return (*_vct); }
    	pointer operator->() { return (&_vct); }

    	reverse_random_access_iterator& operator++() { _vct--; return *this; }
    	reverse_random_access_iterator operator++(int) { reverse_random_access_iterator tmp = *this; _vct--; return tmp; }
		reverse_random_access_iterator& operator--() { _vct++; return *this; }
    	reverse_random_access_iterator operator--(int) {  reverse_random_access_iterator tmp = *this; _vct++; return tmp; }
		
		reverse_random_access_iterator(value_type* source) : _vct(source) {}

        difference_type operator+(const reverse_random_access_iterator<T> &rhs) { return (_vct - rhs._vct); };
        reverse_random_access_iterator operator+(const difference_type &off) { return reverse_random_access_iterator<T>(_vct - off); };
        difference_type operator-(const reverse_random_access_iterator<T> &rhs) { return (_vct + rhs._vct); };
        reverse_random_access_iterator operator-(const difference_type &off) { return reverse_random_access_iterator<T>(_vct + off); };
        reverse_random_access_iterator &operator+=(const difference_type &off) {
            _vct -= off;
            return (*this);
		};
		reverse_random_access_iterator &operator-=(const reverse_random_access_iterator &off) {
           _vct += off;
            return (*this);}
	private:
        T*		_vct;
};
}
#endif
