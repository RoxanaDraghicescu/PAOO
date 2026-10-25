#ifndef THERMOMETER_HPP
#define THERMOMETER_HPP

class Thermometer {
private:
    double* temperature_;

public:
    explicit Thermometer(double initial_temperature);
    //Destructor 
    ~Thermometer();
    //Copy Constructor
    Thermometer(const Thermometer& other);
    //Move Constructor
    Thermometer(Thermometer&& other) noexcept;

    double getTemperature() const;
    void setTemperature(double new_temperature);
};

#endif 