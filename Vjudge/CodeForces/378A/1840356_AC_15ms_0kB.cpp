#include<cstdio>
using namespace std;
int main()
{
    int a,  b, AW, BW, DR, da, db, i;

    while(scanf("%d %d", &a, &b)==2)
    {
        AW=BW=DR=0;
        for(i=1; i<=6; i++)
        {
            da=a-i;
            db=b-i;

            if(da<0)
                da=-da;
            if(db<0)
                db=-db;

            if(da==db)
            {
                ++DR;
            }
            else if(da < db)
            {
                ++AW;
            }
            else
            {
                ++BW;
            }

        }

        printf("%d %d %d\n",AW,DR,BW);
    }

    return 0;
}
