/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enable_if.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ambervandam <ambervandam@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/03 10:42:36 by ambervandam   #+#    #+#                 */
/*   Updated: 2021/06/03 19:11:13 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP
#include "ft_list.hpp"

#include <iostream>

namespace ft {
    template<bool B, class T = void>
    struct enable_if;
 
    template<class T>
    struct enable_if<true, T> {
        typedef T type; 
};
// template<class T>
// struct is_arithmetic : std::integral_constant < bool,
        //  std::is_integral<T>::value || std::is_floating_point<T>::value > {};
    template<typename T, typename C = typename<template is_arithmetic<T>>
    struct is_arithmetic {
        typedef char yes[1];
        typedef char no[2];

        static yes& test(std::is_arithmetic<T>);
        static no& test(...);

        static const bool value = (sizeof(test(C())) == sizeof(yes));
    };
}

#endif
