/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_map.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/05 09:15:25 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/09/16 14:17:14 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_HPP
# define FT_MAP_HPP

#include "../utils/type_traits.hpp"
#include "../utils/ft_pair.hpp"
#include "../utils/tree_node.hpp"
#include "../iterators/bidirectional_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"


#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
// DELETE 



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
            std::cout << "starting with "<< val.first << std::endl;
            node_ptr current_root;
            if (_root_node == NULL)
            {
                _root_node = _alloc.allocate(1);
                _alloc.construct(_root_node, val);
                _root_node->_height = 1;
                insert_end_node();
                return (ft::make_pair(begin(), true));
            }
            /* if a node with that key already exists do not insert a new one */
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
                        current_root = current_root->_left;
                        current_root->_height = 0;
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
                        current_root = current_root->_right;
                        current_root->_height = 0;
                        break;
                    }
                    current_root = current_root->_right;
                }
            }
            node_ptr tmp;
            node_ptr tmp2 = current_root;
            while (current_root->_parent)
            {
                current_root->_height = calc_height(current_root);
                current_root = current_root->_parent;
            }
            tmp = _root_node;
            while (tmp != tmp2 && tmp != NULL)
            {
                check_rebalance(tmp);
                if (val.first < tmp->_data.first)
                    tmp = tmp->_left;
                else
                    tmp = tmp->_right;
            }
            if (tmp != NULL)
                check_rebalance(tmp);
            current_root = tmp;
            // while (current_root->_parent)
            // {
            //     current_root->_height = calc_height(current_root);
            //     // check_rebalance(current_root);
            //     current_root = current_root->_parent;
            // }
            // while (tmp->_parent)
            // {
            //     check_rebalance(tmp);
            //     tmp = tmp->_parent;
            // }
            // tmp->_height = calc_height(tmp);
            // std::cout << "height is " << current_root->_height << std::endl;
            // if (tmp->_parent)
                // check_rebalance(current_root);
            print_tree(_root_node);
            insert_end_node();
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
            if (node->_left && node->_right)
                return (node->_left->_height - node->_right->_height - 1); 
            else if (node->_left && node->_right == NULL)
                return (node->_left->_height + 1); 
            else if (node->_left== NULL && node->_right )
                return (-node->_right->_height - 1);
            return 0;
        }

        int calc_height(node_ptr node)
        {
            if(node->_left && node->_right)
            {
                if (node->_left->_height < node->_right->_height)
                    return node->_right->_height + 1;
                return  node->_left->_height + 1;
            }
            else if (node->_left && node->_right == NULL)
               return node->_left->_height + 1;
            else if (node->_left == NULL && node->_right)
               return node->_right->_height + 1;
            return 0;
        }

        void update_height(node_ptr root)
        {
            if (root != NULL) 
            {
                int val;

                val = 1;
                if (root->_left != NULL)
                    val = root->_left->_height + 1;
                if (root->_right != NULL)
                    val = max(val, root->_right->_height + 1);
                root->_height = val;
            }
        }

        node_ptr  llrotation(node_ptr root)
        {
    		bool rootly;

    		rootly = false;
    		if (root == _root_node)
        		rootly = true;
    		/* reference to the left child */ 
    		node_ptr tmpnode = root->_left;
    		/* Update left child of root to the right child of the current left child of the root */ 
    		root->_left = tmpnode->_right;
    		/* Update parent pointer of the left child of the root node */
    		if (tmpnode->_right != NULL)
        		tmpnode->_right->_parent = root;
    		/* Update the right child of tmpnode to root  */
    		tmpnode->_right = root;
    		/* Update parent pointer of the tmpnode */ 
    		tmpnode->_parent = root->_parent;
    		/*  Update the parent pointer of the root */
    		root->_parent = tmpnode;
    		/* Update tmpnode as the left or the right child of its parent pointer according to its key value */ 
    		if (tmpnode->_parent != NULL && root->_data.first < tmpnode->_parent->_data.first) 
        		tmpnode->_parent->_left = tmpnode;
    		else if (tmpnode->_parent != NULL)
            	tmpnode->_parent->_right = tmpnode;
    		/* Make tmpnode as the new root */ 
    		root = tmpnode;
    		/* Update the heights */ 
    		update_height(root->_left);
    		update_height(root->_right);
    		update_height(root);
    		update_height(root->_parent);
    		/* special case if root node */
    		if (rootly == true)
    		{    
       			_root_node = root;
        		update_height(_root_node->_left);
        		update_height(_root_node->_right);
        		update_height(_root_node);
        		update_height(_root_node->_parent);
    		}
    		return root;
		}


    	node_ptr  rrrotation(node_ptr root)
		{
            bool rootly;

    		rootly = false;
    		if (root == _root_node)
        		rootly = true;
    		/* Create a reference to the right child */
    		node_ptr tmpnode = root->_right;
			/* Update the right child of the root as the left child of the current right child of the root */ 
    		root->_right = tmpnode->_left;
    		/* Update parent pointer of the right child of the root node */
    		if (tmpnode->_left != NULL)
        		tmpnode->_left->_parent = root;
			/* Update the left child of the tmpnode to root */
    		tmpnode->_left = root;
			/* Update parent pointer of the tmpnode */
    		tmpnode->_parent = root->_parent;
   			/* Update the parent pointer of the root */
		    root->_parent = tmpnode;
    		/* Update tmpnode as the left or the right child of its parent pointer according to its key value */
    		if (tmpnode->_parent != NULL && root->_data.first < tmpnode->_parent->_data.first)
        		tmpnode->_parent->_left = tmpnode;
    		else if (tmpnode->_parent != NULL)
            	tmpnode->_parent->_right = tmpnode;
    		root = tmpnode;
	    	/* Update the heights */ 
    		update_height(root->_left);
    		update_height(root->_right);
    		update_height(root);
    		update_height(root->_parent);
		    /* special case for root */
			if (rootly == true)
    		{    
        		_root_node = root;
        		update_height(_root_node->_left);
        		update_height(_root_node->_right);
        		update_height(_root_node);
        		update_height(_root_node->_parent);
    		}
		    return root;
    	}

    	node_ptr  rlrotation(node_ptr root)
    	{
        	if (root == _root_node)
        	{
        		_root_node->_right = llrotation(_root_node->_right);
        		return rrrotation(_root_node);
        	}
        	root->_right = llrotation(root->_right);
        	return rrrotation(root);
    	}

    	node_ptr  lrrotation(node_ptr root)
    	{
        	if (root == _root_node)
        	{
            	_root_node->_left = rrrotation(_root_node->_left);
            	return llrotation(_root_node);
        	}
        	root->_left = rrrotation(root->_left);
        	return llrotation(root);
    	}

    	void    check_rebalance(node_ptr node)
    	{
        	long bfnd;

        	bfnd = get_balance(node);
        	if(bfnd > 1 && get_balance(node->_left) > 0)
            	node = llrotation(node);
        	else if(bfnd < -1 && get_balance(node->_right) < 0)
            	node = rrrotation(node);
        	else if(bfnd < -1 && get_balance(node->_right) > 0)
            	node = rlrotation(node);
        	else if(bfnd > 1 && get_balance(node->_left) < 0)
            	node = lrrotation(node);
        }

        //delete AALLLL
        public:
        void    ft_print_balance()
        {
            for (typename ft::map<Key,T>::const_iterator it = begin(); it!=end(); ++it)
            {   
                std::cout << "node "  << " ";
                std::cout << it->first;
                std::cout << " balance "  << " ";
                std::cout << get_balance(it.get_node());
                std::cout << " height " << " ";
                std::cout << calc_height(it.get_node()) << std::endl;
            }
        }
        void    ft_print_map()
        {
            std::cout << "rootnode" << _root_node->_data.first << std::endl;
            if (_root_node->_left)
                std::cout << "rootnode left" << _root_node->_left->_data.first << std::endl;
            if (_root_node->_right)
                 std::cout << "rootnode rigt" << _root_node->_right->_data.first << std::endl;
            if (_root_node->_right->_right)
                 std::cout << "rootnode rigt ->_right" << _root_node->_right->_right->_data.first << std::endl;
            if (_root_node->_right->_left)
                 std::cout << "rootnode rigt->_left" << _root_node->_right->_left->_data.first << std::endl;
        }
        void    ft_iterate()
        {
            for (typename ft::map<Key,T>::const_iterator it = begin(); it!=end(); ++it)
            {   
                std::cout << "node is: " << it->first;
                if (it.get_node()->_parent)
                    std::cout << "parent is: " << it.get_node()->_parent->_data.first;
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }

        			void	print_tree_utils(node_ptr root, int space) const
			{
			   int count = 5;
				if (root == NULL)
					return;
				space += count;
				print_tree_utils(root->_right, space);
				std::cout << std::endl;
				for (int i = count; i < space; i++)
					std::cout << " ";
				std::cout << root->_data.first << ", _height = " << root->_height << std::endl;
				print_tree_utils(root->_left, space);
			}

			// REMOVE THIS REMOVE THIS REMOVE THIS REMOVE THIS
			// REMOVE THIS REMOVE THIS REMOVE THIS REMOVE THIS
			// REMOVE THIS REMOVE THIS REMOVE THIS REMOVE THIS
			void	print_tree(node_ptr root) const
			{
				print_tree_utils(root, 0);
			}
    };
}      

#endif
