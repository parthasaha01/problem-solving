#include<bits/stdc++.h>
using namespace std;
//char ans[200050];
char s[100005];
int main()
{
    while(scanf("%s",s)!=EOF)
    {
        //printf("%s\n",s);
        int n = strlen(s);
        //int fst,cur,lst;
        //fst = 100005;
        //lst = 100005;
        //cur = 100005;
        //int home = 1;
        deque<char>dq;

        for(int i=0; i<n; i++)
        {
            if(s[i]=='[')
            {
                stack<char>st;
                while(i+1<n && (s[i+1]!='[' && s[i+1]!=']'))
                {
                    //cout << s[i+1] << endl;
                    st.push(s[i+1]);
                    i++;
                }
                while(!st.empty())
                {
                    //printf("%c\n",st.top());
                    dq.push_front(st.top());
                    st.pop();
                }
            }
            else if(s[i]==']')
            {

            }
            else
            {
                dq.push_back(s[i]);
            }

            //fst = min(fst,cur);
            //lst = max(lst,cur);
        }

        while(!dq.empty())
        {
            printf("%c",dq.front());
            dq.pop_front();
        }
        printf("\n");
    }

    return 0;
}
