#include "include/header.h"

// #include "vrg.h" header file is for command line interface
// it abstracts the integration workflow

char* readData(char* filename){
    int size = 100, stored_byte = 0;
    // dynamically allocate memory as the size of
    // text file is unknown
    char* text = (char*)malloc(sizeof(char)*size);

    FILE* input = fopen(filename, "r");

    char data = fgetc(input);
    while(data != EOF){
        text[stored_byte] = data;
        data = fgetc(input);
        stored_byte++;

        // reallocation part
        if (stored_byte == size){
            size *= 2;  
            text = realloc(text, size);
        }
    }

    text[stored_byte] = '\0';

    fclose(input);

    return text;
}

void saveData(char* filename, char* text){
    FILE *output = fopen(filename, "w");

    fprintf(output, text);

    fclose(output);
}

// command line interface argument taken from argc and argv
int main(int argc, char *argv[]) {
    char* key=NULL;
    char* inputFile = NULL;
    char* outputFile = "output.txt";
    char* task = NULL;
    char *inputText = NULL;

    // command line interface argument capture.
    // Start
    vrgcli("Encryption and Decryption v1.0")
    {
        vrgarg("-h, --help\tShows the help page."){
            vrgusage();
        }

        vrgarg("-i, --input mandatory\tFile to encrypt/decrypt"){
            inputFile = vrgarg;
        }

        vrgarg("-o, --output\tOutput of the encryption/decryption"){
            outputFile = vrg_argv[vrgargn];
        }

        // If want to --->
        vrgarg("-k\tInputted text to encrypt"){
            inputText = "Y";
        }

        vrgarg("-t, --task\t0 -> Encrypting\n\t\t\t1 -> Decrypting"){
            task = vrg_argv[vrgargn];
        }

        if (argc == 1){
            vrgusage("\033[1;31mERROR: No input file provided '%s'\n\n\033[0m", vrgarg);
        }
    }
    // End

    if (inputFile == NULL && inputText == NULL){
        printf("\033[1;31mERROR: No input file provided \n\n\033[0m");
    }

    // Working from file 
    if (inputFile){
        if (*task == '0'){
            char* text = readData(inputFile); 
            char* encrypted = Encryption(text, 0);
            saveData(outputFile, encrypted);

            // Deallocating dynamic memory 
            free(text);
            free(encrypted);
        }

        else if (*task == '1'){
            char* text = readData(inputFile); 
            char* password = Decryption(text, 0);
            saveData(outputFile, password);

            // Deallocating dynamic memory
            free(text);
            free(password);
        }
    }

    // Working directly from terminal
    if (inputText){
        if (*task == '0'){
            char* encrypted = Encryption(inputText, 1);
            printf("\n\033[1;34mEncryption : \033[0m\n");
            printf("%s\n\n", encrypted);

            // Deallocating dynamic memory
            free(encrypted);
        }

        else if (*task == '1'){
            char* password = Decryption(inputText, 1);
            printf("\n\033[1;34mEncryption : \033[0m\n");
            printf("%s\n\n", password);

            // Deallocating dynamic memory
            free(password);
        }
    }

    return 0;
}