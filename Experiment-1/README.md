# Experiment 1: Fibonacci Series in C++

[![Run on OneCompiler](https://img.shields.io/badge/Run_Code-OneCompiler-2ecc71?style=for-the-badge&logo=c%2B%2B)](https://onecompiler.com/cpp)
[![Run on OnlineGDB](https://img.shields.io/badge/Run_Code-OnlineGDB-3498db?style=for-the-badge&logo=c%2B%2B)](https://www.onlinegdb.com/online_c++_compiler)

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
See [`fibonacci.cpp`](./fibonacci.cpp):

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
