#include <smartArray/array.hpp>
#include <iostream>

SmartArray::SmartArray(int size, int value) : data_(new int[size]), size_(size) {
    for (int i = 0; i < size_; ++i) {
        data_[i] = value;
    }
    std::cout<<"Am alocat un array de "<<size_ <<" elem pe heap la adresa: "<<data_<<"\n";
}

SmartArray::~SmartArray() {
    if (data_ != nullptr) {
        std::cout<<"Am eliberat array-ul de la adresa: "<<data_<<"(Size: "<<size_<<")\n";
        delete[] data_;
        data_ = nullptr;
        size_ = 0;
    } else {
        std::cout<<"obiectul e gol (nullptr)\n";
    }
}

//Copy Constructor - DEEP COPY 
// De ce e nevoie? fara el, compilerul face shallow copy: 2 obiecte ar arata spre acelasi bloc `data_`, iar la stergere amandoua ar incerca sa stearga acceasi memorie si s-ar produce "double delete" si crash
SmartArray::SmartArray(const SmartArray& other) : data_(new int[other.size_]), size_(other.size_) {
    for (int i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
    std::cout<<"Am alocat o adresa noua pe heap: "<<data_ <<" pt"<<size_<<" elem\n";
}

// se preia pointerul și dimensiunea fără să facă alocări noi pe heap.
SmartArray::SmartArray(SmartArray&& other) noexcept : data_(other.data_), size_(other.size_) {
    other.data_ = nullptr; 
    other.size_ = 0;
    std::cout << "Am mutat resursa de pe heap fara realocare, noua adresa este: "<<data_<<"\n";
}

int SmartArray::getSize() const {
    return size_;
}

int SmartArray::getElement(int index) const {
    if (index >= 0 && index < size_) {
        return data_[index];
    }
    return -1; 
}

void SmartArray::setElement(int index, int value) {
    if (index >= 0 && index < size_) {
        data_[index] = value;
    }
}

void SmartArray::print() const {
    std::cout<<"Array [ ";
    for (int i = 0; i < size_; ++i) {
        std::cout<<data_[i]<<" ";
    }
    std::cout<<"](Adresa: "<<data_<<")\n";
}