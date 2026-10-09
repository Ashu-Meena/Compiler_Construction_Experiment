#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char *keywords[] = {
    "int", "float", "char", "double",
    "if", "else", "for", "while",
    "return", "void", "break", "continue"
};

int isKeyword(const char *word)
{
    int i;

    for (i = 0; i < 12; i++)
    {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }

    return 0;
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' ||
            ch == '/' || ch == '=' || ch == '<' ||
            ch == '>' || ch == '%');
}

int main()
{
    char str[500];
    int i = 0;

    printf("Enter C source code: ");
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0')
    {
        /* Ignore spaces and newline */
        if (isspace(str[i]))
        {
            i++;
            continue;
        }

        /* Identifier or keyword */
        if (isalpha(str[i]) || str[i] == '_')
        {
            char word[50];
            int j = 0;

            while (isalnum(str[i]) || str[i] == '_')
            {
                word[j++] = str[i++];
            }

            word[j] = '\0';

            if (isKeyword(word))
                printf("%s -> Keyword\n", word);
            else
                printf("%s -> Identifier\n", word);
        }

        /* Constant */
        else if (isdigit(str[i]))
        {
            char number[50];
            int j = 0;

            while (isdigit(str[i]))
            {
                number[j++] = str[i++];
            }

            number[j] = '\0';

            printf("%s -> Constant\n", number);
        }

        /* Operator */
        else if (isOperator(str[i]))
        {
            printf("%c -> Operator\n", str[i]);
            i++;
        }

        /* Special symbol */
        else
        {
            printf("%c -> Special Symbol\n", str[i]);
            i++;
        }
    }

    return 0;
}
