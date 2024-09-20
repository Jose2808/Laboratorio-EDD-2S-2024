#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include "nlohmann/json.hpp"
#include <list>
#include "persona.h"

std::list<persona> lista_personas;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Boton_abrir_clicked()
{
    QString ruta_archivo = QFileDialog::getOpenFileName(this, "Abrir archivo a cargar", "D://");
    QFile file(ruta_archivo);

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Advertencia", "Archivo no abierto");
    }
    QTextStream in(&file);
    QString contenido = in.readAll();
    ui->verArchivo->setPlainText(contenido);

    file.close();
}


void MainWindow::on_Boton_cargar_clicked()
{
    using json = nlohmann::json;

    QString texto = ui->verArchivo->toPlainText();
    json personas = json::parse(texto.toStdString());

    for(const auto& p : personas){
        if(p.contains("nombres") && p.contains("apellidos") && p.contains("correo") && p.contains("fecha_de_nacimiento") && p.contains("contraseña")){
            persona nueva_persona;
            nueva_persona.nombres = p["nombres"];
            nueva_persona.apellidos = p["apellidos"];
            nueva_persona.correo = p["correo"];
            nueva_persona.nacimiento = p["fecha_de_nacimiento"];
            nueva_persona.contrasenia = p["contraseña"];

            lista_personas.push_front(nueva_persona);
        }else{
            QMessageBox::warning(this, "Carga de usuarios", "Error al cargar usuarios");
            ui->verArchivo->setPlainText("");
            return;
        }
    }

    QMessageBox::information(this, "Carga de usuarios", "Carga realizada exitósamente");
    ui->verArchivo->setPlainText("");
}


void MainWindow::on_Boton_reporte_clicked()
{
    int i = 0;
    ui->Tabla_usuarios->setRowCount(lista_personas.size());

    for(persona p : lista_personas){
        ui->Tabla_usuarios->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(p.nombres)));
        ui->Tabla_usuarios->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(p.apellidos)));
        ui->Tabla_usuarios->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(p.nacimiento)));
        ui->Tabla_usuarios->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(p.correo)));

        i++;
    }
}

