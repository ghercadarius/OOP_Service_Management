//
// Created by gherc on 4/22/2023.
//
#include "masini.h"
#include "exceptions.h"
#include <string>
#include <iostream>
using namespace std;

int vehicul::nr_masini_rulate(){
    return masini_rulate;
}
void vehicul::nr_masini_reset(){
    masini_rulate = 0;
}
void vehicul::nr_masini_add(){
    masini_rulate++;
}
vehicul::vehicul(const string &d_fab, const string &n_vin,const int & n_consum, const string &n_marca, const int &ngreutate){
    set_data(d_fab);
    set_vin(n_vin);
    set_consum(n_consum);
    set_marca(n_marca);
    set_greutate(ngreutate);
    nr_masini_add();
}
vehicul::vehicul(){
    set_data("undefined");
    set_vin("undefined");
    set_consum(0);
    set_marca("undefined");
    set_greutate(0);
    nr_masini_add();
}
vehicul::vehicul(const vehicul &a){
    set_data(a.data_fab);
    set_vin(a.vin);
    set_marca(a.marca);
    set_consum(a.consum);
    set_greutate(a.greutate);
    nr_masini_add();
}
vehicul::~vehicul(){
    /*delete &data_fab;
    delete &vin;
    delete &marca;
    delete &consum;
    delete &greutate;*/
}
void vehicul::aux_del(){
    /*delete &data_fab;
    delete &vin;
    delete &marca;
    delete &consum;
    delete &greutate;*/
}
int vehicul::get_greutate() const{
    return greutate;
}
void vehicul::set_greutate(const int ngreutate){
    greutate = ngreutate;
}
string vehicul::get_vin() const{
    return vin;
}
void vehicul::set_vin(const string &nvin){
    vin = nvin;
}
string vehicul::get_data() const{
    return data_fab;
}
void vehicul::set_data(const string &ndata){
    data_fab = ndata;
}
int vehicul::get_consum() const{
    return consum;
}
void vehicul::set_consum(const int nconsum){
    consum = nconsum;
}
string vehicul::get_marca() const{
    return marca;
}
void vehicul::set_marca(const string &nmarca){
    marca = nmarca;
}
vehicul& vehicul::operator =(const vehicul &aux){
    this -> set_vin(aux.get_vin());
    this -> set_marca(aux.get_marca());
    this -> set_consum(aux.get_consum());
    this -> set_data(aux.get_data());
    this -> set_greutate(aux.get_greutate());
    return *this;
}
std::ostream& operator<<(ostream& os, const vehicul &a){
    os << "Vin: " << a.get_vin() << "\n" << "Marca: " << a.get_marca() << "\n" << "Consum: " << a.get_consum() << "\n" << "Data Fabricatie: " << a.get_data() << "\n" << "Greutate: " << a.get_greutate() << "\n";
    return os;
}

int ev::nr_masini_ev_rulate(){
    return masini_ev_rulate;
}
void ev::nr_masini_ev_reset(){
    masini_ev_rulate = 0;
}
void ev::add_masini_ev(){
    masini_ev_rulate++;
}
ev::ev(const string &d_fab, const string &n_vin,const int & n_consum, const string &n_marca, const int &ngreutate, const int &nbat,
       const int &nrange) : vehicul(d_fab, n_vin,
                                    n_consum, n_marca, ngreutate){
    set_bat(nbat);
    set_range(nrange);
    add_masini_ev();
}
ev::ev() : vehicul(){
    set_bat(0);
    set_range(0);
    add_masini_ev();
}
ev::ev(const ev &a) : vehicul(a.get_data(), a.get_vin(), a.get_consum(), a.get_marca(), a.get_greutate()){
    set_bat(a.get_bat());
    set_range(a.get_range());
    add_masini_ev();
}
ev::~ev(){
    /*delete &data_fab;
    delete &vin;
    delete &marca;
    delete &consum;
    delete &greutate;
    delete &cap_bat;
    delete &range;*/
}
void ev::set_bat(const int nbat){
    cap_bat = nbat;
}
int ev::get_bat() const{
    return cap_bat;
}
void ev::set_range(const int nrange){
    range = nrange;
}
int ev::get_range() const{
    return range;
}
ev& ev::operator =(const ev &aux){
    this -> set_range(aux.get_range());
    this -> set_bat(aux.get_bat());
    this -> set_vin(aux.get_vin());
    this -> set_consum(aux.get_consum());
    this -> set_greutate(aux.get_greutate());
    this -> set_data(aux.get_data());
    this -> set_marca(aux.get_marca());
    return *this;
}
std::ostream& operator<<(ostream& os,const ev& a){
    os << "Range: " << a.get_range() << "\n" << "Baterie: " << a.get_bat() << "\n" << "Vin: " << a.get_vin() << "\n" << "Marca: " << a.get_marca() << "\n" << "Consum: " << a.get_consum() << "\n" << "Data Fabricatie: " << a.get_data() << "\n" << "Greutate: " << a.get_greutate() << "\n";
    return os;
}
int ev::calc_impozit() const {
    return 0;
}
double ev::calc_nota() const{
    if(cap_bat == 0 || range == 0)
        throw Exception2();
    return (double)((int)((cap_bat / 68) * (range / 348) * 100)) / 10;
}

int termic::nr_masini_termic(){
    return masini_termic_rulate;
}
void termic::nr_masini_termic_reset(){
    masini_termic_rulate = 0;
}
void termic::masini_termic_add(){
    masini_termic_rulate++;
}
termic::termic(const string &d_fab, const string &n_vin,const int & n_consum, const string &n_marca, const int &ngreutate, const int &nrezervor,
               const double &nmotor, const int &nputere) : vehicul(d_fab, n_vin, n_consum, n_marca, ngreutate){
    set_rezervor(nrezervor);
    set_motor(nmotor);
    set_putere(nputere);
    masini_termic_add();
}
termic::termic () : vehicul(){
    set_rezervor(0);
    set_motor(0);
    set_putere(0);
    masini_termic_add();
}
termic::termic (const termic &aux) : vehicul(aux.get_data(), aux.get_vin(), aux.get_consum(), aux.get_marca(), aux.get_greutate()){
    rezervor = aux.get_rezervor();
    motor = aux.get_motor();
    putere = aux.get_putere();
}
termic::~termic(){
    /*aux_del();
    delete &rezervor;
    delete &motor;
    delete &putere;*/
}
void termic::set_rezervor(const int nrezervor){
    rezervor = nrezervor;
}
int termic::get_rezervor() const{
    return rezervor;
}
void termic::set_motor(const int nmotor){
    motor = nmotor;
}
double termic::get_motor() const{
    return motor;
}
void termic::set_putere(const int nputere){
    putere = nputere;
}
int termic::get_putere() const{
    return putere;
}
termic& termic::operator =(const termic &aux){
    this -> set_vin(aux.get_vin());
    this -> set_consum(aux.get_consum());
    this -> set_greutate(aux.get_greutate());
    this -> set_data(aux.get_data());
    this -> set_marca(aux.get_marca());
    this -> set_rezervor(aux.get_rezervor());
    this -> set_motor(aux.get_motor());
    this -> set_putere(aux.get_putere());
    return *this;
}
std::ostream& operator<<(ostream& os,const termic& a){
    os << "Rezervor: " << a.get_rezervor() << "\n" << "Motor: " << a.get_motor() << "\n" << "Putere: " << a.get_putere() << "\n" << "Vin: " << a.get_vin() << "\n"
       << "Marca: " << a.get_marca() << "\n" << "Consum: " << a.get_consum() << "\n" << "Data Fabricatie: " << a.get_data() << "\n" << "Greutate: " << a.get_greutate() << "\n";
    return os;
}
int termic::calc_impozit() const{
    if(motor == 0)
        throw Exception2();
    return (motor / 200) * 22;
}
double termic::calc_nota() const{
    if(motor == 0 || putere == 0)
        throw Exception2();
    return (double)((int)((motor / 1500) * (putere / 131) * 100)) / 10;
}

int hibrid::nr_masini_hibrid(){
    return masini_hibrid_rulate;
}
void hibrid::reset_nr_masini_hibrid(){
    masini_hibrid_rulate = 0;
}
void hibrid::nr_masini_hibrid_add(){
    masini_hibrid_rulate++;
}
hibrid::hibrid (const string &d_fab, const string &n_vin,const int & n_consum, const string &n_marca, const int &ngreutate, const int &nrezervor,
                const double &nmotor, const int &nputere, const int &nbat, const int &nrange) : vehicul(d_fab, n_vin, n_consum, n_marca, ngreutate){
    set_rezervor(nrezervor);
    set_motor(nmotor);
    set_putere(nputere);
    set_bat(nbat);
    set_range(nrange);
    nr_masini_hibrid_add();
}
hibrid::hibrid () : vehicul(){
    set_rezervor(0);
    set_motor(0);
    set_putere(0);
    set_bat(0);
    set_range(0);
    nr_masini_hibrid_add();
}
hibrid::hibrid (const hibrid &aux) : vehicul(aux.get_data(), aux.get_vin(), aux.get_consum(), aux.get_marca(), aux.get_greutate()){
    rezervor = aux.get_rezervor();
    motor = aux.get_motor();
    putere = aux.get_putere();
    cap_bat = aux.get_bat();
    range = aux.get_range();
    nr_masini_hibrid_add();
}
hibrid::~hibrid(){
    /*aux_del();
    delete &rezervor;
    delete &motor;
    delete &putere;
    delete &cap_bat;
    delete &range;*/
}
void hibrid::set_rezervor(const int nrezervor){
    rezervor = nrezervor;
}
int hibrid::get_rezervor() const{
    return rezervor;
}
void hibrid::set_motor(const int nmotor){
    motor = nmotor;
}
double hibrid::get_motor() const{
    return motor;
}
void hibrid::set_putere(const int nputere){
    putere = nputere;
}
int hibrid::get_putere() const{
    return putere;
}
void hibrid::set_bat(const int nbat){
    cap_bat = nbat;
}
int hibrid::get_bat() const{
    return cap_bat;
}
void hibrid::set_range(const int nrange){
    range = nrange;
}
int hibrid::get_range() const{
    return range;
}
hibrid& hibrid::operator =(const hibrid &aux){
    this -> set_vin(aux.get_vin());
    this -> set_consum(aux.get_consum());
    this -> set_greutate(aux.get_greutate());
    this -> set_data(aux.get_data());
    this -> set_marca(aux.get_marca());
    this -> set_rezervor(aux.get_rezervor());
    this -> set_motor(aux.get_motor());
    this -> set_putere(aux.get_putere());
    this -> set_range(aux.get_range());
    this -> set_bat(aux.get_bat());
    return *this;
}
std::ostream& operator<<(ostream& os,const hibrid& a){
    os << "Range: " << a.get_range() << "\n" << "Baterie: " << a.get_bat() << "\n" << "Rezervor: " << a.get_rezervor() << "\n" << "Motor: " << a.get_motor() << "\n" << "Putere: " << a.get_putere() << "\n" << "Vin: " << a.get_vin() << "\n"
       << "Marca: " << a.get_marca() << "\n" << "Consum: " << a.get_consum() << "\n" << "Data Fabricatie: " << a.get_data() << "\n" << "Greutate: " << a.get_greutate() << "\n";
    return os;
}
int hibrid::calc_impozit() const{
    if(motor == 0)
        throw Exception2();
    return ((motor / 200) * 22) / 2;
}
double hibrid::calc_nota() const{
    if(motor == 0 || putere == 0 || cap_bat == 0 || range == 0)
        throw Exception2();
    return (double)((int)((motor / 1500) * (putere / 131) * (cap_bat / 68) * (range / 348) * 100)) / 10;
}