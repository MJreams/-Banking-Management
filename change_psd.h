#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <fstream>

#define UserN 20
using namespace std;

ifstream infile("useracc.dat", ios::in|ios::out|ios::binary);
void change_psd()
{
    cout<<"------正在为您修改密码------"<<endl;
    string name;
    long long phone;
    double money;
    int password;
    Account a[10];
    int i = 0,str = 0;//初始化数据
    infile.seekg(0);
    while(!infile.eof())//将文件中的数据取出并存在一个类数组当中
    {

        infile>>name>>phone>>money>>password;
        a[i].set_username(name);
        a[i].set_phonenum(phone);
        a[i].set_money(money);
        a[i].set_password(password);
        i++;
        ++str;
    }
    infile.close();
    //查看原始数据
    /*
    cout<<i-1<<str-1<<endl;
    for(i = 0;i<str-1;i++)
    {
        cout<<a[i].get_username()<<" "<<a[i].get_phonenum()<<" "<<a[i].get_money()<<" "<<a[i].get_psd()<<endl;
    }
    */
    cout<<"请输入你的手机号："<<endl;
    long long p1;
    cin>>p1;
    int flag = 0;
    int j;
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
                            cout<<"请输入你的新密码："<<endl;
                            int psd2;
                            cin>>psd2;
                            while(1)//循环判断新密码是否正确
                            {
                                if(100000<psd2 && psd2<=999999)
                                {
                                    break;
                                }
                                else
                                {
                                    cout<<"新密码过于简单，请重新输入："<<endl;
                                    cin>>psd2;
                                }

                            }
                            cout<<"请再次输入你的密码(六位):"<<endl;
                            cin>>j;
                            while(1)
                            {
                                if(j > 100000&&j<1000000)
                                {
                                    break;
                                }
                                else
                                {
                                    cout<<"密码输入错误，请重新输入"<<endl;
                                    cin>>j;
                                }
                            }
                            cout<<endl;
                            while(1)
                            {
                                if(psd2 == j)
                                {
                                    a[i].set_password(psd2);
                                    ofstream psdfile("useracc.dat",ios::binary);
                                    infile.seekg(0);
                                    for(i = 0; i < str-1; i ++)//循环重存
                                        psdfile<<a[i].get_username()<<" "<<a[i].get_phonenum()<<" "<<a[i].get_money()<<" "<<a[i].get_psd()<<endl;
                                    psdfile.close();
                                    break;
                                }
                                else
                                {
                                    cout<<"密码前后不一致，请重新输入你的密码(六位整数):"<<endl;
                                    cin>>psd2;
                                    cout<<endl;
                                    cout<<"请再次输入你的密码(六位整数):"<<endl;
                                    cin>>j;
                                    cout<<endl;
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
    cout<<"------修改密码成功------"<<endl;
}
