/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bidirectional_iterator.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/05 14:24:39 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/08/26 14:53:26 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

#include "../utils/tree_node.hpp"
#include "../containers/ft_map.hpp"
#include <iostream>

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

        operator const_type() const {   return const_type(_tree_node);  }   /* for casting to const */
        pointer operator->()        {   return &(_tree_node->_data);    }
        reference operator*()       {   return (_tree_node->_data);     }
    
        bidirectional_iterator& operator++() 
        {  
            node_ptr p;
            if (_tree_node == nullptr)
            {
                // if null go to first node
                while (_tree_node->_left != nullptr && _tree_node->_left->_start_node == false)
                    _tree_node = _tree_node->_left; 
            }
            else if (_tree_node->_right != nullptr)
            {
                // furthest left node of right subtree
                _tree_node = _tree_node->_right;
                while (_tree_node->_left != nullptr)
                    _tree_node = _tree_node->_left;
            }
            else
            {
                //  already processed the left subtree, and no right subtree. go to parent
                // which _tree_node is a left child, stop if parent ==null a non-NULL parent
                // is the successor. if parent is NULL, the original node
                // was the last node inorder, and its successor is the end of the list
                p = _tree_node->_parent;
                while (p != nullptr && _tree_node == p->_right)
                {
                    _tree_node = p;
                    p = p->_parent;
                }
                // if we were previously at the right-most node in
                // the tree, _tree_node = nullptr, and iterator is end of the list
                _tree_node = p;
            }
        return *this;
    }

        bidirectional_iterator operator++(int)
        {
            bidirectional_iterator tmp = *this;
            node_ptr p;
            if (_tree_node == nullptr)
            {
                while (_tree_node->_left != nullptr && _tree_node->_left->_start_node == false)
                    _tree_node = _tree_node->_left; 
            }
            else if (_tree_node->_right != nullptr)
            {
                _tree_node = _tree_node->_right;
                while (_tree_node->_left != nullptr)
                  _tree_node = _tree_node->_left;
            }
            else
            {
                p = _tree_node->_parent;
                while (p != nullptr && _tree_node == p->_right)
                {
                    _tree_node = p;
                    p = p->_parent;
                }
                _tree_node = p;
            }
            return tmp; 
        }
        bidirectional_iterator& operator--() 
        {
            node_ptr p;
            if (_tree_node == nullptr)
            {
                while (_tree_node->_right != nullptr && _tree_node->_right->_end_node == false)
                    _tree_node = _tree_node->_right; 
            }
            else if (_tree_node->_left != nullptr)
            {
                _tree_node = _tree_node->_left;
                while (_tree_node->_right != nullptr)
                    _tree_node = _tree_node->_right;
            }
            else
            {
                p = _tree_node->_parent;
                while (p != nullptr && _tree_node == p->_left)
                {
                    _tree_node = p;
                    p = p->_parent;
                }
                // if we were previously at the right-most node in
                // the tree, _tree_node = nullptr, and iterator is end of the list
                _tree_node = p;
            }
        return *this;
        }
            
        bidirectional_iterator operator--(int) {
            bidirectional_iterator tmp = *this; 
            node_ptr p;
            if (_tree_node == nullptr)
            {
                while (_tree_node->_right != nullptr && _tree_node->_right->_end_node == false)
                    _tree_node = _tree_node->_right; 
            }
            else if (_tree_node->_left != nullptr)
            {
                _tree_node = _tree_node->_left;
                while (_tree_node->_right != nullptr)
                    _tree_node = _tree_node->_right;
            }
            else
            {
                p = _tree_node->_parent;
                while (p != nullptr && _tree_node == p->_left)
                {
                    _tree_node = p;
                    p = p->_parent;
                }
                // if we were previously at the right-most node in
                // the tree, _tree_node = nullptr, and iterator is end of the list
                _tree_node = p;
            }
            return tmp; 
            }

        bool operator!=(const bidirectional_iterator& rhs) { return _tree_node != rhs._tree_node; }
        bool operator==(const bidirectional_iterator& rhs) { return _tree_node == rhs._tree_node; }     
        bidirectional_iterator() : _tree_node(nullptr) {}
        bidirectional_iterator(const node_ptr source) : _tree_node(source) {}
        bidirectional_iterator & operator=(const bidirectional_iterator& source)
        {
            if (_tree_node != source._tree_node)
                _tree_node = source._tree_node;
            return *this;
        }
        bidirectional_iterator(bidirectional_iterator const & source) : _tree_node(node_ptr(source._tree_node)) {}
        ~bidirectional_iterator() {}
    
    private:
        node_ptr    _tree_node;
    };

template <typename T, typename P, typename R>
class reverse_bidirectional_iterator
    {
    public:
        typedef std::bidirectional_iterator_tag                         iterator_category;
        typedef ptrdiff_t                                               difference_type;
        typedef T                                                       value_type;
        typedef R                                                       reference;
        typedef P                                                       pointer;
        typedef tree_node<T>                                            node;
        typedef tree_node<T>*                                           node_ptr;
        typedef tree_node<T>&                                           node_ref;
        typedef reverse_bidirectional_iterator<T, const T*, const T&>   const_type;

        operator const_type() const { return const_type(_tree_node); }  /* for casting to const */
        pointer operator->() {      return (&_tree_node->_data);    }
        reference operator*() {     return _tree_node->_data;   }
            
        reverse_bidirectional_iterator& operator--() 
        {
            node_ptr p;
            if (_tree_node == nullptr)
            {
                // if null go to first node
                while (_tree_node->_left != nullptr && _tree_node->_left->_start_node == false)
                    _tree_node = _tree_node->_left; 
            }
            else if (_tree_node->_right != nullptr)
            {
                // furthest left node of right subtree
                _tree_node = _tree_node->_right;
                while (_tree_node->_left != nullptr)
                    _tree_node = _tree_node->_left;
            }
            else
            {
                p = _tree_node->_parent;
                while (p != nullptr && _tree_node == p->_right)
                {
                    _tree_node = p;
                    p = p->_parent;
                }
                _tree_node = p;
            }
        return *this;
        }
        reverse_bidirectional_iterator operator--(int) {
            reverse_bidirectional_iterator tmp = *this;
            node_ptr p;
            if (_tree_node == nullptr)
            {
                // if null go to first node
                while (_tree_node->_left != nullptr && _tree_node->_left->_start_node == false)
                    _tree_node = _tree_node->_left; 
            }
            else if (_tree_node->_right != nullptr)
            {
                // furthest left node of right subtree
                _tree_node = _tree_node->_right;
                while (_tree_node->_left != nullptr)
                    _tree_node = _tree_node->_left;
            }
            else
            {
                p = _tree_node->_parent;
                while (p != nullptr && _tree_node == p->_right)
                {
                    _tree_node = p;
                    p = p->_parent;
                }
                _tree_node = p;
            }
            return tmp; 
            }
        reverse_bidirectional_iterator& operator++() {
            node_ptr p;
            if (_tree_node == nullptr)
            {
                while (_tree_node->_right != nullptr && _tree_node->_right->_end_node == false)
                    _tree_node = _tree_node->_right; 
            }
            else if (_tree_node->_left != nullptr)
            {
                _tree_node = _tree_node->_left;
                while (_tree_node->_right != nullptr)
                    _tree_node = _tree_node->_right;
            }
            else
            {
                p = _tree_node->_parent;
                while (p != nullptr && _tree_node == p->_left)
                {
                    _tree_node = p;
                    p = p->_parent;
                }
                _tree_node = p;
            }
            return *this;
            }
            
        reverse_bidirectional_iterator operator++(int) {
            reverse_bidirectional_iterator tmp = *this; 
             node_ptr p;
            if (_tree_node == nullptr)
            {
                while (_tree_node->_right != nullptr && _tree_node->_right->_end_node == false)
                    _tree_node = _tree_node->_right; 
            }
            else if (_tree_node->_left != nullptr)
            {
                _tree_node = _tree_node->_left;
                while (_tree_node->_right != nullptr)
                    _tree_node = _tree_node->_right;
            }
            else
            {
                p = _tree_node->_parent;
                while (p != nullptr && _tree_node == p->_left)
                {
                    _tree_node = p;
                    p = p->_parent;
                }
                // if we were previously at the right-most node in
                // the tree, _tree_node = nullptr, and iterator is end of the list
                _tree_node = p;
            }
            return tmp; 
            }


        bool operator!=(const reverse_bidirectional_iterator& rhs) { return _tree_node != rhs._tree_node; }
        bool operator==(const reverse_bidirectional_iterator& rhs) { return _tree_node == rhs._tree_node; }     
        reverse_bidirectional_iterator() : _tree_node(nullptr) {}
        reverse_bidirectional_iterator(const node_ptr source) : _tree_node(source) {}
        reverse_bidirectional_iterator & operator=(const reverse_bidirectional_iterator& source)
        {
            if (_tree_node != source._tree_node)
                _tree_node = source._tree_node;
            return *this;
        }
        reverse_bidirectional_iterator(reverse_bidirectional_iterator const & source) : _tree_node(node_ptr(source._tree_node)) {}
        ~reverse_bidirectional_iterator() {}
    
    private:
        node_ptr    _tree_node;
    };
}



#endif

