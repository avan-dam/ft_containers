#ifndef FT_STACK_HPP
# define FT_STACK_HPP

#include "ft_vector.hpp"
#include <deque>

namespace ft {
    template <class T, class Container = ft::vector<T> >
    class stack {
        public:
            typedef	T			value_type; 
            typedef Container   container_type;
            typedef size_t      size_type;

            /* Member functions */
            explicit stack (const container_type& ctnr = container_type()) : _storaged(ctnr) {}
            bool empty() const { return(_storaged.empty());}
            size_type size() const { return(_storaged.size());}
            value_type& top() { return(_storaged.back());}
            const value_type& top() const { return(_storaged.back());}
            void push (const value_type& val) { return(_storaged.push_back(val));}
            void pop() { return(_storaged.pop_back());}
        protected:
            Container    _storaged;
        /* relational operators */
        /* uses friend as needs access to private members _storaged*/
        /* Friend functions are not considered class members */
        friend bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
        {
            return (lhs._storaged == rhs._storaged);
        }
        friend bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
        {
            return (lhs._storaged != rhs._storaged);
        }
        friend bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
        {
            return (lhs._storaged < rhs._storaged);
        }
        friend bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
        {
            return (lhs._storaged <=rhs._storaged);
        }
        friend bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
        {
            return (lhs._storaged > rhs._storaged);
        }
        friend bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
        {
            return (lhs._storaged >= rhs._storaged);
        }
};

}

#endif
