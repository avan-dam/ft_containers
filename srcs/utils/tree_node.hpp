/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tree_node.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/05 13:21:47 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/08/11 14:19:54 by ambervandam   ########   odam.nl         */
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
        bool                        _end_node;
    
        tree_node(node_ptr parent) : first(), second(), _left(nullptr), _right(nullptr), _parent(parent), _end_node(false) {}
        tree_node(Key key, T data, node_ptr parent) : first(key), second(data), _left(nullptr), _right(nullptr), _parent(parent), _end_node(false) {}
        tree_node(const tree_node & source) : first(source.first), second(source.second), _left(source._left), _right(source._right), _parent(source.parent), _end_node(source._end_node) {}
        tree_node & operator=(const tree_node & source)
		{
			if (this != source)
			{
				first   = source.first;
				second  = source.second;
				_left   = source._left;
				_right  = source._right;
                _parent = source._parent;
                _end_node = source._end_node;
			}
			return *this;
		}
        ~tree_node() {
        // if (_left)
        //     delete [] _left;
        // if (_right)
        //     delete [] _right;
        // if (_parent)
        //     delete [] _parent;
        // _left = nullptr;        
        }

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
		// T           getsecond() const {return (second);}

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
