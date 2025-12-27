#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int N,len,i,Rear,Max,Front,letter;
    char str[1000000],ch;
    int last[130];

    while(cin >> N && N)
    {
        getchar();
        gets(str);

        len=strlen(str);

        for(i=0;i<128;i++)
            last[i]= -1;

        Rear=-1;
        letter=0;
        Max=0;

        for(Front=0; Front<len; Front++)
        {
            //if(str[Front]>='a' && str[Front]<='z')
                //str[Front]=str[Front]-32;

            ch = str[Front];

            if(last[ch]<=Rear)
            {
                letter++;
                last[ch]=Front;

                if(letter>N)
                {
                    Rear++;
                    letter--;

                    while(last[str[Rear]] != Rear)
                    {
                        Rear++;
                    }
                }
            }
            else
            {
                last[ch]=Front;
            }

            Max = max(Max, Front-Rear);
        }

        cout << Max << endl;
    }

    return 0;
}
