#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "neuronsety.h"
#include <QMainWindow>
#include <QTextEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_action_triggered();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_comboBox_activated(int index);

    void on_comboBox_currentIndexChanged(int index);

private:
    int index;
    NeuronSety * a;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
