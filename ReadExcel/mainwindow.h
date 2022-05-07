#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
using namespace QXlsx;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    MainWindow(Document* file,QWidget *parent = nullptr);
    void deneme();

    ~MainWindow();

private slots:
    //exit click
    void on_exit_clicked();
    //accept click
    void on_accept_clicked();

private:
    Ui::MainWindow *ui;
    //A document pointer to hold excel file`s address in
    //this program
    Document* file;
    //a QString headers to store headers
    QString headers[23];
    //total number of headers
    int headers_count = 23;
    //maximum headers length
    int max_headLen = 25;

    //A method to get headers from excel file
    //and stores headers[] value
    void fillHeaders();
    //method to aligns headers for display
    void allignHeaders();


};
#endif // MAINWINDOW_H
