	/* function KALENP */
	/* call kalenp(ix1,ix2,ix3,&iy1,&iy2); */
void kalenp(int ix1, int ix2, int ix3, int *piy1, int *piy2)
/*int ix1,ix2,ix3;
int *piy1,*piy2; */
{
int id1,id2,id4,id5,id6,iy1,iy2;
	id1=ix1-ix3;
	if(id1<0) id1=0;
	id1=ix1-id1;
	if(id1>=ix2){
	iy2=ix1-ix3;
	if(iy2<0) iy2=0;
	iy2=ix2+iy2; iy1=ix1-iy2+1; goto kones;}
	id2=ix2-id1;
	id6=id2/ix3; id4=id2-id6*ix3;
	if(id4==0){iy1=1;iy2=id6*7+ix1;}
	else {id5=id4+7-ix3; iy1=8-id5;
	iy2=ix1+id6*7+id5;}
kones:
	*piy1=iy1; *piy2=iy2;
	return ;
}