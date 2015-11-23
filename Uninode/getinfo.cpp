#include "getinfo.h"
#include <QLibrary>
#include <winsock2.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <QMessageBox>
#include <QString>
#include <QByteArray>

using namespace std;


//call IPHLAPI to get adpters info like name and descriotion
GetInfo::GetInfo()
{
        IP_ADAPTER_INFO   *pAdapterInfo;
        ULONG             ulOutBufLen;
        DWORD             dwRetVal;
        PIP_ADAPTER_INFO pAdapter;

        pAdapterInfo = (IP_ADAPTER_INFO *)malloc(sizeof(IP_ADAPTER_INFO));
        ulOutBufLen = sizeof(IP_ADAPTER_INFO);
        if (GetAdaptersInfo(pAdapterInfo, &ulOutBufLen) != ERROR_SUCCESS) {
            free(pAdapterInfo);
            pAdapterInfo = (IP_ADAPTER_INFO *)malloc(ulOutBufLen);
        }
        if ((dwRetVal = GetAdaptersInfo(pAdapterInfo, &ulOutBufLen)) != ERROR_SUCCESS) {
            //printf("GetAdaptersInfo call failed with %d\n", dwRetVal);
            string str="GetAdaptersInfo call failed with " + dwRetVal;
            QMessageBox::warning(NULL,"Error","Adapters "+QString::fromStdString(str)+"Error!");
        }
        pAdapter = pAdapterInfo;
        while (pAdapter) {
            QString tempS;
            QByteArray tempB;
            //printf("Adapter Name: %s\n", pAdapter->AdapterName);
            tempS=pAdapter->AdapterName;
            tempB=tempS.toLocal8Bit();
            AdapterName.append(QString::fromLocal8Bit(tempB));
            //printf("Adapter Desc: %s\n", pAdapter->Description);
            tempS=pAdapter->Description;
            tempB=tempS.toLocal8Bit();
            AdapterDescription.append(QString::fromLocal8Bit(tempB));
            pAdapter = pAdapter->Next;
        }
        if (pAdapterInfo)
            free(pAdapterInfo);
}

