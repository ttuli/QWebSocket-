#include "widget.h"
#include<QMessageBox>
#include<QHostAddress>
#include<QDebug>
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    socket=nullptr;
    connect(socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(disError(QAbstractSocket::SocketError)));

}

Widget::~Widget()
{
    delete ui;
    if(socket)
        socket->close();
}

void Widget::receiveMsg(const QString &msg)
{
    QJsonDocument jsd=QJsonDocument::fromJson(msg.toUtf8().data());

    if(jsd.isNull())
    {
        ui->textEdit_get->append("收到消息:"+msg);
    }
    else
    {
        QJsonObject jo=jsd.object();
        ui->textEdit_get->append("收到来自"+jo["SRC"].toString()+"的消息:"+jo["MSG"].toString());
    }
}

void Widget::disError(QAbstractSocket::SocketError error)
{
    QWebSocket *socket=qobject_cast<QWebSocket*>(sender());
    ui->textEdit_get->append(socket->origin()+"出错:"+socket->errorString());
}

void Widget::on_pushButton_connect_clicked()
{
    if(!socket)
    {
        if(ui->lineEdit_name->text().isEmpty())
        {
            QMessageBox::critical(this,"错误","服务器名称不能为空",QMessageBox::Yes);
            return;
        }

        socket=new QWebSocket(ui->lineEdit_name->text().trimmed(),QWebSocketProtocol::VersionLatest);
        connect(socket,&QWebSocket::connected,this,[this]{
            ui->textEdit_get->append("已连接"+socket->peerAddress().toString());
            isconnect=true;
            ui->pushButton_connect->setText("断开连接");
        });

        connect(socket,&QWebSocket::disconnected,this,[this]{
            ui->textEdit_get->append("已断开"+socket->peerAddress().toString());
            isconnect=false;
            ui->pushButton_connect->setText("连接");
        });

        connect(socket,&QWebSocket::textMessageReceived,this,&Widget::receiveMsg);
    }



    if(isconnect)
    {
        socket->close();
        socket->deleteLater();
        socket=nullptr;
    }
    else
        socket->open(QUrl(ui->lineEdit_ip->text().trimmed()));
}


void Widget::on_pushButton_send_clicked()
{
    if(!socket->isValid())return;

    QString str=ui->textEdit_mes->toPlainText().trimmed();
    if(str.isEmpty())return;

    QString sname=ui->lineEdit_toSomeone->text().trimmed();
    if(sname.isEmpty())
    {
        socket->sendTextMessage(str);
        ui->textEdit_get->append("发送消息:"+str);
    }
    else
    {
        QJsonObject job;
        job["src"]=socket->origin();
        job["dst"]=sname;
        job["msg"]=str;
        socket->sendTextMessage(QString(QJsonDocument(job).toJson(QJsonDocument::Compact)));
        ui->textEdit_get->append("给客户端"+sname+"发送:"+str);
    }
    ui->textEdit_mes->clear();
}

