#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_ajouter_clicked();
    void on_pushButton_afficher_clicked();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_modifier_clicked();
    void on_pushButton_rechercher_clicked();  // Recherche par ID
    void on_pushButton_trier_clicked();
    void afficher_statistiques();
    void afficherHistorique();
    void attribuerTacheAuto();
    void afficherAttributions();

private:
    Ui::MainWindow *ui;  // Pointer to the UI class
};

#endif // MAINWINDOW_H
