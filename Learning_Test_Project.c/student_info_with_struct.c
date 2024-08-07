#include <stdio.h>
#include <string.h>

typedef struct {
    char firstname[40];
    char midname[40];
    char lastname[40];
} nametype;

typedef struct {
    int id;
    nametype name;
    char grade[3];
} studenttype;

void calculate_grade(studenttype *s, int mark);

int main() {
    int numberOfStudent, mid, i;
    printf("Enter number of students\n~ ");
    scanf("%d", &numberOfStudent);

    studenttype student[numberOfStudent];
    int marks[numberOfStudent]; // Ensure this matches the number of students or adjust dynamically

    for(i = 0; i < numberOfStudent; i++) {
        printf("Enter student Id\n~ ");
        scanf("%d", &student[i].id);

        printf("Enter student First name\n~ ");
        scanf("%s", student[i].name.firstname);

        student[i].name.midname[0] = '\0'; // Corrected to use student[i]
        printf("Any mid name?\n1.Yes\n2.No\n~ ");
        scanf("%d", &mid);

        if(mid == 1) {
            printf("Enter student Mid name\n~ ");
            scanf("%s", student[i].name.midname);
        }

        printf("Enter student Last name\n~ ");
        scanf("%s", student[i].name.lastname);

        printf("Enter Number of student\n~ "); // Initialize the grade to an empty string
        scanf("%d", marks);


        printf("\n-----------------------------------------------------------\n");
    }

    for(i = 0; i < numberOfStudent; i++) {
        calculate_grade(&student[i], marks[i]);
    }

    printf("Output: \n\n");

    for(i = 0; i < numberOfStudent; i++) {
        printf("Id: %d\t", student[i].id);
        printf("Name: %s %s %s\t", student[i].name.firstname, 
               student[i].name.midname, 
               student[i].name.lastname);
        printf("Grade: %s\n", student[i].grade);
    }

    return 0;
}

void calculate_grade(studenttype *s, int mark) {
    if (mark >= 90) {
        strcpy(s->grade, "Golden-A");
    } else if (mark >= 80) {
        strcpy(s->grade, "A+");
    } else if (mark >= 70) {
        strcpy(s->grade, "B");
    } else if (mark >= 60) {
        strcpy(s->grade, "C");
    } else if (mark >= 50) {
        strcpy(s->grade, "D");
    } else if (mark >= 40) {
        strcpy(s->grade, "E");
    } else {
        strcpy(s->grade, "F");
    }
}
