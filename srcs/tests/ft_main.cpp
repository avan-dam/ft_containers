
#include "../containers/ft_vector.hpp"
#include "../containers/ft_map.hpp"
#include "../containers/ft_stack.hpp"
#include <iostream>
#include <fstream>
#include <list>
#include <sys/time.h>

using namespace ft;

template <class T>
void output(vector<T> vct, std::ofstream& myfile)
{
    myfile << "size is " << vct.size() << std::endl;
    myfile << "empty is " << vct.empty() << std::endl;
    myfile << "capacity is " << vct.capacity() << std::endl;
	for (unsigned int i = 0; i < vct.size(); i++)
        myfile << ' ' << vct[i];
    myfile << "starting" << std::endl;
    myfile << std::endl;
	if (vct.size() == 0)
		return;
 	typename vector<T>::iterator it = 2 + vct.begin();
	while (it != vct.end())
	{
        myfile << ' ' << *it;
		it++;
	}
    myfile << std::endl;
    myfile << "reverse_iterator" << std::endl;
 	typename vector<T>::reverse_iterator itr = vct.rbegin();
	while (itr != vct.rend() - 1)
	{
        myfile << ' ' << *itr;
		itr++;
	}
    myfile << std::endl;
 	typename vector<T>::const_iterator itc = vct.begin();
	if (itc == it)
		myfile << "iterator comparable start same" << std::endl;
	else 
		myfile << "iterator comparable start NOT same" << std::endl;
	while (itc != vct.end())
	{
        myfile << ' ' << *itc;
		itc++;
	}
    myfile << std::endl;
    myfile << "const_reverse_iterator" << std::endl;
 	typename vector<T>::const_reverse_iterator itrc = vct.rbegin() + 2;
 	typename vector<T>::const_reverse_iterator itrce = vct.rend();
	while (itrc != itrce)
	{
        myfile << ' ' << *itrc;
		itrc++;
	}
    myfile << "ending" << std::endl;
    myfile << std::endl;
}

template <class Key, class T>
void output_map(map<Key, T> mp, std::ofstream& myfile)
{
    myfile << "size is " << mp.size() << std::endl;
    myfile << "empty is " << mp.empty() << std::endl;
	if (mp.size() == 0)
		return;
 	typename map<Key, T>::iterator it = mp.begin();
	while (it != mp.end())
	{
        myfile << ' ' << it->first << "=" << it->second;
		it++;
	}
    myfile << std::endl;
 	typename map<Key, T>::reverse_iterator itr = mp.rbegin();
	while (itr != mp.rend())
	{
        myfile << ' ' << itr->first << "=" << itr->second;
		itr++;
	}
    myfile << std::endl;
 	typename map<Key, T>::const_iterator itc = mp.begin();
	while (itc != mp.end())
	{
        myfile << ' ' << itc->first << "=" << itc->second;
		itc++;
	}
    myfile << std::endl;
 	typename map<Key, T>::const_reverse_iterator itrc = mp.rbegin();
 	typename map<Key, T>::const_reverse_iterator itrce = mp.rend();
	while (itrc != itrce)
	{
        myfile << ' ' << itrc->first << "=" << itrc->second;
		itrc++;
	}
    myfile << std::endl;
}

void		random_map_tests(std::ofstream& myfile)
{
    myfile << "PERFORMING MAP TESTS:" << std::endl;
	map<char, int> m;

	m.insert ( pair<char,int>('b',100) );
	m.insert ( pair<char,int>('a',2) );
	m.insert ( pair<char,int>('c',500) );
	m.insert ( pair<char,int>('l',100) );
	m.insert ( pair<char,int>('d',2) );
	m.insert ( pair<char,int>('p',500) );
	m.insert ( pair<char,int>('y',500));
	m.insert ( pair<char,int>('f',100));
	m.insert ( pair<char,int>('h',2));
	m.insert ( pair<char,int>('e',2));

	output_map(m, myfile);
	map<char,int> second (m.begin(),m.end());

	output_map(second, myfile);
	map<char,int> third(second);
	third.clear();
	output_map(third, myfile);

	map<char,int> fourth = second;
	myfile << fourth.begin()->first << std::endl;
	output_map(fourth, myfile);

	map<char,int> fifth;
	output_map(fifth, myfile);

  	map<char,std::string> mymap4;
  	mymap4['a']="an element";
  	mymap4['b']="another element";
  	mymap4['c']=mymap4['b'];
  	
	myfile << mymap4['a'] << std::endl;
	myfile << mymap4['b'] << std::endl;
	myfile << mymap4['c'] << std::endl;
	myfile << mymap4['d'] << std::endl;
	output_map(mymap4, myfile);
	
	myfile << mymap4.count('c') << std::endl;
	myfile << mymap4.count('y') << std::endl;
	myfile << mymap4.find('c')->first << std::endl;
}

void	map_key_compare(std::ofstream& myfile)
{
    myfile << "PERFORMING map key TESTS:" << std::endl;

	map<char,int> mymap1;

  	mymap1['a']=100;
	mymap1['b']=200;
	mymap1['c']=300;

	myfile << mymap1['a'] << std::endl;
	myfile << mymap1['b'] << std::endl;
	myfile << mymap1['c'] << std::endl;

	output_map(mymap1, myfile);

  	map<char,std::string>	mymap;

  	mymap['a']="an element";
  	mymap['b']="another element";
  	mymap['c']=mymap['b'];

	myfile << mymap['a'] << std::endl;
	myfile << mymap['b'] << std::endl;
	myfile << mymap['c'] << std::endl;

	map<char,int>::key_compare mycomp = mymap.key_comp();

	myfile << "mymap1 contains:\n";
	char highesty = mymap1.rbegin()->first;
	map<char,int>::iterator ity = mymap1.begin();
  	do {
    	myfile << ity->first << " => " << ity->second << '\n';
	} while ( mycomp((*ity++).first, highesty) );
	myfile << '\n';

	myfile << "value comp" << std::endl;
    map<char,int> mymap2;

	mymap2['x']=1001;
	mymap2['y']=2002;
	mymap2['z']=3003;

	myfile << "mymap contains:\n";
	pair<char,int> highest1 = *mymap2.rbegin();

	map<char,int>::iterator it1 = mymap2.begin();
	do {
    	myfile << it1->first << " => " << it1->second << '\n';
	} while ( mymap2.value_comp()(*it1++, highest1) );
}

void	map_insert_tests(std::ofstream& myfile)
{
	myfile << "in map insert test" << std::endl;
	map<char,int> mymap;

	mymap.insert ( pair<char,int>('a',100) );
	mymap.insert ( pair<char,int>('z',200) );

	pair<map<char,int>::iterator,bool> retft;

	retft = mymap.insert ( pair<char,int>('z',500) );

	myfile << retft.second << std::endl;
	myfile << retft.first->second << std::endl;

	map<char,int>::iterator it = mymap.begin();
	mymap.insert (it, pair<char,int>('b',300)); 
	mymap.insert (it, pair<char,int>('c',400)); 

	map<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.find('c'));

	output_map(mymap, myfile);
	output_map(anothermap, myfile);

	myfile << mymap.upper_bound('b')->first << std::endl;
	myfile << mymap.lower_bound('b')->first << std::endl;
}

void	map_equal_range(std::ofstream& myfile)
{
	map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	pair<map<char,int>::iterator,map<char,int>::iterator> ret;

	ret = mymap.equal_range('b');

	myfile << ret.first->second << std::endl;
	myfile << ret.first->first << std::endl;
}

void	map_swap(std::ofstream& myfile)
{
	map<char,int> foo,bar;

	foo['x']=100;
	foo['y']=200;
	foo['p']=4;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;
	
	map<char,int>::iterator it1 = foo.begin();
	map<char,int>::iterator it2 = bar.begin();
	myfile << "b4 swap it1->first"<< it1->first << std::endl;
	myfile << "b4 swap it1->first"<< it2->first << std::endl;
	foo.swap(bar);
	myfile << "afta swap it1->first"<< it1->first << std::endl;
	myfile << "afta swap it1->first"<< it2->first << std::endl;
	output_map(foo, myfile);
	output_map(bar, myfile);
}

void	map_erase(std::ofstream& myfile)
{
	map<char,int> mymap;
	map<char,int>::iterator it;

	mymap['a']=10;
	mymap['b']=20;
	mymap['k']=30;
	mymap['m']=30;
	mymap['o']=30;
	mymap['g']=40;
	mymap['e']=50;
	mymap['f']=60;

	it=mymap.find('b');
	mymap.erase (it);  
	output_map(mymap, myfile);

	mymap.erase ('e');     
	output_map(mymap, myfile);
 
	mymap.erase ( mymap.begin(), mymap.end() );
	output_map(mymap, myfile);
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
	third.resize(10,100);
	third.resize(12);

	output(third, myfile);
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

	first.assign (7,100); 
	vector<int>::iterator it =first.begin(); it++;
	second.assign (it ,first.end());
	output(first, myfile);
	output(second, myfile);
}

void	vector_push_n_pop_back(std::ofstream& myfile)
{
	myfile << "\ncalling vector vector_push_n_pop_back functions" << std::endl;
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
	myvector.push_back(4);
	myvector.push_back(7);
	vector<int>::iterator it;

	it = myvector.begin(); it++; it++;
	it = myvector.insert ( it , 200 );
	myfile << *it << std::endl;
	myvector.insert (it,2,300);
	output(myvector, myfile);

	it = myvector.begin();
	vector<int> anothervector (2,400); it++; it++;
	anothervector.push_back(5);
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
	
	vector<int>::iterator result = myvector.erase (first,last);
	myfile << *result << std::endl;
	first = myvector.end(); first--;
	myvector.erase (first);
	output(myvector, myfile);
}

void	vector_swap(std::ofstream& myfile)
{
	myfile << "\ncalling vector_swap functions" << std::endl;
	vector<int> foo (3,100);
	vector<int> bar (5,200);

	vector<int>::iterator it1 = foo.begin();
	vector<int>::iterator it2 = bar.begin();
	myfile << "b4 swap it1->first"<< *it1 << std::endl;
	myfile << "b4 swap it1->first"<< *it2 << std::endl;
	foo.swap(bar);
	myfile << "afta swap it1->first"<< *it1 << std::endl;
	myfile << "afta swap it1->first"<< *it2 << std::endl;
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
}


void    time_diff(struct timeval begin, struct timeval end)
{
    std::ofstream myfiletime;
    myfiletime.open ("srcs/tests/myfile_ft_time.txt");
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;
    myfiletime << elapsed << std::endl;
}

void vector_tests(std::ofstream& myfile)
{
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
}

void	map_tests(std::ofstream& myfile)
{
	random_map_tests(myfile);
	map_key_compare(myfile);
	map_insert_tests(myfile);
	map_equal_range(myfile);
	map_swap(myfile);
	map_erase(myfile);
}

void    stack_tests(std::ofstream& myfile)
{
    myfile << "\n\nPERFORMING STACK TESTS:" << std::endl;
	myfile << "calling constructors" << std::endl;
	std::list<int> listy(1, 1);
  	vector<int> myvector (2,200);
	stack<int,std::list<int> > first(listy);
  	stack<int,vector<int> > second (myvector);
	myfile << first.size() << std::endl;
	myfile << second.size() << std::endl;
	myfile << first.empty() << std::endl;
	myfile << second.empty() << std::endl;

  	stack<int> mystack;

	myfile << "calling push()" << std::endl;
  	mystack.push(10);
  	mystack.push(20);

	myfile << "calling top()" << std::endl;
	mystack.top() -= 5;
	myfile << mystack.top() << std::endl;

	stack<int> mystack1;

	myfile << "calling push()" << std::endl;
	for (int i=0; i<5; ++i) mystack1.push(i);
	myfile << "testing pop() and top() and empty()" << std::endl;
	while (!mystack1.empty())
  	{
		myfile << mystack1.top() << std::endl;
    	mystack1.pop();
  	}
	myfile << "mystack1.empty()" << std::endl;
	myfile << mystack1.empty() << std::endl;
	myfile << "stack relational operator tests:" << std::endl;
	vector<int> vec(2, 20);
  	stack<int,vector<int> > st1;
  	stack<int,vector<int> > st2;
	for (int i=0; i<1; ++i) st1.push(2);
	myfile << std::boolalpha << (st1 == st2) << std::endl;
	myfile << std::boolalpha << (st1 < st2) << std::endl;
	myfile << std::boolalpha << (st1 <= st2) << std::endl;
}

int main(void)
{
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    std::ofstream myfile;
    myfile.open ("srcs/tests/myfile_ft.txt");
	vector_tests(myfile);
	map_tests(myfile);
	stack_tests(myfile);
    myfile.close();
    gettimeofday(&end, 0);
    time_diff(begin, end);
    return (0);
}
