#include <stdio.h>

int main(void){
    char bracket = ')';
    int red, green, blue;
    printf("Type color in RGB format:\n");

    if (scanf(" rgb ( %d , %d , %d %c", &red, &green, &blue, &bracket ) != 4)  {
        printf("Invalid input.\n");
        return 0;
    }
        if( ( red >= 0 && red <= 255 ) && ( green >= 0 && green <= 255 ) && ( blue >= 0 && blue <= 255 ) && bracket == ')' ){
            printf("#%.2X%.2X%.2X\n", red, green, blue);
            return 0;
        
    }else{
    printf("Invalid input.\n");
    return 0;
    }

  
}
