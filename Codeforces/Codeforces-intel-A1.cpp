#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int main()
{
    int type;
    string s;
    while(cin >> type)
    {
        int h,m;
        scanf("%d:%d",&h,&m);
        int h1,h2,m1,m2;

        if(type==24)
        {
            if(h>=0&&h<=23)
            {
                if(h<10)
                {
                    h1=0;
                    h2=h;
                }
                else
                {
                    h1=h/10;
                    h2=h%10;
                }


            }
            else

            {
                h1=0;
                h2=h%10;
            }

            if(m<=59)
            {
                if(m<10)
                {
                    m1=0;
                    m2=m;
                }
                else{
                    m1=m/10;
                    m2=m%10;
                }

            }
            else
            {
                m1=0;
                m2=m%10;
            }
            cout << h1 << h2 << ":" << m1 << m2 << endl;
        }
        else
        {
            if(h>=1&&h<=12)
            {
                if(h<10)
                {
                    h1=0;
                    h2=h;
                }
                else
                {
                    h1=h/10;
                    h2=h%10;
                }
            }
            else
            {
                if(h%10==0)
                {
                    h1=1;
                    h2=h%10;
                }
                else
                {
                    h1=0;
                    h2=h%10;
                }
            }
            if(m<=59)
            {
                if(m<10)
                {
                    m1=0;
                    m2=m;
                }
                else{
                    m1=m/10;
                    m2=m%10;
                }

            }
            else
            {
                m1=0;
                m2=m%10;
            }

            cout << h1 << h2 << ":" << m1 << m2 << endl;
        }
    }

    return 0;
}

