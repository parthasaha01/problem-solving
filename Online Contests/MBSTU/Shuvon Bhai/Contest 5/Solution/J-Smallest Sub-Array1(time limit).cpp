#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
int main()
{
    long N,Min,Minx,low,high,j,total,hp,lp;
    int T,M,K,cnt,i,test,flag;

    cin >> T;

    for(test=1; test<=T; test++)
    {
        cin >> N >> M >> K;

        /*vector<int>num;
        vector<int>next;
        vector<int>pos;*/
        map<int,int>num;
        map<int,int>next;
        map<int,int>pos;

        flag=1;

        if(K>N || (K>3 && K>M))
        {
            flag=0;
        }
        else if(K<4)
        {
            Min=K;
        }
        else
        {
            /*int pos[N+1];
            int next[N+1];
            int num[N+1];*/

            for(j=1; j<=3; j++)
            {
                num[j]=j;
                //pos[j]=j;
                next[j]=j;
            }

            //num[1]=1,num[2]=2,num[3]=3;
            //pos[1]=1,pos[2]=2,pos[3]=3;
            //ara[j++]=1,ara[j++]=2,ara[j++]=3;

            for(i=4,j=3; i<=N; i++)
            {
                num[i]=((num[i-1]+num[i-2]+num[i-3])%M)+1;

                if(num[i]<=K)
                {
                    next[++j]=i;
                }
            }

            /*for(i=1;i<=N;i++)
            {
                cout << num[i] << " ";
            }
            cout << endl;*/

            total=j;

            /*cout << "total= " << total << endl;
            for(i=1; i<=total; i++)
            {
                cout << next[i] << " ";
            }
            cout << endl;*/


            for(i=1; i<=K; i++)
            {
                pos[i]=0;
            }

            Min = 1000001;
            cnt=0;
            low=1;

            for(i=1; i<=total; i++)
            {
                if(pos[num[next[i]]]==0)
                {
                    cnt++;
                    pos[num[next[i]]]=next[i];
                    if(cnt==K)
                    {
                        hp=i;
                        high=next[hp];
                        Minx=high-low+1;
                        break;
                    }
                }
                else
                {
                    pos[num[next[i]]]=next[i];
                }
            }

            /*for(j=1;j<=4;j++)
            {
                cout << pos[j] << " ";
            }
            cout << endl;*/

            /*for(low=1; low<=total; low++)
            {
                cout << pos[num[next[low]]] << " ";
            }
            cout << endl;*/

            /*for(j=1,low=1;j<10; j++)
            {
                low=next[low+1];
                cout << low << " ";
            }
            cout << endl;*/

            if(i>total || cnt<K)
            {
                flag=0;
            }
            else
            {
                //cout << Min << endl;
                if(Minx<Min)
                {
                    Min=Minx;
                    //cout << Min << endl;
                }
                lp=1;
                while(lp<=total-K && hp<=total)
                {
                    if(pos[num[next[lp]]] <= high && pos[num[next[lp]]] != next[lp])
                    {
                        low=next[lp+1];
                        //high=
                        Minx=high-low+1;
                        if(Minx<Min)
                        {
                            Min=Minx;
                            //cout << lp << " " << Min << endl;
                        }
                    }
                    else
                    {
                        while(hp<=total)
                        {
                            if(num[next[lp]]==num[next[hp]])
                            {
                                low=next[lp+1];
                                high=next[hp];
                                Minx=high-low+1;

                                if(Minx<Min)
                                {
                                    Min=Minx;
                                    //cout << lp << " " << Min << endl;
                                }
                                pos[num[next[hp]]]=next[hp];
                                break;
                            }
                            pos[num[next[hp]]]=next[hp];
                            hp++;
                        }

                    }

                    lp++;
                }
            }

        }

        if(flag==1)
        {
            cout << "Case " << test << ": " << Min << endl;
        }
        else
        {
            cout << "Case " << test << ": sequence nai" << endl;
        }
    }

    return 0;
}
