/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_node.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 15:47:16 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/04/20 12:08:40 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_NODE_HPP
# define LIST_NODE_HPP

#include <iostream>

template <typename T>
class list_node
{
    public:
        list_node() : data(0), nxt(nullptr), prev(nullptr) {}
        list_node(T data_rec) : data(data_rec), nxt(nullptr), prev(nullptr) {}
        list_node(const list_node & source) : data(source.data), nxt(source.nxt), prev(source.prev) {}
        list_node(list_node & source) : data(source.data), nxt(source.nxt), prev(source.prev) {}
        list_node & operator=(const list_node & source)
		{
			if (this != source)
			{
				prev = source.prev;
				nxt = source.nxt;
				data = source.data;
			}
			return *this;
		}
        ~list_node() {}

        list_node<T>* get_next() {  return (nxt);}
        list_node<T>* get_prev() {	return (prev);}

		bool operator==(const list_node & rhs)
        {
            if (data == rhs.data && nxt == rhs.nxt && prev == rhs.prev)
                return (true);
            return (false);
        }
		bool operator!=(const list_node & rhs)
        {
            if (data == rhs.data && nxt == rhs.nxt && prev == rhs.prev)
                return (false);
            return (true); 
        }

        T				data;
        list_node<T>*	nxt;
        list_node<T>*	prev;
};

#endif
