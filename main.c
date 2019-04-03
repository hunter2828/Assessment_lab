#include <stdio.h>

int main()
{
int key, i;// Declared as integers as the key must be an integer and i will be incremented in a loop.
char message[100], ch; //message[100] array allows a message of 100 characters
printf("Enter a message to encrypt: \n");// User enters a message which is to be encrypted, and it is stored as a type char, called message
gets(message);// text stored as variable type char, named message

printf("Enter key: \n");
scanf("%d", &key);

    for (i = 0; message[i] != 0; ++i)//for loop used because it reduces the amount of code that needs to be written, and allows the whole string to be tested for in one loop
    {
        ch = message[i];
        
        if(ch>= 'a' && ch<= 'z')//if loop to encrypt lower case letters. The loop adds the key to the value, and if the value exceeds the value of lowercase 'z', it initiates another if loop.
        {
            ch = ch + key;//a letters ascii code plus the key is assigned to the same variable butwill have a different ascii code
            if(ch > 'z')//used to encrypt an values that 'overflow' past the ascii value of 'z'
            {
                ch = ch - 26;//formula encrypts values that overflow past z, by using previous value calculated for the new 'ch' and minuses 26.
            }
            
            message[i] = ch;
        }
        
        else if(ch>= 'A' && ch<= 'Z')//if loop to encrypt lower case letters. The loop adds the key to the value, and if the value exceeds the value of uppercase 'Z' it initiates another loop
        {
            ch = ch + key;//a letters ascii code plus the key is assigned to the same variable butwill have a different ascii code
            if(ch > 'Z')//used to encrypt an values that 'overflow' past the ascii value of 'Z'
            {
                ch = ch - 26;
            }
            message[i] = ch;
        }
        
    }
    printf("Encrypted Message: %s\n", message);


  return 0;
}

