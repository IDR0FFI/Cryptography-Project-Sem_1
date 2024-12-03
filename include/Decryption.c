// \033[1;34m<Text>\033[0m
// To give color to the text

char* Decryption(char* encryption, int inTerminal){
    print("\033[1;34mWelcome to the Secure Key Generator!\033[0m");
    int length;

    // Initialisation for terminal
    if (inTerminal){
        char encrypt[10000];
        print("\033[1;32mEnter Encrypted code :\033[0m\n");
        scanf("%s",encrypt);
        length=strlen(encrypt);

        encryption = encrypt;
    }

    // Initialisation for file
    else{
        length = strlen(encryption);
    }

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

    // Public Key
    if (value==2)
    {
        length/=7;
        char* password = (char*)malloc(length);

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
        
        return password;
    }

    // Private Key
    if (value==1)
    {   
        length/=10;
        char* password = (char*)malloc(length+1);
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
        
        return password;
    } 
}