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
    char encryption[10000];
    print("Enter Encrypte code :\n");
    scanf(" %s",encryption);
    int length=strlen(encryption);
    int value;
     input:
    print("\033[1;36m1. Generate Using Private Key\n2. Generate Using Public Key\n\033[0m");
    print("\033[1;33mEnter Method No. :\033[0m");
    scanf("%d",&value);
    if (value>2&&value<1)
    {
       print("\033[1;31mInvalid input! \033[0m\n");
        goto input;
    }
    if (value==2)
    {
        length/=7;
        char password[length];

    for (int i = 0; i < length; i++)
    {
      password[i]=encryption[7*i+6];

    }
    swapoperation1(password,length);
    swapoperation2(password,length);
    swapoperation3(password,length);
    int b=1;
    for (int i = 0; i <length; i++)
    {
           b*=-1;
        password[i]-=i*b+1;    
    }
    print("\n\033[1;34mPassword:\n\033[0m");
    printf("\033[1;32m%s\n\033[0m \n",password);
    }
    if (value==1)
    {    length/=10;
        char password[length+1];
        char private[length];
        printf("\n\033[1;34mEnter Private Key: \033[0m\n  ");
        scanf("%s",private);
    for (int i = 0; i < length; i++)
    {
      password[i]=encryption[10*i+9];
    }
    swapoperation1(password,length);
    swapoperation2(password,length);
    swapoperation3(password,length);
    swapoperation1(password,length);
    swapoperation2(password,length);
    swapoperation3(password,length);
    int b=-1;
    for (int i = 0; i <length; i++)
    {
           b*=-1;
        password[i]-=i*b+1;    
    }
    progress(6);
    print("\n\033[1;34mPassword:\n\033[0m");
    printf("\033[1;32m%s\n\033[0m \n",password);
    } 
    return 0;
}