#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

void input(void);
int convertCharToHex(char *hexdecnum);
void toUpperCase(char *hexdecnum);

// Constants
#define invalidInput -1

int main()
{
    input();
    return 0;
}

void input()
{
    char hexdecnum[20];
    int result = 0;
    char continueOrBreak;
    printf("\n Please enter hexadecimal value: ");
    scanf("%s", &hexdecnum);
    toUpperCase(hexdecnum);
    result = convertCharToHex(hexdecnum);
    if (result != invalidInput)
    {
        printf("\n Decimal value of entered hexadecimal number = %d", result);
    }
    else
    {
        printf("\n Invalid hexadecimal");
    }
    printf("\n Press c to enter another value or any key to quit ");
    scanf("%s", &continueOrBreak);
    if(continueOrBreak == 'c')
    {
        input();
    }
    else
    {
        return;
    }
}

int convertCharToHex(char *hexdecnum)
{
    int decnum = 0, rem, i = 0, len = 0;
    while (hexdecnum[i] != '\0')
    {
        len++;
        i++;
    }
    len--;
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
            return invalidInput;
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
