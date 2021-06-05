/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-dam <avan-dam@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/23 14:38:34 by avan-dam      #+#    #+#                 */
/*   Updated: 2021/06/05 10:29:11 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.hpp"
#include "list_node.hpp"
#include "list_iterator.hpp"
#include <list>
#include <vector>

void    queue_tests()
{
    std::cout << "PERFORMING QUEUE TESTS:" << std::endl;
}

void    stack_tests()
{
    std::cout << "PERFORMING STACK TESTS:" << std::endl;
}

void    map_tests()
{
    std::cout << "PERFORMING MAP TESTS:" << std::endl;
}

void    vector_tests()
{
    std::cout << "PERFORMING VECTOR TESTS:" << std::endl;
}

int	list_constructor() // and begin and end and iterator tested here and rend and rbegin
{
	std::cout << "Calling list constructors:" << std::endl;
	std::list<int> first_std;													// empty list of ints
	ft::list<int> first_ft;
	std::list<int> second_std (4,100);											// four ints with value 100
	ft::list<int> second_ft (4,100);  
	std::list<int> third_std (second_std.begin(),second_std.end());				// iterating through second
	ft::list<int> third_ft (second_ft.begin(),second_ft.end());					// iterating through second
	std::list<int> fourth_std (third_std);                       				// a copy of third
	ft::list<int> fourth_ft (third_ft);  	                  					// a copy of third

	std::cout << "The contents of first_std are: ";
  	for (std::list<int>::iterator it = first_std.begin(); it != first_std.end(); it++)
    	std::cout << *it << ' ';
	std::cout << '\n';
	std::cout << "The contents of first_ft are : ";
  	for (ft::list<int>::iterator it1 = first_ft.begin(); it1 != first_ft.end(); it1++)
    	std::cout << *it1 << ' ';
	std::cout << '\n';
	std::cout << "The contents of second_std are: ";
  	for (std::list<int>::iterator it2 = second_std.begin(); it2 != second_std.end(); it2++)
    	std::cout << *it2 << ' ';
	std::cout << '\n';
	std::cout << "The contents of second_ft are : ";
  	for (ft::list<int>::iterator it3 = second_ft.begin(); it3 != second_ft.end(); it3++)
    	std::cout << *it3 << ' ';
	std::cout << '\n';
	std::cout << "The contents of third_std are: ";
  	for (std::list<int>::iterator it4 = third_std.begin(); it4 != third_std.end(); it4++)
    	std::cout << *it4 << ' ';
	std::cout << '\n';
	std::cout << "The contents of third_ft are : ";
  	for (ft::list<int>::iterator it5 = third_ft.begin(); it5 != third_ft.end(); it5++)
    	std::cout << *it5 << ' ';
	std::cout << '\n';
	std::cout << "The contents of fourth_std are: ";
  	for (std::list<int>::iterator it5 = fourth_std.begin(); it5 != fourth_std.end(); it5++)
    	std::cout << *it5 << ' ';
	std::cout << '\n';
	std::cout << "The contents of fourth_ft are : ";
  	for (ft::list<int>::iterator it6 = fourth_ft.begin(); it6 != fourth_ft.end(); it6++)
    	std::cout << *it6 << ' ';
	std::cout << std::endl << std::endl;

		std::list<int> std_list(4, 100);
	ft::list<int> ft_list(4, 100);
	std::cout << "std_list contains:";
  	for (std::list<int>::iterator it=std_list.begin(); it!=std_list.end(); ++it)
		std::cout << ' ' << *it;
  	std::cout << '\n';
	std::cout << "ft_list contains:";
  	for (ft::list<int>::iterator it=ft_list.begin(); it!=ft_list.end(); ++it)
		std::cout << ' ' << *it;
  	std::cout << '\n';


	std::list<int> std_list2(std_list.begin(), std_list.end());
	ft::list<int> ft_list2(ft_list.begin(), ft_list.end());
	std::cout << "std_list contains:";
  	for (std::list<int>::iterator it=std_list2.end(); it!=std_list2.begin(); --it)
		std::cout << ' ' << *it;
  	std::cout << '\n';
	std::cout << "ft_list contains:";
  	for (ft::list<int>::iterator it=ft_list2.end(); it!=ft_list2.begin(); --it)
		std::cout << ' ' << *it;
  	std::cout << '\n';

	std::list<std::string> myList(5, "Geeks");
	for (std::list<std::string>::iterator itp=myList.begin(); itp!=myList.end(); ++itp)
		std::cout << ' ' << *itp;
  	std::cout << '\n';
	ft::list<std::string> myList2(5, "GEEKS");
	for (ft::list<std::string>::iterator itp=myList2.begin(); itp!=myList2.end(); ++itp)
		std::cout << ' ' << *itp;
  	std::cout << '\n';
	return 0;
}

int	list_assigment_opperator()
{
	std::cout << std::endl << "Calling assignment opperators:" << std::endl;

	std::list<int>	first_std (3);      // list of 3 zero-initialized ints
  	ft::list<int>	first_ft (3);
	std::list<int>	second_std (5);     // list of 5 zero-initialized ints
	ft::list<int>	second_ft (5);

  	std::cout << "Size of second_std: " << int (second_std.size()) << '\n';
  	std::cout << "Size of second_ft : " << int (second_ft.size()) << '\n';
  	second_std = first_std;
  	second_ft = first_ft;
  	std::cout << "Size of second_std: " << int (second_std.size()) << '\n';
  	std::cout << "Size of second_ft : " << int (second_ft.size()) << '\n';
	// DOES NOT WORK //
 	// first_std = std::list<int>();
 	// first_ft = ft::list<int>();

  	std::cout << "Size of first_std: " << int (first_std.size()) << '\n';
  	std::cout << "Size of first_ft : " << int (first_ft.size()) << '\n';
	std::cout << "Iterating through first_std:";
	for (std::list<int>::iterator it = first_std.begin(); it != first_std.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	std::cout << "Iterating through first_ft :";
	for (ft::list<int>::iterator it = first_ft.begin(); it != first_ft.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	std::cout << "Iterating backward first_std:";
	for (std::list<int>::iterator it = first_std.end(); it != first_std.begin(); --it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	std::cout << "Iterating backward first_ft :";
	for (ft::list<int>::iterator it = first_ft.end(); it != first_ft.begin(); --it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
  	std::cout << "Size of second_std: " << int (second_std.size()) << '\n';
  	std::cout << "Size of second_ft : " << int (second_ft.size()) << '\n';
	std::cout << "Iterating through second_std:";
	for (std::list<int>::iterator it = second_std.begin(); it != second_std.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	std::cout << "Iterating through second_ft :";
	for (ft::list<int>::iterator it = second_ft.begin(); it != second_ft.end(); ++it)
    	std::cout << ' ' << *it;
	std::cout << std::endl << std::endl;
	return 0;
}

void	list_assign()
{
	std::cout << "Calling list assign functions:" << std::endl;
	std::list<int> first_std(4, 100);
	ft::list<int> first_ft(4, 100);
	std::cout << "size of first_std" << first_std.size() << std::endl;
  	// std::list<int> second_std;
  	// ft::list<int> second_ft;

  	first_std.assign (3,50);                      // 1 ints with value 100
  	first_ft.assign (3,50);                      // 1 ints with value 100
	// for (int i=1; i<=4; ++i) first_std.push_back(i); // 1 2 3 4 5
	// for (int i=1; i<=4; ++i) first_ft.push_back(i); // 1 2 3 4 5

	// std::cout << "second_std.begin(): " << *(first_std.begin()) << "second_std.end()" << *(first_std.end()) << std::endl;
	// std::cout << "second_ft.begin(): " << *(first_ft.begin()) << "second_ft.end()" << *(first_ft.end()) << std::endl;
	// second_std.assign (second_std.begin(),second_std.end()); // a copy of first
	// second_ft.assign (second_ft.begin(),second_ft.end()); // a copy of first
	// std::cout << "Size of first_std: " << int (first_std.size()) << '\n';
	// std::cout << "Size of first_ft : " << int (first_ft.size()) << '\n';
  	// std::cout << "Size of second_std: " << int (second_std.size()) << '\n';
	// std::cout << "Size of second_ft : " << int (second_ft.size()) << '\n';
  
	std::cout << "Iterating backwards through first_std:";
	for (std::list<int>::iterator it = first_std.begin(); it != first_std.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	std::cout << "Iterating backwards through first_ft :";
	for (ft::list<int>::iterator it = first_ft.begin(); it != first_ft.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	// std::cout << "Iterating through second_std:";
	// for (std::list<int>::iterator it = second_std.begin(); it != second_std.end(); ++it)
    // 	std::cout << ' ' << *it;
  	// std::cout << '\n';
	// std::cout << "Iterating through second_ft:";
	// for (ft::list<int>::iterator it = second_ft.begin(); it != second_ft.end(); ++it)
    // 	std::cout << ' ' << *it;
	// std::cout << std::endl << std::endl;
}

void list_push()
{
	std::cout << "Calling list push functions:" << std::endl;
	std::list<int> std_list(0, 100);
	ft::list<int> ft_list(0, 100);
	std::list<int> std_list1;
	ft::list<int> ft_list1;
	std_list.push_back (200);
  	ft_list.push_back (200);
	std_list1.push_back (200);
  	ft_list1.push_back (200);

	// std_list1.push_front (200);
  	// ft_list1.push_front (200);
  	std::cout << "size of std_list1: " << std_list1.size() << "size of std_list: " << std_list.size() << std::endl;
  	std::cout << "size of ft_list1 : " << ft_list1.size() << "size of ft_list : " << ft_list.size() << std::endl;
	
  	std_list.push_back (300);
  	ft_list.push_back (300);
	  	// std_list1.push_front (300);
  	// ft_list1.push_front (300);


	// std::cout << "Size of std_list: " << int (std_list.size()) << '\n';
	// std::cout << "Size of ft_list : " << int (ft_list.size()) << '\n';
	// std::cout << "Size of std_list1: " << int (std_list1.size()) << '\n';
	// std::cout << "Size of ft_list1 : " << int (ft_list1.size()) << '\n';
  	std::cout << "std_list contains:";
  	for (std::list<int>::iterator it=std_list.end(); it!=std_list.begin(); --it)
    	std::cout << ' ' << *it;
	std::cout << '\n';
  	std::cout << "ft_list contains :";
  	for (ft::list<int>::iterator it=ft_list.end(); it!=ft_list.begin(); --it)
    	std::cout << ' ' << *it;
	std::cout << '\n'; 
  	std::cout << "std_list1 contains:";
  	for (std::list<int>::iterator it=std_list1.begin(); it!=std_list1.end(); ++it)
    	std::cout << ' ' << *it;
	std::cout << '\n';
  	std::cout << "ft_list1 contains :";
  	for (ft::list<int>::iterator it=ft_list1.begin(); it!=ft_list1.end(); ++it)
    	std::cout << ' ' << *it;
	std::cout << '\n';  

  	std::cout << "Popping back out the elements in std_list:";
  	while (!std_list.empty())
  	{
  		std::cout << ' ' << std_list.back();
    	std_list.pop_back();
  	}
	std::cout << '\n';  
  	std::cout << "Popping back out the elements in ft_list: ";
  	while (!ft_list.empty())
  	{
  		std::cout << ' ' << ft_list.back();
    	ft_list.pop_back();
  	}
	std::cout << '\n'; 
	std::cout << "size of std_list1: " << std_list1.size() << "std_list1.end(): " << *(std_list1.end()) << std::endl;
	std::cout << "size of ft_list1: " << ft_list1.size() << "ft_list1.end(): " << *(ft_list1.end()) << std::endl;
	std::cout << "Popping front out the elements in std_list:";
  	while (!std_list1.empty())
  	{
  		std::cout << "  front: " << std_list1.front();
    	std_list1.pop_front();
  	}
	std::cout << '\n';
  	std::cout << "Popping front out the elements in ft_list: ";
  	while (!ft_list1.empty())
  	{
  		std::cout << "  front: " << ft_list1.front();
    	ft_list1.pop_front();
  	}
	std::cout << '\n'; 

	std::cout << "PArt two list_push: " << std::endl;
	std::list<int> std_list2;
	ft::list<int> ft_list2;
	std_list.push_back (200);
  	ft_list.push_back (200);
  	std::cout << "std_list2 contains :";
	for (std::list<int>::iterator it=std_list2.begin(); it!=std_list2.end(); ++it)
    	std::cout << ' ' << *it;
	std::cout << '\n';
  	std::cout << "ft_list2 contains :";
  	for (ft::list<int>::iterator it=ft_list2.begin(); it!=ft_list2.end(); ++it)
    	std::cout << ' ' << *it;
	std::cout << '\n'; 
  	std::cout << "std_list2 backwards :";
	for (std::list<int>::iterator it=std_list2.end(); it!=std_list2.begin(); --it)
    	std::cout << ' ' << *it;
	std::cout << '\n';
  	std::cout << "ft_list2 backwards :";
  	for (ft::list<int>::iterator it=ft_list2.end(); it!=ft_list2.begin(); --it)
    	std::cout << ' ' << *it;
	std::cout << '\n'; 
	
}

void	list_insert()
{
	std::cout << "Calling list insert functions:" << std::endl;
	std::list<int> mylist_std(2, 100);
	std::list<int>::iterator it_std;
	ft::list<int> mylist_ft(2, 100);
	ft::list<int>::iterator it_ft;
	
	for (int i=1; i<=5; ++i) mylist_std.push_back(i); // 1 2 3 4 5
	for (int i=1; i<=5; ++i) mylist_ft.push_back(i); // 1 2 3 4 5

  	std::cout << "Size of std_list: " << int (mylist_std.size()) << '\n';
	std::cout << "Size of ft_list : " << int (mylist_ft.size()) << '\n';
	// std::list<int>::iterator it_std = mylist_std.begin();
	// ft::list<int>::iterator it_ft = mylist_ft.begin();
	it_std = mylist_std.begin();
	it_ft = mylist_ft.begin();
	std::cout << "begin mylist_std : " << *(mylist_std.begin()) << '\n';
  	std::cout << "begin mylist_ft : " << *(mylist_ft.begin()) << '\n';
	std::cout << "end mylist_std : " << *(mylist_std.end()) << '\n';
  	std::cout << "end mylist_ft : " << *(mylist_ft.end()) << '\n';
  	std::cout << "mylist_std contains:";
  	for (std::list<int>::iterator it=mylist_std.begin(); it!=mylist_std.end(); ++it)
    	std::cout << ' ' << *it;
	std::cout << '\n';
  	std::cout << "mylist_ft contains: ";
  	for (ft::list<int>::iterator it=mylist_ft.begin(); it!=mylist_ft.end(); ++it)
    	std::cout << ' ' << *it;
	std::cout << '\n';
	//it_std++;	//it_std++;  //	it_std++;//	it_std++;	it_std++;	it_std++;	it_std++;	//it_std++;	//it_std++;	it_std++;	it_std++;
	// it_std++; 	it_std++; 	it_std++;	//it_std++;	//it_std++;	it_std++;	it_std++;	it_std++;	it_std++;	it_std++;	it_std++;
	// // // it_std++; // FIX IT BISH
	//it_ft++;	//it_ft++; //	it_ft++; 	//it_ft++;	it_ft++;	it_ft++;	it_ft++;	//it_ft++;	//it_ft++;	it_ft++;	it_ft++;
	// it_ft++; 	it_ft++; 	it_ft++; 	//it_ft++;	//it_ft++;	it_ft++;	it_ft++;	it_ft++;	it_ft++;	it_ft++;	it_ft++;

	// // // PROBLEM WHEN THESE ARE IN  		in hpp file std::cout << "IN THIS << std::endl" << std::endl;
	// std::cout << "it_STD is : " << *it_std <<std::endl;
	// std::cout << "it_FT is : " << *it_ft <<std::endl;
  	// mylist_std.insert (it_std, 1, 20);
  	// mylist_ft.insert (it_ft, 1, 20);
	// std::cout << "mylist_std.begin() begin is ()" << *(mylist_std.begin()) << "mylist_std.end(): " << *(mylist_std.end()) << std::endl;
	// std::cout << "mylist_ft.begin() begin is ()" << *(mylist_ft.begin()) << "mylist_ft.end(): " << *(mylist_ft.end()) << std::endl;
  	// std::cout << "mylist_std containS: ";
  	// for (std::list<int>::iterator it=mylist_std.begin(); it!=mylist_std.end(); ++it)
    // 	std::cout << ' ' << *it;
	// std::cout << '\n';
  	// std::cout << "mylist_ft containS : ";
  	// for (ft::list<int>::iterator it=mylist_ft.begin(); it!=mylist_ft.end(); ++it)
    // 	std::cout << ' ' << *it;
	// std::cout << '\n';
	// std::cout << "RET VAL" << *(mylist_std.insert (it_std,10)) << std::endl;                      // 1 10 2 3 4 5
	// std::cout << "RET VAL" << *(mylist_ft.insert (it_ft,10)) << std::endl; 
  	// std::cout << "Size of std_list: " << int (mylist_std.size()) << '\n';
	// std::cout << "Size of ft_list : " << int (mylist_ft.size()) << '\n';
	// ++it_std;	++it_std;	++it_std;	++it_std;
  	// ++it_ft;	++it_ft;	++it_ft;	++it_ft;
	// mylist_std.erase(it_std);
	// mylist_ft.erase(it_ft);
  	// std::cout << "mylist_STD contains:";
  	// for (std::list<int>::iterator it=mylist_std.begin(); it!=mylist_std.end(); ++it)
    // 	std::cout << ' ' << *it;
  	// std::cout << '\n';
  	// std::cout << "mylist_ft  contains:";
  	// for (ft::list<int>::iterator it=mylist_ft.begin(); it!=mylist_ft.end(); ++it)
    // 	std::cout << ' ' << *it;
  	// std::cout << '\n';
	// std::list<int> stdlisty(4, 30);
	// ft::list<int> ftlisty(4, 30);
	// std::list<int>::iterator it_std1 = mylist_std.begin();
	// it_std1++;	it_std1++;	it_std1++;	//it_std1++;//	it_std1++; //----- THESE BREAK IT
	// ft::list<int>::iterator it_ft1 = mylist_ft.begin();
	// it_ft1++;	it_ft1++;	it_ft1++;	//it_ft1++;	//it_ft1++;  //----- THESE BREAK IT
	// std::cout << "begin mylist_std : " << *(mylist_std.begin()) << '\n';
  	// std::cout << "begin mylist_ft : " << *(mylist_ft.begin()) << '\n';
	// std::list<int>::iterator it_std2 = mylist_std.begin();
	// ft::list<int>::iterator it_ft2 = mylist_ft.begin();
	// std::cout << "IT_STD is: " << *it_std1 << std::endl;
	// std::cout << "IT_SFT is: " << *it_ft1 << std::endl;
	// mylist_std.insert (it_std1, 4, 10);				 // 1 10 20 30 30 20 2 3 4 5
  	// mylist_ft.insert (it_ft1, 4, 10);
	// mylist_std.insert (it_std2,stdlisty.begin(),stdlisty.end());				 // 1 10 20 30 30 20 2 3 4 5
  	// mylist_ft.insert (it_ft2,ftlisty.begin(),ftlisty.end());
  	// std::cout << "end mylist_std : " << *(mylist_std.end()) << '\n';
  	// std::cout << "end mylist_ft : " << *(mylist_ft.end()) << '\n';

  	// std::cout << "mylist_std contains:";
  	// for (std::list<int>::iterator it=mylist_std.begin(); it!=mylist_std.end(); ++it)
    // 	std::cout << ' ' << *it;
  	// std::cout << '\n';
  	// std::cout << "mylist_ft contains :";
  	// for (ft::list<int>::iterator it=mylist_ft.begin(); it!=mylist_ft.end(); ++it)
    // 	std::cout << ' ' << *it;
  	// std::cout << '\n';
}

void	list_erase()
{
	std::cout << "calling list erase fucntions" << std::endl;
	std::list<int> mylist_std(3, 400);
	ft::list<int> mylist_ft(3, 400);
	// for (int i=1; i<=4; ++i) mylist_std.push_back(i); // 1 2 3 4 5
	// for (int i=1; i<=4; ++i) mylist_ft.push_back(i); // 1 2 3 4 5
	ft::list<int>::iterator it_ft = mylist_ft.begin();
	std::list<int>::iterator it_std = mylist_std.begin();
	it_std++;
	it_ft++;
	it_std++;
	it_ft++;
	// it_std++;
	// it_ft++;
  	std::cout << "mylist_std contains:";
  	for (std::list<int>::iterator it=mylist_std.begin(); it!=mylist_std.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
  	std::cout << "mylist_ft contains :";
  	for (ft::list<int>::iterator it=mylist_ft.begin(); it!=mylist_ft.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	mylist_std.erase(it_std);
	mylist_ft.erase(it_ft);
  	std::cout << "Size of std_list: " << int (mylist_std.size()) << '\n';
	std::cout << "Size of ft_list : " << int (mylist_ft.size()) << '\n';
  	std::cout << "mylist_std contains:";
  	for (std::list<int>::iterator it=mylist_std.begin(); it!=mylist_std.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
  	std::cout << "mylist_ft contains :";
  	for (ft::list<int>::iterator it=mylist_ft.begin(); it!=mylist_ft.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	std::cout  << "PART TWO OF ERASE" << std::endl << std::endl;  
	std::list<int> stdmylist;
  	std::list<int>::iterator stdit1,stdit2;
	ft::list<int> ftmylist;
  	ft::list<int>::iterator ftit1,ftit2;
	// set some values:
  	for (int i=1; i<3; ++i) stdmylist.push_back(i*10);
  	for (int i=1; i<3; ++i) ftmylist.push_back(i*10);
  	stdit1 = stdit2 = stdmylist.begin(); 
  	ftit1 = ftit2 = ftmylist.begin(); 
  	stdit2 = stdmylist.end();
  	ftit2= ftmylist.end();
	std::cout << "stdmylist.end() " << *(stdmylist.end()) << std::endl;
	std::cout << "ftmylist.end () " << *(ftmylist.end()) << std::endl;
	std::cout << "stdmylist.begin() " << *(stdmylist.begin()) << std::endl;
	std::cout << "ftmylist.begin () " << *(ftmylist.begin()) << std::endl;
	stdit2--;
	ftit2--;

	stdit1 = stdmylist.erase (stdit1,stdit2);
	ftit1 = ftmylist.erase (ftit1,ftit2);
	// std::cout << "ftit1: " << *ftit1 << std::endl;
	// std::cout << "stdit1:" << *stdit1 << std::endl;
	std::cout << "Erase: stdmylist contains:";
	for (stdit1=stdmylist.begin(); stdit1!=stdmylist.end(); ++stdit1)
    	std::cout << ' ' << *stdit1;
	std::cout << '\n';
	std::cout << "Erase: ftmylist contains :";
	for (ftit1=ftmylist.begin(); ftit1!=ftmylist.end(); ++ftit1)
    	std::cout << ' ' << *ftit1;
	std::cout << '\n';
	std::cout << "Size of std_list: " << int (mylist_std.size()) << '\n';
	std::cout << "Size of ft_list : " << int (mylist_ft.size()) << '\n';
}

void	list_swap()
{
	std::cout << "calling list swap fucntions" << std::endl;
	std::list<int> first_std (3,100);   // three ints with a value of 100
	ft::list<int> first_ft (3,100);   // three ints with a value of 100
	std::list<int> second_std (5,200);  // five ints with a value of 200
	ft::list<int> second_ft (5,200);  // five ints with a value of 200

	first_std.swap(second_std);
	first_ft.swap(second_ft);

	std::cout << "first_std contains:";
	for (std::list<int>::iterator it=first_std.begin(); it!=first_std.end(); it++)
    	std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "first_ft contains: ";
	for (ft::list<int>::iterator it=first_ft.begin(); it!=first_ft.end(); it++)
    	std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "second_std contains:";
	for (std::list<int>::iterator it=second_std.begin(); it!=second_std.end(); it++)
    	std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "second_ft contains :";
	for (ft::list<int>::iterator it=second_ft.begin(); it!=second_ft.end(); it++)
    	std::cout << ' ' << *it;
	std::cout << '\n';
}

void	list_clear()
{
	std::cout << "calling list clear fucntions" << std::endl;
	std::list<int> mylist_std1(10, 100);
	ft::list<int> mylist_ft1(10, 100);
  	std::list<int>::iterator it_std;
  	ft::list<int>::iterator it_ft;

	mylist_std1.push_back (800);
	mylist_ft1.push_back (800);
	// mylist_std.push_back (200);
	// mylist_ft.push_back (200);
	// mylist_std.push_back (300);
	// mylist_ft.push_back (300);

	std::cout << "mylist_std contains1:";
	for (it_std=mylist_std1.begin(); it_std!=mylist_std1.end(); ++it_std)
    	std::cout << ' ' << *it_std;
	std::cout << '\n';
	std::cout << "mylist_ft contains1 :";
	for (it_ft=mylist_ft1.begin(); it_ft!=mylist_ft1.end(); ++it_ft)
    	std::cout << ' ' << *it_ft;
	std::cout << '\n';

	mylist_std1.clear();
	mylist_ft1.clear();
	// mylist_std.push_back (1101);
	// mylist_ft.push_back (1101);
	// mylist_std.push_back (2202);
	// mylist_ft.push_back (2202);

	// std::cout << "mylist_std contains:";
	// for (it_std=mylist_std.begin(); it_std!=mylist_std.end(); ++it_std)
    // 	std::cout << ' ' << *it_std;
  	// std::cout << '\n';
	// std::cout << "mylist_ft contains :";
	// for (it_ft=mylist_ft.begin(); it_ft!=mylist_ft.end(); ++it_ft)
    // 	std::cout << ' ' << *it_ft;
	// std::cout << '\n';
}

void	list_resize()
{
	std::cout << "calling list resize fucntions" << std::endl;
	std::list<int> std_list;
	std::list<int> ft_list;

	for (int i=1; i<10; ++i) std_list.push_back(i);
	for (int i=1; i<10; ++i) ft_list.push_back(i);

	std_list.resize(5);
	ft_list.resize(5);
	std_list.resize(8,100);
	ft_list.resize(8,100);
	std_list.resize(12);
	ft_list.resize(12);

	std::cout << "std_list contains:";
  	for (std::list<int>::reverse_iterator it=std_list.rbegin(); it!=std_list.rend(); ++it)
		std::cout << ' ' << *it;
  	std::cout << '\n';
	std::cout << "ft_list contains :";
  	for (std::list<int>::reverse_iterator it=ft_list.rbegin(); it!=ft_list.rend(); ++it)
		std::cout << ' ' << *it;

  	std::cout << '\n';
}

void	list_splice()
{
	std::cout << "calling list list_splice fucntions" << std::endl;
	std::list<int> std_mylist1, std_mylist2;
	ft::list<int> ft_mylist1, ft_mylist2;
  	std::list<int>::iterator std_it;
  	ft::list<int>::iterator ft_it;
  	for (int i=2; i<=5; ++i)
    	 std_mylist1.push_back(i);      // mylist1: 1 2 3 4
  	for (int i=2; i<=5; ++i)
    	 ft_mylist1.push_back(i);      // mylist1: 1 2 3 4
  	for (int i=2; i<=4; ++i)
    	std_mylist2.push_back(i*10);   // mylist2: 10 20 30
  	for (int i=2; i<=4; ++i)
    	ft_mylist2.push_back(i*10);   // mylist2: 10 20 30
 	ft_it = ft_mylist1.begin();
 	std_it = std_mylist1.begin();
  	// ++std_it;	++std_it; 	++std_it; 	++std_it; 	++std_it; 	++std_it; 	++std_it;
	// ++ft_it;	++ft_it;	++ft_it;	++ft_it;	++ft_it;	++ft_it;	++ft_it;
  	std_mylist1.splice (std_it, std_mylist2);
  	ft_mylist1.splice (ft_it, ft_mylist2);
	std::cout << "std_mylist1 contains1:";
	for (std::list<int>::iterator it_std=std_mylist1.begin(); it_std!=std_mylist1.end(); ++it_std)
    	std::cout << ' ' << *it_std;
	std::cout << '\n';
	std::cout << "ft_mylist1 contains1 :";
	for (ft::list<int>::iterator it_ft=ft_mylist1.begin(); it_ft!=ft_mylist1.end(); ++it_ft)
    	std::cout << ' ' << *it_ft;
	std::cout << '\n';
	std::cout << "std_mylist_ft2 contains1 :";
	for (std::list<int>::iterator it_ft=std_mylist2.begin(); it_ft!=std_mylist2.end(); ++it_ft)
    	std::cout << ' ' << *it_ft;
	std::cout << '\n';
	std::cout << "ft_mylist_ft2 contains1 :";
	for (ft::list<int>::iterator it_ft=ft_mylist2.begin(); it_ft!=ft_mylist2.end(); ++it_ft)
    	std::cout << ' ' << *it_ft;
	std::cout << '\n';

	std_mylist2.splice (std_mylist2.begin(),std_mylist1, std_it);
	ft_mylist2.splice (ft_mylist2.begin(),ft_mylist1, ft_it);
	std::cout << "PART 2: \nstd_mylist1 contains1 :";
	for (std::list<int>::iterator it_std=std_mylist1.begin(); it_std!=std_mylist1.end(); ++it_std)
    	std::cout << ' ' << *it_std;
	std::cout << '\n';
	std::cout << "ft_mylist1 contains1 :";
	for (ft::list<int>::iterator it_ft=ft_mylist1.begin(); it_ft!=ft_mylist1.end(); ++it_ft)
    	std::cout << ' ' << *it_ft;
	std::cout << '\n';
	std::cout << "std_mylist_ft contains2 :";
	for (std::list<int>::iterator it_ft=std_mylist2.begin(); it_ft!=std_mylist2.end(); ++it_ft)
    	std::cout << ' ' << *it_ft;
	std::cout << '\n';
	std::cout << "ft_mylist_ft contains2 :";
	for (ft::list<int>::iterator it_ft=ft_mylist2.begin(); it_ft!=ft_mylist2.end(); ++it_ft)
    	std::cout << ' ' << *it_ft;
	std::cout << '\n';
	std_it = std_mylist1.begin();
	ft_it = ft_mylist1.begin();
  	std_it++;
	ft_it++;
	std_mylist1.splice ( std_mylist1.begin(), std_mylist1, std_it, std_mylist1.end());
	ft_mylist1.splice ( ft_mylist1.begin(), ft_mylist1, ft_it, ft_mylist1.end());

	std::cout << "PART 3: \nstd_mylist1 contains1 :";
	for (std::list<int>::iterator it_std=std_mylist1.begin(); it_std!=std_mylist1.end(); ++it_std)
    	std::cout << ' ' << *it_std;
	std::cout << '\n';
	std::cout << "ft_mylist1 contains1 :";
	for (ft::list<int>::iterator it_ft=ft_mylist1.begin(); it_ft!=ft_mylist1.end(); ++it_ft)
    	std::cout << ' ' << *it_ft;
	std::cout << '\n';
}

bool single_digit (const int& value) { return (value<10); }
struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};
void	list_remove()
{
	std::cout << "calling list list_remove fucntions" << std::endl;
	std::list<int> first_std(4, 100);
	ft::list<int> first_ft(4, 100);
	for (int i=1; i<=4; ++i) first_std.push_back(i); // 1 2 3 4 5
	for (int i=1; i<=4; ++i) first_ft.push_back(i); // 1 2 3 4 5
	first_std.remove(2);
	first_ft.remove(2);
	std::cout << "first_std contains1 :";
	for (std::list<int>::iterator it_std=first_std.begin(); it_std!=first_std.end(); ++it_std)
    	std::cout << ' ' << *it_std;
	std::cout << '\n';
	std::cout << "first_ft contains1 :";
	for (ft::list<int>::iterator it_ft=first_ft.begin(); it_ft!=first_ft.end(); ++it_ft)
    	std::cout << ' ' << *it_ft;
	std::cout << '\n';

	first_std.remove_if (is_odd());           // 15 36 17 20 39
	first_ft.remove_if (is_odd());           // 15 36 17 20 39
 	std::cout << "PART TWO:\nfirst_std contains:";
  	for (std::list<int>::iterator it=first_std.begin(); it!=first_std.end(); ++it)
    std::cout << ' ' << *it;
  	std::cout << '\n';
 	std::cout << "first_ft contains:";
  	for (ft::list<int>::iterator it=first_ft.begin(); it!=first_ft.end(); ++it)
    std::cout << ' ' << *it;
  	std::cout << '\n';
}

struct is_near {
  bool operator() (double first, double second)
  { return (fabs(first-second)<5.0); }
};

void	list_unique()
{
	std::cout << "calling list list_unique fucntions" << std::endl;	
	std::list<int> first_std(4, 100);
	ft::list<int> first_ft(4, 100);
	for (int i=1; i<=4; ++i) first_std.push_back(2); // 1 2 3 4 5
	for (int i=1; i<=4; ++i) first_ft.push_back(2); // 1 2 3 4 5
	first_std.unique();
	first_ft.unique();
	std::cout << "first_std contains1 :";
	for (std::list<int>::iterator it_std=first_std.begin(); it_std!=first_std.end(); ++it_std)
    	std::cout << ' ' << *it_std;
	std::cout << '\n';
	std::cout << "first_ft contains1 :";
	for (ft::list<int>::iterator it_ft=first_ft.begin(); it_ft!=first_ft.end(); ++it_ft)
    	std::cout << ' ' << *it_ft;
	std::cout << '\n';
	std::list<float> second_std;
	ft::list<float> second_ft;
	second_std.push_back(2.72);	second_std.push_back(3.14);	second_std.push_back(12.15); second_std.push_back(15.3); second_std.push_back(72.25); second_std.push_back(73.0);
	second_ft.push_back(2.72);	second_ft.push_back(3.14);	second_ft.push_back(12.15); second_ft.push_back(15.3); second_ft.push_back(72.25); second_ft.push_back(73.0);	
	std::cout << "second_std contains1 :";
	for (std::list<float>::iterator it_std=second_std.begin(); it_std!=second_std.end(); ++it_std)
    	std::cout << ' ' << *it_std;
	std::cout << '\n';
	std::cout << "second_ft  contains1 :";
	for (ft::list<float>::iterator it_ft=second_ft.begin(); it_ft!=second_ft.end(); ++it_ft)
    	std::cout << ' ' << *it_ft;
	std::cout << '\n';
	second_std.unique (is_near());
	second_ft.unique (is_near());
	std::cout << "second_std contains1 :";
	for (std::list<float>::iterator it_std=second_std.begin(); it_std!=second_std.end(); ++it_std)
    	std::cout << ' ' << *it_std;
	std::cout << '\n';
	std::cout << "second_ft  contains1 :";
	for (ft::list<float>::iterator it_ft=second_ft.begin(); it_ft!=second_ft.end(); ++it_ft)
    	std::cout << ' ' << *it_ft;
	std::cout << '\n';
}


bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }
void	list_merge()
{
	std::cout << "calling list list_merge fucntions" << std::endl;	
	std::list<double> first_std, second_std;
	ft::list<double> first_ft, second_ft;

 	first_std.push_back (3.1);
  	first_std.push_back (2.2);
  	first_std.push_back (2.9);
	first_ft.push_back (3.1);
  	first_ft.push_back (2.2);
  	first_ft.push_back (2.9);

  	second_std.push_back (3.7);
  	second_std.push_back (7.1);
  	second_std.push_back (2.7);
  	second_ft.push_back (3.7);
  	second_ft.push_back (7.1);
  	second_ft.push_back (2.7);

  	// first_std.sort();
  	// second_std.sort();

  	first_std.merge(second_std);
  	first_ft.merge(second_ft);
	std::cout << "first_std contains1 :";
	for (std::list<double>::iterator it_std=first_std.begin(); it_std!=first_std.end(); ++it_std)
    	std::cout << ' ' << *it_std;
	std::cout << '\n';
	std::cout << "first_ft  contains1 :";
	for (ft::list<double>::iterator it_std=first_ft.begin(); it_std!=first_ft.end(); ++it_std)
    	std::cout << ' ' << *it_std;
	std::cout << '\n';
	std::cout << "second_std  contains1 :";
	for (std::list<double>::iterator it_ft=second_std.begin(); it_ft!=second_std.end(); ++it_ft)
    	std::cout << ' ' << *it_ft;
	std::cout << '\n';
	std::cout << "second_ft  contains1 :";
	for (ft::list<double>::iterator it_ft=second_ft.begin(); it_ft!=second_ft.end(); ++it_ft)
    	std::cout << ' ' << *it_ft;
	std::cout << '\n';
	second_std.push_back (2.9);
	second_ft.push_back (2.9);
	second_std.push_back (9.3);
	second_ft.push_back (9.3);
	second_std.push_back (4.3);
	second_ft.push_back (4.3);
  	first_std.merge(second_std,mycomparison);
  	first_ft.merge(second_ft,mycomparison);
	std::cout << "PART 2\nfirst_std contains1 :";
	for (std::list<double>::iterator it_std=first_std.begin(); it_std!=first_std.end(); ++it_std)
    	std::cout << ' ' << *it_std;
	std::cout << '\n';
	std::cout << "first_ft  contains1 :";
	for (ft::list<double>::iterator it_std=first_ft.begin(); it_std!=first_ft.end(); ++it_std)
    	std::cout << ' ' << *it_std;
	std::cout << '\n';
	std::cout << "second_std  contains1 :";
	for (std::list<double>::iterator it_ft=second_std.begin(); it_ft!=second_std.end(); ++it_ft)
    	std::cout << ' ' << *it_ft;
	std::cout << '\n';
	std::cout << "second_ft  contains1 :";
	for (ft::list<double>::iterator it_ft=second_ft.begin(); it_ft!=second_ft.end(); ++it_ft)
    	std::cout << ' ' << *it_ft;
	std::cout << '\n';
	
}

int    list_tests()
{
    std::cout << "PERFORMING LIST TESTS:" << std::endl;
	// list_constructor();
	// list_assigment_opperator();
	// list_push(); 
	// list_assign();
	// list_insert();
	// list_erase();
	// list_swap();
	// list_clear();
	// list_resize();
	// list_splice();
	// list_remove();
	// list_unique();
	list_merge();
	return 0;
}

int    main(int argc, char **argv)
{
	// ft_testing_my_own_list();
    if (argc == 1 || argc == 2)
    {
        if (argc == 1 || strcmp(argv[1], "list") == 0)
            list_tests();
    //     if (argc == 1 || strcmp(argv[1], "vector") == 0)
    //         vector_tests();
    //     if (argc == 1 || strcmp(argv[1], "map") == 0)
    //         map_tests();
    //     if (argc == 1 || strcmp(argv[1], "stack") == 0)
    //         stack_tests();
    //     if (argc == 1 || strcmp(argv[1], "queue") == 0)
    //         queue_tests();
    //     if (argc == 2 && strcmp(argv[1], "queue") != 0
	// 		&& strcmp(argv[1], "stack") != 0
	// 		&& strcmp(argv[1], "map") != 0
	// 		&& strcmp(argv[1], "vector") != 0
	// 		&& strcmp(argv[1], "list") != 0)
    //        std::cout << "invalid arguments" << std::endl;
    }
    else
        std::cout << "invalid arguments" << std::endl;
    return (0);
}
