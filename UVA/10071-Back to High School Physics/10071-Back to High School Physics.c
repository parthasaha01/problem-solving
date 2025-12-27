#include<stdio.h>
int main()
{
    int v,t,s;

    while(scanf("%d %d",&v,&t) == 2)
    {
        s=2*v*t;
        printf("%d\n",s);
    }
    return 0;
}

/* t---------v
     0--------0(v=u)
     12-------5  , so a=(v-u)/t=v/t
(2*12)------?,so s = 0.5*a*t*t = 0.5*(v/t)*(2t)*(2t) = 2*v*t */
