#include <stdio.h>



int main() {
//nhap vao 1 ngay va dua ra ngay do la ngay nghi hay lam viec
int ngay;
printf("nhap vao ngay thu may trong tuan:");
scanf("%d",&ngay);
switch (ngay)
   { 
	case 1 :
	case 2 :
	case 3 :
	case 4 :
	case 5 : printf("lam viec ca ngay!"); /*nghia la ngay = 1,2,3,4,5 thi thuc hien lenh nay*/
	         //break;   /*cho nay ma k co break ma n=1,2,3,4,5 thi no in ra  "lam viec ca ngay" "lam nua ngay"*/
	case 6 :
	case 7 : printf("lam nua ngay");
	         break;
	default : printf("nhap sai ngay");
	}
return 0;
}
//neu khong co break cac lenh se lien tuc duoc thuc hien cho den khi gap break hoac ket thuc lenh switch
//default la nhung gia tri con lai khac nhung gia tri o case
// de danh dau 1 doan van ban la chu thich c: boi den van ban va nhan to h
