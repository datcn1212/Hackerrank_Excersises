#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int random(int min, int max)
	{
	 return min + rand() % (max-min+1);
	}

int main(){
	int MAX=100000000;
	int i,j,k,y,m,n=1000;
	float sosanh1;
	float sosanh2;
	int a;
	printf("\n Nhap vao so thanh pho:");
	scanf("%d",&a);
	float toado[a][2];
	int cathe[n][a];
	float thichnghi[n];
	float khoangcach[a][a];
	int hotro[a];
	srand((int)time(0));
	// mang ho tro
	for(i=0;i<a;i++){
		hotro[i]=i+1;
	}
	int num;
    FILE *fptr;
 
    if ((fptr = fopen("data_48.txt","r")) == NULL){
       printf("Error! opening file");
 
       // Program exits if the file pointer returns NULL.
       exit(1);
   }
	for(i=0;i<a;i++)
		for(j=0;j<a;j++)
			fscanf(fptr,"%f",&khoangcach[i][j]);
	fclose(fptr); 
			
	// khoi tao quan the
	for( i=0;i<n;i++){
	    int minP;
	    int maxP=a-1;
	    int swapP;
	    for(int h=0;h<a-1;h++){
	    	minP=h+1;
	    	swapP=random(minP,maxP);
	    	int tg=hotro[h];
	    	hotro[h]=hotro[swapP];
	    	hotro[swapP]=tg;
	    	
		}
		for(j=0;j<a;j++){
			cathe[i][j]=hotro[j];
		}
	}
	// bat dau vong lap the he
	for( k=0;k<1000;k++){
		// danh gia
		for(i=0;i<n;i++){
			thichnghi[i]=0;
			for(j=0;j<a-1;j++){
				thichnghi[i]=thichnghi[i]+khoangcach[cathe[i][j]-1][cathe[i][j+1]-1];
			}
			thichnghi[i]=thichnghi[i]+khoangcach[cathe[i][a-1]-1][cathe[i][0]-1]; 				
			
		}
		// in ra duong di ngan nhat trong quan the hien tai
 	    float trunggiann[n];
	    for (i=0;i<n;i++){
	    	trunggiann[i]=thichnghi[i];
	    }
	    for (i=0;i<n-1;i++){
	    	for(j=i+1;j<n;j++){
	    		if(trunggiann[i]>trunggiann[j]){
	    			float x=trunggiann[i];
 	    			trunggiann[i]=trunggiann[j];
	    			trunggiann[j]=x;
	    		}
	    	}
	    }
	float best;
	best=trunggiann[0];
	printf("\n duong di ngan nhat luc nay co tong do dai la:%f",best);
	printf("\n duong di luc nay se la:");
	for(i=0;i<n;i++){
		if(thichnghi[i]==best){
			for(int j=0;j<a;j++){
				printf("%d ",cathe[i][j]);
			}
			break;
		}
	}
		// chon loc
		float trunggian[n];
		for( i=0;i<n;i++){
			trunggian[i]=thichnghi[i];
		}
		for( i=0;i<n-1;i++){
			for(j=i+1;j<n;j++){
				if(trunggian[i]>trunggian[j]){
					float tg=trunggian[i];
					trunggian[i]=trunggian[j];
					trunggian[j]=tg;
				}
			}
		}
		int nguong=trunggian[800];
		int cttg[n][a];
		for(i=0;i<n;i++){
			for( j=0;j<a;j++){
				cttg[i][j]=cathe[i][j];
			}
		}
		int heso;
		for(i=0;i<n;i++){
			if(thichnghi[i]>nguong){
				heso=random(0,800);
				for(int j=0;j<a;j++){
				    cathe[i][j]=cttg[heso][j];
				}
			
			}
		}
	    
		// lai ghep
	    for(i=0;i<50;i++){
	    	int cha=random(0,n-1);
	    	int me;
	    	do{
	    		me=random(0,n-1);
	    	}while(me==cha);			
	    	int p=random(1,a-2);
	    	int l=-1;
	    	for(j=0;j<a;j++){
	    		for(y=p;y<a;y++){
	    			if(cathe[cha][j]==cathe[me][y])break;
	    			else if(y==a-1){
	    				l++;
	    				int tg=cathe[cha][j];
	    				cathe[cha][j]=cathe[me][l];
	    				cathe[me][l]=tg;
	    			 }
	    			}
	    		}
	    	}
	    // dot bien
	    for( i=0;i<20;i++){
	    	int index=random(0,n-1);
	    	for(int j=0;j<a;j++){
	    	int bit1=random(0,a-1);
	    	int bit2;
	    	do{
	    	   bit2=random(0,a-1);
	    	}while(bit1==bit2);
	    	sosanh1=0;
	    	for(int m=0;m<a-1;m++){
	    		sosanh1+=khoangcach[cathe[index][m]-1][cathe[index][m+1]-1];
			}
			sosanh1+=khoangcach[cathe[index][0]-1][cathe[index][a]-1];
			int tg=cathe[index][bit1];
	    	cathe[index][bit1]=cathe[index][bit2];
	    	cathe[index][bit2]=tg;
	    	sosanh2=0;
	    	for( m=0;m<a-1;m++){
	    		sosanh2+=khoangcach[cathe[index][m]-1][cathe[index][m+1]-1];
			}
			sosanh2+=khoangcach[cathe[index][0]-1][cathe[index][a]-1];
			if(sosanh2<=sosanh1)break;
			else{
				int tgdb=cathe[index][bit1];
				cathe[index][bit1]=cathe[index][bit2];
				cathe[index][bit2]=tgdb;
			} 
			}
	    	}
	    }
	    
	    
}




