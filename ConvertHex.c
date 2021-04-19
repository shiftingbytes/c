#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

void inputOutput(void);
int convertCharToHex(char *hexdecnum);
void toUpperCase(char *hexdecnum);
void clearStdin();
void deleteLastChar(char *string);

// Constants
#define INVALID_INPUT -1
#define MAX_INPUT 23
#define MAX_OUTPUT 31

int main()
{
    // Test cases
    // FF B4 C5 D1 65 99 A2 FF
    // FF B4 C6 D4 65 95 A9 FF
    // ff b4 c6 d4 65 95 a9 FF
    inputOutput();
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
    char continueOrBreak[1] = "\0";
    char *token;

    printf("\n Please enter hexadecimals (maximum 23 characters total, numbers separated by space): ");
    fgets(hexdecnum, MAX_INPUT+1, stdin);
    toUpperCase(hexdecnum);
    token = strtok(hexdecnum, delim);
    while(token != NULL)
    {
        result = convertCharToHex(token);
        if (result != INVALID_INPUT)
        {
        //it's only going to be 3 digits + \0
        char decimalNumber[4]; 
        sprintf(decimalNumber,"%d", result);
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
    //delete last comma
    deleteLastChar(stringOfDecimals);        
    if(stringOfDecimals[0]!='\0')
    {
        printf("\n Decimal values of entered hexadecimal number = %s", stringOfDecimals);
    } 
   
    printf("\n Press c to enter another value or any key to quit ");
    scanf("%s", continueOrBreak);
    if(continueOrBreak[0] == 'c')
    {
        clearStdin();
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

void clearStdin(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF) 
    { }
}

void deleteLastChar(char * string){

    string[strlen(string)-1]=0;

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