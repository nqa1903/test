#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct contactList{
	int id;
	char name[50];
	char phone[12];
	char address[50];
	int status;
};

int currentSize = 2;
struct contactList list[100];

//In toan bo danh sach
void display(struct contactList arr[] , int size){
	for(int i = 0 ; i < size ; i++){
		printf("The ID of contact : %d \n",arr[i].id);
		printf("The name of contact : %s \n",arr[i].name);
		printf("The phone number of contact : %s \n",arr[i].phone);
		printf("The address of contact : %s \n",arr[i].address);
		printf("The status of contact : %d \n",arr[i].status);
		printf("----- \n");
	}
}

//Nhap thong tin
struct contactList addInfo(){
	struct contactList add;
	printf("Nhap vao id : \n");
	scanf("%d",&add.id);
	fflush(stdin);
	printf("Nhap vao ten : \n");
	gets(add.name);
	printf("Nhap vao SDT : \n");
	gets(add.phone);
	printf("Nhap vao dia chi : \n");
	gets(add.address);
	printf("Nhap trang thai : \n");
	scanf("%d",&add.status);
	fflush(stdin);
	return add;
}

//Them vao danh sach
void addList(){
	if(currentSize < 100){
        struct contactList newContact = addInfo();
        list[currentSize] = newContact;
        currentSize++;
		printf("Da them moi \n");
	}else{
		printf("Danh sach day , khong the them moi \n");
	}
}

//tim kiem contact de sua
int searchContact(struct contactList arr[], int size, char answer[50]) {
    int index = -1;
    for (int i = 0; i < size; i++){
        if (strcmp(arr[i].name, answer) == 0){
            index = i;
            break;
        }
    }
    return index;
}

//xoa contact
void deleteContact(char answer[50]){
    int index = searchContact(list, currentSize, answer);
    if (index != -1) {
        for (int i = index; i < currentSize - 1; i++) {
            list[i] = list[i + 1];
        }
        currentSize--;
        printf("Xoa thanh cong contact \n");
    } else {
        printf("Khong co contact nao trung \n");
    }
}

//sap xep noi bot
void bubbleSort(struct contactList arr[], int size){
    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - i - 1; j++){
            if (strcmp(arr[j].name, arr[j + 1].name) > 0){
                struct contactList temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){
	struct contactList list1 = {
		1,
		"Ngo Quang Anh",
		"0969510625",
		"Nghe An",
		0,
	};
	struct contactList list2 = {
		2,
		"Beyonce",
		"0982517590",
		"LA",
		1,
	};
	list[0] = list1;
	list[1] = list2;
	char answer[50];
	do{
		printf("************************ MENU ************************ \n");
		printf("1. In toan bo danh sach contact co trong mang \n");
		printf("2. Them contact vao danh sach \n");
		printf("3. Cap nhap thong tin contact \n");
		printf("4. Xoa thong tin contact \n");
		printf("5. In ra danh sach contact da sap xep theo ten (thuat toan noi bot) \n");
		printf("6. In ra danh sach contact da sap xep theo ten (thuat toan tim kiem nhi phan) \n");
		printf("7. In ra danh sach contact da sap xep theo status (thuat toan tim kiem tuyen tinh) \n");
		printf("8. Thoat \n");
		printf("Nhap vao lua chon : ");
		int choice;
		scanf("%d",&choice);
		fflush(stdin);
		switch(choice){
			case 1:
				display(list,currentSize);
				break;
			case 2:
				addList();
				break;
			case 3:
				printf("Nhap vao ten contact muon sua: ");
        		gets(answer);
                int updateIndex = searchContact(list,currentSize,answer);
                if(updateIndex != -1){
                	struct contactList updatedContact = addInfo();
                	list[updateIndex] = updatedContact;
					printf("Cap nhap thanh cong \n");  
                }
        		break;
        	case 4:
				printf("Nhap vao ten contact muon sua: ");
        		gets(answer);
        		deleteContact(answer);
        		break;	
        	case 5:
        		bubbleSort(list , currentSize);
        		printf("Danh sach sau khi sap xep theo ten \n");
        		display(list,currentSize);
        		break;
        	case 6:
        		break;
        	case 7: 
        		break;
        	case 8:
        		exit(0);
        	default:
        		printf("Vui long chon lai tu 1 - 8 \n");
		}
	}while(1);
}
