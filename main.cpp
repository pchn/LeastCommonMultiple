#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if(argc != 3)
    {
        std::cout << "Please specify 2 integers!";
        return -1;
    }
    int firstNum, secondNum;
    try
    {
        firstNum = std::stoi(argv[1]);
        secondNum = std::stoi(argv[2]);
        if((firstNum <= 0) || (secondNum <=0) ||
        (std::string(argv[1]).find_first_not_of("0123456789") != -1)||
        (std::string(argv[2]).find_first_not_of("0123456789") != -1))
            throw std::invalid_argument("");
    }
    catch (std::invalid_argument&)
    {
        std::cout << "Please specify 2 integers!";
        return -2;
    }
    catch (std::out_of_range&)
    {
        std::cout << "Please specify 2 numbers of 4 byte integer type!";
        return -3;
    }

    int gcd;
    if(firstNum == secondNum)
        gcd = firstNum;

    int first = firstNum, second = secondNum;
    while(first && second)
    {
        if(first > second)
            first %= second;
        else
            second %= first;
    }
    gcd = first + second;

    std::cout << ((long long)firstNum * secondNum / gcd);
    return 0;
}
