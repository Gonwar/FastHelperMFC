#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QWidget>
#include <QSettings>
#include <cdatabase.h>

namespace Ui {
class settingDialog;
}

class settingDialog : public QWidget
{
    Q_OBJECT

public:
    explicit settingDialog(QWidget *parent = 0);
    ~settingDialog();

private slots:
    void on_pushButton_4_clicked();

    void on_btn_cancel_clicked();

    void on_btn_OK_clicked();

private:
    Ui::settingDialog *ui;
    cdatabase database;
};

#endif // SETTINGDIALOG_H
