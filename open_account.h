#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <fstream>


#define UserN 20
using namespace std;
typedef class Account //账户
{
private:
    long long phone;//手机号
    string username;//用户名
    int psd;//密码
    double money;//账户余额
public:
    void set_username(string);
    void set_password(int i);
    void set_phonenum(long long i);
    void set_money(double);
    long long get_phonenum();
    int get_psd();
    string get_username();
    double get_money();
} account;
void Account::set_username(string i)
{
    username=i;
}
void Account::set_password(int i)
{
    psd = i;
}
void Account::set_phonenum(long long i)
{
    phone = i;
}
void Account::set_money(double i)
{
    money = i;
}
long long Account::get_phonenum()
{
    return phone;
}
int Account::get_psd()
{
    return psd;
}
string Account::get_username()
{
    return username;
}
double Account::get_money()
{
    return money;
}
void open_account()
{
    Account acc;
    cout<<"------------正在为您开户------------"<<endl;
    cout<<"请输入你的姓名:"<<endl;
    string name;
    cin>>name;
    acc.set_username(name);
    cout<<"请输入你的手机号："<<endl;
    //long long phone;
    //cin>>phone;
    //验证手机号是否已经存在
    ifstream infile("useracc.dat", ios::in|ios::out|ios::binary);
    string n;
    long long p ;
    double m;
    int pa;
    Account a[10];
    int ii = 0,str = 0;//初始化数据
    infile.seekg(0);
    while(!infile.eof())
    {

        infile>>n>>p>>m>>pa;
        a[ii].set_username(n);
        a[ii].set_phonenum(p);
        a[ii].set_money(m);
        a[ii].set_password(pa);
        ii++;
        str++;
    }
    infile.close();
    cout<<"请输入你的手机号："<<endl;
    long long phone;
    cin>>phone;
    int flag = 0;

    while(1)//循环判断手机号是否匹配
    {
        for(ii = 0; ii < str; ii++)
        {
            if(a[ii].get_phonenum() == phone)//判断手机号是否存在
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
    //
    while(1)
    {
        if(phone > 10000000000&&phone<100000000000)
        {
            acc.set_phonenum(phone);
            break;
        }
        else
        {
            cout<<"手机号错误，请重新输入"<<endl;
            cin>>phone;
        }
    }

    cout<<"请输入你要存入的金额："<<endl;
    double money;
    cin>>money;
    acc.set_money(money);
    cout<<"请输入你的密码(六位):"<<endl;
    int i,j;
    cin>>i;
    while(1)
    {
        if(i > 100000&&i<1000000)
        {
            break;
        }
        else
        {
            cout<<"密码不够六位整数或者密码过于简单，请重新输入"<<endl;
            cin>>i;
        }
    }
    cout<<endl;
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
        if(i == j)
        {
            ofstream outfile("useracc.dat",ios_base::app);//文件重存
            acc.set_password(i);
            outfile<<acc.get_username()<<" "<<acc.get_phonenum()<<" "<<acc.get_money()<<" "<<acc.get_psd()<<endl;
            outfile.close();
            break;
        }
        else
        {
            cout<<"密码前后不一致，请重新输入你的密码(六位整数):"<<endl;
            cin>>i;
            cout<<endl;
            cout<<"请再次输入你的密码(六位整数):"<<endl;
            cin>>j;
            cout<<endl;
        }
    }
    cout<<"---------------开户成功---------------"<<endl;
}
