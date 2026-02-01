#include <stdio.h>
 
 int main()
 {
 	int day;
 	double h, u, d, f;
 	double ih, dc, hac, has;
 	while(scanf("%lf %lf %lf %lf", &h, &u, &d, &f), h != 0)
 	{
 		day = 1;
 		ih = 0;
 		dc = u;
 		hac = u;
 		has = hac - d;

 		while( hac <= h  && has >= 0)
 		{
 			ih = has;
 			dc -= (u*f/100);
 			hac = (dc > 0) ? ih + dc: ih;
 			has = hac - d;
 			day++;
 		}
 		if(hac >= h)
 			printf("success on day %d\n", day );
 		else
 			printf("failure on day %d\n", day );
 	}
 	return 0;
 }