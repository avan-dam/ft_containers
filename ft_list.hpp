/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 13:06:53 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/04/16 14:47:23 by ambervandam   ########   odam.nl         */
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

	public:
		list() : _head(nullptr), _tail(nullptr), _size(0) {}
        list(size_type n, const value_type val);
		list(size_type n);
        list(iterator first, iterator last);
		list(const list &x);
		list & operator=(const list &x);
		~list();

        void clear();

		bool    		empty() const { return (_head == nullptr && _tail == nullptr && _size == 0); }
		size_type		size() const { return (_size); }
		// size_type max_size() const;

		iterator begin() const { return ft::iterator<T>(_head);	}
		iterator end() const { return ft::iterator<T>(_tail); }
	private:
		node		*_head;
		node		*_tail;
		size_type	_size;
};

template <typename T>
list<T>::list(iterator first, iterator last)
{
    node * current;

	_size = 0;
    current = new node(first._list->data);
    _head = current;
	_size++;
	for (iterator it = first; it != last; ++it)
    {
        current = new node(it._list->data);
		_size++;
        current->prev = it._list->prev;
		current->nxt = it._list->nxt;
        current = current->nxt;
    }
    _tail = current;
    _head->prev = nullptr;
	_tail->nxt = nullptr;
}

template <typename T>
list<T>::list(size_type n, const value_type val)
{
    node * temp_ptr;
	node * new_ptr;

    _size = 0;
	_head = nullptr;
	_tail = nullptr;
    if (n == 0)
	    return ;
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
    _tail->nxt = nullptr;
}

template <typename T>
list<T>::list(size_type n)
{
	list(n, 0);
	return ;
}

template <typename T>
list<T>::list(const list & source)
{
    clear();
	_head = source._head;
	_tail = source._tail;
	_size = source._size;
    list(this->begin(), this->end());
    return ;
}

template<typename T>
list<T> & list<T>::operator=(const list & source)
{
    if (_head != source._head || _tail != source._tail || _size != source._size)
	{
        clear();
        _head = source.head;
        _tail = source.tail;
        _size = source.size;
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
            delete (temp_ptr);
        }
    }
    return ;
}

template <typename T>
list<T>::~list()
{
    clear();
    return ;
}

}

#endif
