#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <iostream>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

using namespace std;

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

void MainWindow::on_pushButton_clicked()
{
    this->generar_texto();
}


void MainWindow::generar_texto()
{
    ui->plainTextEdit->clear();

    if(lista.get_lista_beg() != NULL)
    {
        neurona *aux = lista.get_lista_beg();
        while(aux != NULL)
        {
            QString aux_qstr = QString("ID: %1\nVoltaje: %2\n Posicion x: %3\nPosicion y: %4\nRed: %5\nGreen: %6\nBlue: %7\n---------------").arg(aux->get_id()).arg(aux->get_voltaje()).arg(aux->get_posicion_x()).arg(aux->get_posicion_y()).arg(aux->get_red()).arg(aux->get_green()).arg(aux->get_blue());
            ui->plainTextEdit->appendPlainText(aux_qstr);
            aux = aux->get_sig_neurona();
        }
    }
}

void MainWindow::obtener_datos(int indicador)
{
    neurona *aux = new neurona();

    aux->set_all(ui->spinBox->value(),ui->doubleSpinBox->value(),ui->spinBox_2->value(),ui->spinBox_3->value(),ui->spinBox_4->value(),ui->spinBox_5->value(),ui->spinBox_6->value());

    if(indicador == 0)
        lista.agregar_inicio(aux);
    if(indicador == 1)
        lista.agregar_final(aux);

}


void MainWindow::on_pushButton_2_clicked()
{
    obtener_datos(0);
}


void MainWindow::on_pushButton_3_clicked()
{
    obtener_datos(1);
}


void MainWindow::on_actionGuardar_triggered()
{
    QString direccion = QFileDialog::getSaveFileName(this, tr("Guardar Neuronas"),"",tr("Text files (*.txt)"));

    if (!direccion.isEmpty())
    {
        QFile archivo_guardar(direccion);

        if (archivo_guardar.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream imprimir(&archivo_guardar);
            if(lista.get_lista_beg() != NULL)
            {
                neurona *aux = lista.get_lista_beg();
                while(aux != NULL)
                {
                    QString aux_qstr = QString("%1:%2:%3:%4:%5:%6:%7").arg(aux->get_id()).arg(aux->get_voltaje()).arg(aux->get_posicion_x()).arg(aux->get_posicion_y()).arg(aux->get_red()).arg(aux->get_green()).arg(aux->get_blue());
                    imprimir << aux_qstr << '\n';
                    aux = aux->get_sig_neurona();
                }
            }
            archivo_guardar.close();
        }
    }
}


void MainWindow::on_actionRecuperar_triggered()
{
    QString direccion = QFileDialog::getOpenFileName(this, tr("Abrir Neuronas"),"",tr("Text files (*.txt)"));

    if (!direccion.isEmpty())
    {
        QFile archivo_leer(direccion);

        if (archivo_leer.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream leer(&archivo_leer);

            while (!leer.atEnd())
            {
                QString linea = leer.readLine();
                QStringList lista_valores =  linea.split(":");
                int id = lista_valores[0].toInt();
                float voltaje = lista_valores[1].toFloat();
                int posicionX = lista_valores[2].toInt();
                int posicionY = lista_valores[3].toInt();
                int red = lista_valores[4].toInt();
                int green = lista_valores[5].toInt();
                int blue = lista_valores[6].toInt();

                neurona *aux = new neurona();
                aux->set_all(id,voltaje,posicionX,posicionY,red,green,blue);
                lista.agregar_final(aux);
            }

            archivo_leer.close();
        }

    }
}

