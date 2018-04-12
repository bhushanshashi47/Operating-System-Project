#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
system("color 40");
int i,n,j,min,line[10],k1[10],p[10]={1,2,3,4,5,6,7,8,9,10};
int BT[100],AVT[100],WT[100],temp,TAT[10];
int bt=0,ta=0,sum=0,k=1;
float AVGWT=0,AVGTT=0,TATSUM=0,WTS=0;
cout<<"********************************************\n";
cout<<"::::::::Enter the Number of processes : ";
cin>>n;
cout<<"********************************************\n";
    for(i=0;i<n;i++)
    {
        cout<<"\nEnter The Arrival Time Of Process"<<i+1<<" : ";
        cin>>AVT[i];
        cout<<"Enter The Burst Time Of Process"<<i+1<<" : ";
        cin>>BT[i];

    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(AVT[i]<AVT[j])
            {
                temp=p[j];
                p[j]=p[i];
                p[i]=temp;
                temp=AVT[j];
                AVT[j]=AVT[i];
                AVT[i]=temp;
                temp=BT[j];
                BT[j]=BT[i];
                BT[i]=temp;
            }
        }
    }

    for(j=0;j<n;j++)
    {
        bt=bt+BT[j];
        min=BT[k];
    for(i=k;i<n;i++)
    {
        if (bt>=AVT[i] && BT[i]<min)
            {
                temp=p[k];
                p[k]=p[i];
                p[i]=temp;
                temp=AVT[k];
                AVT[k]=AVT[i];
                AVT[i]=temp;
                temp=BT[k];
                BT[k]=BT[i];
                BT[i]=temp;
            }
    }
    k++;
    }
WT[0]=0;
    for(i=1;i<n;i++)
    {
        sum=sum+BT[i-1];
        WT[i]=sum-AVT[i];
        line[i]=WT[i];
        WTS=WTS+WT[i];
    }

AVGWT=(WTS/n);
    for(i=0;i<n;i++)
    {
        ta=ta+BT[i];
        TAT[i]=ta-AVT[i];
        k1[i]=TAT[i];
        TATSUM=TATSUM+TAT[i];
    }

AVGTT=(TATSUM/n);
cout<<"\nProcess Name\tBurst Time\t Arrival Time\t Waiting Time\t Turn Around Time";
    for(i=0;i<n;i++)
    {
       cout<<"\n"<<p[i]<<"\t\t"<<BT[i]<<"\t\t"<<AVT[i]<<"\t\t"<<WT[i]<<"\t\t"<<TAT[i];
    }
cout<<"\n\nAVERAGE WAITING TIME :"<<AVGWT;
cout<<"\nAVERAGE TURN AROUND TIME : "<<AVGTT;
cout<<"\n";
    for(i=0;i<TATSUM/2;i++)
    {
        cout<<" ";
    }
cout<<"\n******************GANTT CHART**************\n";
cout<<"********************************************\n";
    line[0]=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<(line[i]+k1[i])/2;j++)
        {
            cout<<" ";
        }
    cout<<"P"<<p[i];
    }
cout<<"\n";
cout<<"0";
    for(i=0;i<n; i++)
    {
        for(j=0;j<k1[i];j++)
        {
            cout<<"-";
        }
        cout<<k1[i];
    }
    cout<<"\n";
cout<<"********************************************\n";
getch();
return 0;

}
