#include <stdio.h>

char get_letter_grade(float average) {
    if (average >= 80)
        return 'A+';
    else if (average >= 70)
        return 'A';
    else if (average >= 60)
        return 'A-';
    else if (average >= 50)
        return 'B';
    else if (average >= 45)
        return 'C';
    else if (average >= 40)
        return 'D';
    else
        return 'F';
}

void print_student_data(int count, int number_of_bangla[], int number_of_english[], int number_of_math[], float average[], char grade[]) {
    printf("\nStudent marks and grades:\n");
    printf("Student\tBangla\tEnglish\tMath\tAverage\tGrade\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%d\t%d\t%d\t%.2f\t%c\n", i + 1, number_of_bangla[i], number_of_english[i], number_of_math[i], average[i], grade[i]);
    }
}

void sort_students(int count, int number_of_bangla[], int number_of_english[], int number_of_math[], float average[], char grade[]) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (average[i] < average[j]) {
                // Swap average
                float temp_avg = average[i];
                average[i] = average[j];
                average[j] = temp_avg;

                // Swap grade
                char temp_grade = grade[i];
                grade[i] = grade[j];
                grade[j] = temp_grade;

                // Swap Bangla marks
                int temp_marks = number_of_bangla[i];
                number_of_bangla[i] = number_of_bangla[j];
                number_of_bangla[j] = temp_marks;

                // Swap English marks
                temp_marks = number_of_english[i];
                number_of_english[i] = number_of_english[j];
                number_of_english[j] = temp_marks;

                // Swap Math marks
                temp_marks = number_of_math[i];
                number_of_math[i] = number_of_math[j];
                number_of_math[j] = temp_marks;
            }
        }
    }
}

int main() {
    int number_of_student;
    printf("Enter number of students: ");
    scanf("%d", &number_of_student);

    int number_of_bangla[number_of_student];
    int number_of_english[number_of_student];
    int number_of_math[number_of_student];
    float average[number_of_student];
    char grade[number_of_student];

    printf("\nEnter marks of Bangla:\n");
    for (int i = 0; i < number_of_student; i++) {
        printf("%dth student's marks: ", i + 1);
        scanf("%d", &number_of_bangla[i]);
    }

    printf("\nEnter marks of English:\n");
    for (int i = 0; i < number_of_student; i++) {
        printf("%dth student's marks: ", i + 1);
        scanf("%d", &number_of_english[i]);
    }

    printf("\nEnter marks of Math:\n");
    for (int i = 0; i < number_of_student; i++) {
        printf("%dth student's marks: ", i + 1);
        scanf("%d", &number_of_math[i]);
    }

    // Calculate average and grade
    for (int i = 0; i < number_of_student; i++) {
        average[i] = (number_of_bangla[i] + number_of_english[i] + number_of_math[i]) / 3.0;
        grade[i] = get_letter_grade(average[i]);
    }

    // Print all student data
    print_student_data(number_of_student, number_of_bangla, number_of_english, number_of_math, average, grade);

    // Sort students by average
    sort_students(number_of_student, number_of_bangla, number_of_english, number_of_math, average, grade);

    // Print sorted student data
    printf("\nSorted student data by average marks:\n");
    print_student_data(number_of_student, number_of_bangla, number_of_english, number_of_math, average, grade);

    return 0;
}
