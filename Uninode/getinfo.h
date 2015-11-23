#ifndef GETINFO_H
#define GETINFO_H

#include <string>
#include <QStringList>

using namespace std;

class GetInfo
{
public:
    GetInfo();

    QStringList AdapterName;
    QStringList AdapterDescription;
};

#endif // GETINFO_H
