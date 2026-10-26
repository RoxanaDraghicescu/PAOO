#include <smartArray/array.hpp>
#include <iostream>
#include <utility>

void runDemo() {
    SmartArray arr1(4, 10);
    arr1.print();

    arr1.setElement(1, 42);
    arr1.setElement(3, 99);
    std::cout<<"Dupa modif, arr1: ";
    arr1.print();

    {
        SmartArray arr2 = arr1; 
        std::cout<<"Array-ul copiat (arr2): ";
        arr2.print();
        arr2.setElement(0, 555);
        std::cout<<"Dupa modif in arr2:\n";
        arr2.print();
        std::cout<<"arr1 (ramane neschimbat): ";
        arr1.print();
    }
    
    std::cout<<"\ndupa ce arr2 a iesit din scope, arr1 inca functioneaza:\n";
    arr1.print();

    {
        SmartArray arr3(std::move(arr1)); 
        std::cout<<"Array-ul dest dupa move (arr3): ";
        arr3.print();
    } 
}

int main() {
    runDemo();
    return 0;
}