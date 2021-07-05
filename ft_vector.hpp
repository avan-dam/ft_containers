/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vector.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 12:04:40 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/07/05 18:54:15 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

#include "random_access_iterator.hpp"
#include "traits.hpp"


namespace ft {
template <class T, class Alloc = std::allocator<T> >
class vector
    {
    public:
		typedef	T														value_type; 
		typedef Alloc													allocator_type;
        typedef	T&														reference;
        typedef const T&												const_reference;
        typedef	T*														pointer;
        typedef	const T*												const_pointer;
		typedef	random_access_iterator<value_type>						iterator;
		// typedef													const_iterator;
		typedef	reverse_random_access_iterator<value_type>				reverse_iterator;
		// typedef													const_reverse_iterator;
		typedef	typename ft::iterator_traits<iterator>::difference_type	difference_type;
		typedef unsigned int 											size_type; 
        
    public:
		/* Constructors, deconstructor and assignment operator*/
        vector(const allocator_type& alloc = allocator_type()) 
			:  _vector(nullptr), _size(0), _capacity(0), _alloc(alloc) {}
		
        vector(size_type n, const value_type& val = value_type(),
                	const allocator_type& alloc = allocator_type()) : _alloc(alloc)
        {
            _size = n;
            _capacity = n;
            _vector = new value_type[_capacity];
            for (unsigned int i = 0; i < n; i++)
                _vector[i] = val;
        }
		
		template <class InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
            typename ft::enable_if<ft::is_iterator<InputIterator>::value >::type* = 0) : _alloc(alloc)
        {
			int i;

			i = 0;
			_size = 0;
			for (InputIterator n = first; n != last; n++)
				_size++;
            _capacity = _size;
            _vector = new value_type[_capacity];
			for (InputIterator n = first; n != last; n++)
            {
				_vector[i] = *n;
				i++;
			}
        }

        vector (const vector& x)
        {
            _size = x.size();
			_alloc = x._alloc;
            _capacity = x.size();
            _vector = new value_type[_capacity];  
            for (unsigned int i = 0; i < _size; i++)
                _vector[i] = x[i];
            return;
        }

        ~vector() {	delete [] _vector; }

		vector& operator=(const vector& x)
        {
            if (_size != x._size || _capacity != x._capacity)
            {
				_capacity = x._capacity;
                _size = x._size;
                delete [] _vector;
                _vector = new value_type[_capacity];
            }
            for (unsigned int i = 0; i < _size; i++)
                _vector[i] = x[i];
		    return *this;
        }


		/* Iterators */
		iterator begin() { return iterator(&_vector[0]); }
		// const_iterator begin() const;
		
		iterator end() { return iterator(&_vector[_size]); }
		// const_iterator end() const;
		
		reverse_iterator rbegin()  {if (_size == 0) return reverse_iterator(0); return reverse_iterator(&_vector[_size - 1]);}
		// const_reverse_iterator rbegin() const;
		
		reverse_iterator rend() {if (_size == 0) return reverse_iterator(0);  return reverse_iterator(&_vector[-1]);}
		// const_reverse_iterator rend() const;


		/* capacity */
        size_type size() const  { return (_size); }

       	size_type max_size() const { return _alloc.max_size(); }

		void resize (size_type n, value_type val = value_type())
		{
			if (n == _size)
				return;
			while (n < _size)
				pop_back();
			while (n > _size)
				push_back(val);
		}

		size_type	capacity() const	{return (_capacity); }

		bool  		empty() const { return (_size == 0); }

		void reserve (size_type n)
		{
			if (n > _capacity)
			{
				vector<T,Alloc>		tmp(begin(), end());
				if (_capacity != 0 && _size != 0 && _vector != nullptr)
	            	delete [] _vector;
				_capacity = n;
				_vector = new value_type[_capacity];
            	for (unsigned int i = 0; i < _size; i++)
               		_vector[i] = tmp[i];
			}
		}

		
		/* Element access */
        reference  operator[](size_type n) {return reference(_vector[n]); }
		const_reference operator[] (size_type n) const {return const_reference(_vector[n]); }

		reference at (size_type n) { return reference(_vector[n]);}
		const_reference at (size_type n) const { return const_reference(_vector[n]);}
        
		reference front() { return reference(_vector[0]);}
        const_reference front() const { return const_reference(_vector[0]);}
        
		reference back() { if (_size == 0) return front(); return reference(_vector[_size - 1]);}
        const_reference back() const { return const_reference(_vector[_size - 1]);}


		/* Modifiers*/
		template <class InputIterator>
        void assign (InputIterator first, InputIterator last,
                    typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
		{
			if (_size > 0 && _size < max_size())
				clear();
			_size = 0;
			for (InputIterator counter = first; counter !=last; counter++)
				_size++;
			_capacity = _size;
            _vector = new value_type[_capacity];
            for (unsigned int i = 0; i < _size; i++)
            {
			    _vector[i] = *first;
				first++;
			}	
		}
        void assign (size_type n, const value_type& val)
        {
            _size = n;
            _capacity = n;
            delete [] _vector;
            _vector = new value_type[_capacity];
            for (unsigned int i = 0; i < _size; i++)
                _vector[i] = val;
        }

		void push_back (const value_type& val)
		{
			vector<T,Alloc>		newvector(begin(), end());

			if (_vector != nullptr && _capacity != 0)
            	delete [] _vector;
			if (_size == _capacity)
	            _capacity++;
            _size++;
            _vector = new value_type[_capacity];
            for (unsigned int i = 0; i < _size - 1; i++)
			    _vector[i] = newvector[i];
			_vector[_size - 1] = val;
		}

		void	pop_back()
		{
			ft::vector<T,Alloc> tmp(begin(), end());
			_size--;
			_capacity--;
			delete [] _vector;
			_vector = new value_type[_capacity];
       		for (unsigned int i = 0; i < _size; i++)
            	_vector[i] = tmp[i];
		}

		iterator insert (iterator position, const value_type& val)
		{
			vector<T,Alloc>		newvector(1, val);
			return (insert_vector_helper(newvector, position));
		}
    	void insert (iterator position, size_type n, const value_type& val)
		{
			vector<T,Alloc>		newvector(n, val);
			insert_vector_helper(newvector, position);
			return ;

		}
		template <class InputIterator>
        void insert (InputIterator position, InputIterator first, InputIterator last,
                    typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
		{
			vector<T,Alloc>		newvector(first, last);
			insert_vector_helper(newvector, position);
		}

		iterator erase (iterator position)
		{
			iterator pos_nxt = position;
			pos_nxt++;
			return (erase(position, pos_nxt));
		}
		iterator erase (iterator first, iterator last)
		{
			size_type		size_delete = 0;
			size_type		i = 0;
			vector<T,Alloc>	copyvector(begin(), end());
			iterator 		loop = begin();

			for (iterator tmp = first; tmp != last; tmp++)
				size_delete++;
			_size = _size - size_delete;
			_capacity = _size;
			delete [] _vector;
            _vector = new value_type[_capacity];
			while (loop != first)
			{
				_vector[i] = copyvector[i];
				loop++;
				i++;
			}
			iterator ret = (&_vector[i]);//+1?
			while (i < _size)
			{
				_vector[i] = copyvector[i + size_delete];
				i++;
			}
			return (ret);
		}

		void swap (vector& x)
		{
			ft::vector<T,Alloc> tmp(begin(), end());	
			assign(x.begin(), x.end());
			_size = x._size;
			x.clear();
			x.assign(tmp.begin(), tmp.end());
			x._size = tmp._size;
		}
		
		void clear()
		{
			if (_capacity != 0 && _vector != nullptr)
			{
				_size = 0;
				_capacity = 0;
				delete [] _vector;
			}
		}


		/* Allocator */
		allocator_type get_allocator() const { return _alloc; }

	private:
    	value_type* 	_vector;
		size_type		_size;
		size_type		_capacity;
		allocator_type	_alloc;

		void	insert_newvector(ft::vector<T,Alloc> newvector)
		{
			if (newvector.size() == 0)
				return ;
			for (ft::vector<T,Alloc>::iterator it=newvector.begin(); it!=newvector.end(); ++it)
				push_back(*it);
			return ;
		}
		
		iterator	insert_vector_helper(ft::vector<T,Alloc> newvector, iterator position)
		{
			vector<T,Alloc>		vector_start(begin(), position);
			vector<T,Alloc>		vector_end(position, end());
			if (!empty())
				clear();
			insert_newvector(vector_start);
			insert_newvector(newvector);
			position = &_vector[_size - 1];
			insert_newvector(vector_end);
			return (position);
		}
    };

	/* Non-member function overloads */
	template <class T, class Alloc>
	bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		ft::vector<T,Alloc> lhs_copy(lhs);
		ft::vector<T,Alloc> rhs_copy(rhs);
		if (lhs.size() != rhs.size())
			return false;
		typename ft::vector<T,Alloc>::iterator lhs_it = lhs_copy.begin();
		typename ft::vector<T,Alloc>::iterator rhs_it = rhs_copy.begin();
		unsigned int i = 0;
		while (lhs_it != lhs_copy.end() && rhs_it != rhs_copy.end() && i < lhs_copy.size())
		{
			if (lhs[i] != rhs[i])
				return false;
			lhs_it++;
			rhs_it++;
			i++;
		}
		return true;
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		ft::vector<T,Alloc> lhs_copy(lhs);
		ft::vector<T,Alloc> rhs_copy(rhs);
		typename ft::vector<T,Alloc>::iterator lhs_it = lhs_copy.begin();
		typename ft::vector<T,Alloc>::iterator rhs_it = rhs_copy.begin();
		unsigned int i = 0;
		while (lhs_it != lhs_copy.end() && rhs_it != rhs_copy.end() && i < lhs_copy.size())
		{
			if (lhs_copy[i] > rhs_copy[i])
				return true;
			lhs_it++;
			rhs_it++;
			i++;
		}
		if (lhs_it != lhs_copy.end())
			return true;
		return false;
	}

	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		ft::vector<T,Alloc> lhs_copy(lhs);
		ft::vector<T,Alloc> rhs_copy(rhs);
		typename ft::vector<T,Alloc>::iterator lhs_it = lhs_copy.begin();
		typename ft::vector<T,Alloc>::iterator rhs_it = rhs_copy.begin();
		unsigned int i = 0;
		while (lhs_it != lhs_copy.end() && rhs_it != rhs_copy.end() && i < lhs_copy.size())
		{
			if (lhs_copy[i] < rhs_copy[i])
				return true;
			lhs_it++;
			rhs_it++;
			i++;
		}
		if (rhs_it != rhs_copy.end())
			return true;
		return false;
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs > rhs);
	}

	template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		ft::vector<T,Alloc> tempthislist(y.begin(), y.end());
		y.assign(x.begin(), x.end());
		x.clear();
		x.assign(tempthislist.begin(), tempthislist.end());
	}
}

# endif
