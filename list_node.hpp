/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_node.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 15:47:16 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/04/13 15:23:25 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_NODE_HPP
# define LIST_NODE_HPP

#include <iostream>

template <typename T>
class list_node
{
    public:
        list_node();
        list_node(T data_rec);
        list_node(const list_node & source);
        list_node & operator=(const list_node & source);
        ~list_node();
        void deep_copy(const list_node & source, int i);
        list_node<T>* get_next();
        T   data;
        list_node<T>*   nxt;
        list_node<T>*   prev;
};

template <typename T>
list_node<T>* list_node<T>::get_next()
{
    return (nxt);
}

template <typename T>
list_node<T>::list_node()
{
    data = 0;
    nxt = nullptr;
    prev = nullptr;
}

template <typename T>
list_node<T>::list_node(T data_rec)
{
    data = data_rec;
    nxt = nullptr;
    prev = nullptr;
}

template <typename T>
void list_node<T>::deep_copy(const list_node & source, int i)
{
    // if (i == 1)
    // {
    //     delete next;
    //     delete prev;
    // }
    (void)i;
    data = source.data;
    // nxt = new list_node<T>(*source.nxt);
    // prev = new list_node<T>(*source.prev);
    nxt = source.nxt;
    prev = source.prev;
}

template <typename T>
list_node<T>::list_node(const list_node & source)
{
    std::cout << "list node in copy constructor" << std::endl;
    deep_copy(source, 0);
    std::cout << "out node in copy constructor" << std::endl;
}

template <typename T>
list_node<T> & list_node<T>::operator=(const list_node & source)
{
    if (nxt != source.nxt || prev != source.prev || data != source.data)
        deep_copy(source, 1);
    return *this;
}

template <typename T>
list_node<T>::~list_node()
{
    data = 0;
    nxt = nullptr;
    prev = nullptr;
}

#endif
