#include "neuron.h"
#include "math.h"
#include <iostream>
Neuron::Neuron()
{

}
QVector<double> Neuron::get_w(){
    return w;
}
double Neuron::get_speed(){
    return speed;
}
void Neuron::set_speed(double speed){
    this->speed = speed;
}
double Neuron::get_out(){
    if(this->id_neuron == 0)
        return y1;
    else
        return y2;
}
double Neuron::get_eps(){
    if(this->id_neuron == 0)
        return x[3];
    else
        return x[4];
}
void Neuron::set(int kol_vh, int id_neuron, int id_function){
    this->id_neuron = id_neuron;
    for (int i = 0; i < kol_vh + 1; ++i)
        w.push_back((i + 1) / 7.5);
    this->kol_vh = kol_vh;
    this->id_function = id_function;
}
void Neuron::setW(int kol_vh, int id_neuron, QVector<double> w, int id_function){
    this->id_neuron = id_neuron;
    this->kol_vh = kol_vh;
    this->w = w;
    this->id_function = id_function;
}

void Neuron::norm_in(bool flag){
    if(flag){
        if(this->a == -1){
            for (int i = 0; i < x.size(); ++i){
                if(i < 3)
                    this->x[i] = 2 * ((this->x[i] - min) / (max - min)) - 1;
                if(i == 3)
                    this->x[i] = 2 * ((this->x[i] - minY1) / (maxY1 - minY1)) - 1;
                if(i == 4)
                    this->x[i] = 2 * ((this->x[i] - minY2) / (maxY2 - minY2)) - 1;
            }
        }
        if(this->a == 0){
            for (int i = 0; i < x.size(); ++i){
                if(i < 3)
                    this->x[i] = ((this->x[i] - min) / (max - min));
                if(i == 3)
                    this->x[i] = ((this->x[i] - minY1) / (maxY1 - minY1));
                if(i == 4)
                    this->x[i] = ((this->x[i] - minY2) / (maxY2 - minY2));
            }
        }
    }
    else{
        for (int i = 0; i < x.size(); ++i){
            if(i < 3)
                this->x[i] = 1 / (exp(-this->b0 * (this->x[i] - (max + min) / 2)) + 1);
            if(i == 3)
                this->x[i] = 1 / (exp(-this->b0 * (this->x[i] - (maxY1 + minY1) / 2)) + 1);
            if(i == 4)
                this->x[i] = 1 / (exp(-this->b0 * (this->x[i] - (maxY2 + minY2) / 2)) + 1);
        }
    }
}
void Neuron::set_A_B(double a, double b, double b0, double b1,
             double speed, double min, double max, double minY1,
             double maxY1, double minY2, double maxY2){
    this->a = a; this->b = b;
    this->b0 = b0; this->b1 = b1; this->speed = speed;
    this->min = min; this->max = max;
    this->minY1 = minY1; this->maxY1 = maxY1;
    this->minY2 = minY2; this->maxY2 = maxY2;
}
void Neuron::set_X(QVector<double> x){
    this->x = x;
    if(this->id_function == 0)
        norm_in(true);
    else
        norm_in(false);
    out();
}
void Neuron::aktivation_Function(){
    double T1 = -this->b0 / (this->b1), T2 = (1 - this->b0) / (this->b1);
    switch (id_function) {
    case 0:
        if(this->id_neuron == 0){
           if(this->energy <= T1)
               this->y1 = this->a;
           if(T1 < this->energy && T2 > this->energy)
               this->y1 = this->b1 * this->energy + this->b0;
           if(this->energy >= T2)
               this->y1 = this->b;
        }
        else{
            if(this->energy <= T1)
                this->y2 = this->a;
            if(T1 < this->energy && T2 > this->energy)
                this->y2 = this->b1 * this->energy + this->b0;
            if(this->energy >= T2)
                this->y2 = this->b;
        }
        break;
    case 1:
        if(this->id_neuron == 0)
            this->y1 = (exp(this->b0 * this->energy) - 1) / (exp(this->b0 * this->energy) + 1);
        else
            this->y2 = (exp(this->b0 * this->energy) - 1) / (exp(this->b0 * this->energy) + 1);
        break;
    case 2:
        if(this->id_neuron == 0)
            this->y1 = 1 / (exp(-this->b0 * this->energy) + 1);
        else
            this->y2 = 1 / (exp(-this->b0 * this->energy) + 1);
        break;
        break;
    default:
        break;
    }
}
void Neuron::out(){
   this->energy = 0;
   for (int i = 1; i < w.size(); ++i)
        this->energy += x[i - 1] * w[i];
   this->energy += w[0];
   aktivation_Function();
}
void Neuron::w_corekt(){
    for (int i = 0; i < w.size(); ++i){
        if(i == 0){
            w[i] = w[i] + this->speed * (get_eps() - get_out());
            continue;
        }
        w[i] = w[i] + this->speed * (get_eps() - get_out()) * x[i - 1];
    }
}

