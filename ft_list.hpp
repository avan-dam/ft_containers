/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 13:06:53 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/04/07 16:56:27 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_HPP
# define FT_LIST_HPP

#include "list_node.hpp"

#include <iostream>

template <typename T>
class ft_list
{
    public:
    typedef unsigned int size_type;
        ft_list();
        ft_list(T *val);
        ft_list(size_type n, T val);
        ft_list(const ft_list &x);
    private:
        list_node<T> *_start_ptr;
        list_node<T> *_end_ptr;
        size_type   _size;
};

template <typename T>
ft_list<T>::ft_list() //creates list with start and end as NULL
{
	_start_ptr = NULL;
	_end_ptr = NULL;
}

template <typename T>
ft_list<T>::ft_list(T *val)
{
    int i;
    list_node<T> * temp_ptr;

    i = 0;
   _start_ptr= NULL;
    _end_ptr = NULL;
    if (val[i])
    {
	    list_node<T> * new_ptr = new list_node<T>(val[i]); //creates new node
        _size++;
        std::cout << "creating node " << i << " with " << new_ptr->data << std::endl;
        _start_ptr = new_ptr;
        temp_ptr = new_ptr;
        i++;
        if (!(val[i]))
        {
            _end_ptr = new_ptr;
            return ;
        }
    }
    while (val[i + 1])
    {
	    list_node<T> * new_ptr = new list_node<T>(val[i]); //creates new node
        _size++;
        std::cout << "creating node " << i << " with " << new_ptr->data << std::endl;
        new_ptr->prev_ptr = temp_ptr;
        temp_ptr->next_ptr = new_ptr;
        temp_ptr = new_ptr;
        i++;
    }
    if (val[i])
    {
	    list_node<T> * new_ptr = new list_node<T>(val[i]); //creates new node
        _size++;
        std::cout << "creating node " << i << " with " << new_ptr->data << std::endl;
        _end_ptr = new_ptr;
        new_ptr->prev_ptr = temp_ptr;
    }
    _start_ptr->prev_ptr = NULL;
    _end_ptr->prev_ptr = NULL;
}


template <typename T>
ft_list<T>::ft_list(size_type n, T val)
{
    size_type i;
    list_node<T> * temp_ptr;

    i = 0;
    _start_ptr= NULL;
    _end_ptr = NULL;
    if (n > 0)
    {
	    list_node<T> * new_ptr = new list_node<T>(val); //creates new node
        _size++;
        std::cout << "creating node " << i << " with " << new_ptr->data << std::endl;
        _start_ptr = new_ptr;
        temp_ptr = new_ptr;
        if (n == 1)
        {
            _end_ptr = new_ptr;
            return ;
        }
        i++;
    }
    while (i < n - 1)
    {
	    list_node<T> * new_ptr = new list_node<T>(val); //creates new node
        _size++;
        std::cout << "creating node " << i << " with " << new_ptr->data << std::endl;
        new_ptr->prev_ptr = temp_ptr;
        temp_ptr->next_ptr = new_ptr;
        temp_ptr = new_ptr;
        i++;
    }
	list_node<T> * new_ptr = new list_node<T>(val); //creates new node
    _size++;
    std::cout << "creating node " << i << " with " << new_ptr->data << std::endl;
    _end_ptr = new_ptr;
    new_ptr->prev_ptr = temp_ptr;
    _start_ptr->prev_ptr = NULL;
    _end_ptr->prev_ptr = NULL;
    return ;
}


template <typename T>
ft_list<T>::ft_list(const ft_list &x)
{
    _size = x._size;
    _start_ptr = x._start_ptr;
    _end_ptr = x._end_ptr;
    return ;
}


#endif
