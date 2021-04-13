/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 13:06:53 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/04/13 15:41:25 by ambervandam   ########   odam.nl         */
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
		typedef T value_type; 
		typedef iterator<T> iterator;

	public:
		list();
		list(size_type n);
        	list(size_type n, const value_type val);
		list(const list &x);
		list & operator=(const list &x);
		~list();

		void 		deep_copy(const list & source, int i);
		bool    		empty() const;
		size_type		size() const;
		// size_type max_size() const;

		iterator begin() {return ft::iterator<T>(_head);}
		iterator end() { return ft::iterator<T>(_tail->nxt); }
	private:
		list_node<T>	*_head;
		list_node<T>	*_tail;
		size_type  	 _size;
};

template <typename T>
size_type		list<T>::size() const
{
	return (_size);
}

template <typename T>
list<T>::list()
{
	_size = 0;
    	_head = nullptr;
    	_tail = nullptr;
}

template <typename T>
bool    list<T>::empty() const
{
	if (_head == nullptr && _tail == nullptr && _size == 0)
        	return (true);
    	return (false);
}

template <typename T>
list<T>::list(size_type n, const value_type val)
{
    list_node<T> * temp_ptr;

    _size = 0;
    if (n == 0)
        return ;
	_head = new list_node<T>(val);
    _size++;
    std::cout << "_head node " << " with " << _head->data << std::endl;
    temp_ptr = _head;
    if (n == 1)
    {
        _tail = _head;
        return ;
    }
    for (size_type i = 1; i < n; i++)
    {
	    list_node<T> * new_ptr = new list_node<T>(val); //creates new node
        _size++;
        std::cout << "creating node " << i << " with " << new_ptr->data << std::endl;
        new_ptr->prev = temp_ptr;
        temp_ptr->nxt = new_ptr;
        temp_ptr = new_ptr;
    }
    _tail = temp_ptr;
    std::cout << "_tail node " << " with " << _tail->data << std::endl;
    _head->prev = nullptr;
    _tail->nxt = nullptr;
    std::cout << "size is: " << _size << std::endl;
}

template <typename T>
list<T>::list(size_type n)
{
	list_node<T> * temp_ptr;

	_size = 0;
    if (n == 0)
        return ;
	_head = new list_node<T>(0);
    _size++;
    std::cout << "_head node " << " with " << _head->data << std::endl;
    temp_ptr = _head;
    if (n == 1)
    {
        _tail = _head;
        return ;
    }
    for (size_type i = 1; i < n; i++)
    {
	    list_node<T> * new_ptr = new list_node<T>(0); //creates new node
        _size++;
        std::cout << "creating node " << i << " with " << new_ptr->data << std::endl;
        new_ptr->prev = temp_ptr;
        temp_ptr->nxt = new_ptr;
        temp_ptr = new_ptr;
    }
     _tail = temp_ptr;
    std::cout << "_tail node " << " with " << _tail->data << std::endl;
    _head->prev = nullptr;
    _tail->nxt = nullptr;
    std::cout << "size is: " << _size << std::endl;
}

template <typename T>
void list<T>::deep_copy(const list & source, int i)
{
// 	if (i == 1)
// 	{
//    		list_node<T> * current;
//     		list_node<T> * temp;

// 	    if (empty() == false)
//     		{
//        		current =_head;
//         		while (current)
//         		{
//           		temp = current->nxt;
//           		std::cout << "deeletomg  " << std::endl;
//           		delete current;
//           		current = temp;
//         		}
// 		}
//     }
(void)i;
    _size = source._size;
    if (source._head)
        _head = new list_node<T>(source._head->data);
    std::cout << "creating _head " << _head->data << std::endl;
    if (source._tail)
        _tail = new list_node<T>(source._tail->data);
	std::cout << "creating _tail " << _tail->data << std::endl;
    std::cout << "size is: " << _size << std::endl;  
}

template <typename T>
list<T>::list(const list & source)
{
    std::cout << "Assignment opp called list" << std::endl;
    deep_copy(source, 0);
    return ;
}

template<typename T>
list<T> & list<T>::operator=(const list & source)
{
    std::cout << "Copy constructor list called list" << std::endl;
    if (_head != source._head || _tail != source._tail || _size != source._size)
		deep_copy(source, 1);
    std::cout << "END Copy constructor list called list" << std::endl;
    return *this;
}

template <typename T>
list<T>::~list()
{
    list_node<T> * current_ptr = _head;
    list_node<T> * temp_ptr;

    if (!empty())
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
}

#endif
