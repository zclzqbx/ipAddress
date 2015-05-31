#include "qipaddress.h"
#include <QMessageBox>

static bool slotCheck(QWidget *parent,QString str)
{
    if(str.isEmpty() || str.size()>3)
    {
        QMessageBox::warning(parent,QObject::tr("提示"),QObject::tr("IP地址不合理！"),QMessageBox::Ok);
        return false;
    }

    int i=0;
    for(;i<str.size();++i)
    {
        if(str.at(i)>'9' || str.at(i)<'0')
            break;
    }
    if(i<str.size())
    {
        QMessageBox::warning(parent,QObject::tr("提示"),QObject::tr("IP地址不合理！"),QMessageBox::Ok);
        return false;
    }

    int ipValue=str.toInt();
    if(ipValue>255)
    {
        QMessageBox::warning(parent,QObject::tr("提示"),QObject::tr("IP地址不合理！"),QMessageBox::Ok);
        return false;
    }
    return true;
}

QIpAddress::QIpAddress(QWidget *parent) :
    QWidget(parent)
{
    oneLabel=new QLabel(".");
    twoLabel=new QLabel(".");
    threeLabel=new QLabel(".");

    oneLineEdit=new QLineEdit;
    twoLineEdit=new QLineEdit;
    threeLineEdit=new QLineEdit;
    fourLineEdit=new QLineEdit;

    mainLayout=new QHBoxLayout(this);

    mainLayout->addWidget(oneLineEdit);
    mainLayout->addWidget(oneLabel);
    mainLayout->addWidget(twoLineEdit);
    mainLayout->addWidget(twoLabel);
    mainLayout->addWidget(threeLineEdit);
    mainLayout->addWidget(threeLabel);
    mainLayout->addWidget(fourLineEdit);

    setTabOrder(oneLineEdit,twoLineEdit);
    setTabOrder(twoLineEdit,threeLineEdit);
    setTabOrder(threeLineEdit,fourLineEdit);

    setMaximumSize(600,60);

    connect(oneLineEdit,SIGNAL(textEdited(QString)),this,SLOT(slotOneCheck(QString)));
    connect(twoLineEdit,SIGNAL(textEdited(QString)),this,SLOT(slotTwoCheck(QString)));
    connect(threeLineEdit,SIGNAL(textEdited(QString)),this,SLOT(slotThreeCheck(QString)));
    connect(fourLineEdit,SIGNAL(textEdited(QString)),this,SLOT(slotFourCheck(QString)));
}

void QIpAddress::slotOneCheck(QString str)
{
    if(!slotCheck(this,str))
    {
        oneLineEdit->clear();
    }
}

void QIpAddress::slotTwoCheck(QString str)
{
    if(!slotCheck(this,str))
    {
        twoLineEdit->clear();
    }
}

void QIpAddress::slotThreeCheck(QString str)
{
    if(!slotCheck(this,str))
    {
        threeLineEdit->clear();
    }
}

void QIpAddress::slotFourCheck(QString str)
{
    if(!slotCheck(this,str))
    {
        fourLineEdit->clear();
    }
}

QHostAddress QIpAddress::getIpAddress()
{
    QHostAddress ipAddress;
    QString ipStr=oneLineEdit->text()+twoLineEdit->text()+threeLineEdit->text()+fourLineEdit->text();
    ipAddress.setAddress(ipStr);
    return ipAddress;
}

void QIpAddress::setIpAddress(QHostAddress hostAddress)
{
    QString ipStr=hostAddress.toString();
    setIpAddress(ipStr);

}

void QIpAddress::setIpAddress(QString ipStr)
{
    QStringList spiece=ipStr.split(".",QString::SkipEmptyParts);

    oneLineEdit->setText(spiece.at(0));
    twoLineEdit->setText(spiece.at(1));
    threeLineEdit->setText(spiece.at(2));
    fourLineEdit->setText(spiece.at(3));
}
