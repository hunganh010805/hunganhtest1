#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 100
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}
void displayMenu() {
    printf("\nMENU\n");
    printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
    printf("2. In ra gia tri cac phan tu dang quan li\n");
    printf("3. In ra gia tri lon nhat cua mang\n");
    printf("4. In ra cac phan tu la so nguyen to trong mang\n");
    printf("5. Them mot phan tu vao trong mang\n");
    printf("6. Xoa mot phan tu trong mang\n");
    printf("7. Sap xep mang theo thu tu tang dan\n");
    printf("8. Tim kiem phan tu va in ra vi tri index cua phan tu do\n");
    printf("9. Thoat\n");
    printf("Lua chon cua ban: ");
}
int main() {
    int arr[MAX_SIZE], n = 0, choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
        	//nhap gia tri cac phan tu
            case 1: {
                printf("Nhap so luong phan tu: ");
                scanf("%d", &n);
                if (n > MAX_SIZE) {
                    printf("So luong phan tu vuot qua gioi han!\n");
                    n = 0;
                    break;
                }
                for (int i = 0; i < n; i++) {
                    printf("Nhap phan tu %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                break;
            }
            //in ra cac phan tu da nhap
            case 2: {
                printf("Cac phan tu trong mang: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }
            //in ra gia tri lon nhat cua mang
            case 3: {
                if (n == 0) {
                    printf("Mang trong !\n");
                    break;
                }
                int max = arr[0];
                for (int i = 1; i < n; i++) {
                    if (arr[i] > max) max = arr[i];
                }
                printf("Gia tri lon nhat la: %d\n", max);
                break;
            }
            //in cac phan tu la so nguyen to
            case 4: {
                printf("Cac phan tu la so nguyen to: ");
                for (int i = 0; i < n; i++) {
                    if (isPrime(arr[i])) printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }
            //them gia tri phan tu
            case 5: {
                if (n >= MAX_SIZE) {
                    printf("Khong the them phan tu ,mang o day!\n");
                    break;
                }
                printf("Nhap gia tri phan tu can them: ");
                int value;
                scanf("%d", &value);
                arr[n++] = value;
                printf("Da them phan tu %d.\n", value);
                break;
            }
            //xoa mot phan tu
            case 6: {
                printf("Nhap vi tri phan tu can xoa: ");
                int index;
                scanf("%d", &index);
                if (index < 0 || index >= n) {
                    printf("khong hop le!\n");
                    break;
                }
                for (int i = index; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                n--;
                printf("Da xoa phan tu %d.\n", index);
                break;
            }
            //sap xep cac phan tu theo gia tri tang dan
            case 7: {
                for (int i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (arr[i] > arr[j]) {
                            int temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }
                printf("Mang da duoc sap xep.\n");
                break;
            }
            //@.@
            case 8: {
                
            };
            case 9:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 9);

    return 0;
}

