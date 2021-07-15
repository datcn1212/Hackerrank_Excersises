#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

const int n=17;

//ham fitness
unsigned int fitness(int u,unsigned int a[][n],unsigned int b[][n]){
	unsigned int s=0;
	int i;
	for (i=0;i<n-1;i++) s+= b[a[u][i]][a[u][i+1]];
	s+=b[a[u][n-1]][a[u][0]];
	return s;
}

void sapxep(int m,unsigned int a[][n],unsigned int b[][n]){
	int i,j,p,l,u,t;
	int c;
	for(i=0;i<m;i++){
		p=i;
	    for(j=i;j<m;j++){
	    	if (fitness(j,a,b) < fitness(p,a,b) ) p=j;
			}
		for(l=0;l<n;l++) {
	    		c=a[i][l];
	    		a[i][l]=a[p][l];
	    		a[p][l]=c;
		}
	}
}


// Chuong trinh chinh

int main(){
	int m=70;
	int i,j,k,l,s,t,c=0,p;
	unsigned int khoangcach[n][n];
	unsigned int duongdi[100][n];
	
	for(i=0;i<m;i++) for(j=0;j<n;j++) duongdi[i][j]=j;
	
	// gan khoang cach cho cac thanh pho
	
    for (i=0;i<n;i++) {
       for (j=0;j<n;j++) { 
	   scanf("%d",&khoangcach[i][j]);
         }
       }
       
       
    // khoi tao quan the
    
    for(i=0;i<m;i++) for(j=0;j<1000;j++) {
		p=rand()%(n-1);
		c=duongdi[i][p];
		duongdi[i][p]=duongdi[i][p+1];
		duongdi[i][p+1]=c;
	}
     
    // Chon loc tu nhien
    
    sapxep(m,duongdi,khoangcach);
    
    
    //sinh san
    
    for(i=0,j=30;i<10;i+=1) {
    	for(k=n/2;k<n;k++) {
    		duongdi[j][k]=duongdi[i][k];
    		duongdi[j+1][k]=duongdi[29-i][k];
		}
		s=0;
		for(k=0;k<n;k++) {
		    for(l=n/2;l<n;l++) {
			if(duongdi[29-i][k]==duongdi[j][l]) break;
		}
		    if(l==n&&s<n/2) {
		    	duongdi[j][s]=duongdi[29-i][k];
		    	s++;
			}
	}
	    s=0;
		for(k=0;k<n;k++) {
		    for(l=n/2;l<n;l++) {
			if(duongdi[i][k]==duongdi[j+1][l]) break;
		}
		    if(l==n&&s<n/2) {
		    	duongdi[j+1][s]=duongdi[i][k];
		    	s++;
			}
	}
		j+=2;
	}
	// Dot bien
	for(i=10,j=50;i<20;i++){
		for(k=0;k<n;k++) duongdi[j][k]=duongdi[i][k];
		for(k=0;k<100;k++) {
			p=rand()%(n-1);
		    c=duongdi[j][p];
		    duongdi[j][p]=duongdi[j][p+1];
		    duongdi[j][p+1]=c;
		}
		j++;
	}
	
	// vong lap
	
	m=60;
	sapxep(m,duongdi,khoangcach);
    for(t=0;t<1000;t++) {

    	for(i=0,j=30;i<10;i++) {
    	c=rand()%n;
    	for(k=c;k<n;k++) {
    		duongdi[j][k]=duongdi[i][k];
    		duongdi[j+1][k]=duongdi[29-i][k];
		}
		s=0;
		for(k=0;k<n;k++) {
		    for(l=c;l<n;l++) {
			if(duongdi[29-i][k]==duongdi[j][l]) break;
		}
		    if(l==n&&s<c) {
		    	duongdi[j][s]=duongdi[29-i][k];
		    	s++;
			}
	}
	    s=0;
		for(k=0;k<n;k++) {
		    for(l=c;l<n;l++) {
			if(duongdi[i][k]==duongdi[j+1][l]) break;
		}
		    if(l==n&&s<c) {
		    	duongdi[j+1][s]=duongdi[i][k];
		    	s++;
			}
	}
		j+=2;
	}
	
	for(i=10,j=50;i<20;i++){
		for(k=0;k<n;k++) duongdi[j][k]=duongdi[i][k];
		for(k=0;k<100;k++) {
			p=rand()%(n-1);
		    c=duongdi[j][p];
		    duongdi[j][p]=duongdi[j][p+1];
		    duongdi[j][p+1]=c;
		}
		j++;
	}
	
	sapxep(m,duongdi,khoangcach);
	printf("%d\n",fitness(0,duongdi,khoangcach));
	for(j=0;j<n;j++) printf("%3d",duongdi[0][j]);
	printf("\n");
	}
	
	for(i=0;i<10;i++) printf("%d\n\n",fitness(i,duongdi,khoangcach));
    for(i=0;i<10;i++){
	for(j=0;j<n;j++) printf("%3d",duongdi[i][j]);
	printf("\n");}
	
    return 0;
}
