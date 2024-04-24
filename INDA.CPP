			    /* inda function*/
#include <stdio.h>

void inda(int NR, int ip[], int jp[], int cod[], float q[], char zn[],
	    int rs[], char prs[])

	{
int i,f,j;
prs[0]='*'; cod[0]=0; q[0]=99999;
ia2: f=0; for(i=0;i<NR;i++) {
if(rs[i]!=0) goto ia1;
if(prs[ip[i]]=='*') goto ia3; else goto ia1;
ia3: if(prs[jp[i]]!='*') {
f=1; j=jp[i];zn[j]='+';
prs[j]='*'; q[j]=99999; cod[j]=ip[i]; }
ia1: ; } if(f==1) goto ia2;
return ;
}