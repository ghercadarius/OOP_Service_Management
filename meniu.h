//
// Created by gherc on 4/22/2023.
//

#ifndef PR2_CLION_MENIU_H
#define PR2_CLION_MENIU_H

#include "masini.h"
#include "stocare.h"
#include "exceptions.h"
#include <iostream>
#include <cstdlib>
class meniu{
    //static int input;
private:
    static int input;
public:
    static int get_input();
    static void set_input(const int a);
    static void dcl();
    meniu(){
        main_menu();
    }
    static void main_menu();
    static void add_car();
    static void see_cars();
    static void delete_car();
    static void calculations(int index);
    static void delete_car(int index);
    static void see_cars(int index);
    static void mcon();
};


#endif //PR2_CLION_MENIU_H
