#include "connection.h"
#include<QDebug>
#include <QInputDialog>
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("source_projet2A");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("oracle");//inserer mot de passe de cet utilisateur
if (db.open())
test=true;





    return  test;
}

void Connection::closeConnection(){db.close();}
