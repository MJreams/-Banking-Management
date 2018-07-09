#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <fstream>

#define UserN 20
using namespace std;

void test()
{
    //cout<<"------测试开户------"<<endl;
    ifstream infile("useracc.dat", ios::in|ios::out|ios::binary);
    string n;
    long long p ;
    double m;
    int pa;
    Account a[10];
    int i = 0,str = 0;//初始化数据
    infile.seekg(0);
    while(!infile.eof())
    {

        infile>>n>>p>>m>>pa;
        a[i].set_username(n);
        a[i].set_phonenum(p);
        a[i].set_money(m);
        a[i].set_password(pa);
        i++;
        str++;
    }
    infile.close();
    cout<<"请输入你的手机号："<<endl;
    long long phone;
    cin>>phone;
    int flag = 0;

    while(1)//循环判断手机号是否匹配
    {
        for(i = 0; i < str; i++)
        {
            if(a[i].get_phonenum() == phone)//判断手机号是否存在
            {
                flag = 1;
            }
        }
        if(flag)//如果存在
        {
            cout<<"手机号已经存在，不能重复开户，请重新输入手机号"<<endl;
            flag = 0;
            cin>>phone;
        }
        else
        {
            break;
        }

    }
}
