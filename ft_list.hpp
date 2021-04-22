/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 13:06:53 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/04/22 10:50:48 by ambervandam   ########   odam.nl         */
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
			if (_size == 0)
				return iterator(_tail); 
			return iterator(_head); 
			}
		iterator end() { 
			if (_size == 0)
				return iterator(_tail); 
			else
				return iterator(_tail->nxt); 
		}

		node front() { return (*_head);	}
		// const_reference front() const;
		node back() { return (*_tail);	}
		// const_reference back() const;

		void assign (size_type n, const value_type& val);
		void assign (iterator first, iterator last);

		void push_front (const value_type& val);
		void pop_front();
		void push_back (const value_type& val);
		void pop_back();

		iterator insert (iterator position, const value_type& val);
		void insert (iterator position, size_type n, const value_type& val);
		void insert (iterator position, iterator first, iterator last);
	private:
		node		*_head;
		node		*_tail;
		size_type	_size;
};

template <typename T>
void list<T>::insert (iterator position, size_type n, const value_type& val)
{
	ft::list<int> newlist(n, val);
	iterator	it;
	node * 		afterinsert;
	node * 		beforeinsert;

	it = iterator(_head);
	if (n == 0)
		return ;
  	while (it != position)
		it++;
	afterinsert = it.get_list();
	_size = _size + n;
	if (afterinsert == _head)
	{
		newlist._tail->nxt = _head;
		_head->prev = newlist._tail;
		_head = newlist._head;
		_head->prev = nullptr;
		return ;
	}
	beforeinsert = afterinsert->prev;
	beforeinsert->nxt = newlist._head;
	newlist._head->prev = beforeinsert->nxt;
	newlist._tail->nxt = afterinsert;
	afterinsert->prev = newlist._tail;
	return ;
}

template <typename T>
void list<T>::insert (iterator position, iterator first, iterator last)
{
	ft::list<int> newlist(first, last);
	iterator	it;
	node * 		afterinsert;
	node * 		beforeinsert;
	size_type 	n;

	n = 0;
	while (first != last)
	{	
		n++;
		first++;
	}
	if (n == 0)
		return;
	it = iterator(_head);
	if (n == 0)
		return ;
  	while (it != position)
		it++;
	afterinsert = it.get_list();
	_size = _size + n;
	if (afterinsert == _head)
	{
		newlist._tail->nxt = _head;
		_head->prev = newlist._tail;
		_head = newlist._head;
		_head->prev = nullptr;
		return ;
	}
	beforeinsert = afterinsert->prev;
	beforeinsert->nxt = newlist._head;
	newlist._head->prev = beforeinsert->nxt;
	newlist._tail->nxt = afterinsert;
	afterinsert->prev = newlist._tail;
	return ;
}
		
template <typename T>
ft::iterator<T> list<T>::insert (iterator position, const value_type& val)
{
	iterator	it;
	node * 		new_ptr;
	node * 		afterinsert;
	node * 		beforeinsert;

	it = iterator(_head);
  	while (it != position)
		it++;
	afterinsert = it.get_list();
	new_ptr = new node(val);
	_size++;
	if (afterinsert == _head)
	{
		new_ptr->nxt = _head;
		_head->prev = new_ptr;
		new_ptr->prev = nullptr;
		_head = new_ptr;
		return (new_ptr);
	}
	beforeinsert = afterinsert->prev;
	beforeinsert->nxt = new_ptr;
	new_ptr->prev = beforeinsert->nxt;
	new_ptr->nxt = afterinsert;
	afterinsert->prev = new_ptr;
	return (new_ptr);
}

template <typename T>
void list<T>::pop_front()
{
	node * temp_ptr;
	if (_size == 0)
	{	
		_head = nullptr;
		_tail = nullptr;
		return ;
	}
	temp_ptr = _head->nxt;
	delete _head;
	_head = temp_ptr;
	_size--;
	if (_size == 0)
		_tail = nullptr;
	return ;
}

template <typename T>
void list<T>::pop_back()
{
	node * temp_ptr;
	if (_size == 0)
	{	
		_head = nullptr;
		_tail = nullptr;
		return ;
	}
	temp_ptr = _tail->prev;
	delete _tail;
	_tail = temp_ptr;
	_size--;
	if (_size == 0)
	{
		_tail = nullptr;
		_head = nullptr;
	}
	return;
}
template <typename T>
void list<T>::push_back (const value_type& val)
{
	node * temp_ptr;
	temp_ptr = new node(val);
	if (_size == 0)
	{
		_tail = temp_ptr;
		_head = _tail;
		_size = 1;
		return ;
	}
	temp_ptr->prev = _tail;
	_tail->nxt = temp_ptr;
	temp_ptr->nxt = nullptr;
	_tail = temp_ptr;
	_size++;
	return ;
}

template <typename T>
void list<T>::push_front (const value_type& val)
{
	node * temp_ptr;
	temp_ptr = new node(val);
	if (_size == 0)
	{
		_tail = temp_ptr;
		_head = _tail;
		_size = 1;
		return ;
	}
	temp_ptr->nxt = _head;
	temp_ptr->prev = nullptr;
	_head = temp_ptr;
	_size++;
	return ;
}

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
	{
		list();
		return ;	
	}
	_head = new node(val);
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
        _size++;
        new_ptr->prev = temp_ptr;
        temp_ptr->nxt = new_ptr;
        temp_ptr = new_ptr;
    }
    _tail = temp_ptr;
    _head->prev = nullptr;
    // _tail->nxt = nullptr;
	_tail->nxt = new node(_size);
	return ;
}

template <typename T>
void list<T>::assign (iterator first, iterator last)
{
    node * temp_ptr;
	node * new_ptr;
	size_type	size = 0;

	_size = 0;
	if (first == last)
	{
		list();
		return ;
	}
	_head = new node(first.get_content());
    temp_ptr = _head;
	size++;
	iterator it = first;
	it++;
	while (it != last)
    {
		new_ptr = new node(it.get_content());
		size++;
        new_ptr->prev = temp_ptr;
        temp_ptr->nxt = new_ptr;
        temp_ptr = new_ptr;
		it++;
    }
    _tail = temp_ptr;
    _head->prev = nullptr;
	// _tail->nxt = nullptr;
	_tail->nxt = new node(_size);
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
