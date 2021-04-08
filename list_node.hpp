/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_node.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 15:47:16 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/04/08 11:31:02 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_NODE_HPP
# define LIST_NODE_HPP

#include <iostream>

template <typename T>
class list_node
{
    public:
        list_node(T);
        list_node(const list_node & source);
        list_node & operator=(const list_node & source);
        ~list_node();
        void deep_copy(const list_node & source);
        T   get_data();

    // private
        T   data;
        list_node<T>*   next_ptr;
        list_node<T>*   prev_ptr;
};

template <typename T>
list_node<T>::list_node(T data_rec)
{
    data = data_rec;
    next_ptr = nullptr;
    prev_ptr = nullptr;
}

template <typename T>
list_node<T>::list_node(const list_node & source)
{
    std::cout << "copy constructor called" << std::endl;
    deep_copy(source);
}

template <typename T>
list_node<T> & list_node<T>::operator=(const list_node & source)
{
    std::cout << "assignment opperator called" << std::endl;
    if (this != source)
        deep_copy(source);
    return *this;
}

template <typename T>
list_node<T>::~list_node()
{
    data = 0;
    next_ptr = nullptr;
    prev_ptr = nullptr;
}

template <typename T>
void list_node<T>::deep_copy(const list_node & source)
{
    delete next_ptr;
    delete prev_ptr;
    data = source.data;
    next_ptr = new list_node<T>(source.next_ptr);
    prev_ptr = new list_node<T>(source.prev_ptr);
}

template <typename T>
T list_node<T>::get_data()
{
    return (data);
}

#endif
