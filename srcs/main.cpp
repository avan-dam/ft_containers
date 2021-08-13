/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-dam <avan-dam@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/23 14:38:34 by avan-dam      #+#    #+#                 */
/*   Updated: 2021/08/13 14:25:27 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "containers/ft_vector.hpp"
#include "containers/ft_stack.hpp"
#include "containers/ft_map.hpp"
#include <math.h>
#include <vector>
#include <list>
#include <stack>
#include <map>


#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */


// compare timings

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

template <class Key, class T>
bool	print_false(std::map<Key, T> std, ft::map<Key, T> ft, std::string name_std, std::string name_ft)
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
	if (std.size() != ft.size()|| ft.capacity() != std.capacity() || ft.empty() != std.empty())
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

template <class Key, class T>
bool	same_map_ft_std_int(std::map<Key, T> std, ft::map<Key, T> ft, std::string name_std, std::string name_ft)
{
	if (std.size() != ft.size() || ft.empty() != std.empty())
		return (print_false(std, ft, name_ft, name_std));
 	typename std::map<Key, T>::iterator it_std = std.begin();
 	typename ft::map<Key, T>::iterator it_ft = ft.begin();
	while (it_std != std.end() && it_ft != ft.end())
	{
		if (it_ft->first != it_std->first || it_ft->second != it_std->second)
			return (print_false(std, ft, name_ft, name_std));
		it_std++;
		it_ft++;
	}
 	typename std::map<Key, T>::reverse_iterator it_r_std = std.rbegin();
 	typename ft::map<Key, T>::reverse_iterator it_r_ft = ft.rbegin();
	while (it_r_std != std.rend() && it_r_ft != ft.rend())
	{
		if (it_r_ft->first != it_r_std->first || it_r_ft->second != it_r_std->second)
			return (print_false(std, ft, name_ft, name_std));
		it_r_std++;
		it_r_ft++;
	}
 	typename std::map<Key, T>::const_iterator c_it_std = std.begin();
 	typename ft::map<Key, T>::const_iterator c_it_ft = ft.begin();
	while (c_it_std != std.end() && c_it_ft != ft.end())
	{
		if (c_it_ft->first != c_it_std->first || c_it_ft->second != c_it_std->second)
			return (print_false(std, ft, name_ft, name_std));
		c_it_std++;
		c_it_ft++;
	}
 	typename std::map<Key, T>::const_reverse_iterator c_it_r_std = std.rbegin();
 	typename ft::map<Key, T>::const_reverse_iterator c_it_r_ft = ft.rbegin();
	while (c_it_r_std != std.rend() && c_it_r_ft != ft.rend())
	{
		if (c_it_r_ft->first != c_it_r_std->first || c_it_r_ft->second != c_it_r_std->second)
			return (print_false(std, ft, name_ft, name_std));
		c_it_r_std++;
		c_it_r_ft++;
	}
	return (print_true(name_ft, name_std));
}

void    stack_tests()
{
    std::cout << "\n\nPERFORMING STACK TESTS:" << std::endl;
	std::cout << "calling constructors" << std::endl;
	std::list<int> list_std(1, 1);
  	std::vector<int> myvector_std (2,200);        // vector with 2 elements
  	ft::vector<int> myvector_ft (2,200);        // vector with 2 elements
	std::stack<int,std::list<int> > first_std(list_std);  // empty stack using vector
	ft::stack<int,std::list<int> > first_ft(list_std);  // empty stack using vector
  	std::stack<int,std::vector<int> > second_std (myvector_std);
  	ft::stack<int,std::vector<int> > second_ft (myvector_std);
	std::cout << "calling size size()" << std::endl;
	result_of_function_call(first_std.size(), first_ft.size(), "size()");
	result_of_function_call(second_std.size(), second_ft.size(), "size()");
	std::cout << "calling empty()" << std::endl;
	result_of_function_call(first_std.empty(), first_ft.empty(), "empty()");
	result_of_function_call(second_std.empty(), second_ft.empty(), "empty()");
  	std::stack<int> mystack_std;
  	ft::stack<int> mystack_ft;

	std::cout << "calling push()" << std::endl;
  	mystack_std.push(10);
  	mystack_ft.push(10);
  	mystack_std.push(20);
  	mystack_ft.push(20);

	std::cout << "calling top()" << std::endl;
	mystack_std.top() -= 5;
	mystack_ft.top() -= 5;
	result_of_function_call(mystack_std.top(), mystack_ft.top(), "top()");

	std::stack<int> mystack1_std;
	ft::stack<int> mystack1_ft;

	std::cout << "calling push()" << std::endl;
	for (int i=0; i<5; ++i) mystack1_std.push(i);
	for (int i=0; i<5; ++i) mystack1_ft.push(i);
	std::cout << "testing pop() and top() and empty()" << std::endl;
	while (!mystack1_std.empty() && !mystack1_ft.empty())
  	{
		result_of_function_call(mystack_std.top(), mystack_ft.top(), "top()");
    	mystack1_std.pop();
		mystack1_ft.pop();
  	}
	result_of_function_call(mystack1_std.empty(), mystack1_ft.empty(), "empty()");

	std::cout << "stack relational operator tests:" << std::endl;
	std::vector<int> vec_std(2, 20);
	ft::vector<int> vec_ft(2, 20);
	std::stack<int,std::vector<int> > ft1 (vec_std);
  	ft::stack<int,ft::vector<int> > std1;
	std::stack<int,std::vector<int> > ft2 (vec_std);
  	ft::stack<int,ft::vector<int> > std2;
	for (int i=0; i<1; ++i) ft2.push(2);
	for (int i=0; i<1; ++i) std2.push(2);
	result_of_function_call((ft1>ft2), (std1>std2), ">");
	result_of_function_call((ft1<ft2), (std1<std2), "<");
	result_of_function_call((ft1>=ft2), (std1>=std2), ">=");
	result_of_function_call((ft1<=ft2), (std1<=std2), "<=");
	result_of_function_call((ft1==ft2), (std1==std2), "==");
	result_of_function_call((ft1!=ft2), (std1!=std2), "!=");
}

void	map_key_compare()
{
	std::map<char,int> mymapstd1;
	ft::map<char,int> mymapft1;

  	mymapstd1['a']=100;
  	mymapft1['a']=100;
	mymapstd1['b']=200;
	mymapft1['b']=200;
	mymapstd1['c']=300;
	mymapft1['c']=300;

	std::cout << "now reverse" << std::endl;
	result_of_function_call(mymapft1['a'], mymapstd1['a'], "assignment operator calling 'a'");
	result_of_function_call(mymapft1['b'], mymapstd1['b'], "assignment operator calling 'b'");
	result_of_function_call(mymapft1['c'], mymapstd1['c'], "assignment operator calling 'c'");

	same_map_ft_std_int(mymapstd1, mymapft1, "mymapstd1", "mymapft1");

	std::map<char,std::string>	mymapstd;
  	ft::map<char,std::string>	mymapft;

  	mymapstd['a']="an element";
  	mymapft['a']="an element";
  	mymapstd['b']="another element";
  	mymapft['b']="another element";
  	mymapstd['c']=mymapstd['b'];
  	mymapft['c']=mymapft['b'];
	result_of_function_call(mymapft['a'], mymapstd['a'], "assignment operator calling 'a'");
	result_of_function_call(mymapft['b'], mymapstd['b'], "assignment operator calling 'b'");
	result_of_function_call(mymapft['c'], mymapstd['c'], "assignment operator calling 'c'");
	std::map<char,int>::key_compare mycompstd = mymapstd.key_comp();
	ft::map<char,int>::key_compare mycompft = mymapft.key_comp();

	std::cout << "mymapstd contains:\n";
	char highest = mymapstd1.rbegin()->first;     // key value of last element
	std::map<char,int>::iterator it = mymapstd1.begin();
	do {
    	std::cout << it->first << " => " << it->second << '\n';
	} while ( mycompstd((*it++).first, highest) );
	std::cout << '\n';
	std::cout << "mymapft contains:\n";
	char highesty = mymapft1.rbegin()->first;     // key value of last element
	ft::map<char,int>::iterator ity = mymapft1.begin();
  	do {
    	std::cout << ity->first << " => " << ity->second << '\n';
	} while ( mycompft((*ity++).first, highesty) );
	std::cout << '\n';

	// std::cout << "value comp" << std::endl;
    // std::map<char,int> mymapstd2;
    // ft::map<char,int> mymapft2;

	// mymapstd2['x']=1001;
	// mymapft2['x']=1001;
	// mymapstd2['y']=2002;
	// mymapft2['y']=2002;
	// mymapstd2['z']=3003;
	// mymapft2['z']=3003;

	// std::cout << "mymap contains:\n";

	// std::pair<char,int> higheststd1 = *mymapstd2.rbegin();          // last element
	// ft::pair<char,int> highestft1 = *mymapft2.rbegin();          // last element

	// std::map<char,int>::iterator itstd1 = mymapstd2.begin();
	// do {
    // 	std::cout << itstd1->first << " => " << itstd1->second << '\n';
	// } while ( mymapstd2.value_comp()(*itstd1++, higheststd1) );

	// ft::map<char,int>::iterator itftd1 = mymapft2.begin();
	// do {
    // 	std::cout << itftd1->first << " => " << itftd1->second << '\n';
	// } while ( mymapft2.value_comp()(*itftd1++, highestft1) );
}

void	map_insert_tests()
{
	std::cout << "in map insert test" << std::endl;
	std::map<char,int> mymapstd;
	ft::map<char,int> mymapft;

	// first insert function version (single parameter):
	mymapstd.insert ( std::pair<char,int>('a',100) );
	mymapft.insert ( ft::pair<char,int>('a',100) );
	mymapstd.insert ( std::pair<char,int>('z',200) );
	mymapft.insert ( ft::pair<char,int>('z',200) );

	std::pair<std::map<char,int>::iterator,bool> retstd;
	retstd = mymapstd.insert ( std::pair<char,int>('z',500) );
	if (retstd.second==false) {
    std::cout << "element 'z' already existed";
    std::cout << " with a value of " << retstd.first->second << '\n';
  	}
	ft::pair<ft::map<char,int>::iterator,bool> retft;
	retft = mymapft.insert ( ft::pair<char,int>('z',500) );
	if (retft.second==false) {
    std::cout << "element 'z' already existed";
    std::cout << " with a value of " << retft.first->second << '\n';
  	}

	// second insert function version (with hint position):
  std::map<char,int>::iterator itstd = mymapstd.begin();
  ft::map<char,int>::iterator itft = mymapft.begin();
  mymapstd.insert (itstd, std::pair<char,int>('b',300));  // max efficiency inserting
  mymapft.insert (itft, ft::pair<char,int>('b',300));  // max efficiency inserting
  mymapstd.insert (itstd, std::pair<char,int>('c',400));  // no max efficiency inserting
  mymapft.insert (itft, ft::pair<char,int>('c',400));  // no max efficiency inserting

  // third insert function version (range insertion):
  std::map<char,int> anothermap;
  ft::map<char,int> anothermapft;
  anothermap.insert(mymapstd.begin(),mymapstd.find('c'));
  anothermapft.insert(mymapft.begin(),mymapft.find('c'));

  // showing contents:
	same_map_ft_std_int(mymapstd, mymapft, "mymapstd", "mymapft");
	same_map_ft_std_int(anothermap, anothermapft, "anothermap", "anothermapft");

	result_of_function_call(mymapstd.upper_bound('b')->first, mymapft.upper_bound('b')->first, "mymapstd.upper_bound('b') && mymapft.upper_bound('b')->first");
	result_of_function_call(mymapstd.lower_bound('b')->first, mymapft.lower_bound('b')->first, "mymapstd.lower_bound('b') && mymapft.lower_bound('b')->first");
}

void	map_equal_range()
{
	std::map<char,int> mymapstd;
	ft::map<char,int> mymapft;

	mymapstd['a']=10;
	mymapft['a']=10;
	mymapstd['b']=20;
	mymapft['b']=20;
	mymapstd['c']=30;
	mymapft['c']=30;

//   std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> retstd;
//   ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> retft;
//   retstd = mymapstd.equal_range('b');
//   retft = mymapstd.equal_range('b');

//   std::cout << "lower bound points to: ";
//   std::cout << retstd.first->first << " => " << retstd.first->second << '\n';
//   std::cout << "lower bound FT points to: ";
//   std::cout << retft.first->first << " => " << retft.first->second << '\n';

//   std::cout << "upper bound points to: ";
//   std::cout << retstd.second->first << " => " << retstd.second->second << '\n';

//   std::cout << "upper bound points to: ";
//   std::cout << retstd.second->first << " => " << retstd.second->second << '\n';
}

void    map_tests()
{
    std::cout << "PERFORMING MAP TESTS:" << std::endl;
	ft::map<char, int> m;
	std::map<char, int> m2;

	std::map<char,int>::iterator it=m2.end();
	std::cout << "stdit = begin() it->first " << it->first << std::endl;

	ft::map<char,int>::iterator it3=m.end();
	std::cout << "it = end() it->first " << it3->first << std::endl;

	std::cout << "size of mine should be 0 is " << m.size() << std::endl;
	std::cout << "size of theirs should be 0 is " << m2.size() << std::endl;
	std::cout << "empty of mine is " << m.empty() << std::endl;
	std::cout << "empty of theirs is " << m2.empty() << std::endl;
	m.insert ( ft::pair<char,int>('b',100) );
	m2.insert ( std::pair<char,int>('b',100) );
	m.insert ( ft::pair<char,int>('a',2) );
	m2.insert ( std::pair<char,int>('a',2) );

	m.insert ( ft::pair<char,int>('c',500) );
	m2.insert ( std::pair<char,int>('c',500) );
	m.insert ( ft::pair<char,int>('l',100) );
	m2.insert ( std::pair<char,int>('l',100) );
	m.insert ( ft::pair<char,int>('d',2) );
	m2.insert ( std::pair<char,int>('d',2) );
	m.insert ( ft::pair<char,int>('p',500) );
	m2.insert ( std::pair<char,int>('p',500) );

	m2.insert ( std::pair<char,int>('y',500));
	m.insert ( ft::pair<char,int>('y',500));
	m2.insert ( std::pair<char,int>('f',100));
	m.insert ( ft::pair<char,int>('f',100));
	m2.insert ( std::pair<char,int>('h',2));
	m.insert ( ft::pair<char,int>('h',2));

	same_map_ft_std_int(m2, m, "m2", "m");

	std::map<char,int> secondstd (m2.begin(),m2.end());
	ft::map<char,int> secondft (m.begin(),m.end());

	same_map_ft_std_int(secondstd, secondft, "secondstd", "secondft");

	std::map<char,int> thirdstd (secondstd);
	ft::map<char,int> thirdft (secondft);
	same_map_ft_std_int(thirdstd, thirdft, "thirdstd", "thirdft");
	thirdstd.clear();
	thirdft.clear();
	// same_map_ft_std_int(thirdstd, thirdft, "thirdstd", "thirdft");

	std::map<char,int> fourthstd = secondstd;
	ft::map<char,int> fourthft = secondft;
	same_map_ft_std_int(fourthstd, fourthft, "fourthstd", "fourthft");
	std::cout << "std max size is  " << fourthstd.max_size() << std::endl;
	std::cout << "my max size is  " << fourthft.max_size() << std::endl;

	std::map<char,int> fifthstd;
	ft::map<char,int> fifthft;
	// same_map_ft_std_int(fifthstd, fifthft, "fifthstd", "fifthft"); 
	// when empty does not work

  	std::map<char,std::string> mymapstd4;
  	ft::map<char,std::string> mymapft4;
  	mymapstd4['a']="an element";
  	mymapft4['a']="an element";
  	mymapstd4['b']="another element";
  	mymapft4['b']="another element";
  	mymapstd4['c']=mymapstd4['b'];
  	mymapft4['c']=mymapft4['b'];
  
	result_of_function_call(mymapft4['a'], mymapstd4['a'], "mymapft4['a'] and mymapstd4['a']");
	result_of_function_call(mymapft4['b'], mymapstd4['b'], "mymapft4['b'] and mymapstd4['b']");
	result_of_function_call(mymapft4['c'], mymapstd4['c'], "mymapft4['c'] and mymapstd4['c']");
	result_of_function_call(mymapft4['d'], mymapstd4['d'], "mymapft4['d'] and mymapstd4['d']");

	same_map_ft_std_int(mymapstd4, mymapft4, "mymapft4", "mymapstd4");

	result_of_function_call(mymapft4.count('c'), mymapstd4.count('c'), "mymapft4and mymapstd4 .count('c')");
	result_of_function_call(mymapft4.count('y'), mymapstd4.count('y'), "mymapft4and mymapstd4 .count('y')");
	result_of_function_call(mymapft4.find('c')->first, mymapstd4.find('c')->first, "mymapft4and mymapstd4 .find('c')->first");
	result_of_function_call(mymapft4.find('y')->first, mymapstd4.find('y')->first, "mymapft4and mymapstd4 .find('y')->first");

	map_key_compare();
	map_insert_tests();
	map_equal_range();
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
	std::cout << "until here" << std::endl;
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
	same_vecor_ft_std_int(first_std, first_ft, "first_std", "first_ft");
	same_vecor_ft_std_int(second_std, second_ft, "second_std", "second_ft");
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
	myvector_std.erase (first_std);
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
        // if (argc == 1 || strcmp(argv[1], "vector") == 0)
        //     vector_tests();
        if (argc == 1 || strcmp(argv[1], "map") == 0)
            map_tests();
		// if (argc == 1 || strcmp(argv[1], "stack") == 0)
        //     stack_tests();
        else if (argc == 2 && strcmp(argv[1], "vector") != 0
			&& strcmp(argv[1], "map") != 0 
			&& strcmp(argv[1], "stack") != 0)
           std::cout << "invalid arguments" << std::endl;
    }
    else
        std::cout << "invalid arguments" << std::endl;
	// while (1) {} // testing mem leaks
    return (0);
}
