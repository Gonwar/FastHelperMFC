#include "fasthelper.h"
#include "ui_fasthelper.h"

FastHelper::FastHelper(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FastHelper)
{
    ui->setupUi(this);
    QObject::connect(this,SIGNAL(toWrite(QStringList)),this,SLOT(writeToTable(QStringList)));
    ui->tableWidget->hideColumn(0);
    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->tableWidget->horizontalHeader()->setVisible(true);
    mainText = database.readFromDB();
    emit toWrite(mainText);
    ui->tableWidget->resizeColumnsToContents();
    QObject::connect(ui->tableWidget,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(slotCustomMenu(QPoint))); //Вызов контекстого меню
}

FastHelper::~FastHelper()
{
    delete ui;
}

//Метод получения строки из таблицы в формате QStringList
QStringList FastHelper::getRow()
{
    QStringList text;
    int row = ui->tableWidget->selectionModel()->currentIndex().row();
    int column = ui->tableWidget->columnCount();
    if(row!=-1)
    {
        for(int i=0; i<column; i++)
        {
            if(ui->tableWidget->item(row,i)!=0)
                text << ui->tableWidget->item(row,i)->text();
            else
                text << "";
        }
    }
    return text;
}

//Вызов меню on press key F1
void FastHelper::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();
    settingDialog* setting = new settingDialog();
    if(key == Qt::Key_F1)
    {
        setting->setWindowTitle("Настройки...");
        setting->show();
    }
}

//Слот для записи базы в таблицу
void FastHelper::writeToTable(QStringList text)
{
    if(ui->lineEdit->text()!= NULL)
        text = database.searchInDB(ui->lineEdit->text());
    ui->tableWidget->clearContents();
    QStringList cellL;
    QString s;
    for(int i = 0; i<text.count(); i++)
    {
        ui->tableWidget->setRowCount(text.count());
        s = text[i];
        cellL = s.split("\t");
        for(int j=0; j<cellL.count(); j++)
            ui->tableWidget->setItem(i,j,new QTableWidgetItem(cellL[j]));
    }
    ui->tableWidget->sortByColumn(1,Qt::SortOrder(0));
}

//Слот для вызова контекстного меню
void FastHelper::slotCustomMenu(QPoint pos)
{
    QMenu * menu = new QMenu(this);
    QAction * connectTV = new QAction (trUtf8("Подключиться по ТВ"), this);
    QAction * edit = new QAction (trUtf8("Редактировать"), this);
    QAction * del = new QAction (trUtf8("Удалить"), this);

    connect(connectTV, SIGNAL(triggered(bool)), this, SLOT(slotConnectTV()));
    connect(edit, SIGNAL(triggered(bool)), this, SLOT(slotEdit()));
    connect(this, SIGNAL(toGoEdit(QStringList)), dialog,SLOT(slotEdit(QStringList)));
    connect(del, SIGNAL(triggered(bool)), this, SLOT(slotDel()));

    menu->addAction(connectTV);
    menu->addAction(edit);
    menu->addAction(del);
    menu->popup(ui->tableWidget->viewport()->mapToGlobal(pos));
}

//Слот для поиска в базе по введеным данным
void FastHelper::on_lineEdit_textEdited()
{
    emit toWrite(mainText);
}

//Кнопка добавления новой записи в базу данных
void FastHelper::on_pushButton_clicked()
{
    dialog = new editDialog();
    dialog->setWindowTitle("Добавить в базу данных");
    dialog->setWindowOpacity(0.96);
    dialog->show();
    QObject::connect(dialog, SIGNAL(toWrite(QStringList)),this,SIGNAL(toWrite(QStringList)));
}

//Слот для подключения
void FastHelper::slotConnectTV()
{
    int row = ui->tableWidget->selectionModel()->currentIndex().row();
    if(row >=0 && ui->tableWidget->item(row,3) != 0 )
        database.connectToTV(ui->tableWidget->item(row,3)->text());
}

void FastHelper::slotEdit()
{
    QStringList editString = getRow();
    emit toGoEdit(editString);
    dialog->setWindowTitle("Редактировать...");
    dialog->setWindowOpacity(0.96);
    dialog->show();
    QObject::connect(dialog, SIGNAL(toWrite(QStringList)),this,SIGNAL(toWrite(QStringList)));
}

void FastHelper::slotDel()
{
    int row = ui->tableWidget->selectionModel()->currentIndex().row();
    database.deleteFromDB(ui->tableWidget->item(row,0)->text());
    mainText = database.readFromDB();
    emit toWrite(mainText);
}
