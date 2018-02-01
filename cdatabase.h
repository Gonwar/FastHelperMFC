#ifndef CDATABASE_H
#define CDATABASE_H

#include <QDir>
#include <QTextStream>
#include <QProcess>
#include <QMessageBox>
#include <QRegExp>
#include <QKeyEvent>

class cdatabase
{
public:
    cdatabase();
    ~cdatabase();
    QStringList readFromDB();
    QString getLastID();
    bool checkTV(QString idTV);
    void writeToDB(QStringList text);
    void editToDB(QStringList newStr);
    void deleteFromDB(QString idLine);
    QStringList searchInDB(QString search);
    void connectToTV(QString idTV);
    void reindexing();
private:
    QString *DBname = new QString("//172.18.10.208//Share//FastHelper//Database//base.db"); //Путь к базе данных
    QFile* file = new QFile(*DBname);
    void openToRead();
    void openToWrite();
    void writeAllDB(QString text);
    void writeAllDB(QStringList text);
};

#endif // CDATABASE_H
