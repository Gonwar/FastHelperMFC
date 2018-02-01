/********************************************************************************
** Form generated from reading UI file 'settingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGDIALOG_H
#define UI_SETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settingDialog
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *btn_OK;
    QPushButton *btn_selectPath;
    QPushButton *btn_cancel;
    QPushButton *pushButton_4;

    void setupUi(QWidget *settingDialog)
    {
        if (settingDialog->objectName().isEmpty())
            settingDialog->setObjectName(QStringLiteral("settingDialog"));
        settingDialog->resize(352, 157);
        gridLayout = new QGridLayout(settingDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 1, 1, 1);

        label = new QLabel(settingDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(settingDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setReadOnly(true);

        gridLayout->addWidget(lineEdit, 1, 0, 1, 2);

        btn_OK = new QPushButton(settingDialog);
        btn_OK->setObjectName(QStringLiteral("btn_OK"));

        gridLayout->addWidget(btn_OK, 6, 0, 1, 1);

        btn_selectPath = new QPushButton(settingDialog);
        btn_selectPath->setObjectName(QStringLiteral("btn_selectPath"));

        gridLayout->addWidget(btn_selectPath, 1, 2, 1, 1);

        btn_cancel = new QPushButton(settingDialog);
        btn_cancel->setObjectName(QStringLiteral("btn_cancel"));

        gridLayout->addWidget(btn_cancel, 6, 2, 1, 1);

        pushButton_4 = new QPushButton(settingDialog);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 4, 1, 1, 1);

        QWidget::setTabOrder(lineEdit, btn_selectPath);
        QWidget::setTabOrder(btn_selectPath, pushButton_4);
        QWidget::setTabOrder(pushButton_4, btn_OK);
        QWidget::setTabOrder(btn_OK, btn_cancel);

        retranslateUi(settingDialog);

        QMetaObject::connectSlotsByName(settingDialog);
    } // setupUi

    void retranslateUi(QWidget *settingDialog)
    {
        settingDialog->setWindowTitle(QApplication::translate("settingDialog", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", Q_NULLPTR));
        label->setText(QApplication::translate("settingDialog", "\320\237\321\203\321\202\321\214 \320\272 \320\261\320\260\320\267\320\265:", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("settingDialog", "\320\237\320\276\320\272\320\260 \320\275\320\265 \321\200\320\260\320\261\320\276\321\202\320\260\320\265\321\202!!!", Q_NULLPTR));
        btn_OK->setText(QApplication::translate("settingDialog", "\320\236\320\232", Q_NULLPTR));
        btn_selectPath->setText(QApplication::translate("settingDialog", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214", Q_NULLPTR));
        btn_cancel->setText(QApplication::translate("settingDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("settingDialog", "\320\237\320\265\321\200\320\265\320\270\320\275\320\264\320\265\320\272\321\201\320\260\321\206\320\270\321\217 \320\261\320\260\320\267\321\213 \320\264\320\260\320\275\320\275\321\213\321\205", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class settingDialog: public Ui_settingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGDIALOG_H
