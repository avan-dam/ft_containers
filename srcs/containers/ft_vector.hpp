/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vector.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 12:04:40 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/09/29 09:34:51 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

#include "../iterators/reverse_iterator.hpp"
#include "../utils/type_traits.hpp"
#include "../utils/compare.hpp"

namespace ft {
template <class T, class Alloc = std::allocator<T> >
class vector
    {
    public:
		typedef	T															value_type; 
		typedef Alloc														allocator_type;
        typedef	T&															reference;
        typedef const T&													const_reference;
        typedef	T*															pointer;
        typedef	const T*													const_pointer;
		typedef random_access_iterator<T, T*, T&>							iterator;
		typedef	random_access_iterator<T, const T*, const T&>				const_iterator;
		typedef	reverse_iterator<const_iterator>							const_reverse_iterator;
		typedef	reverse_iterator<iterator>									reverse_iterator;
		typedef	typename ft::iterator_traits<iterator>::difference_type		difference_type;
		typedef size_t		 												size_type; 

    public:
		/* Constructors, deconstructor and assignment operator*/
        vector(const allocator_type& alloc = allocator_type()) 
			:  _vector(NULL), _size(0), _capacity(0), _alloc(alloc) {}
		
        vector(size_type n, const value_type& val = value_type(),
                	const allocator_type& alloc = allocator_type()) : _alloc(alloc)
        {
            _size = n;
            _capacity = n;
			_vector = _alloc.allocate(n);
            for (size_t i = 0; i < n; i++)
                _alloc.construct(&_vector[i], val);
        }
		
		template <class InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
        typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0) : _alloc(alloc)
        {
			int i;

			i = 0;
			_size = distance(first, last);
            _capacity = _size;
			_vector = _alloc.allocate(_capacity);
			for (InputIterator n = first; n != last; n++, i++)
				_alloc.construct(&_vector[i], *n);
        }

        vector (const vector& x)
        {
            _size = x.size();
			_alloc = x._alloc;
            _capacity = x.size();
			if (_size == 0)
			{
				_vector = NULL;
				return;
			}
			_vector = _alloc.allocate(_capacity);
            for (size_t i = 0; i < _size; i++)
			    _alloc.construct(&_vector[i], x[i]);
            return;
        }

        ~vector() 
		{
			clear();
			_alloc.deallocate(_vector, _size);
		}

		vector& operator=(const vector& x)
        {
            if (_size != x._size || _capacity != x._capacity)
            {
				_alloc.deallocate(_vector, _capacity);
				_capacity = x._capacity;
                _size = x._size;
				_vector = _alloc.allocate(_capacity);
            }
            for (size_t i = 0; i < _size; i++)
				_alloc.construct(&_vector[i], x[i]);
		    return *this;
        }


		/* Iterators */
		const_iterator begin() const { return const_iterator(_vector); }
		iterator begin() { return iterator(_vector); }
		
		const_iterator end() const { return const_iterator(&_vector[_size]); }
		iterator end() { return iterator(&_vector[_size]); }
	
		reverse_iterator rbegin()  {return reverse_iterator(end());}
		const_reverse_iterator rbegin() const  {return const_reverse_iterator(end());}
		
		reverse_iterator rend() {return reverse_iterator(begin());}
		const_reverse_iterator rend() const {return const_reverse_iterator(begin());}

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
			if (n > max_size())
				return;
			if (n > _capacity)
			{
				value_type *tmp = _alloc.allocate(n, &_vector);
				for (size_type i = 0; i < _size; i++)
					tmp[i] = _vector[i];
				_alloc.deallocate(_vector, _size);
				_vector = tmp;
				_capacity = n;
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
			_vector = _alloc.allocate(_capacity);
            for (size_t i = 0; i < _size; i++)
            {
				_alloc.destroy(&_vector[i]);
				_alloc.construct(&_vector[i], *first);
				first++;
			}	
		}
        void assign (size_type n, const value_type& val)
        {
			_alloc.deallocate(_vector, _size);
            _size = n;
            _capacity = n;
			_vector = _alloc.allocate(_capacity);
            for (size_t i = 0; i < _size; i++)
            {
				_alloc.destroy(&_vector[i]);
				_alloc.construct(&_vector[i], val);
			}
        }

		void push_back (const value_type& val)
		{
			if (_size == _capacity)
			{
				if (_size == 0)
					reserve(1);
				else
					reserve(_size * 2);
			}
			_vector[_size] = val;
			_size++;
		}

		void	pop_back()	
		{	
			_alloc.destroy(&_vector[_size - 1]);
			_size--; 
		}

		iterator insert (iterator position, const value_type& val)
		{
			size_t pos = position - begin();
			_size++;
			if (_size > _capacity)
			{
				if (_capacity == 0)
					reserve(1);
				else
					reserve(_size * 2);
			}
			for (unsigned int i = _size - 1; i >pos; i--)
				_alloc.construct(&_vector[i], _vector[i - 1]);
			_vector[pos] = val;
			iterator ret(&_vector[pos]);
			return ret;
		}

    	void insert (iterator position, size_type n, const value_type& val)
		{
			size_t startpos = position - begin();
			size_t endpos = startpos + n;
			_size = _size + n;
			if (_size > _capacity)
			{
				if (_capacity == 0)
					reserve(1);
				else
					reserve(_size * 2);
			}
			for (unsigned int i = _size; i >= endpos; i--)
				_alloc.construct(&_vector[i], _vector[i - n]);
			for (unsigned int j = startpos; j < endpos; j++)
				_alloc.construct(&_vector[j], val);
			return ;
		}

		template <class InputIterator>
        void insert (InputIterator position, InputIterator first, InputIterator last,
                    typename ft::enable_if<ft::is_iterator<InputIterator>::value >::type* = 0)
		{
			size_t n = last - first;
			size_t startpos = position - begin();
			size_t endpos = startpos + n;
			_size = _size + n;
			if (_size > _capacity)
			{
				if (_capacity == 0)
					reserve(1);
				else
					reserve(_size * 2);
			}
			for (unsigned int i = _size; i >= endpos; i--)
				_alloc.construct(&_vector[i], _vector[i - n]);
			for (unsigned int j = startpos; j < endpos; j++, first++)
				_alloc.construct(&_vector[j], *first);
			return ;
		}

		iterator erase (iterator first, iterator last)
		{
			size_t		size_delete = last - first;
			size_t 		position = first - begin();
			size_t 		startdel = 0;
			
			_size = _size - size_delete;
			for (size_t i = first - begin(); i < _size; i++)
			{	
				_alloc.construct(&_vector[i], _vector[i + size_delete]);
				startdel++;
			}
			for (size_type i = 0; i < size_delete; i++)
				_alloc.destroy(&_vector[i + startdel]);
			return (iterator(begin() + position));
		}

		iterator erase (iterator position)
		{
			iterator pos_nxt = position;
			pos_nxt++;
			return (erase(position, pos_nxt));
		}

		void swap (vector& x)
		{
			ft::swap(_vector, x._vector);
			ft::swap(_size, x._size);
			ft::swap(_capacity, x._capacity);
			ft::swap(_alloc, x._alloc);
		}

		void clear()
		{
			_alloc.destroy(_vector);
			_size = 0;
			_capacity = 0;
		}

		/* Allocator */
		allocator_type get_allocator() const { return _alloc; }

	private:
    	value_type* 	_vector;
		size_type		_size;
		size_type		_capacity;
		allocator_type	_alloc;
    };

	/* Non-member function overloads */
	template <class T, class Alloc>
	bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		return (ft::equal<typename ft::vector<T,Alloc>::const_iterator, typename ft::vector<T,Alloc>::const_iterator>(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (ft::equal<typename ft::vector<T,Alloc>::const_iterator, typename ft::vector<T,Alloc>::const_iterator>(lhs.begin(), lhs.end(), rhs.begin()) == true ||
		ft::lexicographical_compare<typename ft::vector<T,Alloc>::const_iterator, typename ft::vector<T,Alloc>::const_iterator>(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) == true)
			return false;
		return true;
	}

	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare<typename ft::vector<T,Alloc>::const_iterator, typename ft::vector<T,Alloc>::const_iterator>(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
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
		ft::swap(y._vector, x._vector);
		ft::swap(y._size, x._size);
		ft::swap(y._capacity, x._capacity);
		ft::swap(y._alloc, x._alloc);
	}
}

# endif
