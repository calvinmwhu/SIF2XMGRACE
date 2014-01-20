#ifndef SIF2XMGRACE_H
#define SIF2XMGRACE_H

#include <QDialog>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <boost/tokenizer.hpp>
#include <deque>
#include <iterator>
#include <vector>
#include <QMap>
#include <algorithm>
#include <sstream>
#include "readSIFs.h"
#include "curve.h"
#include "writeXMgrace.h"
#include <cctype>
#include <stdlib.h>
#include <QVector>
#include <map>
#include <QListWidgetItem>
#include <QModelIndex>

#include <cmath>
#include <time.h>
#include <unistd.h>
#define PI 3.14159265

using namespace std;
using std::cout;
using std::endl;

namespace Ui {
class SIF2XMGRACE;
}

class SIF2XMGRACE : public QDialog
{
    Q_OBJECT
    
public:
    explicit SIF2XMGRACE(map<string,bool> boolOpt,vector<QString> stringOpt,int curr , QWidget *parent=0);
    ~SIF2XMGRACE();

    void warning();
    bool shouldPlot();
    map<string,bool> recordBool();
    map<string, int> recordInt();
    vector<QString> recordString();
    QListWidgetItem* currItem();
    QModelIndex currIndex();
    int currRow();


//public slots:


private slots:
    void getPath();

    void newSteps();
    void on_pushButton_plot_clicked();
    void on_pushButton_clicked();

private:
    Ui::SIF2XMGRACE *ui;
    string in_file_name;
    string out_file_name;
    string input;
    int opt, multi , ib, ie, ifr;

    bool anySteps;
    bool multiFronts;

    bool isPropFile;
    bool PROP;
    bool PGL;
    bool PGLMLS;
    bool PL;
    bool PLMLS;
    bool deleteFiles;
    bool plotAgain;

    void autoClick();

    double  X_ini, X_end;
    vector <int> planeV, Pindex;
    vector<double> Center;
};


#endif // SIF2XMGRACE_H
