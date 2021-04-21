/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_iterator.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/09 14:51:34 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/04/20 18:31:57 by ambervandam   ########   odam.nl         */
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
		typedef std::bidirectional_iterator_tag	iterator_category;
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef T&								reference;
		typedef T*								pointer;
		typedef	list_node<T>					node;
		typedef list_node<T>*					lst_node_ptr;

		reference operator*() const { return _list->data; }
    	pointer operator->() { return &_list->data; }
    	iterator& operator++() { _list = _list->get_next(); return *this; }
    	iterator operator++(int) { iterator tmp = *this; _list = _list->get_next(); return tmp; }
		iterator& operator--() { _list = _list->get_prev(); return *this; }
    	iterator operator--(int) {  iterator tmp = *this; _list = _list->get_prev(); return tmp; }
		bool operator!=(const iterator& rhs) { return _list != rhs._list; }
		bool operator==(const iterator& rhs) { return _list == rhs._list; }		
		iterator() : _list(nullptr) {}
		iterator(lst_node_ptr source) : _list(source) {}
		iterator & operator=(const iterator& source)
		{
			if (_list != source._list)
				_list = lst_node_ptr(source);
			return *this;
		}
		iterator(const iterator & source) // check this
		{
			_list = lst_node_ptr(source._list);
		}
		~iterator() {}
		value_type get_content() {return(*_list->data);}
	// private:
		node	*_list;
};
}


# endif
