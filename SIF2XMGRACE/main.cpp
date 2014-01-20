#include "sif2xmgrace.h"
#include <QApplication>
#include <map>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    map<string,bool> boolOpt;
    vector<QString> stringOpt;
    QModelIndex curr;
    int currentRow;

     while(true){        
         SIF2XMGRACE w(boolOpt,stringOpt,currentRow);
         w.show();
         a.exec();
         if (!w.shouldPlot()) return 0;
         boolOpt=w.recordBool();
         stringOpt=w.recordString();
         currentRow=w.currRow();
     }


}
