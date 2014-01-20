#include "sif2xmgrace.h"
#include "ui_sif2xmgrace.h"
#include "sif2xmgrace.h"
#include <QWidget>
#include <QtGui>
#include <QtCore>
#include <QLabel>
#include <QMessageBox>
#include <QLineEdit>
#include <iostream>
#include <QFileDialog>
#include <QtWidgets>
#include <QRect>
#include <QInputDialog>

SIF2XMGRACE::SIF2XMGRACE( map<string,bool> boolOpt,vector<QString> stringOpt, int curr,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SIF2XMGRACE)
{
    ui->setupUi(this);

    anySteps=false;
    multiFronts=false;
    isPropFile=false;

    PROP=false;
    PGL=false;
    PGLMLS=false;
    PL=false;
    PLMLS=false;
    deleteFiles=false;
    plotAgain=false;

    X_ini=0;
    X_end=0;

    ui->listWidget->addItem("1) PLOT KI only");
    ui->listWidget->addItem("2) PLOT KII only");
    ui->listWidget->addItem("3) PLOT KIII only");
    ui->listWidget->addItem("4) PLOT G only");
    ui->listWidget->addItem("5) PLOT all K's");
    ui->listWidget->addItem("6) PLOT all K's and G ");
    ui->checkBox_PROP->setChecked(true);

    ui->checkBoxAnySteps->setChecked(false);
    ui->lineEdit_specSteps->setEnabled(false);
    ui->label_anySteps->setEnabled(false);
    ui->checkBoxDelete->setChecked(true);
    ui->checkBoxDelete->setCheckable(true);
    ui->checkBox_PGLMLS->setCheckable(true);
    ui->checkBox_PLMLS->setCheckable(true);

    if(!boolOpt.empty() && !stringOpt.empty()){
        ui->listWidget->item(curr)->setSelected(true);
        ui->listWidget->setCurrentItem(ui->listWidget->item(curr) );
        ui->checkBox_PROP->setChecked(boolOpt["PROP"]);
        ui->checkBox_PGL->setChecked(boolOpt["PGL"]);
        ui->checkBox_PGLMLS->setChecked(boolOpt["PGLMLS"]);
        ui->checkBox_PL->setChecked(boolOpt["PL"]);
        ui->checkBox_PLMLS->setChecked(boolOpt["PLMLS"]);
        ui->checkBoxMulti->setChecked(boolOpt["multiFronts"]);
        ui->checkBoxAnySteps->setChecked(boolOpt["anySteps"]);
        ui->checkBoxDelete->setChecked(boolOpt["deleteFiles"]);
        newSteps();

        ui->lineEdit_startX->setText(stringOpt[0]);
        ui->lineEdit_EndX->setText(stringOpt[1]);
        if(!ui->checkBoxAnySteps->isChecked()){
                ui->lineEdit_fromStep->setText(stringOpt[2]);
                ui->lineEdit_toStep->setText(stringOpt[3]);
                ui->lineEditSteps->setText(stringOpt[4]);
         }
        else{
                 ui->lineEdit_specSteps->setText(stringOpt[5]);
        }
        ui->lineEditName->setText(stringOpt[6]);
        autoClick();

    }

    connect(ui->checkBoxAnySteps,SIGNAL(stateChanged(int) ), this , SLOT(newSteps()) );



}

void SIF2XMGRACE::newSteps(){

    if(ui->checkBoxAnySteps->isChecked()){

        ui->lineEdit_specSteps->setEnabled(true);

        ui->lineEdit_fromStep->setDisabled(true);
        ui->lineEdit_toStep->setDisabled(true);
        ui->lineEditSteps->setDisabled(true);

        ui->label_anySteps->setEnabled(true);
        ui->label_3->setDisabled(true);
        ui->label_4->setDisabled(true);
        ui->label_5->setDisabled(true);
    }
    else{

        ui->lineEdit_fromStep->setDisabled(false);
        ui->lineEdit_toStep->setDisabled(false);
        ui->lineEditSteps->setDisabled(false);

        ui->lineEdit_specSteps->setDisabled(true);

        ui->label_anySteps->setDisabled(true);
        ui->label_3->setDisabled(false);
        ui->label_4->setDisabled(false);
        ui->label_5->setDisabled(false);

    }

}

void SIF2XMGRACE::getPath(){


    QString path;

        path = QFileDialog::getOpenFileName(
                    this,
            "Choose a file to open",
            QString::null,
            QString::null);

    ui->lineEditName->setText(path);


}

void SIF2XMGRACE::warning(){

    QMessageBox warning;
    warning.setText("warning: you selected a .sif file, but it doesn't have SIFs data for propagation. The SIFs for propagation box will be unchecked");

    if(ui->checkBox_PROP->isChecked()&& isPropFile==false){
        warning.exec();
        ui->checkBox_PROP->setChecked(false);
        PROP=false;
        ui->checkBox_PROP->setCheckable(false);

     }
}

bool SIF2XMGRACE::shouldPlot(){

    return plotAgain;
}

map<string,bool> SIF2XMGRACE::recordBool(){
    map<string,bool> boolVariables;
    boolVariables["PROP"]=PROP;
    boolVariables["PGL"]=PGL;
    boolVariables["PGLMLS"]=PGLMLS;
    boolVariables["PL"]=PL;
    boolVariables["PLMLS"]=PLMLS;
    boolVariables["multiFronts"]=multiFronts;
    boolVariables["anySteps"]=anySteps;
    boolVariables["deleteFiles"]=deleteFiles;

    return boolVariables;
}

map<string,int> SIF2XMGRACE::recordInt(){
    map<string,int> intVariables;
    intVariables["option"]=opt;
    intVariables["startX"]=X_ini;
    intVariables["endX"]=X_end;
    intVariables["fromStep"]=ib;
    intVariables["toStep"]=ie;
    intVariables["steps"]=ifr;

    return intVariables;
}

vector<QString> SIF2XMGRACE::recordString(){
    vector<QString> stringVari;
    stringVari.push_back(ui->lineEdit_startX->text());    //0
    stringVari.push_back(ui->lineEdit_EndX->text());      //1
    stringVari.push_back(ui->lineEdit_fromStep->text());  //2
    stringVari.push_back(ui->lineEdit_toStep->text());    //3
    stringVari.push_back(ui->lineEditSteps->text());      //4
    stringVari.push_back(ui->lineEdit_specSteps->text()); //5
    stringVari.push_back(ui->lineEditName->text());       //6

    return stringVari;

}
QListWidgetItem* SIF2XMGRACE:: currItem(){

    return ui->listWidget->currentItem();
}
QModelIndex SIF2XMGRACE:: currIndex(){
   return  ui->listWidget->currentIndex();
}

int SIF2XMGRACE:: currRow(){
    return ui->listWidget->currentRow();
}

SIF2XMGRACE::~SIF2XMGRACE()
{
    delete ui;
}


void SIF2XMGRACE::on_pushButton_clicked()
{
    getPath();

    QString fileName=ui->lineEditName->text();
    if(fileName[fileName.size()-1]=='p')
        isPropFile=true;
    in_file_name=fileName.toStdString();

    warning();

}
void SIF2XMGRACE::autoClick(){
    QString fileName=ui->lineEditName->text();
    if(fileName[fileName.size()-1]=='p')
        isPropFile=true;
    in_file_name=fileName.toStdString();

    warning();
}


void SIF2XMGRACE::on_pushButton_plot_clicked()
{

    warning();

    if(in_file_name==""){
        QMessageBox::warning(this,"warning","No file selected, please select a data file!",QMessageBox::Ok);
    on_pushButton_clicked();
    }

    if(!isPropFile) {
        ui->checkBoxMulti->setChecked(false);
    }

    QChar option=(ui->listWidget->currentItem()->text())[0];

    if(option=='1')opt=1;
    else if(option=='2')opt=2;
    else if(option=='3')opt=3;
    else if(option=='4')opt=4;
    else if(option=='5')opt=5;
    else opt=6;

    if(ui->checkBoxMulti->isChecked()) multiFronts=true;

    if (ui->checkBox_PROP->isChecked()) PROP=true;
    if (ui->checkBox_PGL->isChecked()) PGL=true;
    if (ui->checkBox_PGLMLS->isChecked()) PGLMLS=true;
    if (ui->checkBox_PL->isChecked()) PL=true;
    if (ui->checkBox_PLMLS->isChecked()) PLMLS=true;

    X_ini=ui->lineEdit_startX->text().toDouble();
    X_end=ui->lineEdit_EndX->text().toDouble();

    if(!ui->checkBoxAnySteps->isChecked()) {
        anySteps=false;
        ib=ui->lineEdit_fromStep->text().toInt();
        ie=ui->lineEdit_toStep->text().toInt();
        ifr=ui->lineEditSteps->text().toInt();

        for(int pos=ib;pos<=ie;pos=pos+ifr)
            Pindex.push_back(pos);

     }

    else {
        anySteps=true;

        input=ui->lineEdit_specSteps->text().toStdString();

        for(int i=0;i<(int)input.size();i++){


                if (isdigit(input[i])){
                    string specificSteps="";

                    specificSteps.push_back(input[i]);
                                //cout<<specificSteps[0]<<"";
                    for(int k=i+1;k<(int)input.size();k++){
                        if (!isdigit(input[k])){ i=k; break;}

                        specificSteps.push_back(input[k]);
                        i=k;
                        }

                int singlestep;
                stringstream(specificSteps) >> singlestep;

                Pindex.push_back(singlestep);
                }
            }
            bool repeat=false;
            bool  negative=false;


            for(int z=0;z<(int)Pindex.size();z++){
                     if(Pindex[z]<0) {
                        negative=true;
                        Pindex.erase(Pindex.begin()+z);z--;
                        }

            }
            for(int x=0;x<(int)Pindex.size();x++){

                for(int y=x+1;y<(int)Pindex.size();y++)
                    if(Pindex[x]==Pindex[y]) {

                    repeat=true;
                    Pindex.erase(Pindex.begin()+y);y--;
                    }
            }


            if(repeat) {
                QMessageBox::warning(this,"warning","warning: you entered at least two same number! We will only keep one of them",QMessageBox::Ok);
              cout<<"warning: you entered at least two same number! We will only keep one of them"<<endl;
            }
            if(negative)
              cout<<"warning: you entered at least a negative number! We will remove negative number"<<endl;
            cout<<"valid steps you entered are: "<<endl;
            for(int num=0;num<(int)Pindex.size();num++){
                if(num==(int)Pindex.size()-1) cout<<Pindex[num]<<endl;
                else cout<<Pindex[num]<<",";

            }
    }

    if(ui->checkBoxDelete->isChecked()) deleteFiles=true;

    int numFronts=1;
     bool multiExists=false;

     if(isPropFile ==false) { multiFronts=false; }

     else {

       ReadSIFs inFileHelper(in_file_name,1,multiFronts,multiExists);  
       
       if(!inFileHelper.checkMLS() && (PGLMLS || PLMLS)){
           QMessageBox::warning(this,"warning","The selected data file does not have MLS data !",QMessageBox::Ok);
           ui->checkBox_PGLMLS->setCheckable(false);
           PGLMLS=false;
           ui->checkBox_PLMLS->setCheckable(false);
           PLMLS=false;

       }
       numFronts=inFileHelper.getNumFronts();

       if(numFronts>1) multiExists=true;

       if(multiFronts==false) numFronts=1;
     }


     for(int i=1;i<=numFronts;i++){
       ReadSIFs inFile(in_file_name,i,multiFronts, multiExists);
       inFile.set_isPropFile(isPropFile);  //use set_isPropFile member function to set variables in inFile
       inFile.storeCurves();
       //declare variables of vector type using curve template
       vector<Curve> Propcurves;
       vector<Curve> GLcurves;
       vector<Curve> GLMLScurves;
       vector<Curve> Lcurves;
       vector<Curve> LMLScurves;


       Propcurves=inFile.getPropSIFs(); // using getPropSIFS() to read data from inFile object and extract corrensponding values 					   // and use them to initialize Propcurves

       //the following extract member fucntions from ReadSIFs class work the same way and extract different information and store t
       // them in different curve variables.
       GLcurves=inFile.getGLSIFs();
       GLMLScurves=inFile.getGLMlsSIFs();
       Lcurves=inFile.getLSIFs();
       LMLScurves=inFile.getLMlsSIFs();

       cout<<"Read Process done!"<<endl;

       if(Lcurves.size()==0) PL=false;
       if(LMLScurves.size()==0) PLMLS=false;

       string PCols;

       switch(opt){
            case(1): {   //plot KI only

                    PCols = " -bxy 1:5 ";
                    break;
                }

             case(2): {   // plot KII only
                     PCols = " -bxy 1:6 ";
                    break;
                    }
            case(3):{    //plot KIII only
                    PCols = " -bxy 1:7 ";
                     break;
                }
            case(4):{   // this corrensponds to  "PLOT G only:", which should be added in curve.cpp!!!!!!
                     PCols = " -bxy 1:8 ";
                     break;
                }
            case(5):{   // plot all K's
                     PCols = " -bxy 1:5 -bxy 1:6 -bxy 1:7 ";
                     break;
                }
            case(6):{   // plot all K's and G

                    PCols = " -bxy 1:5 -bxy 1:6 -bxy 1:7 -bxy 1:8 ";
                    break;
                }
       }
       //this connects to WriteXMgrace class; all the previously initialized variables are passed by values to the constructor
       //which constructs the outFile object of WriteXMgrace type!!!!!!!!!

       if(!deleteFiles){
            bool ok;
          QString output= QInputDialog::getText(this, "output file name", "Please give the output file name", QLineEdit::Normal,QDir::home().dirName(), &ok);
           out_file_name=output.toStdString();
       }

       WriteXMgrace outFile(out_file_name, Propcurves, GLcurves,
                    GLMLScurves, Lcurves,
                    LMLScurves, PCols, opt, PROP, PGL,
                    PGLMLS, PL, PLMLS, /*planeV,*/
                    /*Center,*/ X_ini, X_end,
                    Pindex, deleteFiles, isPropFile);


       cout << endl << endl<< "Done!!!!"<<endl;


       }

     QMessageBox::StandardButton reply;
     QMessageBox::information(this,"Result","XMGrace data plotted successfully !");
     reply=QMessageBox::question(this,"Question","Do you want to continue plotting ?", QMessageBox::Yes | QMessageBox::No);

     if(reply==QMessageBox::Yes) plotAgain=true;

     this->close();

}





