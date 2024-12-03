// \033[1;34m<Text>\033[0m
// To give color to the text

char* Encryption(char* password, int inTerminal){
  print("\033[1;34mWelcome to the Secure Key Generator!\033[0m");
  int length;
  
  // Initialisation for terminal   
  if (inTerminal){
    char word[20];
    label1:
      print("\033[1;32mEnter password (8-12 characters):\033[0m\n");
      scanf("%s", word);
      load(3);
      length=strlen(word);
      if (length>12||length<8)
      {
        printf("\r\033[1;31mYour password must be between 8 and 12 characters.\033[0m\n");
        goto label1;
      }

    password = word;
  }

  // Initialisation for file
  else {
    length = strlen(password);
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

  // Public Key
  if (value==2)
  {
    printf("Start");
    int b=1;
    for (int i = 0; i <length; i++)
    {
      b*=-1;
      password[i]+=i*b+1; 
    }

    swapoperation3(password,length);
    swapoperation2(password,length);
    swapoperation1(password,length);
    
    char* encryption = (char*)malloc(7*length);
    for(int i = 0; i < length; i++)
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
    
    return encryption;
  }

  // Private Key
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

    char* encryption = (char*)malloc(10*length);
    for (int i = 0; i < length; i++)
    {
      for (int j = 1; j <10;j++)
      {
        encryption[10*i+j-1]=randomcharacter();   
      }  
      encryption[10*i+9]=password[i];
    }

    print("\n\r\033[1;33mProcessing your request...\033[0m");
    progress(5);
    print("\n\033[1;34mPrivate Key: \033[0m");
    printf("%s\n", password);
    
    return encryption;
  }
}