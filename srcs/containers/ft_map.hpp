/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_map.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/05 09:15:25 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/09/15 23:19:35 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_HPP
# define FT_MAP_HPP

#include "../utils/type_traits.hpp"
#include "../utils/ft_pair.hpp"
#include "../utils/tree_node.hpp"
#include "../iterators/bidirectional_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"

namespace ft {
// template < class Key, class T, class Compare = less<Key>, class Alloc = std::allocator<T> > 
template < class Key, class T, class Compare = less<Key>, class Alloc = std::allocator<T> > 
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
		typedef	reverse_iterator<const_iterator>                                                    const_reverse_iterator;
		typedef	reverse_iterator<iterator>				                                            reverse_iterator;
		typedef	typename ft::iterator_traits<iterator>::difference_type		                        difference_type;
		typedef size_t		 												                        size_type;
        typedef	tree_node<value_type>                                                               node;
        typedef	tree_node<value_type>*                                                              node_ptr;
		typedef typename Alloc::template rebind<node>::other				                        alloc_nd;
    /* INNER CLASS VALUE COMPARE */
    class value_compare : std::binary_function<value_type,value_type,bool>
    {   
        protected:
            Compare comp;
        public:
            value_compare (Compare c) : comp(c) {} 
            typedef bool result_type;
            typedef value_type first_argument_type;
            typedef value_type second_argument_type;
            bool operator() (const value_type& x, const value_type& y) const
            {
                return comp(x.first, y.first);
            }
    };

    private:
    	alloc_nd	    _alloc;
        node_ptr        _root_node;
        size_type       _size;

    protected:
        key_compare     _compare;

    public:
        /* constructors */
        explicit map (const key_compare& comp = key_compare(), 
        const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(0), _compare(comp)
        {
            _root_node = NULL;
        }

        template <class InputIterator>
        map (InputIterator first, InputIterator last,
        const key_compare& comp = key_compare(),
        const allocator_type& alloc = allocator_type(),
        typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
        : _alloc(alloc), _compare(comp)
        {
            if (first == last)
                return;
            _root_node = NULL;
	        for (InputIterator it = first; it!=last; ++it)
            {
                ft::pair<Key, T> p = ft::make_pair(it->first, it->second); 
                insert(p);
            }
        }

        map (const map& x) : _alloc(x._alloc), _size(x._size), _compare(x._compare)
        {
            _root_node = NULL;
            if (x._root_node == NULL)
            {
                _root_node = NULL;
                return;
            }
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
		    return *this;
        }

        /* iterators */
        iterator        begin()
        {
            node_ptr _current_node = _root_node;
            while (_current_node->_left != NULL)
                _current_node = _current_node->_left;
            iterator ret(_current_node);
            return (ret);
        }

        const_iterator  begin() const
        {
            node_ptr _current_node = _root_node;
            while (_current_node->_left != NULL)
                _current_node = _current_node->_left;
            const_iterator ret(_current_node);
            return (ret);
        }

        iterator        end()
        {
            node_ptr _current_node = _root_node;
            while (_current_node->_right != NULL)
                _current_node = _current_node->_right;
            iterator ret(_current_node);
            return (ret);
        }

        const_iterator  end() const
        {
            node_ptr _current_node = _root_node;
            while (_current_node->_right != NULL)
                _current_node = _current_node->_right;
            const_iterator ret(_current_node);
            return (ret);
        }

        reverse_iterator rbegin()
        {
            return reverse_iterator(end());
        }

        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(end());
        }

        reverse_iterator rend()
        {
            return reverse_iterator(begin());
        }
        const_reverse_iterator rend() const
        {
            return const_reverse_iterator(begin()); 
        }

        /* capacity */
        size_type size() const
        {
            size_type   ret;

            ret = 0;
            if (_root_node == NULL)
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
            node_ptr current_root;
            if (_root_node == NULL)
            {
                _root_node = _alloc.allocate(1);
                _alloc.construct(_root_node, val);
                insert_end_node();
                return (ft::make_pair(begin(), true));
            }
#            /* if a node with that key already exists do not insert a new one */
            if (find(val.first) != end()) 
                return (ft::pair<iterator, bool> (find(val.first), false));
            current_root = _root_node;
            delete_end_node();
            while (current_root != NULL)
            {
                if (val.first < current_root->_data.first)
                {
                    if (current_root->_left == NULL)
                    {
                        current_root->_left = _alloc.allocate(1);
                        _alloc.construct(current_root->_left, val);
                        current_root->_left->_parent = current_root;
                        insert_end_node();
                        break;
                    }
                    current_root = current_root->_left;
                }
                else if (val.first > current_root->_data.first)
                {
                    if (current_root->_right == NULL)
                    {
                        current_root->_right = _alloc.allocate(1);
                        _alloc.construct(current_root->_right, val);
                        current_root->_right->_parent = current_root;
                        insert_end_node();
                        break;
                    }
                    current_root = current_root->_right;
                }
            }
            // check_rebalance(current_root);
            return (ft::pair<iterator, bool> (find(val.first), false));
        }

        iterator insert (iterator position, const value_type& val)
        {
            (void)position;
            ft::pair<iterator, bool>  p = insert(val);
            return(p.first);
        }


        template <class InputIterator>
        void insert (InputIterator first, InputIterator last,
        typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
        {
            for (typename ft::map<Key,T>::iterator it = first; it!=last ; ++it)
            {   
                ft::pair<Key, T> p = ft::make_pair(it->first, it->second); 
                insert(p);
            }
        }

        void swap (map& x)
        {
		    ft::swap(_root_node, x._root_node);
		    ft::swap(_size, x._size);
		    ft::swap(_compare, x._compare);
		    ft::swap(_alloc, x._alloc);
        }


        void erase (iterator first, iterator last)
        {
            ft::map<Key,T> tmp;
            
            if (first != begin())
                tmp.insert(begin(), first);
            if (last != end())
                tmp.insert(last, end());
            clear();
            if (tmp._root_node != NULL)
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
            delete_end_node();
            delete_tree(_root_node);
            _root_node = NULL;
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
        
        pair<const_iterator,const_iterator> equal_range (const key_type& k) const
        {
            return(ft::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));   
        }
    
		/* Allocator */
		allocator_type get_allocator() const { return _alloc; }
        
        /* privat helper functions */
        private:
        void delete_tree(node_ptr node)
        {
            if (node == NULL) return;
            delete_tree(node->_left);
            delete_tree(node->_right);
            _alloc.destroy(node);
            _alloc.deallocate(node, 1);
        }

        void    delete_end_node()
        {
            node_ptr current_node;

            current_node = _root_node;
            if (_root_node == NULL)
                return ;
            while (current_node->_right != NULL && current_node->_right->_end_node == false)
                current_node = current_node->_right;
            if (current_node->_right == NULL)
                return ;
            node_ptr tmp = current_node->_right;
            current_node->_right = NULL;
            if (tmp->_end_node == true) 
                delete(tmp);
        }
        void    insert_end_node()
        {
            node_ptr current_node;

            current_node = _root_node;
            if (_root_node == NULL)
                return;
            while (current_node->_right != NULL && current_node->_right->_end_node == false)
                current_node = current_node->_right;
            current_node->_right = _alloc.allocate(1);
            _alloc.construct(current_node->_right);
            current_node->_right->_parent = current_node;
            current_node = current_node->_right;
            current_node->_end_node = true;
        }

        long    max(long a, long b)
        {
            if (a > b)
                return (a);
            return (b);
        }

        long    get_balance(node_ptr node)
        {
            if (node == NULL)
                return 0;
            return (node->_left->_height - node->_right->_height);
        }

        node_ptr    rotate_right(node_ptr y)
        {
            node_ptr x = y->_left;
            node_ptr T2 = x->_right;

            x->_right = y;
            y->_left = T2;
            return x;
        }
        node_ptr    rotate_left(node_ptr x)
        {
            node_ptr    y = x->_right;
            node_ptr    T2 = y->_left;
            
            y->_left = x;
            x->_right = T2;
            return y;
        }

        void    check_rebalance(node_ptr node)
        {
            long balance;

            balance = get_balance(node);
            /* left left case */
            if (balance > 1 && node->_data.first < node->_left->_data.first)
                rotate_right(node);
            /* right right case */
            if (balance > 1 && node->_data.first > node->_right->_data.first)
                rotate_left(node);
            if (balance > 1 && node->_data.first > node->_left->_data.first)
            {
                node->_left = rotate_left(node->_left);
                rotate_right(node);
            }
            if (balance < -1 && node->_data.first < node->_right->_data.first)
            {
                node_ptr tmp = rotate_right(node->_right);
                node->_right = tmp;
                rotate_left(node);
            }
        }
    };
}      

#endif
