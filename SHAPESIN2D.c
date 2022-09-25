#include <stdio.h>
#include <math.h>
#define EPS 1e-12

int DoubleEqual(double a, double b){
   return fabs(a - b) < EPS * 1000 * (fabs(a) + fabs(b));
}

int main (){
    char shape1 =0, shape2 = 0;
    double a =0, b =0, c =0;
    double x =0, y =0, z =0;
    double area1 =0, perimeter1 =0, area2 =0, perimeter2 =0;
    double s1 =0, s2 =0;
    int shp1 =0, shp2 =0;
    printf("Shape #1\n");
        if ( scanf(" %c ", &shape1) != 1 || ( shape1 != 'S' && shape1 != 'R' && shape1 != 'T') ){
        printf("Invalid input.\n");
        return 0;
        }
        
        // ELSE IF
        if( shape1 == 'T'){
            if ( scanf("%lf %lf %lf", &a, &b, &c) != 3 || a + b < c || DoubleEqual(c,a+b) || a + c < b || DoubleEqual(b,a+c) || b + c < a || DoubleEqual(a,b+c) || a <= 0|| b <= 0 || c <= 0){
                printf("Invalid input.\n");
                return 0;
            }
            else{
                s1 = ( a + b + c ) / 2;
                area1 = sqrt(s1 * ( (s1-a) * (s1-b) * (s1-c) ));
                perimeter1 = a + b + c;
                shp1 = 3;
            }
        }
        else if( shape1 == 'R'){
            if ( scanf("%lf %lf", &a, &b) != 2 || DoubleEqual(a,b) || a <= 0 || b <= 0){
                printf("Invalid input.\n");
                return 0;
            }
            else{
                area1 = a * b;
                perimeter1 = ( 2 * a ) + ( 2 * b);
                shp1 = 2;
            }
        }
        else if( shape1 == 'S'){
            if ( scanf("%lf", &a) != 1 || a <= 0 ){
                printf("Invalid input.\n");
                return 0;
            }
            else{
                area1 = pow(a,2);
                perimeter1 = 4 * a;
                shp1 = 1;
            }
        }
        else{
            printf("Invalid input.\n");
        }
       
    printf("Shape #2\n");
    if ( scanf(" %c ", &shape2) != 1 && ( shape2 != 'S' && shape2 != 'R' && shape2 != 'T') ){
        printf("Invalid input.\n");
        return 0;
        }
        
        
        else if( shape2 == 'T'){
            if ( scanf("%lf %lf %lf", &x, &y, &z) != 3 || x + y < z || DoubleEqual (z,x+y) || x + z < y || DoubleEqual(y,x+z) || y + z < x || DoubleEqual(x,y+z) || x <= 0 || y <= 0 || z <= 0){
                printf("Invalid input.\n");
                return 0;
            }
            else{
                s2 = ( x + y + z ) / 2;
                area2 = sqrt(s2 * ( (s2-x) * (s2-y) * (s2-z) ));
                perimeter2 = x + y + z;
                shp2 = 3;
            }
        }
        else if( shape2 == 'R'){
            if ( scanf("%lf %lf", &x, &y) != 2 || DoubleEqual(x,y) || x <= 0 || y <= 0){
                printf("Invalid input.\n");
                return 0;
            }
            else{
                area2 = x * y;
                perimeter2 = ( 2 * x ) + ( 2 * y);
                shp2 = 2;
            }
        }
        else if( shape2 == 'S'){
            if ( scanf("%lf", &x) != 1 || x <= 0 ){
                printf("Invalid input.\n");
                return 0;
            }
            else{
                area2 = pow(x,2);
                perimeter2 = 4 * x;
                shp2 = 1;
            }
        }
        else{
            printf("Invalid input.\n");
        }
    


         //redundent 

        if ( shp1 == 3 && shp2 == 3){ // T  T
            if (DoubleEqual(perimeter1,perimeter2)){
            printf("Perimeter: triangle #1 = triangle #2\n");
            }
            else if (perimeter1 < perimeter2){
            printf("Perimeter: triangle #1 < triangle #2\n");
            }
            else{
            printf("Perimeter: triangle #1 > triangle #2\n");
            }
            // space..
            if (DoubleEqual(area1,area2)){
            printf("Area: triangle #1 = triangle #2\n");
            }
            else if (area1 < area2){
            printf("Area: triangle #1 < triangle #2\n");
            }
            else{
            printf("Area: triangle #1 > triangle #2\n");
            }

        }
        else if ( shp1 == 3 && shp2 == 2){ // T  R
            if (DoubleEqual(perimeter1,perimeter2)){
            printf("Perimeter: triangle #1 = rectangle #2\n");
            }
            else if ( perimeter1 < perimeter2){
            printf("Perimeter: triangle #1 < rectangle #2\n");    
            }
            else{
            printf("Perimeter: triangle #1 > rectangle #2\n");
            }
            // space..
            if (DoubleEqual(area1,area2)){
            printf("Area: triangle #1 = rectangle #2\n");  
            }
            else if ( area1 < area2){
            printf("Area: triangle #1 < rectangle #2\n");
            }
            else{
            printf("Area: triangle #1 > rectangle #2\n");
            }
        }

        else if ( shp1 == 3 && shp2 == 1){ // T  S
            if (DoubleEqual(perimeter1,perimeter2)){
            printf("Perimeter: triangle #1 = square #2\n");
            }
            else if (perimeter1< perimeter2){
            printf("Perimeter: triangle #1 < square #2\n");
            }
            else{
            printf("Perimeter: triangle #1 > square #2\n");
            }
            // space..
            if (DoubleEqual(area1,area2)){
            printf("Area: triangle #1 = square #2\n");
            }
            else if( area1 < area2){
            printf("Area: triangle #1 < square #2\n");
            }
            else{
            printf("Area: triangle #1 > square #2\n");
            }

        }
        else if ( shp1 == 2 && shp2 == 3){ // R  T
            if (DoubleEqual(perimeter1,perimeter2)){
            printf("Perimeter: rectangle #1 = triangle #2\n");
            }
            else if(perimeter1 < perimeter2){
            printf("Perimeter: rectangle #1 < triangle #2\n");
            }
            else{
            printf("Perimeter: rectangle #1 > triangle #2\n");
            }
            // space..
            if (DoubleEqual(area1,area2)){
            printf("Area: rectangle #1 = triangle #2\n");
            }
            else if(area1 < area2){
            printf("Area: rectangle #1 < triangle #2\n");
            }
            else{
            printf("Area: rectangle #1 > triangle #2\n");
            }

        }
        else if ( shp1 == 2 && shp2 == 2){ // R R
            if ( DoubleEqual(perimeter1,perimeter2)){
            printf("Perimeter: rectangle #1 = rectangle #2\n");
            }
            else if ( perimeter1 < perimeter2){
            printf("Perimeter: rectangle #1 < rectangle #2\n");
            }
            else{
            printf("Perimeter: rectangle #1 > rectangle #2\n");
            }
            // space..
            if ( DoubleEqual(area1,area2)){
            printf("Area: rectangle #1 = rectangle #2\n");
            }
            else if ( area1 < area2){
            printf("Area: rectangle #1 < rectangle #2\n");
            }
            else{
            printf("Area: rectangle #1 > rectangle #2\n");
            }

        }
        else if ( shp1 == 2 && shp2 == 1){ // R S
            if ( DoubleEqual(perimeter1,perimeter2)){
            printf("Perimeter: rectangle #1 = square #2\n");
            }
            else if( perimeter1 < perimeter2){
            printf("Perimeter: rectangle #1 < square #2\n");
            }
            else{
            printf("Perimeter: rectangle #1 > square #2\n");
            }
            // space..
            if (DoubleEqual(area1,area2)){
            printf("Area: rectangle #1 = square #2\n");
            }
            else if(area1 < area2){
            printf("Area: rectangle #1 < square #2\n");
            }
            else{
            printf("Area: rectangle #1 > square #2\n");
            }

        }
        else if ( shp1 == 1 && shp2 == 3){ // S T
            if ( DoubleEqual(perimeter1,perimeter2)){
            printf("Perimeter: square #1 = triangle #2\n");
            }
            else if ( perimeter1 < perimeter2){
            printf("Perimeter: square #1 < triangle #2\n");
            }
            else{
            printf("Perimeter: square #1 > triangle #2\n");
            }
            // space..
            if(DoubleEqual(area1,area2)){
            printf("Area: square #1 = triangle #2\n");
            }
            else if ( area1 < area2){
            printf("Area: square #1 < triangle #2\n");
            }
            else{
            printf("Area: square #1 > triangle #2\n");
            }  

        }
        else if ( shp1 == 1 && shp2 == 2){ // S R
            if (DoubleEqual(perimeter1,perimeter2)){
            printf("Perimeter: square #1 = rectangle #2\n");
            }
            else if (perimeter1 < perimeter2){
            printf("Perimeter: square #1 < rectangle #2\n");
            }
            else{
            printf("Perimeter: square #1 > rectangle #2\n");
            }
            // space..
            if (DoubleEqual(area1,area2)){
            printf("Area: square #1 = rectangle #2\n");
            }
            else if( area1 < area2){
            printf("Area: square #1 < rectangle #2\n");
            }
            else{
            printf("Area: square #1 > rectangle #2\n");
            }
        }
        else if ( shp1 == 1 && shp2 == 1){ // S S
            if (DoubleEqual(perimeter1,perimeter2)){
            printf("Perimeter: square #1 = square #2\n");
            }
            else if ( perimeter1 < perimeter2){
            printf("Perimeter: square #1 < square #2\n");
            }
            else{
            printf("Perimeter: square #1 > square #2\n");
            }
            // space..
            if (DoubleEqual(area1,area2)){
            printf("Area: square #1 = square #2\n");
            }
            else if( area1 < area2){
            printf("Area: square #1 < square #2\n");
            }
            else{
            printf("Area: square #1 > square #2\n");
            }

        }
        return 0;

}
