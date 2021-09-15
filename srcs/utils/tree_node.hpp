/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tree_node.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/05 13:21:47 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/09/15 23:12:54 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_NODE_HPP
# define TREE_NODE_HPP

#include <iostream>

template <class T>
class tree_node
{
    public:
		typedef	tree_node<T>	    node;
		typedef tree_node<T>*	    node_ptr;
        typedef T                   value_type;
        typedef T&                  reference;
        typedef T*                  pointer;
        /* member variables */
        value_type                  _data;
        node_ptr	                _left;
        node_ptr	                _right;
        node_ptr	                _parent;
        bool                        _end_node;
        long                        _height; // out?
    
        tree_node() : _data(), _left(NULL), _right(NULL), _parent(NULL), _end_node(false), _height(0) {}
        tree_node(T data) : _data(data), _left(NULL), _right(NULL), _parent(NULL), _end_node(false), _height(0) {}
        tree_node(const tree_node & source) : _data(source._data), _left(source._left), _right(source._right), _parent(source._parent), _end_node(source._end_node), _height(source.height) {}
        tree_node & operator=(const tree_node & source)
		{
			if (this != source)
			{
				_data   = source._data;
				_left   = source._left;
				_right  = source._right;
                _parent = source._parent;
                _end_node = source._end_node;
                _height = source._height;
			}
			return *this;
		}

        tree_node & operator=(tree_node & source)
		{
			if (this != source)
			{
				_data   = source._data;
				_left   = source._left;
				_right  = source._right;
                _parent = source._parent;
                _end_node = source._end_node;
                _height = source._height;
			}
			return *this;
		}

        ~tree_node() {}

		bool operator==(const tree_node & rhs)
        {
            if (_data == rhs._data && _left == rhs._left && _right == rhs._right && _parent == rhs._parent && _end_node == rhs._end_node && _height == rhs._height)
                return (true);
            return (false);
        }
		bool operator!=(const tree_node & rhs)
        {
            if (_data == rhs._data && _left == rhs._left && _right == rhs._right && _parent == rhs._parent && _end_node == rhs._end_node && _height == rhs._height)
                return (false);
            return (true); 
        }
};


# endif
