#ifndef TRANSFER_H
#define TRANSFER_H
#include <QSerialPort>
class Transfer : public QObject
{
    Q_OBJECT
public:
    explicit Transfer(QObject *parent=nullptr);
    QSerialPort*serialPort();
    void write(const QByteArray&data);
    void write(const QByteArrayList&,int ms=20);
signals:
    void signal_request(const QByteArray&data);
    void signal_response(const QByteArray&data);
private slots:
    void slot_read();
private:
    QSerialPort sp;
    void delay_ms(int ms);
};

#endif // TRANSFER_H
