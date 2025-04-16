#include "mainwindow.h"
#include "employes.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlError>

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

    Employe e(id, prenom, nom, email, dateEmbauche, poste, salaire);

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

    Employe e(id, prenom, nom, email, dateEmbauche, poste, salaire);

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
