/********************************************************************************
** Form generated from reading UI file 'editdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITDIALOG_H
#define UI_EDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_editDialog
{
public:
    QGridLayout *gridLayout;
    QPushButton *btn_cancel;
    QPushButton *btn_ok;
    QLabel *label_4;
    QLineEdit *noteLedit;
    QLineEdit *tvLedit;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *phoneLedit;
    QLineEdit *nameLedit;

    void setupUi(QWidget *editDialog)
    {
        if (editDialog->objectName().isEmpty())
            editDialog->setObjectName(QStringLiteral("editDialog"));
        editDialog->resize(400, 177);
        gridLayout = new QGridLayout(editDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btn_cancel = new QPushButton(editDialog);
        btn_cancel->setObjectName(QStringLiteral("btn_cancel"));

        gridLayout->addWidget(btn_cancel, 4, 2, 1, 1);

        btn_ok = new QPushButton(editDialog);
        btn_ok->setObjectName(QStringLiteral("btn_ok"));

        gridLayout->addWidget(btn_ok, 4, 0, 1, 1);

        label_4 = new QLabel(editDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        noteLedit = new QLineEdit(editDialog);
        noteLedit->setObjectName(QStringLiteral("noteLedit"));

        gridLayout->addWidget(noteLedit, 3, 1, 1, 2);

        tvLedit = new QLineEdit(editDialog);
        tvLedit->setObjectName(QStringLiteral("tvLedit"));

        gridLayout->addWidget(tvLedit, 2, 1, 1, 2);

        label_3 = new QLabel(editDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(editDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(editDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        phoneLedit = new QLineEdit(editDialog);
        phoneLedit->setObjectName(QStringLiteral("phoneLedit"));

        gridLayout->addWidget(phoneLedit, 1, 1, 1, 2);

        nameLedit = new QLineEdit(editDialog);
        nameLedit->setObjectName(QStringLiteral("nameLedit"));

        gridLayout->addWidget(nameLedit, 0, 1, 1, 2);

        QWidget::setTabOrder(nameLedit, phoneLedit);
        QWidget::setTabOrder(phoneLedit, tvLedit);
        QWidget::setTabOrder(tvLedit, noteLedit);
        QWidget::setTabOrder(noteLedit, btn_ok);
        QWidget::setTabOrder(btn_ok, btn_cancel);

        retranslateUi(editDialog);
        QObject::connect(btn_cancel, SIGNAL(clicked()), editDialog, SLOT(deleteLater()));

        QMetaObject::connectSlotsByName(editDialog);
    } // setupUi

    void retranslateUi(QWidget *editDialog)
    {
        editDialog->setWindowTitle(QApplication::translate("editDialog", "Form", Q_NULLPTR));
        btn_cancel->setText(QApplication::translate("editDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", Q_NULLPTR));
        btn_ok->setText(QApplication::translate("editDialog", "\320\236\320\272", Q_NULLPTR));
        label_4->setText(QApplication::translate("editDialog", "\320\224\320\276\320\277. \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217:", Q_NULLPTR));
        label_3->setText(QApplication::translate("editDialog", "ID TeamViewer:", Q_NULLPTR));
        label_2->setText(QApplication::translate("editDialog", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275:", Q_NULLPTR));
        label->setText(QApplication::translate("editDialog", "\320\230\320\274\321\217/\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class editDialog: public Ui_editDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITDIALOG_H
