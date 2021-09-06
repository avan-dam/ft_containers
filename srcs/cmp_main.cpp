#include <iostream>
#include <fstream>

int main(void)
{
    std::ifstream in("myfile_std.txt"); //open two ins and one out
    std::ifstream in2("myfile_ft.txt");
    int found = 0;
    while ((!in.eof()) && (!in2.eof())) { //continue you get til the end of both
        std::string line,line2;
        getline(in,line);
        getline(in2,line2);
        if(line!=line2){ 
           std::cout << "first unequal line is" << std::endl;
           std::cout << line << std::endl;
           std::cout << "and" << std::endl;
           std::cout << line2 << std::endl;
           found = -1;
           break;
        }
    }
    in.close();
    in2.close();
    if (found == 0)
        std::cout << "FILES ARE EQUAL" << std::endl;
    else
        std::cout << "FILES ARE NOTEQUAL" << std::endl;
    return (0);
}
