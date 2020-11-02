#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int a=7;
    char array[7];
    int dzielnik=1000000;
    srand(time(NULL));
    long number = rand();
    number=number*100;
    printf("%ld \n",number);
    for(int i=0;i<=7;i++)
    {
        while(i<1)
        {
            array[i]=number/dzielnik;
            i++;
        }
        array[i]=number/dzielnik%10;
        dzielnik=dzielnik/10;
        printf("%ld \n",array[i]);

    }
    return 0;
}
