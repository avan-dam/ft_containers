/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tree_node.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/05 13:21:47 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/08/05 22:55:30 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_NODE_HPP
# define TREE_NODE_HPP

#include <iostream>

template <class Key, class T>
class tree_node
{
    public:
		typedef	tree_node<Key, T>	node;
		typedef tree_node<Key, T>*	node_ptr;
        
        // member variables
        Key                         first;
        T				            second;
        node_ptr	                _left;
        node_ptr	                _right;
        node_ptr	                _parent;
    
        tree_node() : first(), second(), _left(nullptr), _right(nullptr), _parent(nullptr) {}
        tree_node(Key key, T data, node_ptr parent) : first(key), second(data), _left(nullptr), _right(nullptr), _parent(parent) {}
        tree_node(const tree_node & source) : first(source.first), second(source.second), _left(source._left), _right(source._right), _parent(source.parent) {}
        tree_node & operator=(const tree_node & source)
		{
			if (this != source)
			{
				first   = source.first;
				second  = source.second;
				_left   = source._left;
				_right  = source._right;
                _parent = source._parent;
			}
			return *this;
		}
        ~tree_node() {}

        node_ptr get_left()     {   return (_left); }
        node_ptr get_right()    {   return (_right); }
        node_ptr get_parent()   {   return (_parent); }
		T getsecond() const {return (second);}

		bool operator==(const tree_node & rhs)
        {
            if (first == rhs.first && second == rhs.second && _left == rhs._left && _right == rhs._right && _parent == rhs._parent)
                return (true);
            return (false);
        }
		bool operator!=(const tree_node & rhs)
        {
            if (first == rhs.first && second == rhs.second && _left == rhs._left && _right == rhs._right && _parent == rhs._parent)
                return (false);
            return (true); 
        }

        // void    change_content(T newdata)
        // {
        //     data = newdata;
        //     return;
        // }
};

# endif
