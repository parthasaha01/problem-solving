#include<bits/stdc++.h>
using namespace std;
int mon[] = {31,28,31,30,31,30,31,31,30,31,30,31};
int fun(string s,int n)
{
    int day = 0;
    if(s=="January")
    {
        day += n;
    }
    else if(s=="February")
    {
        for(int i=0; i<1; i++){
            day += mon[i];
        }
        day += n;
    }
    else if(s=="March")
    {
        for(int i=0; i<2; i++){
            day += mon[i];
        }
        day += n;
    }
    else if(s=="April")
    {
        for(int i=0; i<3; i++){
            day += mon[i];
        }
        day += n;
    }
    else if(s=="May")
    {
        for(int i=0; i<4; i++){
            day += mon[i];
        }
        day += n;
    }
    else if(s=="June")
    {
        for(int i=0; i<5; i++){
            day += mon[i];
        }
        day += n;
    }
    else if(s=="July")
    {
        for(int i=0; i<6; i++){
            day += mon[i];
        }
        day += n;
    }
    else if(s=="August")
    {
        for(int i=0; i<7; i++){
            day += mon[i];
        }
        day += n;
    }
    else if(s=="September")
    {
        for(int i=0; i<8; i++){
            day += mon[i];
        }
        day += n;
    }
    else if(s=="October")
    {
        for(int i=0; i<9; i++){
            day += mon[i];
        }
        day += n;
    }
    else if(s=="November")
    {
        for(int i=0; i<10; i++){
            day += mon[i];
        }
        day += n;
    }
    else if(s=="December")
    {
        for(int i=0; i<11; i++){
            day += mon[i];
        }
        day += n;
    }

    return day;
}
int main()
{
    int tt; cin>>tt;

    for(int ks=1; ks<=tt; ks++)
    {
        string s;
        cin>> s;
        int n; cin>>n;

        int day = fun(s,n);

        int sum = 67;

        int rr = day%sum;
        if(rr==0)rr=67;

        int ee = rr%10;
        if(ee==0)ee=10;

        //printf("day=%d rr=%d ee=%d\n",day,rr,ee);

        if(rr<=10)
        {
            cout << "S01E";
            if(ee!=10)cout<<"0";
            cout << ee << endl;
        }
        else if(rr<=20)
        {
            cout << "S02E";
            if(ee!=10)cout<<"0";
            cout << ee << endl;
        }
        else if(rr<=30)
        {
            cout << "S03E";
            if(ee!=10)cout<<"0";
            cout << ee << endl;
        }
        else if(rr<=40)
        {
            cout << "S04E";
            if(ee!=10)cout<<"0";
            cout << ee << endl;
        }
        else if(rr<=50)
        {
            cout << "S05E";
            if(ee!=10)cout<<"0";
            cout << ee << endl;
        }
        else if(rr<=60)
        {
            cout << "S06E";
            if(ee!=10)cout<<"0";
            cout << ee << endl;
        }
        else if(rr<=70)
        {
            cout << "S07E";
            if(ee!=10)cout<<"0";
            cout << ee << endl;
        }

    }
    return 0;
}
