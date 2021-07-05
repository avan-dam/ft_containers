/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_node.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 15:47:16 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/06/06 17:14:32 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_NODE_HPP
# define LIST_NODE_HPP

#include <iostream>

template <typename T>
class list_node
{
    public:
        list_node() : data(), nxt(nullptr), prev(nullptr) {}
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

        list_node<T>* get_next() {
        if (nxt)
            return (nxt); 
        while (prev->prev)
            prev = prev->prev;
        return (prev);
        }
         list_node<T>* get_prev() {
             if (prev)
            return (prev); 
        while (nxt->nxt)
            nxt = nxt->nxt;
        return (nxt);
        }
		T get_data() const {return (data);}

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

        void    change_content(T newdata)
        {
            data = newdata;
            return;
        }

        T				data;
        list_node<T>*	nxt;
        list_node<T>*	prev;
};

template<class T>
std::ostream& operator<<(std::ostream & out, const list_node<T> &o) {
	out << o.get_data();
	return out;
}

#endif
