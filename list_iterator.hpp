/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_iterator.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/09 14:51:34 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/04/13 15:48:29 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Bidirectional iterator

#ifndef LIST_ITERATOR_HPP
# define LIST_ITERATOR_HPP

#include "list_node.hpp"
#include <iostream>

namespace ft {
template <typename T>
class iterator 
{
	public:
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;
		typedef list_node<T>*	lst_node_ptr;

		reference operator*() const { return _list->data; }
    	pointer operator->() { return _list->data; }
    	iterator& operator++() { _list = _list->get_next(); return *this; }   // Prefix increment
    	iterator operator++(int) { iterator tmp = *this; _list = _list->get_next(); return tmp; } 	// Postfix increment
		iterator& operator--() { _list = _list->prev; return *this; }   // Prefix increment
    	iterator operator--(int) { iterator tmp = *this; (*this = this->prev); return tmp; } 	// Postfix increment
		bool operator!=(const iterator& rhs) { return _list != rhs._list; }
		bool operator==(const iterator& rhs) { return _list == rhs._list; }		
		iterator(lst_node_ptr source)
		{
			_list = lst_node_ptr(source);
		}
		iterator & operator=(const iterator& source)
		{
			std::cout << "in iterator asignment operator here" << std::endl;
			if (_list != source._list)
				_list = lst_node_ptr(source);
			return *this;
		}
		iterator(const iterator & source)
		{
			_list = lst_node_ptr(source._list);
		}
		value_type get_content()
		{
			return(*_list->data);
		}
	private:
		lst_node_ptr	_list;
};
}


# endif
