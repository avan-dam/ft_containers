/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_iterator.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/09 14:51:34 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/06/02 11:14:42 by ambervandam   ########   odam.nl         */
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
				_list = source._list;
			// if (*_list != *(source.get_list()))
			// 	*_list = node(*(source.get_list()));
			return *this;
		}
		iterator(const iterator & source) // check this
		{
			_list = lst_node_ptr(source._list);
		}
		~iterator() {}
		value_type get_content() const {return(_list->data);}
		node * get_list() const {return(_list);}
	// private:
		node	*_list;
};

template <typename T>
class reverse_iterator 
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
    	reverse_iterator& operator++() { _list = _list->get_prev(); return *this; }
    	reverse_iterator operator++(int) { reverse_iterator tmp = *this; _list = _list->get_prev(); return tmp; }
		reverse_iterator& operator--() { _list = _list->get_next(); return *this; }
    	reverse_iterator operator--(int) {  reverse_iterator tmp = *this; _list = _list->get_next(); return tmp; }
		bool operator!=(const reverse_iterator& rhs) { return _list != rhs._list; }
		bool operator==(const reverse_iterator& rhs) { return _list == rhs._list; }		
		reverse_iterator() : _list(nullptr) {}
		reverse_iterator(lst_node_ptr source) : _list(source) {}
		reverse_iterator & operator=(const reverse_iterator& source)
		{
			if (_list != source._list)
				_list = source._list;
			// if (*_list != *(source.get_list()))
			// 	*_list = node(*(source.get_list()));
			return *this;
		}
		reverse_iterator(const reverse_iterator & source) // check this
		{
			_list = lst_node_ptr(source._list);
		}
		~reverse_iterator() {}
		value_type get_content() const {return(_list->data);}
		node * get_list() const {return(_list);}
	// private:
		node	*_list;
};
}


# endif
