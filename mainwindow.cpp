#include "mainwindow.h"
#include "employes.h"
#include "ui_mainwindow.h"
#include "gestiontaches.h"
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QDate>
#include <QPieSeries>
#include <QChart>
#include <QChartView>
#include <QVBoxLayout>
#include <QDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QFile>
#include <QTextStream>
#include <QDateTime>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->ajouter, &QPushButton::clicked, this, &MainWindow::on_pushButton_ajouter_clicked);
    connect(ui->supprimer, &QPushButton::clicked, this, &MainWindow::on_pushButton_supprimer_clicked);
    connect(ui->modifier, &QPushButton::clicked, this, &MainWindow::on_pushButton_modifier_clicked);
    connect(ui->chercher, &QPushButton::clicked, this, &MainWindow::on_pushButton_rechercher_clicked);
    connect(ui->tri, &QPushButton::clicked, this, &MainWindow::on_pushButton_trier_clicked);
    connect(ui->pdf, &QPushButton::clicked, this, &MainWindow::on_pushButton_afficher_clicked);
    connect(ui->statistique, &QPushButton::clicked, this, &MainWindow::afficher_statistiques);
    connect(ui->history, &QPushButton::clicked, this, &MainWindow::afficherHistorique);
    connect(ui->attribuerTache, &QPushButton::clicked, this, &MainWindow::attribuerTacheAuto);
    connect(ui->afficherAttributions, &QPushButton::clicked, this, &MainWindow::afficherAttributions);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ajouter_clicked()
{
    int id = ui->id->text().toInt();
    QString prenom = ui->first_name->text();
    QString nom = ui->last_name->text();
    QString email = ui->email->text();
    QDate dateEmbauche = ui->hire_date->date();
    QString poste = ui->job_id->text();
    double salaire = ui->salary->text().toDouble();
    QString competences =ui->competences->text();

    Employe e(id, prenom, nom, email, dateEmbauche, poste, salaire , competences);

    if (e.ajouter())
        QMessageBox::information(this, "Succès", "Employé ajouté !");
    else
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout.");
}

void MainWindow::on_pushButton_afficher_clicked()
{
    Employe e;
    QSqlQueryModel *model = e.afficher();

    if (model) {
        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();
    }
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    int id = ui->id->text().toInt();
    Employe e;

    if (e.supprimer(id))
        QMessageBox::information(this, "Succès", "Employé supprimé !");
    else
        QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression.");
}

void MainWindow::on_pushButton_modifier_clicked()
{
    int id = ui->id->text().toInt();
    QString prenom = ui->first_name->text();
    QString nom = ui->last_name->text();
    QString email = ui->email->text();
    QDate dateEmbauche = ui->hire_date->date();
    QString poste = ui->job_id->text();
    double salaire = ui->salary->text().toDouble();
    QString competences =ui->competences->text();

    Employe e(id, prenom, nom, email, dateEmbauche, poste, salaire,competences);

    if (e.modifier())
        QMessageBox::information(this, "Succès", "Employé modifié !");
    else
        QMessageBox::critical(this, "Erreur", "Erreur lors de la modification.");
}

void MainWindow::on_pushButton_rechercher_clicked()
{
    bool ok;
    int id = ui->id->text().toInt(&ok);  // Récupérer l'ID entré par l'utilisateur

    if (!ok || id == 0) {
        QMessageBox::warning(this, "ID invalide", "Veuillez saisir un ID valide.");
        return;
    }

    Employe e;
    QSqlQueryModel* model = e.chercherEmployeParId(id);  // Recherche par ID

    if (model && model->rowCount() > 0) {
        ui->tableView->setModel(model);  // Afficher les résultats dans le QTableView
    } else {
        QMessageBox::warning(this, "Aucun résultat", "Aucun employé trouvé avec cet ID.");
    }
}

void MainWindow::on_pushButton_trier_clicked()
{
    QString critere = ui->critere->currentText();
    QString ordre = ui->ordre->currentText();

    QString colonne;
    if (critere == "ID Employee")
        colonne = "EMPLOYEE_ID";
    else if (critere == "First name")
        colonne = "FIRST_NAME";
    else if (critere == "Hire date")
        colonne = "HIRE_DATE";
    else
        colonne = "EMPLOYEE_ID"; // fallback

    QString query = QString("SELECT * FROM EMPLOYEES ORDER BY %1 %2")
                        .arg(colonne, ordre == "Ascending" ? "ASC" : "DESC");

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(query);

    if (model->lastError().isValid())
        QMessageBox::critical(this, "Erreur SQL", model->lastError().text());
    else
        ui->tableView->setModel(model);
}


void MainWindow::afficher_statistiques()
{
    QSqlQuery query;

    // Préparer la requête pour obtenir les statistiques sur les salaires
    query.prepare(
        "SELECT "
        "MIN(SALARY), "  // Salaire minimum
        "AVG(SALARY), "  // Salaire moyen
        "MAX(SALARY) "  // Salaire maximum
        "FROM EMPLOYEES"
        );

    // Exécuter la requête
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec de la requête : " + query.lastError().text());
        return;
    }

    // Vérifier que la requête a retourné des résultats
    if (query.next()) {
        double minSalary = query.value(0).toDouble();
        double avgSalary = query.value(1).toDouble();
        double maxSalary = query.value(2).toDouble();

        // Création du graphique à barres
        QBarSet *set = new QBarSet("Salaries");
        *set << minSalary << avgSalary << maxSalary;

        QBarSeries *series = new QBarSeries();
        series->append(set);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Employee Salary Statistics");
        chart->setAnimationOptions(QChart::SeriesAnimations);

        QStringList categories;
        categories << "Min" << "Average" << "Max";
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        axisY->setRange(0, maxSalary + 1000);  // Ajouter une marge
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        // Créer une nouvelle fenêtre pour afficher le graphique
        QMainWindow *chartWindow = new QMainWindow(this);
        chartWindow->setCentralWidget(chartView);
        chartWindow->resize(600, 400);
        chartWindow->setWindowTitle("Salary Statistics Chart");
        chartWindow->show();
    } else {
        QMessageBox::warning(this, "Aucune donnée", "Aucun employé trouvé.");
    }
}
void MainWindow::afficherHistorique()
{
    QFile file("history.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString contenu = in.readAll();
        file.close();

        QMessageBox::information(this, "Historique des actions", contenu);
    } else {
        QMessageBox::warning(this, "Erreur", "Impossible d'ouvrir le fichier historique.");
    }
}
void MainWindow::attribuerTacheAuto() {
    int idTache = ui->comboBox_taches->currentData().toInt();

    // Charger les infos de la tâche depuis la base
    QSqlQuery query;
    query.prepare("SELECT * FROM TACHES WHERE TACHE_ID = :id");
    query.bindValue(":id", idTache);
    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "Erreur", "Impossible de charger la tâche.");
        return;
    }

    QString desc = query.value("DESCRIPTION").toString();
    QString comp = query.value("COMPETENCE_REQUISE").toString();
    int duree = query.value("DUREE_ESTIMEE").toInt();

    Tache t(idTache, desc, comp, duree);
    Employe e;

    if (GestionTaches::assignerTacheAuto(t, e))
        QMessageBox::information(this, "Succès", "Tâche attribuée automatiquement.");
    else
        QMessageBox::warning(this, "Échec", "Aucun employé correspondant trouvé.");
}

void MainWindow::afficherAttributions() {
    QSqlQueryModel* model = GestionTaches::afficherAttributions();

    if (model == nullptr || model->rowCount() == 0) {
        QMessageBox::critical(this, "Erreur", "Aucune attribution à afficher.");
        return;
    }

    if (model->lastError().isValid()) {
        QMessageBox::critical(this, "Erreur SQL", "Erreur lors de l'exécution de la requête : " + model->lastError().text());
        return;
    }

    ui->tableView_2->setModel(model);
    ui->tableView_2->resizeColumnsToContents();
}



