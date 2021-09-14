/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_iterator.hpp                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/07 16:26:04 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/09/13 22:04:51 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "../utils/type_traits.hpp"

namespace ft {
template <class Iterator>
class reverse_iterator
{
    public:
		typedef	Iterator		                                            iterator_type;
        typedef typename ft::iterator_traits<Iterator>::iterator_category   iterator_category;
        typedef typename ft::iterator_traits<Iterator>::value_type	        value_type;
        typedef typename ft::iterator_traits<Iterator>::difference_type	    difference_type;
        typedef typename ft::iterator_traits<Iterator>::pointer	            pointer;
        typedef typename ft::iterator_traits<Iterator>::reference	        reference;
    private:
        iterator_type _cnt;
    public:
    /* constructors */
    reverse_iterator() : _cnt() {}
    explicit reverse_iterator (iterator_type it) : _cnt(it) {}
    template <class Iter>
    reverse_iterator (const reverse_iterator<Iter>& rev_it) {_cnt = rev_it.base();}
    /* deconstructor */
    ~reverse_iterator() {}
    /* assignment operator */
    reverse_iterator& operator= (const reverse_iterator& x)
    {
        _cnt = x.base();
		return *this;
    }
    /* get content */
    iterator_type base() const { return _cnt; }
    /*operators*/
    reference operator*() const
    {
        iterator_type   tmp = _cnt;
        --tmp;
        return (*tmp);
    }
    reverse_iterator operator+ (difference_type n) const
    {
        return(reverse_iterator(_cnt - n));
    }
    reverse_iterator& operator++()
    {
        _cnt--;
        return *this;
    }
    // check this
    reverse_iterator operator++(int) {
    reverse_iterator temp = *this;
    ++(*this);
    return temp;
    }
    reverse_iterator& operator+= (difference_type n)
    {
        _cnt -= n;
        return *this;
    }
    reverse_iterator operator- (difference_type n) const
    {
        return(reverse_iterator(_cnt + n));
    }
    reverse_iterator& operator--()
    {
        _cnt++;
        return *this;
    }
    reverse_iterator  operator--(int)
    {
        reverse_iterator temp = *this; 
        --(*this);
        return temp;  
    }
    reverse_iterator& operator-= (difference_type n)
    {
        _cnt += n;
        return *this;   
    }
    pointer operator->() const
    {
        return &(operator*());
    }
    reference operator[] (difference_type n) const
    {
        iterator_type   tmp = _cnt - n;
        return (*(--tmp));
    }
};

template <class Iterator>
bool operator== (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs)
{
   	return (lhs.base() == rhs.base());
}

template <class Iterator>
bool operator!= (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs)
{
    return (lhs.base() != rhs.base()); 
}

template <class Iterator>
bool operator<  (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs)
{
    return (lhs.base() > rhs.base());
}
template <class Iterator>
  bool operator<= (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs)
{
	return !(lhs.base() >= rhs.base());
}

template <class Iterator>
  bool operator>  (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs)
{
    return (lhs.base() < rhs.base());
}

template <class Iterator>
  bool operator>= (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs)
{
	return !(lhs.base() <= rhs.base());
}

template <class Iterator>
reverse_iterator<Iterator> operator+ (
             typename reverse_iterator<Iterator>::difference_type n,
             const reverse_iterator<Iterator>& rev_it)
{
    return (rev_it + n);
}

template <class Iterator>
typename reverse_iterator<Iterator>::difference_type operator- (
    const reverse_iterator<Iterator>& lhs,
    const reverse_iterator<Iterator>& rhs)
{
    return(rhs.base() - lhs.base());
}
}

#endif
