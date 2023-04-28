//
// Created by gherc on 4/22/2023.
//


#include "meniu.h"
#include "masini.h"
#include "stocare.h"
#include "exceptions.h"

#include <iostream>
#include <cstdlib>

int meniu::input = -1;
int vehicul::masini_rulate = 0;
int ev::masini_ev_rulate = 0;
int hibrid::masini_hibrid_rulate = 0;
int termic::masini_termic_rulate = 0;

void meniu::mcon(){
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
                "6) Measure rating or tax of car by index\nEnter your option by typing the desired number\n";
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
        }
        cout<<"!";
        set_input(-1);
    }while(get_input() == -1);
}

void meniu::add_car(){
    set_input(-1);
    shared_ptr<vehicul> nev;
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
                nev = make_shared<ev>(dfab, nvin, ncon, nmarca, ngreutate, nbat, nrang);
                stocare::add_masina(nev);
                break;
            case 2:
                cout << "Tank capacity\n";
                cin >> ncap;
                cout << "Engine displacement\n";
                cin >> neng;
                cout << "Horsepower\n";
                cin >> nbhp;
                nev = make_shared<termic>(dfab, nvin, ncon, nmarca, ngreutate, ncap, neng, nbhp);
                stocare::add_masina(nev);
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
                nev = make_shared<hibrid>(dfab, nvin, ncon, nmarca, ngreutate, ncap, neng, nbhp, nbat, nrang);
                stocare::add_masina(nev);
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
    stocare::del_ul_masina();
    mcon();
}

void meniu::delete_car(int index){
    try{
        stocare::del_id_masina(index);
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
    for(auto i : *stocare::vec_masini()){
        cout << (*i) << "\n";
    }
    mcon();
}

void meniu::see_cars(int index){
    try {
        cout << *stocare::arata_id_masina(index);
    }
    catch (const Exception1 &e){
        cout << e.what() << "\n";
    }
    mcon();
}

void meniu::calculations(int index){
    try{
        shared_ptr<vehicul> aux = stocare::arata_id_masina(index);
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