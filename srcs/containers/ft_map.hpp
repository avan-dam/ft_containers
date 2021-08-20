/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_map.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/05 09:15:25 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/08/20 12:51:48 by ambervandam   ########   odam.nl         */
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
       	typedef	Key													                        		key_type; 
		typedef	T														                        	mapped_type; 
		typedef	pair<const key_type, mapped_type>						                        	value_type; 
		typedef	Compare														                        key_compare; 
		typedef	Alloc														                        allocator_type; 
		typedef	typename allocator_type::reference							                        reference; 
		typedef	typename allocator_type::const_reference					                        const_reference; 
		typedef	typename allocator_type::pointer     			    		                        pointer; 
		typedef	typename allocator_type::const_pointer     					                        const_pointer; 
 		typedef	bidirectional_iterator <value_type, value_type*, value_type&>						iterator;
		typedef	bidirectional_iterator <value_type, const value_type*, const value_type&>			const_iterator;
		typedef	reverse_bidirectional_iterator<value_type, value_type*, value_type&>				reverse_iterator;
		typedef	reverse_bidirectional_iterator<value_type, const value_type*, const value_type&>    const_reverse_iterator;
		typedef	typename ft::iterator_traits<iterator>::difference_type		                        difference_type;
		typedef size_t		 												                        size_type;
        typedef	tree_node<value_type>                                                               node;
        typedef	tree_node<value_type>*                                                              node_ptr;
    
    // INNER CLASS VALUE COMPARE 
    class value_compare : std::binary_function<value_type,value_type,bool>
    {   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
            friend class map;
        protected:
            Compare comp;
            value_compare (Compare c) : comp(c) {} 
            // constructed with map's comparison object
        public:
            typedef bool result_type;
            typedef value_type first_argument_type;
            typedef value_type second_argument_type;
            bool operator() (const value_type& x, const value_type& y) const
            {
                return comp(x.first, y.first);
            }
    };

    private:
    	allocator_type	_alloc;
        key_compare     _compare;
        node_ptr        _root_node;
        size_type       _size;

    public:
        /* constructors */
        explicit map (const key_compare& comp = key_compare(), 
        const allocator_type& alloc = allocator_type()) : _alloc(alloc), _compare(comp), _size(0) 
        {
            _root_node = new node(nullptr);
            _root_node->_end_node = true;
            _root_node->_start_node = true;
        }

        template <class InputIterator>
        map (InputIterator first, InputIterator last,
        const key_compare& comp = key_compare(),
        const allocator_type& alloc = allocator_type(),
        typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
        : _alloc(alloc), _compare(comp)
        {
            _root_node = nullptr;
	        for (InputIterator it = first; it!=last; ++it)
            {
                ft::pair<Key, T> p = ft::make_pair(it->first, it->second); 
                insert(p);
            }
        }

        map (const map& x)
        {
            _root_node = nullptr;
            for (typename ft::map<Key,T>::const_iterator it = x.begin(); it!=x.end(); ++it)
            {   
                ft::pair<Key, T> p = ft::make_pair(it->first, it->second); 
                insert(p);
            }
        }
        
        ~map()
        {
            clear();
        }

        map& operator= (const map& x)
        {
            clear();
            for (typename ft::map<Key,T>::const_iterator it = x.begin(); it!=x.end(); ++it)
            {   
                ft::pair<Key, T> p = ft::make_pair(it->first, it->second); 
                insert(p);
            }
        }

        /* iterators */
        iterator        begin()
        {
            node_ptr _current_node = _root_node;
            while (_current_node->_left != nullptr && _current_node->_left->_start_node == false)
                _current_node = _current_node->_left;
            iterator ret(_current_node);
            return (ret);
        }

        const_iterator  begin() const
        {
            node_ptr _current_node = _root_node;
            while (_current_node->_left != nullptr && _current_node->_left->_start_node == false)
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

        reverse_iterator rbegin()
        {
            node_ptr _current_node = _root_node;
            while (_current_node->_right != nullptr && _current_node->_right->_end_node == false)
                _current_node = _current_node->_right;
            reverse_iterator ret(_current_node);
            return (ret);
        }

        const_reverse_iterator rbegin() const
        {
            node_ptr _current_node = _root_node;
            while (_current_node->_right != nullptr && _current_node->_right->_end_node == false)
                _current_node = _current_node->_right;
            const_reverse_iterator ret(_current_node);
            return (ret);
        }

        reverse_iterator rend()
        {
            node_ptr _current_node = _root_node;
            while (_current_node->_left != nullptr)
                _current_node = _current_node->_left;
            reverse_iterator ret(_current_node);
            return (ret);    
        }
        const_reverse_iterator rend() const
        {
            node_ptr _current_node = _root_node;
            while (_current_node->_left != nullptr)
                _current_node = _current_node->_left;
            const_reverse_iterator ret(_current_node);
            return (ret);    
        }

        /* capacity */
        size_type size() const
        {
            size_type   ret;

            ret = 0;
            // std::cout << "here" << std::endl;
            if (_root_node == nullptr)
                return (ret);
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

       	size_type max_size() const { return _alloc.max_size(); }

        /* element accessors */
        mapped_type& operator[] (const key_type& k)
        {           
            return ((*((this->insert(ft::make_pair(k,mapped_type()))).first)).second);
        }

        /* modifiers */
        pair<iterator,bool> insert (const value_type& val)
        {
            iterator ret;
            if (_root_node == nullptr || _root_node->_end_node == true)
            {
                _root_node = new node(val, nullptr);
                _root_node->_right = new node(_root_node);
                _root_node->_right->_end_node = true;
                _root_node->_left = new node(_root_node);
                _root_node->_left->_start_node = true;
                iterator ity = begin();
                ft::pair<iterator, bool>  p(ity, true);
                return (p);
            }
            iterator ity = begin();
            ft::pair<iterator, bool> p(ity, true);
            if (find(val.first) != end()) // if a node with that key already exists do not insert a new one
                return (ft::pair<iterator, bool> (find(val.first), false));
            node_ptr current_root = _root_node;
            while (current_root != nullptr)
            {
                if (_compare(val.first, current_root->_data.first))
                {
                    if (current_root->get_left() == nullptr || current_root->get_left()->is_start_node() == true)
                    {
                        if (current_root->get_left() == nullptr)
                        {    
                            current_root->_left = new node(val, current_root);
                            ret = iterator(current_root->_left);
                            return (ft::pair<iterator, bool>(ret, true));
                        }
                        else
                        {
                            node_ptr old = current_root->_left;
                            delete (old);
                            current_root->_left = new node(val, current_root);
                            // ret = iterator(current_root->_left);
                            current_root = current_root->_left;
                            current_root->_start_node = false;
                            current_root->_left = new node (current_root);
                            current_root = current_root->_left;
                            current_root->_start_node = true;
                            return (ft::pair<iterator, bool>((iterator)current_root, true));
                        }
                        // return (make_pair<iterator, bool>(ret, true));
                    }
                    current_root = current_root->get_left();
                }
                else
                {
                    if (current_root->get_right() == nullptr || current_root->get_right()->is_end_node() == true)
                    {
                        if (current_root->get_right() == nullptr)
                        {    
                            current_root->_right = new node(val, current_root);
                            ret = iterator(current_root->_right);
                        }
                        else 
                        {
                            node_ptr old = current_root->_right;
                            delete (old);
                            current_root->_right = new node(val, current_root);
                            ret = iterator(current_root->_right);
                            current_root = current_root->_right;
                            current_root->_end_node = false;
                            current_root->_right = new node (current_root);
                            current_root = current_root->_right;
                            current_root->_end_node = true;
                        }
                        return (ft::pair<iterator, bool> (ret, true));
                    }
                    current_root = current_root->get_right();
                }
            }      
            return (p);
        }

        iterator insert (iterator position, const value_type& val)
        {
            iterator ret;
            if (_root_node == nullptr || _root_node->_end_node == true)
            {
                _root_node = new node(val, nullptr);
                _root_node->_right = new node(_root_node);
                _root_node->_right->_end_node = true;
                _root_node->_left = new node(_root_node);
                _root_node->_left->_start_node = true;
                return (begin());
            }
            iterator ity = begin();
            if (find(val.first) != end()) // if a node with that key already exists do not insert a new one
                return (find(val.first));
            node_ptr current_root = position.get_node();
            while (current_root != nullptr)
            {
                if (_compare(val.first, current_root->_data.first))
                {
                    if (current_root->get_left() == nullptr || current_root->get_left()->is_start_node() == true)
                    {
                        if (current_root->get_left() == nullptr)
                        {    
                            current_root->_left = new node(val, current_root);
                            ret = iterator(current_root->_left);
                        }
                        else
                        {
                            node_ptr old = current_root->_left;
                            delete (old);
                            current_root->_left = new node(val, current_root);
                            ret = iterator(current_root->_left);
                            current_root = current_root->_left;
                            current_root->_start_node = false;
                            current_root->_left = new node (current_root);
                            current_root = current_root->_left;
                            current_root->_start_node = true;
                        }
                        return (ret);
                    }
                    current_root = current_root->get_left();
                }
                else
                {
                    if (current_root->get_right() == nullptr || current_root->get_right()->is_end_node() == true)
                    {
                        if (current_root->get_right() == nullptr)
                        {    
                            current_root->_right = new node(val, current_root);
                            ret = iterator(current_root->_right);
                        }
                        else 
                        {
                            node_ptr old = current_root->_right;
                            delete (old);
                            current_root->_right = new node(val, current_root);
                            ret = iterator(current_root->_right);
                            current_root = current_root->_right;
                            current_root->_end_node = false;
                            current_root->_right = new node (current_root);
                            current_root = current_root->_right;
                            current_root->_end_node = true;
                        }
                        return (ret);
                    }
                    current_root = current_root->get_right();
                }
            }
            ft::pair<iterator, bool> p = insert(val);      
            return (p.first);
        }


        template <class InputIterator>
        void insert (InputIterator first, InputIterator last,
        typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
        {
            for (typename ft::map<Key,T>::iterator it = first; it!=last; ++it)
            {   
                ft::pair<Key, T> p = ft::make_pair(it->first, it->second); 
                insert(p);
            }
        }

        void swap (map& x)
        {
            if (size() == 0)
            {
                for (typename ft::map<Key,T>::const_iterator it = x.begin(); it!=x.end(); ++it)
                    insert(ft::make_pair(it->first, it->second));
                x.clear();
                return;
            }
			ft::map<Key, T> tmp(begin(), end());
            clear();
            for (typename ft::map<Key,T>::const_iterator it = x.begin(); it!=x.end(); ++it)
                insert(ft::make_pair(it->first, it->second));
            x.clear();
            for (typename ft::map<Key,T>::const_iterator itp = tmp.begin(); itp!=tmp.end(); ++itp)
                x.insert(ft::make_pair(itp->first, itp->second));
        }


        void erase (iterator first, iterator last)
        {
            ft::map<Key,T> tmp;
            if (first != begin())
            {
                first--;
                tmp.insert(begin(), first);
            } 
            tmp.insert(last, end());
            clear();
            insert(tmp.begin(), tmp.end());
        }

        void erase (iterator position)
        {
            iterator posnext = position;
            posnext++;
            erase(position, posnext);
        }

        size_type erase (const key_type& k)
        {
            if (count(k) == 0)
                return (0);
            iterator it = find(k);
            erase(it);
            return (1);
        }

        void    clear()
        {
            if (empty() || _root_node == nullptr)
                return;
            iterator prev = begin();
            iterator nxt = prev;
            iterator last = end();
            delete (prev.get_node());
            nxt++;
            while (nxt != last)
            {
                prev = nxt;
                ++nxt;
                delete (prev.get_node());
            }
            delete (last.get_node()); // FIND ANOTHER WAY CANNOT IMPLEMENT THIS AS PUBLIC MEMBER
            _root_node = nullptr;
        }
        
        /* observers */
        key_compare key_comp() const
        {
            return (_compare);
        }

        value_compare value_comp() const
        {
            return (value_compare(_compare));
        }
        
        /* operations */
        size_type count (const key_type& k) const
        {
            size_type ret;

            ret = 0;
            for (typename ft::map<Key,T>::const_iterator it = begin(); it!=end(); ++it)
            {   
                if (it->first == k)
                    ret++; 
            }
            return (ret);
        }

        iterator find (const key_type& k)
        {
            for (typename ft::map<Key,T>::iterator it = begin(); it!=end(); ++it)
            {   
                if (it->first == k)
                    return(it); 
            }
            return (end());
        }
        
        const_iterator find (const key_type& k) const
        {
            for (typename ft::map<Key,T>::const_iterator it = begin(); it!=end(); ++it)
            {   
                if (it->first == k)
                    return(it); 
            }
            return (end());  
        }

        iterator lower_bound (const key_type& k)
        {
            for (typename ft::map<Key,T>::iterator it = begin(); it!=end(); ++it)
            {   
                if (it->first >= k)
                    return(it); 
            }
            return (end());  
        }

        const iterator lower_bound (const key_type& k) const
        {
            for (typename ft::map<Key,T>::const_iterator it = begin(); it!=end(); ++it)
            {   
                if (it->first >= k)
                    return(it); 
            }
            return (end());  
        }

        iterator upper_bound (const key_type& k)
        {
            for (typename ft::map<Key,T>::iterator it = begin(); it!=end(); ++it)
            {   
                if (it->first > k)
                    return(it); 
            }
            return (end());  
        }

        const iterator upper_bound (const key_type& k) const
        {
            for (typename ft::map<Key,T>::const_iterator it = begin(); it!=end(); ++it)
            {   
                if (it->first > k)
                    return(it); 
            }
            return (end());  
        }

        ft::pair<iterator,iterator>             equal_range (const key_type& k)
        {
            return(ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
        }
        
        // pair<const_iterator,const_iterator> equal_range (const key_type& k) const
        // {
        //     return(ft::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));   
        // }
    
		/* Allocator */
		allocator_type get_allocator() const { return _alloc; }
    };
}      

#endif
