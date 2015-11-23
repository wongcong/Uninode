#ifndef ABOUTCONFIG_H
#define ABOUTCONFIG_H

#include "mainwindow.h"
class AboutConfig
{
public:
    AboutConfig();

    static QString Username;
    static QString Password;

    static bool RememberInfo;
    static bool AutoLogin;

    static int IndexOfAdapter;

    static bool readConfig();
    static void writeConfig(bool Auto=false,bool Memory=false);
    static void cleanConfig();
    static void checkConfig();
};

#endif // ABOUTCONFIG_H
