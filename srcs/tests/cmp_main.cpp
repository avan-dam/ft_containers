#include <iostream>
#include <fstream>
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */

void    test_content()
{
    std::ifstream in("srcs/tests/myfile_std.txt");
    std::ifstream in2("srcs/tests/myfile_ft.txt");
    int found = 0;
    int i = 0;

    while ((!in.eof()) && (!in2.eof())) 
    {
        i++;
        std::string line,line2;
        getline(in,line);
        getline(in2,line2);
        if(line!=line2){ 
           std::cout << "first unequal line is" << std::endl;
           std::cout << line << std::endl;
           std::cout << "and" << std::endl;
           std::cout << line2 << std::endl;
           std::cout << "on line " << i << std::endl;
           found = -1;
           break;
        }
    }
    in.close();
    in2.close();
    if (found == 0)
        std::cout << GREEN << "THE CONTENT OF THE FILES ARE EQUAL" << RESET << std::endl;
    else
        std::cout << RED << "THE CONTENT OF THE FILES ARE NOTEQUAL" << RESET << std::endl;
}

void    test_timing()
{
    std::ifstream   std("srcs/tests/myfile_std_time.txt");
    std::ifstream   ft("srcs/tests/myfile_ft_time.txt");
    std::string     stdline;
    std::string     ftline;
    double          stdtime;
    double          fttime;

    getline(std,stdline);
    getline(ft,ftline);

    stdtime = atof( stdline.c_str());
    fttime = atof( ftline.c_str());
    std::cout << "time of execution in seconds for std is " << stdtime << " and for ft it is" << fttime << std::endl;
    if ((stdtime * 20) < fttime)
        std::cout << RED << "TIME IS TOO SLOW FOR PROJECT SPECIFICATIONS" << RESET << std::endl;
    else
        std::cout << GREEN << "TIME IS GOOD SPEED FOR PROJECT SPECIFICATIONS" << RESET << std::endl;
}


int main(void)
{
    test_content();
    test_timing();
    return (0);
}
