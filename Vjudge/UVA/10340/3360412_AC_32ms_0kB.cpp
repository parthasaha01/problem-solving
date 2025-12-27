#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    long i,j,ls,lp,flag;
    char pat[100000],str[100000];

    while(cin >> pat >> str)
    {
       lp=strlen(pat);
       ls=strlen(str);

       for(i=0,j=0; i<lp; i++)
       {
           flag=0;

           while(j<ls)
           {
               if(pat[i]==str[j])
               {
                   flag=1;
                   j++;
                   break;
               }
               j++;
           }

           if(flag==0)
            break;
       }

       if(flag)
        cout << "Yes" << endl;
       else
        cout << "No" << endl;
    }

    return 0;
}
