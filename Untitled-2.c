#include <stdio.h>
#include <string.h>

#define MAX 50

struct Student {
    char name[50];
    char aadhaar[15];
    char apaar[20];
    char email[50];
    char phone[15];
};

struct Student s[MAX];
int count = 0;

/* Function declarations */
void addStudent();
void displayStudents();
void searchStudent();
void updatePhone();
void updateEmail();

int main() {
    int choice;

    do {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student (Aadhaar)\n");
        printf("4. Update Phone Number\n");
        printf("5. Update Email\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updatePhone(); break;
            case 5: updateEmail(); break;
            case 6: printf("Exiting program...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}

void addStudent() {
    if (count >= MAX) {
        printf("Student list is full!\n");
        return;
    }

    printf("Enter Name: ");
    scanf(" %[^\n]", s[count].name);

    printf("Enter Aadhaar Number: ");
    scanf("%s", s[count].aadhaar);

    printf("Enter APAAR ID: ");
    scanf("%s", s[count].apaar);

    printf("Enter Email ID: ");
    scanf("%s", s[count].email);

    printf("Enter Phone Number: ");
    scanf("%s", s[count].phone);

    count++;
    printf("Student added successfully!\n");
}

void displayStudents() {
    if (count == 0) {
        printf("No student records found!\n");
        return;
    }

    printf("\nName\tAadhaar\t\tAPAAR\t\tEmail\t\tPhone\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%s\t%s\t%s\t%s\n",
               s[i].name,
               s[i].aadhaar,
               s[i].apaar,
               s[i].email,
               s[i].phone);
    }
}

void searchStudent() {
    char aadhaar[15];
    int found = 0;

    printf("Enter Aadhaar Number to search: ");
    scanf("%s", aadhaar);

    for (int i = 0; i < count; i++) {
        if (strcmp(s[i].aadhaar, aadhaar) == 0) {
            printf("\nStudent Found!\n");
            printf("Name: %s\n", s[i].name);
            printf("APAAR ID: %s\n", s[i].apaar);
            printf("Email: %s\n", s[i].email);
            printf("Phone: %s\n", s[i].phone);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found!\n");
}

void updatePhone() {
    char aadhaar[15];

    printf("Enter Aadhaar Number: ");
    scanf("%s", aadhaar);

    for (int i = 0; i < count; i++) {
        if (strcmp(s[i].aadhaar, aadhaar) == 0) {
            printf("Enter new Phone Number: ");
            scanf("%s", s[i].phone);
            printf("Phone number updated successfully!\n");
            return;
        }
    }
    printf("Student not found!\n");
}

void updateEmail() {
    char aadhaar[15];

    printf("Enter Aadhaar Number: ");
    scanf("%s", aadhaar);

    for (int i = 0; i < count; i++) {
        if (strcmp(s[i].aadhaar, aadhaar) == 0) {
            printf("Enter new Email ID: ");
            scanf("%s", s[i].email);
            printf("Email updated successfully!\n");
            return;
        }
    }
    printf("Student not found!\n");
}
