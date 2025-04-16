/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *widget_2;
    QLineEdit *id;
    QLineEdit *first_name;
    QPushButton *ajouter;
    QPushButton *modifier;
    QPushButton *supprimer;
    QPushButton *chercher;
    QPushButton *tri;
    QTableView *tableView;
    QPushButton *statistique;
    QPushButton *pdf;
    QLabel *label_15;
    QPushButton *history;
    QComboBox *ordre;
    QComboBox *critere;
    QTextEdit *historique;
    QPushButton *clear_history;
    QLineEdit *last_name;
    QLineEdit *job_id;
    QLineEdit *salary;
    QLabel *date;
    QDateEdit *hire_date;
    QPushButton *clear_history_2;
    QLineEdit *email;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1536, 938);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 201, 1081));
        widget->setStyleSheet(QString::fromUtf8("background-color: #b68a4d;\n"
"border: none;"));
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 150, 201, 61));
        label_2->setTabletTracking(false);
        label_2->setStyleSheet(QString::fromUtf8("color: White;\n"
"background-color: #f6a961;\n"
"border: 2px solid black;\n"
"font-size: 16px;\n"
"\n"
"\n"
""));
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 210, 201, 61));
        label_3->setStyleSheet(QString::fromUtf8("color: White;\n"
"border-top: 2px solid black;\n"
"font-size: 16px;\n"
"\n"
"\n"
""));
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 270, 201, 61));
        label_4->setStyleSheet(QString::fromUtf8("color: White;\n"
"border-top: 2px solid black;\n"
"font-size: 16px;\n"
""));
        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 330, 201, 61));
        label_5->setStyleSheet(QString::fromUtf8("color: White;\n"
"border-top: 2px solid black;\n"
"font-size: 16px;\n"
""));
        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, 390, 201, 61));
        label_6->setStyleSheet(QString::fromUtf8("color: White;\n"
"border-top: 2px solid black;\n"
"font-size: 16px;\n"
"\n"
""));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(200, 0, 1491, 951));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: #f6a961;\n"
"border: none;\n"
"QLineEdit::placeholderText {\n"
"    font-style: bold; /* Optional: Makes the text italic */\n"
"    font-size: 14px; /* Optional: Adjust font size */\n"
"}\n"
""));
        id = new QLineEdit(widget_2);
        id->setObjectName("id");
        id->setGeometry(QRect(10, 90, 231, 31));
        id->setStyleSheet(QString::fromUtf8("background-color: #bd842d;\n"
"border: 1px solid #5E9387;\n"
"border-radius: 4px;\n"
"padding: 6px;\n"
"    font-style: bold;\n"
"    font-size: 14px\n"
"\n"
""));
        first_name = new QLineEdit(widget_2);
        first_name->setObjectName("first_name");
        first_name->setGeometry(QRect(10, 130, 231, 31));
        first_name->setStyleSheet(QString::fromUtf8("background-color: #bd842d;\n"
"border: 1px solid #5E9387;\n"
"border-radius: 4px;\n"
"padding: 6px;\n"
""));
        ajouter = new QPushButton(widget_2);
        ajouter->setObjectName("ajouter");
        ajouter->setGeometry(QRect(10, 410, 111, 41));
        ajouter->setStyleSheet(QString::fromUtf8("background-color: #b68a4d;\n"
"border: none;\n"
"color: white;\n"
"border-radius: 5px;\n"
"padding: 8px 12px;\n"
"font-size: 18px;\n"
"font: bold;\n"
"\n"
"\n"
""));
        modifier = new QPushButton(widget_2);
        modifier->setObjectName("modifier");
        modifier->setGeometry(QRect(140, 410, 111, 41));
        modifier->setStyleSheet(QString::fromUtf8("background-color: #b68a4d;\n"
"border: none;\n"
"color: white;\n"
"border-radius: 5px;\n"
"padding: 8px 12px;\n"
"font-size: 18px;\n"
"font: bold;\n"
"\n"
"\n"
""));
        supprimer = new QPushButton(widget_2);
        supprimer->setObjectName("supprimer");
        supprimer->setGeometry(QRect(140, 470, 111, 41));
        supprimer->setStyleSheet(QString::fromUtf8("background-color: #b68a4d;\n"
"border: none;\n"
"color: white;\n"
"border-radius: 5px;\n"
"padding: 8px 12px;\n"
"font-size: 18px;\n"
"font: bold;\n"
"\n"
"\n"
""));
        chercher = new QPushButton(widget_2);
        chercher->setObjectName("chercher");
        chercher->setGeometry(QRect(10, 470, 111, 41));
        chercher->setStyleSheet(QString::fromUtf8("background-color: #b68a4d;\n"
"border: none;\n"
"color: white;\n"
"border-radius: 5px;\n"
"padding: 8px 12px;\n"
"font-size: 18px;\n"
"font: bold;\n"
"\n"
"\n"
""));
        tri = new QPushButton(widget_2);
        tri->setObjectName("tri");
        tri->setGeometry(QRect(950, 60, 151, 31));
        tri->setStyleSheet(QString::fromUtf8("background-color: #b68a4d;\n"
"border: none;\n"
"color: white;\n"
"border-radius: 5px;\n"
"padding: 8px 12px;\n"
"font-size: 18px;\n"
"font: bold;\n"
"\n"
"\n"
""));
        tableView = new QTableView(widget_2);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(390, 140, 801, 401));
        tableView->setStyleSheet(QString::fromUtf8("border: 1px solid #5E9387;\n"
"QHeaderView::section { height: 50px; }"));
        statistique = new QPushButton(widget_2);
        statistique->setObjectName("statistique");
        statistique->setGeometry(QRect(390, 560, 251, 41));
        statistique->setStyleSheet(QString::fromUtf8("background-color: #b68a4d;\n"
"border: none;\n"
"color: white;\n"
"border-radius: 5px;\n"
"padding: 8px 12px;\n"
"font-size: 18px;\n"
"font: bold;\n"
"\n"
"\n"
""));
        pdf = new QPushButton(widget_2);
        pdf->setObjectName("pdf");
        pdf->setGeometry(QRect(660, 560, 251, 41));
        pdf->setStyleSheet(QString::fromUtf8("background-color: #b68a4d;\n"
"border: none;\n"
"color: white;\n"
"border-radius: 5px;\n"
"padding: 8px 12px;\n"
"font-size: 18px;\n"
"font: bold;\n"
"\n"
"\n"
""));
        label_15 = new QLabel(widget_2);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(10, 10, 231, 51));
        label_15->setStyleSheet(QString::fromUtf8("color: white;\n"
""));
        history = new QPushButton(widget_2);
        history->setObjectName("history");
        history->setGeometry(QRect(920, 560, 271, 41));
        history->setStyleSheet(QString::fromUtf8("background-color: #b68a4d;\n"
"border: none;\n"
"color: white;\n"
"border-radius: 5px;\n"
"padding: 8px 12px;\n"
"font-size: 18px;\n"
"font: bold;\n"
"\n"
"\n"
""));
        ordre = new QComboBox(widget_2);
        ordre->addItem(QString());
        ordre->addItem(QString());
        ordre->addItem(QString());
        ordre->setObjectName("ordre");
        ordre->setGeometry(QRect(690, 60, 221, 31));
        ordre->setStyleSheet(QString::fromUtf8("color: black;\n"
"background-color: #bd842d;\n"
"border: 1px solid #5E9387;\n"
"border-radius: 4px;\n"
"padding: 6px;"));
        critere = new QComboBox(widget_2);
        critere->addItem(QString());
        critere->addItem(QString());
        critere->addItem(QString());
        critere->addItem(QString());
        critere->addItem(QString());
        critere->addItem(QString());
        critere->addItem(QString());
        critere->setObjectName("critere");
        critere->setGeometry(QRect(450, 60, 221, 28));
        critere->setStyleSheet(QString::fromUtf8("color: black;\n"
"background-color: #bd842d;\n"
"border: 1px solid #5E9387;\n"
"border-radius: 4px;\n"
"padding: 6px;"));
        historique = new QTextEdit(widget_2);
        historique->setObjectName("historique");
        historique->setGeometry(QRect(390, 660, 811, 151));
        historique->setStyleSheet(QString::fromUtf8("color: black;\n"
"background-color: #bd842d;\n"
"border: 1px solid #5E9387;\n"
"border-radius: 4px;\n"
"padding: 6px;"));
        clear_history = new QPushButton(widget_2);
        clear_history->setObjectName("clear_history");
        clear_history->setGeometry(QRect(800, 610, 271, 41));
        clear_history->setStyleSheet(QString::fromUtf8("background-color: #b68a4d;\n"
"border: none;\n"
"color: white;\n"
"border-radius: 5px;\n"
"padding: 8px 12px;\n"
"font-size: 18px;\n"
"font: bold;\n"
"\n"
"\n"
""));
        last_name = new QLineEdit(widget_2);
        last_name->setObjectName("last_name");
        last_name->setGeometry(QRect(10, 170, 231, 31));
        last_name->setStyleSheet(QString::fromUtf8("background-color: #bd842d;\n"
"border: 1px solid #5E9387;\n"
"border-radius: 4px;\n"
"padding: 6px;\n"
""));
        job_id = new QLineEdit(widget_2);
        job_id->setObjectName("job_id");
        job_id->setGeometry(QRect(10, 310, 231, 31));
        job_id->setStyleSheet(QString::fromUtf8("background-color: #bd842d;\n"
"border: 1px solid #5E9387;\n"
"border-radius: 4px;\n"
"padding: 6px;\n"
""));
        salary = new QLineEdit(widget_2);
        salary->setObjectName("salary");
        salary->setGeometry(QRect(10, 360, 231, 31));
        salary->setStyleSheet(QString::fromUtf8("background-color: #bd842d;\n"
"border: 1px solid #5E9387;\n"
"border-radius: 4px;\n"
"padding: 6px;\n"
""));
        date = new QLabel(widget_2);
        date->setObjectName("date");
        date->setGeometry(QRect(10, 220, 91, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("Tahoma")});
        font.setBold(true);
        date->setFont(font);
        hire_date = new QDateEdit(widget_2);
        hire_date->setObjectName("hire_date");
        hire_date->setGeometry(QRect(90, 220, 151, 31));
        hire_date->setStyleSheet(QString::fromUtf8("background-color: #b68a4d;\n"
"border: none;\n"
"color: white;\n"
"border-radius: 5px;\n"
"padding: 8px 12px;\n"
"font-size: 18px;\n"
"font: bold;\n"
""));
        clear_history_2 = new QPushButton(widget_2);
        clear_history_2->setObjectName("clear_history_2");
        clear_history_2->setGeometry(QRect(490, 610, 271, 41));
        clear_history_2->setStyleSheet(QString::fromUtf8("background-color: #b68a4d;\n"
"border: none;\n"
"color: white;\n"
"border-radius: 5px;\n"
"padding: 8px 12px;\n"
"font-size: 18px;\n"
"font: bold;\n"
"\n"
"\n"
""));
        email = new QLineEdit(widget_2);
        email->setObjectName("email");
        email->setGeometry(QRect(10, 260, 231, 31));
        email->setStyleSheet(QString::fromUtf8("background-color: #bd842d;\n"
"border: 1px solid #5E9387;\n"
"border-radius: 4px;\n"
"padding: 6px;\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1536, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:700;\">Employ\303\251s</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:700;\">Produits</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:700;\">Clients</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:700;\">Magazines</span></p><p align=\"center\"><span style=\" font-weight:700;\"><br/></span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:700;\">Parkings</span></p><p align=\"center\"><br/></p><p align=\"center\"><br/></p><p align=\"center\"><br/></p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        id->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        id->setText(QString());
        id->setPlaceholderText(QCoreApplication::translate("MainWindow", "Employee ID:", nullptr));
        first_name->setText(QString());
        first_name->setPlaceholderText(QCoreApplication::translate("MainWindow", "First Name:", nullptr));
        ajouter->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        modifier->setText(QCoreApplication::translate("MainWindow", "Modify", nullptr));
        supprimer->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        chercher->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        tri->setText(QCoreApplication::translate("MainWindow", "Sort", nullptr));
        statistique->setText(QCoreApplication::translate("MainWindow", "Statistics", nullptr));
        pdf->setText(QCoreApplication::translate("MainWindow", "Export PDF", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700;\">Add ou Modify</span></p></body></html>", nullptr));
        history->setText(QCoreApplication::translate("MainWindow", "History", nullptr));
        ordre->setItemText(0, QCoreApplication::translate("MainWindow", "sorting", nullptr));
        ordre->setItemText(1, QCoreApplication::translate("MainWindow", "Ascending", nullptr));
        ordre->setItemText(2, QCoreApplication::translate("MainWindow", "Descending", nullptr));

        critere->setItemText(0, QCoreApplication::translate("MainWindow", "Criteria", nullptr));
        critere->setItemText(1, QCoreApplication::translate("MainWindow", "ID Employee", nullptr));
        critere->setItemText(2, QCoreApplication::translate("MainWindow", "Firast name", nullptr));
        critere->setItemText(3, QCoreApplication::translate("MainWindow", "Hire date ", nullptr));
        critere->setItemText(4, QCoreApplication::translate("MainWindow", "Last name ", nullptr));
        critere->setItemText(5, QCoreApplication::translate("MainWindow", "Job ID", nullptr));
        critere->setItemText(6, QCoreApplication::translate("MainWindow", "Salary", nullptr));

        clear_history->setText(QCoreApplication::translate("MainWindow", "Clear History", nullptr));
        last_name->setText(QString());
        last_name->setPlaceholderText(QCoreApplication::translate("MainWindow", "Last Name:", nullptr));
        job_id->setText(QString());
        job_id->setPlaceholderText(QCoreApplication::translate("MainWindow", "Job ID:", nullptr));
        salary->setText(QString());
        salary->setPlaceholderText(QCoreApplication::translate("MainWindow", "Salary:", nullptr));
        date->setText(QCoreApplication::translate("MainWindow", "Hire Date:", nullptr));
        clear_history_2->setText(QCoreApplication::translate("MainWindow", "Check Salary", nullptr));
        email->setText(QString());
        email->setPlaceholderText(QCoreApplication::translate("MainWindow", "Email:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
