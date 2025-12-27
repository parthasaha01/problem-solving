#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int x;
    cin>>x;
    string hh,mm;
    cin>>hh>>mm;

    int gh = ((hh[0]-'0')*10) + (hh[1]-'0');
    int gm = ((mm[0]-'0')*10) + (mm[1]-'0');

    string s1;
    s1+=hh;
    s1+=mm;

   // cout <<"s1= " << s1 << endl;
    //cout << "gh=" << gh << " gm=" << gm << endl;

    int ans = 100000000;

    for(int h1=0; h1<=2; h1++)
    {
        for(int h2=0; h2<=9; h2++)
        {
            if(h1==2 && h2==4)break;

            for(int m1=0; m1<=5; m1++)
            {
                for(int m2=0; m2<=9; m2++)
                {
                    if(h1==7 || h2==7 || m1==7 || m2==7)
                    {
                        int th = (h1*10) + h2;
                        int tm = (m1*10) + m2;

                        string s2;
                        s2+=h1+'0';
                        s2+=h2+'0';
                        s2+=m1+'0';
                        s2+=m2+'0';

                       // cout <<"s2= " << s2 << endl;
                        //cout << "th=" << th << " tm=" << tm << endl;

                        if(s1>=s2)
                        {
                            int sum = ((gh-th)*60) - tm + gm;

                            if(sum%x==0){
                                int cnt = sum/x;
                                ans = min(ans,cnt);
                            }
//                            else{
//                                int cnt = (sum/x)+1;
//                                ans = min(ans,cnt);
//                            }

                            //cout << "ans1= " << ans << endl << endl;

                        }
                        else
                        {
                            int sum=0;
                            sum = (24-th)*60 - tm;
                            sum += (gh*60) + gm;

                            if(sum%x==0){
                                int cnt = sum/x;
                                ans = min(ans,cnt);
                            }
//                            else{
//                                int cnt = (sum/x)+1;
//                                ans = min(ans,cnt);
//                            }

                            //cout << "ans2= " << ans << endl << endl;
                        }
                    }
                }
            }
        }
    }

//    if(ans==100000000)
//    {
//        int sum = 3+(mm[1]-'0');
//        int cnt = sum/x;
//        if(sum%x != 0)cnt++;
//        ans = min(ans,cnt);
//    }

    cout << ans << endl;

    //main();

    return 0;
}
