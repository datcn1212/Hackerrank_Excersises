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
	int n=1000;
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
	for(int i=0;i<a;i++){
		hotro[i]=i+1;
	}
	// dien toa do
	printf("dien toa do cac thanh pho:\n");
	for(int i=0;i<a;i++){
		int fake;
		scanf("%d",&fake);
		scanf("%f",&toado[i][0]);
		scanf("%f",&toado[i][1]);
	}
	// dien khoang cach
	for(int i=0;i<a;i++){
		for(int j=i+1;j<a;j++){
			khoangcach[i][j]=sqrt(pow(toado[i][0]-toado[j][0],2)+pow(toado[i][1]-toado[j][1],2));
			
		}
		khoangcach[i][i]=MAX;
	}
	for(int i=1;i<a;i++){
		for(int j=0;j<i;j++){
			khoangcach[i][j]=khoangcach[j][i];
		}
	}
	printf("\n cac khoang cach la: \n");
	for(int i=0;i<a;i++){
		for(int j=0;j<a;j++){
			printf("%f  ",khoangcach[i][j]);
			if(j==a-1) printf("\n");
		}
	}
	// khoi tao quan the
	for(int i=0;i<n;i++){
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
		for(int j=0;j<a;j++){
			cathe[i][j]=hotro[j];
		}
	}
	// bat dau vong lap the he
	for(int k=0;k<1000;k++){
		// danh gia
		for(int i=0;i<n;i++){
			thichnghi[i]=0;
			for(int j=0;j<a-1;j++){
				thichnghi[i]=thichnghi[i]+khoangcach[cathe[i][j]-1][cathe[i][j+1]-1];
			}
			thichnghi[i]=thichnghi[i]+khoangcach[cathe[i][a-1]-1][cathe[i][0]-1]; 				
			
		}
		// in ra duong di ngan nhat trong quan the hien tai
 	    float trunggiann[n];
	    for (int i=0;i<n;i++){
	    	trunggiann[i]=thichnghi[i];
	    }
	    for (int i=0;i<n-1;i++){
	    	for(int j=i+1;j<n;j++){
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
	for(int i=0;i<n;i++){
		if(thichnghi[i]==best){
			for(int j=0;j<a;j++){
				printf("%d ",cathe[i][j]);
			}
			break;
		}
	}
		// chon loc
		float trunggian[n];
		for(int i=0;i<n;i++){
			trunggian[i]=thichnghi[i];
		}
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if(trunggian[i]>trunggian[j]){
					float tg=trunggian[i];
					trunggian[i]=trunggian[j];
					trunggian[j]=tg;
				}
			}
		}
		int nguong=trunggian[800];
		int cttg[n][a];
		for(int i=0;i<n;i++){
			for(int j=0;j<a;j++){
				cttg[i][j]=cathe[i][j];
			}
		}
		int heso;
		for(int i=0;i<n;i++){
			if(thichnghi[i]>nguong){
				heso=random(0,800);
				for(int j=0;j<a;j++){
				    cathe[i][j]=cttg[heso][j];
				}
			
			}
		}
	    
		// lai ghep
	    for(int i=0;i<50;i++){
	    	int cha=random(0,n-1);
	    	int me;
	    	do{
	    		me=random(0,n-1);
	    	}while(me==cha);			
	    	int p=random(1,a-2);
	    	int l=-1;
	    	for(int j=0;j<a;j++){
	    		for(int y=p;y<a;y++){
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
	    for(int i=0;i<20;i++){
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
	    	for(int m=0;m<a-1;m++){
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




