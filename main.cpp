#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <fstream>
//���ļ�����
#include "open_account.h"//����
#include "change_psd.h"//�޸�����
#include "transfer_account.h"//ת��
#include "inquire.h"//��ѯ
#include "deposit.h"//���
#include "withdrawal.h"//ȡ��
#include "close_account.h"//����
#include "test.h"//����

#define UserN 20
using namespace std;

int menu_select()
{

    char c;
    do
    {
        system("cls");
        cout<<"\n\n\n\t������������������������������������������������������\n"
        <<"\t��                                                  ��\n"
        <<"\t��             ��ӭʹ�ô������ϵͳ                 ��\n"
        <<"\t��                    1.����                        ��\n"
        <<"\t��                    2.�޸�����                    ��\n"
        <<"\t��                    3.ȡ��                        ��\n"
        <<"\t��                    4.ת��                        ��\n"
        <<"\t��                    5.��ѯ                        ��\n"
        <<"\t��                    6.���                        ��\n"
        <<"\t��                    7.����                        ��\n"
        <<"\t��                    0.�˳�                        ��\n"
        //<<"\t��                    8.����                        ��\n"
        <<"\t������������������������������������������������������\n"<<endl;
        cout<<"��ѡ��Ҫ���е���Ŀ��"<<endl;
        c = getchar();
    }
    while(c<'0'||c>'8');
    return c-'0';
}

void beging()
{
    char n;
    while(1)
    {
        cout<<"\n\n\n\t     *********************************************\n";
        cout<<"\n\t                      ��ӭ��������"<<endl;
        cout<<"\n\t        ����Y/y��ʼ������N/n���������ַ�����"<<endl;
        cout<<"\n\t     *********************************************\n"<<endl;
        cout<<"                              ";
        cin>>n;
        break;
    }
    if(n =='Y' || n == 'y')
        for(;;)
        {
            switch(menu_select())
            {
            case 1:
                open_account();
                system("pause");
                break;
            case 2:
                change_psd();
                system("pause");
                break;
            case 3:
                withdrawal();
                system("pause");
                break;
            case 4:
                transfer_account();
                system("pause");
                break;
            case 5:
                inquire();
                system("pause");
                break;
            case 6:
                deposit();
                system("pause");
                break;
            case 7:
                close_account();
                system("pause");
                break;
            case 8:
                test();
                system("pause");
                break;
            case 0:
                cout<<"Goodbye"<<endl;
                system("pause");
                exit(0);
            }
        }
    else
        exit(0);
}
int main()
{
    beging();
    return 0;
}
