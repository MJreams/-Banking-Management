#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <fstream>

#define UserN 20
using namespace std;

void close_account()
{
    cout<<"------正在为您销户------"<<endl;
    string name;
    long long phone;
    double money;
    int password;
    Account a[10];
    int i = 0,str = 0;//初始化数据
    //infile.seekg(0);//移动到文件头
    ifstream infile("useracc.dat", ios::in|ios::out|ios::binary);
    while(!infile.eof())//将文件中的数据取出并存在一个类数组当中
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
                    while(1)//循环判断密码是否正确
                    {
                        if(psd == a[i].get_psd())
                        {
                            cout<<"确认销户请按'1'，其他键退出"<<endl;
                            char t;
                            int g = i;//标记要销户的位置
                            cin>>t;
                                if(t == '1')
                                {
                                    ofstream psdfile("useracc.dat",ios_base::out);
                                    while(i < str-1)
                                    {
                                       if(g != i)
                                       psdfile<<a[i].get_username()<<" "<<a[i].get_phonenum()<<" "<<a[i].get_money()<<" "<<a[i].get_psd()<<endl;
                                       i++;
                                    }
                                    psdfile.close();
                                }
                                else
                                {
                                        cout<<"------退出成功------"<<endl;
                                    break;
                                }
                                    cout<<"------销户成功------"<<endl;
                            break;
                        }
                        else
                        {
                            cout<<"密码不正确，请重新输入："<<endl;
                            cin>>psd;
                        }

                    }
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
