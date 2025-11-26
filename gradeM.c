#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  typedef struct student{
    int ID;
    char nom[50];
    int nbNotes;
    float *grades;
  }Student;
  int choice = 0, n;
  puts("===== STUDENT GRADE MANAGER =====");
  puts("Please enter the number of your students");
  scanf("%d",&n);
  Student students[n];
  for(int i = 0; i < n; i++){
    Student S;
    S.ID = 0;
    S.nbNotes = 0;
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
        puts("===== ADD STUDENT =====");
        Student s;
        printf("ID of the student: ");
        scanf("%d", &s.ID);
        printf("Name: ");
        scanf("%s", s.nom);
        printf("number of grades: ");
        scanf("%d", &s.nbNotes);
        s.grades = (float*)malloc(n*sizeof(float));
        for(int i = 0; i < s.nbNotes; i++){
          printf("Grade %d: ",i);
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
          puts("The list is full !!");
        }
        puts("");
      break;
      case 2:
        puts("===== MODIFY STUDENT =====");
        Student st;
        int s_ID
        puts("The ID of the student you want to modify");
        scanf("%d",&s_ID);
        
        for
      break;
      case 3:
        puts("===== DELETE STUDENT =====");
        puts("standby");
      break;
      case 4:
        puts("===== SEARCH STUDENT =====");
        puts("standby");
      break;
      case 5:
        puts("===== DISPLAY STUDENTS =====");
        puts("The list of students :");
        for(int i = 0; i < n; i++){
          printf("%d. %s: \n", students[i].ID, students[i].nom);
          for(int j = 0; j < students[i].nbNotes; j++){
            printf("  %f\n", students[i].grades[j]);
          }
        }
      break;
      case 6:
        puts("Bye !!");
        exit(0);
      break;
    }
  }while(choice != 6);
  return 0;
}