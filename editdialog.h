#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QWidget>
#include <cdatabase.h>

namespace Ui {
class editDialog;
}

class editDialog : public QWidget
{
    Q_OBJECT

public:
    explicit editDialog(QWidget *parent = 0);
    ~editDialog();

private:
    Ui::editDialog *ui;
    cdatabase database;
    QStringList line;
    bool edit = false;

private slots:
    void on_btn_ok_clicked();
    void slotEdit(QStringList text);

signals:
    toWrite(QStringList text);
};

#endif // EDITDIALOG_H
