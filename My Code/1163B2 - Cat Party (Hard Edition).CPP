#include<bits/stdc++.h>
using namespace std;
int a[100005];
int n, cnt[100005],temp[100005], tot=0;
set<int>ss;
map<int,int>mp;
map<int,int>pp;
int check(int pos){

    if(ss.size()>2)return 0;


    if(ss.size()==1){
        if(tot==pos || tot==1){
            //a
            //printf("a tot=%d pos=%d\n",tot,pos);
            return 1;
        }

        //b
        //printf("b tot=%d pos=%d\n",tot,pos);
        return 0;
    }else if(ss.size()==2){
        int minn = 10000000,maxx=0;
        for(auto it=ss.begin(); it!=ss.end(); it++){
            minn = min(minn,(*it));
            maxx = max(maxx,(*it));
        }
        //c
        //printf("c minn=%d maxx=%d\n",minn,maxx);

        if(minn==1){
            if(temp[minn]==1){
                if(temp[maxx]==tot-1){
                    //e
                    //printf("e temp[minn]=%d temp[maxx]=%d tot=%d\n",temp[minn],temp[maxx],tot);
                    return 1;
                }else{
                    //f
                    //printf("f temp[minn]=%d temp[maxx]=%d tot=%d\n",temp[minn],temp[maxx],tot);
                    return 0;
                }
            }else{
                if(temp[minn]==tot && maxx==minn){
                    //g
                    //printf("g temp[minn]=%d temp[maxx]=%d tot=%d minn=%d maxx=%d\n",temp[minn],temp[maxx],tot,minn,maxx);
                    return 1;
                }else if(temp[minn]==tot-1 && (minn+1)==maxx){
                    //x
                    //printf("x temp[minn]=%d temp[maxx]=%d tot=%d minn=%d maxx=%d\n",temp[minn],temp[maxx],tot,minn,maxx);
                    return 1;
                }else{
                    //h
                    //printf("h temp[minn]=%d temp[maxx]=%d tot=%d minn=%d maxx=%d\n",temp[minn],temp[maxx],tot,minn,maxx);
                    return 0;
                }
            }
        }else{
            if(temp[maxx]==1){
                if(temp[minn]==tot-1 && (minn+1)==maxx){
                    //i
                    //printf("i temp[minn]=%d temp[maxx]=%d tot=%d minn=%d maxx=%d\n",temp[minn],temp[maxx],tot,minn,maxx);
                    return 1;
                }else{
                    //j
                    //printf("j temp[minn]=%d temp[maxx]=%d tot=%d minn=%d maxx=%d\n",temp[minn],temp[maxx],tot,minn,maxx);
                    return 0;
                }
            }else{
                //k
                //printf("k temp[minn]=%d temp[maxx]=%d tot=%d minn=%d maxx=%d\n",temp[minn],temp[maxx],tot,minn,maxx);
                return 0;
            }
        }
    }
}
int main() {

    memset(cnt,0,sizeof(cnt));
    memset(temp,0,sizeof(temp));
    ss.clear();
    mp.clear();
    pp.clear();
    tot = 0;

    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }
    int ans = 1;

    for(int i=1; i<=n; i++){
        cnt[a[i]]++;
        mp[a[i]]++;
        if(cnt[a[i]]==1){
            tot++;
        }

		if(temp[cnt[a[i]]-1]>0){
			temp[cnt[a[i]]-1]--;
			if(temp[cnt[a[i]]-1]==0){
            	ss.erase(cnt[a[i]]-1);
        	}
		}
        temp[cnt[a[i]]]++;

        ss.insert(cnt[a[i]]);
        //printf("\n");
        //printf("pos=%d size=%d tot=%d\n",i,ss.size(),tot);
//        for(auto it=ss.begin(); it!=ss.end(); it++){
//            cout<<(*it)<<" ";
//        }
        //cout<<endl;
        if(check(i)){
            ans = max(ans,i);
        }
    }

    printf("%d\n",ans);

    //main();

    return 0;
}

