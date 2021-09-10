#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP
#include <iostream>
#include "../iterators/random_access_iterator.hpp"

namespace ft {
    template<bool Cond, class T = void> struct enable_if {};
    template<class T> struct enable_if<true, T> { typedef T type; };

    template <bool is_iterator, typename T>
    struct iterator_result
    {
	    typedef T type;
	    static const bool value = is_iterator;
    };

    // template <typename Key, typename T>
    template <typename T>
    struct is_iterator { static const bool value = false; };
    template <>
    struct is_iterator<std::input_iterator_tag> : public iterator_result<true, std::input_iterator_tag> {};
    template <>
    struct is_iterator<std::output_iterator_tag> : public iterator_result<true, std::output_iterator_tag> {};
    template <>
    struct is_iterator<std::forward_iterator_tag> : public iterator_result<true, std::forward_iterator_tag> {};
    template <>
    struct is_iterator<std::bidirectional_iterator_tag> : public iterator_result<true, std::bidirectional_iterator_tag> {};
    // template <typename Key, typename T>
    // struct is_iterator<ft::bidirectional_iterator_tag<Key, T, T*, T&>> : public iterator_result<true, ft::bidirectional_iterator_tag<Key, T, T*, T&>> {};
    template <>
    struct is_iterator<std::random_access_iterator_tag> : public iterator_result<true, std::random_access_iterator_tag> {};
    template <class T>
    struct is_iterator<ft::random_access_iterator<T, T*, T&> > : public iterator_result<true, ft::random_access_iterator<T, T*, T&> > {};

    template <class T>
    struct is_integral { static const bool value = false; };
    template <>
    struct is_integral<bool> { static const bool value = true; };
    template <>
    struct is_integral<char> { static const bool value = true; };
    template <>
    struct is_integral<unsigned char> { static const bool value = true; };
    template <>
    struct is_integral<short> { static const bool value = true; };
    template <>
    struct is_integral<unsigned short> { static const bool value = true; };
    template <>
    struct is_integral<int> { static const bool value = true; };
    template <>
    struct is_integral<unsigned int> { static const bool value = true; };
    template <>
    struct is_integral<long> { static const bool value = true; };
    template <>
    struct is_integral<unsigned long> { static const bool value = true; };

	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};
    template <class Iterator>
    class iterator_traits {
        public:
		    typedef typename Iterator::difference_type					difference_type;
		    typedef typename Iterator::value_type						value_type;
		    typedef typename Iterator::pointer							pointer;
		    typedef typename Iterator::reference						reference;
		    typedef typename Iterator::iterator_category				iterator_category;
        };
    template <class T>
    class iterator_traits<T*> {
        public:
		    typedef std::ptrdiff_t              			            difference_type;
		    typedef T                  						            value_type;
		    typedef T*	                						        pointer;
		    typedef T&	                    					        reference;
		    typedef random_access_iterator_tag 				            iterator_category;
        };
    template <class T>
    class iterator_traits<const T*> {
        public:
		    typedef ptrdiff_t              					            difference_type;
		    typedef T                  						            value_type;
		    typedef const T*               						        pointer;
		    typedef const T&                 					        reference;
		    typedef random_access_iterator_tag 				            iterator_category;
        };

    template<class InputIterator>
    typename iterator_traits<InputIterator>::difference_type
    distance (InputIterator first, InputIterator last)
    {
        typename iterator_traits<InputIterator>::difference_type dist = 0;
        for (InputIterator n = first; n != last; n++)
            dist++;
        return (dist);
    }

    template <class T> struct less : std::binary_function <T,T,bool> {
    bool operator() (const T& x, const T& y) const {return x<y;}
    };
}

#endif 
