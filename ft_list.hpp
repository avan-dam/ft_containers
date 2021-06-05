/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 13:06:53 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/06/05 10:32:23 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_HPP
# define FT_LIST_HPP

#include "list_node.hpp"
#include "list_iterator.hpp"
// #include "enable_if.hpp"
#include <iostream>
#include <algorithm>
#include <cstddef>
#include <memory>
#include <limits>

typedef unsigned int size_type; 

namespace ft {
template <typename T>
class list
    {
	public:
		typedef	T						value_type; 
        typedef	list_node<T>			node;
		typedef	iterator<T>				iterator;
		typedef	reverse_iterator<T>		reverse_iterator;

	public:
		list();
        list(size_type n, const value_type val);
		list(size_type n);
        list(iterator first, iterator last);
		list(const list &x);
		list & operator=(const list &x);
		~list() {clear(); return ;}

        void clear();

		bool    		empty() const { return (_size == 0); }
		size_type		size() const { return (_size); }
		// size_type max_size() const;

		iterator begin() {
			if (_size == 0)
				return iterator(_tail); 
			return iterator(_head); 
			}
		iterator end() { 
			if (_size == 0 || !(_tail->nxt))
				return iterator(_tail); 
			else
				return iterator(_tail->nxt); 
		}

		reverse_iterator rbegin() {
			if (_size == 0)
				return iterator(_tail); 
			return iterator(_tail->nxt); 
			}
		reverse_iterator rend() { 
			if (_size == 0)
				return iterator(_tail); 
			else
				return iterator(_head); 
		}

		node		front() { return (*_head);	}
		// const_reference front() const;
		node		back() { return (*_tail);	}
		// const_reference back() const;

		void		assign (size_type n, const value_type& val);
		void		assign (iterator first, iterator last);

		void		push_front (const value_type& val);
		void		pop_front();
		void		push_back (const value_type& val);
		void		pop_back();

		iterator	insert (iterator position, const value_type& val);
		void		insert (iterator position, size_type n, const value_type& val);
		void		insert (iterator position, iterator first, iterator last);
	
		iterator	erase (iterator position);
		iterator	erase (iterator first, iterator last);

		void		swap (list& x);

		void resize (size_type n, value_type val);

		void splice (iterator position, list& x);
		void splice (iterator position, list& x, iterator i);
		void splice (iterator position, list& x, iterator first, iterator last);

		void remove (const value_type& val);
		template <class Predicate>
  		void remove_if (Predicate pred)
  		{
			iterator	it;

			it = begin();
			while (it != end())
			{
				if (pred(*it) == true)
				{
					erase(it);
					it = begin();
				}
				else
					it++;
			}	
  		}
		void unique();
		template <class BinaryPredicate>
  		void unique (BinaryPredicate binary_pred)
		{
		  	iterator	it;
			iterator	nxt;

			it = begin();
			nxt = begin();
			nxt++;
			while (it != end() && nxt!= end())
			{
				if (binary_pred(*nxt, *it) == true)
				{
					nxt = erase(nxt);
					it = nxt;
					it--;
				}
				else
				{
					it++;
					nxt++;
				}
			}	
		}
		void merge (list& x);

		template <class Compare>
		  void merge (list& x, Compare comp)
		{
			iterator	it_insert;
			iterator	it_this;

			it_insert = x.begin();
			it_this = begin();
			while (it_insert != x.end())
			{
				while (it_this != end())
				{
					std::cout << "trying to insert " << *it_insert << std::endl;
					if (comp(*it_insert, *it_this) ==true)
					{
						insert(it_this, it_insert.get_content());
						break;
					}
					it_this++;
				}
				if (it_this == end())
					push_back(it_insert.get_content());
				it_insert++;
			}
			x.clear();
		}
		
	private:
		node		*_head;
		node		*_tail;
		size_type	_size;
		iterator	insert_newlist(ft::list<T> newlist, size_type n, iterator position);
		void		create_tail_last();
		void		assign_operator(iterator first, iterator last);

};

template <typename T>
void	list<T>::resize (size_type n, value_type val)
{
	if (n == _size)
		return;
	while (n < _size)
	{
		pop_back();
		n++;
	}
	while (n > _size)
	{
		insert(val);
		n++;
	}
	create_tail_last();
	return;
}

template <typename T>
void		list<T>::create_tail_last()
{
	node * 		temp_ptr;

	if (_tail->nxt && _tail->nxt != nullptr)
		delete(_tail->nxt);
	temp_ptr = new node(); // ENABLE IF AS LAST ONE IN INT NEEDS TO BE THIS
	// temp_ptr = new node(_size); // CHECK // if value try is integral then put size otherwise one above
	_tail->nxt = temp_ptr;
	temp_ptr->prev = _tail;
	temp_ptr->nxt = nullptr;
}

template <typename T>
ft::iterator<T>	list<T>::insert_newlist(ft::list<T> newlist, size_type n, iterator position)
{
	node * 		afterinsert;
	node *		new_ptr = NULL;
	node *		temp_ptr;
	iterator	it;
	size_type	i;
	size_type	initial_size;

	i = 0;
	initial_size = _size;
	it = begin();
	while (it != position && it != end())
		it++;
	afterinsert = it.get_list();
	if (it == end() && it == position && it != begin())
	{
		if (_tail->nxt)
			delete (_tail->nxt);
		_tail->nxt = afterinsert;
		afterinsert->prev = _tail;
	}
	else if (((it == end() && it != position) && afterinsert != _head->nxt) || (it == end() && it == position))
		afterinsert = _head;
	else if (afterinsert == _tail)
	{
		afterinsert = _tail;
		afterinsert->prev = _tail->prev;
	}
	node * newlist_ptr = newlist._head;
	if (afterinsert == _head)
	{
		_head = new node(newlist_ptr->get_data());
		it = (iterator)_head;
		newlist_ptr = newlist_ptr->nxt;
        _size++;
        _head->prev = nullptr;
		temp_ptr = _head;
		i++;
	}
	else if (afterinsert->prev == _head)
	{
		new_ptr = new node(newlist_ptr->get_data());
		it = (iterator)new_ptr;	
	    _size++;
		_head->nxt = new_ptr;
		new_ptr->prev = _head;
		temp_ptr = new_ptr;
		i++;
	}
	else
		temp_ptr = afterinsert->prev;	
	while (i < n)
	{
		new_ptr = new node(newlist_ptr->get_data());
		if (i == 0)
			it = (iterator)new_ptr;	
	    _size++;
	    new_ptr->prev = temp_ptr;
	    temp_ptr->nxt = new_ptr;
    	if (i != n - 1 || (afterinsert != _tail && afterinsert != _tail->nxt))	
			temp_ptr = new_ptr;
		newlist_ptr = newlist_ptr->nxt;
		i++;
	}
	if ((initial_size == 0) && temp_ptr == _head)
	{
		_tail = new node(1);
		temp_ptr->nxt = _tail;
		return (it);
	}
	if ((initial_size == 1) && temp_ptr == _head)
	{
		_tail = afterinsert;
		temp_ptr->nxt = _tail;
		return (it);
	}
	if (afterinsert == _tail)
	{
		new_ptr->nxt = _tail;
		_tail = afterinsert;
		_tail->prev = new_ptr;
		create_tail_last();
		return (it);
	}
	if (afterinsert == _tail->nxt)
	{
		_tail = new_ptr;
		_tail->prev = temp_ptr;
		create_tail_last();
		return (it);
	}
	temp_ptr->nxt = afterinsert;
	if (afterinsert->prev != _head)
		afterinsert->prev = temp_ptr;
	else
		temp_ptr->prev = _tail;
	create_tail_last();
	return (it);
}

template <typename T>
void list<T>::insert (iterator position, iterator first, iterator last)
{
	list<T>		newlist(first, last);
	size_type	n;

	n = newlist.size();
	insert_newlist(newlist, n, position);
	return ;
}

template <typename T>
void list<T>::insert (iterator position, size_type n, const value_type& val)
{
	list<T>		newlist(n, val);
	std::cout << "inserting newlist containing contains:";
  	for (ft::list<int>::iterator it=newlist.begin(); it!=newlist.end(); ++it)
    	std::cout << ' ' << *it;
	std::cout << '\n';
	insert_newlist(newlist, n, position);
	return ;
}

template <typename T>
iterator<T> list<T>::insert (iterator position, const value_type& val)
{
	size_type 	n = 1;
	list<T>		newlist(n, val);

	iterator	ret_it = insert_newlist(newlist, n, position);
	return (ret_it);
}

template <typename T>
void list<T>::swap (list& x)
{
	ft::list<T> tempthislist(begin(), end());	
	clear();
	assign(x.begin(), x.end());
	_size = x._size;
	x.clear();
	x.assign(tempthislist.begin(), tempthislist.end());
	x._size = tempthislist._size;
	// tempthislist.clear(); // not letting me do this so check mem 
}

template <typename T>
ft::iterator<T> list<T>::erase(iterator first, iterator last)
{
	node * 		aftererase;
	node * 		erase;
	node * 		beforeerase;
	iterator	it;

	if (_size == 0)
		return (_head);
	if (first == last)
		return(_head);
	it = first;
	erase = it.get_list();
	if (erase == _head)
		beforeerase = nullptr;
	else
		beforeerase = erase->prev;
	while (it != last)
	{
		erase = it.get_list();
		aftererase = erase->nxt;
		delete erase;
		_size--;
		it++;
	}
	if (beforeerase == nullptr)
	{
		_head = aftererase;
		_head->prev = nullptr;
		if (aftererase == _tail->nxt)
		{
			_head = new node();
			_tail = new node();
			_head->nxt = _tail;
			_tail->prev = _head;
			_size = 0;
			return (_head);
		}
	}
	if (aftererase != _tail)
	{
		beforeerase->nxt = aftererase;
		aftererase->prev = beforeerase;
	}
	create_tail_last();
	return((iterator)aftererase);
}

template <typename T>
ft::iterator<T> list<T>::erase(iterator position)
{
	node * 		aftererase;
	node * 		erase;
	node * 		beforeerase;
	iterator	it;
	
	if (_size == 0)
		return (_head);
	it = begin();
	while (it != position && it != end())
		it++;
	if (it == end())
		return (_tail);
	_size--;
	erase = it.get_list();
	if (erase == _head)
	{
		_head = erase->nxt;
		_head->prev = nullptr;
		delete erase;
		create_tail_last();
		return (_head->nxt);
	}
	if (erase == _tail)
	{
		create_tail_last();
		aftererase = _tail->nxt;
		delete _tail;
		_tail = erase->prev;
		_tail->nxt = aftererase;
		return (_tail->nxt);
	}
	if (erase == _head->nxt)
		beforeerase = _head;
	else
		beforeerase = erase->prev;
	if (erase == _tail->prev)
		aftererase = _tail;
	else
		aftererase = erase->nxt;
	delete erase;
	beforeerase->nxt = aftererase;
	aftererase->prev = beforeerase;
	create_tail_last();
	return(aftererase);
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
	_head->prev = nullptr;
	_size--;
	if (_size == 0)
	{
		_head = new node();
		_tail = new node();
		_head->nxt = _tail;
		_tail->prev = _head;
		_size = 0;
		return ;
	}
	create_tail_last();
	return ;
}

template <typename T>
void list<T>::pop_back()
{
	node * temp_ptr;

	if (_size == 0)
	{	
		_head = new node();
		_tail = new node();
		_head->nxt = _tail;
		_tail->prev = _head;
		return ;
	}
	temp_ptr = _tail->prev;
	if (_tail->nxt)
		delete(_tail->nxt);
	delete _tail;
	_tail = temp_ptr;
	_size--;
	if (_size == 0)
	{
		_head = new node();
		_tail = new node();
		_head->nxt = _tail;
		_tail->prev = _head;
		// _size = 0;
		return ;
	}
	temp_ptr = new node(_size);
	_tail->nxt = temp_ptr;
	temp_ptr->prev = _tail;
	return;
}
template <typename T>
void list<T>::push_back (const value_type& val)
{
	node * temp_ptr;
	// node * tail_lst;
	temp_ptr = new node(val);
	if (_size == 0)
	{
		_head = temp_ptr;
		_tail = _head;
		_size++;
		create_tail_last();
		return ;
	}
	if (_tail->nxt && _tail->nxt != nullptr)
	{
		delete _tail->nxt;
		// _tail->nxt = nullptr;
	}
	temp_ptr->prev = _tail;
	_tail->nxt = temp_ptr;
	temp_ptr->nxt = nullptr;
	_tail = temp_ptr;
	_size++;
	create_tail_last();
	// tail_lst = new node(_size);
	// _tail->nxt = tail_lst;
	// tail_lst->prev = _tail;
	// tail_lst->nxt = nullptr;
	return ;
}

template <typename T>
void list<T>::push_front (const value_type& val)
{
	node * temp_ptr;
	temp_ptr = new node(val);
	if (_size == 0)
		clear();
	if (_size == 0)
	{
		_tail = temp_ptr;
		_head = _tail;
		_size = 1;
		create_tail_last();
		return ;
	}
	temp_ptr->nxt = _head;
	temp_ptr->prev = nullptr;
	_head = temp_ptr;
	_size++;
	create_tail_last();
	return ;
}
template <typename T>
list<T>::list(iterator first, iterator last)
{
	assign(first, last);
	_size = 0;
	for (ft::list<T>::iterator it = first; it != last; ++it)
		_size++;
	create_tail_last();
	return ;
}

template <typename T>
list<T>::list(size_type n, const value_type val)
{
	assign(n, val);
	_size = n;
	create_tail_last();
	return ;
}

template <typename T>
list<T>::list()
{
	assign(0, 0);
	_size = 0;
	create_tail_last();
	return ;
	// _head = new node();
	// _tail = new node();
	// _head->nxt = _tail;
	// _tail->prev = _head;
	// _size = 0;
}

template <typename T>
void list<T>::assign (size_type n, const value_type& val)
{
	node * temp_ptr;
	node * new_ptr;

	if (_size > 0 && _size < 20000) // MAX SIZE
		clear();
    _size = 0;
	_head = nullptr;
	_tail = nullptr;
    if (n == 0)
	{
		// _head = new node();
		// _tail = _head;
		// _size = 0;
		// create_tail_last();
		// return;
		_head = new node();
		_tail = new node();
		_head->nxt = _tail;
		_tail->prev = _head;
		_size = 0;
		create_tail_last();
		return ;	
	}
    if (n == 1)
	{
		_head = new node(val);
		_tail = _head;
		_size = 1;
		create_tail_last();
		return ;	
	}
	_head = new node(val);
    _size++;
    temp_ptr = _head;
    for (size_type i = 1; i < n; i++)
    {
	    new_ptr = new node(val);
        _size++;
        new_ptr->prev = temp_ptr;
        temp_ptr->nxt = new_ptr;
        temp_ptr = new_ptr;
    }
    _tail = new_ptr;
    _head->prev = nullptr;
    _tail->nxt = nullptr;
	temp_ptr->nxt = nullptr;
	create_tail_last();
	return ;
}

template <typename T>
void list<T>::assign (iterator first, iterator last)
{
    node * temp_ptr;
	node * new_ptr;
	size_type	size = 0;

	if (_size > 0 && _size < 20000) // MAX SIZE
		clear();
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
	create_tail_last();
	return ;
}

template <typename T>
list<T>::list(size_type n)
{
	assign(n, 0);
	_size = n;
	create_tail_last();
	return ;
}

template <typename T>
list<T>::list(const list & source)
{
	_head = source._head;
	_tail = source._tail;
	_tail->prev = source._tail->prev;
	_head->prev = nullptr;
	assign(_head, _tail->nxt);
	_size = source._size;
	create_tail_last();
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
		// _tail->nxt = nullptr;
		
		_head->prev = nullptr;
		create_tail_last();
		assign_operator(_head, _tail->nxt);
		_size = source._size;
		create_tail_last();

   }
    return *this;
}

template <typename T>
void list<T>::clear()
{

	node * current_ptr = _head;
    node * temp_ptr;
    if (empty() == 0)
    {
		if (_tail->nxt)
			delete(_tail->nxt);
        while (_size > 0)
        {
            temp_ptr = current_ptr;
            current_ptr = current_ptr->nxt;
			current_ptr->prev = temp_ptr;
			_size--;
            delete (temp_ptr);
        }
		_head = nullptr;
		_tail = nullptr;
    }
	else
	{
		if (_head != nullptr)
			delete _head;
		if (_tail != nullptr)
			delete _tail;
	}
    return ;
}

template <typename T>
void list<T>::assign_operator (iterator first, iterator last)
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
	create_tail_last();
	return ;
}

template <typename T>
void list<T>::splice (iterator position, list& x)
{ 
	iterator	it;

	it = begin();
	while (it != position && it != end())
		it++;
	insert(it, x.begin(), x.end());
	x.clear();
	x = list();

}

template <typename T>
void list<T>::splice (iterator position, list& x, iterator i)
{
	const value_type& val = i.get_content();
	insert (position, 1, val);
	x.erase(i);
}

template <typename T>
void list<T>::splice (iterator position, list& x, iterator first, iterator last)
{
	insert (position, first, last);
	x.erase(first, last);
}

template <typename T>
void list<T>::remove(const value_type& val)
{
	iterator	it;

	it = begin();
	while (it != end())
	{
		if (*it == val)
		{
			erase(it);
			it = begin();
		}
		else
			it++;
	}	
}

template <typename T>
void list<T>::unique()
{
	iterator	it;
	iterator	nxt;

	it = begin();
	nxt = begin();
	nxt++;
	while (it != end() && nxt!= end())
	{
		if (*it == *nxt)
		{
			nxt = erase(it);
			it = nxt;
			it--;
		}
		else
		{
			it++;
			nxt++;
		}
	}	
}

template <typename T>
void list<T>::merge (list& x)
{
	iterator it;
	
	it = x.begin();
	while (it != x.end())
	{
		const value_type& val = it.get_content();
		push_back(val);
		it++;
	}
	x.clear();
}

}

#endif
