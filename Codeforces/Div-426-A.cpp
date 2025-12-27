#include<bits/stdc++.h>
using namespace std;
string st,ed;
int n;
bool clockwise(string st,string ed,int d)
{
    if(d==0)
    {
        if(st==ed)return true;
        return false;
    }
    else if(d==1)
    {
        if(st=="v" && ed=="<")return true;
        if(st=="<" && ed=="^")return true;
        if(st=="^" && ed==">")return true;
        if(st==">" && ed=="v")return true;
        return false;
    }
    else if(d==2)
    {
        if(st=="v" && ed=="^")return true;
        if(st=="<" && ed==">")return true;
        if(st=="^" && ed=="v")return true;
        if(st==">" && ed=="<")return true;
        return false;
    }
    else if(d==3)
    {
        if(st=="v" && ed==">")return true;
        if(st=="<" && ed=="v")return true;
        if(st=="^" && ed=="<")return true;
        if(st==">" && ed=="^")return true;
        return false;
    }
}
bool counterclockwise(string st,string ed,int d)
{
    if(d==0)
    {
        if(st==ed)return true;
        return false;
    }
    else if(d==1)
    {
        if(st=="v" && ed==">")return true;
        if(st==">" && ed=="^")return true;
        if(st=="^" && ed=="<")return true;
        if(st=="<" && ed=="v")return true;
        return false;
    }
    else if(d==2)
    {
        if(st=="v" && ed=="^")return true;
        if(st==">" && ed=="<")return true;
        if(st=="^" && ed=="v")return true;
        if(st=="<" && ed==">")return true;
        return false;
    }
    else if(d==3)
    {
        if(st=="v" && ed=="<")return true;
        if(st==">" && ed=="v")return true;
        if(st=="^" && ed==">")return true;
        if(st=="<" && ed=="^")return true;
        return false;
    }
}
int main()
{
    while(cin>>st>>ed)
    {


        cin>>n;

        int d = n%4;

        bool cw = clockwise(st,ed,d);
        bool ccw = counterclockwise(st,ed,d);

        if(cw==true && ccw==false)
        {
            cout << "cw" << endl;
        }
        else if(cw==false && ccw==true)
        {
            cout << "ccw" << endl;
        }
        else
        {
            cout << "undefined" << endl;
        }

    }

    return 0;
}
