/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 13:06:53 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/04/21 09:18:27 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_HPP
# define FT_LIST_HPP

#include "list_node.hpp"
#include "list_iterator.hpp"
#include <iostream>

typedef unsigned int size_type; 

namespace ft {
template <typename T>
class list
    {
	public:
		typedef	T				value_type; 
        typedef	list_node<T>	node;
		typedef	iterator<T>		iterator;
		typedef	iterator		reverse_iterator;

	public:
		list();
        list(size_type n, const value_type val);
		list(size_type n);
        list(iterator first, iterator last);
		list(const list &x);
		list & operator=(const list &x);
		~list() {clear(); return ;}

        void clear();

		bool    		empty() const { return (_head == nullptr && _tail == nullptr && _size == 0); }
		size_type		size() const { return (_size); }
		// size_type max_size() const;

		iterator begin() {
			 return ft::iterator<T>(_head); 
			 }
		iterator end() { 
			if (_size == 0)
				return ft::iterator<T>(_head); 
			else
				return ft::iterator<T>(_tail->nxt); 
		}

		node & front() { return (&_head);	}
		// const_reference front() const;
		node & back() { return (&_tail);	}
		// const_reference back() const;

		void assign (size_type n, const value_type& val);
		void assign (iterator first, iterator last);
	private:
		node		*_head;
		node		*_tail;
		size_type	_size;
};

template <typename T>
list<T>::list(iterator first, iterator last)
{
	// _size = 0;
	// for (ft::list<int>::iterator it = first; it != last; ++it)
	// 	_size++;
	assign(first, last);
	_size = 0;
	for (ft::list<int>::iterator it = first; it != last; ++it)
		_size++;
	return ;
    // node * temp_ptr;
	// node * new_ptr;
	// size_type	size = 0;

	// _size = 0;
    // _head = new node(first._list->data);
    // temp_ptr = _head;
	// size++;
	// for (iterator it = first; it != last; ++it)
    // {
    //     new_ptr = new node(it._list->data);
	// 	size++;
    //     new_ptr->prev = temp_ptr;
    //     temp_ptr->nxt = new_ptr;
    //     temp_ptr = new_ptr;
    // }
    // _tail = temp_ptr;
    // _head->prev = nullptr;
	// _tail->nxt = nullptr;
}

template <typename T>
list<T>::list(size_type n, const value_type val)
{
	assign(n, val);
	_size = n;
	return ;
}

template <typename T>
list<T>::list()
{
	_head = new node();
	_tail = new node();
	_head->nxt = _tail;
	_tail->prev = _head;
	_size = 0;
}

template <typename T>
void list<T>::assign (size_type n, const value_type& val)
{
	node * temp_ptr;
	node * new_ptr;

    _size = 0;
	_head = nullptr;
	_tail = nullptr;
    if (n == 0)
	    return ;
	_head = new node(val);
	std::cout << "head assigned" << std::endl;
    _size++;
    if (n == 1)
    {
        _tail = _head;
        return ;
    }
    temp_ptr = _head;
    for (size_type i = 1; i < n; i++)
    {
	    new_ptr = new node(val);
		std::cout << "middles assigned" << std::endl;
        _size++;
        new_ptr->prev = temp_ptr;
        temp_ptr->nxt = new_ptr;
        temp_ptr = new_ptr;
    }
    _tail = temp_ptr;
    _head->prev = nullptr;
    _tail->nxt = nullptr;
	// list(n, val);
	return ;
}

template <typename T>
void list<T>::assign (iterator first, iterator last)
{
	// list(first, last);
    node * temp_ptr;
	node * new_ptr;
	size_type	size = 0;

	_size = 0;
    _head = new node(first._list->data);
    temp_ptr = _head;
	size++;
	iterator it = first;
	it++;
	while (it != last)
    {
        new_ptr = new node(it._list->data);
		size++;
        new_ptr->prev = temp_ptr;
        temp_ptr->nxt = new_ptr;
        temp_ptr = new_ptr;
		it++;
    }
    _tail = temp_ptr;
    _head->prev = nullptr;
	_tail->nxt = nullptr;
	return ;
}

template <typename T>
list<T>::list(size_type n)
{
    node * temp_ptr;
	node * new_ptr;

    _size = 0;
	_head = nullptr;
	_tail = nullptr;
    if (n == 0)
	    return ;
	_head = new node(0);
    _size++;
    if (n == 1)
    {
        _tail = _head;
        return ;
    }
    temp_ptr = _head;
    for (size_type i = 1; i < n; i++)
    {
	    new_ptr = new node(0);
        _size++;
        new_ptr->prev = temp_ptr;
        temp_ptr->nxt = new_ptr;
        temp_ptr = new_ptr;
    }
    _tail = temp_ptr;
    _head->prev = nullptr;
    _tail->nxt = nullptr;
}

template <typename T>
list<T>::list(const list & source)
{
    clear();
	_head = source._head;
	_tail = source._tail;
	_tail->prev = source._tail->prev;
	_tail->nxt = nullptr;
	_head->prev = nullptr;
	_size = source._size;
	list(ft::iterator<T>(_head), ft::iterator<T>(_tail->nxt));
	return ;
}

template<typename T>
list<T> & list<T>::operator=(const list & source)
{
    if (_head != source._head || _tail != source._tail || _size != source._size)
	{
        clear();
        _size = source.size();
		_head = source._head;
		_tail = source._tail;
		_tail->nxt = nullptr;
		_head->prev = nullptr;
		list(ft::iterator<T>(_head), ft::iterator<T>(_tail->nxt));
    }
    return *this;
}

template <typename T>
void list<T>::clear()
{
    node * current_ptr = _head;
    node * temp_ptr;

    if (empty() != 0)
    {
        while (current_ptr != nullptr)
        {
            temp_ptr = current_ptr;
            current_ptr = current_ptr->nxt;
			_size--;
            delete (temp_ptr);
        }
    }
    return ;
}

}

#endif
