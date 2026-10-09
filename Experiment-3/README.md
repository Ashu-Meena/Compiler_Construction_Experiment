# Experiment 3: Lexical Analysis of C Source Code

[![Run on OneCompiler (Auto-Copy)](https://img.shields.io/badge/Run_Code_(Auto--Copy)-OneCompiler-2ecc71?style=for-the-badge&logo=c)](https://ashu-meena.github.io/Compiler_Construction_Experiment/run.html?exp=3&target=onecompiler)
[![Run on OnlineGDB (Auto-Copy)](https://img.shields.io/badge/Run_Code_(Auto--Copy)-OnlineGDB-3498db?style=for-the-badge&logo=c)](https://ashu-meena.github.io/Compiler_Construction_Experiment/run.html?exp=3&target=onlinegdb)
[![Interactive Web Portal](https://img.shields.io/badge/Web_Portal-All_Exps-6f42c1?style=for-the-badge&logo=github)](https://ashu-meena.github.io/Compiler_Construction_Experiment/)

## Aim
To implement a lexical analyzer in C to identify tokens (keywords, identifiers, constants, operators, and special symbols) from given C source code.

## Algorithm
1. Start the program.
2. Define a list of language keywords (e.g., `int`, `float`, `char`, `if`, `while`, etc.) and helper validation functions:
   - `isKeyword(word)`: checks if the word exists in the keyword list.
   - `isOperator(ch)`: checks if a character is one of `+`, `-`, `*`, `/`, `=`, `<`, `>`, `%`.
3. Input the source code string using `fgets()`.
4. Traverse the string character by character:
   - **Skip Whitespace:** Ignore spaces, tabs, and newline characters.
   - **Identifiers / Keywords:** If a character is alphabetical or `_`, collect alphanumeric and underscore characters into a token buffer. If it matches a known keyword, classify as **Keyword**; otherwise, classify as **Identifier**.
   - **Constants:** If a character is a digit, collect consecutive digits into a token buffer and classify as **Constant**.
   - **Operators:** If it matches operator symbols, classify as **Operator**.
   - **Special Symbols:** Treat any remaining symbols (e.g., `;`, `{`, `}`) as **Special Symbol**.
5. Display each detected token along with its token category.
6. Terminate the program.

## Program Code
See [`lexical_analysis.c`](./lexical_analysis.c):

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *keywords[] = {
    "int", "float", "char", "double",
    "if", "else", "for", "while",
    "return", "void", "break", "continue"
};

int isKeyword(char *word)
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
```

## Sample Input & Output
```text
Enter C source code: int a = 10;

int -> Keyword
a -> Identifier
= -> Operator
10 -> Constant
; -> Special Symbol
```

## How to Run Locally

### Using GCC (MinGW on Windows / Linux / macOS)
```bash
gcc lexical_analysis.c -o lexical_analysis
./lexical_analysis
```
