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
        cout<<"------����Ϊ��ȡ��------"<<endl;
    ifstream infile("useracc.dat", ios::in|ios::out|ios::binary);
    string name;
    long long phone;
    double money;
    int password;
    Account a[10];
    int i = 0,str = 0;//��ʼ������
    //infile.seekg(0);//�ƶ����ļ�ͷ
    while(!infile.eof())//���ļ��е�����ȡ��������һ�������鵱��
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
                    while(1)//ѭ���ж������Ƿ���ȷ
                    {
                        if(psd == a[i].get_psd())
                        {
                            cout<<"���������ȡ���"<<endl;
                            int m2;
                            cin>>m2;
                            while(1)//ѭ���ж��������Ƿ���ȷ
                            {
                                if(0<=m2 && m2<=a[i].get_money())
                                {
                                    int m1 = a[i].get_money();
                                    m1 -= m2;
                                    a[i].set_money(m1);
                                    cout<<"ʣ���"<<a[i].get_money()<<endl;
                                    ofstream psdfile("useracc.dat",ios_base::out);
                                    for(i = 0; i < str-1; i ++)
                                    psdfile<<a[i].get_username()<<" "<<a[i].get_phonenum()<<" "<<a[i].get_money()<<" "<<a[i].get_psd()<<endl;
                                    psdfile.close();
                                    break;
                                }
                                else
                                {
                                    cout<<"ȡ����������������룺"<<endl;
                                    cin>>m2;
                                }

                            }
                            break;
                        }
                        else
                        {
                            cout<<"���벻��ȷ�����������룺"<<endl;
                            cin>>psd;
                        }

                    }
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
    cout<<"------ȡ��ɹ�------"<<endl;
}
