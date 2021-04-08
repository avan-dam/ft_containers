/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 13:06:53 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/04/08 11:54:50 by ambervandam   ########   odam.nl         */
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
        ft_list & operator=(const ft_list &x);
        void deep_copy(const ft_list & source);
        // ~ft_list();
    private:
        list_node<T> *_start_ptr;
        list_node<T> *_end_ptr;
        size_type   _size;
};

template <typename T>
ft_list<T>::ft_list() //creates list with start and end as nullptr
{
    _size = 0;
	_start_ptr = nullptr;
	_end_ptr = nullptr;
}

template <typename T>
ft_list<T>::ft_list(T *val)
{
    list_node<T> * temp_ptr;

    _size = 0;
    _start_ptr= nullptr;
    _end_ptr = nullptr;
    if (val[0])
    {
	    _start_ptr = new list_node<T>(val[0]); //creates new node
        _size++;
        std::cout << "_start_ptr node " << " with " << _start_ptr->data << std::endl;
        temp_ptr = _start_ptr;
        if (!(val[1]))
        {
            _end_ptr = _start_ptr;
            return ;
        }
    }
    for (int i = 1; val[i]; i++)
    {
	    list_node<T> * new_ptr = new list_node<T>(val[i]); //creates new node
        _size++;
        std::cout << "creating node " << i << " with " << new_ptr->data << std::endl;
        new_ptr->prev_ptr = temp_ptr;
        temp_ptr->next_ptr = new_ptr;
        temp_ptr = new_ptr;
    }
    _end_ptr = temp_ptr;
    std::cout << "_end_ptr node " << " with " << _end_ptr->data << std::endl;
    _start_ptr->prev_ptr = nullptr;
    _end_ptr->prev_ptr = nullptr;
    std::cout << "size is: " << _size << std::endl;

}


template <typename T>
ft_list<T>::ft_list(size_type n, T val)
{
    list_node<T> * temp_ptr;

    _size = 0;
    if (n == 0)
        return ;
    _end_ptr = nullptr;
	_start_ptr = new list_node<T>(val); //creates new node
    _size++;
    std::cout << "_start_ptr node " << " with " << _start_ptr->data << std::endl;
    temp_ptr = _start_ptr;
    if (n == 1)
    {
        _end_ptr = _start_ptr;
        return ;
    }
    for (size_type i = 1; i < n; i++)
    {
	    list_node<T> * new_ptr = new list_node<T>(val); //creates new node
        _size++;
        std::cout << "creating node " << i << " with " << new_ptr->data << std::endl;
        new_ptr->prev_ptr = temp_ptr;
        temp_ptr->next_ptr = new_ptr;
        temp_ptr = new_ptr;
    }
    _end_ptr = temp_ptr;
    std::cout << "_end_ptr node " << " with " << _end_ptr->data << std::endl;
    _start_ptr->prev_ptr = nullptr;
    _end_ptr->prev_ptr = nullptr;
    std::cout << "size is: " << _size << std::endl;

}

template <typename T>
void ft_list<T>::deep_copy(const ft_list & source)
{
    list_node<T> * temp_ptr = nullptr;
    list_node<T> * temp_ptr2 = nullptr;

    _size = source._size;
    _start_ptr = temp_ptr;
    while (temp_ptr)
    {    
        temp_ptr2 = temp_ptr->next_ptr;
        delete temp_ptr;
        temp_ptr = temp_ptr2;
    }
    _end_ptr = nullptr;
    if (source._start_ptr)
        _start_ptr = source._start_ptr;
    std::cout << "creating _start_ptr " << _start_ptr->data << std::endl;
    temp_ptr = _start_ptr;
    if (source._end_ptr)
        _end_ptr = source._end_ptr;
    std::cout << "creating _end_ptr " << _end_ptr->data << std::endl;  
    std::cout << "size is: " << _size << std::endl;  
}

template <typename T>
ft_list<T>::ft_list(const ft_list & source)
{
    deep_copy(source);
    return ;
}

template<typename T>
ft_list<T> & ft_list<T>::operator=(const ft_list & source)
{
    if (this != source)
        deep_copy(source);
    return *this;
}

#endif
