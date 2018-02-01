#include "editdialog.h"
#include "ui_editdialog.h"
#include <QDebug>
editDialog::editDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::editDialog)
{
    ui->setupUi(this);
}

editDialog::~editDialog()
{
    delete ui;
}

void editDialog::on_btn_ok_clicked()
{
    if(!edit)
        line.clear();
    line << ui->nameLedit->text() << ui->phoneLedit->text() << ui->tvLedit->text() << ui->noteLedit->text();
    if(edit)
    {
        database.editToDB(line);
        QStringList text = database.readFromDB();
        emit toWrite(text);
        editDialog::close();
    }
    else
    {
        if(!database.checkTV(ui->tvLedit->text())){
            database.writeToDB(line);
            QStringList text = database.readFromDB();
            emit toWrite(text);
            editDialog::close();
        }
        else
            QMessageBox::information(0,
                                  "Внимание!",
                                  "Запись с таким id TeamViewer'a уже имеется!");
    }
}

void editDialog::slotEdit(QStringList text)
{
    edit = true;
    line.clear();
    line << text[0];
    ui->nameLedit->setText(text[1]);
    ui->phoneLedit->setText(text[2]);
    ui->tvLedit->setText(text[3]);
    ui->noteLedit->setText(text[4]);
}
