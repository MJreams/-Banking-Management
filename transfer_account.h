#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <fstream>


using namespace std;

void transfer_account()
{
    cout<<"------------正在为您转账------------"<<endl;
    ifstream infile("useracc.dat", ios::in|ios::out|ios::binary);
    string name;
    long long phone;
    double money;
    int password;
    Account a[10];
    //初始化数据
    int i = 0;//控制循环
    int str = 0;//记录文件内的数据个数
    int ff = 0;//控制转账手机号是否存在
    int f = 0;//控制转账手机号是否正确
    int m = 0;//控制密码
    int pl = 0;//记录转账手机号的位置
    int ph = 0;//记录起始手机号的位置
    int mo;//转账金额
    int ml = 0;//转账手机号转账后金额
    int mh = 0;//原始手机号转账后金额
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
                flag = 1;//手机号正确记录flag为1，进行下一步操作
            }
        }
        if(flag)//如果存在
        {
            for(i = 0; i < str; i++)
            {
                if(a[i].get_phonenum() == p1)
                {
                    m = 1;//密码正确记录m为1，进行下一步操作
                    ph = i;
                }
            }
            if(m)
            {
                cout<<"请输入你的密码："<<endl;
                int psd;
                cin>>psd;
                while(1)//循环判断密码是否正确
                {
                    for(i = 0; i < str; i++)
                    {
                        if(psd == a[i].get_psd())
                        {
                            f = 1;//密码成功后f记录为1
                            flag = 0;
                        }
                    }
                    if(f)
                    {
                        cout<<"请输入你要转账的手机号"<<endl;
                        long long pp;
                        cin>>pp;
                        while(1)//循环判断转账手机号是否匹配
                        {
                            for(i = 0; i < str; i++)
                            {
                                if(a[i].get_phonenum() == pp)//判断手机号是否存在
                                {
                                    ff = 1;
                                    pl = i;//记录手机号位置
                                }
                            }
                            if(ff)//如果转账手机号存在
                            {
                                cout<<"请输入你要转账的额度"<<endl;
                                cin>>mo;
                                while(1)
                                {
                                    if(mo >= 0 && mo <= a[ph].get_money())
                                    {
                                        ml = mo + a[pl].get_money();
                                        mh = a[ph].get_money() - mo;
                                        a[ph].set_money(mh);
                                        a[pl].set_money(ml);
                                        ofstream psdfile("useracc.dat",ios_base::out);
                                        for(i = 0; i < str-1; i ++)
                                            psdfile<<a[i].get_username()<<" "<<a[i].get_phonenum()<<" "<<a[i].get_money()<<" "<<a[i].get_psd()<<endl;
                                        psdfile.close();
                                        cout<<"------转账成功------"<<endl;
                                        break;//跳出转账
                                    }
                                    else
                                    {
                                        cout<<"金额错误，请重新输入"<<endl;
                                        cin>>mo;
                                    }
                                }

                                break;//跳出转账手机号匹配
                            }
                            else
                            {
                                cout<<"手机号不存在，请重新输入"<<endl;
                                cin>>pp;
                            }
                            f = 0;
                        }
                        break;//跳出密码判断
                    }
                    else
                    {
                        cout<<"密码不正确，请重新输入："<<endl;
                        cin>>psd;
                    }
                }
                break;//
            }
            break;//跳出手机号是否存在

        }
        else
        {
            cout<<"手机号错误，请重新输入："<<endl;
            cin>>p1;
        }
        //break;
    }
}
