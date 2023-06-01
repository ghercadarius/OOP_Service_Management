#include "mvec.h"

template<typename T>
T nod<T>::getVal() const {
    return val;
}

template<typename T>
void nod<T>::setVal(T aval) {
    val = aval;
}

template<typename T>
nod<T> *nod<T>::getNext() const {
    return next;
}

template<typename T>
void nod<T>::setNext(nod<T> *anext) {
    next = anext;
}

template<typename T>
void mvect<T>::inc() {
    start = new nod <T>;
    start->setNext(nullptr);
    end = start;
}

template<typename T>
mvect<T>::mvect(T x) {
    inc();
    push(x);
}

template<typename T>
mvect<T>::mvect() {
    inc();
}

template<typename T>
mvect<T>::mvect(mvect<T> &aux) {
    nod<T> *astart = aux.getStart();
    while (astart != nullptr) {
        push(astart->getVal());
    }
}

template<typename T>
void mvect<T>::push(T x) {
    nod <T> *aux = new nod<T>;
    aux->setVal(x);
    aux->setNext(nullptr);
    if (end == start) {
        if (!startval) {
            start->setVal(x);
            startval = true;
        } else {
            end->setNext(aux);
            end = aux;
        }
    }
    alc_size++;
}

template<typename T>
T mvect<T>::pop() {
    nod<T> *aux = start;
    if (start == end) {
        if (startval) {
            T rez = start->val;
            startval = false;
            alc_size--;
            return rez;
        } else {
            cout << "Nu sunt elemente\n";
            return;
        }
    }
    while (aux->next != end) {
        aux = aux->next;
    }
    T rez = end->val;
    delete end;
    end = aux;
    alc_size--;
    return rez;
}

template<typename T>
T mvect<T>::read_el(int poz) {
    if (poz >= alc_size) {
        throw Exception1();
        return;
    } else {
        nod<T> *aux = start;
        for (int i = 0; i < poz; i++) {
            aux = aux->next;
        }
        return aux->val;
    }
}

template<typename T>
void mvect<T>::del_el(int poz) {
    if (poz >= alc_size) {
        throw Exception1();
        return;
    } else {
        nod <T> *aux = start;
        nod <T> *ant;
        for (int i = 0; i < poz; i++) {
            ant = aux;
            aux = aux->next;
        }
        ant->next = aux->next;
        delete aux;
    }
}

template<typename T>
void mvect<T>::alc_space(int values) {
    if (alc_size > values)
        return;
    int i;
    if (alc_size == 0) {
        i = 0;
    } else {
        i = alc_size - 1;
    }
    for (i; i <= values; i++) {
        nod<T> *aux = new nod<T>;
        aux->next = nullptr;
        end->next = aux;
        end = aux;
    }
}

template<typename T>
void mvect<T>::set_val(int poz, T value){
    if (poz >= alc_size) {
        alc_space(poz);
    }
    nod<T> *aux = start;
    for (int i = 0; i <= poz; i++) {
        aux = aux->next;
    }
    aux->val = value;
}

template<typename T>
int mvect<T>::getId() const {
    return id;
}

template<typename T>
void mvect<T>::setId(int aid) {
    id = aid;
}

template<typename T>
nod<T> *mvect<T>::getStart() const {
    return start;
}

template<typename T>
void mvect<T>::setStart(nod<T> *astart) {
    start = astart;
}

template<typename T>
nod<T> *mvect<T>::getAnEnd() const {
    return end;
}

template<typename T>
void mvect<T>::setAnEnd(nod<T> *anEnd) {
    end = anEnd;
}

template<typename T>
bool mvect<T>::isStartval() const {
    return startval;
}

template<typename T>
void mvect<T>::setStartval(bool astartval) {
    startval = astartval;
}

template<typename T>
int mvect<T>::getAlcSize() const {
    return alc_size;
}

template<typename T>
void mvect<T>::setAlcSize(int aalcSize) {
    alc_size = aalcSize;
}

template<typename T>
ostream& operator<<(ostream &o, mvect<T> &aux) {
    nod<T> *sstart = aux -> getStart();
    while(sstart){
        o << sstart -> getVal() << "\n";
        sstart = sstart -> getNext();
    }
    return o;
}
