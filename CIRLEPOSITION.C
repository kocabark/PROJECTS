#include <stdio.h>
#include <math.h>
#define EPS 1e-12
const double PI = 3.14159265358979323846;

int DoubleEqual(double a, double b){
   return fabs(a - b) < EPS * 1000 * (fabs(a) + fabs(b));
}



int main (void){
double x1, x2, y1, y2, r1, r2;

printf("Enter circle #1 parameters:\n");
if(scanf (" %lf %lf %lf", &x1,&y1, &r1) != 3 || r1 <= 0 ){
    printf("Invalid input.\n");
    return 0;
}

printf("Enter circle #2 parameters:\n");
if(scanf (" %lf %lf %lf", &x2 ,&y2, &r2) != 3 || r2 <= 0 ){
    printf("Invalid input.\n");
    return 0;
}


double dist1 = x1 - x2;
double dist2 = y1 - y2;
double d = sqrt( pow(dist1,2) + pow(dist2,2) );
double tmp;
int x = 0, y = 0;

if (r2 > r1){
    y = 2;
    x = 1;
} else if ( r1 > r2){
    y = 1;
    x = 2;
}



if( r2 > r1){
    tmp = r2;
    r2 = r1;
    r1 = tmp;
    }// r2 always the small cirle.
double Area = PI * r2 * r2;
double h1 =  ((d * d) - (r2 * r2) + (r1 * r1)) / (2 * d);
double h2 = d - h1;
double areacirc1 = (r1 * r1) * (acos(h1 / r1) )  -h1 * sqrt(fabs( (r1 * r1) - (h1 * h1) ));
double areacirc2 = (r2 * r2) * (acos(h2 / r2) )  -h2 * sqrt(fabs( (r2 * r2) - (h2 * h2) ));
double overlap = areacirc1 + areacirc2;


    if ( DoubleEqual(x1,x2) && DoubleEqual(y1,y2) && DoubleEqual(r1,r2)){
        printf("The circles are identical, overlap: %lf\n", Area);
        return 0;
        // overlap is the area they have in common.
    }
    else if ( DoubleEqual( d, r1 + r2 ) ){
        printf("External touch, no overlap.\n");
        return 0;
    }
    else if ( DoubleEqual( d, r1 - r2 ) ){
        printf("Internal touch, circle #%d lies inside circle #%d, overlap: %lf\n", x, y, Area);
        return 0;
    }
    else if ( r1 - r2 < d && d < r1 + r2){
        printf("The circles intersect, overlap: %lf\n", overlap);

    }
    else if ( d <= fabs(r1 - r2) ){
        
        printf("Circle #%d lies inside circle #%d, overlap: %lf\n", x, y, Area);   
    }
    else {
        printf("The circles lie outside each other, no overlap.\n");
    }
    

}


