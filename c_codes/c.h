#ifndef __C_H__
#define __C_H__



typedef struct point_struct
{
   int x;
   int y;
} point_t;

int   clock      ( point_t* p,int loop );
int   antiClock  ( point_t* p,int loop );
int   findAngle  ( point_t p           );

#endif

