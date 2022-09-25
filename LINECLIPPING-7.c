#ifndef __PROGTEST__
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <assert.h>
#endif /* __PROGTEST__ */
int almostEqual5( double x, double y )
{
    if (fabs(x-y)<10e-12*fabs(x+y))
        return 1;
    return 0;
}
typedef unsigned int outcode;
const outcode INSIDE = 0; // 0000
const outcode LEFT = 1;   // 0001
const outcode RIGHT = 2;  // 0010
const outcode BOTTOM = 4; // 0100
const outcode TOP = 8;    // 1000
int compute_outcode(double x, double y,double xmin,double ymin,double xmax,double ymax)//ymax ymin vs global variable olarak tanitilabilir
{
     int anana;
     anana = 0;
    if((almostEqual5(y,fmax(ymin,ymax))) || (almostEqual5(y,fmin(ymin,ymax))))
    {
        anana |= INSIDE;
    }
    else if (y > fmax(ymin,ymax))
	{
        anana |= TOP;
        printf("A.\n");
    }
    else if (y < fmin(ymin,ymax))
    {
        anana |= BOTTOM;
        printf("B.\n");
    }

    if ((almostEqual5(x,fmax(xmin,xmax))) || (almostEqual5(x,fmin(xmin,xmax))))
    {
        anana |= INSIDE;
    }
    else if (x > fmax(xmin,xmax))
    {
        anana |= RIGHT;
        printf("R.\n");
    }
    else if (x < fmin(xmin,xmax))
	{
        anana |= LEFT;
        printf("L.\n");
    }


    return anana;
}


int clipLine(double rx1,double ry1,double rx2,double ry2,double * ax,double * ay,double * bx,double * by )//pointlerlari function icinde farkli kullanman gerekebilir check et.
{

   double axx, ayy, bxx, byy;
    *ax *= 10e5;
    *ay *= 10e5;
    *by *= 10e5;
    *bx *= 10e5;
    rx1 *= 10e5;
    rx2 *= 10e5;
    ry1 *= 10e5;
    ry2 *= 10e5;
    axx = *ax;
    ayy = *ay;
    bxx = *bx;
    byy = *by;



    int outcode1 = compute_outcode (*ax, *ay, rx1, ry1, rx2, ry2);
    printf("%d\n", outcode1);
    int outcode2 = compute_outcode (*bx, *by, rx1, ry1, rx2, ry2);
    printf("%d\n", outcode2);


    while(1)
 {
    if ( (outcode1 == INSIDE) && (outcode2 == INSIDE) )//if (!(outcode0 | outcode1)) or if ((outcode0 | outcode1) == false ) or ((outcode0 | outcode1)  )
	{
        printf("1.1if\n");
        break;
	}
    else if (outcode1 & outcode2)  // conditiondan emin ol tekrar cek et
    {
        if(fabs(*ax-*bx)<=10e-12*fabs(*ax+*bx) && fabs(*ay-*by)<=10e-12*fabs(*ay+*by))
        {
    *ax = axx/10e5;
    *ay = ayy/10e5;
    *bx = bxx/10e5;
    *by = byy/10e5;
        }
        else
        {
    *ax /= 10e5;
    *ay /= 10e5;
    *bx /= 10e5;
    *by /= 10e5;
        }

        printf("0elseif\n");
        return 0;
	}else{
        double x = 0, y = 0;
        //check to see atleast one endpoint outside the window rectangle.
        int outcode_ex = outcode1 ? outcode1 : outcode2;
        //calculating intersection point by using slopes and ABRL region code.
	    if (outcode_ex & 8){
            x = * ax + (* bx - * ax) * (fmax(ry2,ry1) - * ay) / (* by - * ay);
            y = fmax(ry1,ry2);
	    }else if (outcode_ex & 4){
            x = * ax + (* bx - * ax) * (fmin(ry1,ry2) - * ay) / (* by - * ay);
            y = fmin(ry1,ry2);
	    }else if (outcode_ex & 2){
            y = * ay + (* by  - * ay) * (fmax(rx2,rx1) - * ax) / (* bx - * ax);
            x = fmax(rx1,rx2);
	    }else if (outcode_ex & 1){
            y = * ay + (* by  - * ay) * (fmin(rx1,rx2) - * ax) / (* bx - * ax);
            x = fmin(rx1,rx2);
	    }


	    //replaceing endpoint outside the rectangle by intersection the endpoint
        if (outcode_ex == outcode1){
            *ax = x;
            *ay = y;
            outcode1 = compute_outcode (* ax, * ay, rx1, ry1, rx2, ry2);

	    }else{
            *bx = x;
            *by = y;
            outcode2 = compute_outcode (* bx, * by, rx1, ry1, rx2, ry2);

	    }

    }
    }


    *ax /= 10e5;
    *ay /= 10e5;
    *bx /= 10e5;
    *by /= 10e5;

  return 1;
}
#ifndef __PROGTEST__
int almostEqual(double x, double y)
{

    // Check if the numbers are really close -- needed when comparing numbers near zero. 10e-5
    //0.1e-5 epsilon variable olarak verip fabs x ile fabs y i toplayip bir degerle carp
    if ( fabs(x - y) <10e-12 * fabs( x + y ) ) //e-5
            return 1;
        return 0;

}
int main (void)
{
    double x1, y1, x2, y2;

    x1 = 60;
    y1 = 40;
    x2 = 70;
    y2 = 50;
    assert ( clipLine ( 10, 20, 90, 100, &x1, &y1, &x2, &y2 )
            && almostEqual ( x1, 60 )
            && almostEqual ( y1, 40 )
            && almostEqual ( x2, 70 )
            && almostEqual ( y2, 50 ) );

    x1 = 0;
    y1 = 50;
    x2 = 20;
    y2 = 30;
    assert ( clipLine ( 90, 100, 10, 20, &x1, &y1, &x2, &y2 )
            && almostEqual ( x1, 10 )
            && almostEqual ( y1, 40 )
            && almostEqual ( x2, 20 )
            && almostEqual ( y2, 30 ) );

    x1 = 0;
    y1 = 30;
    x2 = 120;
    y2 = 150;
    assert ( clipLine ( 10, 20, 90, 100, &x1, &y1, &x2, &y2 )
            && almostEqual ( x1, 10 )
            && almostEqual ( y1, 40 )
            && almostEqual ( x2, 70 )
            && almostEqual ( y2, 100 ) );

    x1 = -10;
    y1 = -10;
    x2 = -20;
    y2 = -20;
    assert ( ! clipLine ( 10, 20, 90, 100, &x1, &y1, &x2, &y2 ) );

    x1 = 0;
    y1 = 30;
    x2 = 20;
    y2 = 10;
    assert ( clipLine ( 10, 20, 90, 100, &x1, &y1, &x2, &y2 )
            && almostEqual ( x1, 10 )
            && almostEqual ( y1, 20 )
            && almostEqual ( x2, 10 )
            && almostEqual ( y2, 20 ) );

    x1 = 0;
    y1 = 0.3553;
    x2 = 10.45;
    y2 = 0;
    assert ( clipLine ( 0.95, 0.323, 1, 1, &x1, &y1, &x2, &y2 )
            && almostEqual ( x1, 0.95 )
            && almostEqual ( y1, 0.323 )
            && almostEqual ( x2, 0.95 )
            && almostEqual ( y2, 0.323 ) );


    return 0;
}
#endif /* __PROGTEST__ */
