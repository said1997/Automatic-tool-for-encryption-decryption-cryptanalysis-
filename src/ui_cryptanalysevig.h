/********************************************************************************
** Form generated from reading UI file 'cryptanalysevig.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CRYPTANALYSEVIG_H
#define UI_CRYPTANALYSEVIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CryptanalyseVig
{
public:
    QListWidget *listWidget;
    QTableWidget *tableWidget;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QWidget *CryptanalyseVig)
    {
        if (CryptanalyseVig->objectName().isEmpty())
            CryptanalyseVig->setObjectName(QStringLiteral("CryptanalyseVig"));
        CryptanalyseVig->resize(855, 476);
        listWidget = new QListWidget(CryptanalyseVig);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(460, 40, 391, 401));
        tableWidget = new QTableWidget(CryptanalyseVig);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 40, 440, 401));
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(28);
        tableWidget->horizontalHeader()->setMinimumSectionSize(15);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(21);
        tableWidget->verticalHeader()->setMinimumSectionSize(15);
        pushButton = new QPushButton(CryptanalyseVig);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(750, 450, 83, 25));
        label = new QLabel(CryptanalyseVig);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 10, 311, 17));

        retranslateUi(CryptanalyseVig);

        QMetaObject::connectSlotsByName(CryptanalyseVig);
    } // setupUi

    void retranslateUi(QWidget *CryptanalyseVig)
    {
        CryptanalyseVig->setWindowTitle(QApplication::translate("CryptanalyseVig", "Form", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        tableWidget->setAccessibleName(QApplication::translate("CryptanalyseVig", "tabText", nullptr));
#endif // QT_NO_ACCESSIBILITY
        pushButton->setText(QApplication::translate("CryptanalyseVig", "Next", nullptr));
        label->setText(QApplication::translate("CryptanalyseVig", "Cl\303\251 de Cryptage :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CryptanalyseVig: public Ui_CryptanalyseVig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CRYPTANALYSEVIG_H
