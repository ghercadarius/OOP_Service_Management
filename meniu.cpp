//
// Created by gherc on 4/22/2023.
//


#include "meniu.h"
#include "masini.h"
#include "stocare.h"
#include "exceptions.h"
#include "mvec.h"

#include <iostream>
#include <cstdlib>

int meniu::input = -1;
int vehicul::masini_rulate = 0;
int ev::masini_ev_rulate = 0;
int hibrid::masini_hibrid_rulate = 0;
int termic::masini_termic_rulate = 0;

void meniu::mcon(){
    cout << "\n";
    string x;
    do{
        cout << "Type anything to continue\n";
        cin >> x;
    }while(false);
}

int meniu::get_input(){
    return input;
}

void meniu::set_input(const int a){
    input = a;
}

void meniu::dcl(){
    //system("cls");
}

void meniu::main_menu(){
    do{
        dcl();
        cout << "Project made by Gherca Darius\n\n1) Add a car\n2) See all cars\n3) Delete last car\n4) Delete a car by its index\n5) Show a car by its index\n"
                "6) Measure rating or tax of car by index\n7) Counter Reset\n8) Exit\nEnter your option by typing the desired number\n";
        int x;
        cin>>x;
        set_input(x);
        switch(get_input()){
            case 1:
                add_car();
                break;
            case 2:
                see_cars();
                break;
            case 3:
                delete_car();
                break;
            case 4:
                cout << "Index: ";
                cin >> x;
                delete_car(x);
                break;
            case 5:
                cout << "Index: ";
                cin >> x;
                see_cars(x);
                break;
            case 6:
                cout << "Index: ";
                cin >> x;
                calculations(x);
                break;
            case 7:
                counter_reset();
                break;
            case 8:
                set_input(8);
                break;
        }
        cout<<"!";
        if(get_input() != 8)
        set_input(-1);
    }while(get_input() == -1);
}

void meniu::counter_reset(){
    cout << vehicul::nr_masini_rulate() << "\n";
    vehicul::nr_masini_reset();
    cout << ev::nr_masini_ev_rulate() << "\n";
    ev::nr_masini_ev_reset();
    cout << termic::nr_masini_termic() << "\n";
    termic::nr_masini_termic_reset();
    cout << hibrid::nr_masini_hibrid() << "\n";
    hibrid::reset_nr_masini_hibrid();
    mcon();
}

void meniu::add_car(){
    set_input(-1);
    vehicul *nev;
    do{
        dcl();
        cout << "Project made by Gherca Darius\n\n1) Electric Vehicle\n2) Gas Vehicle\n3) Hybrid vehicle\nEnter your option by typing the desired number\n";
        int x;
        cin >> x;
        set_input(x);
        dcl();
        cout << "Fabrication date with / or just the year\n";
        string dfab;
        cin >> dfab;
        cout << "Vin\n";
        string nvin;
        cin >> nvin;
        cout << "Consumption\n";
        int ncon;
        cin >> ncon;
        cout << "Brand\n";
        string nmarca;
        cin >> nmarca;
        cout << "Weight\n";
        int ngreutate;
        cin >> ngreutate;
        int nbat, nrang, ncap, neng, nbhp;
        switch(get_input()) {
            case 1:
                cout << "Battery Capacity\n";
                cin >> nbat;
                cout << "Range\n";
                cin >> nrang;
                nev = new ev(dfab, nvin, ncon, nmarca, ngreutate, nbat, nrang);
                stoc.push(nev);
                break;
            case 2:
                cout << "Tank capacity\n";
                cin >> ncap;
                cout << "Engine displacement\n";
                cin >> neng;
                cout << "Horsepower\n";
                cin >> nbhp;
                nev = new termic(dfab, nvin, ncon, nmarca, ngreutate, ncap, neng, nbhp);
                stoc.push(nev);
                break;
            case 3:
                cout << "Tank capacity\n";
                cin >> ncap;
                cout << "Engine displacement\n";
                cin >> neng;
                cout << "Horsepower\n";
                cin >> nbhp;
                cout << "Battery Capacity\n";
                cin >> nbat;
                cout << "Range\n";
                cin >> nrang;
                nev = new hibrid(dfab, nvin, ncon, nmarca, ngreutate, ncap, neng, nbhp, nbat, nrang);
                stoc.push(nev);
                break;
        }
        cout << "If you wish to add another, type 1\nElse type 2\n";
        cin >> x;
        if(x == 1)
            x = -1;
        set_input(x);
    }while(get_input() == -1);
}

void meniu::delete_car(){
    stoc.pop();
    mcon();
}

void meniu::delete_car(int index){
    try{
        stoc.del_el(index);
    }
    catch (const Exception1 &e){
        cout << e.what() << "\n";
    }
    mcon();
}

void meniu::see_cars(){
    /*for(auto i: *stocare::vec_masini()) {
        cout << typeid(*i).name() << "\n";
    }*/
    cout << stoc;
    mcon();
}

void meniu::see_cars(int index){
    try {
        cout << stoc.read_el(index);
    }
    catch (const Exception1 &e){
        cout << e.what() << "\n";
    }
    mcon();
}

void meniu::calculations(int index){
    try{
        vehicul *aux = stoc.read_el(index);
        cout << "Tax: " << aux -> calc_impozit() << "\n";
        cout << "Rating: " << aux -> calc_nota() << "\n";
    }
    catch(const Exception1 &e){
        cout << e.what() << "\n";
    }
    catch(const Exception2 &e) {
        cout << e.what() << "\n";
    }
    mcon();
}