/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bidirectional_iterator.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/05 14:24:39 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/09/21 17:19:15 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

namespace ft {
template <typename T, typename P, typename R>
class bidirectional_iterator
{
    public:
        typedef std::bidirectional_iterator_tag iterator_category;
        typedef ptrdiff_t                       difference_type;
        typedef T                               value_type;
        typedef R                               reference;
        typedef P                               pointer;
        typedef tree_node<T>                    node;
        typedef tree_node<T>*                   node_ptr;
        typedef tree_node<T>&                   node_ref;
        typedef bidirectional_iterator<T, const T*, const T&>   const_type;

        operator const_type() const {   return const_type(_node);  }   /* for casting to const */
        pointer operator->()        {   return &(_node->_data);    }
        reference operator*()       {   return (_node->_data);     }

        bidirectional_iterator& operator++() 
        {  
            node_ptr p;
            if (_node == NULL)
            {
                /* if null go to first node */
                while (_node->_left != NULL)// && _node->_left->_start_node == false)
                    _node = _node->_left; 
            }
            else if (_node->_right != NULL)
            {
                /* furthest left node of right subtree */
                _node = _node->_right;
                while (_node->_left != NULL)
                    _node = _node->_left;
            }
            else
            {
                /*  already processed the left subtree, and no right subtree. go to parent */
                /* which _node is a left child, stop if parent ==null a non-NULL parent */
                /* is the successor. if parent is NULL, the original node */
                /* was the last node inorder, and its successor is the end of the list */
                p = _node->_parent;
                while (p != NULL && _node == p->_right)
                {
                    _node = p;
                    p = p->_parent;
                }
                /* if we were previously at the right-most node in */
                /* the tree, _node = NULL, and iterator is end of the list */
                _node = p;
            }
        return *this;
    }

        bidirectional_iterator operator++(int)
        {
            bidirectional_iterator tmp = *this;
            node_ptr p;
            if (_node == NULL)
            {
                while (_node->_left != NULL)// && _node->_left->_start_node == false)
                    _node = _node->_left; 
            }
            else if (_node->_right != NULL)
            {
                _node = _node->_right;
                while (_node->_left != NULL)
                  _node = _node->_left;
            }
            else
            {
                p = _node->_parent;
                while (p != NULL && _node == p->_right)
                {
                    _node = p;
                    p = p->_parent;
                }
                _node = p;
            }
            return tmp; 
        }
        bidirectional_iterator& operator--() 
        {
            node_ptr p;
            if (_node == NULL)
            {
                while (_node->_right != NULL && _node->_right->_end_node == false)
                    _node = _node->_right; 
            }
            else if (_node->_left != NULL)
            {
                _node = _node->_left;
                while (_node->_right != NULL)
                    _node = _node->_right;
            }
            else
            {
                p = _node->_parent;
                while (p != NULL && _node == p->_left)
                {
                    _node = p;
                    p = p->_parent;
                }
                /* if we were previously at the right-most node in */
                /* the tree, _node = NULL, and iterator is end of the list */
                _node = p;
            }
        return *this;
        }
            
        bidirectional_iterator operator--(int) {
            bidirectional_iterator tmp = *this; 
            node_ptr p;
            if (_node == NULL)
            {
                while (_node->_right != NULL && _node->_right->_end_node == false)
                    _node = _node->_right; 
            }
            else if (_node->_left != NULL)
            {
                _node = _node->_left;
                while (_node->_right != NULL)
                    _node = _node->_right;
            }
            else
            {
                p = _node->_parent;
                while (p != NULL && _node == p->_left)
                {
                    _node = p;
                    p = p->_parent;
                }
                /* if we were previously at the right-most node in */
                /* the tree, _node = NULL, and iterator is end of the list */
                _node = p;
            }
            return tmp; 
            }

        bool operator!=(const bidirectional_iterator& rhs) { return _node != rhs._node; }
        bool operator==(const bidirectional_iterator& rhs) { return _node == rhs._node; }     
        bidirectional_iterator() : _node(NULL) {}
        bidirectional_iterator(const node_ptr source) : _node(source) {}
        bidirectional_iterator & operator=(const bidirectional_iterator& source)
        {
            if (_node != source._node)
                _node = source._node;
            return *this;
        }
        bidirectional_iterator(bidirectional_iterator const & source) : _node(node_ptr(source._node)) {}
        ~bidirectional_iterator() {}

        node_ptr    _node;
    };
}

#endif

