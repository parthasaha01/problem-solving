#include <stdio.h>
#include <string.h>
int main()
{
    int test, j, k, flag, L;
    char input[1000];

    scanf("%d", &test);
    getchar();

    while(test--)
    {

        gets(input);
        L = strlen(input);

        int stck[500] = {0};
        k=0;
        flag=1;

        for(j=0; j<L; j++)
        {
            if( input[j]=='(' )
            {
                stck[k]=1;
                k++;
            }
            else if( input[j]=='[' )
            {
                stck[k]=3;
                k++;
            }
            else if( input[j]==')' )
            {
                    if(k-1>=0)
                    {
                        if(stck[k-1]==1)
                        {
                            stck[k-1]=0;
                            k--;
                        }
                        else
                        {
                            flag=0;
                            break;
                        }
                    }
                    else
                    {
                        flag=0;
                        break;
                    }

            }
            else
            {
                if(k-1>=0)
               {
                    if(stck[k-1]==3)
                    {
                        stck[k-1]=0;
                        k--;
                    }
                    else
                    {
                        flag=0;
                        break;
                    }
                }
                else
                {
                    flag=0;
                    break;
                }
            }


        }

      if(flag==1 && stck[0]==0)
        printf("Yes\n");
      else
        printf("No\n");

    }

    return 0;
}
