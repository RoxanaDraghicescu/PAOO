#include <thermometer/thermometer.hpp>
#include <iostream>
#include <utility>

void runApplicationDemo() {
    std::cout << "creare obiect original\n";
    Thermometer t1(21.5);
    
    std::cout << "temp curenta (t1): " << t1.getTemperature() << " °C\n";
    t1.setTemperature(23.8);
    std::cout << "temp modificata (t1): " << t1.getTemperature() << " °C\n";

    std::cout << "\nTestare Copy Constructor\n";
    {
        Thermometer t2 = t1; 
        std::cout << "temp obiectului copiat (t2): " << t2.getTemperature() << " °C\n";
    }

    std::cout << "\nTestare Move Constructor\n";
    {
        Thermometer t3(std::move(t1));
        std::cout << "temp obiectului dest dupa move (t3): " << t3.getTemperature() << " °C\n";
    } 
}

int main() {
    runApplicationDemo();
    return 0;
}