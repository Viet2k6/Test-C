#include<stdio.h>
int main(){
	int arr[100];
	int n;
	int choice;
	do{
		printf("\nMENU\n");
		printf("1. Nhap so phan tu can nhap va gia tri cho cac phan tu\n");
		printf("2. In ra gia tri cac phan tu dang quan ly\n");	
		printf("3. In ra gia tri lon nhat cua mang\n");
		printf("4. In ra cac phan tu la so nguyen to trong mang\n");
		printf("5. Them 1 phan tu vao trong mang \n");
		printf("6. Xoa mot phan tu trong mang \n");
		printf("7. Sap xep mang theo thu tu tang dan\n");
		printf("8. Tim kiem phan tu va in ra vi tri phan tu do\n");
		printf("9. Thoat\n");
		printf("Lua chon cua ban:");
		scanf("%d",&choice);
		switch (choice){
			case 1: {
	            printf("Nhap so phan tu");
	            scanf("%d",&n);
	            for(int i=0;i<n;i++){
		            printf("Nhap phan tu thu %d:",i+1);
		            scanf("%d",&arr[i]);
	                }
				break;
			}
			case 2: {
				printf("\nCac phan tu trong mang la: ");
	            for(int i=0;i<n;i++){
		        printf("%d ",arr[i]);
	            }
				break;
			}
			case 3: {
				int max=arr[0];
	            for(int i=0;i<n;i++){
		            if(arr[i]>max){
			            max = arr[i];
		            }
	            }
	            printf("\nGia tri phan tu lon nhat cua mang la:%d",max);
				break;
			}
			case 4: {
				printf("\nSo nguyen to trong mang la:");
	            for(int i=0;i<n;i++){
		            int soNguyento = 1;
		            if(arr[i]<2){
			            soNguyento=0;
		            }
		            else{
			            for(int j=2;j*j<=arr[i];j++){
				            if(arr[i]%j==0){
					        soNguyento=0;
					        break;
				            }
			            }
		            }
		            if(soNguyento==1){
			            printf("%d ",arr[i]);
		                }
	            }
				break;
			}
			case 5: {
				int position;
                do{
    	            printf("\nNhap vi tri can them phan tu:");
	                scanf("%d",&position);
	                if(position<=0||position>n+1){
	    	            printf("Khong hop le. Vui long nhap lai");
	          	    }
	            }while(position<=0||position>n+1);
              	for(int i=n;i>position-1;i--){
		            arr[i]=arr[i-1];
	            }
	            printf("\nNhap gia tri phan tu can them:");
	            scanf("%d",&arr[position-1]);
	            n++;
				break;
			}
			case 6: {
				int position;
                do{
	                printf("\nNhap vi tri phan tu can xoa");
	                scanf("%d",&position);
	                if(position<=0||position>n){
	    	            printf("Khong hop le. Vui long nhap lai");
	                }
                }while(position<=0 || position>n);
                for(int i=position-1;i<n;i++){
    	            arr[i]=arr[i+1];
	            }
	            n--;
				break;
			}
			case 7: {
				for(int i=0;i<n-1;i++){
		            for(int j=0;j<n-1-i;j++){
			            if(arr[j]>arr[j+1]){
				        int temp=arr[j];
				            arr[j]=arr[j+1];
				            arr[j+1]=temp;
			            }
		            }
	            }
	            printf("\nPhan tu sap xep theo thu tu tang dan: ");
	            for(int i=0;i<n;i++){
		            printf("%d ",arr[i]);
	            }
				break;
			}
			case 8:{
				int search,exist;
	            printf("\nNhap phan tu can tim: ");
	            scanf("%d",&search);
	            exist=0;
	            printf("\nPhan tu can tim o vi tri: ");
	            for(int i=0;i<n;i++){
		            if(arr[i]==search){
			        printf("%d ",i+1);
			        exist=1;	
		            }
	            }
	            if(exist==0){
		            printf("Phan tu khong ton tai");
	            }
				break;
			}
			case 9: {
				printf("Thoat chuong trinh\n");
				break;
			}
			default:
                printf("Khong hop le\n");
			
		}
	
	}while(choice!=9);
        return 0;
}
