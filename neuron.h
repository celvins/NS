#ifndef NEURON_H
#define NEURON_H
#include <QVector>
#include <iostream>
#include "time.h"
class Neuron
{
private:
    QVector<double>  w;
    QVector<double>  x;
    double energy, speed;
    double y1, y2, a, b,
           b0, b1, min, max,
           minY1, maxY1, minY2, maxY2;
    int kol_vh;
    int id_neuron, id_function;
public:
    Neuron();
    void set(int, int, int);
    void setW(int, int, QVector<double>, int);
    void norm_in(bool);//Normalizaciya vhodnih dannih
    void out(); //Raschet Y
    void aktivation_Function();
    void set_X(QVector<double>);
    void w_corekt();
    void set_A_B(double, double, double, double,
                 double, double, double, double,
                 double, double, double);
    double get_out();
    double get_eps();
    QVector<double> get_w();
    double get_speed();
    void set_speed(double);
};

#endif // NEURON_H
