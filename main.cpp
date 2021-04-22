/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-dam <avan-dam@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/23 14:38:34 by avan-dam      #+#    #+#                 */
/*   Updated: 2021/04/22 10:59:38 by ambervandam   ########   odam.nl         */
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
	ft::list<int> second_ft (4,100);                       						// four ints with value 100
	std::list<int> third_std (second_std.begin(),second_std.end());				// iterating through second
	ft::list<int> third_ft (second_ft.begin(),second_ft.end());					// iterating through second
	std::list<int> fourth_std (third_std);                       				// a copy of third
	ft::list<int> fourth_ft (third_ft);  	                  					// a copy of third
	int myarray[] = {16,2,77,29};
	std::list<int> fifth_std (myarray, myarray + 4);
	// THIS DOES NOT WORK
	// ft::list<int> fifth_ft (myarray, myarray + 4);
	// THIS DOES NOT WORK //
	// int myints[] = {16,2,77,29};
	// std::list<int> sixth_std (myints, myints + sizeof(myints) / sizeof(int) ); // the iterator constructor can also be used to construct from arrays:
	// ft::list<int> sixth_ft (myints, myints + sizeof(myints) / sizeof(int) );

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
	// std::cout << "The contents of fifth_std are: ";
  	// for (std::list<int>::iterator it5 = fifth_std.begin(); it5 != fifth_std.end(); it5++)
    // 	std::cout << *it5 << ' ';
	// std::cout << '\n';
	// std::cout << "The contents of fifth_ft are: ";
  	// for (ft::list<int>::iterator it6 = fifth_ft.begin(); it6 != fifth_ft.end(); it6++)
    // 	std::cout << *it6 << ' ';
	// std::cout << '\n';
	return 0;
}

int	list_assigment_opperator()
{
	std::cout << std::endl << "Calling assignment opperators:" << std::endl;

	std::list<int>	first_std (3);      // list of 3 zero-initialized ints
  	ft::list<int>	first_ft (3);
	std::list<int>	second_std (5);     // list of 5 zero-initialized ints
	ft::list<int>	second_ft (5);

  	second_std = first_std;
  	second_ft = first_ft;
	// DOES NOT WORK //
 	// first_std = std::list<int>();
 	// first_ft = ft::list<int>();

  	std::cout << "Size of first_std: " << int (first_std.size()) << '\n';
	std::cout << "Iterating through first_std:";
	for (std::list<int>::iterator it = first_std.begin(); it != first_std.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
  	std::cout << "Size of first_ft : " << int (first_ft.size()) << '\n';
	std::cout << "Iterating through first_ft:";
	for (ft::list<int>::iterator it = first_ft.begin(); it != first_ft.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
  	std::cout << "Size of second_std: " << int (second_std.size()) << '\n';
	std::cout << "Iterating through second_std:";
	for (std::list<int>::iterator it = second_std.begin(); it != second_std.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
  	std::cout << "Size of second_ft : " << int (second_ft.size()) << '\n';
	std::cout << "Iterating through second_ft:";
	for (ft::list<int>::iterator it = second_ft.begin(); it != second_ft.end(); ++it)
    	std::cout << ' ' << *it;
	std::cout << std::endl << std::endl;
	return 0;
}

void	list_assign()
{
	std::cout << "Calling list assign functions:" << std::endl;
	std::list<int> first_std;
	ft::list<int> first_ft;
  	std::list<int> second_std;
  	ft::list<int> second_ft;

  	first_std.assign (1,100);                      // 1 ints with value 100
  	first_ft.assign (1,100);                      // 1 ints with value 100
  	second_std.assign (second_std.begin(),second_std.end()); // a copy of first
	second_ft.assign (second_ft.begin(),second_ft.end()); // a copy of first
	std::cout << "Size of first_std: " << int (first_std.size()) << '\n';
	std::cout << "Size of first_ft : " << int (first_ft.size()) << '\n';
  	std::cout << "Size of second_std: " << int (second_std.size()) << '\n';
	std::cout << "Size of second_ft : " << int (second_ft.size()) << '\n';
  
	std::cout << "Iterating through first_std:";
	for (std::list<int>::iterator it = first_std.begin(); it != first_std.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	std::cout << "Iterating through first_ft:";
	for (ft::list<int>::iterator it = first_ft.begin(); it != first_ft.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	std::cout << "Iterating through second_std:";
	for (std::list<int>::iterator it = second_std.begin(); it != second_std.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	std::cout << "Iterating through second_ft:";
	for (ft::list<int>::iterator it = second_ft.begin(); it != second_ft.end(); ++it)
    	std::cout << ' ' << *it;
	std::cout << std::endl << std::endl;
}

void list_push()
{
	std::cout << "Calling list push functions:" << std::endl;
	std::list<int> std_list (1,100);         // two ints with a value of 100
	ft::list<int> ft_list (1,100);         // two ints with a value of 100
	std::list<int> std_list1 (1,100);         // two ints with a value of 100
	ft::list<int> ft_list1 (1,100);         // two ints with a value of 100
  	std_list.push_back (200);
  	ft_list.push_back (200);
  	std_list1.push_front (200);
  	ft_list1.push_front (200);
  	std_list.push_back (300);
  	ft_list.push_back (300);
  	std_list1.push_front (300);
  	ft_list1.push_front (300);

	std::cout << "Size of std_list: " << int (std_list.size()) << '\n';
	std::cout << "Size of ft_list : " << int (ft_list.size()) << '\n';
	std::cout << "Size of std_list1: " << int (std_list1.size()) << '\n';
	std::cout << "Size of ft_list1 : " << int (ft_list1.size()) << '\n';
  	std::cout << "std_list contains:";
  	for (std::list<int>::iterator it=std_list.begin(); it!=std_list.end(); ++it)
    	std::cout << ' ' << *it;
	std::cout << '\n';
  	std::cout << "ft_list contains :";
  	for (ft::list<int>::iterator it=ft_list.begin(); it!=ft_list.end(); ++it)
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
}

void	list_insert()
{
	std::cout << "Calling list insert functions:" << std::endl;
	std::list<int> mylist_std;
	std::list<int>::iterator it_std;
	ft::list<int> mylist_ft;
	ft::list<int>::iterator it_ft;
	
	for (int i=1; i<=5; ++i) mylist_std.push_back(i); // 1 2 3 4 5
	for (int i=1; i<=5; ++i) mylist_ft.push_back(i); // 1 2 3 4 5

	it_std = mylist_std.begin();
	++it_std;       // it points now to number 2           ^
	++it_std;       // it points now to number 2           ^
	++it_std;       // it points now to number 2           ^
	it_ft = mylist_ft.begin();
	++it_ft;       // it points now to number 2   
	++it_ft;       // it points now to number 2   
	++it_ft;       // it points now to number 2   

	// THIS ONE NOT WORKING THIS ONE NOT WORKING
	std::cout << "result of single insert with mylist_std is : " << *(mylist_std.insert (it_std,10)) << std::endl;                        // 1 10 2 3 4 5
	std::cout << "result of single insert with mylist_ft  is : " << *(mylist_ft.insert (it_ft,10)) << std::endl;;                        // 1 10 2 3 4 5

  	std::cout << "mylist_std contains:";
  	for (std::list<int>::iterator it=mylist_std.begin(); it!=mylist_std.end(); ++it)
    	std::cout << ' ' << *it;
	std::cout << '\n';
  	std::cout << "mylist_ft contains: ";
  	for (ft::list<int>::iterator it=mylist_ft.begin(); it!=mylist_ft.end(); ++it)
    	std::cout << ' ' << *it;
	std::cout << '\n';
  	mylist_std.insert (it_std,2,20);                    // 1 10 20 20 2 3 4 5
  	mylist_ft.insert (it_ft,2,20);                      // 1 10 20 20 2 3 4 5
	mylist_std.insert (it_std,10);                      // 1 10 2 3 4 5
	mylist_ft.insert (it_ft,10); 
  	++it_std;											// it points now to the second 20            ^
  	++it_ft;
	std::cout << "mylist_std contains:";
  	for (std::list<int>::iterator it=mylist_std.begin(); it!=mylist_std.end(); ++it)
    	std::cout << ' ' << *it;
	std::cout << '\n';
  	std::cout << "mylist_ft  contains:";
  	for (ft::list<int>::iterator it=mylist_ft.begin(); it!=mylist_ft.end(); ++it)
    	std::cout << ' ' << *it;
	std::cout << '\n';
  	std::cout << "Size of mylist_ft : " << int (mylist_ft.size()) << '\n';
  	std::cout << "Size of mylist_std: " << int (mylist_std.size()) << '\n';
	
	std::list<int> stdlisty(4, 30);
	ft::list<int> ftlisty(4, 30);
	mylist_std.insert (it_std,stdlisty.begin(),stdlisty.end());				 // 1 10 20 30 30 20 2 3 4 5
  	mylist_ft.insert (it_ft,ftlisty.begin(),ftlisty.end());				 // 1 10 20 30 30 20 2 3 4 5
  	std::cout << "mylist_std contains:";
  	for (std::list<int>::iterator it=mylist_std.begin(); it!=mylist_std.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
  	std::cout << "mylist_ft  contains:";
  	for (ft::list<int>::iterator it=mylist_ft.begin(); it!=mylist_ft.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
}

int    list_tests()
{
    std::cout << "PERFORMING LIST TESTS:" << std::endl;
	// list_constructor();
	// list_assigment_opperator();
	// list_assign();
	// list_push();
	// list_insert();
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
