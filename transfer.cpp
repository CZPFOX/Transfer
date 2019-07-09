#include "transfer.h"
#include <QTime>
#include <QCoreApplication>
Transfer::Transfer(QObject *parent):QObject(parent)
{
}

QSerialPort*Transfer::serialPort()
{
    return&sp;
}

void Transfer::write(const QByteArray&data)
{
    sp.write(data);
    emit signal_request(data);
}

void Transfer::write(const QByteArrayList&list,int ms)
{
    foreach(const QByteArray&data,list)
    {
        write(data);
        delay_ms(ms);
    }
}

void Transfer::delay_ms(int ms)
{
    QTime dieTime = QTime::currentTime().addMSecs(ms);
    while(QTime::currentTime() < dieTime)
    {
        QCoreApplication::processEvents(QEventLoop::ExcludeUserInputEvents);
    }
}
