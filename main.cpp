/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-dam <avan-dam@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/23 14:38:34 by avan-dam      #+#    #+#                 */
/*   Updated: 2021/04/09 11:02:57 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.hpp"
#include "list_node.hpp"
#include <list>

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
	// std::list<int> first;                                // empty list of ints
	std::list<int> second (4,100);                       // four ints with value 100
// 	std::list<int> third (second.begin(),second.end());  // iterating through second
// 	std::list<int> fourth (third);                       // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	// int myints[] = {16,2,77,29};
	// std::list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
	// std::list<int> sixth = fifth;
	// char mychars[5] = "amber";


	// std::cout << "The contents of first are: ";
  	// for (std::list<int>::iterator it = first.begin(); it != first.end(); it++)
    // 	std::cout << *it << ' ';
	// std::cout << '\n';
	std::cout << "The contents of second are: ";
  	for (std::list<int>::iterator it = second.begin(); it != second.end(); it++)
    	std::cout << *it << ' ';
	std::cout << '\n';
	// std::cout << "The contents of third are: ";
  	// for (std::list<int>::iterator it = third.begin(); it != third.end(); it++)
    // 	std::cout << *it << ' ';
	// std::cout << '\n';
	// std::cout << "The contents of forth are: ";
  	// for (std::list<int>::iterator it = third.begin(); it != third.end(); it++)
    // 	std::cout << *it << ' ';
	// std::cout << '\n';
	// std::cout << "The contents of fifth are: ";
  	// for (std::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
    // 	std::cout << *it << ' ';
	// std::cout << '\n';
	// std::cout << "The contents of fifth BACKWARDS are: ";
 	// for (std::list<int>::reverse_iterator rit=fifth.rbegin(); rit!=fifth.rend(); ++rit)
    // std::cout << ' ' << *rit;
	// std::cout << '\n';
  	// std::cout << "The contents of sixth (using cbegin and cend) are: ";
  	// for (std::list<int>::iterator it = sixth.cbegin(); it != sixth.cend(); ++it)
    // std::cout << ' ' << *it;
  	// std::cout << '\n'; ASK IF WE NEED CBEGIN AND CEND
	return 0;
}

int	list_assigment_opperator()
{
	std::list<int> first (3);      // list of 3 zero-initialized ints
	std::list<int> second (5);     // list of 5 zero-initialized ints

	second = first;
	first = std::list<int>();

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	return 0;
}

int    list_tests()
{
    std::cout << "PERFORMING LIST TESTS:" << std::endl;
	// list_constructor();
	// destructor cant really test ? but must be present
	list_assigment_opperator();
	return 0;
}

void	ft_testing_my_own_list()
{
	ft::list<double> A;
	std::list<double> B;
	std::list<float> C (4,100);
	ft::list<float> D (4,100);
	std::list<float> E(C);
	ft::list<float> F(D);
	ft::list<float> G = D;
	std::list<float> H = C;
	E = C;
	F = D;
	// ft_list<int> B(sixth, sixth + sizeof(sixth) / sizeof(int));	// float sixths[4] = {5.0,10.5,15.5,20.5};
	// std::list<float> b(sixths);
	// ft_list<char> B(6, "amber");
	// ft_list<int> ft_list_me2(6, 100);
	// ft_list<int>C(A);
    // ft_list<char>D = B;
	// ft_list_me2 =ft_list_me1; // workout how to test this one better
	// ft_list_me2 = ft_list_me1;
	// ft_list<int> ft_list4 (ft_list_me2);
	// ft_list<int> first;                                // empty list of ints
	// ft_list<int> second (4,100);                       // four ints with value 100
	// ft_list<int> third (second.begin(),second.end());  // iterating through second
	// ft_list<int> fourth (third); 
	// int myints[] = {16,2,77,29};
	// ft_list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
}

int    main(int argc, char **argv)
{
	ft_testing_my_own_list();
	(void)argv;
	(void)argc;
    // if (argc == 1 || argc == 2)
    // {
    //     if (argc == 1 || strcmp(argv[1], "list") == 0)
            // list_tests();
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
    // }
    // else
    //     std::cout << "invalid arguments" << std::endl;
    return (0);
}
