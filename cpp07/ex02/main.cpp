#include <iostream>
#include <ctime>//
#include <cstdlib>//
#include "Array.hpp"//

#define MAX_VAL 5
int main(int, char**)
{

    {//my own test for the default consrtructor of Array 
        Array<int> array_int;

        try
        {
            array_int[5];
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        std::cout << "(" << value << "; ";
        numbers[i] = value;
        std::cout << numbers[i] << ")" << std::endl;
        mirror[i] = value;
    }

    //SCOPE
    {
        std::cout << "NUMBERS ARE: " << numbers << std::endl;
        Array<int> tmp = numbers;
        std::cout << "TMP: " << tmp << std::endl;
        Array<int> test(tmp);
        std::cout << "TEST: " << test << std::endl;
        test[0] = 0;
        std::cout << "TEST updated: " << test << std::endl;
        std::cout << "NUMBER after test update: " << numbers << std::endl;


    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    std::cout << " -> copy constructor: ok" << std::endl;//

    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << " -> error detected" << std::endl;//
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << " -> error detected" << std::endl;//
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}