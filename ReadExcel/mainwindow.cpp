#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "QMessageBox"
#include <iostream>
#include <iomanip>
using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::MainWindow(Document* file, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->file = file;
    fillHeaders();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete file;
}

/**
 * @brief MainWindow::fillHeaders
 * A private method to get headers from excel file
 */
void MainWindow::fillHeaders(){
    for(int i=1; i<headers_count+1; i++){
        Cell* cell =file->cellAt(3, i); // get cell pointer.
        if(cell!=NULL){
            headers[i-1] = cell->readValue().toString();
        }
    }
    allignHeaders();
}

/**
 * @brief MainWindow::allignHeaders
 * A method to make it ready for display
 */
void MainWindow::allignHeaders(){
    for(int i=0; i<headers_count; i++){
        headers[i].append(": ");
        for(int j=headers[i].length(); j< this->max_headLen; j++){
            headers[i].append(" ");
        }
    }
}



void MainWindow::deneme(){
    qDebug()<<"denedim";
    int k = 10;
    this->file->cellAt(1,1);
    qDebug()<<k;
}




/**
 * @brief MainWindow::on_accept_clicked
 * A method to select & check rowbox stages' specifies
 */

void MainWindow::on_accept_clicked()
{
    int row = 0;
    QString qstring;
    QString combo = ui->comboBox->currentText();
    row = combo.toInt();
    row+=3;//stages start 4.row

    for(int i=1; i<headers_count+1; i++){
        Cell* cell =file->cellAt(row, i); // get cell pointer.
        if(cell!=NULL){
            qstring.append(headers[i-1] + "\t\t" );
            qstring.append(cell->readValue().toString()+"\n");
        }
    }
    //inform user with stage`s information
    QMessageBox::information(this,tr("Infography"), qstring);

}

void MainWindow::on_exit_clicked()
{
    MainWindow::close();

}


