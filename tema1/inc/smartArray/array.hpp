#ifndef SMART_ARRAY_HPP
#define SMART_ARRAY_HPP

class SmartArray {
private:
    int* data_;    
    int size_;      

public:
    SmartArray(int size, int value);

    ~SmartArray();

    SmartArray(const SmartArray& other);

    SmartArray(SmartArray&& other) noexcept;

    int getSize() const;
    int getElement(int index) const;
    void setElement(int index, int value);
    void print() const;
};

#endif 