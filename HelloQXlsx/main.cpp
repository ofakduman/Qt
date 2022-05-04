// main.cpp

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
    QCoreApplication a(argc, argv);

    QXlsx::Document xlsx;
    xlsx.write("A1", "Hello digga!"); // write "Hello Qt!" to cell(A,1). it's shared string.
    xlsx.saveAs("test.xlsx"); // save the document as 'Test.xlsx'

    Document xlsxR("excel_to_import.xlsx");

    if (xlsxR.load()) // load excel file
        {
            int row = 163; int col = 23;
            for(int i=1;i<=row;i++){
                    for(int j=1; j<col; j++){
                        Cell* cell = xlsxR.cellAt(i, j); // get cell pointer.
                        if ( cell != NULL )
                        {
                            QVariant var = cell->readValue(); // read cell value (number(double), QDateTime, QString ...)
                            qDebug() << var; // display value. it is 'Hello Qt!'.
                        }
                    }
               }
        }
    return 0;
    // return a.exec();
}
