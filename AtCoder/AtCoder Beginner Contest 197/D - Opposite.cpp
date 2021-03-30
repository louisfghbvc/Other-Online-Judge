#include <bits/stdc++.h>

using namespace std;
#define PI acos(-1)

int main()
{
   int n;
   double x0, y0, x1, y1;
   cin >> n;
   cin >> x0 >> y0 >> x1 >> y1;
   double midx = (x0+x1)/2.0;
   double midy = (y0+y1)/2.0;
   
   double sieta = (double)2 * PI /n;
   
   double x = cos(sieta) * (x0-midx) - sin(sieta) * (y0-midy);
   double y = sin(sieta) * (x0-midx) + cos(sieta) * (y0-midy);
   printf("%.9f %.9f\n", midx + x, midy + y);
   
   return 0;
}
