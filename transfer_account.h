#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <fstream>


using namespace std;

void transfer_account()
{
    cout<<"------------����Ϊ��ת��------------"<<endl;
    ifstream infile("useracc.dat", ios::in|ios::out|ios::binary);
    string name;
    long long phone;
    double money;
    int password;
    Account a[10];
    //��ʼ������
    int i = 0;//����ѭ��
    int str = 0;//��¼�ļ��ڵ����ݸ���
    int ff = 0;//����ת���ֻ����Ƿ����
    int f = 0;//����ת���ֻ����Ƿ���ȷ
    int m = 0;//��������
    int pl = 0;//��¼ת���ֻ��ŵ�λ��
    int ph = 0;//��¼��ʼ�ֻ��ŵ�λ��
    int mo;//ת�˽��
    int ml = 0;//ת���ֻ���ת�˺���
    int mh = 0;//ԭʼ�ֻ���ת�˺���
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
                flag = 1;//�ֻ�����ȷ��¼flagΪ1��������һ������
            }
        }
        if(flag)//�������
        {
            for(i = 0; i < str; i++)
            {
                if(a[i].get_phonenum() == p1)
                {
                    m = 1;//������ȷ��¼mΪ1��������һ������
                    ph = i;
                }
            }
            if(m)
            {
                cout<<"������������룺"<<endl;
                int psd;
                cin>>psd;
                while(1)//ѭ���ж������Ƿ���ȷ
                {
                    for(i = 0; i < str; i++)
                    {
                        if(psd == a[i].get_psd())
                        {
                            f = 1;//����ɹ���f��¼Ϊ1
                            flag = 0;
                        }
                    }
                    if(f)
                    {
                        cout<<"��������Ҫת�˵��ֻ���"<<endl;
                        long long pp;
                        cin>>pp;
                        while(1)//ѭ���ж�ת���ֻ����Ƿ�ƥ��
                        {
                            for(i = 0; i < str; i++)
                            {
                                if(a[i].get_phonenum() == pp)//�ж��ֻ����Ƿ����
                                {
                                    ff = 1;
                                    pl = i;//��¼�ֻ���λ��
                                }
                            }
                            if(ff)//���ת���ֻ��Ŵ���
                            {
                                cout<<"��������Ҫת�˵Ķ��"<<endl;
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
                                        cout<<"------ת�˳ɹ�------"<<endl;
                                        break;//����ת��
                                    }
                                    else
                                    {
                                        cout<<"����������������"<<endl;
                                        cin>>mo;
                                    }
                                }

                                break;//����ת���ֻ���ƥ��
                            }
                            else
                            {
                                cout<<"�ֻ��Ų����ڣ�����������"<<endl;
                                cin>>pp;
                            }
                            f = 0;
                        }
                        break;//���������ж�
                    }
                    else
                    {
                        cout<<"���벻��ȷ�����������룺"<<endl;
                        cin>>psd;
                    }
                }
                break;//
            }
            break;//�����ֻ����Ƿ����

        }
        else
        {
            cout<<"�ֻ��Ŵ������������룺"<<endl;
            cin>>p1;
        }
        //break;
    }
}
