/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pair.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/05 09:51:31 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/08/12 18:23:34 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PAIR_HPP
# define FT_PAIR_HPP

namespace ft {
template <class T1, class T2> struct pair 
{
    public:
		typedef T1		first_type; 
		typedef	T2		second_type; 

        first_type  first;
        second_type second;
        
        // constructors
        pair() : first(), second() {}
        template<class U, class V>
        pair(const pair<U,V>& pr) : first(pr.first), second(pr.second) {}
        pair (const first_type& a, const second_type& b) : first(a), second(b) {}
        // assignment operator
        pair& operator= (const pair& pr)
        {
            if (first != pr.first || second != pr.second)
            {
                first = pr.first;
                second = pr.second;
            }
            return *this;
        }
};

    template <class T1, class T2>
    pair<T1,T2> make_pair (T1 x, T2 y)
    {
        return (ft::pair<T1, T2>(x, y));
    }

	template <class T1, class T2>
	bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {   return lhs.first==rhs.first && lhs.second==rhs.second;  }

	template <class T1, class T2>
	bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{   return !(lhs < rhs);    }
    
    template <class T1, class T2>
    bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

    template <class T1, class T2>
    bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {   return !(rhs<lhs);  }

    template <class T1, class T2>
    bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {   return rhs<lhs; }

    template <class T1, class T2>
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {   return !(lhs<rhs);  }
}

#endif
