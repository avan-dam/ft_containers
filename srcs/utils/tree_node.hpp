/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tree_node.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/05 13:21:47 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/08/05 18:53:10 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_NODE_HPP
# define TREE_NODE_HPP

#include <iostream>

template <class Key, class T>
class tree_node
{
    public:
        // member variables
        Key                 first;
        T				    second;
        tree_node<Key, T>*	_left;
        tree_node<Key, T>*	_right;
    
        // tree_node() : first(), second(), _left(nullptr), _right(nullptr) {}
        tree_node(Key key, T data) : first(key), second(data), _left(nullptr), _right(nullptr) {}
        tree_node(const tree_node & source) : first(source.first), second(source.second), _left(source._left), _right(source._right) {}
        tree_node & operator=(const tree_node & source)
		{
			if (this != source)
			{
				first = source.first;
				second = source.second;
				_left = source._left;
				_right = source._right;
			}
			return *this;
		}
        ~tree_node() {}

        tree_node<Key, T>* get_left() {
        if (_left)
            return (_left); 
        return (nullptr);
        }
        tree_node<Key, T>* get_right() {
        if (_right)
            return (_right);
        return (nullptr);
        }
		T getsecond() const {return (second);}

		bool operator==(const tree_node & rhs)
        {
            if (first == rhs.first && second == rhs.second && _left == rhs._left && _right == rhs._right)
                return (true);
            return (false);
        }
		bool operator!=(const tree_node & rhs)
        {
            if (first == rhs.first && second == rhs.second && _left == rhs._left && _right == rhs._right)
                return (false);
            return (true); 
        }

        // void    change_content(T newdata)
        // {
        //     data = newdata;
        //     return;
        // }
};

template<class Key, class T>
std::ostream& operator<<(std::ostream & out, const tree_node<Key, T> &o) {
	out << o.getsecond();
	return out;
}

# endif
