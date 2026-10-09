# Experiment 7: Lexical Analyzer Using LEX / FLEX

[![Run on OneCompiler (Auto-Copy)](https://img.shields.io/badge/Run_Code_(Auto--Copy)-OneCompiler-2ecc71?style=for-the-badge&logo=c)](https://ashu-meena.github.io/Compiler_Construction_Experiment/run.html?exp=7&target=onecompiler)
[![Run on OnlineGDB (Auto-Copy)](https://img.shields.io/badge/Run_Code_(Auto--Copy)-OnlineGDB-3498db?style=for-the-badge&logo=c)](https://ashu-meena.github.io/Compiler_Construction_Experiment/run.html?exp=7&target=onlinegdb)
[![Interactive Web Portal](https://img.shields.io/badge/Web_Portal-All_Exps-6f42c1?style=for-the-badge&logo=github)](https://ashu-meena.github.io/Compiler_Construction_Experiment/)

**Course Outcome:** CO3

## Aim
To write a lexical analyzer using Lex/Flex that reads a C-like program and classifies its lexemes into keywords, identifiers, numbers, operators, and special symbols.

## Software Required
* Linux, macOS, or WSL with Flex and GCC installed (`sudo apt install flex gcc`)
* Or WinFlex on Windows

## Theory
Lexical analysis is the first phase of a compiler. It reads the source code as a stream of characters, groups them into meaningful units called **tokens**, and passes them to the parser. It also removes whitespace/comments and flags lexical errors.

| Term | Meaning | Example |
| :--- | :--- | :--- |
| **Token** | A category of lexical unit | `KEYWORD`, `IDENTIFIER` |
| **Lexeme** | The actual character sequence matched | `int`, `count` |
| **Pattern** | Regular expression describing a token | `[0-9]+` |

### Matching Rules of Lex
1. **Longest match:** Lex picks the rule that matches the longest input (e.g. `==` is matched as one operator, not two `=` signs).
2. **First rule wins on a tie:** If two rules match the same length, the rule listed first is chosen (which is why keyword rules precede the identifier rule).
3. **Default action:** Characters not matched by any rule are reported as `UNKNOWN`.

---

## Program Code (`lexer.l`)
See [`lexer.l`](./lexer.l):

```lex
%{
#include <stdio.h>
%}

%option noyywrap

%%
"int"|"float"|"char"|"double"|"if"|"else"|"while"|"for"|"return" {
    printf("%s -> KEYWORD\n", yytext);
}

[0-9]+ {
    printf("%s -> NUMBER\n", yytext);
}

[a-zA-Z_][a-zA-Z0-9_]* {
    printf("%s -> IDENTIFIER\n", yytext);
}

"=="|"!="|"<="|">="|"&&"|"||"|"++"|"--" {
    printf("%s -> OPERATOR\n", yytext);
}

[+\-*/%=<>] {
    printf("%s -> OPERATOR\n", yytext);
}

[{}();,\[\]] {
    printf("%s -> SPECIAL SYMBOL\n", yytext);
}

[ \t\n]+ { /* Ignore whitespace */ }

. {
    printf("%s -> UNKNOWN\n", yytext);
}
%%

int main()
{
    printf("Enter C program (Ctrl+D to finish):\n");
    yylex();
    return 0;
}
```

---

## Test Cases & Output

### Test Case 1: Sample Program
**Input:**
```c
int a = 10;
if (a > 5)
    a = a + 1;
```

**Output:**
```text
int -> KEYWORD
a -> IDENTIFIER
= -> OPERATOR
10 -> NUMBER
; -> SPECIAL SYMBOL
if -> KEYWORD
( -> SPECIAL SYMBOL
a -> IDENTIFIER
> -> OPERATOR
5 -> NUMBER
) -> SPECIAL SYMBOL
a -> IDENTIFIER
= -> OPERATOR
a -> IDENTIFIER
+ -> OPERATOR
1 -> NUMBER
; -> SPECIAL SYMBOL
```

### Test Case 2: Multi-Character Operators & Braces
**Input:**
```c
while (i <= 10) { i++; }
```

**Output:**
```text
while -> KEYWORD
( -> SPECIAL SYMBOL
i -> IDENTIFIER
<= -> OPERATOR
10 -> NUMBER
) -> SPECIAL SYMBOL
{ -> SPECIAL SYMBOL
i -> IDENTIFIER
++ -> OPERATOR
; -> SPECIAL SYMBOL
} -> SPECIAL SYMBOL
```

### Test Case 3: Unknown Symbol
**Input:**
```c
int x = 5 @ 3;
```

**Output:**
```text
int -> KEYWORD
x -> IDENTIFIER
= -> OPERATOR
5 -> NUMBER
@ -> UNKNOWN
3 -> NUMBER
; -> SPECIAL SYMBOL
```

---

## How to Compile & Run

### Using Flex on Linux / WSL / macOS
```bash
flex lexer.l
gcc lex.yy.c -o lexer
./lexer
```
*(Type input and press `Ctrl+D` on Linux/macOS or `Ctrl+Z` then `Enter` on Windows to signal end of input).*
