/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_iterator.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 12:49:25 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/06/10 17:32:32 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include "ft_vector.hpp"
#include <iostream>

namespace ft {
template <typename T>
class vector_iterator
{
	public:
		typedef std::bidirectional_iterator_tag	iterator_category;
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef T&								reference;
		typedef T*								pointer;
		typedef unsigned int 					size_type; 
		// typedef vector<T>						ptr;
		// typedef vector<T>*						vct_ptr;


		reference operator*() const { return (*_vct); }
    	pointer operator->() { return (&_vct); }
    	vector_iterator& operator++() { _vct++; return *this; }
    	vector_iterator operator++(int) { vector_iterator tmp = *this; _vct++; return tmp; }
		vector_iterator& operator--() { _vct--; return *this; }
    	vector_iterator operator--(int) {  vector_iterator tmp = *this; _vct; return tmp; }
		
		bool operator!=(const vector_iterator& rhs) { return !(*this == rhs); }
		bool operator==(const vector_iterator& rhs) { return _vct == rhs._vct; }		
		vector_iterator() : _vct(nullptr) {}
		vector_iterator(T* source) : _vct(source) {}

		vector_iterator & operator=(const vector_iterator& source)
		{
			if (_vct != source._vct)
				_vct = source._vct;
			// if (*_list != *(source.get_list()))
			// 	*_list = node(*(source.get_list()));
			return *this;
		}
		// iterator(const iterator & source) // check this
		// {
		// 	_vextor = lst_node_ptr(source._list);
		// }
		~vector_iterator() {}
	// private:
        T*		_vct;
        // size_type   _position;
};
}
#endif
