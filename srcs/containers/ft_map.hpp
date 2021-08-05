/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_map.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/05 09:15:25 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/08/05 20:17:51 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_HPP
# define FT_MAP_HPP

#include "../utils/more.hpp"
#include "../utils/ft_pair.hpp"
#include "../utils/tree_node.hpp"
#include "../iterators/bidirectional_iterator.hpp"

namespace ft {
template < class Key, class T, class Compare = less<Key>, class Alloc = std::allocator<pair<const Key,T> > > 
class map
    {
    public:
       	typedef	Key															key_type; 
		typedef	T															mapped_type; 
		typedef	pair<const key_type, mapped_type>							value_type; 
		typedef	Compare														key_compare; 
		// typedef		Nested function class to compare elements		    	value_compare; 
		typedef	Alloc														allocator_type; 
		typedef	typename allocator_type::reference							reference; 
		typedef	typename allocator_type::const_reference					const_reference; 
		typedef	typename allocator_type::pointer     			    		pointer; 
		typedef	typename allocator_type::const_pointer     					const_pointer; 
 		typedef	bidirectional_iterator <Key, T, T*, T&>						iterator;
		typedef	bidirectional_iterator <Key, T, const T*, const T&>			const_iterator;
		// typedef	reverse_bidirectional_iterator<T, T*, T&>					reverse_iterator;
		// typedef	reverse_bidirectional_iterator<T, const T*, const T&>		const_reverse_iterator;
		typedef	typename ft::iterator_traits<iterator>::difference_type		difference_type;
		typedef size_t		 												size_type;
        typedef	tree_node<Key, T>                                           node;
    private:
    	allocator_type	_alloc;
        key_compare     _compare;
        node            *_root_node;
        size_type       _size;
    
    public:
        explicit map (const key_compare& comp = key_compare(), 
        const allocator_type& alloc = allocator_type()) : _alloc(alloc), _compare(comp), _root_node(nullptr), _size(0) {}

        // template <class InputIterator>
        // map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
        // const allocator_type& alloc = allocator_type(), 
        // typename ft::enable_if<ft::is_iterator<InputIterator>::value >::type* = 0) : 
        // _alloc(alloc), _compare(comp)
        // { //_size
        //     node current;
        //     node newroot;

        //     if (first == last)
        //     {    
        //         _root_node = nullptr;
        //         return;
        //     }
    	// 	_root_node = new node(first.get_key(), first.get_data());
        //     // check if only one node;
        //     current = first++;
        //     newroot = _root_node;
        //     while (current != last)
        //     {
        //         while (key_compare(current.get_key(), newroot.get_key()))
        //         {
        //             if (newroot.left == nullptr)
        //             {
        //                 newroot.left = new node(current.get_key(), current.get_data());
        //                 current++;
        //                 newroot = _root_node;
        //             }
        //             newroot = newroot.left;
        //         }
        //         while (!key_compare(current.get_key(), newroot.get_key()))
        //         {
        //             if (newroot.right == nullptr)
        //             {
        //                 newroot.right = new node(current.get_key(), current.get_data());
        //                 current++;
        //                 newroot = _root_node;
        //             }
        //             newroot = newroot.right;
        //         }
        //     }            
        // }
        // map (const map& x)

        iterator begin()
        {
            iterator ret(_root_node);
            while (ret.left_exists())
                ret--;
            return (ret);
        }

        const_iterator begin() const
        {
            const_iterator ret(_root_node);
            while (ret.left_exists())
                ret--;
            return (ret);
        }

        iterator end() // needs to be one further
        {
            iterator ret(_root_node);
            while (ret.right_exists())
                ret++;
            return (ret);
        }

        const_iterator end() const  // needs to be one further
        {
            const_iterator ret(_root_node);
            while (ret.right_exists())
                ret++;
            return (ret);
        }

        // mapped_type& operator[] (const key_type& k)
        // {
        //     if (_root_node->_key == k)
        //         return   _root_node->_data;
            // else 
            // return NULL;             
            // return ((*((this->insert(make_pair(k,mapped_type()))).first)).second);
        // }

        pair<iterator,bool> insert (const value_type& val)
        {
            if (_root_node == nullptr)
            {
                _root_node = new node(val.first, val.second);
                iterator ity(_root_node);
                return (make_pair(ity, true));
            }
            iterator ity(_root_node);
            node *current_root = _root_node;
            while (current_root)
            {
                if (val.first == current_root->first)
                    break ;
                else if (val.first < current_root->first)
                {
                    if (current_root->get_left() == nullptr)
                    {
                        current_root->_left = new node(val.first, val.second);
                        std::cout << "val.first [" << val.first << "] added as the left of " << current_root->first << std::endl;
                        return (make_pair(ity, true));
                    }
                    current_root = current_root->get_left();
                }
                else
                {
                    if (current_root->get_right() == nullptr)
                    {
                        current_root->_left = new node(val.first, val.second);
                        std::cout << "val.first [" << val.first << "] added as the right of " << current_root->first << std::endl;
                        return (make_pair(ity, true));
                    }
                    current_root = current_root->get_right();
                }
            }
            
    		// _root_node = new node(first.get_key(), first.get_data());
            // // check if only one node;
            // current = first++;
            // newroot = _root_node;
            // while (current != last)
            // {
            //     while (key_compare(current.get_key(), newroot.get_key()))
            //     {
            //         if (newroot.left == nullptr)
            //         {
            //             newroot.left = new node(current.get_key(), current.get_data());
            //             current++;
            //             newroot = _root_node;
            //         }
            //         newroot = newroot.left;
            //     }
            //     while (!key_compare(current.get_key(), newroot.get_key()))
            //     {
            //         if (newroot.right == nullptr)
            //         {
            //             newroot.right = new node(current.get_key(), current.get_data());
            //             current++;
            //             newroot = _root_node;
            //         }
            //         newroot = newroot.right;
            //     }
            // }            
            return (make_pair(ity, true));
        }
    };
}      

#endif
