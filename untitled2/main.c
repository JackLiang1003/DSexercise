#include <stdio.h>

int main( )
{
    int sum = 0;
    printf("\t");
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <=9 ; ++j) {
            for (int k = 1; k <=9 ; ++k) {
                if((k!=j)&&(j!=i)&&(k!=i)){
                    printf("%d%d%d\t",k,j,i);
                    sum ++;
                }
            }
        }
    }
    printf("\n\t");

    printf("sum =%d",sum);
    return 0;
}
