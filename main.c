#include <stdio.h>

int main()
{ int m=0;
printf("Enter 1 for rotation encrytpion\n");
    printf("Enter 2 for rotation decryption\n");
    printf("Enter 3 for substitution encrytpion\n");
    scanf("%d", &m);
    if(m<1 || m>6)
    {
        printf("Enter an integer between 1 and 6\n");
        scanf("%d", &m);
    }

    
switch(1)
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
    FILE *inputsk3;
    inputsk3 = fopen("inputsk3.txt", "r");
    char ch;
    int fgetc(FILE *inputtsk3);
    //char origalpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    for(n = 0; n<26; n++)
    {
        if(feof(inputsk3) == 0)
  {
      alpha[n] = fgetc(inputsk3);
      
      
  }
}
   
    FILE *tsk3orig; //opening file with text to encrypt
    tsk3orig = fopen("tsk3orig.txt", "r");
    int fgetc(FILE *tsk3orig);
    while(feof(tsk3orig) == 0) // DO NOT USE FP != NULL, WILL CRASH WHILE LOOP
          {
              ch = fgetc(tsk3orig);
        //fscanf(tsk3orig, "%c", &ch);
        
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

    return 0;
}

 
   }
   
   default: printf("Something went very wrong");

}
  return 0;
}

