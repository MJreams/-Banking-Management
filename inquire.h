#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <fstream>

#define UserN 20
using namespace std;

void inquire()
{
   cout<<"------正在为您查询------"<<endl;
    ifstream infile("useracc.dat", ios::in|ios::out|ios::binary);
    string name;
    long long phone;
    double money;
    int password;
    Account a[10];
    int i = 0,str = 0;//初始化数据
    infile.seekg(0);
    while(!infile.eof())
    {

        infile>>name>>phone>>money>>password;
        a[i].set_username(name);
        a[i].set_phonenum(phone);
        a[i].set_money(money);
        a[i].set_password(password);
        i++;
        str++;
    }
    infile.close();
    cout<<"请输入你的手机号："<<endl;
    long long p1;
    cin>>p1;
    int flag = 0;

    while(1)//循环判断手机号是否匹配
    {
        for(i = 0; i < str; i++)
        {
            if(a[i].get_phonenum() == p1)//判断手机号是否存在
            {
                flag = 1;
            }
        }
        if(flag)//如果存在
        {
            for(i = 0; i < str; i++)
            {
                if(a[i].get_phonenum() == p1)
                {
                    cout<<"请输入你的密码："<<endl;
                    int psd;
                    cin>>psd;
                    while(1)//循环判断是否正确
                    {
                        if(psd == a[i].get_psd())
                        {
                            int f = 1;//密码成功后f记录为1
                        if(f)
                        {
                            cout<<"------查询成功------"<<endl;
                            cout<<"\n\t※※※※※※※※※※※※※※※※※※※\n"
                                <<"\t                                  \n"
                                <<"\t          "<<"用户名："<<a[i].get_username()<<"         \n"
                                <<"\t          "<<"手机号："<<a[i].get_phonenum()<<"     \n"
                                <<"\t          "<<"余额："<<a[i].get_money()<<"               \n"
                                <<"\t          "<<"密码："<<a[i].get_psd()<<"              \n\n"
                                <<"\t※※※※※※※※※※※※※※※※※※※\n"<<endl;
                                f = 0;//查询完毕后f记录为0
                            break;
                        }
                        }
                        else
                        {
                            cout<<"密码不正确，请重新输入："<<endl;
                            cin>>psd;
                        }

                    }
                    break;
                }

            }
            break;

        }
        else
        {
            cout<<"手机号错误，请重新输入："<<endl;
            cin>>p1;
        }

    }
}
