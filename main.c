#include <stdio.h>

int main(){
    int m;
    //Menu 
    printf("Enter 1 for rotation encrytpion\n");
    printf("Enter 2 for rotation decryption\n");
    printf("Enter 3 for substitution encrytpion\n");
    printf("Enter 4 for substitution decrytpion\n");
    scanf("%d", &m);//stores users input as m
if(m<0 || m>5)// used to ensure that user imputs correct keys
        {
            printf("Enter an integer, 1-4:\n");
            scanf("%d", &m);
        }
    
else
{
    switch(m)//users choice of algorithm was stored as 'm' and this value is used in a switch case to call correct program
    {

        case 1:
        {
            //Encryption using alphabet rotation with known key
            int key;
            char ch;
            FILE *input;//initialises file pointer 
            
            char sentence[200]; //string to store the message in
             
            printf("Enter string: \n"); //prompts user to enter sentence
            getchar(); //this 'deletes' the last char entered, which was a space key. If this is not implemented, then the compiler uses an entrer character as the message input
            fgets(sentence, 200, stdin); //gets sentence from stdin and stores it as 'sentence'
            input = fopen("input.txt", "w"); //opens file for writing
            fputs(sentence, input); //stores 'sentence' in the file
    
            fclose(input);//closes file
            input = fopen("input.txt", "r");//opens the file for reading
            fscanf(input, "%c", &ch); //scans the file for the first char and stores it as ch
       
            printf("Enter key: \n");// prompts user to enter key
            scanf("%d", &key); //stores input as 'key'
                    
    	    printf("%c", sentence[0]+key);//prints the first char of the file and adds the key. This is done as the fgets fucntion was skipping sentence[1]. 
          
            while(feof(input) == 0)//while the file has not reached its null value
               {
                    fscanf(input, "%c", &ch);//scans file 'input' and stores it as ch
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
                printf("%c", ch); //prints new encrypt value
               }
    }
    
        
           break;
           case 2:
           //Decryption of rotation cipher with known key
           {
            int key;
            char ch;
            char ovrflw;
            FILE *input;//initialises file pointer 
            
            char sentence[200]; //string to store the message in
             
            printf("Enter encoded text: \n"); //prompts user to enter sentence
            getchar(); //this 'deletes' the last char entered, which was a space key. If this is not implemented, then the compiler uses an entrer character as the message input
            fgets(sentence, 200, stdin); //gets sentence from stdin and stores it as 'sentence'
            input = fopen("input.txt", "w"); //opens filefor writing
            fputs(sentence, input); //stores 'sentence' in the file
    
            fclose(input);//closes file
            input = fopen("input.txt", "r");//opens the file for reading
            fscanf(input, "%c", &ch); //scans the file for the first char and stores it as ch
       
            printf("Enter key: \n");// prompts user to enter key
            scanf("%d", &key); //stores input as 'key'
            
            ovrflw = sentence[0]-key;
            if(ovrflw < 'a')
             {
                        ovrflw = ovrflw + 26;//formula encrypts values that overflow past z, by using previous value calculated for the new 'ch' and minuses 26.
                    }
    	    printf("%c", ovrflw);//prints the first char of the file and adds the key. This is done as the fgets fucntion was skipping sentence[1].
    
         
           
               while(feof(input) == 0)//while the end of the file has not been reached
               
               {
                fscanf(input, "%c", &ch);//storing first character of input as ch
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
           //This algorithm reads text from input and stores it in a file for reading. It encrypts a message using a substituion cipher.
        {
        int n;//used for incrementation in for loop
        char subalpha[27];//this string will store the substitution key
        FILE *key; //file pointer for the file with the key in it
        printf("Enter substitution alphabet string you would like to useto encrypt the messsage, in capitals, with no spaces or characters other than letters: ");//prompts user to enter alphabet substitution
        getchar();//is used as the enter character is used to select task 3 is used as the input instead of the actual input. This means that the compiler will 
        //not read the input and skip straight to the Ënter text to encrypt" section below. The getchar() function simply 'eats' the enter character and allows for input
        fgets(subalpha, 27, stdin); //gets input from standard input and stores in string subalpha[27].
        key = fopen("key.txt", "w");//opening file for writing
        fputs(subalpha, key);//puts the string subalpha in the file 'key'
        fclose(key); //closes file as it has to be reopened differently to do reading
         
        key = fopen("key.txt", "r"); //opening key file for reading
         
            
        char ch;
        int fgetc(FILE *key); //initialising fgetc function with file pointer
        char alpha[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};//Plain alphabet string used to help encoding/decoding process
        for(n = 0; n<26; n++)//Indexes once for each letter
            {
                if(feof(key) == 0)//If the todecrypt5 alphabet file isn't at the end of file, the IF loop commences
                {
                    alpha[n] = fgetc(key);/*The first letter of the alpha string becomes the first letter of the string entered in the file, 
                                                  and is repeated until the 26 letter of the alpha string becomes the 26th letter of the todecrypt5ted string*/    
                }
            }
        char subencrypt[200];//string of 200 characters is used to store the message
        FILE *todecrypt5; //opening file with text to encrypt
        printf("Enter text to encrypt: ");
        getchar();//is used as the enter character used to select task 3 is used as the input instead of the actual input. This means that the compiler will 
        //not read the input and skip it. The getchar() function simply 'eats' the enter character and allows for input
        fgets(subencrypt, 200, stdin);//Gets inputted message and stores it in string subencrypt[200]
        todecrypt5 = fopen("todecrypt5.txt", "w"); //opens file for reading
        fputs(subencrypt, todecrypt5);//puts subencrypt[200] into file 'todecrypt5'
        fclose(todecrypt5);//closes file so that it can be reopened for reading
        todecrypt5 = fopen("todecrypt5.txt", "r");//file opened for reading
        int fgetc(FILE *todecrypt); //initialising fgetc function with file pointer
        while(feof(todecrypt5) == 0) // DO NOT USE FP != NULL, WILL CRASH WHILE LOOP
            {
                ch = fgetc(todecrypt5);/* the char variable is assigned the ascii value of a letter from the code to be decrypted. The fgetc function remembers the 
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
            //this algorithm decrypts a message with a given alphabet substitution string  
            int n;//used for incrementation in for loop
            char keyalpha[27];//stores substituion alphabet string
            FILE *fp; //file pointer for the file with the key in it
            printf("Enter alphabet string used to encrypt the message: ");//prompts user to enter message
            getchar();//is used as the enter character is used to select task 4 is used as the input instead of the actual input. This means that the compiler will 
            //not read the input and skip straight to the "enter text to encrypt" section below. The getchar() function simply 'eats' the enter character and allows for input
            fgets(keyalpha, 27, stdin); //gets input from standard input and stores in string keyalpha[27].
            fp = fopen("keytsk4.txt", "w");//opening file for writing
            fputs(keyalpha, fp);//puts the string subalpha in the file 'keyalpha'
            fclose(fp); //closes file as it has to be reopened differently to do reading
             
            fp = fopen("keytsk4.txt", "r"); //opening key file for reading
             
                
            char ch;
            int fgetc(FILE *fp); //initialising fgetc function with file pointer
            char alpha[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};//Plain alphabet string used to help encoding/decoding process
            for(n = 0; n<26; n++)//Indexes once for each letter/ The for loop is used to allocated the he first letter of the string key to A, the second letter to B and so on.
                {
                    if(feof(fp) == 0)//If the todecrypt5 alphabet file isn't at the end of file, the IF loop commences
                    {
                        alpha[n] = fgetc(fp);/*The first letter of the alpha string becomes the first letter of the string entered in the file, 
                                                      and is repeated until the 26 letter of the alpha string becomes the 26th letter of the todecrypt5ted string. The fgetc 
                                                      function remembers the position from the last time it was
                                                      called and reads from there*/    
                    }
                }
            char subdecrypt[200];//string of 200 characters is used to store the message
            FILE *todecrypttsk4; //opening file with text to encrypt    
            printf("Enter text to decrypt: ");
            getchar();//is used as the enter character used to select task 3 is used as the input instead of the actual input. This means that the compiler will 
            //not read the input and skip it. The getchar() function simply 'eats' the enter character and allows for input
            fgets(subdecrypt, 200, stdin);//Gets inputted message and stores it in string subencrypt[200]
            todecrypttsk4 = fopen("todecrypttsk4.txt", "w"); //opens file for reading
            fputs(subdecrypt, todecrypttsk4);//puts subdecrypt[200] into file 'todecrypt5'
            fclose(todecrypttsk4);//closes file so that it can be reopened for reading
            todecrypttsk4 = fopen("todecrypttsk4.txt", "r");//file opened for reading
            int fgetc(FILE *todecrypttsk4); //initialising fgetc function with file pointer
            
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
    
    
  return 0;
}
