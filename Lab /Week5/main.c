#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// student record structure
typedef struct {
    char name[50];
    int id;
    int enrollmentYear;
    float cgpa;
} Student;

// random student record generator function
void generateStudentRecords(Student students[], int n) {
    char names[][50] = {"Parth", "Tanay", "Vaibhav", "Suryavir", "Pratham", "Saniya", "Nikhil", "Dev", "Anushka", "Aditya"};
    int ids[] = {1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010};
    int years[] = {2020, 2021, 2022, 2023, 2024};

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        strcpy(students[i].name, names[rand() % 10]);
        students[i].id = ids[rand() % 10];
        students[i].enrollmentYear = years[rand() % 5];
        students[i].cgpa = (float)(rand() % 101) / 10; 
    }
}

// function to merge two sorted subarrays
void merge(Student arr[], Student left[], int leftSize, Student right[], int rightSize) {
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
        if (strcmp(left[i].name, right[j].name) <= 0) {
            arr[k++] = left[i];
            i++;
        } else {
            arr[k++] = right[j];
            j++;
        }
    }

    while (i < leftSize) {
        arr[k++] = left[i];
        i++;
    }

    while (j < rightSize) {
        arr[k++] = right[j];
        j++;
    }
}

// merge sort function (fix error)
void mergeSort(Student arr[], int n) {
    if (n < 2)
        return;

    int mid = n / 2;
    Student left[mid], right[n - mid];

    for (int i = 0; i < mid; i++)
        left[i] = arr[i];

    for (int i = mid; i < n; i++)
        right[i - mid] = arr[i];

    mergeSort(left, mid);
    mergeSort(right, n - mid);
    merge(arr, left, mid, right, n - mid);
}

// main
int main() {
    int n = 10; 
    Student students[n];

    // generate random student records
    generateStudentRecords(students, n);

    printf("Unsorted Student Records:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, ID: %d, Enrollment Year: %d, CGPA: %.2f\n", students[i].name, students[i].id, students[i].enrollmentYear, students[i].cgpa);
    }

    // timer
    clock_t start = clock();

    mergeSort(students, n);

    clock_t end = clock();
    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nSorted Student Records (by Name):\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, ID: %d, Enrollment Year: %d, CGPA: %.2f\n", students[i].name, students[i].id, students[i].enrollmentYear, students[i].cgpa);
    }

    printf("\nTime taken for sorting: %.6f seconds\n", timeTaken);

    return 0;
}
