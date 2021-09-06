
#include "containers/ft_vector.hpp"
#include <iostream>
#include <fstream>

using namespace ft;

template <class T>
void output(vector<T> vct, std::ofstream& myfile)
{
    myfile << "size is " << vct.size() << std::endl;
    myfile << "empty is " << vct.empty() << std::endl;
    myfile << "capacity is " << vct.capacity() << std::endl;
	for (unsigned int i = 0; i < vct.size(); i++)
        myfile << ' ' << vct[i];
    myfile << std::endl;
 	typename vector<T>::iterator it = vct.begin();
	while (it != vct.end())
	{
        myfile << ' ' << *it;
		it++;
	}
    myfile << std::endl;
 	typename vector<T>::reverse_iterator itr = vct.rbegin();
	while (itr != vct.rend())
	{
        myfile << ' ' << *itr;
		itr++;
	}
    myfile << std::endl;
 	typename vector<T>::const_iterator itc = vct.begin();
	while (itc != vct.end())
	{
        myfile << ' ' << *itc;
		itc++;
	}
    myfile << std::endl;
 	typename vector<T>::const_reverse_iterator itrc = vct.rbegin();
	while (itrc != vct.rend())
	{
        myfile << ' ' << *itrc;
		itrc++;
	}
    myfile << std::endl;
}
void vector_constructor(std::ofstream& myfile)
{
	myfile << "\ncalling vector vector_constructor functions" << std::endl;

	vector<int> first;
	vector<int> second(4,100);
	vector<int> third(second.begin(),second.end());
	vector<int> fourth(second);

	output(first, myfile);
	output(second, myfile);
	output(third, myfile);
	output(fourth, myfile);
}

int main(void)
{
    std::ofstream myfile;
    myfile.open ("myfile_ft.txt");
    vector_constructor(myfile);
    myfile.close();
    return (0);
}
