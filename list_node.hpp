/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_node.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 15:47:16 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/04/07 16:28:21 by ambervandam   ########   odam.nl         */
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
        T   get_data();
    public:
        T   data;
        list_node<T>*   next_ptr;
        list_node<T>*   prev_ptr;
};

template <typename T>
list_node<T>::list_node(T data_rec)
{
    data = data_rec;
    next_ptr = NULL;
    // prev_p/tr = NULL; /// not sure about this line
}

template <typename T>
T list_node<T>::get_data()
{
    return (data);
}

#endif
