//
// Created by gherc on 6/1/2023.
//
#ifndef OOP_MVEC_H
#define OOP_MVEC_H
#include "meniu.h"
#include "masini.h"
#include "stocare.h"
#include "exceptions.h"
#include <iostream>

class id_gen{
private:
    static int nid;
public:
    id_gen();
    static int get_id(){
        nid++;
        return nid;
    }
};

template<typename T>
class nod{
private:
    T val;
    nod* next;
public:
    T getVal() const;
    void setVal(T aval);
    nod *getNext() const;
    void setNext(nod<T> *anext);
};

template<typename T>
class mvect{
private:
    int id = id_gen::get_id();
    nod <T>* start, *end;
    bool startval = false;
    void inc();
    int alc_size = 0;
public:
    mvect(T x);
    mvect();
    mvect(mvect<T> &aux);
    void push(T x);
    T pop();
    T read_el(int poz);
    void del_el(int poz);
    void alc_space(int values);
    void set_val(int poz, T value);

    int getId() const;
    void setId(int id);

    nod<T> *getStart() const;
    void setStart(nod<T> *astart);

    nod<T> *getAnEnd() const;
    void setAnEnd(nod<T> *anEnd);

    bool isStartval() const;
    void setStartval(bool astartval);

    int getAlcSize() const;
    void setAlcSize(int aalcSize);

    friend ostream& operator<<(ostream &o, mvect<T> &aux);
};
#endif //OOP_MVEC_H
