#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <fstream>


#define UserN 20
using namespace std;
typedef class Account //�˻�
{
private:
    long long phone;//�ֻ���
    string username;//�û���
    int psd;//����
    double money;//�˻����
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
    cout<<"------------����Ϊ������------------"<<endl;
    cout<<"�������������:"<<endl;
    string name;
    cin>>name;
    acc.set_username(name);
    cout<<"����������ֻ��ţ�"<<endl;
    //long long phone;
    //cin>>phone;
    //��֤�ֻ����Ƿ��Ѿ�����
    ifstream infile("useracc.dat", ios::in|ios::out|ios::binary);
    string n;
    long long p ;
    double m;
    int pa;
    Account a[10];
    int ii = 0,str = 0;//��ʼ������
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
    cout<<"����������ֻ��ţ�"<<endl;
    long long phone;
    cin>>phone;
    int flag = 0;

    while(1)//ѭ���ж��ֻ����Ƿ�ƥ��
    {
        for(ii = 0; ii < str; ii++)
        {
            if(a[ii].get_phonenum() == phone)//�ж��ֻ����Ƿ����
            {
                flag = 1;
            }
        }
        if(flag)//�������
        {
            cout<<"�ֻ����Ѿ����ڣ������ظ������������������ֻ���"<<endl;
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
            cout<<"�ֻ��Ŵ�������������"<<endl;
            cin>>phone;
        }
    }

    cout<<"��������Ҫ����Ľ�"<<endl;
    double money;
    cin>>money;
    acc.set_money(money);
    cout<<"�������������(��λ):"<<endl;
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
            cout<<"���벻����λ��������������ڼ򵥣�����������"<<endl;
            cin>>i;
        }
    }
    cout<<endl;
    cout<<"���ٴ������������(��λ):"<<endl;
    cin>>j;
    while(1)
    {
        if(j > 100000&&j<1000000)
        {
            break;
        }
        else
        {
            cout<<"���������������������"<<endl;
            cin>>j;
        }
    }
    cout<<endl;
    while(1)
    {
        if(i == j)
        {
            ofstream outfile("useracc.dat",ios_base::app);//�ļ��ش�
            acc.set_password(i);
            outfile<<acc.get_username()<<" "<<acc.get_phonenum()<<" "<<acc.get_money()<<" "<<acc.get_psd()<<endl;
            outfile.close();
            break;
        }
        else
        {
            cout<<"����ǰ��һ�£������������������(��λ����):"<<endl;
            cin>>i;
            cout<<endl;
            cout<<"���ٴ������������(��λ����):"<<endl;
            cin>>j;
            cout<<endl;
        }
    }
    cout<<"---------------�����ɹ�---------------"<<endl;
}
