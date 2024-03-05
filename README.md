# ft_printf

## Description
ft_printf is a custom implementation of the printf function in C. It provides functionality to format and print output to the standard output stream or a specified file descriptor. This project is part of the curriculum at 42 ecole.

## Motivation
The motivation behind creating this project is to deepen understanding of variadic functions, string parsing, and format specifiers in C programming.

## Features
- Custom implementation of the printf function with support for formatting specifiers such as `%s`, `%d`, `%c`, `%p`, etc.
- Additional modifiers and flags to control formatting, precision, and width of output.
- Support for printing to standard output stream or a specified file descriptor.
- Well-documented code with clear explanations of each function's purpose and usage.

## Getting Started
1. Clone the repository: git clone https://github.com/Adel2k/printf.git
2. Navigate to the `ft_printf` directory:
3. Compile the library:

## Testers
- https://github.com/Tripouille/printfTester.git

## Usage
- To use this library in your projects, include the `ft_printf.h` header file in your source files.
- Example usage:
```c
#include "ft_printf.h"

int main() {
   ft_printf("Hello, %s!\n", "world");
   return 0;
}
