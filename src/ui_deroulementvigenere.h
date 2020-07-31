/********************************************************************************
** Form generated from reading UI file 'deroulementvigenere.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEROULEMENTVIGENERE_H
#define UI_DEROULEMENTVIGENERE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeroulementVigenere
{
public:
    QTableWidget *tableWidget;
    QListWidget *listWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QProgressBar *progressBar;

    void setupUi(QWidget *DeroulementVigenere)
    {
        if (DeroulementVigenere->objectName().isEmpty())
            DeroulementVigenere->setObjectName(QStringLiteral("DeroulementVigenere"));
        DeroulementVigenere->resize(871, 546);
        tableWidget = new QTableWidget(DeroulementVigenere);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(17, 40, 481, 401));
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(28);
        tableWidget->horizontalHeader()->setMinimumSectionSize(15);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(21);
        tableWidget->verticalHeader()->setMinimumSectionSize(15);
        listWidget = new QListWidget(DeroulementVigenere);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(500, 40, 351, 401));
        pushButton = new QPushButton(DeroulementVigenere);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(763, 450, 83, 25));
        pushButton_2 = new QPushButton(DeroulementVigenere);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setEnabled(false);
        pushButton_2->setGeometry(QRect(673, 450, 83, 25));
        pushButton_3 = new QPushButton(DeroulementVigenere);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(583, 450, 83, 25));
        progressBar = new QProgressBar(DeroulementVigenere);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(20, 450, 561, 25));
        progressBar->setValue(24);

        retranslateUi(DeroulementVigenere);

        QMetaObject::connectSlotsByName(DeroulementVigenere);
    } // setupUi

    void retranslateUi(QWidget *DeroulementVigenere)
    {
        DeroulementVigenere->setWindowTitle(QApplication::translate("DeroulementVigenere", "Form", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        tableWidget->setAccessibleName(QApplication::translate("DeroulementVigenere", "tabText", nullptr));
#endif // QT_NO_ACCESSIBILITY
        pushButton->setText(QApplication::translate("DeroulementVigenere", "Next", nullptr));
        pushButton_2->setText(QApplication::translate("DeroulementVigenere", "Finish", nullptr));
        pushButton_3->setText(QApplication::translate("DeroulementVigenere", "Retour", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeroulementVigenere: public Ui_DeroulementVigenere {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEROULEMENTVIGENERE_H
