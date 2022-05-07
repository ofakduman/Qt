#include "mainwindow.h"

#include <QApplication>
#include <QtGlobal>
#include <QCoreApplication>
#include <QtCore>
#include <QVariant>
#include <QDebug>

#include <iostream>
using namespace std;


// [0] include QXlsx headers
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
using namespace QXlsx;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //reads external excel file
    Document xlsxR("excel_to_import.xlsx");
    //pass as a parameter to mainwindow
    MainWindow w1(&xlsxR);
    w1.show();


    return a.exec();
}
