/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-dam <avan-dam@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/23 14:38:34 by avan-dam      #+#    #+#                 */
/*   Updated: 2021/04/16 14:27:49 by ambervandam   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.hpp"
#include "list_node.hpp"
#include "list_iterator.hpp"
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
	std::cout <<"here"<< std::endl;
	std::list<int> first;                                // empty list of ints
	ft::list<int> second;
	std::list<int> third (4,100);                       // four ints with value 100
// 	std::list<int> third (second.begin(),second.end());  // iterating through second
// 	std::list<int> fourth (third);                       // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	// int myints[] = {16,2,77,29};
	// std::list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
	// std::list<int> sixth = fifth;


	// std::cout << "The contents of first are: ";
  	// for (std::list<int>::iterator it = first.begin(); it != first.end(); it++)
    // 	std::cout << *it << ' ';
	// std::cout << '\n';
	// std::cout << "The contents of second are: ";
  	// for (std::list<int>::iterator it = second.begin(); it != second.end(); it++)
    // 	std::cout << *it << ' ';
	// std::cout << '\n';
	std::cout << "The contents of third are: ";
  	for (std::list<int>::iterator it = third.begin(); it != third.end(); it++)
    	std::cout << *it << ' ';
	std::cout << '\n';
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
	std::list<int> first (3, 5);      // list of 3 zero-initialized ints
	ft::list<int> first2 (3, 5);      // list of 3 zero-initialized ints
	// std::list<int> second (5);     // list of 5 zero-initialized ints
	// ft::list<int> second2 (5);     // list of 5 zero-initialized ints

	// second = first;
	// first = std::list<int>();
	// second2= first2;
	// first2 = ft::list<int>();

	// std::cout << "Size of first: " << int (first.size()) << '\n';
	// for (std::list<int>::iterator it = first.begin(); it != first.end(); ++it)
    // 	std::cout << ' ' << *it;
  	// std::cout << '\n';
	// std::cout << "Size of second: " << int (second.size()) << '\n';
	// std::cout << "Size of first2: " << int (first2.size()) << '\n';
	std::cout << "FIRST2:" << std::endl;
	for (ft::list<int>::iterator itp = first2.begin(); itp != first2.end(); ++itp)
    	std::cout << ' ' << *itp;
  	std::cout << '\n';
	std::cout << "FIRST:" << std::endl;
	for (std::list<int>::iterator ity = first.begin(); ity != first.end(); ++ity)
    	std::cout << ' ' << *ity << ' ';
  	std::cout << '\n';

	std::cout << "iterator constructors" << std::endl;
	std::list<int> second (4,100);                       // four ints with value 100
  	std::list<int> third (second.begin(),second.end());
	ft::list<int> second2 (4,100);                       // four ints with value 100
  	ft::list<int> third2 (second2.begin(),second2.end());
	// for (ft::list<int>::iterator it = third2.begin(); it != third2.end(); it++)
    	// std::cout << "it is:" << *it << std::endl;
	// std::cout << "first it is" << third2.begin() << '\n';
	return 0;
}

int    list_tests()
{
    std::cout << "PERFORMING LIST TESTS:" << std::endl;
	list_constructor();
	// destructor cant really test ? but must be present
	list_assigment_opperator();
	return 0;
}

void	ft_testing_my_own_list()
{
	// ft::list<double> A;
	// std::list<double> B;
	// ft::list<double> A2(2);
	// std::list<double> B2(2);
	
	std::list<float> C(4,100);
	ft::list<float> D(4,100);
	std::cout << "size of D is : " << D.size() << std::endl;
	std::list<float> E(C);
	ft::list<float> F(D);
	std::cout << "size of F is : " << F.size() << std::endl;
	// std::cout << "2size of D is : " << D.size() << std::endl;
	// ft::list<float> G = D;
	// std::list<float> H = C;
	// std::cout << "A empty function gives: " << A.empty() << std::endl;
	// std::cout << "B empty function gives: " << B.empty() << std::endl;
	// std::cout << "size of G is : " << G.size() << std::endl;
	// std::cout << "before it " << std::endl;
	// ft::list<float>::iterator it= D.begin();
	// ft::list<float>::iterator ite= D.end();
	// std::cout << "size of D is : " << D.size() << std::endl;
	// ft::list<double>::iterator it = A.begin();
	// ft::list<double>::iterator ite = A.end();
	std::cout <<"about titerate E begin is:" << *(E.begin()) << std::endl;
	std::cout <<"about titerate F begin is:" << *(F.begin()) << std::endl;
  	for (ft::list<float>::iterator it = F.begin(); it != F.end(); it++)
    	std::cout << "iteratoring F: " << *it << std::endl;
	std::cout <<"finished titerate F" << std::endl;
  	for (ft::list<float>::iterator ite = D.begin(); ite != D.end(); ite++)
    	std::cout << "iteratoring D: " << *ite << std::endl;
	// std::cout << "after it " << std::endl;
	return ;
}

int    main(int argc, char **argv)
{
	ft_testing_my_own_list();
	(void)argv;
	(void)argc;
    // if (argc == 1 || argc == 2)
    // {
    //     if (argc == 1 || strcmp(argv[1], "list") == 0)
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
    // }
    // else
    //     std::cout << "invalid arguments" << std::endl;
    return (0);
}
