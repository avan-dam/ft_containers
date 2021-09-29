#include <iostream>
#include <fstream>
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */

void    test_content()
{
    std::ifstream std("srcs/tests/myfile_std.txt");
    std::ifstream ft("srcs/tests/myfile_ft.txt");
    int found = 0;
    int i = 0;
    int nolinesft = 0;
    int nolinesstd = 0;
    std::string stdline;
    std::string ftline;

    while ((!std.eof()) && (!ft.eof())) 
    {
        i++;
        getline(ft,ftline);
        getline(std,stdline);
        if(ftline!=stdline){ 
           std::cout << "first unequal line is std is:" << std::endl;
           std::cout << stdline << std::endl;
           std::cout << "and ft is:" << std::endl;
           std::cout << ftline << std::endl;
           std::cout << "on line " << i << std::endl;
           found = -1;
           break;
        }
    }
    while ((!std.eof())) 
    {
        getline(std,stdline);
        nolinesft++;
    }
    while ((!ft.eof())) 
    {
        getline(ft,ftline);
        nolinesstd++;
    }
    if (nolinesft != nolinesstd)
        found = -1;
    if (found == 0)
        std::cout << GREEN << "THE CONTENT OF THE FILES ARE EQUAL" << RESET << std::endl;
    else
        std::cout << RED << "THE CONTENT OF THE FILES ARE NOTEQUAL" << RESET << std::endl;
    std.close();
    ft.close();
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
    std.close();
    ft.close();
}


int main(void)
{
    test_content();
    test_timing();
    return (0);
}
