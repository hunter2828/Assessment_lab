#include <stdio.h>

int main()
{ int m=0;
printf("Enter 1 for rotation encrytpion\n");
    printf("Enter 2 for rotation decryption\n");
    printf("Enter 3 for substitution encrytpion\n");
    scanf("%d", &m);
    if(m<1 || m>6)
    {
        printf("Enter an integer between 1 and 6");
        scanf("%d", &m);
    }

    if(m)
switch(m)
{

case 1:
{
    int key=1;
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
   
   default: printf("Something went very wrong");

}
  return 0;
}

