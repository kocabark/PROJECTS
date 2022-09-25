#include <stdio.h>
#include <math.h>

int main(){
    double num1, num2;
    char sign, equal;
    double sum;

    printf("Type formula:\n");
    
    if ((scanf(" %lf %c %lf %c", &num1, &sign, &num2, &equal) !=4 ) || equal != '=') {
        printf("Invalid input.\n");
    }
    else if ( sign == '+' ){
    // g format specifier kullan hallolsun
    printf("%g\n", num1 + num2);
    return 0;
    }
    else if( sign == '-' ){
    printf("%.15lf\n", num1 - num2);
    return 0;
    }
    else if( sign == '*' ){
    sum = num1 * num2;
        if ( fabs(sum) < 1e-6 || fabs(sum) > 1e6 )
    printf("%g\n", sum);
        else {
    printf("%.15lf\n", sum);
        }
    return 0;
    }
    else if( sign == '/' && num2 != 0){
        if ( num1 * num2 < 0 ){
      sum = ceil(num1 / num2);
        } else {
    sum = floor(num1 / num2);
    }
    printf("%g\n", sum);
    return 0;
    }
    else{
    printf("Invalid input.\n");
    }


}

