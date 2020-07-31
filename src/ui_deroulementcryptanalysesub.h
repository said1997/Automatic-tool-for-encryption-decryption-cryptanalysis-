/********************************************************************************
** Form generated from reading UI file 'deroulementcryptanalysesub.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEROULEMENTCRYPTANALYSESUB_H
#define UI_DEROULEMENTCRYPTANALYSESUB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_deroulementcryptanalysesub
{
public:
    QTableWidget *tableWidget;
    QListWidget *listWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *deroulementcryptanalysesub)
    {
        if (deroulementcryptanalysesub->objectName().isEmpty())
            deroulementcryptanalysesub->setObjectName(QStringLiteral("deroulementcryptanalysesub"));
        deroulementcryptanalysesub->resize(911, 506);
        tableWidget = new QTableWidget(deroulementcryptanalysesub);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(45, 20, 431, 421));
        listWidget = new QListWidget(deroulementcryptanalysesub);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(485, 20, 421, 421));
        pushButton = new QPushButton(deroulementcryptanalysesub);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(820, 450, 83, 25));
        pushButton_2 = new QPushButton(deroulementcryptanalysesub);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(730, 450, 83, 25));

        retranslateUi(deroulementcryptanalysesub);

        QMetaObject::connectSlotsByName(deroulementcryptanalysesub);
    } // setupUi

    void retranslateUi(QWidget *deroulementcryptanalysesub)
    {
        deroulementcryptanalysesub->setWindowTitle(QApplication::translate("deroulementcryptanalysesub", "Form", nullptr));
        pushButton->setText(QApplication::translate("deroulementcryptanalysesub", "Next", nullptr));
        pushButton_2->setText(QApplication::translate("deroulementcryptanalysesub", "Finish", nullptr));
    } // retranslateUi

};

namespace Ui {
    class deroulementcryptanalysesub: public Ui_deroulementcryptanalysesub {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEROULEMENTCRYPTANALYSESUB_H
