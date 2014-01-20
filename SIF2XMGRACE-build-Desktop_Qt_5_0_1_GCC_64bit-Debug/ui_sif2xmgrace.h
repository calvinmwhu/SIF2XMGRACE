/********************************************************************************
** Form generated from reading UI file 'sif2xmgrace.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIF2XMGRACE_H
#define UI_SIF2XMGRACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SIF2XMGRACE
{
public:
    QListWidget *listWidget;
    QCheckBox *checkBox_PROP;
    QCheckBox *checkBoxMulti;
    QCheckBox *checkBoxAnySteps;
    QLabel *label_anySteps;
    QLineEdit *lineEdit_specSteps;
    QLabel *label;
    QLabel *label_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox_PGL;
    QCheckBox *checkBox_PGLMLS;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox_PL;
    QCheckBox *checkBox_PLMLS;
    QSplitter *splitter;
    QLabel *label_startValueX;
    QLineEdit *lineEdit_startX;
    QSplitter *splitter_2;
    QLabel *label_endValueX;
    QLineEdit *lineEdit_EndX;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QSplitter *splitter_3;
    QLabel *label_3;
    QLineEdit *lineEdit_fromStep;
    QSplitter *splitter_4;
    QLabel *label_4;
    QLineEdit *lineEdit_toStep;
    QSplitter *splitter_5;
    QLabel *label_5;
    QLineEdit *lineEditSteps;
    QSplitter *splitter_6;
    QLineEdit *lineEditName;
    QPushButton *pushButton;
    QSplitter *splitter_7;
    QCheckBox *checkBoxDelete;
    QPushButton *pushButton_plot;

    void setupUi(QDialog *SIF2XMGRACE)
    {
        if (SIF2XMGRACE->objectName().isEmpty())
            SIF2XMGRACE->setObjectName(QStringLiteral("SIF2XMGRACE"));
        SIF2XMGRACE->resize(649, 737);
        listWidget = new QListWidget(SIF2XMGRACE);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(90, 40, 391, 121));
        checkBox_PROP = new QCheckBox(SIF2XMGRACE);
        checkBox_PROP->setObjectName(QStringLiteral("checkBox_PROP"));
        checkBox_PROP->setGeometry(QRect(80, 180, 391, 22));
        checkBoxMulti = new QCheckBox(SIF2XMGRACE);
        checkBoxMulti->setObjectName(QStringLiteral("checkBoxMulti"));
        checkBoxMulti->setGeometry(QRect(80, 290, 401, 22));
        checkBoxAnySteps = new QCheckBox(SIF2XMGRACE);
        checkBoxAnySteps->setObjectName(QStringLiteral("checkBoxAnySteps"));
        checkBoxAnySteps->setGeometry(QRect(80, 410, 291, 22));
        label_anySteps = new QLabel(SIF2XMGRACE);
        label_anySteps->setObjectName(QStringLiteral("label_anySteps"));
        label_anySteps->setGeometry(QRect(80, 530, 471, 17));
        lineEdit_specSteps = new QLineEdit(SIF2XMGRACE);
        lineEdit_specSteps->setObjectName(QStringLiteral("lineEdit_specSteps"));
        lineEdit_specSteps->setGeometry(QRect(80, 550, 421, 27));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_specSteps->sizePolicy().hasHeightForWidth());
        lineEdit_specSteps->setSizePolicy(sizePolicy);
        label = new QLabel(SIF2XMGRACE);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 600, 461, 17));
        label_2 = new QLabel(SIF2XMGRACE);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 20, 301, 17));
        layoutWidget = new QWidget(SIF2XMGRACE);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 220, 378, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        checkBox_PGL = new QCheckBox(layoutWidget);
        checkBox_PGL->setObjectName(QStringLiteral("checkBox_PGL"));

        horizontalLayout->addWidget(checkBox_PGL);

        checkBox_PGLMLS = new QCheckBox(layoutWidget);
        checkBox_PGLMLS->setObjectName(QStringLiteral("checkBox_PGLMLS"));

        horizontalLayout->addWidget(checkBox_PGLMLS);

        layoutWidget1 = new QWidget(SIF2XMGRACE);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(80, 250, 381, 24));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        checkBox_PL = new QCheckBox(layoutWidget1);
        checkBox_PL->setObjectName(QStringLiteral("checkBox_PL"));

        horizontalLayout_2->addWidget(checkBox_PL);

        checkBox_PLMLS = new QCheckBox(layoutWidget1);
        checkBox_PLMLS->setObjectName(QStringLiteral("checkBox_PLMLS"));

        horizontalLayout_2->addWidget(checkBox_PLMLS);

        splitter = new QSplitter(SIF2XMGRACE);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(80, 320, 321, 27));
        splitter->setOrientation(Qt::Horizontal);
        label_startValueX = new QLabel(splitter);
        label_startValueX->setObjectName(QStringLiteral("label_startValueX"));
        splitter->addWidget(label_startValueX);
        lineEdit_startX = new QLineEdit(splitter);
        lineEdit_startX->setObjectName(QStringLiteral("lineEdit_startX"));
        sizePolicy.setHeightForWidth(lineEdit_startX->sizePolicy().hasHeightForWidth());
        lineEdit_startX->setSizePolicy(sizePolicy);
        splitter->addWidget(lineEdit_startX);
        splitter_2 = new QSplitter(SIF2XMGRACE);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setGeometry(QRect(80, 360, 321, 27));
        splitter_2->setOrientation(Qt::Horizontal);
        label_endValueX = new QLabel(splitter_2);
        label_endValueX->setObjectName(QStringLiteral("label_endValueX"));
        splitter_2->addWidget(label_endValueX);
        lineEdit_EndX = new QLineEdit(splitter_2);
        lineEdit_EndX->setObjectName(QStringLiteral("lineEdit_EndX"));
        sizePolicy.setHeightForWidth(lineEdit_EndX->sizePolicy().hasHeightForWidth());
        lineEdit_EndX->setSizePolicy(sizePolicy);
        splitter_2->addWidget(lineEdit_EndX);
        layoutWidget2 = new QWidget(SIF2XMGRACE);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(80, 440, 456, 29));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        splitter_3 = new QSplitter(layoutWidget2);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(splitter_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        splitter_3->addWidget(label_3);
        lineEdit_fromStep = new QLineEdit(splitter_3);
        lineEdit_fromStep->setObjectName(QStringLiteral("lineEdit_fromStep"));
        splitter_3->addWidget(lineEdit_fromStep);

        horizontalLayout_3->addWidget(splitter_3);

        splitter_4 = new QSplitter(layoutWidget2);
        splitter_4->setObjectName(QStringLiteral("splitter_4"));
        splitter_4->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(splitter_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        splitter_4->addWidget(label_4);
        lineEdit_toStep = new QLineEdit(splitter_4);
        lineEdit_toStep->setObjectName(QStringLiteral("lineEdit_toStep"));
        splitter_4->addWidget(lineEdit_toStep);

        horizontalLayout_3->addWidget(splitter_4);

        splitter_5 = new QSplitter(SIF2XMGRACE);
        splitter_5->setObjectName(QStringLiteral("splitter_5"));
        splitter_5->setGeometry(QRect(80, 480, 313, 27));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(splitter_5->sizePolicy().hasHeightForWidth());
        splitter_5->setSizePolicy(sizePolicy1);
        splitter_5->setOrientation(Qt::Horizontal);
        label_5 = new QLabel(splitter_5);
        label_5->setObjectName(QStringLiteral("label_5"));
        splitter_5->addWidget(label_5);
        lineEditSteps = new QLineEdit(splitter_5);
        lineEditSteps->setObjectName(QStringLiteral("lineEditSteps"));
        splitter_5->addWidget(lineEditSteps);
        splitter_6 = new QSplitter(SIF2XMGRACE);
        splitter_6->setObjectName(QStringLiteral("splitter_6"));
        splitter_6->setGeometry(QRect(80, 620, 461, 27));
        splitter_6->setOrientation(Qt::Horizontal);
        lineEditName = new QLineEdit(splitter_6);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));
        sizePolicy.setHeightForWidth(lineEditName->sizePolicy().hasHeightForWidth());
        lineEditName->setSizePolicy(sizePolicy);
        splitter_6->addWidget(lineEditName);
        pushButton = new QPushButton(splitter_6);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        splitter_6->addWidget(pushButton);
        splitter_7 = new QSplitter(SIF2XMGRACE);
        splitter_7->setObjectName(QStringLiteral("splitter_7"));
        splitter_7->setGeometry(QRect(80, 660, 471, 27));
        splitter_7->setOrientation(Qt::Horizontal);
        checkBoxDelete = new QCheckBox(splitter_7);
        checkBoxDelete->setObjectName(QStringLiteral("checkBoxDelete"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(checkBoxDelete->sizePolicy().hasHeightForWidth());
        checkBoxDelete->setSizePolicy(sizePolicy2);
        splitter_7->addWidget(checkBoxDelete);
        pushButton_plot = new QPushButton(splitter_7);
        pushButton_plot->setObjectName(QStringLiteral("pushButton_plot"));
        splitter_7->addWidget(pushButton_plot);

        retranslateUi(SIF2XMGRACE);

        QMetaObject::connectSlotsByName(SIF2XMGRACE);
    } // setupUi

    void retranslateUi(QDialog *SIF2XMGRACE)
    {
        SIF2XMGRACE->setWindowTitle(QApplication::translate("SIF2XMGRACE", "SIF2XMGRACE", 0));
        checkBox_PROP->setText(QApplication::translate("SIF2XMGRACE", "Plot SIFs for propagation (only applies to .crp files)", 0));
        checkBoxMulti->setText(QApplication::translate("SIF2XMGRACE", "Plot fronts separately (in separate files)", 0));
        checkBoxAnySteps->setText(QApplication::translate("SIF2XMGRACE", "Plot for specific steps", 0));
        label_anySteps->setText(QApplication::translate("SIF2XMGRACE", "Plot for specific steps; enter the steps with space inbetween each", 0));
        label->setText(QApplication::translate("SIF2XMGRACE", "Please browse for a file to plot (file needs to be a .crp or .sif)", 0));
        label_2->setText(QApplication::translate("SIF2XMGRACE", "Choose an option:", 0));
        checkBox_PGL->setText(QApplication::translate("SIF2XMGRACE", "Plot Raw Global values", 0));
        checkBox_PGLMLS->setText(QApplication::translate("SIF2XMGRACE", "Plot Global MLS values", 0));
        checkBox_PL->setText(QApplication::translate("SIF2XMGRACE", "Plot Local Raw values", 0));
        checkBox_PLMLS->setText(QApplication::translate("SIF2XMGRACE", "Plot Local MLS values", 0));
        label_startValueX->setText(QApplication::translate("SIF2XMGRACE", "Start value for x", 0));
        label_endValueX->setText(QApplication::translate("SIF2XMGRACE", "End value for x", 0));
        label_3->setText(QApplication::translate("SIF2XMGRACE", "Plot from step:", 0));
        label_4->setText(QApplication::translate("SIF2XMGRACE", "To step:", 0));
        label_5->setText(QApplication::translate("SIF2XMGRACE", "For every (1,2,3...)step(s)", 0));
        pushButton->setText(QApplication::translate("SIF2XMGRACE", "Browse", 0));
        checkBoxDelete->setText(QApplication::translate("SIF2XMGRACE", "Delete XMGrace data files after plotting", 0));
        pushButton_plot->setText(QApplication::translate("SIF2XMGRACE", "PLOT", 0));
    } // retranslateUi

};

namespace Ui {
    class SIF2XMGRACE: public Ui_SIF2XMGRACE {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIF2XMGRACE_H
