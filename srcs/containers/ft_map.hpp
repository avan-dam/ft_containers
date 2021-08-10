/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_map.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/05 09:15:25 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/08/10 15:51:53 by ambervandam   ########   odam.nl         */
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
        typedef	tree_node<Key, T>*                                           node_ptr;
    private:
    	allocator_type	_alloc;
        key_compare     _compare;
        node_ptr        _root_node;
        size_type       _size;
    
    public:
        explicit map (const key_compare& comp = key_compare(), 
        const allocator_type& alloc = allocator_type()) : _alloc(alloc), _compare(comp), _size(0) 
        {
            _root_node = new node(nullptr);
        }

        // typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
        template <class InputIterator>
        map (InputIterator first, InputIterator last,
        const key_compare& comp = key_compare(),
        const allocator_type& alloc = allocator_type(),
        typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
        : _alloc(alloc), _compare(comp)
        {
	        for (InputIterator it = first; it!=last; ++it)
            {   
                ft::pair<Key, T> p = ft::make_pair(it->first, it->second); 
                insert(p);
            }
        }

        map (const map& x)
        {
            for (typename ft::map<Key,T>::const_iterator it = x.begin(); it!=x.end(); ++it)
            {   
                ft::pair<Key, T> p = ft::make_pair(it->first, it->second); 
                insert(p);
            }
        }
        
        // ~map()
        // {
        //     clear();
        // }

        iterator        begin()
        {
            node_ptr _current_node = _root_node;
            while (_current_node->_left != nullptr)
                _current_node = _current_node->_left;
            iterator ret(_current_node);
            return (ret);
        }

        const_iterator  begin() const
        {
            node_ptr _current_node = _root_node;
            while (_current_node->_left != nullptr)
                _current_node = _current_node->_left;
            const_iterator ret(_current_node);
            return (ret);
        }

        iterator        end()
        {
            node_ptr _current_node = _root_node;
            while (_current_node->_right != nullptr)
                _current_node = _current_node->_right;
            iterator ret(_current_node);
            return (ret);
        }

        const_iterator  end() const
        {
            node_ptr _current_node = _root_node;
            while (_current_node->_right != nullptr)
                _current_node = _current_node->_right;
            const_iterator ret(_current_node);
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


        // capacity
        size_type size() const
        {
            size_type   ret;

            ret = 0;
            for (typename ft::map<Key,T>::const_iterator it = begin(); it!=end(); ++it)
                ret++;
            return (ret);
        }

        bool empty() const
        {
            if (size() == 0)
                return (true);
            return (false);
        }

        // modifiers
        pair<iterator,bool> insert (const value_type& val)
        {
            // if key already in map then do something?? use key_comp
            if (_root_node == nullptr || _root_node->_end_node == true)
            {
                _root_node = new node(val.first, val.second, nullptr);
                _root_node->_right = new node(_root_node);
                _root_node->_right->_end_node = true;
                iterator ity(_root_node);
                return (make_pair(ity, true));
            }
            iterator ity(_root_node);
            node_ptr current_root = _root_node;
            while (current_root != nullptr)
            {
                if (_compare(val.first, current_root->first))
                {
                    if (current_root->get_left() == nullptr)
                    {
                        current_root->_left = new node(val.first, val.second, current_root);
                        current_root = current_root->get_left();
                        return (make_pair(ity, true));
                    }
                    current_root = current_root->get_left();
                }
                else
                {
                    if (current_root->get_right() == nullptr || current_root->get_right()->is_end_node() == true)
                    {
                        if (current_root->get_right() == nullptr)
                            current_root->_right = new node(val.first, val.second, current_root);
                        else 
                        {
                            current_root = current_root->_right;
                            current_root->first = val.first;
                            current_root->second = val.second;
                            current_root->_end_node = false;
                            current_root->_right = new node (current_root);
                            current_root->_right->_end_node = true;
                        }
                        return (make_pair(ity, true));
                    }
                    current_root = current_root->get_right();
                }
            }       
            return (make_pair(ity, true));
        }


        // void    clear()
        // {
        //     node_ptr start = *(begin());
        //     (void)start;
        // }
    };
}      

#endif
