#ifndef QIPADDRESS_H
#define QIPADDRESS_H

#include <QWidget>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QLabel>
#include <QHostAddress>

class QIpAddress : public QWidget
{
    Q_OBJECT

public:
    QIpAddress(QWidget *parent = 0);
    QHostAddress getIpAddress();
    void setIpAddress(QHostAddress);
    void setIpAddress(QString);

private slots:
    void slotOneCheck(QString);
    void slotTwoCheck(QString);
    void slotThreeCheck(QString);
    void slotFourCheck(QString);


private:
    QLineEdit *oneLineEdit;
    QLineEdit *twoLineEdit;
    QLineEdit *threeLineEdit;
    QLineEdit *fourLineEdit;

    QLabel *oneLabel;
    QLabel *twoLabel;
    QLabel *threeLabel;

    QHBoxLayout *mainLayout;
};

#endif
