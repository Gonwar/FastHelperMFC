#ifndef FASTHELPER_H
#define FASTHELPER_H
#include <QDebug>
#include <QWidget>
#include <QMenu>
#include <cdatabase.h>
#include <editdialog.h>
#include <settingdialog.h>

namespace Ui {
class FastHelper;
}

class FastHelper : public QWidget
{
    Q_OBJECT

public:
    explicit FastHelper(QWidget *parent = 0);
    ~FastHelper();

private:
    Ui::FastHelper *ui;
    cdatabase database;
    QStringList mainText;
    editDialog * dialog = new editDialog();
    QStringList getRow();
    void keyPressEvent(QKeyEvent *event);

private slots:
    void writeToTable(QStringList text);
    void slotCustomMenu(QPoint pos);
    void on_lineEdit_textEdited();
    void on_pushButton_clicked();
    void slotConnectTV();
    void slotEdit();
    void slotDel();

signals:
    toWrite(QStringList text);
    toGoEdit(QStringList row);
};

#endif // FASTHELPER_H
