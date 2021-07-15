// Viết công thức nhập vào danh sách họ tên học sinh
// của một lớp, điều kiện kết thúc nhập là họ tên là rỗng
// hoặc đạt được số học sinh tối ta (50)
// Sau đó sắp xếp và in ra sanh sách theo thứ tự abc của họ tên

#include <stdio.h>
#include <string.h>

int main(){
    int n, i, j, k;
    char ds[50][30], tg[30];
    i = 0;
    while(i < 50){
        printf("Nhap vao sinh vien thu %d: ", i + 1);
        fflush(stdin);
        gets(ds[i]);
        if(ds[i][0] == '\0')
            break;
        i++;
    }
    n = i;
     
    // Sắp xếp theo nổi bọt

    // for(i = 0; i <= n - 1; i++){
    //     for(j = i + 1; j <= n - 1; j++){
    //         if(stricmp(ds[i], ds[j]) > 0){
    //             strcpy(tg, ds[j]);
    //             strcpy(ds[j], ds[i]);
    //             strcpy(ds[i], tg);
    //         }
    //     }
    // }

    // Sắp xếp chọn

    for(i = 0; i <= n - 1; i++){
        k = i;
        for(j = i + 1; j <= n - 1; j++){
            if(stricmp(ds[i], ds[j]) > 0)
                k = j;
        }
        if(k != i){
            strcpy(tg, ds[k]);
            strcpy(ds[k], ds[i]);
            strcpy(ds[i], tg);
        }
    }

    printf("Danh sach da sap xep la:\n");
    for(i = 0; i <= n - 1; i++){
        printf("%s\n", ds[i]);
    }

    return 0;
}