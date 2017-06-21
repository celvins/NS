#ifndef NEURONSETY_H
#define NEURONSETY_H
#include "neuron.h"
#include "math.h"
#include <QVector>
class NeuronSety
{
private:
    int kol_ep, kol_neu, kol_vh, kol_vh_d, id_function;
    double eps, a, b, b0, b1, epsilon_set, speed, min, max, minY1, maxY1, minY2, maxY2;
    QVector<Neuron> neuron_seti;
    QVector<QVector<double> >w;
    bool flag, flag2;
public:
    NeuronSety();
    NeuronSety(int kol_ep, int kol_neu, int kol_vh, bool flag, int id_function){this->kol_ep = kol_ep;
                                                               this->kol_vh = kol_vh;
                                                               this->kol_neu = kol_neu;
                                                               this->flag = flag;
                                                               this->flag2 = false;
                                                               this->id_function = id_function;}
    NeuronSety(int kol_ep, int kol_neu, int kol_vh, QVector<QVector<double> >w, bool flag2, int id_function){this->kol_ep = kol_ep;
                                                               this->kol_vh = kol_vh;
                                                               this->kol_neu = kol_neu;
                                                               this->w = w;
                                                               this->flag2 = flag2;
                                                               this->flag = false;
                                                               this->id_function = id_function;}
    void set_A_B_X(double a, double b, double kol_vh_d, double b0, double b1, double eps, double speed){
                                                                this->a = a; this->b = b;
                                                                this->kol_vh_d = kol_vh_d;
                                                                this->b0 = b0;
                                                                this->b1 = b1;
                                                                this->eps = eps;
                                                                this->speed = speed;}
    double get_eps(int i){return neuron_seti[i].get_eps() - neuron_seti[i].get_out();}
    double get_Eps(){return this->epsilon_set;}
    QVector<double> get_w(int i){return neuron_seti[i].get_w();}
    void zapuskator();
};

#endif // NEURONSETY_H
