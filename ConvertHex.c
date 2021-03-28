#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

void inputOutput(void);
int convertCharToHex(char *hexdecnum);
void toUpperCase(char *hexdecnum);

// Constants
#define INVALID_INPUT -1
#define MAX_INPUT 23
#define MAX_OUTPUT 31

int main()
{
    inputOutput();
    /* char str[] ="- This, a sample string.";
    char * pch;
    printf ("Splitting string \"%s\" into tokens:\n",str);
    pch = strtok (str," ");
    while (pch != NULL)
    {
        printf ("%s\n",pch);
        pch = strtok (NULL, " ");
    } */
    return 0;
}

void inputOutput()
{
    //max number of characters plus newline \n
    char hexdecnum[MAX_INPUT+1] = "\0";
    //final string is max 32: 3*8 + 7 commas + newline
    char stringOfDecimals[MAX_OUTPUT+1] = "\0";
    char delim[] = " ";
    char comma[] = ",";
    int result = 0;
    int len;
    char continueOrBreak[1];
    char *inputPtr = NULL;
    char *token;
    printf("\n Please enter hexadecimal values: ");
    
    while((inputPtr = fgets(hexdecnum, MAX_INPUT, stdin))!= NULL){
            if(*inputPtr == '\n')
                    break;
            token = strtok(hexdecnum, delim);
            while(token != NULL)
            {
                result = convertCharToHex(token);
                if (result != INVALID_INPUT)
                {
                //it's only going to be 3 digits + \0
                char decimalNumber[4]; 
                sprintf(decimalNumber,"%ld", result);
                len = MAX_OUTPUT - strlen(stringOfDecimals);
                strncat(stringOfDecimals, decimalNumber, len);
                strncat(stringOfDecimals, comma, 1); 
                }
                else
                {
                    printf("\n Invalid hexadecimal");
                    stringOfDecimals[0] = '\0';
                    break;
                }
                token = strtok(NULL, delim);
            }
    }
    
    //toUpperCase(hexdecnum);         
    if(stringOfDecimals[0]!='\0')
    {
        printf("\n Decimal values of entered hexadecimal number = %s", stringOfDecimals);
    }  
    printf("\n Press c to enter another value or any key to quit ");
    fgets(continueOrBreak, 1, stdin);
    if(continueOrBreak[0] == 'c')
    {
        inputOutput();
    }
    else
    {
        return;
    }
}

int convertCharToHex(char *hexdecnum)
{
    int decnum = 0, rem, i = 0, len = strlen(hexdecnum)-1;
    if(hexdecnum[len] == '\n')
    {
       len--; 
    }
    i = 0;
    while (len >= 0)
    {
        rem = hexdecnum[len];
        if (rem >= 48 && rem <= 57)
            rem = rem - 48;
        else if (rem >= 65 && rem <= 90)
            rem = rem - 55;
        else
        {
            return INVALID_INPUT;
        }
        decnum = decnum + (rem * pow(16, i));
        len--;
        i++;
    }
    return decnum;
}

void toUpperCase(char * temp) {
  char * name;
  name = strtok(temp,":");

  // Convert to upper case
  char *s = name;
  while (*s) {
    *s = toupper((unsigned char) *s);
    s++;
  }

}
