#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include <fstream>
#include <algorithm>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete a;
}

void MainWindow::on_pushButton_clicked()
{
    a = new NeuronSety (ui->lineEdit_5->text().toInt(), ui->lineEdit_7->text().toInt(), ui->lineEdit_8->text().toInt(), ui->checkBox->isChecked(), this->index);
    a->set_A_B_X(ui->lineEdit_9->text().toDouble(), ui->lineEdit_10->text().toDouble(), ui->lineEdit_11->text().toDouble()
            ,ui->lineEdit_3->text().toDouble(), ui->lineEdit_4->text().toDouble(), ui->lineEdit_6->text().toDouble(), ui->lineEdit_12->text().toDouble());
    a->zapuskator();
    ui->tableWidget->setColumnCount(ui->lineEdit_8->text().toInt()+1);
    ui->tableWidget->setRowCount(ui->lineEdit_7->text().toInt()+2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "w0" << "w1" << "w2" << "w3");
    for(int i = 0; i < ui->lineEdit_7->text().toInt(); ++i){
        QVector<double> w;
        w = a->get_w(i);
        for(int j = 0; j < w.size(); ++j){
            QTableWidgetItem * itm = new QTableWidgetItem(tr("%1").arg(w[j]));
            ui->tableWidget->setItem(i, j, itm);
        }
    }
    QTableWidgetItem * itm1 = new QTableWidgetItem(tr("%1").arg(a->get_Eps()));
    QTableWidgetItem * itm2 = new QTableWidgetItem(tr("%1").arg("Epsilon"));
    ui->tableWidget->setItem(ui->lineEdit_7->text().toInt(), 0, itm2);
    ui->tableWidget->setItem(ui->lineEdit_7->text().toInt(), ui->lineEdit_8->text().toInt(), itm1);
}

void MainWindow::on_action_triggered()
{
    QCustomPlot * graph = new QCustomPlot();
    std::ifstream file("graph.txt");
    if(file.fail()){
        std::cout << "Error";
        return;
    }
    QVector<double> speed;
    QVector<double> gener;
    while(!file.eof()){
        double a, b;
        file >> a >> b;
        speed.push_back(a);
        gener.push_back(b);
    }
    graph->legend->setVisible(true);
    graph->resize(800, 500);
    graph->clearGraphs();
    graph->addGraph();
    graph->xAxis->setLabel("Speed");
    graph->yAxis->setLabel("Generation");
    graph->xAxis->setRange(0, 1);
    double minY = gener[0], maxY = gener[0];
    for(int i = 0; i < gener.size(); ++i){
        minY = std::min(minY, gener[i]);
        maxY = std::max(maxY, gener[i]);
    }
    graph->yAxis->setRange(minY - 0.5, maxY + 0.5);
    graph->graph(0)->setData(speed, gener);
    graph->graph(0)->setName("Generation(speed)");
    graph->graph(0)->setPen(QColor(50,50,50,255));
    graph->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    std::ofstream file("w.txt");
    for(int i = 0; i < ui->lineEdit_7->text().toInt(); ++i){
        QVector<double> w;
        w = a->get_w(i);
        for(int j = 0; j < w.size(); ++j)
            file << w[j] << " ";
        file << std::endl;
    }
    file.close();
}

void MainWindow::on_pushButton_3_clicked()
{
    QVector<QVector<double> > w;
    std::ifstream file("w.txt");
    if(file.fail()){
        std::cout << "error file w.txt";
        return;
    }
    for(int i = 0; i < 2; ++i){
        QVector<double> a;
        for(int j = 0; j < 4; ++j){
            a.push_back(j);
            file >> a[j];
        }
        w.push_back(a);
    }
    file.close();
    a = new NeuronSety (ui->lineEdit_5->text().toInt(), ui->lineEdit_7->text().toInt(), ui->lineEdit_8->text().toInt(), w, true, this->index);
    a->set_A_B_X(ui->lineEdit_9->text().toDouble(), ui->lineEdit_10->text().toDouble(), ui->lineEdit_11->text().toDouble()
            ,ui->lineEdit_3->text().toDouble(), ui->lineEdit_4->text().toDouble(), ui->lineEdit_6->text().toDouble(), ui->lineEdit_12->text().toDouble());
    a->zapuskator();
    ui->tableWidget->setColumnCount(ui->lineEdit_8->text().toInt()+1);
    ui->tableWidget->setRowCount(ui->lineEdit_7->text().toInt()+2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "w0" << "w1" << "w2" << "w3");
    for(int i = 0; i < ui->lineEdit_7->text().toInt(); ++i){
        QVector<double> w;
        w = a->get_w(i);
        for(int j = 0; j < w.size(); ++j){
            QTableWidgetItem * itm = new QTableWidgetItem(tr("%1").arg(w[j]));
            ui->tableWidget->setItem(i, j, itm);
        }
    }
    QTableWidgetItem * itm1 = new QTableWidgetItem(tr("%1").arg(a->get_Eps()));
    QTableWidgetItem * itm2 = new QTableWidgetItem(tr("%1").arg("Epsilon"));
    ui->tableWidget->setItem(ui->lineEdit_7->text().toInt(), 0, itm2);
    ui->tableWidget->setItem(ui->lineEdit_7->text().toInt(), ui->lineEdit_8->text().toInt(), itm1);
}

void MainWindow::on_comboBox_activated(int index)
{
    this->index = index;
    if(index == 0){
        ui->label_4->setText(tr("a0"));
        ui->label_5->setText(tr("a1"));
        ui->label_4->show();
        ui->label_5->show();
        ui->lineEdit_3->setText(tr("-1"));
        ui->lineEdit_4->setText(tr("0.1"));
        ui->lineEdit_3->show();
        ui->lineEdit_4->show();
        ui->label_10->show();
        ui->lineEdit_9->show();
        ui->lineEdit_10->show();
    }
    if(index == 1){
        ui->label_4->setText(tr("Alpha"));
        ui->label_5->hide();
        ui->lineEdit_3->setText(tr("0.2"));
        ui->lineEdit_4->hide();
        ui->label_10->hide();
        ui->lineEdit_9->hide();
        ui->lineEdit_10->hide();
    }
    if(index == 2){
        ui->label_4->setText(tr("Alpha"));
        ui->label_5->hide();
        ui->lineEdit_3->setText(tr("0.2"));
        ui->lineEdit_4->hide();
        ui->label_10->hide();
        ui->lineEdit_9->hide();
        ui->lineEdit_10->hide();
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{

}
