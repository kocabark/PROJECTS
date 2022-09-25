#include <stdio.h>
#include <math.h>

int countDigit(int n)
{
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        ++count;
    }
    return count;
}

int main(void)
{
    int i, j;
    int limit;
    printf("Limit:\n");
    if (scanf("%d", &limit) != 1 )
    {
        printf("Invalid input.\n");
        return 0;
    }
    if (limit <= 0){
        printf("Invalid input.\n");
        return 0;
    }
    //print columns
    int spacing = countDigit(limit * limit);
    printf("%*c| ", spacing, ' ');
    // print rows
    for (i = limit; i > 0; i--)
    {
        if (i == 1){
        printf("%*d", spacing, i);
        }else{
        printf("%*d ", spacing, i);
        }
    }
    printf("\n");

    //inside of multlipication
    for (i = 0; i <= limit; i++)
    {
        if (i == 0)
        {
            for (int k = 0; k < spacing; k++)
            {
                printf("-");
            }
            printf("+");
        }
        else
        {

            printf("%*d|", spacing, i);
        }
        for (j = limit; j > 0; j--)
        {
            if (i * j == 0)
            {
                int sep = limit + (spacing * limit);
                for (int k = 0; k < sep; k++)
                {
                    printf("-");
                }
                break;
            }
            else
            {
                if (i <= j)
                {
                    printf(" %*d", spacing, i * j);
                }
            }
        }
        printf("\n");
    }
}
