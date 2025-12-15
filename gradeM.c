
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a student
typedef struct student{
    int ID;              // Unique identifier for the student
    char name[50];        // Name of the student (up to 49 characters)
    float *grades;       // Pointer to an array of grades (dynamically allocated)
}Student;

// Function to perform linear search on the student array by ID
int linearSearchStudent(Student arr[], int n, int target) {
    int i = 0;
    while (i < n) {
        if (arr[i].ID == target) {
          // Element found
          return i;
        }
        else {
          i++;
        }
    }
    return -1; // Element not found
}

// Function to perform binary search on the student array by ID (assumes array is sorted)
int searchStudent(Student arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid].ID == target) {
           // Element found
            return mid;
        }
        else if (arr[mid].ID < target) {
            low = mid + 1; // Search right half
        }
        else {
            high = mid - 1; // Search left half
        }
    }
    return -1; // Element not found
}

// Function to check if the student array is full (all slots occupied)
int isFull(Student arr[], int n){
  int i = 0, j = 0;
  while(i < n){
    if(arr[i].ID != 0 && strcmp(arr[i].name
, "JohnDoe") != 0)
      j++;
    i++;
  }
  if(i == j)
    return 0; // Array is full
  else
    return -1; // Array is not full
}

// Function to check if the student array is empty (all slots are default)
int isEmpty(Student arr[], int n){
  int i = 0, j = 0;
  while(i < n){
    if(arr[i].ID == 0 && strcmp(arr[i].name
, "JohnDoe") == 0)
      j++;
    i++;
  }
  if(i == j)
    return 0; // Array is empty
  else
    return -1; // Array is not empty
}

// Main function: Entry point of the program
int main(){
  int choice = 0, n, nbNotes = 0, auto_ID = 0; // Variables for menu choice, number of students, number of grades, and auto-incrementing ID
  puts("===== STUDENT GRADE MANAGER =====");
  puts("Please enter the number of your students");
  scanf("%d",&n);
  puts("Please enter the number of grades");
  scanf("%d",&nbNotes);
  Student students[n]; // Declare an array of students with size n
  // Initialize the student array with default values
  for(int i = 0; i < n; i++){
    Student S;
    S.ID = 0;
    strcpy(S.name
,"JohnDoe");
    S.grades = (float*)malloc(1*sizeof(float)); // Allocate minimal space initially
    students[i] = S;
  }
  do{
    // Display the main menu
    puts("===== STUDENT GRADE MANAGER =====");
    puts("1. Add a student");
    puts("2. Modify a student");
    puts("3. Delete a student");
    puts("4. Search student");
    puts("5. Display all students");
    puts("6. exit");
    scanf("%d",&choice);
    switch(choice){
      case 1: // Add a new student
        if(isFull(students, n) == 0)
          puts("The list is full!");
        else{
          puts("===== ADD STUDENT =====");
          Student s;
          auto_ID++; // Increment the auto ID
          s.ID = auto_ID;
          printf("Name: ");
          scanf("%s", s.name
    );
          s.grades = (float*)malloc(nbNotes*sizeof(float)); // Allocate space for grades
          // Input grades for the student
          for(int i = 0; i < nbNotes; i++){
            printf("Grade %d: ",i+1);
            scanf("%f", &s.grades[i]);
          }
          // Find the first empty slot and add the student
          for(int i = 0; i < n; i++){
            if(students[i].ID != 0 && i != n-1)
              continue;
            if(students[i].ID == 0){
              students[i] = s;
              puts("student added succesfully");
              break;
            }
          }
        }
      break;
      case 2: // Modify an existing student
        if(isEmpty(students, n) == 0)
          puts("The list is empty!");
        else{
          puts("===== MODIFY STUDENT =====");
          Student st;
          int s_ID;
          puts("The ID of the student you want to modify");
          scanf("%d",&s_ID);
          int index;
          // Use binary search if full, linear otherwise
          if(isFull(students,n) == 0)
            index = searchStudent(students, n, s_ID);
          else
            index = linearSearchStudent(students, n, s_ID);
          if(index != -1 && students[index].ID != 0){
            int c = 0;
            do{
              // Sub-menu for modification options
              puts("===== MODIFY STUDENT =====");
              puts("what would you like to modify?");
              puts("1. Name");
              puts("2. Grades");
              puts("3. validate");
              scanf("%d",&c);
              switch(c){
                case 1: // Modify name
                  puts("===== MODIFY NAME =====");
                  printf("New Name: ");
                  scanf("%s", students[index].name
            );
                break;
                case 2: // Modify grades
                  puts("===== MODIFY GRADE =====");
                  puts("which grade would you like to modify?");
                  int g_index;
                  // Display current grades
                  for(int i = 0; i < nbNotes; i++){
                    printf("%d. %2f\n", i+1, students[index].grades[i]);
                  }
                  scanf("%d", &g_index);
                  float n_value;
                  // Update the selected grade
                  for(int i = 0; i < nbNotes; i++){
                    if(g_index == i+1){
                      printf("New value: ");
                      scanf("%f", &n_value);
                      students[index].grades[i] = n_value;
                    }
                  }
                break;
                case 3: // Validate changes
                  puts("changes applyed!");
                break;
                default:
                  puts("invalid choice !!");
                break;
              }
            }while(c != 3);
          }
          else{
            puts("Student not found!");
          }
        }
      break;
      case 3: // Delete a student
        if(isEmpty(students, n) == 0)
          puts("The list is empty!");
        else{
          puts("===== DELETE STUDENT =====");
          Student st;
          int s_ID;
          puts("The ID of the student you want to delete");
          scanf("%d",&s_ID);
          int index;
          // Use binary search if full, linear otherwise
          if(isFull(students,n) == 0)
            index = searchStudent(students, n, s_ID);
          else
            index = linearSearchStudent(students, n, s_ID);
          // Create a default student to overwrite
          st.ID = 0;
          strcpy(st.name
      ,"JohnDoe");
          st.grades = (float*)malloc(1*sizeof(float));
          if(index != -1 && students[index].ID != 0){
            free(students[index].grades); // Free the grades memory
            students[index] = st; // Overwrite with default
            puts("Student deleted!");
          }else{
            puts("Student not found!");
          }
        }
      break;
      case 4: // Search for a student
        if(isEmpty(students, n) == 0)
          puts("The list is empty!");
        else{
          puts("===== SEARCH STUDENT =====");
          int s_ID;
          puts("The ID of the student you're looking for:");
          scanf("%d",&s_ID);
          int index;
          // Use binary search if full, linear otherwise
          if(isFull(students,n) == 0)
            index = searchStudent(students, n, s_ID);
          else
            index = linearSearchStudent(students, n, s_ID);
          if(index != -1 && students[index].ID != 0){
            // Display student details
            printf("ID : %d\nName : %s\n",students[index].ID, students[index].name
      );
            printf("Grades : ");
            for(int j = 0; j < nbNotes; j++){
              printf("         %2f\n", students[index].grades[j]);
            }
          }else{
            puts("Student not found!");
          }
        }
      break;
      case 5: // Display all students
        puts("===== DISPLAY STUDENTS =====");
        puts("The list of students :");
        for(int i = 0; i < n; i++){
          printf("%d. %s: \n", students[i].ID, students[i].name
    );
          for(int j = 0; j < nbNotes; j++){
            printf("  %2f\n", students[i].grades[j]);
          }
        }
      break;
      case 6: // Exit the program
        // Free allocated memory for grades
        for(int i = 0; i < n; i++){
          free(students[i].grades);
        }
        puts("Bye !!");
        exit(0);
      default:
        puts("invalid choice !!");
      break;
    }
  }while(choice != 6);
  return 0;
}