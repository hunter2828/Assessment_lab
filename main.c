#include <stdio.h>

int main()
{ int m;
printf("Enter 1 for rotation encrytpion\n");
    printf("Enter 2 for rotation decryption\n");
    printf("Enter 3 for substitution encrytpion\n");
    scanf("%d", &m);
    if(m<1 || m>6)
    {
        printf("Enter an integer between 1 and 6\n");
        scanf("%d", &m);
    }

    
switch(m)
{

case 1:
{
    int key=2;
    char ch;
    /*printf("Enter key: \n");*/
    scanf("%d", &key);
    //Write text to a file, then read it from a file, lecture 9/04 around half hour into lecture recording.
    FILE *input;
    input = fopen("input.txt", "r");


   
       while(feof(input) == 0)
       //while(i < 1)
       {
        //i++;
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
    int key=1;
    char ch;
    printf("Enter key: \n");
    scanf("%d", &key);
    //Write text to a file, then read it from a file, lecture 9/04 around half hour into lecture recording.
    FILE *input;
    input = fopen("input.txt", "r");


   
       while(feof(input) == 0)
       //while(i < 1)
       {
        //i++;
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
   break;
   default: 
   {
       printf("Something went very wrong");
   }
   

}
}
  return 0;
}

