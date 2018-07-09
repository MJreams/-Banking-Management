#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <fstream>
//多文件处理
#include "open_account.h"//开户
#include "change_psd.h"//修改密码
#include "transfer_account.h"//转帐
#include "inquire.h"//查询
#include "deposit.h"//存款
#include "withdrawal.h"//取款
#include "close_account.h"//销户
#include "test.h"//测试

#define UserN 20
using namespace std;

int menu_select()
{

    char c;
    do
    {
        system("cls");
        cout<<"\n\n\n\t※※※※※※※※※※※※※※※※※※※※※※※※※※※\n"
        <<"\t※                                                  ※\n"
        <<"\t※             欢迎使用储蓄管理系统                 ※\n"
        <<"\t※                    1.开户                        ※\n"
        <<"\t※                    2.修改密码                    ※\n"
        <<"\t※                    3.取款                        ※\n"
        <<"\t※                    4.转账                        ※\n"
        <<"\t※                    5.查询                        ※\n"
        <<"\t※                    6.存款                        ※\n"
        <<"\t※                    7.销户                        ※\n"
        <<"\t※                    0.退出                        ※\n"
        //<<"\t※                    8.测试                        ※\n"
        <<"\t※※※※※※※※※※※※※※※※※※※※※※※※※※※\n"<<endl;
        cout<<"请选择要进行的项目："<<endl;
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
        cout<<"\n\t                      欢迎来到这里"<<endl;
        cout<<"\n\t        输入Y/y开始，输入N/n或者其他字符结束"<<endl;
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
