//
// Created by gherc on 4/22/2023.
//

#include "stocare.h"
#include "masini.h"
#include "exceptions.h"

#include <vector>
#include <memory>
#include <iostream>

vector <shared_ptr<vehicul>> stocare::masini;// = new vector<shared_ptr<vehicul>>;

void stocare::add_masina( shared_ptr<vehicul> aux){
    cout<<"@";
    masini.push_back(aux);
}

vector <shared_ptr<vehicul>>* stocare::vec_masini(){
    return &masini;
}

void stocare::del_ul_masina(){
    masini.pop_back();
}

bool stocare::del_id_masina(int index){
    ///EXCEPTIE daca index > masini.size()
    if(index > masini.size())
        throw Exception1();
    masini.erase(masini.begin() + index);

}

shared_ptr<vehicul> stocare::arata_id_masina(int index){
    ///EXCEPTIE DACA INDEX > masini.size()
    if(index > masini.size())
        throw Exception1();
    return masini[index];
}