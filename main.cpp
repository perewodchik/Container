#include <iostream>
#include "Container.h"
#include "Character.h"

int main() {

    /*
     * Testing container of integers
     * */
    Container<int> intC;
    const int MaxOperations = 1000000;

    // NlogN operations
    for(int i = 0; i < MaxOperations; i++)
    {
        intC.insert(i);
    }

    Container<int> splitC = intC.split(MaxOperations / 2);
    for(int i = 0; i < 10; i++)
    {
        std::cout << splitC.at(i) << " at position " << i << "\n";
    }

    try
    {
        splitC.at(MaxOperations);
    } catch (std::out_of_range)
    {
        std::cout << "Tried to access " << MaxOperations << "th element\n";
        std::cout << "Caught out of range exception\n";
    }

    std::cout << "\n";
    for(int i = MaxOperations; i > MaxOperations  - 10; --i)
    {
        std::cout << "Position of " << i << " is " << splitC.find(i) << "\n";
    }
    std::cout << "\n";


    /*
     * Testing container of custom objects
     * */
    Container<Character> charC;

    Character Itachi("Itachi", "9.6.1995", 178, 57);
    Character Denis("Denis", "25.8.2000", 175, 65);
    charC.insert(Itachi);
    charC.insert(Denis);
    charC.emplace("Naruto", "13.10.1997", 166, 50);
    charC.emplace("Kolya", "1.11.2000", 179, 75);

    int position = charC.find(Itachi);
    std::cout << "Position of Itachi is: " << position << "\n\n";

    for(int i = 0; i < charC.size(); ++i)
    {
        std::cout << charC.at(i) << "\n";
    }

    return 0;
}