#include<stdio.h>
int main()
{
    int T, Term1, Term2, Final, Attendance, Class_Test1, Class_Test2, Class_Test3, max1, max2, Class_Test, Total_marks,i;

    scanf("%d",&T);
    for(i=1; i<=T; i++)
    {
        scanf("%d %d %d %d %d %d %d",&Term1, &Term2, &Final, &Attendance, &Class_Test1, &Class_Test2, &Class_Test3);

        if(Class_Test1 <= Class_Test2 && Class_Test1 <= Class_Test3)
        {
            max1=Class_Test2;
            max2=Class_Test3;
        }
        else if(Class_Test2 <= Class_Test1 && Class_Test2 <= Class_Test3)
        {
            max1=Class_Test1;
            max2=Class_Test3;
        }
        else
        {
            max1=Class_Test1;
            max2=Class_Test2;
        }

        Class_Test=(max1+max2)/2;

        Total_marks=(Term1+Term2+Final+Attendance+Class_Test);

        if(Total_marks >= 90)
            printf("Case %d: A\n",i);

        else if(Total_marks >= 80 && Total_marks < 90)
            printf("Case %d: B\n",i);

        else if(Total_marks >= 70 && Total_marks < 80)
            printf("Case %d: C\n",i);

        else if(Total_marks >= 60 && Total_marks < 70)
            printf("Case %d: D\n",i);

        else
            printf("Case %d: F\n",i);
    }

    return 0;
}
