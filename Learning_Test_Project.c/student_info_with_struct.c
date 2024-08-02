#include<stdio.h>
#include<string.h>

struct nametype{
       char firstname[40];
       char midname[40];
       char lastname[40];
};

struct studenttype{
       int id;
       struct nametype name;
};

int main(){

       int numOfStudent, i, mid;
       printf("Enter number of student\n~ ");
       scanf("%d", &numOfStudent);

       struct studenttype student[numOfStudent];

       for(i=0; i<numOfStudent; i++){
              printf("Enter the Id for student %d\n~ ", i+1);
              scanf("%d", &student[i].id);
              printf("Enter the First name for student %d\n~ ", i+1);
              scanf("%s", student[i].name.firstname);

              student[i].name.midname[0] = '\0';
              printf("Any mid name?\n1.Yes\n2.No\n~ ");
              scanf("%d", &mid);
              if(mid == 1){
                     printf("Enter the Mid name for student %d\n~ ", i+1);
                     scanf("%s", student[i].name.midname);
              }

              printf("Enter the Last name for student %d\n~ ", i+1);
              scanf("%s", student[i].name.lastname);

              printf("--------------------\n");

       }

       printf("Output : \n\n");

       for(i=0; i<numOfStudent; i++){
              printf("Id: %d\t", student[i].id);
              printf("Name: %s %s %s.\n", student[i].name.firstname, student[i].name.midname, student[i].name.lastname);
       }

       return 0;
}
