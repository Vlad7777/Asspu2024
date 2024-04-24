
   /* blab5 function */
#include <stdio.h>
#include <conio.h>
/*
blab5(ptrX,dob,dnd,dod,god)
int *ptrX;
int dob;
long dnd,dod;
int god;
*/
blab5(int *ptrX, int dob, long dnd, long dod, int god)
{  /* define duration mant. over. data. */
int i, mat[13],qq5[10],x;
int ddob,mdob,r,h,m,s,g1,g2,g3;
long ddnd,mdnd,ddod,mdod,tdnd,tdod;
/* ddob=dob/100;mdob=ddob*100;mdob=dob-mdob;
ddnd=dnd/100;mdnd=ddnd*100;mdnd=dnd-mdnd; */

// #include "defwind.c"

    mdob=dob/100; ddob=mdob*100; ddob=dob-ddob;
    mdnd=dnd/100; ddnd=mdnd*100; ddnd=dnd-ddnd;

   /*define day!*/
//   cprintf(" work BLAB5 \r");
/***** tdnd=dnd/10000; tdnd=tdnd*10000;
ddnd=dnd/100; ddnd=ddnd*100;
ddnd=ddnd-tdnd; ddnd=ddnd/100;  *****/
if(mdob>mdnd) goto m13;
if(mdnd>mdob) goto m14;
if(ddob>ddnd) goto m13;
m14: r=ddnd; m=mdnd; goto m15;
m13: r=ddob; m=mdob; m15:;
// cprintf("r=%d m=%d\r",r,m);

/**** ddod=dod/100; mdod=ddod*100;
mdod=dod-mdod;
tdod=dod/10000; tdod=tdod*10000;
ddod=dod/100; ddod=ddod*100;
ddod=ddod-tdod; ddod=ddod/100;  *******/
mdod=dod/100; ddod=mdod*100; ddod=dod-ddod;
h=ddod; s=mdod;
for(i=0; i<13; i++) mat[i]=31;
mat[4]=mat[6]=mat[9]=mat[11]=30;
mat[2]=28;
   /*проверка на високосность*/
/*cl=kk24; read file(fseti) into(gg) key(ll)*/   /* ?????????????????? */
for (i=0;i<10;i++) qq5[i]=0; /* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
g1=god/100;g1=g1*100; g1=god-g1;
x=1; if((r==h)&&(m==s)) goto en; x=0;
p1: g3=g1/4; g2=g3*4; g2=g1-g2;
if(g2==0) mat[2]=29;
if((r==0)||(m==0)||(h==0)||(s==0)) goto m4;
if((m>12)||(s>12)) goto m4;
if(r>mat[m]) goto m4;
if(h>mat[s]) goto m4;
if(m>s) goto m5;
if((m==s)&&(r>h)) goto m4; goto m2;
m4:  /*exit!*/
 printf(" ошибка в датах r=%d m=%d h=%d s=%d\r",r,m,h,s);
goto en;
m5: printf(" возможна ошибка в датах r=%d m=%d h=%d s=%d\r",
r,m,h,s);
m2:;
m3: if(m==s) {
x=x+h-r+1; goto m8; }
x=x+mat[m]-r+1; m=m+1; r=1;
if(m==13) { m=1; g1=g1+1;
goto p1; } goto m3;
m8: for(i=0;i<10;i++) {
if(qq5[i]==0) goto en;  /* ?question*/
x=x-1; }
en:;  *ptrX=x;
return 0;
}
