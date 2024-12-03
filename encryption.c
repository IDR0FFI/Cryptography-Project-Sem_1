#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <windows.h>

void swap(char *s1,char *s2){
    char tem=*s2;
    *s2=*s1;
    *s1=tem;
}

void swapoperation1(char password[],int length){
    for (int  i = 0; i < length/2; i++)
    {
       swap(&password[i],&password[i+length/2]);
    }
    
}

void swapoperation2(char password[],int length){
    for (int  i = 0; i < length/2; i++)
    {
       swap(&password[i],&password[length-1-i]);
    }
    
}

void swapoperation3(char password[],int length){
    for (int  i = 0; i < (length/2)-1; i++)
    {
       swap(&password[2*i],&password[2*i+1]);
    }  
}

char randomcharacter(){
    char x;
    start:
    x=rand()%128;
    if ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z'))
    {
       return x;
    }else
    {
        goto start;
    }    
}

void print(const char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        printf("%c", text[i]);
        fflush(stdout);
        Sleep(50);
    }
    printf("\n");
}

void load(int Sec) {
    const char spinner[] = "|/-\\";
    time_t startTime = time(NULL);
    int i = 0;
    while (time(NULL) - startTime < Sec) {
        printf("\r%c Checking Password..", spinner[i++ % 4]);
        fflush(stdout);
        Sleep(20);
    }
    printf("\rchecked!  \n");
}

void progress(int Sec) {
    const int width = 30; 
    const char *border = "|"; 
    const char *fill = "#"; 
    const char *empty = " "; 

    printf("\nLoading: \n");
    for (int i = 0; i <= width; i++) {
        printf("\r%s", border); 
        for (int j = 0; j < width; j++) {
            if (j < i) {
                printf("\033[1;32m%s\033[0m", fill);
            } else {
                printf("%s", empty);
            }
        }
        printf("%s %3d%%", border, (i * 100) / width); 
        fflush(stdout);
        Sleep((Sec * 1000) / width); 
    }
     printf("\n");
}

int main (){
   print("\033[1;34mWelcome to the Secure Key Generator!\033[0m");
    char password[20];
      label1:
    print("\033[1;32mEnter password (8-12 characters):\033[0m\n");
    scanf("%s",password);
    load(3);
    int length=strlen(password);
    if (length>12||length<8)
    {
        printf("\r\033[1;31mYour password must be between 8 and 12 characters.\033[0m\n");
        goto label1;
    }
    int value;
     input:
    print("\033[1;36m1. Generate Private Key\n2. Generate Public Key\033[0m\n");
    scanf("%d",&value);
    if (value>2||value<1)
    {
        print("\033[1;31mInvalid input! \033[0m\n");
        goto input;
    }
    if (value==2)
    {
    int b=1;
    for (int i = 0; i <length; i++)
    {
           b*=-1;
        password[i]+=i*b+1; 
    }
    swapoperation3(password,length);
    swapoperation2(password,length);
    swapoperation1(password,length);
    
    char encryption[7*length];
    for (int i = 0; i < length; i++)
    {
      for (int j = 1; j <7; j++)
      {
      
        encryption[7*i+j-1]=randomcharacter();
        
      }
      encryption[7*i+6]=password[i];
    }
    print("\n\033[1;33mProcessing your request...\033[0m");
    progress(5);
    print("\n\033[1;34mPublic Key: \033[0m");
    printf("%s\n", password);
    print("\n\033[1;34mEncryption : \033[0m");
    printf("%s\n\n", encryption);
    }
    if (value==1)
    {
    int b=-1;
    for (int i = 0; i <length; i++)
    {
          b*=-1;
        password[i]+=i*b+1;   
    }
    swapoperation3(password,length);
    swapoperation2(password,length);
    swapoperation1(password,length);
    swapoperation3(password,length);
    swapoperation2(password,length);
    swapoperation1(password,length);
    char encryption[10*length];
    for (int i = 0; i < length; i++)
    {
      for (int j = 1; j <10;j++){
        encryption[10*i+j-1]=randomcharacter();   
      }  
      encryption[10*i+9]=password[i];
    }
    print("\n\r\033[1;33mProcessing your request...\033[0m");
    progress(5);
    print("\n\033[1;34mPrivate Key: \033[0m");
    printf("%s\n", password);
    print("\n\033[1;34mEncryption : \033[0m");
    printf("%s\n\n", encryption);
    }
    return 0;
}