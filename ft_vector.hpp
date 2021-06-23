/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vector.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 12:04:40 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/06/19 15:48:39 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

#include "vector_iterator.hpp"

namespace ft {
template <typename T>
class vector
    {
    public:
		typedef unsigned int 			size_type; 
		typedef	T						value_type; 
        typedef T&                      reference;
		typedef	vector_iterator<T>		iterator;
        
    public:
        vector() :  _vector(nullptr), _size(0), _capacity(0){}

        vector(size_type n, const value_type &val)
        {
            _vector = new value_type[n];
            _size = n;
            _capacity = n;
            for (unsigned int i = 0; i < n; i++)
                _vector[i] = val;
            return;
        }

		vector(size_type n)
		{
            _vector = new value_type[n];
            _size = n;
            _capacity = n;
            for (unsigned int i = 0; i < n; i++)
                _vector[i] = 0;
			return ;
		}

        vector(iterator first, iterator last)
        {
			_size = 0;
			for (iterator tmp = first; tmp != last; tmp++)
				_size++;
            _vector = new value_type[_size];
            for (unsigned int i = 0; i < _size; i++)
            {
			    _vector[i] = *first;
				first++;
			}
		}

        vector (const vector& x)
        {
            _size = x.size();
            _capacity = x.size();
            _vector = new value_type[_size];  
            for (unsigned int i = 0; i < _size; i++)
                _vector[i] = x[i];
            return;
        }
        ~vector()
        {
            delete [] _vector;
        }

		iterator begin() {
			return iterator(&_vector[0]); 
			}
		// const_iterator begin() const;
		iterator end() {
			return iterator(&_vector[_size]); 
			}
		// const_iterator end() const;

		// reverse_iterator rbegin();
		// const_reverse_iterator rbegin() const;
        vector& operator=(const vector& x)
        {
            if (_size != x._size || _capacity != x._capacity)
            {
				_capacity = x._capacity;
                _size = x._size;
                delete _vector;
                _vector = new value_type[_size];
            }
            for (unsigned int i = 0; i < _size; i++)
                _vector[i] = x[i];
		    return *this;
        }

        size_type size() const  {   return (_size); }
        // size_type max_size() const;
		// void resize (size_type n, value_type val = value_type())
		void resize (size_type n, value_type val)
		{
			if (n == _size)
				return;
			while (n < _size)
				pop_back();
			while (n > _size)
				push_back(val);
			return;
		}
		size_type capacity() const	{return (_capacity); }
		bool  empty() const { return (_size == 0); }

		void reserve (size_type n)
		{
			if (n > _capacity)
			{
				vector<T>		tmp(begin(), end());
				_capacity = n;
				delete _vector;
				_vector = new value_type[_capacity];
            	for (unsigned int i = 0; i < _size; i++)
               		_vector[i] = tmp[i];
			}
		}

		// const_reference operator[] (size_type n) const;
        T &  operator[](size_type n) const
        {
            // if (n >= _size)
            //     throw notAccessibleException();
              return (_vector[n]);
        }

		reference at (size_type n) { return (&_vector[n]);}
		// const_reference at (size_type n) const;
        reference front() { return _vector[0];}
        // const_reference front() const { return const &_vector[0];}
        reference back() { if (_size == 0) return front(); return _vector[_size - 1];}
        // const_reference back() const { return const &_vector[_size - 1];}

        void assign (iterator first, iterator last)
		{
			if (_size > 0 && _size < 20000) // MAX SIZE
				clear();
			_size = 0;
			for (ft::vector<T>::iterator counter = first; counter !=last; counter++)
				_size++;
			_capacity = _size;
            _vector = new value_type[_size];
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
            _vector = new value_type[_size];
            for (unsigned int i = 0; i < _size; i++)
                _vector[i] = val;
        }

        void push_front (const value_type& val)
        {
			vector<T>		newvector(_vector);

			if (_size == _capacity)
	            _capacity++;
            _size++;
            delete [] _vector;
            _vector = new value_type[_size];
			_vector[0] = val;
            for (unsigned int i = 1; i < _size; i++)
                _vector[i] = newvector[i - 1];
			// delete new vector? no cos destruct
        }

		void push_back (const value_type& val)
		{
			vector<T>		newvector(begin(), end());

			if (_size != 0)
	            delete [] _vector;
			if (_size == _capacity)
	            _capacity++;
            _size++;
            _vector = new value_type[_size];
            for (unsigned int i = 0; i < _size - 1; i++)
            {
			    _vector[i] = newvector[i];
			}
			_vector[_size - 1] = val;

		}

		iterator insert (iterator position, const value_type& val)
		{
			vector<T>		newvector(1, val);
			return (insert_vector_helper(newvector, position));
		}

		

    	void insert (iterator position, size_type n, const value_type& val)
		{
			vector<T>		newvector(n, val);
			insert_vector_helper(newvector, position);
			return ;

		}
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last)
		{
			vector<T>		newvector(first, last);
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
			size_type	size_delete = 0;
			size_type	i = 0;
			vector<T>	copyvector(begin(), end());
			iterator 	loop = begin();

			for (iterator tmp = first; tmp != last; tmp++)
				size_delete++;
			_size = _size - size_delete;
			_capacity = _size;
			delete [] _vector;
            _vector = new value_type[_size];
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
			ft::vector<T> tmp(begin(), end());	
			assign(x.begin(), x.end());
			_size = x._size;
			x.clear();
			x.assign(tmp.begin(), tmp.end());
			x._size = tmp._size;
		}
		
		void clear()
		{
			if (_size != 0)
			{
				_size = 0;
				delete [] _vector;
			}
		}
	bool operator==(const vector & rhs)
    {
		if (_size != rhs._size || _capacity != rhs._capacity)
			return (false);
        for (unsigned int i = 0; i < _size - 1; i++)
		{
            if (_vector[i] != rhs[i])
				return (false);
		}		
		return (true);
    }

	void	pop_back()
	{
		ft::vector<T> tmp(begin(), end());
		_size--;
		_capacity--;
		delete [] _vector;
		_vector = new value_type[_size];
       for (unsigned int i = 0; i < _size; i++)
            _vector[i] = tmp[i];
		}

    private:
        value_type* _vector;
		size_type	_size;
		size_type	_capacity;

		void	insert_newvector(ft::vector<T> newvector)
		{
			if (newvector.size() == 0)
				return ;
			for (ft::vector<T>::iterator it=newvector.begin(); it!=newvector.end(); ++it)
				push_back(*it);
			return ;
		}
		iterator	insert_vector_helper(ft::vector<T> newvector, iterator position)
		{
			vector<T>		vector_start(begin(), position);
			vector<T>		vector_end(position, end());
			if (!empty())
				clear();
			insert_newvector(vector_start);
			insert_newvector(newvector);
			position = &_vector[_size - 1];
			insert_newvector(vector_end);
			return (position);
		}
    };

template <typename T>
bool operator== (const vector<T>& lhs, const vector<T>& rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	typename ft::vector<T>::iterator lhs_it = lhs.begin();
	typename ft::vector<T>::iterator rhs_it = rhs.begin();
	unsigned int i = 0;
	while (lhs_it != lhs.end() && rhs_it != rhs.end() && i < lhs.size())
	{
		if (lhs[i] != rhs[i])
			return false;
		lhs_it++;
		rhs_it++;
		i++;
	}
	return true;
}

template <typename T>
bool operator!=(const vector<T>& lhs, const vector<T>& rhs)
{
	return !(lhs == rhs);
}

template <typename T>
bool operator>(const vector<T>& lhs, const vector<T>& rhs)
{
	ft::vector<T> lhs_copy(lhs);
	ft::vector<T> rhs_copy(rhs);
	typename ft::vector<T>::iterator lhs_it = lhs_copy.begin();
	typename ft::vector<T>::iterator rhs_it = rhs_copy.begin();
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

template <typename T>
bool operator<(const vector<T>& lhs, const vector<T>& rhs)
{
	ft::vector<T> lhs_copy(lhs);
	ft::vector<T> rhs_copy(rhs);
	typename ft::vector<T>::iterator lhs_it = lhs_copy.begin();
	typename ft::vector<T>::iterator rhs_it = rhs_copy.begin();
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

template <typename T>
bool operator<=(const vector<T>& lhs, const vector<T>& rhs)
{
	return !(lhs > rhs);
}

template <typename T>
bool operator>=(const vector<T>& lhs, const vector<T>& rhs)
{
	return !(lhs < rhs);
}

template <class T>
  void swap (vector<T>& x, vector<T>& y)
  {
	  ft::vector<T> tempthislist(y.begin(), y.end());
	  y.assign(x.begin(), x.end());
	  x.clear();
	  x.assign(tempthislist.begin(), tempthislist.end());
  }
}

# endif
