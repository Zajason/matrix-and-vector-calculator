


/*
to dos:
1.create an array ok
2.load an array
3.show available arrays ok
4.delete arrays ok 
5.vector operations ok
6.matrix operations ok
*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "time.h"
#include <math.h>



int a;
char c[100];

int num ;




int main() {

   
        void create_array();
        void delete_array();
        void preview_arrays();
        void matrix_operation();
        void vector_operation();
        void load_array();
        void gauss();
        int user_answer;
        time_t t;
        srand((unsigned) time(&t));
        int vaccination;
        printf("In order to use this project you have to be vaccinated against covid-19.\n");
        printf("Bad ASCII drawing of a vaccine:\n");
        printf("\n");
        printf("         ||==========================|\n");
        printf("|        ||         |------|         |\n");
        printf("|========||         |PFISER|         |--------------------\n");                            
        printf("|        ||         |------|         |\n");
        printf("         ||==========================|\n");
        printf("\n");
        printf("Are you fully vaccinated? Type 1 for yes or 2 for no\n");
        scanf("%d" , &vaccination);
        if (vaccination == 1){


        printf(
                " =====================================================================================\n 1.create an array\n 2.load an array\n 3.Show available arrays\n 4.Delete array\n 5.Vector operations \n 6.Matrix operations\n 7.Solve the system corresponding to a matrix with the Gauss Elimination method\n=====================================================================================\n"
          //εκτυπωνεται το κυριο μενου

        ) ;
        printf("Please choose one of the above options!\n=====================================================================================\n");
        scanf("%d" , &user_answer);
        printf("=====================================================================================\n");
//παιρνω την επιλογη του χρηστη και την αποθηκευω σε μια μεταβλητη
        if (user_answer == 1){

            create_array();
           
        }
        else if(user_answer ==2){
          load_array();
        }
        else if(user_answer == 3){
          preview_arrays();
          int uao;
          printf("would you like to go back to the main meny? Type 0 to do so!\n");
          scanf("%d", &uao);
          if(uao == 0){
            main();
          }
          else{
            printf("i do not accept no as an answer");
          }
        }
         else if (user_answer == 4){
            delete_array();
//αν ο χρηστης επιλεξει την επιλογη 4 καλειται η function delete_arrays()
        }
        else if (user_answer == 5){
          vector_operation();
        }
        else if(user_answer == 6){
          matrix_operation();
        }
        else if(user_answer == 7){
          gauss();
        }
        else{
          printf("This is not a viable choice you wil be redirected to the main menu\n");
          main();
        }
        }
        if (vaccination ==2){
          printf("I am sorry but you can not use this app have a nice day");
        }
        return 0;

//αναλογα την επιλογη του χρηστη καλειται η αναλογη συστοιχια
    }



void create_array(){
  FILE *last = fopen("lastnum.csv" , "r");
  void matrix_operation();
  void preview_arrays();
  void vector_operation();
    int rows;
    int cols;
    int i;
    int matrix[100];
    printf("how many columns would you like your array to have\n");

    scanf("%d" ,&cols );
    printf("=====================================================================================\nhow many rows would you like your array to have\n");
    
    scanf("%d" ,&rows );
    printf("==========================================================\n");
// ο χρηστης καλειται να επιλεξει τον αριυμο των στηλων και των γραμμων που θα καταλαμβανει η array που θα φτιαξει
   
    char filename[80];
    char filenameRow[80];
    char filenameCol[80];

  //ενα string  στο οποιο αποθηκευω το ονομα ενος αρχιου στο οποιο θα αποθηκευεται η array , και δυο για τα αρχια στα οποια θα αποθηκευεται ο αριθμος των σειρων και των γραμμων 

    
//ανοιγω το αρχιο τυπου csv lastnum το οποιο περιεχει αρχικα τον αριθμο 1
fgets(c , sizeof c, last);
  num = atoi(c);
  //το περιεχομενο του αρχιου μετατρεπεται σε μια μεταβλητη int  ωστε να μπορω να το χρησιμοποιησω στον κωδικα μου 
    
snprintf(filename, sizeof(filename), "array.%d.csv", num);
snprintf(filenameRow , sizeof(filenameRow) , "row.%d.csv" , num);
snprintf(filenameCol , sizeof(filenameCol) , "col.%d.csv" , num);
//ανοιγω ενα νεο αρχιο  το οποιο θα ειναι διαφορετικο καθε φορα που καλειται το function μου χαρη στη μεταβλητη num στην οποια θα προσθετω ενα και θα την ξανααποθηκευω στο αρχιο lastnum.csv καθως και δυο αρχια στα οποια θα αποθηκευονται ο αριθμος των γραμμων και των στηλων καθε array.

FILE *fout = fopen(filename, "wb");
FILE *frow = fopen(filenameRow, "wb");
FILE  *fcol = fopen(filenameCol , "wb");

//ξαναανοιγω το αρχιο αυτη τη φορα με wb ωστε να μπορω να γραψω μεσα σε αυτο και ταυτοχρονα ανοιγω τα δυο αλλα αρχια στα οποια αποθηκευω τον αριθμο των στηλων και των γραμμων.

fprintf(frow , "%d" , rows);
fprintf(fcol , "%d" , cols);
//αποθηκευω στα δυο αρχια csv των αριθμων των στηλων και των γραμμων καθως θα τα χρησιμοποιησω αργοτερα

  


    if(fout == NULL) {
        printf("fout is null");
        printf("%d" , num);
        //error handling για το ανοιγμα του αρχιου array.num.csv
    }
    if(last == NULL) {
        printf("last is null");
         //error handling για το ανοιγμα του αρχιου lastnum.csv
    }

 printf("Please type your desired elements\n");
    for (i = 0 ; i < rows*cols; i ++){
      printf("Element # %d of %d:" , i+1 ,rows*cols);
      scanf("%d",&matrix[i]);
        printf("\n");
        fprintf(fout,"%d,", matrix[i]);
       
            }
        
       

//μεσω  for loop αποθηκευω μεταβλητες που μου δινει ο χρηστης σε ενα 2 dimensional array το οποιο στη συνεχεια αποθηκευω στο αρχιο csv που εφτιξα στην αρχη του create_array

    
   
    printf("Your array was saved successfuly inside the file %s\n", filename);
    FILE *last2 = fopen("lastnum.csv" , "wt");
   int  num2 = num+1;
    fprintf(last2 , "%d" , num2);
    fclose(last2);
    fclose(fout);
    fclose(frow);
    fclose(fcol);
    main();
    //προσθετω ενα στη μεταβλητη num και στη συνεχεια αντικαθιστω τον αριθμο στο αρχιο lastnum με το νεο  num επιτυγχανοντας ετσι διαφορετικο αρχιο καθε φορα που καλειται το συγκεκριμενο function
   


}
void delete_array(){
  void preview_arrays();
  int main();
  int user_choice;
FILE *last = fopen("lastnum.csv" , "r");
fgets(c , sizeof c, last);
  num = atoi(c);
printf("which array would you like to delete.\n=====================================================================================\n If you want to delete one array type it's number .\n If you want to delete all of them type 0\n.If you want to see the available arrays type 12:\n ");
scanf("%d" , &user_choice);
printf("=====================================================================================\n");
if(user_choice ==0){
  for(int i =0; i<num; i++){
    char filename[89];
    char filenamerow[89];
    char filenamecol[89];
    snprintf(filename, sizeof(filename), "array.%d.csv", i);
    snprintf(filenamerow , sizeof(filenamerow) , "row.%d.csv" , i);
    snprintf(filenamecol , sizeof(filenamecol), "col.%d.csv" , i);
    remove(filename);
    remove(filenamerow);
    remove(filenamecol);
    
  }
  FILE *last2 = fopen("lastnum.csv" , "wt");
   int  num2 = 1;
    fprintf(last2 , "%d" , num2);
    fclose(last2);
    main();
//σε αυτο το function μεσω ενος for loop ανοιγω ολα τα μεχρι τωρα αρχια και τα διαγραφω και ταυτοχρονα αλλαζω τον αριθμο στο αρχιο lastnum σε ενα ωστε το επομενο csv που θα δημιουργηθει να ειναι παλι το ενα
    printf("all arrays were deleted\n");
}
else if(user_choice ==12){
  preview_arrays();
  printf("To delete arrays type 4\nTo go back to the main menu type 0"
  );
  int choice;
  scanf("%d" , &choice);
  if (choice == 0){
    main();
  }
  else if(choice == 4){
    delete_array();
  }

}
else {
  char new_filename[90];
  char new_rowname[90];
  char new_colname[89];
  snprintf(new_filename , sizeof(new_filename), "array.%d.csv", user_choice);
  snprintf(new_rowname , sizeof(new_rowname) , "row.%d.csv" , user_choice);
  snprintf(new_colname , sizeof(new_colname) , "col.%d.csv" , user_choice);
  remove(new_filename);
  remove(new_rowname);
  remove(new_colname);
  printf("array %d was deleted" , user_choice);
}
fclose(last);
    main();
}






void preview_arrays(){

int n;
char* value;
char buffer1[1024];
int matrix1[1024];
char last_f[1024];

    
    FILE *last = fopen("lastnum.csv" , "r");
    
fgets(last_f , sizeof last_f, last);
  num = atoi(last_f) ;

for(int i=1; i<num; i++){
  
    char filename[1024];
    char rowname[1024];
    char colname[1024];
    char srow[1024];
    char scol[1024];

  printf("Array %d :" , i);
    snprintf(filename, sizeof(filename), "array.%d.csv", i);
    snprintf(rowname, sizeof(rowname), "row.%d.csv", i);
    snprintf(colname, sizeof(colname), "col.%d.csv", i);


  FILE* filei = fopen(filename , "r");
  FILE* frow = fopen(rowname , "r");
  FILE* fcol = fopen(colname , "r");

  fscanf(frow , "%s" , srow);
  fscanf(fcol , "%s" , scol);


  int row = atoi(srow);
  int col = atoi(scol);
  

fscanf(filei , "%s", buffer1);

value = strtok(buffer1 , ",");
int l =0;
int z=0;
int a=0;
int matrix[100][100];
while(value != NULL){
  
   for(z=0; z<row; z++){
       printf("\n");
       for(a=0; a<col; a++){
          matrix[z][a] = atoi(value);
          value = strtok(NULL , ",");
          printf(" %d ",matrix[z][a]);
    
    
      }
   }
}
printf("\n");
fclose(filei);
fclose(frow);
fclose(fcol);


  }
  fclose(last);
    
  

}



void matrix_operation(){

  char buffer[1024];
  int user_answer;
  int a1 , a2 , temp;
  int vector[100];
  int rows1 , rows2 , cols1 , cols2;


  printf("\nBetween which two arrays would you like to perform a matrix operation?\n");
  printf("your choices are:\n");
  preview_arrays();
  printf("choice 1:\n");
  scanf("%d" , &a1);
  printf("choice2:\n");
  scanf("%d" , &a2);

 char filename1[80];
  char filename2[80];
  char filenamerow1[80];
  char filenamerow2[80];
  char filenamecol1[80];
  char filenamecol2[80];




  snprintf(filename1,sizeof(filename1) , "array.%d.csv" , a1);
  snprintf(filename2 , sizeof(filename2) , "array.%d.csv" , a2);
  snprintf(filenamerow1 , sizeof(filenamerow1) , "row.%d.csv" , a1);
  snprintf(filenamecol1 , sizeof(filenamecol1) , "col.%d.csv" , a1);
  snprintf(filenamerow2 , sizeof(filenamerow2) , "row.%d.csv" , a2);
  snprintf(filenamecol2 , sizeof(filenamecol2) , "col.%d.csv" , a2);




  FILE *f1 = fopen(filename1 , "r");
  FILE *f2 = fopen(filename2 , "r");
  FILE *f1row = fopen(filenamerow1 , "r");
  FILE *f2row = fopen(filenamerow2 , "r");
  FILE *f1col = fopen(filenamecol1 , "r");
  FILE *f2col = fopen(filenamecol2 , "r");
  
  if(f1 == NULL){
    printf("Array %d doesnt exist\n" , a1);
    matrix_operation();
  }
  if(f2==NULL){
    printf("Array %d doesnt exist\n" , a2);
    matrix_operation();
  }
  else{

  
  
//ανοιγω ολα τα αρχια που θα χρειαστω δηλαδη τα αρχια με τους πινακες αλλα και τα αρχια με τον αριθμο των στηλων και των γραμμων
char srows1[100];
char srows2[100];
char scols1[100];
char scols2[100];

//φτιαχνω 4 string στα οποια θα αποθηκευω τον αριθμο των γραμμων και των στηλων 


fgets(srows1 , sizeof srows1, f1row);
  rows1 = atoi(srows1);
fgets(srows2 , sizeof srows2, f2row);
  rows2 = atoi(srows2);
fgets(scols1 , sizeof scols1, f1col);
  cols1 = atoi(scols1);
fgets(scols2 , sizeof scols2, f2col);
  cols2 = atoi(scols2);


//με τη χρηση της fgets παιρνω τις τιμες των γραμων και των στηλων και στη συνεχεια με τη χρηση της atoi αποθηκευω τις τιμες αυτες σε int για να μπορω να τις χρησιμοποιησω στον κωδικα μου

int matrix1[100][100];
int matrix2[100][100];
int tempMatrix1[100];
int tempMatrix2[100];
int  j , m=0 , n;
int z=0 , a=0 , s =0 ,y =0;
int i=0;
char buffer1[256];
char buffer2[256];
char *value;

fscanf(f1 , "%s" , buffer1);
fscanf(f2 , "%s" , buffer2);


value = strtok(buffer1 , ",");
while(value != NULL){
  
   for(z=0; z<rows1; z++){
       printf("\n");
       for(a=0; a<cols1; a++){
          matrix1[z][a] = atoi(value);
          value = strtok(NULL , ",");
          printf(" %d ",matrix1[z][a]);
    
    
      }
   }
}
printf("\n");



value = strtok(buffer2 , ",");
while(value != NULL){
  
   for(z=0; z<rows2; z++){
      printf("\n");
      for(a=0; a<cols2; a++){
        matrix2[z][a] = atoi(value);
        value = strtok(NULL , ",");
        printf(" %d ",matrix2[z][a]);
    
    
      }
   }
}
printf("\n");
printf("What type of operation would you like to perform?\nType 1 for matrix addition.\nType 2 for matrix multiplication");


int ua ;
char addition[100][100];
scanf("%d" , &ua);

if(ua == 1){
  if(rows1 == rows2){
    if (cols1 == cols2){
      char result_file[100];
      snprintf(result_file , sizeof(result_file) , "matrix.addition.%d,  %d.csv" , a1, a2);
      FILE *result = fopen(result_file , "w");

      printf("The resulting matrix is:");
     for(z=0; z<rows1; z++){
       fprintf(result , "\n");
       printf("\n");
      for(a=0; a<cols1; a++){
        addition[z][a] = matrix1[z][a] + matrix2[z][a];
        printf(" %d " , addition[z][a]);
        fprintf(result , " %d " , addition[z][a]);
      }
     }
     fclose(result);
    }
  }
  else(printf("the addition of these matrices is not possible since they do not share the same dimensions\n"));
}


int multiplication[100][100];
if(ua ==2){
  char result2[100];
  snprintf(result2 , sizeof(result2) , "matrix_multiplication.%d,%d.csv",a1,a2);
  FILE *file_result2 = fopen(result2, "w");
  if(cols1 == rows2){
    printf("the result is :");
    int rows3 , cols3;
    cols3 = cols2;
    rows3 = rows1;
   for (int i = 0; i < rows1; ++i) {
      for (int j = 0; j < cols2; ++j) {
         multiplication[i][j] = 0;
      }
   }
   for (int i = 0; i < rows1; ++i) {
      for (int j = 0; j < cols2; ++j) {
         for (int k = 0; k < cols1; ++k) {
            multiplication[i][j] += matrix1[i][k] * matrix2[k][j];
            
         }
      }
   }
fprintf(file_result2 , "The resulting matrix when multiplying array%d with array%d is:" , a1 , a2);
for(int i=0; i<rows3; i++){
  printf("\n");
  fprintf(file_result2 , "\n");
  for(int j=0; j<cols3; j++){
    printf(" %d " , multiplication[i][j]);
    fprintf(file_result2 , " %d " , multiplication[i][j]);
  }
  printf("\n");
fclose(file_result2);
}

  }
  else if(cols1 != rows2){
    printf ("the multiplication of these two matrices is not possible. In order to multiply two matrices the collumns of the first one should be as many as the rows of the second one . \n");
  }
}
  }
 
fclose(f1);
fclose(f2);
fclose(f1row);
fclose(f2row);
fclose(f1col);
fclose(f2col);
main();
}



void vector_operation(){
  char buffer[1024];
  int user_answer;
  int a1 , a2 , temp;
  int vector[100];
  int rows1 , rows2 , cols1 , cols2;


  printf("between which two arrays would you like to perform a matrix operation?\n");
  printf("your choices are:\n");
  preview_arrays();
  printf("choice 1:\n");
  scanf("%d" , &a1);
  printf("choice 2:\n");
  scanf("%d" , &a2);

  char filename1[80];
  char filename2[80];
  char filenamerow1[80];
  char filenamerow2[80];
  char filenamecol1[80];
  char filenamecol2[80];




  snprintf(filename1,sizeof(filename1) , "array.%d.csv" , a1);
  snprintf(filename2 , sizeof(filename2) , "array.%d.csv" , a2);
  snprintf(filenamerow1 , sizeof(filenamerow1) , "row.%d.csv" , a1);
  snprintf(filenamecol1 , sizeof(filenamecol1) , "col.%d.csv" , a1);
  snprintf(filenamerow2 , sizeof(filenamerow2) , "row.%d.csv" , a2);
  snprintf(filenamecol2 , sizeof(filenamecol2) , "col.%d.csv" , a2);

  FILE *last = fopen("lastnum.csv" , "r");
  FILE *f1 = fopen(filename1 , "r");
  FILE *f2 = fopen(filename2 , "r");
  FILE *f1row = fopen(filenamerow1 , "r");
  FILE *f2row = fopen(filenamerow2 , "r");
  FILE *f1col = fopen(filenamecol1 , "r");
  FILE *f2col = fopen(filenamecol2 , "r");
  
    if(f1 == NULL){
    printf("Array %d doesnt exist\n" , a1);
    matrix_operation();
  }
  if(f2==NULL){
    printf("Array %d doesnt exist\n" , a2);
    matrix_operation();
  }
  else{
//ανοιγω ολα τα αρχια που θα χρειαστω δηλαδη τα αρχια με τους πινακες αλλα και τα αρχια με τον αριθμο των στηλων και των γραμμων
char srows1[100];
char srows2[100];
char scols1[100];
char scols2[100];
char c[100];
fscanf(last, "%s" , c);
num = atoi(c);

//φτιαχνω 4 string στα οποια θα αποθηκευω τον αριθμο των γραμμων και των στηλων 


fgets(srows1 , sizeof srows1, f1row);
  rows1 = atoi(srows1);
fgets(srows2 , sizeof srows2, f2row);
  rows2 = atoi(srows2);
fgets(scols1 , sizeof scols1, f1col);
  cols1 = atoi(scols1);
fgets(scols2 , sizeof scols2, f2col);
  cols2 = atoi(scols2);


//με τη χρηση της fgets παιρνω τις τιμες των γραμων και των στηλων και στη συνεχεια με τη χρηση της atoi αποθηκευω τις τιμες αυτες σε int για να μπορω να τις χρησιμοποιησω στον κωδικα μου

int  j , m=0 , n;
int i=0;

int matrix1[100];
int matrix2[100];
char buffer1[256];
char buffer2[256];
char *value;






fscanf(f1 , "%s" , buffer1);
fscanf(f2 , "%s" , buffer2);



value = strtok(buffer1 , ",");
while(value != NULL){
  
   
    matrix1[i] = atoi(value);
    value = strtok(NULL , ",");

     i++;
    
}
n=i;

for (i = 0;  i<n; i++){
  printf(" %d ", matrix1[i]);
}

printf("\n");


value = strtok(buffer2 , ",");
while(value != NULL){
  
   
    matrix2[m] = atoi(value);
    value = strtok(NULL , ",");

     m++;
    
}
j=m;

for (m = 0;  m<j; m++){
  printf(" %d ", matrix2[m]);
}

printf("\n");

int ua;
printf("What type of operation would you like to perform?\n");
printf("1.addition\n 2.inner product\n 3.outer product");
scanf("%d",&ua);


if(ua ==1){
if(rows1*cols1 != rows2*cols2){
  printf("These vectors can not be added since they dont have the same number of elments");
}
else if(rows1*cols1 == rows2 *cols2){
int addition[100];
char result_file[100];
snprintf(result_file , sizeof(result_file) , "addition_result.%d,%d.csv" , a1, a2);
FILE *result = fopen(result_file , "w");

fprintf(result, "array%d + array%d = \n" , a1 , a2);
 int u=0;

 for (u =0; u<rows1*cols1; u++){
   addition[u] = matrix1[u]+ matrix2[u];
   printf(" %d ",addition[u]);
   fprintf(result, " %d " , addition[u]);
 }
 fclose(result);
}

}

if(ua == 2){
  if(rows1*cols1 != rows2*cols2){
    printf("The  inner product of these vectors can not be found  since they dont have the same number of elments");


  }
  else if(rows1*cols1 == rows2 *cols2){
  int inner_product =0;
  int h=0;
  for (h=0; h<rows1*cols1; h++){
  inner_product = inner_product + matrix1[h]*matrix2[h];
  }
  printf("the inner product is %d" , inner_product);
  char result_file2[100];
snprintf(result_file2 , sizeof(result_file2) , "inner_result.%d,%d.csv" , a1, a2);
FILE *result2 = fopen(result_file2 , "w");

fprintf(result2, "the inner product of array%d and array%d = %d\n" , a1 , a2 , inner_product);
 int u=0;

 fclose(result2);

  }
}
else if (ua == 3){
int outer_product[100][100];
int y = 0;
int u = 0;



printf("The outer product of these vectors is the matrix:\n");

char result_file3[100];
snprintf(result_file3 , sizeof(result_file3) , "outer.%d,%d.csv" , a1, a2);
FILE *result3 = fopen(result_file3 , "w");

fprintf(result3, "the outer product of array%d and array%d is the matrix:" , a1 ,a2);

int kd =0;
int ga = 0;
for (kd =0; kd<rows2*cols2 ; kd++){
  printf("\n");
  fprintf(result3 , "\n");
  for(ga=0; ga <rows1*cols1  ; ga++){
    outer_product[kd][ga] = matrix2[kd]*matrix1[ga];
    printf(" %d ", outer_product[kd][ga]);
    fprintf(result3 , " %d " , outer_product[kd][ga]);
  } 

  }
  fclose(result3);
}
  

  }
fclose(f1);
fclose(f2);
fclose(f1row);
fclose(f2row);
fclose(f1col);
fclose(f2col);
main();
}

void load_array(){
  int rows;
  int cols;
  char buffer[1024];
  int matrix[100];
  printf("=====================================================================================\nIn order to load your file into the program first add it to the project.Then specify the name of the file including the extension which should be csv.You should make sure that the contents of the file are integers in the row seperated with comas.Furthermore in order for the program  to work as intended you should make sure that the number of integers inside the file is equal to (rows*coumns)\n=====================================================================================\n");
 
  printf("how many rows would you like your array to have\n=====================================================================================\n");
  scanf("%d" , &rows);
  printf("how many columns would you like your array to have\n=====================================================================================\n");
  scanf("%d" , &cols);
  printf("=====================================================================================\n");
  
  char c[100];
  char filename[100];
  char name[100];
  char rowname[100];
  char colname[100];
  printf("what is the name of your file\n");
  printf("=====================================================================================\n");
  scanf("%s" , &name[0]);
  printf ("=====================================================================================\n");
  FILE *last = fopen("lastnum.csv" , "r");
  FILE *loaded = fopen(name , "r");
  if (loaded == 0){
    printf("The file %s doesnt exist try again\n" , name);
    load_array();
    
  }
  else{

  fscanf(loaded, "%s", buffer);
  fscanf(last, "%s", c);
  
  num = atoi(c);

  snprintf(filename , sizeof(filename) , "array.%d.csv" , num);
  snprintf(rowname , sizeof(rowname) , "row.%d.csv" , num);
  snprintf(colname , sizeof(colname) , "col.%d.csv" , num);
  FILE *file = fopen(filename , "w");
  FILE *row = fopen(rowname , "w");
  FILE *col = fopen(colname , "w");

  fprintf(row, "%d" ,rows);
  fprintf(col ,"%d", cols);

  char* value;
  value = strtok(buffer , ",");
  int i=0;
  int n;

  
  while(value != NULL){
  
   
    matrix[i] = atoi(value);
    value = strtok(NULL , ",");

     i++;
    
}
n=i;

for (i = 0;  i<n; i++){
  fprintf(file , "%d,", matrix[i]);
}
  
  
    printf("Your array was saved successfuly inside the file %s" , filename);
    printf ("=====================================================================================\n");
    FILE *last2 = fopen("lastnum.csv" , "wt");
    int  num2 = num+1;
    fprintf(last2 , "%d" , num2);
    fclose(last2);
    fclose(loaded);
    fclose(file);
    fclose(row);
    fclose(col);
    main();
    
}
  



}
void gauss (){
  preview_arrays();
  printf("Which matrix would you like to perform the Gauss to?\n");
  int the_answer;
  scanf("%d" , &the_answer);
  char filename1[80];
  char filenamerow1[80];
  char filenamecol1[80];


  snprintf(filename1,sizeof(filename1) , "array.%d.csv" , the_answer);
  snprintf(filenamerow1 , sizeof(filenamerow1) , "row.%d.csv" , the_answer);
  snprintf(filenamecol1 , sizeof(filenamecol1) , "col.%d.csv" , the_answer);
 
  
  FILE *f = fopen(filename1 , "r");
  FILE *frow = fopen(filenamerow1 , "r");
  FILE *fcol = fopen(filenamecol1 , "r");

char srows[90];
char scols[90];
char buffer[80];
int rows;
int cols;
float matrix[100][100];
char* value;
fgets(srows , sizeof srows, frow);
  rows = atoi(srows);
fgets(scols , sizeof scols, fcol);
  cols = atoi(scols);

  fscanf(f , "%s" , buffer);


value = strtok(buffer , ",");
while(value != NULL){
  
   for(int z=1; z<=rows; z++){
      
       for(int a=1; a<=cols; a++){
          matrix[z][a] = atof(value);
          value = strtok(NULL , ",");
         
    
      }
   }
}
printf("\n");

if (cols ==rows+1){
if (rows == 2 && cols ==3){
printf("I will solve the system:\n");
printf("%fx1 + %fx2 = %f\n" , matrix[0][0] , matrix[0][1] , matrix[0][2]);
printf("%fx1 + %fx2 = %f\n" , matrix[1][0] , matrix[1][1] , matrix[1][2]);


}
else if (rows == 3 && cols ==4){
printf("I will solve the system:\n");
printf("%.0fx1 + %.0fx2 + %.0fx3 = %.0f\n" , matrix[1][1] , matrix[1][2] , matrix[1][3]  , matrix[1][4]);
printf("%.0fx1 + %.0fx2 +%.0fx3 = %.0f\n" , matrix[2][1] , matrix[2][2] , matrix[2][3] , matrix[2][4]);
printf("%.0fx1 + %.0fx2 +%.0fx3 = %.0f\n" , matrix[3][1] , matrix[3][2] , matrix[3][3] , matrix[3][4]);

}
int n = rows;
int i, k , j ;
float sum =0.0;

float r;
float x[100];
	

for(j=1; j<=n; j++) 
    {
        for(i=1; i<=n; i++)
        {
            if(i>j)
            {
                r=matrix[i][j]/matrix[j][j];
                for(k=1; k<=n+1; k++)
                {
                    matrix[i][k]=matrix[i][k]-r*matrix[j][k];
                }
            }
        }
    }
    x[n]=matrix[n][n+1]/matrix[n][n];
  
    for(i=n-1; i>=1; i--)
    {
        sum=0;
        for(j=i+1; j<=n; j++)
        {
            sum=sum+matrix[i][j]*x[j];
        }
        x[i]=(matrix[i][n+1]-sum)/matrix[i][i];
    }
    printf("\nThe solution is: \n");
    for(i=1; i<=n; i++)
    {
        printf("\nx%d=%f\t",i,x[i]); 
}
}
else{
  printf("This matrix does not correspond to a system solvable with the gauss elimination. This function can only be used with matrices with two rows and three columns or three rows and four columns");
  main();
}
fclose(f);
fclose(frow);
fclose(fcol);
}