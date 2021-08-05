/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bidirectional_iterator.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/05 14:24:39 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/08/05 20:22:57 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

#include "../utils/tree_node.hpp"
#include <iostream>

namespace ft {
template <typename Key, typename T, typename P, typename R>
class bidirectional_iterator
{
    public:
		typedef std::bidirectional_iterator_tag	iterator_category;
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef R								reference;
		typedef P								pointer;
		typedef	tree_node<Key, T>				node;
		typedef tree_node<Key, T>*				node_ptr;

    	node_ptr operator->() { return _tree_node; }
    	bidirectional_iterator& operator++() { _tree_node = _tree_node->get_right(); return *this; }
    	bidirectional_iterator operator++(int) { bidirectional_iterator tmp = *this; _tree_node = _tree_node->get_right(); return tmp; }
		bidirectional_iterator& operator--() {_tree_node = _tree_node->get_left(); return *this; }
    	bidirectional_iterator operator--(int) {bidirectional_iterator tmp = *this; _tree_node = _tree_node->get_left(); return tmp; }
		bool operator!=(const bidirectional_iterator& rhs) { return _tree_node != rhs._tree_node; }
		bool operator==(const bidirectional_iterator& rhs) { return _tree_node == rhs._tree_node; }		
		bidirectional_iterator() : _tree_node(nullptr) {}
		bidirectional_iterator(node_ptr source) : _tree_node(source) {}
		bidirectional_iterator & operator=(const bidirectional_iterator& source)
		{
			if (_tree_node != source._tree_node)
				_tree_node = source._tree_node;
			return *this;
		}
		bidirectional_iterator(const bidirectional_iterator & source) // check this
		{
			_tree_node = node_ptr(source._tree_node);
		}
		~bidirectional_iterator() {}
		value_type get_data() const {return(_tree_node->_data);}
		value_type get_key() const {return(_tree_node->_key);}
		bool left_exists() const {if (_tree_node->_left != nullptr) return true; return false;}
		bool right_exists() const {if (_tree_node->get_right() != nullptr) return true; return false;}
		node * get_tree_node() const {return(_tree_node);}

		node	*_tree_node;
    };
}

#endif
