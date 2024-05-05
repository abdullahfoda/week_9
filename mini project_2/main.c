#include <stdio.h>

// Function  calculates average score
float calculate_average(float scores[], int num_students) {
    float total = 0;
    for (int i = 0; i < num_students; i++) {
        total += scores[i];
    }
    return total / num_students;
}

// Function  identifys below average scores
void below_average_students(char names[][50], float scores[], int num_students, float average) {
    int below_avg_count = 0; // Counter for below average students
    for (int i = 0; i < num_students; i++) {
        if (scores[i] < average) {
            below_avg_count+=1;
            if (below_avg_count ==1 ) {
                printf("Warning: The following students scored below average:\n");
            }
            printf("%s: %.2f\n", names[i], scores[i]);
        }
    }
    if (below_avg_count == 0) {
        printf("All students scored above or equal to the average.\n");
    }
}

// Function  finds highest test score
float find_highest_score(float scores[], int num_students) {
    float max_score = scores[0];
    for (int i = 1; i < num_students; i++) {
        if (scores[i] > max_score) {
            max_score = scores[i];
        }
    }
    return max_score;
}

// Function  finds top student
void find_top_student(char names[][50], float scores[], int num_students) {
    float max_score = scores[0];
    int max_index = 0;
    for (int i = 1; i < num_students; i++) {
        if (scores[i] > max_score) {
            max_score = scores[i];
            max_index = i;
        }
    }
    printf("Top Student: %s\n", names[max_index]);
    printf("Appreciation Message: Congratulations, %s, for being the top-performing student!\n", names[max_index]);
}


int main() {
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    char names[num_students][50];
    float scores[num_students];

    for (int i = 0; i < num_students; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", names[i]);
        printf("Enter the score of student %d: ", i + 1);
        scanf("%f", &scores[i]);
    }

    float average = calculate_average(scores, num_students);
    printf("Average Test Score: %.2f\n", average);

    below_average_students(names, scores, num_students, average);

    float highest_score = find_highest_score(scores, num_students);
    printf("Highest Test Score: %.2f\n", highest_score);

    find_top_student(names, scores, num_students);

    return 0;
}
