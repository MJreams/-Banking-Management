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
    cout<<"------����Ϊ���޸�����------"<<endl;
    string name;
    long long phone;
    double money;
    int password;
    Account a[10];
    int i = 0,str = 0;//��ʼ������
    infile.seekg(0);
    while(!infile.eof())//���ļ��е�����ȡ��������һ�������鵱��
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
    //�鿴ԭʼ����
    /*
    cout<<i-1<<str-1<<endl;
    for(i = 0;i<str-1;i++)
    {
        cout<<a[i].get_username()<<" "<<a[i].get_phonenum()<<" "<<a[i].get_money()<<" "<<a[i].get_psd()<<endl;
    }
    */
    cout<<"����������ֻ��ţ�"<<endl;
    long long p1;
    cin>>p1;
    int flag = 0;
    int j;
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
                            cout<<"��������������룺"<<endl;
                            int psd2;
                            cin>>psd2;
                            while(1)//ѭ���ж��������Ƿ���ȷ
                            {
                                if(100000<psd2 && psd2<=999999)
                                {
                                    break;
                                }
                                else
                                {
                                    cout<<"��������ڼ򵥣����������룺"<<endl;
                                    cin>>psd2;
                                }

                            }
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
                                if(psd2 == j)
                                {
                                    a[i].set_password(psd2);
                                    ofstream psdfile("useracc.dat",ios::binary);
                                    infile.seekg(0);
                                    for(i = 0; i < str-1; i ++)//ѭ���ش�
                                        psdfile<<a[i].get_username()<<" "<<a[i].get_phonenum()<<" "<<a[i].get_money()<<" "<<a[i].get_psd()<<endl;
                                    psdfile.close();
                                    break;
                                }
                                else
                                {
                                    cout<<"����ǰ��һ�£������������������(��λ����):"<<endl;
                                    cin>>psd2;
                                    cout<<endl;
                                    cout<<"���ٴ������������(��λ����):"<<endl;
                                    cin>>j;
                                    cout<<endl;
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
    cout<<"------�޸�����ɹ�------"<<endl;
}
