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
    //cout<<"------���Կ���------"<<endl;
    ifstream infile("useracc.dat", ios::in|ios::out|ios::binary);
    string n;
    long long p ;
    double m;
    int pa;
    Account a[10];
    int i = 0,str = 0;//��ʼ������
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
    cout<<"����������ֻ��ţ�"<<endl;
    long long phone;
    cin>>phone;
    int flag = 0;

    while(1)//ѭ���ж��ֻ����Ƿ�ƥ��
    {
        for(i = 0; i < str; i++)
        {
            if(a[i].get_phonenum() == phone)//�ж��ֻ����Ƿ����
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
}
