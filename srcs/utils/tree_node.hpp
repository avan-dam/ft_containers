/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tree_node.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/05 13:21:47 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/08/12 10:59:42 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_NODE_HPP
# define TREE_NODE_HPP

#include <iostream>

template <class T>
class tree_node
{
    public:
		typedef	tree_node<T>	node;
		typedef tree_node<T>*	node_ptr;
        typedef T                   value_type;
        typedef T&                  reference;
        typedef T*                  pointer;
        // member variables
        value_type                  _data;
        node_ptr	                _left;
        node_ptr	                _right;
        node_ptr	                _parent;
        bool                        _end_node;
        bool                        _start_node;
    
        tree_node(node_ptr parent) : _data(), _left(nullptr), _right(nullptr), _parent(parent), _end_node(false), _start_node(false) {}
        tree_node(T data, node_ptr parent) : _data(data), _left(nullptr), _right(nullptr), _parent(parent), _end_node(false), _start_node(false) {}
        tree_node(const tree_node & source) : _data(source._data), _left(source._left), _right(source._right), _parent(source._parent), _end_node(source._end_node), _start_node(source._start_node) {}
        tree_node & operator=(const tree_node & source)
		{
			if (this != source)
			{
				_data   = source._data;
				_left   = source._left;
				_right  = source._right;
                _parent = source._parent;
                _end_node = source._end_node;
                _start_node = source._start_node;
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
                _start_node = source._start_node;
			}
			return *this;
		}

        ~tree_node() {}

		// reference operator*() const { return (*_data); }
    	// pointer operator->() { return (&_data); }

        node_ptr    get_left()      
        {   
            if (_left)
                return (_left);    
            return (nullptr); 
        }
        node_ptr    get_right()
        {   
            if (_right)
                return (_right);  
            return (nullptr);   
        }
        node_ptr    get_parent()    
        {   
            if (_parent) 
                return (_parent);   
            return (nullptr);
        }
        bool        is_end_node()  
        {
            if (_end_node)
                return (_end_node);
            return (false);
        }

        bool        is_start_node()  
        {
            if (_start_node)
                return (_start_node);
            return (false);
        }
		// T           getsecond() const {return (second);}

		bool operator==(const tree_node & rhs)
        {
            if (_data == rhs._data && _left == rhs._left && _right == rhs._right && _parent == rhs._parent && _end_node == rhs._end_node && _start_node == rhs._start_node)
                return (true);
            return (false);
        }
		bool operator!=(const tree_node & rhs)
        {
            if (_data == rhs._data && _left == rhs._left && _right == rhs._right && _parent == rhs._parent && _end_node == rhs._end_node && _start_node == rhs._start_node)
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
