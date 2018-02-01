#include "settingdialog.h"
#include "ui_settingdialog.h"
#include <QDebug>
settingDialog::settingDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::settingDialog)
{
    ui->setupUi(this);
}

settingDialog::~settingDialog()
{
    delete ui;
}

void settingDialog::on_pushButton_4_clicked()
{
    database.reindexing();
    QMessageBox::information(0,
                          "Успех!",
                          "Переиндексация выполненна успешно!");
}

void settingDialog::on_btn_cancel_clicked()
{
    this->deleteLater();
}

void settingDialog::on_btn_OK_clicked()
{
    this->deleteLater();
}
