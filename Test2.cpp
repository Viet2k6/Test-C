#include <stdio.h>
int main() {
    int arr[100][100];  
    int rows, cols;    
    int value;    
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Nhap kich co va gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In ra cac phan tu nam tren duong bien va tinh tich \n");
        printf("4. In ra cac phan tu nam tren duong cheo chinh\n");
        printf("5. In ra cac phan tu nam tren duong cheo phu\n");
        printf("6. Sap xep duong cheo chinh theo thu tu tang dan\n");
        printf("7. Tim kiem mot phan tu va in ra vi tri cua phan tu do trong mang\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);     
        switch(choice) {
            case 1:
                printf("Nhap so dong cua ma tran: ");
                scanf("%d", &rows);
                printf("Nhap so cot cua ma tran: ");
                scanf("%d", &cols);
                printf("Nhap cac phan tu cua ma tran:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        printf("Phan tu [%d][%d]: ", i + 1, j + 1);
                        scanf("%d", &arr[i][j]);
                    }
                }
                break;
            case 2:
                printf("\nMa tran:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        printf("%d ", arr[i][j]);
                    }
                    printf("\n");
                }
                break;
            case 3:
                printf("\nCac phan tu tren duong bien: ");
                int productBorder = 1;
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                            printf("%d ", arr[i][j]);
                            productBorder *= arr[i][j];
                        }
                    }
                }
                printf("\nTich cac phan tu tren duong bien: %d\n", productBorder);
                break;
            case 4:
                printf("\nCac phan tu tren duong cheo chinh: ");
                for (int i = 0; i < rows && i < cols; i++) {
                    printf("%d ", arr[i][i]);
                }
                printf("\n");
                break;
            case 5:
                printf("\nCac phan tu tren duong cheo phu: ");
                for (int i = 0; i < rows && i < cols; i++) {
                    printf("%d ", arr[i][cols - i - 1]);
                }
                printf("\n");
                break;
            case 6: 
                {
                    int temp;
                    if (rows != cols) {
                        printf("Ma tran khong phai ma tran vuong. Khong the sap xep duong cheo chinh.\n");
                        break;
                    }
                    
                    for (int i = 0; i < rows - 1; i++) {
                        for (int j = i + 1; j < rows; j++) {
                            if (arr[i][i] > arr[j][j]) {
                                temp = arr[i][i];
                                arr[i][i] = arr[j][j];
                                arr[j][j] = temp;
                            }
                        }
                    }
                    printf("Duong cheo chinh sau khi sap xep la: ");
                    for (int i = 0; i < rows; i++) {
                        printf("%d ", arr[i][i]);
                    }
                    printf("\n");
                }
                break;
            case 7: 
                printf("Nhap phan tu can tim: ");
                scanf("%d", &value);
                int found = 0;
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        if (arr[i][j] == value) {
                            printf("Phan tu %d co vi tri: [%d][%d]\n", value, i, j);
                            found = 1;
                        }
                    }
                }
                if (!found) {
                    printf("Khong tim thay phan tu %d trong ma tran!\n", value);
                }
                break;
            case 8:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le vui long nhap lai\n");
                break;
        }
    } while (choice != 8);

    return 0;
}
