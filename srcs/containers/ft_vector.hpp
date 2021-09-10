/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vector.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 12:04:40 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/09/10 11:41:20 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

#include "../iterators/reverse_iterator.hpp"
#include "../utils/type_traits.hpp"
// #include "../utils/more.hpp"
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
			:  _vector(nullptr), _size(0), _capacity(0), _alloc(alloc) {}
		
        vector(size_type n, const value_type& val = value_type(),
                	const allocator_type& alloc = allocator_type()) : _alloc(alloc)
        {
            _size = n;
            _capacity = n;
            _vector = new value_type[_capacity];
            for (size_t i = 0; i < n; i++)
                _vector[i] = val;
        }
		
		template <class InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
        typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0) : _alloc(alloc)
        {
			int i;

			i = 0;
			_size = distance(first, last);
            _capacity = _size;
			if (_size == 0)
			{
				_vector = nullptr;
				return;
			}
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
			if (_size == 0)
			{
				_vector = nullptr;
				return;
			}
            _vector = new value_type[_capacity];  
            for (size_t i = 0; i < _size; i++)
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
            for (size_t i = 0; i < _size; i++)
                _vector[i] = x[i];
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
			if (n > _capacity)
			{
				vector<T,Alloc>		tmp(begin(), end());
				if (_capacity != 0 && _size != 0 && _vector != nullptr)
					delete [] _vector;
				_capacity = n;
				_vector = new value_type[_capacity];
            	for (size_t i = 0; i < _size; i++)
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
            for (size_t i = 0; i < _size; i++)
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
            for (size_t i = 0; i < _size; i++)
                _vector[i] = val;
        }

		void push_back (const value_type& val)
		{
			reserve(_size + 1);
			_vector[_size] = val;
			_size++;
		}

		void	pop_back()	{	_size--; }

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
                    typename ft::enable_if<ft::is_iterator<InputIterator>::value >::type* = 0)
                    // typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
		{
			vector<T,Alloc>		newvector(first, last);
			insert_vector_helper(newvector, position);
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
			loop = begin();
			for (size_type k = 0; k != i; k++)
				loop++;
			while (i < _size)
			{
				_vector[i] = copyvector[i + size_delete];
				i++;
			}
			return (loop);
		}
		iterator erase (iterator position)
		{
			iterator pos_nxt = position;
			pos_nxt++;
			return (erase(position, pos_nxt));
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

		/* helper functions */
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
			vector<T,Alloc>					vector_start(begin(), position);
			vector<T,Alloc>					vector_end(position, end());
			ft::vector<T,Alloc>::iterator	ret;

			if (!empty())
				clear();
			if (!vector_start.empty())
				insert_newvector(vector_start);
			if (!newvector.empty())
				insert_newvector(newvector);
			ret = iterator(&_vector[_size - 1]);
			if (!vector_end.empty())
				insert_newvector(vector_end);
			return (ret);
		}
    };
// (InputIterator1 first1, InputIterator1 last1,
//                                 InputIterator2 first2, InputIterator2 last2)
	/* Non-member function overloads */
	template <class T, class Alloc>
	bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
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
		ft::vector<T,Alloc> tempthislist(y.begin(), y.end());
		y.assign(x.begin(), x.end());
		x.clear();
		x.assign(tempthislist.begin(), tempthislist.end());
	}
}

# endif

// less than uses the lexoco graphical compare
