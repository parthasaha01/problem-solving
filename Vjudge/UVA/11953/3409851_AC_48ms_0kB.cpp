#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
bool col[999][999];
char s[200][200];
int  node, edge;
int k,flag=0;
int color;

void coloring(int i,int j)
{
    col[i][j]=1;

    if(s[i][j]=='x'||s[i][j]=='@')
    {
        if(!col[i][j+1])
       coloring(i,j+1);
       if(!col[i][j-1])
       coloring(i,j-1);
       if(!col[i+1][j])
       coloring(i+1,j);
       if(!col[i-1][j])
       coloring(i-1,j);
    }

}

/*void dfs(int i)
{
    col[i] = true;

    for (int j = 1; j <=node; j++)
    {


        if (g[i][j] == 1)
        {
            //cout<<g[i][j]<<endl;

            if(!col[j])
               {

                   dfs(j);

               }
        }

    }
}*/
int main()
{
    int u, v,i,j,count,a,c,row,colomn;

    cin>>a;

    for(c=1;c<=a;c++)
    {

    cin >> row;
        count=0;
        //cin>>colomn;

        flag=0;
        for(i=1;i<=row;i++)
        {
            for(j=1;j<=row;j++)
            {
                cin>>s[i][j];
            }
        }

        for(i=1;i<=row;i++)
        {
            for(j=1;j<=row;j++)
            {
                if(!col[i][j])
                {
                    if(s[i][j]=='x')
                    {

                        count++;
                        coloring(i,j);


                    }
                }
            }
        }


        cout<<"Case "<<c<<": "<<count<<endl;

//Clear

      for(i=0;i<201;i++)
      {
          for(j=0;j<201;j++)
            col[i][j]=false;
      }

      for(i=0;i<201;i++)
      {
          for(j=0;j<201;j++)
            s[i][j]='.';
      }





    }
    return 0;
}


