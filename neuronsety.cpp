#include "neuronsety.h"
#include "math.h"
#include <iostream>
#include <fstream>
#include <QMap>
#include <string>
#include <QMessageBox>
NeuronSety::NeuronSety()
{

}
void NeuronSety::zapuskator(){
//    /////////////////////////////////////////////////////////
//    Chtenie iz file obuchaushei viborki i nahojdenie max i min dlya normalizacii
//    /////////////////////////////////////////////////////////
    qsrand(time(0));
    std::ifstream file("test.txt");
    if(file.fail()){
        std::cout << "error file";
        return;
    }
    QVector<QVector<double> >x;
    min = 100, max = 0,
    minY1 = 100, maxY1 = 0,
    minY2 = 100, maxY2 = 0;
    for(int i = 0; i < this->kol_vh_d; ++i){
        QVector<double> b;
        x.push_back(b);
        for(int j = 0; j < (this->kol_vh + this->kol_neu); j++){
            double k;
            file >> k;
            if(j < 3){
                if(k < min) min = k;
                if(k > max) max = k;
            }
            if(j == 3){
                if(k < minY1) minY1 = k;
                if(k > maxY1) maxY1 = k;
            }
            if(j == 4){
                if(k < minY2) minY2 = k;
                if(k > maxY2) maxY2 = k;
            }
            b.push_back(k);
        }
        x[i] = b;
    }
    file.close();
//    /////////////////////////////////////////////////////////
//    /////////////////////////////////////////////////////////
//    Zapolnenie seti neuronami
    for (int i = 0; i < this->kol_neu; i++){
        Neuron neuron;
        if(this->flag2)
            neuron.setW(kol_vh, i, this->w[i], this->id_function); //Testirovanie neuronov
        else
            neuron.set(kol_vh, i, this->id_function); //Obuchenie neuronov
        neuron.set_A_B(this->a, this->b, this->b0, this->b1, this->speed, this->min, this->max,
                       this->minY1, this->maxY1, this->minY2, this->maxY2);
        neuron_seti.push_back(neuron);
    }
    std::ofstream file2("graph.txt", std::ios::app);
    if(!this->flag)
        file2 << neuron_seti[0].get_speed();
//    Obuchenie neuronov
    for (int i = 0; i < this->kol_ep; ++i){
        epsilon_set = 0;
        for (int k = 0; k < this->kol_vh_d; ++k){
            for(int j = 0; j < this->kol_neu; ++j){
                neuron_seti[j].set_X(x[k]);
                epsilon_set += pow(neuron_seti[j].get_eps() - neuron_seti[j].get_out(), 2);
                neuron_seti[j].w_corekt();
            }
//            //////////////////////////////////////////////////////////////////////////////////////
//            Denormalization out
//            std::cout << minY1 + (neuron_seti[0].get_out() + 1) *(maxY1 - minY1) / 2 << " ";
//            std::cout << minY2 + (neuron_seti[1].get_out() + 1) *(maxY2 - minY2) / 2 << std::endl;
//            //////////////////////////////////////////////////////////////////////////////////////
        }
        epsilon_set = pow(epsilon_set / this->kol_vh_d / this->kol_neu, 0.5);
        if(this->flag){
            file2 << neuron_seti[0].get_speed() << " " << epsilon_set << std::endl;
            for(int j = 0; j < this->kol_neu; ++j)
                neuron_seti[j].set_speed(neuron_seti[j].get_speed() - 1.0 / this->kol_ep);
        }
        if(epsilon_set < this->eps){
            if(!this->flag)
                file2 << " " << i + 1 << std::endl;
            std::cout << "ok " << i << std::endl;     
            return;
        }
    }
    if(!this->flag)
        file2 << " 0" <<std::endl;
    file2.close();
}


