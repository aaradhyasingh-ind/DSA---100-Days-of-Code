//write code to show insertion, deletion, searching and sorting
#include <stdio.h>
#include <string.h>

// Structure to store student details
struct Student {
    int sap_id;
    int roll_no;
    char name[30];
    char phone[15];
    char email[40];
    char year[10];
    int semester;
    float sgpa[8]; // SGPA for 8 semesters
    float cgpa;
};

// Function declarations
void displayAll(struct Student s[], int n);
void calculateCGPA(struct Student s[], int n);
void displayStudent(struct Student s[], int n, int roll);
void deleteStudent(struct Student s[], int *n, int roll);
void sortBySAP(struct Student s[], int n);
void sortByName(struct Student s[], int n);
void avgYearCGPA(struct Student s[], int n);
void addStudent(struct Student s[], int *n);

int main() {
    int i, j, n = 5, choice;
    struct Student s[10];

    // --- Initial Data from Table ---
    s[0].sap_id = 100010000; s[0].roll_no = 15;
    strcpy(s[0].name, "Priya Sharma");
    strcpy(s[0].phone, "98765-12345");
    strcpy(s[0].email, "priya.s@uni.edu");
    strcpy(s[0].year, "4th");
    s[0].semester = 7;
    float sgpa1[8] = {8.9, 8.5, 9.1, 9.3, 8.8, 9.0, 9.6, 0};
    for (j=0;j<8;j++) s[0].sgpa[j]=sgpa1[j];

    s[1].sap_id = 100020000; s[1].roll_no = 20;
    strcpy(s[1].name, "Rohan Verma");
    strcpy(s[1].phone, "99887-54321");
    strcpy(s[1].email, "rohan.v@uni.edu");
    strcpy(s[1].year, "2nd");
    s[1].semester = 3;
    float sgpa2[8] = {7.2, 7.5, 7.8, 0, 0, 0, 0, 0};
    for (j=0;j<8;j++) s[1].sgpa[j]=sgpa2[j];

    s[2].sap_id = 100030000; s[2].roll_no = 25;
    strcpy(s[2].name, "Fatima Khan");
    strcpy(s[2].phone, "90001-22334");
    strcpy(s[2].email, "fatima.k@uni.edu");
    strcpy(s[2].year, "3rd");
    s[2].semester = 5;
    float sgpa3[8] = {8.1, 8.4, 7.9, 8.6, 8.8, 0, 0, 0};
    for (j=0;j<8;j++) s[2].sgpa[j]=sgpa3[j];

    s[3].sap_id = 100040000; s[3].roll_no = 30;
    strcpy(s[3].name, "David Lee");
    strcpy(s[3].phone, "87654-98765");
    strcpy(s[3].email, "david.l@uni.edu");
    strcpy(s[3].year, "1st");
    s[3].semester = 1;
    float sgpa4[8] = {9.5, 0, 0, 0, 0, 0, 0, 0};
    for (j=0;j<8;j++) s[3].sgpa[j]=sgpa4[j];

    s[4].sap_id = 100050000; s[4].roll_no = 35;
    strcpy(s[4].name, "Sneha Reddy");
    strcpy(s[4].phone, "91234-56789");
    strcpy(s[4].email, "sneha.r@uni.edu");
    strcpy(s[4].year, "4th");
    s[4].semester = 8;
    float sgpa5[8] = {7.9, 8.2, 7.8, 8.5, 8.0, 8.3, 8.1, 8.6};
    for (j=0;j<8;j++) s[4].sgpa[j]=sgpa5[j];

    // Calculate CGPA initially
    calculateCGPA(s, n);

    // --- Menu starts here ---
    do {
        printf("\n===== STUDENT DATABASE MENU =====\n");
        printf("1. Display all students\n");
        printf("2. Search student by Roll No\n");
        printf("3. Delete student by Roll No\n");
        printf("4. Display in order of SAP ID\n");
        printf("5. Display in order of Name\n");
        printf("6. Display Average CGPA of each Year\n");
        printf("7. Add new student details\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                displayAll(s, n);
                break;
            case 2: {
                int roll;
                printf("Enter Roll No to search: ");
                scanf("%d", &roll);
                displayStudent(s, n, roll);
                break;
            }
            case 3: {
                int roll;
                printf("Enter Roll No to delete: ");
                scanf("%d", &roll);
                deleteStudent(s, &n, roll);
                break;
            }
            case 4:
                sortBySAP(s, n);
                displayAll(s, n);
                break;
            case 5:
                sortByName(s, n);
                displayAll(s, n);
                break;
            case 6:
                avgYearCGPA(s, n);
                break;
            case 7:
                addStudent(s, &n);
                break;
            case 8:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 8);

    return 0;
}

// --- Function Definitions ---

// Calculate CGPA (average of SGPA)
void calculateCGPA(struct Student s[], int n) {
    for (int i=0; i<n; i++) {
        float sum=0; int count=0;
        for (int j=0;j<8;j++) {
            if (s[i].sgpa[j]!=0) { sum+=s[i].sgpa[j]; count++; }
        }
        s[i].cgpa = (count>0) ? sum/count : 0;
    }
}

// Display all students
void displayAll(struct Student s[], int n) {
    printf("\n%-12s %-6s %-15s %-12s %-20s %-5s %-7s %-5s\n",
           "SAP_ID","Roll","Name","Phone","Email","Year","Sem","CGPA");
    for (int i=0;i<n;i++) {
        printf("%-12d %-6d %-15s %-12s %-20s %-5s %-7d %.2f\n",
               s[i].sap_id, s[i].roll_no, s[i].name, s[i].phone,
               s[i].email, s[i].year, s[i].semester, s[i].cgpa);
    }
}

// Display specific student by roll number
void displayStudent(struct Student s[], int n, int roll) {
    for (int i=0;i<n;i++) {
        if (s[i].roll_no==roll) {
            printf("\nRecord found:\n");
            printf("Name: %s\nSAP ID: %d\nPhone: %s\nEmail: %s\nYear: %s\nSemester: %d\nCGPA: %.2f\n",
                   s[i].name, s[i].sap_id, s[i].phone, s[i].email,
                   s[i].year, s[i].semester, s[i].cgpa);
            return;
        }
    }
    printf("Student not found!\n");
}

// Delete a student record
void deleteStudent(struct Student s[], int *n, int roll) {
    int found=0;
    for (int i=0;i<*n;i++) {
        if (s[i].roll_no==roll) {
            for (int j=i;j<*n-1;j++) s[j]=s[j+1];
            (*n)--;
            found=1;
            printf("Record deleted successfully!\n");
            break;
        }
    }
    if (!found) printf("Student not found!\n");
}

// Sort by SAP ID (ascending)
void sortBySAP(struct Student s[], int n) {
    struct Student temp;
    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            if (s[i].sap_id > s[j].sap_id) {
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
    }
}

// Sort by Name (alphabetically)
void sortByName(struct Student s[], int n) {
    struct Student temp;
    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            if (strcmp(s[i].name, s[j].name) > 0) {
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
    }
}

// Average CGPA of each year
void avgYearCGPA(struct Student s[], int n) {
    float sum1=0,sum2=0,sum3=0,sum4=0;
    int c1=0,c2=0,c3=0,c4=0;
    for (int i=0;i<n;i++) {
        if (strcmp(s[i].year,"1st")==0){sum1+=s[i].cgpa;c1++;}
        else if (strcmp(s[i].year,"2nd")==0){sum2+=s[i].cgpa;c2++;}
        else if (strcmp(s[i].year,"3rd")==0){sum3+=s[i].cgpa;c3++;}
        else if (strcmp(s[i].year,"4th")==0){sum4+=s[i].cgpa;c4++;}
    }
    printf("\nAverage CGPA by Year:\n");
    if (c1) printf("1st Year: %.2f\n", sum1/c1);
    if (c2) printf("2nd Year: %.2f\n", sum2/c2);
    if (c3) printf("3rd Year: %.2f\n", sum3/c3);
    if (c4) printf("4th Year: %.2f\n", sum4/c4);
}

// Add new student from user input
void addStudent(struct Student s[], int *n) {
    int i = *n;
    printf("\nEnter details for new student:\n");
    printf("SAP ID: "); scanf("%d", &s[i].sap_id);
    printf("Roll No: "); scanf("%d", &s[i].roll_no);
    printf("Name: "); getchar(); gets(s[i].name); // for spaces
    printf("Phone: "); gets(s[i].phone);
    printf("Email: "); gets(s[i].email);
    printf("Year (1st/2nd/3rd/4th): "); gets(s[i].year);
    printf("Semester: "); scanf("%d", &s[i].semester);
    printf("Enter SGPA for 8 semesters (0 if not completed):\n");
    for (int j=0;j<8;j++) scanf("%f", &s[i].sgpa[j]);

    // Calculate CGPA
    calculateCGPA(s, *n + 1);
    (*n)++;
    printf("Student added successfully!\n");
}/