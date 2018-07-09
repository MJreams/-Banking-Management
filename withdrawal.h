#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <fstream>

#define UserN 20
using namespace std;

void withdrawal()
{
        cout<<"------正在为您取款------"<<endl;
    ifstream infile("useracc.dat", ios::in|ios::out|ios::binary);
    string name;
    long long phone;
    double money;
    int password;
    Account a[10];
    int i = 0,str = 0;//初始化数据
    //infile.seekg(0);//移动到文件头
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
                            cout<<"请输入你的取款金额："<<endl;
                            int m2;
                            cin>>m2;
                            while(1)//循环判断新密码是否正确
                            {
                                if(0<=m2 && m2<=a[i].get_money())
                                {
                                    int m1 = a[i].get_money();
                                    m1 -= m2;
                                    a[i].set_money(m1);
                                    cout<<"剩余金额："<<a[i].get_money()<<endl;
                                    ofstream psdfile("useracc.dat",ios_base::out);
                                    for(i = 0; i < str-1; i ++)
                                    psdfile<<a[i].get_username()<<" "<<a[i].get_phonenum()<<" "<<a[i].get_money()<<" "<<a[i].get_psd()<<endl;
                                    psdfile.close();
                                    break;
                                }
                                else
                                {
                                    cout<<"取款金额错误，请重新输入："<<endl;
                                    cin>>m2;
                                }

                            }
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
    cout<<"------取款成功------"<<endl;
}
