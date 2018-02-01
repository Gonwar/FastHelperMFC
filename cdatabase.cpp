#include "cdatabase.h"
#include <QDebug>
cdatabase::cdatabase()
{
    //Конструктор
}

cdatabase::~cdatabase()
{
    delete DBname;
    delete file;
}

//Метод чтения из базы
QStringList cdatabase::readFromDB()
{
    openToRead();
    QTextStream read(&*file);
    QString tText = read.readAll();
    QStringList text = tText.split("\n");
    text.removeLast();
    file->close();
    return text;
}

//Метод получения ID последней записи
QString cdatabase::getLastID()
{
    QString id = "0";
    QStringList tList = readFromDB();
    if(tList.count()==0)
        return id;
    id = tList.last();
    tList.clear();
    tList = id.split("\t");
    id = tList[0];
    return id;
}

//Метод проверки наличия id TeamViewer'a
bool cdatabase::checkTV(QString idTV)
{
    bool check = false;
    QStringList text = readFromDB();
    QString tString;
    QStringList tList;
    for(int i =0;i<text.count();i++){
        tString = text[i];
        tList = tString.split("\t");
        if(idTV==tList[3]){
            check = true;
            break;
        }
    }
    return check;
}

//Метод записи строки в базу данных
//Сначало новой записи присвается индивидуальный ID затем пишется введеная строка
void cdatabase::writeToDB(QStringList text)
{
    int newID = getLastID().toInt() + 1;
    QString line;
    line.setNum(newID);
    for(int i=0; i<text.count(); i++)
        line += "\t" + text[i];
    line += "\n";
    openToWrite();
    QTextStream write(&*file);
    write << line;
    file->close();
}

//Метод редактирования базы данных
void cdatabase::editToDB(QStringList newStr)
{
    QString str = newStr[0];
    for(int i=1;i<newStr.count();i++)
        str += "\t" + newStr[i];
    QStringList text = readFromDB();
    QString temp;
    for(int i=0;i<text.count();i++){
        temp = text[i];
        QStringList tLine = temp.split("\t");
        if(newStr[0]==tLine[0])
            text[i] = str;
    }
    writeAllDB(text);
}

//Метод удаления выбранной строки из базы данных
void cdatabase::deleteFromDB(QString idLine)
{
    QStringList text = readFromDB();
    for(int i=0;i<text.count();i++){
        QString tID = text[i];
        QStringList tLine = tID.split("\t");
        if(tLine[0]==idLine){
            text.removeAt(i);
            break;
        }
    }
    writeAllDB(text);
}

//Метод для поиска в базе
QStringList cdatabase::searchInDB(QString search)
{
    QStringList text = readFromDB();
    QStringList result;
    QRegExp rx(search);
    rx.setCaseSensitivity(Qt::CaseInsensitive);
    for(int i=0;i<text.count();i++){
        QString temp = text[i];
        QStringList tList = temp.split("\t");
        temp = "";
        for(int j=1;j<tList.count();j++){
            int pos = 0;
            rx.indexIn(tList[j],pos);
            if(rx.matchedLength()!=-1){
                result << text[i];
                break;
            }
        }
    }
    return result;
}

//Метод подключения к TeamViewer по выбранному ID
void cdatabase::connectToTV(QString idTV)
{
    idTV.remove(" ");
    QProcess cmd;
    const QString x86 = "C:\\Program Files\\TeamViewer\\";
    const QString x64 = "C:\\Program Files (x86)\\TeamViewer\\";
    if(QDir(x64).exists())
        cmd.startDetached("\"" + x64 + "TeamViewer.exe\" --id " + idTV + " --Password qwerty123");
    else if(QDir(x86).exists())
        cmd.startDetached("\"" + x86 + "TeamViewer.exe\" --id " + idTV + " --Password qwerty123");
    else
    {
        QMessageBox::information(0,
                              "Ошибка!",
                              "TeamViewer не найден!");
    }
}

//Метод переиндексации базы
void cdatabase::reindexing()
{
    QStringList list = readFromDB();
    //Условие для индексации базы старой версии ПО
    if(!list.isEmpty()&&list[0].count("\t")==3){
        for(int i=0;i<list.count();i++)
            list[i].prepend(QString::number(i+1)+"\t");
    }
    else{
        QStringList tList;
        QString tString;
        for(int i=0;i<list.count();i++){
            tList=list[i].split("\t");
            tString = QString::number(i+1);
            for(int i=1;i<tList.count();i++)
                tString += "\t" + tList[i];
            list[i]=tString;
        }
    }
    writeAllDB(list);
}

//Открыть базу для чтения
void cdatabase::openToRead()
{
    if(!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(0,
                              "Ошибка!",
                              "Не удалось открыть базу данных!");
    }
}

//Открыть базу для записи
void cdatabase::openToWrite()
{
    if(!file->open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        QMessageBox::information(0,
                              "Ошибка!",
                              "Не удалось открыть базу данных!");
    }
}

//Записать данные в файл
void cdatabase::writeAllDB(QString text)
{
    openToWrite();
    QTextStream write(&*file);
    file->resize(0);
    write.seek(0);
    write<<text;
    file->close();
}

//Записать данные в файл
void cdatabase::writeAllDB(QStringList text)
{
    openToWrite();
    QTextStream write(&*file);
    file->resize(0);
    write.seek(0);
    for(int i=0;i<text.count();i++)
        write<<text[i] + "\n";
    file->close();
}


