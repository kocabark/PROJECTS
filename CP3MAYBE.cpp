#include <stdio.h> 
#include <math.h>
#include <stdlib.h>
  
// C Program to convert decimal to any given base 
#include <stdio.h> 
#include <string.h> 
  
// To return char for a value. For example '2' 
// is returned for 2. 'A' is returned for 10. 'B' 
// for 11 
char reVal(int num) 
{ 
    if (num >= 0 && num <= 9) 
        return (char)(num + '0'); 
    else
        return (char)(num - 10 + 'a'); 
} 
  
// Utility function to reverse a string 
void strev(char *str) 
{ 
    int len = strlen(str); 
    int i; 
    for (i = 0; i < len/2; i++) 
    { 
        char temp = str[i]; 
        str[i] = str[len-i-1]; 
        str[len-i-1] = temp; 
    } 
} 
  
// Function to convert a given decimal number 
// to a base 'base' and 
char* fromDeci(char res[], int base, int inputNum) 
{ 
    int index = 0;  // Initialize index of result 
  
    // Convert input number is given base by repeatedly 
    // dividing it by base and taking remainder 
    while (inputNum > 0) 
    { 
        res[index++] = reVal(inputNum % base); 
        inputNum /= base; 
    } 
    res[index] = '\0'; 
  
    // Reverse the result 
    strev(res); 
  
    return res; 
} 
  
 





// Driver program to test above functions 
int main() 
{ 
  char X, res[100];
  int v, i = 0, temp = 0, reverse_i = 0, remainder = 0, counter = 0;  
  long long int R, LO, HI; 
  

    printf("Intervals:\n");
    
     
    
    while(1)
  {
    v = scanf("%s %lld %lld %lld", &X, &R, &LO, &HI);
    if(v==EOF) 
    break;
     //also put scanf into for or while loop below
    if(v!=4)
    {
    printf("Invalid input.\n");
    return 0;
    }
   
    if ((X != 'c' && X != 'l') || (v!=4))
     {
    printf("Invalid input.\n");
    return 0;
     }
     
    if(LO>HI || LO<0 || R < 2 || R > 36 || v!=4)
     {
     printf("Invalid input.\n");
     return 0;
     }
     
       for(i = LO; i <= HI; i++)
  
    {
   //* get the number and base 
   //printf("Enter number and desired base: ");
   //scanf("%ld %i", &number_to_convert, &base);
   //scanf("%c %lld %lld %lld", &X, &R, &LO, &HI);    
         temp = i;
         reverse_i = 0;
         //printf("%d = %d (%lld)\n", i, DecToAnyBase(base,i), R);
         while (temp)
         {
            remainder = temp % R;
            temp = temp / R;
            reverse_i = reverse_i * R + remainder;
         }
     if ( X == 'c' && i == reverse_i )
        {
        fromDeci(res, R, i);
        counter++;
        } 
     if ( X == 'l' && i == reverse_i )
        {
            printf("%d = ", i);
            if(i==0){
                printf("0");
            }
            printf("%s (%lld)\n", fromDeci(res, R, i),R);
            

        }
    }
    if(X=='c'){
        printf("Total: %d\n", counter);
        counter = 0;
    }
  }
}
 





  
