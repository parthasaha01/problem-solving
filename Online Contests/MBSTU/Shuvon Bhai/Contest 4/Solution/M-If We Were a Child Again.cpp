#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    long long num,rem,div,value,i,L,flag;
    char str[1001], sign;

    while(cin >> str >> sign >> num)
    {
        L=strlen(str);

        if(sign=='%'){
            rem=0;
            for(i=0; i<L; i++){
                value = rem*10 + (str[i]-48);
                rem = value%num;
            }
            cout << rem << endl;
        }
        else{
            flag=rem=0;
            for(i=0; i<L; i++){
                value = rem*10 + (str[i]-48);
                div=value/num;
                rem=value%num;

                if(flag==0 && div>0)
                    flag=1;
                if(flag)
                    cout << div;
            }

            if(flag==0)
                cout << "0";

            cout << endl;
        }
    }

    return 0;
}
