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
   cout<<"------����Ϊ����ѯ------"<<endl;
    ifstream infile("useracc.dat", ios::in|ios::out|ios::binary);
    string name;
    long long phone;
    double money;
    int password;
    Account a[10];
    int i = 0,str = 0;//��ʼ������
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
    cout<<"����������ֻ��ţ�"<<endl;
    long long p1;
    cin>>p1;
    int flag = 0;

    while(1)//ѭ���ж��ֻ����Ƿ�ƥ��
    {
        for(i = 0; i < str; i++)
        {
            if(a[i].get_phonenum() == p1)//�ж��ֻ����Ƿ����
            {
                flag = 1;
            }
        }
        if(flag)//�������
        {
            for(i = 0; i < str; i++)
            {
                if(a[i].get_phonenum() == p1)
                {
                    cout<<"������������룺"<<endl;
                    int psd;
                    cin>>psd;
                    while(1)//ѭ���ж��Ƿ���ȷ
                    {
                        if(psd == a[i].get_psd())
                        {
                            int f = 1;//����ɹ���f��¼Ϊ1
                        if(f)
                        {
                            cout<<"------��ѯ�ɹ�------"<<endl;
                            cout<<"\n\t��������������������������������������\n"
                                <<"\t                                  \n"
                                <<"\t          "<<"�û�����"<<a[i].get_username()<<"         \n"
                                <<"\t          "<<"�ֻ��ţ�"<<a[i].get_phonenum()<<"     \n"
                                <<"\t          "<<"��"<<a[i].get_money()<<"               \n"
                                <<"\t          "<<"���룺"<<a[i].get_psd()<<"              \n\n"
                                <<"\t��������������������������������������\n"<<endl;
                                f = 0;//��ѯ��Ϻ�f��¼Ϊ0
                            break;
                        }
                        }
                        else
                        {
                            cout<<"���벻��ȷ�����������룺"<<endl;
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
            cout<<"�ֻ��Ŵ������������룺"<<endl;
            cin>>p1;
        }

    }
}
