/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 13:06:53 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/06/16 16:06:35 by avan-dam      ########   odam.nl         */
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

namespace ft {
template <typename T>
class list
    {
	public:
		typedef unsigned int 			size_type; 
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
		
        list(size_type n, const value_type &val)
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
			if (_head != x._head || _tail != x._tail || _size != x._size)
			{
    		    clear();
				assign (x._head, x._tail->nxt);
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
	
		iterator	insert (iterator position, const value_type& val)
		{
			list<T>		newlist(1, val);
			return (insert_list_helper(newlist, position));
		}
		
		void		insert (iterator position, size_type n, const value_type& val)
		{
			list<T>		newlist(n, val);
			insert_list_helper(newlist, position);
			return ;
		}
		
		void		insert (iterator position, iterator first, iterator last)
		{
			list<T>		newlist(first, last);
			insert_list_helper(newlist, position);
			return ;
		}
	
		iterator	erase (iterator position)
		{
			iterator end = position;
			end++;
			end = erase(position, end);
			return (end);
		}
		
		iterator	erase (iterator first, iterator last)
		{
			iterator	it = begin();

			if (first == it && last == end())// end?
			{
				clear();
				assign(0,0);
				return(_head);
			}
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

		void		swap (list& x)
		{
			ft::list<T> tempthislist(begin(), end());	
			assign(x.begin(), x.end());
			_size = x._size;
			x.clear();
			x.assign(tempthislist.begin(), tempthislist.end());
			x._size = tempthislist._size;
		}

		void		resize (size_type n, value_type val)
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

        void 		clear()
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
						current_ptr = current_ptr->nxt;
        		    if (temp_ptr)
						delete (temp_ptr);
		        }
				_head = nullptr;
				_tail = nullptr;
				return ;
    		}
		if (_head)
			delete _head;
		if (_tail && _tail->nxt)
			delete _tail->nxt;
		if (_tail)
			delete _tail;
		_size = 0;
    	return ;
		}

		void splice (iterator position, list& x)
		{
			iterator	it;

			if (x.empty())
				return;
			it = begin();
			while (it != position && it != end())
				it++;
			insert(it, x.begin(), x.end());
			x.clear();
			return ;
		}
		
		void splice (iterator position, list& x, iterator i)
		{
			iterator	it;

			if (x.empty())
				return;
			it = begin();
			while (it != position && it != end())
				it++;
			const value_type& val = i.get_content();
			insert (it, 1, val);
			x.erase(i);
			return;
		}

		void splice (iterator position, list& x, iterator first, iterator last)
		{
			insert (position, first, last);
			x.erase(first, last);
			return;
		}

		void remove (const value_type& val)
		{
			iterator	it = begin();

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
		
		template <class Predicate>
  		void remove_if (Predicate pred)
  		{
			iterator	it = begin();

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
		
		void unique()
		{
			iterator	it = begin();
			iterator	nxt = begin();

			nxt++;
			while (it != end() && nxt!= end())
			{
				if (*it == *nxt)
				{
					nxt = erase(nxt);
					if (nxt == begin())
					{
						nxt++;
						it = begin();
					}
					else
					{
						it = nxt;
						it--;
					}
				}
				else
				{
					it++;
					nxt++;
				}
			}
		}

		template <class BinaryPredicate>
  		void unique (BinaryPredicate binary_pred)
		{
		  	iterator	it = begin();
			iterator	nxt = begin();

			nxt++;
			while (it != end() && nxt!= end())
			{
				if (binary_pred(*nxt, *it) == true)
				{
					nxt = erase(nxt);
					if (nxt == begin())
					{
						nxt++;
						it = begin();
					}
					else
					{
						it = nxt;
						it--;
					}
				}
				else
				{
					it++;
					nxt++;
				}
			}
		}
		void merge (list& x)
		{
			iterator it = x.begin();
	
			while (it != x.end())
			{
				push_back(it.get_content());
				it++;
			}
			x.clear();
		}

		template <class Compare>
		void merge (list& x, Compare comp)
		{
			iterator	it_insert = x.begin();
			iterator	it_this = begin();

			while (it_insert != x.end() && it_this != end())
			{
				while (it_this != _tail)
				{
					if (comp(*it_insert, *it_this) == true)
					{
						const value_type& val = it_insert.get_content();
						it_this = insert(it_this, val);
						it_this++;
						it_this++;
						break;
					}
					it_this++;
				}
				if (it_this == _tail)
				{
					std::cout << "it_this" << *it_this << std::endl;
					push_back(it_insert.get_content());
					it_this++;
				}
				it_insert++;
			}
			x.clear();
		}

		void	sort()
		{
			iterator	it = begin();
			iterator	nxt = begin();

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

		template <class Compare>
	 	void sort (Compare comp)
		{
			iterator	it = begin();
			iterator	nxt = begin();

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
		void reverse()
		{
			iterator it = begin();
			list<T> list_copy(begin(), end());
			iterator copy_it = list_copy.end();
	
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

	private:
		node		*_head;
		node		*_tail;
		size_type	_size;

		//HELPER FUNCTIONS
		iterator	insert_newlist(ft::list<T> newlist)
		{
			if (newlist.size() == 0)
				return (end());
			for (ft::list<T>::iterator it=newlist.begin(); it!=newlist.end(); ++it)
				push_back(it.get_content());
			if (newlist.size() == 1)
				return (begin());
			return (_tail);
		}
		iterator	insert_list_helper(ft::list<T> newlist, iterator position)
		{
			iterator	it = begin();

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

		void		create_tail_last()
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
		void		create_empty_lst()
		{
			_head = new node();
			_tail = new node();
			_head->nxt = _tail;
			_tail->prev = _head;
			_size = 0;
			create_tail_last();
			return ;
		}
};

//REALTIONAL OPERATORS
template <typename T>
bool operator== (const list<T>& lhs, const list<T>& rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	ft::list<T> lhs_copy(lhs);
	ft::list<T> rhs_copy(rhs);
	typename ft::list<T>::iterator lhs_it = lhs_copy.begin();
	typename ft::list<T>::iterator rhs_it = rhs_copy.begin();
	while (lhs_it != lhs_copy.end() && rhs_it != rhs_copy.end())
	{
		if (lhs_it.get_content() != rhs_it.get_content())
			return false;
		lhs_it++;
		rhs_it++;
	}
	return true;
}

template <typename T>
bool operator!=(const list<T>& lhs, const list<T>& rhs)
{
	return !(lhs == rhs);
}

template <typename T>
bool operator>(const list<T>& lhs, const list<T>& rhs)
{
	ft::list<T> lhs_copy(lhs);
	ft::list<T> rhs_copy(rhs);
	typename ft::list<T>::iterator lhs_it = lhs_copy.begin();
	typename ft::list<T>::iterator rhs_it = rhs_copy.begin();
	while (lhs_it != lhs_copy.end() && rhs_it != rhs_copy.end())
	{
		if (lhs_it.get_content() > rhs_it.get_content())
			return true;
		lhs_it++;
		rhs_it++;
	}
	if (lhs_it != lhs_copy.end())
		return true;
	return false;
}

template <typename T>
bool operator<(const list<T>& lhs, const list<T>& rhs)
{
	ft::list<T> lhs_copy(lhs);
	ft::list<T> rhs_copy(rhs);
	typename ft::list<T>::iterator lhs_it = lhs_copy.begin();
	typename ft::list<T>::iterator rhs_it = rhs_copy.begin();
	while (lhs_it != lhs_copy.end() && rhs_it != rhs_copy.end())
	{
		if (lhs_it.get_content() < rhs_it.get_content())
			return true;
		lhs_it++;
		rhs_it++;
	}
	if (rhs_it != rhs_copy.end())
		return true;
	return false;
}

template <typename T>
bool operator<=(const list<T>& lhs, const list<T>& rhs)
{
	return !(lhs > rhs);
}

template <typename T>
bool operator>=(const list<T>& lhs, const list<T>& rhs)
{
	return !(lhs < rhs);
}

template <class T>
  void swap (list<T>& x, list<T>& y)
  {
	  ft::list<T> tempthislist(y.begin(), y.end());
	  y.assign(x.begin(), x.end());
	  x.clear();
	  x.assign(tempthislist.begin(), tempthislist.end());
  }
}
#endif
