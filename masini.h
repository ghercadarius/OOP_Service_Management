//
// Created by gherc on 4/22/2023.
//

#ifndef PR2_CLION_MASINI_H
#define PR2_CLION_MASINI_H

#include <string>
#include <iostream>
using namespace std;
class vehicul{
private:
    string data_fab;
    string vin;
    int consum; /// litri/100km sau w/100km
    string marca;
    int greutate;
    static int masini_rulate;
public:
    static int nr_masini_rulate();
    static void nr_masini_reset();
    static void nr_masini_add();
    vehicul(const string &d_fab, const string &n_vin,const int & n_consum, const string &n_marca, const int &ngreutate);
    vehicul();
    vehicul(const vehicul &a);
    virtual ~vehicul();
    void aux_del();
    int get_greutate() const;
    void set_greutate(const int ngreutate);
    string get_vin() const;
    void set_vin(const string &nvin);
    string get_data() const;
    void set_data(const string &ndata);
    int get_consum() const;
    void set_consum(const int nconsum);
    string get_marca() const;
    void set_marca(const string &nmarca);
    vehicul& operator =(const vehicul &aux);
    friend std::ostream& operator<<(ostream& os,const vehicul &a);
    virtual int calc_impozit() const = 0;
    virtual double calc_nota() const = 0;
};

class ev : public vehicul{
private:
    int cap_bat;
    int range;
    static int masini_ev_rulate;
public:
    static int nr_masini_ev_rulate();
    static void nr_masini_ev_reset();
    static void add_masini_ev();
    ev(const string &d_fab, const string &n_vin,const int & n_consum, const string &n_marca, const int &ngreutate, const int &nbat,
       const int &nrange);// : vehicul(d_fab, n_vin, n_consum, n_marca, ngreutate);
    ev();// : vehicul();
    ev(const ev &a);// : vehicul(a.get_data(), a.get_vin(), a.get_consum(), a.get_marca(), a.get_greutate());
    ~ev() override;
    void set_bat(const int nbat);
    int get_bat() const;
    void set_range(const int nrange);
    int get_range() const;
    ev& operator =(const ev &aux);
    friend std::ostream& operator<<(ostream& os,const ev& a);
    int calc_impozit() const override;
    double calc_nota() const override;
};

//int ev::masini_ev_rulate = 0;

class termic : public vehicul{
private:
    int rezervor; ///litri
    double motor;
    int putere;
    static int masini_termic_rulate;
public:
    static int nr_masini_termic();
    static void nr_masini_termic_reset();
    static void masini_termic_add();
    termic(const string &d_fab, const string &n_vin,const int & n_consum, const string &n_marca, const int &ngreutate, const int &nrezervor,
           const double &nmotor, const int &nputere);// : vehicul(d_fab, n_vin, n_consum, n_marca, ngreutate)
    termic ();// : vehicul()
    termic (const termic &aux);// : vehicul(aux.get_data(), aux.get_vin(), aux.get_consum(), aux.get_marca(), aux.get_greutate())
    virtual ~termic() override;
    void set_rezervor(const int nrezervor);
    int get_rezervor() const;
    void set_motor(const int nmotor);
    double get_motor() const;
    void set_putere(const int nputere);
    int get_putere() const;
    termic& operator =(const termic &aux);
    friend std::ostream& operator<<(ostream& os,const termic& a);
    int calc_impozit() const override;
    double calc_nota() const override;
};

//int termic::masini_termic_rulate = 0;

class hibrid : public vehicul{
private:
    int rezervor; ///litri
    double motor;
    int putere;
    int cap_bat;
    int range;
    static int masini_hibrid_rulate;
public:
    static int nr_masini_hibrid();
    static void reset_nr_masini_hibrid();
    static void nr_masini_hibrid_add();
    hibrid (const string &d_fab, const string &n_vin,const int & n_consum, const string &n_marca, const int &ngreutate, const int &nrezervor,
            const double &nmotor, const int &nputere, const int &nbat, const int &nrange);// : vehicul(d_fab, n_vin, n_consum, n_marca, ngreutate)
    hibrid ();// : vehicul()
    hibrid (const hibrid &aux);// : vehicul(aux.get_data(), aux.get_vin(), aux.get_consum(), aux.get_marca(), aux.get_greutate())
    ~hibrid() override;
    void set_rezervor(const int nrezervor);
    int get_rezervor() const;
    void set_motor(const int nmotor);
    double get_motor() const;
    void set_putere(const int nputere);
    int get_putere() const;
    void set_bat(const int nbat);
    int get_bat() const;
    void set_range(const int nrange);
    int get_range() const;
    hibrid& operator =(const hibrid &aux);
    friend std::ostream& operator<<(ostream& os,const hibrid& a);
    int calc_impozit() const override;
    double calc_nota() const override;
};

//int hibrid::masini_hibrid_rulate = 0;


#endif //PR2_CLION_MASINI_H
