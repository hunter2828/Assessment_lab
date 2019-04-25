#include <stdio.h>

int main()
{ int m;
printf("Enter 1 for rotation encrytpion\n");
    printf("Enter 2 for rotation decryption\n");
    printf("Enter 3 for substitution encrytpion\n");
    scanf("%d", &m);
    
if(m>0 && m<6)
{
    switch(m)
{

    case 1:
    {
        int key;
        char ch;
    FILE *input;//initialises file pointer 
        
         char sentence[200]; //string to store the message in
         
        printf("Enter string: \n"); //prompts user to enter sentence
        getchar();
        fgets(sentence, 200, stdin); //gets sentence from stdin and stores it as 'sentence'
        input = fopen("input.txt", "w"); //opens file for writing
        fputs(sentence, input); //stores 'sentence' in the file

        fclose(input);//closes file
        input = fopen("input.txt", "r");//opens the file for reading
        fscanf(input, "%c", &ch); //scans the file for the first char and stores it as ch
   
        printf("Enter key: \n");// prompts user to enter key
        scanf("%d", &key); //stores input as 'key'
                
	    printf("%c", sentence[0]+key);//prints the first char of the file and adds the key. This is done as the fgets fucntion was skipping sentence[1].

   
        
      
           while(feof(input) == 0)
           {
                fscanf(input, "%c", &ch);
                if(ch>= 'a' && ch<= 'z')//if loop to encrypt lower case letters. The loop adds the key to the value, and if the value exceeds the value of lowercase 'z', it initiates another if loop.
                {
                    ch = ch + key;//a letters ascii code plus the key is assigned to the same variable butwill have a different ascii code
                    
                    if(ch > 'z')//used to encrypt an values that 'overflow' past the ascii value of 'z'
                    {
                        ch = ch - 26;//formula encrypts values that overflow past z, by using previous value calculated for the new 'ch' and minuses 26.
                    }
                    
                    
                }
                
                else if(ch>= 'A' && ch<= 'Z')//if loop to encrypt lower case letters. The loop adds the key to the value, and if the value exceeds the value of uppercase 'Z' it initiates another loop
                {
                    ch = ch + key;//a letters ascii code plus the key is assigned to the same variable butwill have a different ascii code
                    
                    if(ch > 'Z')//used to encrypt an values that 'overflow' past the ascii value of 'Z'
                    {
                        ch = ch - 26;
                    }
                    
                }
            printf("%c", ch);
           }
}

    
       break;
       case 2:
       {
        int key;
        char ch;
    FILE *input;//initialises file pointer 
        
         char sentence[200]; //string to store the message in
         
        printf("Enter encoded text: \n"); //prompts user to enter sentence
        getchar();
        fgets(sentence, 200, stdin); //gets sentence from stdin and stores it as 'sentence'
        input = fopen("input.txt", "w"); //opens filefor writing
        fputs(sentence, input); //stores 'sentence' in the file

        fclose(input);//closes file
        input = fopen("input.txt", "r");//opens the file for reading
        fscanf(input, "%c", &ch); //scans the file for the first char and stores it as ch
   
        printf("Enter key: \n");// prompts user to enter key
        scanf("%d", &key); //stores input as 'key'
                
	    printf("%c", sentence[0]-key);//prints the first char of the file and adds the key. This is done as the fgets fucntion was skipping sentence[1].

     
       
           while(feof(input) == 0)
           //while(i < 1)
           {
            fscanf(input, "%c", &ch);
            if(ch>= 'a' && ch<= 'z')//if loop to encrypt lower case letters. The loop adds the key to the value, and if the value exceeds the value of lowercase 'z', it initiates another if loop.
            {
                ch = ch - key;//a letters ascii code plus the key is assigned to the same variable butwill have a different ascii code
                if(ch < 'a')//used to encrypt an values that 'overflow' past the ascii value of 'z'
                {
                    ch = ch + 26;//formula encrypts values that overflow past z, by using previous value calculated for the new 'ch' and minuses 26.
                }
                
                
            }
            
            else if(ch>= 'A' && ch<= 'Z')//if loop to encrypt lower case letters. The loop adds the key to the value, and if the value exceeds the value of uppercase 'Z' it initiates another loop
            {
                ch = ch - key;//a letters ascii code plus the key is assigned to the same variable butwill have a different ascii code
                if(ch < 'A')//used to encrypt an values that 'overflow' past the ascii value of 'Z'
                {
                    ch = ch + 26;
                }
                
            }
            printf("%c", ch);
        }
    
    }
       break;
       case 3:       
    {
        int n;
        FILE *inputtsk3;
        inputtsk3 = fopen("inputtsk3.txt", "r"); //Opening file with new alphabet string for reading
        char ch;
        int fgetc(FILE *inputtsk3);
        char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};//Plain alphabet string used to help encoding/decoding process
        for(n = 0; n<26; n++)//Indexes once for each letter
        {
            if(feof(inputtsk3) == 0)// If the input alphabet file isn't at the end of file, the IF loop commences
            {
                alpha[n] = fgetc(inputtsk3);/*The first letter of the alpha string becomes the first letter of the string entered in the file, 
                                              and is repeated until the 26 letter of the alpha string becomes the 26th letter of the inputted string*/    
            }
        }
       
        FILE *tsk3orig; //opening file with text to encrypt
        tsk3orig = fopen("tsk3orig.txt", "r");
        int fgetc(FILE *tsk3orig);
        while(feof(tsk3orig) == 0) // DO NOT USE FP != NULL, WILL CRASH WHILE LOOP
            {
                  ch = fgetc(tsk3orig);/* the char variable is assigned the ascii value of a letter from the code to be decrypted. The fgetc function remembers the 
                                          position of the previous byte that it allocated to ch and calls the one after everytime it is called.*/ 
            
            /* The following IF statements encrypt the character that has been allocated to 'ch'. If 'ch' == A, then it is assigned the new value of alpha[0] and so on. 
            */
                if(ch == 'A')
                {
                    ch = alpha[0];
                    
                }
        
        
                else if(ch == 'B')
                {
                    ch = alpha[1];
                    
                }
                
                
                else if(ch == 'C')
                {
                    ch = alpha[2];
                    
                }
                
                
                else if(ch == 'D')
                {
                    ch = alpha[3];
                    
                }
                
                
                else if(ch == 'E')
                {
                    ch = alpha[4];
                    
                }
                
                
                else if(ch == 'F')
                {
                    ch = alpha[5];
                    
                }
                
                
                else if(ch == 'G')
                {
                    ch = alpha[6];
                    
                }
                
                
                else if(ch == 'H')
                {
                    ch = alpha[7];
                    
                }
                
                
                else if(ch == 'I')
                {
                    ch = alpha[8];
                    
                }
                
                
                else if(ch == 'J')
                {
                    ch = alpha[9];
                    
                }
                
                
                else if(ch == 'K')
                {
                    ch = alpha[10];
                    
                }
                
                
                else if(ch == 'L')
                {
                    ch = alpha[11];
                    
                }
                
                
                else if(ch == 'M')
                {
                    ch = alpha[12];
                    
                }
                
                
                else if(ch == 'N')
                {
                    ch = alpha[13];
                    
                }
                
                
                else if(ch == 'O')
                {
                    ch = alpha[14];
                    
                }
                
                
                else if(ch == 'P')
                {
                    ch = alpha[15];
                    
                }
                
                
                else if(ch == 'Q')
                {
                    ch = alpha[16];
                    
                }
                
                
                else if(ch == 'R')
                {
                    ch = alpha[17];
                    
                }
                
                
                else if(ch =='S')
                {
                    ch = alpha[18];
                    
                }
                
                
                else if(ch == 'T')
                {
                    ch = alpha[19];
                    
                }
                
                
                else if(ch == 'U')
                {
                    ch = alpha[20];
                    
                }
                
                
                else if(ch == 'V')
                {
                    ch = alpha[21];
                    
                }
                
                
                else if(ch == 'W')
                {
                    ch = alpha[22];
                    
                }
                
                
                else if(ch == 'X')
                {
                    ch = alpha[23];
                    
                }
                
                
                else if(ch == 'Y')
                {
                    ch = alpha[24];
                    
                }
                
                
                else if(ch == 'Z')
                {
                    ch = alpha[25];
                    
                }
            printf("%c", ch);
        }
}

       break;
       
       case 4:
      {
          int n;
        FILE *keytsk4;
        keytsk4 = fopen("keytsk4.txt", "r"); //Opening file with new alphabet string for reading
        char ch;
        int fgetc(FILE *keytsk4);
        char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};//Plain alphabet string used to help encoding/decoding process
        for(n = 0; n<26; n++)//Indexes once for each letter
        {
            if(feof(keytsk4) == 0)// If the input alphabet file isn't at the end of file, the IF loop commences
            {
                alpha[n] = fgetc(keytsk4);/*The first letter of the alpha string becomes the first letter of the string entered in the file, 
                                              and is repeated until the 26 letter of the alpha string becomes the 26th letter of the inputted string*/    
            }
        }
       
        FILE *todecrypttsk4; //opening file with text to encrypt
        todecrypttsk4 = fopen("todecrypttsk4.txt", "r");
        int fgetc(FILE *todecrypttsk4);
        while(feof(todecrypttsk4) == 0) // DO NOT USE FP != NULL, WILL CRASH WHILE LOOP
            {
                  ch = fgetc(todecrypttsk4);/* the char variable is assigned the ascii value of a letter from the code to be decrypted. The fgetc function remembers the 
                                          position of the previous byte that it allocated to ch and calls the one after everytime it is called.*/ 
            
            /* The following IF statements encrypt the character that has been allocated to 'ch'. If 'ch' == A, then it is assigned the new value of alpha[0] and so on. 
            */
                if(ch == alpha[0])
                {
                    ch = 'A';
                    
                }
        
        
                else if(ch == alpha[1])
                {
                    ch = 'B';
                    
                }
                
                else if(ch == alpha[2])
                {
                    ch = 'C';
                    
                }
                
                else if(ch == alpha[3])
                {
                    ch = 'D';
                    
                }
                
                else if(ch == alpha[4])
                {
                    ch = 'E';
                    
                }
                
                else if(ch == alpha[5])
                {
                    ch = 'F';
                    
                }
                
                else if(ch == alpha[6])
                {
                    ch = 'G';
                    
                }
                
                else if(ch == alpha[7])
                {
                    ch = 'H';
                    
                }
                
                else if(ch == alpha[8])
                {
                    ch = 'I';
                    
                }
                
                else if(ch == alpha[9])
                {
                    ch = 'J';
                    
                }
                
                else if(ch == alpha[10])
                {
                    ch = 'K';
                    
                }
                
                else if(ch == alpha[11])
                {
                    ch = 'L';
                    
                }
                
                else if(ch == alpha[12])
                {
                    ch = 'M';
                    
                }
                
                else if(ch == alpha[13])
                {
                    ch = 'N';
                    
                }
                
                else if(ch == alpha[14])
                {
                    ch = 'O';
                    
                }
                
                else if(ch == alpha[15])
                {
                    ch = 'P';
                    
                }
                
                else if(ch == alpha[16])
                {
                    ch = 'Q';
                    
                }
                
                else if(ch == alpha[17])
                {
                    ch = 'R';
                    
                }
                
                else if(ch == alpha[18])
                {
                    ch = 'S';
                    
                }
                
                else if(ch == alpha[19])
                {
                    ch = 'T';
                    
                }
                
                else if(ch == alpha[20])
                {
                    ch = 'U';
                    
                }
                
                else if(ch == alpha[21])
                {
                    ch = 'V';
                    
                }
                
                else if(ch == alpha[22])
                {
                    ch = 'W';
                    
                }
                
                else if(ch == alpha[23])
                {
                    ch = 'X';
                    
                }
                
                else if(ch == alpha[24])
                {
                    ch = 'Y';
                    
                }
                
                else if(ch == alpha[25])
                {
                    ch = 'Z';
                    
                }
                
                
            printf("%c", ch);
        
      }
       default: 
       {
           printf("Something went very wrong");
       }
   

}
}
} 

else 
    {
        printf("Enter an integer between 1 and 6\n");
        scanf("%d", &m);
    }

  return 0;
}


