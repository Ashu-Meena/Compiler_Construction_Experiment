# Experiment 1: Fibonacci Series in C++

[![Run on OneCompiler (Auto-Copy)](https://img.shields.io/badge/Run_Code_(Auto--Copy)-OneCompiler-2ecc71?style=for-the-badge&logo=c%2B%2B)](https://ashu-meena.github.io/Compiler_Construction_Experiment/run.html?exp=1&target=onecompiler)
[![Run on OnlineGDB (Auto-Copy)](https://img.shields.io/badge/Run_Code_(Auto--Copy)-OnlineGDB-3498db?style=for-the-badge&logo=c%2B%2B)](https://ashu-meena.github.io/Compiler_Construction_Experiment/run.html?exp=1&target=onlinegdb)
[![Interactive Web Portal](https://img.shields.io/badge/Web_Portal-All_Exps-6f42c1?style=for-the-badge&logo=github)](https://ashu-meena.github.io/Compiler_Construction_Experiment/)

## Aim
To write and execute a C++ program to generate and display the Fibonacci series up to $n$ terms.

## Algorithm
1. Start the program.
2. Declare variables `n`, `a = 0`, `b = 1`, and `c`.
3. Read the number of terms `n` from the user.
4. If $n \ge 1$, initialize loop counter $i = 1$ to $n$:
   - Print current term $a$.
   - Calculate next term $c = a + b$.
   - Update $a = b$.
   - Update $b = c$.
5. Terminate the program.

## Program Code
* **C++ Version:** [`fibonacci.cpp`](./fibonacci.cpp) (Use with C++ / G++ compiler)
* **Standard C Version:** [`fibonacci.c`](./fibonacci.c) (Use with C or C++ compiler)

### C++ (`fibonacci.cpp`):
```cpp
#include <iostream>
using namespace std;

int main() {
    int n, a = 0, b = 1, c;

    cout << "Enter number of terms: ";
    cin >> n;

    cout << "Fibonacci series: ";

    for (int i = 1; i <= n; i++) {
        cout << a << " ";

        c = a + b;
        a = b;
        b = c;
    }

    return 0;
}
```

## Sample Input & Output
```text
Enter number of terms: 7
Fibonacci series: 0 1 1 2 3 5 8
```

## How to Run Locally

### Using GCC / G++ (MinGW on Windows / Linux / macOS)
```bash
g++ fibonacci.cpp -o fibonacci
./fibonacci
```
