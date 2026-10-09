# Experiment 2: Macro Definition Identification in C++

[![Run on OneCompiler (Auto-Copy)](https://img.shields.io/badge/Run_Code_(Auto--Copy)-OneCompiler-2ecc71?style=for-the-badge&logo=c%2B%2B)](https://ashu-meena.github.io/Compiler_Construction_Experiment/run.html?exp=2&target=onecompiler)
[![Run on OnlineGDB (Auto-Copy)](https://img.shields.io/badge/Run_Code_(Auto--Copy)-OnlineGDB-3498db?style=for-the-badge&logo=c%2B%2B)](https://ashu-meena.github.io/Compiler_Construction_Experiment/run.html?exp=2&target=onlinegdb)
[![Interactive Web Portal](https://img.shields.io/badge/Web_Portal-All_Exps-6f42c1?style=for-the-badge&logo=github)](https://ashu-meena.github.io/Compiler_Construction_Experiment/)

## Aim
To write and execute a C++ program to identify whether a given assembly language instruction is a Macro Definition or not.

## Algorithm
1. Start the program.
2. Declare a string variable `s` to store the assembly instruction.
3. Prompt the user to enter an assembly instruction using `getline()` to capture spaces.
4. Check if the string contains the keyword `"MACRO"` using the `find()` method:
   - If found (`s.find("MACRO") != string::npos`), output: `"It is a macro definition"`.
   - Otherwise, output: `"It is not a macro definition"`.
5. Terminate the program.

## Program Code
* **C++ Version:** [`macro_definition.cpp`](./macro_definition.cpp) (Use with C++ / G++ compiler)
* **Standard C Version:** [`macro_definition.c`](./macro_definition.c) (Use with C or C++ compiler)

### C++ (`macro_definition.cpp`):
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;

    cout << "Enter assembly instruction: ";
    getline(cin, s);

    if (s.find("MACRO") != string::npos) {
        cout << "It is a macro definition" << endl;
    } else {
        cout << "It is not a macro definition" << endl;
    }

    return 0;
}
```

## Sample Input & Output

### Case 1: Valid Macro Definition
```text
Enter assembly instruction: ADD MACRO A,B
It is a macro definition
```

### Case 2: Not a Macro Definition
```text
Enter assembly instruction: ADD A,B
It is not a macro definition
```

## How to Run Locally

### Using GCC / G++ (MinGW on Windows / Linux / macOS)
```bash
g++ macro_definition.cpp -o macro_definition
./macro_definition
```
