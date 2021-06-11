/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vector.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 12:04:40 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/06/11 15:43:16 by ambervandam   ########   odam.nl         */
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
        vector() :  _vector(nullptr), _size(0) {}

        vector(size_type n, const value_type &val)
        {
            _vector = new value_type[n];
            _size = n;
            _capacity = n;
            for (unsigned int i = 0; i < n; i++)
                _vector[i] = val;
            return;
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
				vector<T>		tmp = this;
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
        reference front() { return &_vector[0];}
        // const_reference front() const { return const &_vector[0];}
        reference back() { if (_size == 0) return front(); return &_vector[_size - 1];}
        // const_reference back() const { return const &_vector[_size - 1];}

        // void assign (InputIterator first, InputIterator last);
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

            _size++;
            _capacity++;
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

            _size++;
            _capacity++;
            delete [] _vector;
            _vector = new value_type[_size];
            for (unsigned int i = 0; i < _size - 1; i++)
            {
			    _vector[i] = newvector[i];
			}
			_vector[_size - 1] = val;

		}

//		iterator insert (iterator position, const value_type& val);
//     	void insert (iterator position, size_type n, const value_type& val);
//		template <class InputIterator>
//		void insert (iterator position, InputIterator first, InputIterator last);


//		iterator erase (iterator position);
//		iterator erase (iterator first, iterator last);

		void swap (vector& x)
		{
			ft::vector<T> tmp = this;	
			this = x;
			_size = x._size;
			x.clear();
			x = tmp;
			x._size = tmp._size;
			// tmp.clear()??
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

    private:
        value_type* _vector;
		size_type	_size;
		size_type	_capacity;
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
    };

}

# endif
