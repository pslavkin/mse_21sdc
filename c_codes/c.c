#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "c.h"

//float tanTable[]={45,
//                  26.5650511771,
//                  14.0362434679,
//                  7.1250163489,
//                  3.576334375,
//                  1.78991060825,
//                  0.895173710211,
//                  0.447614170861,
//                  0.223810500369,
//                  0.111905677066,
//                  }; //
int tanTable[]= { 4500,
                  2657,
                  1404,
                  713,
                  358,
                  179,
                  90,
                  45,
                  22,
                  11,
                  }; //
#define MAX_TABLE (sizeof(tanTable)/sizeof(tanTable[0]))

point_t inputPoint={10,100};

void main(int argc, char** argv)
{
   point_t p;
   p.x=atoi(argv[1]);
   p.y=atoi(argv[2]);
   printf("angle=%i\r\n",findAngle(p));
}

int antiClock(point_t* p,int loop)
{
   point_t pNew;
   pNew.x=p->x-(p->y>>loop);
   pNew.y=p->y+(p->x>>loop);
   *p=pNew;
   return pNew.y>0;
}
int clock(point_t* p,int loop)
{
   point_t pNew;
   pNew.x=p->x+(p->y>>loop);
   pNew.y=p->y-(p->x>>loop);
   *p=pNew;
   return pNew.y<0;
}

int findAngle(point_t p)
{
   int   i;
   int   actualAngle    = 0;
   bool  clockAntiClock = true;

   for(i=0;i<MAX_TABLE && p.y!=0;i++) {
      printf("actual point {%i,%i}\r\n",p.x,p.y);
      if(clockAntiClock==true) {
         if(clock(&p,i)) {
            clockAntiClock=false;
         }
         actualAngle+=tanTable[i];
      }
      else {
         if(antiClock(&p,i)) {
            clockAntiClock=true;
         }
         actualAngle-=tanTable[i];
      }
      printf("i=%i - clock=%i - actual=%i add/sub=%i\r\n",i,clockAntiClock,actualAngle,tanTable[i]);
      printf("new point {%i,%i}\r\n\r\n",p.x,p.y);
   }
   return actualAngle;
}
