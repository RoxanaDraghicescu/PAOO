#include <thermometer/thermometer.hpp>
#include <iostream>

Thermometer::Thermometer(double initial_temperature) 
    : temperature_(new double(initial_temperature)) {
    std::cout << "am alocat memorie pe heap pentru valoarea: " 
              << *temperature_ << " (Adresa: " << temperature_ << ")\n";
}

Thermometer::~Thermometer() {
    if (temperature_ != nullptr) {
        std::cout << "am eliberat memoria de pe heap de la adresa: " 
                  << temperature_ << " (Valoare: " << *temperature_ << ")\n";
        delete temperature_;
        temperature_ = nullptr;
    } else {
        std::cout << "nullptr\n";
    }
}

// Suprascrierea Copy Constructor-ului
// De ce este nevoie? 
// Daca nu am fi suprascris copy constructor-ul, compilatorul ar fi generat o copiere superficiala (shallow copy)
// in acel caz, 2 obiecte diferite ar fi partajat aceeasi adresa de memorie de pe heap
// La iesirea din scope, ambele obiecte ar fi incercat sa stearga aceeasi adresa, ducand la eroare de "double delete" și crash
Thermometer::Thermometer(const Thermometer& other) {
    if (other.temperature_ != nullptr) {
        temperature_ = new double(*(other.temperature_)); 
        std::cout << "Valoare clonata: " 
                  << *temperature_ << " (adresa noua pe heap: " << temperature_ << ")\n";
    } else {
        temperature_ = nullptr;
        std::cout << "nullptr\n";
    }
}

// transfera dreptul de proprietate asupra memoriei fara a aloca nou spatiu pe heap
Thermometer::Thermometer(Thermometer&& other) noexcept 
    : temperature_(other.temperature_) {
    other.temperature_ = nullptr; 
    std::cout << "am mutat resursa de pe heap. Noua adresa: " 
              << temperature_ << "\n";
}

double Thermometer::getTemperature() const {
    if (temperature_ != nullptr) {
        return *temperature_;
    }
    return 0.0;
}

void Thermometer::setTemperature(double new_temperature) {
    if (temperature_ != nullptr) {
        *temperature_ = new_temperature;
    } else {
        temperature_ = new double(new_temperature);
    }
}