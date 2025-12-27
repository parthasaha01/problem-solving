#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,N,flag,sub,cnt,st,num1,num2,sum;

    cin >> T;

    while(T--)
    {
        string s;
        cin >> s;

        int sz = s.size();
        cnt=0;
        flag=0;
        for(int i=0; i<sz; i++)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                sum=0;
                cnt++;
                if(cnt==2)
                {
                    flag=1;
                }
                while(i<sz)
                {
                    if(s[i]>='0' && s[i]<='9')
                    {
                        int d=s[i]-'0';
                        sum=sum*10+d;
                        i++;
                        continue;
                    }
                    else
                    {
                        if(cnt==1)
                        {
                            num1=sum;
                        }
                        else
                        {
                            num2=sum;
                        }
                        sum=0;
                        break;
                    }
                }
            }
        }
        num2=sum;
        //cout << "flag=" << flag << " " << "num1=" << num1 << " " << "num2=" << num2 << endl;

        if(flag==1)
        {
            string s2;
            int p=0;
            if(num2%26==0)
                p=1;
            while(num2>0)
            {
                int rem=num2%26;
                if(rem==0)
                   num2 = (num2/26)-1;
                else
                    num2 = num2/26;
                //cout << rem << " ";
                if(rem==0){
                    char ch ='Z';
                    s2+=ch;
                }
                else
                {
                    char ch;

                    ch = 'A'+(rem-1);
                    s2 += ch;
                }

            }

            //cout << s2 << " " << num1 << endl;
            int sz2=s2.size();
            //cout << s2 << " " << num1 << " " << sz2 << endl;
            for(int i=sz2-1; i>=0; i--)
            {
                cout << s2[i];
            }
            cout << num1 << endl;
        }
        else
        {
            sum=0;
            for(int i=0; i<sz; i++)
            {
                if(s[i]>='0' && s[i] <='9')
                    break;

                int d = s[i]-'A'+1;
                sum = sum*26+d;
            }
            num1=sum;
            cout << "R" << num2 << "C" << num1 << endl;
        }


    }


    return 0;
}
