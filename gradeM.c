#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
    int ID;
    char nom[50];
    float *grades;
}Student;
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
    return -1;// Element not found
}
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
    return -1;// Element not found
}
int isFull(Student arr[], int n){
  int i = 0, j = 0;
  while(i < n){
    if(arr[i].ID != 0 && strcmp(arr[i].nom, "JohnDoe") != 0)
      j++;
    i++;
  }
  if(i == j)
    return 0;
  else
    return -1;
}
int isEmpty(Student arr[], int n){
  int i = 0, j = 0;
  while(i < n){
    if(arr[i].ID == 0 && strcmp(arr[i].nom, "JohnDoe") == 0)
      j++;
    i++;
  }
  if(i == j)
    return 0;
  else
    return -1;
}
int main(){
  int choice = 0, n, nbNotes = 0, auto_ID = 0;
  puts("===== STUDENT GRADE MANAGER =====");
  puts("Please enter the number of your students");
  scanf("%d",&n);
  puts("Please enter the number of grades");
  scanf("%d",&nbNotes);
  Student students[n];
  for(int i = 0; i < n; i++){
    Student S;
    S.ID = 0;
    strcpy(S.nom,"JohnDoe");
    S.grades = (float*)malloc(1*sizeof(float));
    students[i] = S;
  }
  do{
    puts("===== STUDENT GRADE MANAGER =====");
    puts("1. Add a student");
    puts("2. Modify a student");
    puts("3. Delete a student");
    puts("4. Search student");
    puts("5. Display all students");
    puts("6. exit");
    scanf("%d",&choice);
    switch(choice){
      case 1:
        if(isFull(students, n) == 0)
          puts("The list is full!");
        else{
          puts("===== ADD STUDENT =====");
          Student s;
          auto_ID++;
          s.ID = auto_ID;
          printf("Name: ");
          scanf("%s", s.nom);
          s.grades = (float*)malloc(nbNotes*sizeof(float));
          for(int i = 0; i < nbNotes; i++){
            printf("Grade %d: ",i+1);
            scanf("%f", &s.grades[i]);
          }
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
      case 2:
        if(isEmpty(students, n) == 0)
          puts("The list is empty!");
        else{
          puts("===== MODIFY STUDENT =====");
          Student st;
          int s_ID;
          puts("The ID of the student you want to modify");
          scanf("%d",&s_ID);
          int index;
          if(isFull(students,n) == 0)
            index = searchStudent(students, n, s_ID);
          else
            index = linearSearchStudent(students, n, s_ID);
          if(index != -1 && students[index].ID != 0){
            int c = 0;
            do{
              puts("===== MODIFY STUDENT =====");
              puts("what would you like to modify?");
              puts("1. Name");
              puts("2. Grades");
              puts("3. validate");
              scanf("%d",&c);
              switch(c){
                case 1:
                  puts("===== MODIFY NAME =====");
                  //char n_nom[50];
                  printf("New Name: ");
                  scanf("%s", students[index].nom);
                  //students[index].nom = n_nom;
                break;
                case 2:
                  puts("===== MODIFY GRADE =====");
                  puts("which grade would you like to modify?");
                  int g_index;
                  for(int i = 0; i < nbNotes; i++){
                    printf("%d. %2f\n", i+1, students[index].grades[i]);
                  }
                  scanf("%d", &g_index);
                  float n_value;
                  for(int i = 0; i < nbNotes; i++){
                    if(g_index == i+1){
                      printf("New value: ");
                      scanf("%f", &n_value);
                      students[index].grades[i] = n_value;
                    }
                  }
                break;
                case 3:
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
      case 3:
        if(isEmpty(students, n) == 0)
          puts("The list is empty!");
        else{
          puts("===== DELETE STUDENT =====");
          Student st;
          int s_ID;
          puts("The ID of the student you want to delete");
          scanf("%d",&s_ID);
          int index;
          if(isFull(students,n) == 0)
            index = searchStudent(students, n, s_ID);
          else
            index = linearSearchStudent(students, n, s_ID);
          st.ID = 0;
          strcpy(st.nom,"JohnDoe");
          st.grades = (float*)malloc(1*sizeof(float));
          if(index != -1 && students[index].ID != 0){
            free(students[index].grades);
            students[index] = st;
            puts("Student deleted!");
          }else{
            puts("Student not found!");
          }
        }
      break;
      case 4:
        if(isEmpty(students, n) == 0)
          puts("The list is empty!");
        else{
          puts("===== SEARCH STUDENT =====");
          int s_ID;
          puts("The ID of the student you're looking for:");
          scanf("%d",&s_ID);
          int index;
          if(isFull(students,n) == 0)
            index = searchStudent(students, n, s_ID);
          else
            index = linearSearchStudent(students, n, s_ID);
          if(index != -1 && students[index].ID != 0){
            printf("ID : %d\nName : %s\n",students[index].ID, students[index].nom);
            printf("Grades : ");
            for(int j = 0; j < nbNotes; j++){
              printf("         %2f\n", students[index].grades[j]);
            }
          }else{
            puts("Student not found!");
          }
        }
      break;
      case 5:
        puts("===== DISPLAY STUDENTS =====");
        puts("The list of students :");
        for(int i = 0; i < n; i++){
          printf("%d. %s: \n", students[i].ID, students[i].nom);
          for(int j = 0; j < nbNotes; j++){
            printf("  %2f\n", students[i].grades[j]);
          }
        }
      break;
      case 6:
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