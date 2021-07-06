/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-dam <avan-dam@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/23 14:38:34 by avan-dam      #+#    #+#                 */
/*   Updated: 2021/07/06 19:52:53 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.hpp"
#include <math.h>
#include <vector>

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */

template <class T>
void	result_of_function_call(T result_std , T result_ft, std::string function_name)
{
	if (result_std == result_ft)
		std::cout << GREEN << "result from " <<  function_name << " was the same for std and ft" << RESET << std::endl;
	else
		std::cout << RED << "result from " <<  function_name << " was NOT the same for std and ft" << RESET << std::endl;
}
	
template <class T>
bool	print_false(std::vector<T> std, ft::vector<T> ft, std::string name_std, std::string name_ft)
{
	std::cout << RED << name_std << " and " << name_ft << " are NOT equal" << std::endl;
	std::cout << "ft  container :";
	for (unsigned int i = 0; i < ft.size(); i++)
    	std::cout << ' ' << ft[i];
	std::cout << std::endl;
	std::cout << "std container :";
	for (unsigned int i = 0; i < std.size(); i++)
    	std::cout << ' ' << ft[i];
	std::cout << RESET << std::endl;
	return false;
}

bool	print_true(std::string name_std, std::string name_ft)
{
	std::cout << GREEN << name_std << " and " << name_ft << " are equal" << RESET << std::endl;
	return false;
}

template <class T>
bool	same_vecor_ft_std_int(std::vector<T> std, ft::vector<T> ft, std::string name_std, std::string name_ft)
{
	if (std.size() != ft.size() || ft.capacity() != std.capacity() || ft.empty() != std.empty())
		return (print_false(std, ft, name_ft, name_std));
	for (unsigned int i = 0; i < ft.size(); i++)
	{
		if (ft[i] != std[i])
			return (print_false(std, ft, name_ft, name_std));
	}
 	typename std::vector<T>::iterator it_std = std.begin();
 	typename ft::vector<T>::iterator it_ft = ft.begin();
	while (it_std != std.end() && it_ft != ft.end())
	{
		if (*it_std != *it_ft)
			return (print_false(std, ft, name_ft, name_std));
		it_std++;
		it_ft++;
	}
 	typename std::vector<T>::reverse_iterator it_r_std = std.rbegin();
 	typename ft::vector<T>::reverse_iterator it_r_ft = ft.rbegin();
	while (it_r_std != std.rend() && it_r_ft != ft.rend())
	{
		if (*it_r_std != *it_r_ft)
			return (print_false(std, ft, name_ft, name_std));
		it_r_std++;
		it_r_ft++;
	}
 	typename std::vector<T>::const_iterator c_it_std = std.begin();
 	typename ft::vector<T>::const_iterator c_it_ft = ft.begin();
	while (c_it_std != std.end() && c_it_ft != ft.end())
	{
		if (*c_it_std != *c_it_ft)
			return (print_false(std, ft, name_ft, name_std));
		c_it_std++;
		c_it_ft++;
	}
 	typename std::vector<T>::const_reverse_iterator c_it_r_std = std.rbegin();
 	typename ft::vector<T>::const_reverse_iterator c_it_r_ft = ft.rbegin();
	while (c_it_r_std != std.rend() && c_it_r_ft != ft.rend())
	{
		if (*c_it_r_std != *c_it_r_ft)
			return (print_false(std, ft, name_ft, name_std));
		c_it_r_std++;
		c_it_r_ft++;
	}


	return (print_true(name_ft, name_std));
}

void    stack_tests()
{
    std::cout << "PERFORMING STACK TESTS:" << std::endl;
}

void    map_tests()
{
    std::cout << "PERFORMING MAP TESTS:" << std::endl;
}

void vector_constructor()
{
	std::cout << "\ncalling vector vector_constructor fucntions" << std::endl;

	std::vector<int> first_std;
	ft::vector<int> first_ft;
	std::vector<int> second_std (4,100);
	ft::vector<int> second_ft (4,100);
	std::vector<int> third_std (second_std.begin(),second_std.end());
	ft::vector<int> third_ft (second_ft.begin(),second_ft.end());
	std::vector<int> fourth_std (second_std);
	ft::vector<int> fourth_ft (second_ft);

	same_vecor_ft_std_int(first_std, first_ft, "first_std", "first_ft");
	same_vecor_ft_std_int(second_std, second_ft, "second_std", "second_ft");
	same_vecor_ft_std_int(third_std, third_ft, "third_std", "third_ft");
	same_vecor_ft_std_int(fourth_std, fourth_ft, "fourth_std", "fourth_ft");
}

void	vector_assigment_opperator()
{
	std::cout << "\ncalling vector vector_assigment_opperator fucntions" << std::endl;
	std::vector<int> foo_std (3,0);
	std::vector<int> bar_std (5,0);
  	ft::vector<int> foo_ft (3,0);
  	ft::vector<int> bar_ft (5,0);

  	bar_std = foo_std;
  	bar_ft = foo_ft;
  	foo_std = std::vector<int>();
  	foo_ft = ft::vector<int>();

	same_vecor_ft_std_int(foo_std, foo_ft, "foo_std", "foo_ft");
	same_vecor_ft_std_int(bar_std, bar_ft, "bar_std", "bar_ft");
}

void	vector_capacity()
{
	std::cout << "\ncalling vector vector_capacity fucntions" << std::endl;
	std::cout << "Size function:" << std::endl;
	std::vector<int> first_std;
	ft::vector<int> first_ft;
	std::vector<int> second_std(4, 100);
	ft::vector<int> second_ft(4, 100);

	same_vecor_ft_std_int(first_std, first_ft, "first_std", "first_ft");
	same_vecor_ft_std_int(second_std, second_ft, "second_std", "second_ft");
	
	std::cout << "\nResize function:" << std::endl;
	std::vector<int> third_std;
	ft::vector<int> third_ft;
	for (int i=1;i<10;i++) third_std.push_back(i);
	for (int i=1;i<10;i++) third_ft.push_back(i);

	third_std.resize(5);
	third_ft.resize(5);
	third_std.resize(4,100);
	third_ft.resize(4,100);
	third_std.resize(10,100);
	third_ft.resize(10,100);
	third_std.resize(12);
	third_ft.resize(12);

	same_vecor_ft_std_int(third_std, third_ft, "third_std", "third_ft");
	std::vector<int>::size_type sz_std;
	ft::vector<int>::size_type sz_ft;

	std::vector<int> foo_std;
	ft::vector<int> foo_ft;
	sz_std = foo_std.capacity();
	sz_ft = foo_ft.capacity();	
	for (int i=0; i<100; ++i) {
    	foo_std.push_back(i);
		if (sz_std!=foo_std.capacity())
			sz_std = foo_std.capacity();
  		}
	for (int i=0; i<100; ++i) {
    	foo_ft.push_back(i);
		if (sz_ft!=foo_ft.capacity()) 
			sz_ft = foo_ft.capacity();
    	}
	same_vecor_ft_std_int(foo_std, foo_ft, "foo_std", "foo_ft");
  	std::vector<int> bar_std;
  	ft::vector<int> bar_ft;
	sz_std = bar_std.capacity();
	sz_ft = bar_ft.capacity();
	bar_std.reserve(100);
	bar_ft.reserve(100);
	for (int i=0; i<100; ++i) {
    	bar_std.push_back(i);
    	if (sz_std!=bar_std.capacity()) 
    		sz_std = bar_std.capacity();
 	 	}
  	for (int i=0; i<100; ++i) {
    	bar_ft.push_back(i);
    	if (sz_ft!=bar_ft.capacity())
	    	 sz_ft = bar_ft.capacity();
	}
	same_vecor_ft_std_int(bar_std, bar_ft, "bar_std", "bar_ft");
}

void	vector_assign()
{
	std::cout << "\ncalling vector vector_assign functions" << std::endl;
	std::vector<int> first_std;
	ft::vector<int> first_ft;
	std::vector<int> second_std;
	ft::vector<int> second_ft;
	std::vector<int> third_std;
	ft::vector<int> third_ft;

	first_std.assign (7,100);             // 7 ints with a value of 100
	first_ft.assign (7,100);             // 7 ints with a value of 100
	std::vector<int>::iterator it =first_std.begin(); it++;
	ft::vector<int>::iterator it_ft =first_ft.begin(); it_ft++;
	second_std.assign (it,first_std.end());
	second_ft.assign (it_ft ,first_ft.end());
	int myints[] = {1776,7,4};
  	third_std.assign (myints,myints+3);   // assigning from array.
  	third_ft.assign (myints,myints+3);
	same_vecor_ft_std_int(first_std, first_ft, "first_std", "first_ft");
	same_vecor_ft_std_int(second_std, second_ft, "second_std", "second_ft");
	same_vecor_ft_std_int(third_std, third_ft, "third_std", "third_ft");
}

void	vector_push_n_pop_back()
{
	std::cout << "\ncalling vector vector_push_n_pop_back functions" << std::endl;
	std::vector<int> first_std;
	ft::vector<int> first_ft;

	for (int i=1;i<10;i++) first_std.push_back(i);
	for (int i=1;i<10;i++) first_ft.push_back(i);
	same_vecor_ft_std_int(first_std, first_ft, "first_std", "first_ft");

	std::vector<int> second_std;
	ft::vector<int> second_ft;
	int sum_std (0);
	int sum_ft (0);
	second_std.push_back (100);
	second_ft.push_back (100);
	second_std.push_back (200);
	second_ft.push_back (200);
	second_std.push_back (300);
	second_ft.push_back (300);
	same_vecor_ft_std_int(second_std, second_ft, "second_std", "second_ft");
	while (!second_std.empty())
	{
    	sum_std+=second_std.back();
    	second_std.pop_back();
  	}
	while (!second_ft.empty())
	{
    	sum_ft+=second_ft.back();
    	second_ft.pop_back();
  	}
	result_of_function_call(sum_ft, sum_std, "adding up all elements");
	same_vecor_ft_std_int(second_std, second_ft, "second_std", "second_ft");
}

void	vector_element_access()
{
	std::cout << "\ncalling vector vector_element_access functions" << std::endl;
	std::cout << "operator[] functions" << std::endl;
	std::vector<int> myvector_std (10, 10);
	ft::vector<int> myvector_ft (10, 10);

  	std::vector<int>::size_type sz_std = myvector_std.size();
  	ft::vector<int>::size_type sz_ft = myvector_ft.size();
	for (unsigned i=0; i<sz_std; i++) myvector_std[i]=i;
	for (unsigned i=0; i<sz_ft; i++) myvector_ft[i]=i;
  	for (unsigned i=0; i<sz_std/2; i++)
  	{
    	int temp = myvector_std[sz_std-1-i];
    	myvector_std[sz_std-1-i]=myvector_std[i];
    	myvector_std[i]=temp;
  	}
  	for (unsigned i=0; i<sz_ft/2; i++)
  	{
    	int temp = myvector_ft[sz_ft-1-i];
    	myvector_ft[sz_ft-1-i]=myvector_ft[i];
    	myvector_ft[i]=temp;
  	}
	same_vecor_ft_std_int(myvector_std, myvector_ft, "myvector_std", "myvector_ft");
	std::cout << "at functions" << std::endl;
	std::vector<int> std_vector (10);   // 10 zero-initialized ints
	ft::vector<int> ft_vector (10);   // 10 zero-initialized ints
  	for (unsigned i=0; i<std_vector.size(); i++)
   		std_vector.at(i)=i;
  	for (unsigned i=0; i<ft_vector.size(); i++)
   		ft_vector.at(i)=i;
	same_vecor_ft_std_int(std_vector, ft_vector, "std_vector", "ft_vector");
	std::cout << "front functions and back" << std::endl;
	std::vector<int> vector_std;
	ft::vector<int> vector_ft;
	vector_std.push_back(78);
	vector_ft.push_back(78);
	vector_std.push_back(16);
	vector_ft.push_back(16);
	vector_std.front() -= vector_std.back();
	vector_ft.front() -= vector_ft.back();
	result_of_function_call(vector_std.front(), vector_ft.front(), "front");
	result_of_function_call(vector_std.back(), vector_ft.back(), "front");
	std::vector<int> vector_std2;
	ft::vector<int> vector_ft2;
	vector_std2.push_back(10);
	vector_ft2.push_back(10);
	while (vector_std2.back() != 0)
	    vector_std2.push_back ( vector_std2.back() -1 );
	while (vector_ft2.back() != 0)
	    vector_ft2.push_back ( vector_ft2.back() -1 );
	same_vecor_ft_std_int(vector_std2, vector_ft2, "vector_std2", "vector_ft2");
	result_of_function_call(vector_std.front(), vector_ft.front(), "front");
	result_of_function_call(vector_std.back(), vector_ft.back(), "front");
}

void	vector_insert()
{
	std::cout << "\ncalling vector vector_insert functions" << std::endl;
	std::vector<int> myvector_std (3,100);
	ft::vector<int> myvector_ft (3,100);
	std::vector<int>::iterator it_std;
	ft::vector<int>::iterator it_ft;

	it_std = myvector_std.begin(); it_std++; it_std++;it_std++;// it_std++;
	it_ft = myvector_ft.begin(); it_ft++; it_ft++; it_ft++; //it_ft++;
	it_std = myvector_std.insert ( it_std , 200 );
	it_ft = myvector_ft.insert ( it_ft , 200 );
	result_of_function_call(*it_std, *it_ft, "insert");
	myvector_std.insert (it_std,2,300);
	myvector_ft.insert (it_ft,2,300);
	same_vecor_ft_std_int(myvector_std, myvector_ft, "myvector_std", "myvector_ft");

	it_std = myvector_std.begin();
	it_ft = myvector_ft.begin();
	std::vector<int> anothervector_std (2,400); it_std++; it_std++;
	ft::vector<int> anothervector_ft (2,400); it_ft++; it_ft++;
	myvector_std.insert (it_std,anothervector_std.begin(),anothervector_std.end());
	myvector_ft.insert (it_ft,anothervector_ft.begin(),anothervector_ft.end());
	same_vecor_ft_std_int(myvector_std, myvector_ft, "myvector_std", "myvector_ft");
}

void 	vector_erase()
{
	std::cout << "\ncalling vector_erase functions" << std::endl;
	std::vector<int> myvector_std;
	ft::vector<int> myvector_ft;
	for (int i=1; i<=10; i++) myvector_std.push_back(i);
	for (int i=1; i<=10; i++) myvector_ft.push_back(i);

	std::vector<int>::iterator first_std = myvector_std.begin(); first_std++;
	ft::vector<int>::iterator first_ft = myvector_ft.begin(); first_ft++;
	std::vector<int>::iterator last_std = myvector_std.begin(); last_std++; last_std++; last_std++;
	ft::vector<int>::iterator last_ft = myvector_ft.begin(); last_ft++; last_ft++; last_ft++;
	
	std::vector<int>::iterator result_std = myvector_std.erase (first_std,last_std);  // erase the first 3 elements:
	ft::vector<int>::iterator result_ft = myvector_ft.erase (first_ft,last_ft);  // erase the first 3 elements:
	result_of_function_call(*result_std, *result_ft, "erase");
	first_std = myvector_std.end(); first_std--;
	first_ft = myvector_ft.end(); first_ft--;
	myvector_std.erase (first_std);  // erase the first 3 elements:
	myvector_ft.erase (first_ft);
	same_vecor_ft_std_int(myvector_std, myvector_ft, "myvector_std", "myvector_ft");
}

void	vector_swap()
{
	std::cout << "\ncalling vector_swap functions" << std::endl;
	std::vector<int> foo_std (3,100);
	ft::vector<int> foo_ft (3,100);
	std::vector<int> bar_std (5,200);
	ft::vector<int> bar_ft (5,200);

	foo_std.swap(bar_std);
	foo_ft.swap(bar_ft);

	same_vecor_ft_std_int(bar_std, bar_ft, "bar_std", "bar_ft");
	same_vecor_ft_std_int(foo_std, foo_ft, "foo_std", "foo_ft");
}

void	vector_relational_operators()
{
	std::cout << "\ncalling vector_relational_operators functions" << std::endl;
	ft::vector<int> ft_vectort1 (1, 100);
	ft::vector<int> ft_vector2(1, 100);
	ft_vectort1.push_back (3);
  	ft_vector2.push_back (3);
	ft_vectort1.push_back (4);
  	ft_vector2.push_back (4);
	std::vector<int> std_vector1(1, 100);
	std::vector<int> std_vector2(1, 100);
	std_vector1.push_back (3);
  	std_vector2.push_back (3);
	std_vector1.push_back (4);
  	std_vector2.push_back (4);
	result_of_function_call((ft_vectort1>ft_vector2), (std_vector1>std_vector2), ">");
	result_of_function_call((ft_vectort1<ft_vector2), (std_vector1<std_vector2), "<");
	result_of_function_call((ft_vectort1>=ft_vector2), (std_vector1>=std_vector2), ">=");
	result_of_function_call((ft_vectort1<=ft_vector2), (std_vector1<=std_vector2), "<=");
	result_of_function_call((ft_vectort1==ft_vector2), (std_vector1==std_vector2), "==");
	result_of_function_call((ft_vectort1!=ft_vector2), (std_vector1!=std_vector2), "!=");
}

void	vector_tests()
{
    std::cout << "PERFORMING VECTOR TESTS:" << std::endl;
	vector_constructor();
	vector_assigment_opperator();
	vector_capacity();
	vector_element_access();
	vector_assign();
	vector_push_n_pop_back();
	vector_insert();
	vector_erase();
	vector_swap();
	vector_relational_operators();
}
int    main(int argc, char **argv)
{
    if (argc == 1 || argc == 2)
    {
        if (argc == 1 || strcmp(argv[1], "vector") == 0)
            vector_tests();
    //     else if (argc == 1 || strcmp(argv[1], "map") == 0)
    //         map_tests();
    //     else if (argc == 1 || strcmp(argv[1], "stack") == 0)
    //         stack_tests();
        else
           std::cout << "invalid arguments" << std::endl;
    }
    else
        std::cout << "invalid arguments" << std::endl;
	// while (1) {} // testing mem leaks
    return (0);
}
