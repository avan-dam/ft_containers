/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 13:06:53 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/06/07 18:23:25 by ambervandam   ########   odam.nl         */
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
		//CONSTRUCTORS/DESTRCUTOR
		list()
		{
			create_empty_lst();
			return ;
		}
		
        list(size_type n, const value_type val)
		{
			_size = 0;
			assign(n, val);
			return ;
		}
		
		list(size_type n)
		{
			_size = 0;
			assign(n, 0);
			_size = n;
			create_tail_last();
			return ;
		}
		
        list(iterator first, iterator last)
		{
			_size = 0;
			assign(first, last);
			return ;
		}

		list(const list &x)
		{
			_size = 0;
			_head = x._head;
			_tail = x._tail;
			assign(_head, _tail->nxt);
			_size = x._size;
			create_tail_last();
			return ;
		}
		
		~list() 
		{
			clear(); 
			return ;
		}
		
		//ASSIGNMENT OPERATOR
		list & operator=(const list &x)
		{
			iterator first;
			iterator last;
			if (_head != x._head || _tail != x._tail || _size != x._size)
			{
    		    clear();
				first = x._head;
				last = x._tail->nxt;
				assign (first, last);
				return *this;
   			}
		    return *this;
		}

		//ITERATORS
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
		
		//CAPACITY
		bool    		empty() const { return (_size == 0); }
		size_type		size() const { return (_size); }
		// size_type max_size() const;

		//ELEMENT ACCESS
		node		front() { return (*_head);	}
		// const_reference front() const;
		node		back() { return (*_tail);	}
		// const_reference back() const;

		//MODIFIERS
		void		assign (size_type n, const value_type& val)
		{
			node * temp_ptr;
			node * new_ptr;

			if (_size > 0 && _size < 20000) // MAX SIZE
				clear();
		    if (n == 0)
				return (create_empty_lst());
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
			create_tail_last();
			return ;
		}
	
		void		assign (iterator first, iterator last)
		{
			node * temp_ptr;
			node * new_ptr;
	
			if (_size > 0 && _size < 20000) // MAX SIZE
				clear();
			_size = 0;
			if (first == last)
				return (create_empty_lst());
			_head = new node(first.get_content());
   			temp_ptr = _head;
			_size++;
			first++;
			while (first != last)
    		{
				new_ptr = new node(first.get_content());
				_size++;
		        new_ptr->prev = temp_ptr;
    		    temp_ptr->nxt = new_ptr;
    		    temp_ptr = new_ptr;
				first++;
    		}
		_tail = temp_ptr;
		_head->prev = nullptr;
		create_tail_last();
		return ;
		}

		void		push_front (const value_type& val)
		{
			insert(begin(), val);
			return ;
		}
		void		pop_front()
		{
			erase(begin());
			return;
		}
		
		void		push_back (const value_type& val)
		{
			node * old_tail;

			if (_size == 0)
			{
				clear();
				_tail = new node(val);
				_head = _tail;
				_size = 1;
				create_tail_last();
				return ;
			}
			if (_tail->nxt)
				delete _tail->nxt;
			old_tail = _tail;
			_tail = new node(val);
			old_tail->nxt = _tail;
			_tail->prev = old_tail;
			_size++;
			create_tail_last();
			return ;
		}
		
		void		pop_back()
		{
			erase(_tail);
			return;
		}
	
		iterator	insert (iterator position, const value_type& val);
		void		insert (iterator position, size_type n, const value_type& val);
		void		insert (iterator position, iterator first, iterator last);
	
		iterator	erase (iterator position);
		iterator	erase (iterator first, iterator last);

		void		swap (list& x);

		void resize (size_type n, value_type val);
        void 		clear();

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
					if (comp(*it_insert, *it_this) == true)
					{
						insert(it_this, it_insert.get_content());
						break;
					}
					it_this++;
				}
				if (it_this == end())
				{
					push_back(it_insert.get_content());
					it_this++;
				}
				it_insert++;
			}
			x.clear();
		}

		void	sort();

		template <class Compare>
	 	void sort (Compare comp)
		{
			iterator	it;
			iterator	nxt;

			it = begin();
			nxt = begin();
			nxt++;
			while (it != end() && nxt!= end())
			{
				if (comp(*nxt, *it) == true)
				{
					const value_type& val1 = it.get_content();
					const value_type& val2 = nxt.get_content();
					nxt.get_list()->change_content(val1);
					it.get_list()->change_content(val2);
					it = begin();
					nxt = begin();
					nxt++;
				}
				else
				{
					it++;
					nxt++;
				}
			}	
		}
		void reverse();

	private:
		node		*_head;
		node		*_tail;
		size_type	_size;
		iterator	insert_newlist(ft::list<T> newlist);
		void		create_tail_last();
		void		create_empty_lst();

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

	if (_tail && _tail != nullptr && _tail->nxt && _tail->nxt != nullptr)
		delete(_tail->nxt);
	temp_ptr = new node(); // ENABLE IF AS LAST ONE IN INT NEEDS TO BE THIS
	// temp_ptr = new node(_size); // CHECK // if value try is integral then put size otherwise one above
	_tail->nxt = temp_ptr;
	temp_ptr->prev = _tail;
	temp_ptr->nxt = nullptr;
}

template <typename T>
ft::iterator<T>	list<T>::insert_newlist(ft::list<T> newlist)
{
	if (newlist.size() == 0)
		return (end());
	for (ft::list<T>::iterator it=newlist.begin(); it!=newlist.end(); ++it)
		push_back(it.get_content());
	return (end());
}

template <typename T>
void list<T>::insert (iterator position, iterator first, iterator last)
{
	list<T>		newlist(first, last);
	iterator	it;

	it = begin();
	while (it != position)
		it++;
	list<T>		list_start(begin(), it);
	list<T>		list_end(it, end());

	clear();
	insert_newlist(list_start);
	insert_newlist(newlist);
	insert_newlist(list_end);
	if (!list_start.empty())
		list_start.clear();
	if (!newlist.empty())
		newlist.clear();
	if (!list_end.empty())
		list_end.clear();
	return ;
}

template <typename T>
void list<T>::insert (iterator position, size_type n, const value_type& val)
{
	list<T>		newlist(n, val);
	iterator	it;

	it = begin();
	while (it != position)
		it++;
	list<T>		list_start(begin(), it);
	list<T>		list_end(it, end());

	clear();
	insert_newlist(list_start);
	position = insert_newlist(newlist);
	insert_newlist(list_end);
	if (!list_start.empty())
		list_start.clear();
	if (!newlist.empty())
		newlist.clear();
	if (!list_end.empty())
		list_end.clear();
	return ;
}

template <typename T>
iterator<T> list<T>::insert (iterator position, const value_type& val)
{
	list<T>		newlist(1, val);
	iterator	it;

	it = begin();
	while (it != position)
		it++;
	list<T>		list_start(begin(), it);
	list<T>		list_end(it, end());
	if (!empty())
		clear();
	insert_newlist(list_start);
	position = insert_newlist(newlist);
	insert_newlist(list_end);
	if (!list_start.empty())
		list_start.clear();
	if (!newlist.empty())
		newlist.clear();
	if (!list_end.empty())
		list_end.clear();
	return (position);
}

template <typename T>
void list<T>::swap (list& x)
{
	ft::list<T> tempthislist(begin(), end());	
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

	iterator	it = begin();

	while (it != first)
		it++;
	list<T>		list_start(begin(), it);
	while (it != last)
		it++;
	list<T>		list_end(it, end());

	clear();
	if (list_end.empty() && list_start.empty())
		return (_head);
	it = insert_newlist(list_start);
	insert_newlist(list_end);
	if (list_start.empty())
		it = begin();
	if (list_end.empty())
		it = end();
	if (!list_start.empty())
		list_start.clear();
	if (!list_end.empty())
		list_end.clear();
	return (it);
}

template <typename T>
ft::iterator<T> list<T>::erase(iterator position)
{
	iterator	it = begin();

	while (it != position)
		it++;
	list<T>		list_start(begin(), it);
	it++;
	list<T>		list_end(it, end());

	clear();
	insert_newlist(list_start);
	insert_newlist(list_end);
	if (!list_start.empty())
		list_start.clear();
	if (!list_end.empty())
		list_end.clear();
	return (position);
}

template <typename T>
void	list<T>::create_empty_lst()
{
	_head = new node();
	_tail = new node();
	_head->nxt = _tail;
	_tail->prev = _head;
	_size = 0;
	create_tail_last();
	return ;
}

template <typename T>
void list<T>::clear()
{
	node * current_ptr = _head;
    node * temp_ptr;
    if (empty() == 0)
    {
		if (_tail && _tail != nullptr && _tail->nxt)
			delete(_tail->nxt);
        while (_size > 0)
        {
            temp_ptr = current_ptr;
			_size--;
			if (_size > 0 && current_ptr && current_ptr->nxt)
	        {   
				current_ptr = current_ptr->nxt;
			}
            if (temp_ptr)
				delete (temp_ptr);

        }
		_head = nullptr;
		_tail = nullptr;
    }
	else
	{
		if (_head)
			delete _head;
		if (_tail && _tail->nxt)
			delete _tail->nxt;
		if (_tail)
			delete _tail;
	}
	_size = 0;
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
	std::cout << "in splice" << std::endl;
	insert (position, first, last);
	std::cout << "in splice after insert" << std::endl;
	std::cout << "with size " << _size << std::endl;
	std::cout << "going to clear :";
	for (ft::list<T>::iterator it_ft=begin(); it_ft!=end(); ++it_ft)
    	std::cout << ' ' << *it_ft;
	std::cout << '\n';
	x.erase(first, last);
	std::cout << "in splice after erase" << std::endl;
	std::cout << "leaving splice with with size " << _size << std::endl;
	std::cout << "going to clear :";
	for (ft::list<T>::iterator it_ft=begin(); it_ft!=end(); ++it_ft)
    	std::cout << ' ' << *it_ft << std::endl;
	std::cout << '\n';
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

template <typename T>
void list<T>::sort ()
{
	iterator	it;
	iterator	nxt;

	it = begin();
	nxt = begin();
	nxt++;
	while (it != end() && nxt!= end())
	{
		if (*it > *nxt)
		{
			const value_type& val1 = it.get_content();
			const value_type& val2 = nxt.get_content();
			nxt.get_list()->change_content(val1);
			it.get_list()->change_content(val2);
			it = begin();
			nxt = begin();
			nxt++;
		}
		else
		{
			it++;
			nxt++;
		}
	}	
}

template <typename T>
void list<T>::reverse()
{
	iterator it;
	iterator copy_it;
	list<T> list_copy(begin(), end());
	
	it = begin();
	copy_it = list_copy.end();
	copy_it--;
	while (it != end() && copy_it != list_copy.begin())
	{
		const value_type& val2 = copy_it.get_content();
		it.get_list()->change_content(val2);
		it++;
		copy_it--;
	}
	const value_type& val2 = list_copy.begin().get_content();
	it = end();
	it--;
	it.get_list()->change_content(val2);
	list_copy.clear();
	}
}

#endif
