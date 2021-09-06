
#include <vector>
#include <iostream>
#include <fstream>
#include <sys/time.h>

using namespace std;
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

void	vector_assigment_opperator(std::ofstream& myfile)
{
	myfile << "\ncalling vector vector_assigment_opperator fucntions" << std::endl;
  	vector<int> foo (3,0);
  	vector<int> bar (5,0);

  	bar = foo;
  	foo = vector<int>();

	output(bar, myfile);
	output(foo, myfile);
}

void	vector_capacity(std::ofstream& myfile)
{
	myfile << "\ncalling vector vector_capacity fucntions" << std::endl;
	myfile << "Size function:" << std::endl;
	vector<int> first;
	vector<int> second(4, 100);

	output(first, myfile);
	output(second, myfile);
	
	myfile << "\nResize function:" << std::endl;
	vector<int> third;

	for (int i=1;i<10;i++) third.push_back(i);
	third.resize(5);
	third.resize(4,100);
	// myfile << third.capacity() << std::endl;
	third.resize(10,100);
	third.resize(12);

	output(third, myfile);
	// myfile << third.capacity() << std::endl;
	vector<int>::size_type sz;

	vector<int> foo;
	sz = foo.capacity();	
	for (int i=0; i<100; ++i) {
    	foo.push_back(i);
		if (sz!=foo.capacity())
			sz = foo.capacity();
  		}
	output(foo, myfile);
  	vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);
	for (int i=0; i<100; ++i) {
    	bar.push_back(i);
    	if (sz!=bar.capacity()) 
    		sz = bar.capacity();
 	 	}
	output(bar, myfile);
}

void	vector_assign(std::ofstream& myfile)
{
	myfile << "\ncalling vector vector_assign functions" << std::endl;
	vector<int> first;
	vector<int> second;
	vector<int> third;

	first.assign (7,100);             // 7 ints with a value of 100
	vector<int>::iterator it =first.begin(); it++;
	second.assign (it ,first.end());
	output(first, myfile);
	output(second, myfile);
}

void	vector_push_n_pop_back(std::ofstream& myfile)
{
	std::cout << "\ncalling vector vector_push_n_pop_back functions" << std::endl;
	vector<int> first;

	for (int i=1;i<10;i++) first.push_back(i);
	output(first, myfile);

	vector<int> second;
	int sum (0);
	second.push_back (100);
	second.push_back (200);
	second.push_back (300);
	output(second, myfile);
	while (!second.empty())
	{
    	sum+=second.back();
    	second.pop_back();
  	}
	while (!second.empty())
	{
    	sum+=second.back();
    	second.pop_back();
  	}
	myfile << sum << std::endl;
	output(second, myfile);
}

void	vector_element_access(std::ofstream& myfile)
{
	myfile << "\ncalling vector vector_element_access functions" << std::endl;
	myfile << "operator[] functions" << std::endl;
	vector<int> myvector (10, 10);

  	vector<int>::size_type sz = myvector.size();
  	for (unsigned i=0; i<sz/2; i++)
  	{
    	int temp = myvector[sz-1-i];
    	myvector[sz-1-i]=myvector[i];
    	myvector[i]=temp;
  	}
	output(myvector, myfile);
	vector<int> vectory (10);
  	for (unsigned i=0; i<vectory.size(); i++)
   		vectory.at(i)=i;
	output(vectory, myfile);
	myfile << "front functions and back" << std::endl;
	vector<int> vectorone;
	vectorone.push_back(78);
	vectorone.push_back(16);
	vectorone.front() -= vectorone.back();
	output(vectorone, myfile);
	myfile << vectorone.front() << std::endl;
	myfile << vectorone.back() << std::endl;
	vector<int> vector2;
	vector2.push_back(10);
	while (vector2.back() != 0)
	    vector2.push_back ( vector2.back() -1 );
	output(vector2, myfile);
	myfile << vector2.front() << std::endl;
	myfile << vector2.back() << std::endl;
}

void	vector_insert(std::ofstream& myfile)
{
	myfile << "\ncalling vector vector_insert functions" << std::endl;
	vector<int> myvector (3,100);
	vector<int>::iterator it;

	it = myvector.begin(); it++; it++; it++; //it_ft++;
	it = myvector.insert ( it , 200 );
	myfile << *it << std::endl;
	myvector.insert (it,2,300);
	output(myvector, myfile);

	it = myvector.begin();
	vector<int> anothervector (2,400); it++; it++;
	myvector.insert (it,anothervector.begin(),anothervector.end());
	output(myvector, myfile);
}

void 	vector_erase(std::ofstream& myfile)
{
	myfile << "\ncalling vector_erase functions" << std::endl;
	vector<int> myvector;
	for (int i=1; i<=10; i++) myvector.push_back(i);

	vector<int>::iterator first = myvector.begin(); first++;
	vector<int>::iterator last = myvector.begin(); last++; last++; last++;
	
	vector<int>::iterator result = myvector.erase (first,last);  // erase the first 3 elements:
	myfile << *result << std::endl;
	first = myvector.end(); first--;
	myvector.erase (first);
	output(myvector, myfile);
}

void	vector_swap(std::ofstream& myfile)
{
	std::cout << "\ncalling vector_swap functions" << std::endl;
	vector<int> foo (3,100);
	vector<int> bar (5,200);

	foo.swap(bar);
	output(foo, myfile);
	output(bar, myfile);
}

void	vector_relational_operators(std::ofstream& myfile)
{
	myfile << "\ncalling vector_relational_operators functions" << std::endl;
	vector<int> vectort1 (1, 100);
	vector<int> vector2(1, 100);
	vectort1.push_back (3);
  	vector2.push_back (3);
	vectort1.push_back (4);
  	vector2.push_back (4);
	// myfile << vectort1>vector2 << std::endl;
	// myfile << vectort1<vector2 << std::endl;
	// myfile << vectort1>=vector2 << std::endl;
	// myfile << vectort1<=vector2 << std::endl;
	// myfile << vectort1==vector2 << std::endl;
	// myfile << vectort1!=vector2 << std::endl;
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

void    time_diff(struct timeval begin, struct timeval end)
{
    std::ofstream myfiletime;
    myfiletime.open ("srcs/tests/myfile_std_time.txt");
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;
    myfiletime << elapsed << std::endl;
}

int main(void)
{
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    std::ofstream myfile;
    myfile.open ("srcs/tests/myfile_std.txt");
    vector_constructor(myfile);
	vector_assigment_opperator(myfile);
	vector_capacity(myfile);
	vector_element_access(myfile);
	vector_assign(myfile);
	vector_push_n_pop_back(myfile);
	vector_insert(myfile);
	vector_erase(myfile);
	vector_swap(myfile);
	vector_relational_operators(myfile);
    myfile.close();    
    gettimeofday(&end, 0);
    time_diff(begin, end);
    return (0);
}
