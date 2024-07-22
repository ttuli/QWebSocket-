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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit_get;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton_all;
    QRadioButton *radioButton_single;
    QPushButton *pushButton;
    QTextEdit *textEdit_mes;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listWidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        verticalLayout_4 = new QVBoxLayout(Widget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName("groupBox");
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName("horizontalLayout");
        textEdit_get = new QTextEdit(groupBox);
        textEdit_get->setObjectName("textEdit_get");

        horizontalLayout->addWidget(textEdit_get);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName("groupBox_2");
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        radioButton_all = new QRadioButton(groupBox_2);
        radioButton_all->setObjectName("radioButton_all");

        horizontalLayout_2->addWidget(radioButton_all);

        radioButton_single = new QRadioButton(groupBox_2);
        radioButton_single->setObjectName("radioButton_single");

        horizontalLayout_2->addWidget(radioButton_single);

        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_2);

        textEdit_mes = new QTextEdit(groupBox_2);
        textEdit_mes->setObjectName("textEdit_mes");

        verticalLayout->addWidget(textEdit_mes);


        verticalLayout_3->addWidget(groupBox_2);

        verticalLayout_3->setStretch(0, 2);
        verticalLayout_3->setStretch(1, 1);

        horizontalLayout_3->addLayout(verticalLayout_3);

        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName("groupBox_3");
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setObjectName("verticalLayout_2");
        listWidget = new QListWidget(groupBox_3);
        listWidget->setObjectName("listWidget");

        verticalLayout_2->addWidget(listWidget);


        horizontalLayout_3->addWidget(groupBox_3);

        horizontalLayout_3->setStretch(0, 3);
        horizontalLayout_3->setStretch(1, 1);

        verticalLayout_4->addLayout(horizontalLayout_3);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "\346\266\210\346\201\257\345\210\227\350\241\250", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "\345\217\221\351\200\201\346\266\210\346\201\257", nullptr));
        radioButton_all->setText(QCoreApplication::translate("Widget", "\347\276\244\345\217\221\346\211\200\346\234\211", nullptr));
        radioButton_single->setText(QCoreApplication::translate("Widget", "\347\247\201\345\217\221\345\256\242\346\210\267\347\253\257", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Widget", "\345\256\242\346\210\267\347\253\257\345\210\227\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
