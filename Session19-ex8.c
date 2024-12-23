#include <stdio.h>
#include <string.h>
typedef struct Students{
    int id;
    char name[100];
    int age;
    char phoneNumber[20];
} Student;
void sapxep(Student students[], int n) {
    Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}
void print(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("id: %d\n name: %s\n age: %d\n phonenumber: %s\n", students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}
int main() {
    Student students[5] = {
        {1, "Nguyen Van E", 18, "0938653645"},
        {2, "Nguyen Van B", 19, "0235745434"},
        {3, "Nguyen Van D", 20, "0191434935"},
        {4, "Nguyen Van F", 21, "0623432473"},
        {5, "Nguyen Van C", 22, "0987723743"}
    };
    printf("Danh sach sinh vien truoc khi sap xep:\n");
    print(students, 5);
    sapxep(students, 5);
    printf("\nDanh sach sinh vien sau khi sap xep theo ten:\n");
    print(students, 5);
    return 0;
}
