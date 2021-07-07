#ifndef MORE_HPP
#define MORE_HPP

namespace ft {
    template<class InputIterator>
    typename iterator_traits<InputIterator>::difference_type
    distance (InputIterator first, InputIterator last)
    {
        typename iterator_traits<InputIterator>::difference_type dist = 0;
        for (InputIterator n = first; n != last; n++)
            dist++;
        return (dist);
    }
}

#endif
