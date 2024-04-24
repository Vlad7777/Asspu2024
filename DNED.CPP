			/* function dned.cpp */
dned(int iz1,int dNREM)
{
int iz2,iz6;
	if(iz1>7){
	iz2=iz1/7; iz1=iz1-iz2*7;}
	iz6=iz1+dNREM-1;
	if(iz6>7) iz6=iz6-7;
	else if(iz6==0) iz6=7;
	return(iz6);
	}
