#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){

       char s[1002], word[100];
       int i, j, length, is_word_started;

       printf("Write your passage : ");
       fgets(s, sizeof(s), stdin);

       length = strlen(s);
       is_word_started = 0;
       j =0 ;

       printf("Result is :\n");

       for(i=0; i<length; i++){
              if(islower(s[i])){
              if( is_word_started == 0){
                     is_word_started = 1;
                     word[j] = toupper(s[i]);
                     j++;
              }
              else{
                     word[j] = s[i];
                     j++;
              }
              }
              else if(isupper(s[i])){
                     if( is_word_started == 0){
                     is_word_started = 1;
                     j++;
              }
              else{
                     word[j] = s[i];
                     j++;
              }                     
              }
              else{
                     if(is_word_started == 1){
                            word[j] = s[i];
                            word[j] = '\0';
                            printf("%s\n", word);
                            j=0;
                            is_word_started=0;
                     }
              }
       }


       return 0;
}