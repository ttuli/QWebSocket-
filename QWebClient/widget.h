#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QAbstractSocket>
#include <QWebSocket>
#include <QJsonDocument>
#include <QJsonObject>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_connect_clicked();

    void on_pushButton_send_clicked();

private:
    Ui::Widget *ui;

    void receiveMsg(const QString &msg);
    QWebSocket *socket;
    bool isconnect=false;

    void disError(QAbstractSocket::SocketError error);

};
#endif // WIDGET_H
