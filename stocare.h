//
// Created by gherc on 4/22/2023.
//

#ifndef PR2_CLION_STOCARE_H
#define PR2_CLION_STOCARE_H

#include <vector>
#include <memory>
#include "masini.h"
#include "exceptions.h"

using namespace std;

class stocare{
private:
    static vector <shared_ptr<vehicul>> masini;
public:
    static void add_masina(shared_ptr<vehicul> aux);
    static vector <shared_ptr<vehicul>>* vec_masini();
    static void del_ul_masina();
    static bool del_id_masina(int index);
    static shared_ptr<vehicul> arata_id_masina(int index);
};

#endif //PR2_CLION_STOCARE_H

