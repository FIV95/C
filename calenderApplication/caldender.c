#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// ##########################################
bool leapYearCheck(int *year);
void add_days_to_date(int *m, int *d, int *y, int days_left_to_add);
bool validDateCheck(int *y, int *m, int *d);
char formatCheck(char *inputString);
// ##########################################

int regexCheckForMonth(char *inputString)
{

    // we are preparing the compiliaton of the regex
    regex_t regex;
    int reti;
    char msgbuf[100];
    regmatch_t match[1];
    char *pattern =
        "(January|january|February|february|March|march|April|april|May|may|"
        "June|june|July|july|August|august|September|september|October|october|"
        "November|november|December|december)";
    int result;

    reti = regcomp(&regex, pattern, REG_EXTENDED | REG_ICASE);
    if (reti)
    {
        fprintf(stderr, "Could not compile regex\n");
        return 1;
    }

    // executing the regex against our input string
    reti = regexec(&regex, inputString, 1, match, 0);
    if (!reti)
    {
        for (int i = 0; i < match[0].rm_so; i++)
        {
            printf("%c", inputString[i]);
        }
        printf("%s\n", inputString);
        // rm means register match
        // _so means start offset
        // _eo means end offset
        // the %s.*s means we will specify the characters printed to the string
        // in the printf parameters
        printf("Match found: %.*s\n", match[0].rm_eo - match[0].rm_so,
               &inputString[match[0].rm_so]);
        // we need to save the match to a variiable
        // we need to run a switch statement  to determine the month
        switch (inputString[match[0].rm_so])
        {
        case 'J':
        case 'j':
            if (strncmp(&inputString[match[0].rm_so], "January", 7) == 0 ||
                strncmp(&inputString[match[0].rm_so], "january", 7) == 0)
                result = 1;
            else if (strncmp(&inputString[match[0].rm_so], "June", 4) == 0 ||
                     strncmp(&inputString[match[0].rm_so], "june", 4) == 0)
                result = 6;
            else if (strncmp(&inputString[match[0].rm_so], "July", 4) == 0 ||
                     strncmp(&inputString[match[0].rm_so], "july", 4) == 0)
                result = 7;
            break;
        case 'F':
        case 'f':
            if (strncmp(&inputString[match[0].rm_so], "February", 8) == 0 ||
                strncmp(&inputString[match[0].rm_so], "february", 8) == 0)
                result = 2;
            break;
        case 'M':
        case 'm':
            if (strncmp(&inputString[match[0].rm_so], "March", 5) == 0 ||
                strncmp(&inputString[match[0].rm_so], "march", 5) == 0)
                result = 3;
            else if (strncmp(&inputString[match[0].rm_so], "May", 3) == 0 ||
                     strncmp(&inputString[match[0].rm_so], "may", 3) == 0)
                result = 5;
            break;

        case 'A':
        case 'a':
            if (strncmp(&inputString[match[0].rm_so], "April", 5) == 0 ||
                strncmp(&inputString[match[0].rm_so], "april", 5) == 0)
                result = 4;
            else if (strncmp(&inputString[match[0].rm_so], "August", 6) == 0 ||
                     strncmp(&inputString[match[0].rm_so], "august", 6) == 0)
                result = 8;
            break;
        case 'S':
        case 's':
            if (strncmp(&inputString[match[0].rm_so], "September", 9) == 0 ||
                strncmp(&inputString[match[0].rm_so], "september", 9) == 0)
                result = 9;
            break;
        case 'O':
        case 'o':
            if (strncmp(&inputString[match[0].rm_so], "October", 7) == 0 ||
                strncmp(&inputString[match[0].rm_so], "october", 7) == 0)
                result = 10;
            break;
        case 'N':
        case 'n':
            if (strncmp(&inputString[match[0].rm_so], "November", 8) == 0 ||
                strncmp(&inputString[match[0].rm_so], "november", 8) == 0)
                result = 11;
            break;
        case 'D':
        case 'd':
            if (strncmp(&inputString[match[0].rm_so], "December", 8) == 0 ||
                strncmp(&inputString[match[0].rm_so], "december", 8) == 0)
                result = 12;
            break;
        default:
            printf("Non valid month entered\n");
            result = 0;
            break;
        }
    }
    else
    {
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
        regfree(&regex);
        return 0;
    }
    regfree(&regex);
    return result;
}

bool validDateCheck(int *y, int *m, int *d)
{
    if (!(*y >= 0) || !(*m > 0) || !(*m <= 12) || !(*d <= 31) || !(*d > 0))
    {
        return false;
    }
    else
        return true;
}

bool leapYearCheck(int *year)
{
    if (*year % 4 != 0)
    {
        return false;
    }
    else if (*year % 100 != 0)
    {
        return true;
    }
    else if (*year % 400 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int days_in_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void add_days_to_date(int *m, int *d, int *y, int days_left_to_add)
{
    int limit;
    switch (*m)
    {
    case 1:
        limit = days_in_month[1];
        break;
    case 2:
        limit = days_in_month[2];
        break;
    case 3:
        limit = days_in_month[3];
        break;
    case 4:
        limit = days_in_month[4];
        break;
    case 5:
        limit = days_in_month[5];
        break;
    case 6:
        limit = days_in_month[6];
        break;
    case 7:
        limit = days_in_month[7];
        break;
    case 8:
        limit = days_in_month[8];
        break;
    case 9:
        limit = days_in_month[9];
        break;
    case 10:
        limit = days_in_month[10];
        break;
    case 11:
        limit = days_in_month[11];
        break;
    case 12:
        limit = days_in_month[12];
        break;
    default:
        printf("Non valid month entered\n");
    }
    while (days_left_to_add)
    {
        if (*m == 2 && leapYearCheck(&y))
        {
            limit++;
            *d++;
            if (days_left_to_add > limit)
            {
                *m++;
                if (*m == 12)
                {
                    *y++;
                    *m = 1;
                    limit = days_in_month[*m];
                }
            }
        }
    }
}

int main()
{
    int y, m, d;
    char formatter;
    char date[20];

    printf("Enter the date in the following format: mm/dd/yyyy\n");
    scanf("%s", date);
    int result = regexCheckForMonth(date);
    printf("Result of regexCheckMonth: %d\n", result);
}
