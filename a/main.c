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
    for(int i=7;i>=0;)
    {
        while(i==7)
        {
            array[i]=number/dzielnik;
            i--;
        }
        while(i>=0){
        array[i]=number/dzielnik%10;
        dzielnik=dzielnik/10;
        printf("%ld \n",array[i]);
        i--;
        }
    }
    //for(int o=0;o<7;o++)
    //printf(" %ld", array[o]);
    return 0;
}
