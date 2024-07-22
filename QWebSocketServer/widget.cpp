#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    server=new QWebSocketServer(QStringLiteral("WebServer"),QWebSocketServer::NonSecureMode);

    connect(server,&QWebSocketServer::newConnection,this,&Widget::newconnection);

    server->listen(QHostAddress::Any,6666);
    ui->radioButton_all->setChecked(1);
}

Widget::~Widget()
{
    delete ui;

    for(auto i:list)
    {
        i->close();
    }
    server->close();
}

void Widget::on_pushButton_clicked()
{
    QString info=ui->textEdit_mes->toPlainText().trimmed();
    ui->textEdit_mes->clear();

    if(info.isEmpty())return;

    if(ui->radioButton_all->isChecked())
    {
        for(auto s:list)
        {
            s->sendTextMessage(info);
        }
        ui->textEdit_get->append("服务器群发:"+info);
    }
    else
    {
        if(!ui->listWidget->currentItem())return;
        QString name=ui->listWidget->currentItem()->text();
        for(auto s:list)
        {
            if(s->origin()==name)
            {
                s->sendTextMessage(info);
                ui->textEdit_get->append("服务器群发:"+info);
                break;
            }
        }
    }
}

void Widget::newconnection()
{
    if(server->hasPendingConnections())
    {
        QWebSocket *socket=server->nextPendingConnection();

        ui->textEdit_get->append("客户端"+socket->origin()+"已连接至服务器");

        list<<socket;
        QListWidgetItem *item=new QListWidgetItem;
        item->setText(socket->origin());
        ui->listWidget->addItem(item);

        connect(socket,&QWebSocket::disconnected,[socket,this]{
            ui->textEdit_get->append("客户端"+socket->origin()+"已断开连接");

            list.removeOne(socket);

            for(int i=0;i<ui->listWidget->count();i++)
            {
                QListWidgetItem *item=ui->listWidget->item(i);
                if(item->text()==socket->origin())
                {
                    ui->listWidget->removeItemWidget(item);
                    delete item;
                    break;
                }
            }
            socket->deleteLater();
        });

        connect(socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(diserror(QAbstractSocket::SocketError)));
        connect(socket,&QWebSocket::textMessageReceived,this,&Widget::receiveMsg);
    }
}


void Widget::receiveMsg(const QString &message)
{
    QJsonDocument doc=QJsonDocument::fromJson(message.toLatin1().data());

    if(doc.isNull())
    {
        QWebSocket *soc=qobject_cast<QWebSocket*>(sender());
        ui->textEdit_get->append("收到["+soc->origin()+"]的消息:"+message);
    }
    else
    {
        QJsonObject jdo=doc.object();
        QString dst=jdo["dst:"].toString();

        for(auto s:list)
        {
            if(dst==s->origin())
            {
                s->sendTextMessage(message);
                break;
            }
        }
    }
}


void Widget::diserror(QAbstractSocket::SocketError error)
{
    QWebSocket *socket=qobject_cast<QWebSocket*>(sender());
    ui->textEdit_get->append(socket->origin()+"出错:"+socket->errorString());
}

