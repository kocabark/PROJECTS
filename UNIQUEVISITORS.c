#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int uniqvisitno(int arr[], int a, int b){
    int i,j;
    int count = 0;
    int broken;
    for(i = a; i <= b; i++){
        broken = 0;
        for(j = i+1; j <= b; j++){
            if(arr[i] == arr[j] && i != j){
                broken = 1;
                break;
            }
        }

        if(!broken){
            ++count;
        }
    }
    return count;
}


int main (){
    int uid[1000000];
    int hist[100000] = {0};
    char command = 0;
    int a = 0, b = 0;
    int x;
    int cnt = 0;
    

    printf("Requests:\n");
     
    while (scanf(" %c", &command) == 1 ) {
        if (command != '+' && command != '?' )
        {
            printf("Invalid input.\n");
            return 2;
        }
        if (command == '+'){
            if ( scanf ("%d", &x) != 1 || x > 99999 || x < 0){
            printf("Invalid input.\n");
            return 0;
            }
            
            uid[cnt] = x;
            cnt++;
            
            hist[x]++;

            if( hist[x] == 1 ){
                printf("> first visit\n");
            }
            else{
                printf("> visit #%d\n", hist[x]);
            }

        }
        else if( command  == '?'){
            if ( scanf ("%d %d", &a, &b) != 2 || a < 0 || a > b || b >= cnt ) {
            printf("Invalid input.\n");
            return 0;
                }
            printf("> %d / %d\n", uniqvisitno(uid, a, b), b - a + 1);
            }
    }
    if (!feof(stdin)) {
        printf("Invalid input.\n");
        return 1;
    }
    
    return 0;
}



