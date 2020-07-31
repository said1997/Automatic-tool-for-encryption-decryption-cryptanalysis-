#include "ResultWindow.h"
#include "EncryptWindow.h"
#include "QCheckBox"
#include <QTableWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QGridLayout>
#include <DecryptWindow.h>
#include"gestfichier.h"
#include <MainWindow.h>
#include <QString>
#include <iostream>
#include <QLineEdit>
#include <QString>
#include <iostream>
#include <QLineEdit>
#include <QSignalMapper>
#include <chrono>
#include <thread>
#include <limits>
#include <QScrollBar>
#include <QFileDialog>
#include <QMessageBox>

#define DEBUT 310
#define FIN 50

using namespace std;

resultwindow::resultwindow(QString txt) : QWidget()
{
    setStyleSheet("QPushButton { background-color: yellow } QTabWidget::hover { background-color: red } QPushButton:hover { background-color: red } ");

    for(int i = 0; i < 26 ; i++)
    {
        alphabet[i] = 65 + i;
    }
    setFixedSize(900, 500);
    onglets = new QTabWidget(this);
    onglets->setGeometry(10, 10, 880, 480);

    //texte de la fenetre
    this->setWindowTitle("Outil automatique d'aide au décryptage");

    setTextCrypte(txt);

    char* letter = (char*) malloc(1 * sizeof(char*));
    letter[0] = 64;
    letter[1] = '\0';
    for(int i = 0; i < 26 ; i++)
    {
        letter[0]+= 1;
        lines[i] = new QLineEdit(letter,this);
        if(i<13)
            lines[i]->setGeometry(DEBUT+(i*30)-50, FIN, 30, 30);
        else
            lines[i]->setGeometry(DEBUT+((i-13)*30)-50, FIN+30 , 30, 30);
        lines[i]->setMaxLength(1);
        lines[i]->setAlignment(Qt::AlignCenter);
        connect(lines[i], &QLineEdit::textChanged, [this,i](){ modify_char(i,lines[i]->text()); });
    }
    edit = new QTextEdit(this); // assuming this is your text edit
    QScrollBar *sb = edit->verticalScrollBar();
    sb->setValue(sb->maximum());
    edit->setGeometry(160, 120 , 600, 300);
    edit->setText(txt);

    QPushButton* btn_un = new QPushButton(QString::fromWCharArray(L"\u27f3").toStdString().c_str(),this);
    btn_un->setGeometry(DEBUT+350, FIN+15, 35, 35);

    QPushButton* btn_cinq = new QPushButton(QString::fromWCharArray(L"\u25C2").toStdString().c_str(),this);
    btn_cinq->setGeometry(20, 20, 20, 24);

    QObject::connect(btn_un, SIGNAL(clicked()), this, SLOT(reset()));

    QPushButton* btn_deux = new QPushButton("Export",this);
    btn_deux->setGeometry(660, 425 , 100, 30);


    //QPushButton* btn_trois = new QPushButton(QString::fromWCharArray(L"\u23EA").toStdString().c_str(),this);
    QPushButton* btn_trois = new QPushButton(QString::fromWCharArray(L"\u2A2F").toStdString().c_str(),this); //25B8
    btn_trois->setGeometry(42, 20, 20, 24);

    free(letter);

    QObject::connect(btn_deux, SIGNAL(clicked()), this, SLOT(save()));
    QObject::connect(btn_trois, SIGNAL(clicked()), this, SLOT(back_home()));
    QObject::connect(btn_cinq, SIGNAL(clicked()), this, SLOT(retour()));

    this->setAttribute(Qt::WA_DeleteOnClose);

}

void resultwindow::setType(int i)
{
    type=i;
}

void resultwindow::retour()
{
    if(type==1)
    {
        this->setAttribute(Qt::WA_DeleteOnClose);
        QWidget::hide();
        encryptwindow* my_window = new encryptwindow();
        //my_window->setCurrent();
        my_window-> show();
        //resultwindow::~resultwindow();
    }
    else
    if(type==2)
    {
        this->setAttribute(Qt::WA_DeleteOnClose);

        QWidget::close();
        decryptwindow* my_window = new decryptwindow();
        //my_window->setCurrent();
        my_window-> show();
       // resultwindow::~resultwindow();
    }
}

void resultwindow::save()
{
    QMessageBox msgBox;
    msgBox.setText(tr("Sous quel format voudriez vous enregistrer votre fichier ?"));
    QAbstractButton* pdf = msgBox.addButton(tr("PDF"), QMessageBox::YesRole);
    QAbstractButton* word = msgBox.addButton(tr("WORD"), QMessageBox::YesRole);
    QAbstractButton* txt = msgBox.addButton(tr("TXT"), QMessageBox::YesRole);
    msgBox.addButton(tr("Annulé"), QMessageBox::NoRole);

    msgBox.exec();

    if (msgBox.clickedButton()== pdf)
    {
        exportPdf(edit->toPlainText().toStdString());
    }
    else if (msgBox.clickedButton()== word)
    {
        QString filename =  QFileDialog::getSaveFileName(
                      this,
                      "Save Document",
                      QDir::currentPath(),
                      "Document files (*.doc *.txt)");

        if( !filename.isNull() )
        {
            exportWord(edit->toPlainText().toStdString(),filename.toStdString(),"");
        }

    }
    else if (msgBox.clickedButton()== txt)
    {
        QString filename =  QFileDialog::getSaveFileName(
                      this,
                      "Save Document",
                      QDir::currentPath(),
                      "Document files (*.doc *.txt)");

        if( !filename.isNull() )
        {
            exportTxt(edit->toPlainText().toStdString(),filename.toStdString(),"");
        }
    }


}

void resultwindow::setTextCrypte(QString txt)
{
    this->texte_crypte = txt;
}

void resultwindow::modify_text(string texte, char ancien, char nouveau)
{
    for(int i = 0; i < (int)texte.length(); i++)
    {
        if(texte[i] == ancien)
            texte[i] = nouveau;

        else if(texte[i] == nouveau)
            texte[i] = ancien;
    }
    edit->setText(QString::fromStdString(texte));
}

void resultwindow::modify_char(int i, QString nouveau)
{
    string temp = nouveau.toStdString();
    string tmp;

    if(!isupper(temp[0]))
    {
        temp[0] = (char) ((int)temp[0] - 32);
        lines[i]->setText(QString::fromStdString(temp));
    }
    if(!isalpha(temp[0]) || !isupper(temp[0]))
    {
        temp[0] = alphabet[i];
        lines[i]->setText(QString::fromStdString(temp));

        return;
    }

    for(int j = 0; j < 26; j++)
    {
        if(j == i)
            continue;
        temp = lines[j]->text().toStdString();
        if(temp == nouveau.toStdString())
        {
            temp[0] = alphabet[i];
            lines[j]->setText(QString::fromStdString(temp));
            temp = nouveau.toStdString();
            break;
        }
    }
    cout << "\n" << i << endl;
    cout << "=> Ancien Carctère : " << (char)alphabet[i] << endl;
    cout << "=> Nouveau Caractère : " << qPrintable(nouveau) << endl;
    resultwindow::modify_text(edit->toPlainText().toStdString(),alphabet[i],temp[0]);
    temp = nouveau.toStdString();
    alphabet[i] = temp[0];

    int ascii = 0;
    for(int k = 0; k < 26 ; k++)
    {
        if(lines[k]->text().toStdString()[0] == '\0')
        {
            for(int i = 0; i < 26 ; i++)
            {
                tmp = lines[i]->text().toStdString();
                ascii+= (int)tmp[0];
            }
            tmp[0] = (char) (2015-ascii);
            lines[k]->setText(QString::fromStdString(tmp));
        }
    }
}

void resultwindow::reset()
{
    char* letter = (char*) malloc(1 * sizeof(char*));
    letter[0] = 64;
    letter[1] = '\0';
    for(int i = 0; i < 26 ; i++)
    {
        letter[0]+= 1;
        QString qstr(letter);
        lines[i]->setText(qstr);
    }
    edit->setText(this->texte_crypte);
}

void resultwindow::back_home()
{
    this->setAttribute(Qt::WA_DeleteOnClose);

    QWidget::hide();
    mainwindow* my_window = new mainwindow();
    my_window->show();
    //resultwindow::~resultwindow();
}
resultwindow::~resultwindow()
{
    delete this->edit;
}
//LASAINTVALENTINLACTEDESAMOUREUXUNECTETRSANZIENNEQUIAPRISUNEIMPORTANZEPARTIZULIREZESDERNIRESANNESLESCRANAISOCCRENTUNPETITZADEAULEURAMOUREUXZEPETITZADEAUPEUTTREUNBOUQUETDECLEURSUNBIJOUOUUNESORTIEOUBIENLESTROISLACOISADPENDVRAIMENTDESGENSDESGOTSDELIMAGINATIONETDESMOYENSDEZHAZUNZELAPEUTTREUNESOIREROMANTIQUEDANSUNRESTAURANTAVEZVUESURLASEINEPOURLESUNSUNSIMPLEBAISERZHANGSOUSUNPORZHEPOURLESAUTRESZESTZEQUICAITPEUTTRELESUZZSDEZETTECTERIENNESTDZIDZHAZUNCAITZOMMEILVEUTETZONTRAIREMENTLAPLUPARTDESCTESZOMMEPQUESNOLOULENOUVELANZESTUNECTEQUINESECTEPASENCAMILLEPASQUESTIONDEMMENERLESENCANTSZEJOURLZESTLANOUNOUQUISENOZZUPEETZEUXQUINONTPASDEPETITAMIETBIENILSONTLEZHOIXENTRESORTIRENTREZLIBATAIRESOUTENIRLAZHANDELLEETZHEFVOUSZESTZOMMENTZOMMENTCTETONLASAINTVALENTINOCCREFVOUSDESCLEURSOUAUTREZHOSEZETTECTEEXISTETELLEAUSSIDANSVOTREPAYS
//ZMWMRANDMZKANRAZMSNKXKWMIJLPKLFLAKSNKNPWMAHRKAAKOLRMVPRWLAKRIVJPNMAHKVMPNRHLZRPKHKWXKPARPKWMAAKWZKWSPMAMRWJSSPKANLAVKNRNHMXKMLZKLPMIJLPKLFHKVKNRNHMXKMLVKLNNPKLATJLOLKNXKSZKLPWLATRUJLJLLAKWJPNRKJLTRKAZKWNPJRWZMSJRWMXVKAXDPMRIKANXKWYKAWXKWYJNWXKZRIMYRAMNRJAKNXKWIJGKAWXKHBMHLAHKZMVKLNNPKLAKWJRPKPJIMANROLKXMAWLAPKWNMLPMANMDKHDLKWLPZMWKRAKVJLPZKWLAWLAWRIVZKTMRWKPHBMAYWJLWLAVJPHBKVJLPZKWMLNPKWHKWNHKOLRSMRNVKLNNPKZKWLHHWXKHKNNKSNKPRKAAKWNXHRXHBMHLASMRNHJIIKRZDKLNKNHJANPMRPKIKANZMVZLVMPNXKWSNKWHJIIKVOLKWAJZJLZKAJLDKZMAHKWNLAKSNKOLRAKWKSNKVMWKASMIRZZKVMWOLKWNRJAXKIIKAKPZKWKASMANWHKUJLPZHKWNZMAJLAJLOLRWKAJHHLVKKNHKLFOLRAJANVMWXKVKNRNMIRKNTRKARZWJANZKHBJRFKANPKWJPNRPKANPKHZRTMNMRPKWJLNKARPZMHBMAXKZZKKNHBKCDJLWHKWNHJIIKANHJIIKANSNKNJAZMWMRANDMZKANRAJSSPKCDJLWXKWSZKLPWJLMLNPKHBJWKHKNNKSNKKFRWNKNKZZKMLWWRXMAWDJNPKVMGW
