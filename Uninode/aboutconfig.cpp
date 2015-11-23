#include "aboutconfig.h"
#include "mainwindow.h"
#include <QSettings>
#include <QFile>

QString AboutConfig::Username="";
QString AboutConfig::Password="";

bool AboutConfig::RememberInfo=false;
bool AboutConfig::AutoLogin=false;

int AboutConfig::IndexOfAdapter=0;


AboutConfig::AboutConfig()
{

}

//read configuration
bool AboutConfig::readConfig()
{
    QSettings *config_Ini_Read=new QSettings("config.ini",QSettings::IniFormat);
    RememberInfo=config_Ini_Read->value("/Property/Memory").toBool();
    if(RememberInfo)
    {
        Username=config_Ini_Read->value("/Authentication Information/Username").toString();
        Password=config_Ini_Read->value("/Authentication Information/Password").toString();
        if(Username!=""&&Password!="")
        {
            AutoLogin=config_Ini_Read->value("/Property/Auto").toBool();
            IndexOfAdapter=config_Ini_Read->value("/Authentication Information/Adapter").toInt();
            return true;
        }
        else return false;
    }
    else return false;
}

void AboutConfig::writeConfig(bool Auto,bool Memory)
{
    QSettings *config_Ini_Write=new QSettings("config.ini",QSettings::IniFormat);
    config_Ini_Write->setValue("/Authentication Information/Username",
                               Username);
    config_Ini_Write->setValue("/Authentication Information/Password",
                               Password);
    config_Ini_Write->setValue("/Authentication Information/Adapter",
                               IndexOfAdapter);
    config_Ini_Write->setValue("/Property/Auto",Auto);
    config_Ini_Write->setValue("/Property/Memory",Memory);
}

void AboutConfig::cleanConfig()
{
    QSettings *config_Ini_Write=new QSettings("config.ini",QSettings::IniFormat);
    config_Ini_Write->setValue("/Authentication Information/Username",
                           "");
    config_Ini_Write->setValue("/Authentication Information/Password",
                           "");
    config_Ini_Write->setValue("/Authentication Information/Adapter",
                               "");
    config_Ini_Write->setValue("/Property/Auto",false);
    config_Ini_Write->setValue("/Property/Memory",false);
}

void AboutConfig::checkConfig()
{
    QFile config("config.ini");
    if(!config.exists())
    {
        config.open( QIODevice::WriteOnly );
        config.close();
        writeConfig();
    }
}

