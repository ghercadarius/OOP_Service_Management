//
// Created by gherc on 4/22/2023.
//

#ifndef PR2_CLION_EXCEPTIONS_H
#define PR2_CLION_EXCEPTIONS_H

#include <exception>
using namespace std;

class Exception1 : public exception{ //out of bounds
public:
    virtual const char* what() const noexcept{
        return "Index out of bounds";
    }
};

class Exception2: public exception{ //invalid value for calculations of tax or
public:
    virtual const char* what() const noexcept{
        return "Invalid data for calculations";
    }
};


#endif //PR2_CLION_EXCEPTIONS_H
