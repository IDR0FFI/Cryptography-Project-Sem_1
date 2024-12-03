#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <windows.h>

// Encryption and Decryption methods
// Start
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
    }
    else
    {
         goto start;
    }

}
// End

// Typing animation
void print(const char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        printf("%c", text[i]);
        fflush(stdout);
        Sleep(50);
    }
    printf("\n");
}

// Loading animation 
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

// Progress bar animation 
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
            } 
            else {
                printf("%s", empty);
            }
        }
        printf("%s %3d%%", border, (i * 100) / width); 
        fflush(stdout);
        Sleep((Sec * 1000) / width); 
    }
     printf("\n");
}