/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QWidget *centralWidget;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QLabel *label_11;
    QLineEdit *lineEdit_11;
    QTableWidget *tableWidget;
    QLabel *label_12;
    QLineEdit *lineEdit_12;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QCheckBox *checkBox;
    QMenuBar *menuBar;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(870, 307);
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 131, 16));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(170, 10, 161, 22));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 50, 47, 13));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 80, 47, 13));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 220, 75, 23));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(210, 40, 91, 20));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(210, 70, 71, 16));
        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(60, 50, 113, 20));
        lineEdit_4 = new QLineEdit(centralWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(60, 80, 113, 20));
        lineEdit_5 = new QLineEdit(centralWidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(300, 40, 113, 20));
        lineEdit_6 = new QLineEdit(centralWidget);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(300, 70, 113, 20));
        lineEdit_7 = new QLineEdit(centralWidget);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(300, 100, 113, 20));
        lineEdit_8 = new QLineEdit(centralWidget);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(300, 130, 113, 20));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(210, 100, 71, 16));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(210, 130, 71, 16));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(30, 120, 151, 16));
        lineEdit_9 = new QLineEdit(centralWidget);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(70, 140, 31, 20));
        lineEdit_10 = new QLineEdit(centralWidget);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(110, 140, 31, 20));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(220, 170, 151, 16));
        lineEdit_11 = new QLineEdit(centralWidget);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        lineEdit_11->setGeometry(QRect(260, 190, 31, 20));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(430, 10, 431, 181));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(40, 170, 151, 16));
        lineEdit_12 = new QLineEdit(centralWidget);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));
        lineEdit_12->setGeometry(QRect(40, 190, 31, 20));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(430, 200, 75, 23));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(520, 200, 75, 23));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(230, 220, 81, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 870, 21));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_2->menuAction());
        menu_2->addAction(action);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        action->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\263\321\200\320\265\321\210\320\275\320\276\321\201\321\202\321\214 \320\276\321\202 \320\272\320\276\320\273-\320\262\320\260 \321\215\320\277\320\276\321\205", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Activation function", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\320\233\320\270\320\275\320\265\320\271\320\275\320\276 \320\277\320\276\321\200\320\276\320\263\320\276\320\262\320\260\321\217", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\320\223\320\270\320\277\320\265\321\200\320\261\320\276\320\273\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \321\202\320\260\320\275\320\263\320\265\320\275\321\201", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\320\241\320\270\320\263\320\274\320\276\320\270\320\264\320\275\320\260\321\217 \320\273\320\276\320\263\320\270\321\201\321\202\320\270\321\207\320\265\321\201\320\272\320\260\321\217", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("MainWindow", "b0", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "b1", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Count generation", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Epsilon", Q_NULLPTR));
        lineEdit_3->setText(QApplication::translate("MainWindow", "-1", Q_NULLPTR));
        lineEdit_4->setText(QApplication::translate("MainWindow", "0.1", Q_NULLPTR));
        lineEdit_5->setText(QApplication::translate("MainWindow", "100", Q_NULLPTR));
        lineEdit_6->setText(QApplication::translate("MainWindow", "0.08", Q_NULLPTR));
        lineEdit_7->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        lineEdit_8->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Neuron count", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "In count", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "The limits of the output signal", Q_NULLPTR));
        lineEdit_9->setText(QApplication::translate("MainWindow", "-1", Q_NULLPTR));
        lineEdit_10->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "The number of input data", Q_NULLPTR));
        lineEdit_11->setText(QApplication::translate("MainWindow", "17", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Speed", Q_NULLPTR));
        lineEdit_12->setText(QApplication::translate("MainWindow", "0.1", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Test", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainWindow", "linear speed", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\320\272\320\270", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
