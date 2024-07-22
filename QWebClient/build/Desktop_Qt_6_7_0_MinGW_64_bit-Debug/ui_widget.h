/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_ip;
    QLabel *label_2;
    QLineEdit *lineEdit_name;
    QPushButton *pushButton_connect;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *textEdit_get;
    QTextEdit *textEdit_mes;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_toSomeone;
    QPushButton *pushButton_send;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(840, 600);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(Widget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        lineEdit_ip = new QLineEdit(Widget);
        lineEdit_ip->setObjectName("lineEdit_ip");

        horizontalLayout->addWidget(lineEdit_ip);

        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        lineEdit_name = new QLineEdit(Widget);
        lineEdit_name->setObjectName("lineEdit_name");

        horizontalLayout->addWidget(lineEdit_name);

        pushButton_connect = new QPushButton(Widget);
        pushButton_connect->setObjectName("pushButton_connect");

        horizontalLayout->addWidget(pushButton_connect);


        verticalLayout->addLayout(horizontalLayout);

        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName("groupBox");
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        textEdit_get = new QTextEdit(groupBox);
        textEdit_get->setObjectName("textEdit_get");

        horizontalLayout_2->addWidget(textEdit_get);


        verticalLayout->addWidget(groupBox);

        textEdit_mes = new QTextEdit(Widget);
        textEdit_mes->setObjectName("textEdit_mes");

        verticalLayout->addWidget(textEdit_mes);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        lineEdit_toSomeone = new QLineEdit(Widget);
        lineEdit_toSomeone->setObjectName("lineEdit_toSomeone");

        horizontalLayout_3->addWidget(lineEdit_toSomeone);

        pushButton_send = new QPushButton(Widget);
        pushButton_send->setObjectName("pushButton_send");
        pushButton_send->setMinimumSize(QSize(0, 30));

        horizontalLayout_3->addWidget(pushButton_send);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 2);
        horizontalLayout_3->setStretch(3, 1);

        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(1, 4);
        verticalLayout->setStretch(2, 1);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200", nullptr));
        lineEdit_ip->setText(QCoreApplication::translate("Widget", "ws://192.168.10.13:6666", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\346\234\215\345\212\241\345\231\250\345\220\215\347\247\260", nullptr));
        pushButton_connect->setText(QCoreApplication::translate("Widget", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "\346\266\210\346\201\257\345\210\227\350\241\250", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\347\247\201\350\201\212\347\273\231:", nullptr));
        pushButton_send->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201\346\266\210\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
