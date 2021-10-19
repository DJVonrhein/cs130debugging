#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void print_cases(const std::string& name)
{
    std::string up = name;
    std::string lo = name;

    for(size_t i = 0; i < name.size(); i++)
    {
        up.at(i) = std::toupper(name[i]);
        lo.at(i) = std::tolower(name[i]);
    }

    std::cout << lo << " " << up << std::endl;
}

int main()
{
    print_cases("Elizabeth");
    print_cases("John");
    print_cases("Frank");
    print_cases("Fred");

    return 0;
}

