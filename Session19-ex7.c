#include <stdio.h>
#include <string.h>
typedef struct {
    int id;
    char name[100];
    int age;
    char phoneNumber[20];
} Student;
void print(Student students[], int currentLength) {
    if (currentLength == 0) {
        printf("Danh sach sinh vien rong\n");
        return;
    }
    for (int i = 0; i < currentLength; i++) {
        printf("ID: %d\n name: %s\n age: %d phonenumber: %s\n", students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}
void deletestudents(int id, Student students[], int* currentLength) {
    int found = -1;
    for (int i = 0; i < *currentLength; i++) {
        if (students[i].id == id) {
            found = i;
            break;
        }
    }
    if (found == -1) {
        printf("Sinh vien id = %d khong ton tai trong danh sach\n", id);
        return;
    }
    for (int i = found; i < *currentLength - 1; i++) {
        students[i] = students[i + 1];
    }
    (*currentLength)--;
    printf("Sinh vien id = %d da duoc xoa\n", id);
}
int main() {
    Student students[5] = {
        {1, "Nguyen Van A", 18, "0364564366"},
        {2, "Nguyen Van B", 19, "0717473473"},
        {3, "Nguyen Van C", 20, "0914832583"},
        {4, "Nguyen Van D", 21, "0148372987"},
        {5, "Nguyen Van E", 22, "0912498349"}
    };
    int length = 5;  
    printf("Danh sach sinh vien ban dau:\n");
    print(students, length);
    int deleteid;
    printf("\nNhap id sinh vien muon xoa: ");
    scanf("%d", &deleteid);
    deletestudents(deleteid, students, &length);
    printf("\nDanh sach sinh vien sau khi xoa:\n");
    print(students, length);
    return 0;
}
