# Brainfuck Interpreter in C++

A simple and lightweight Brainfuck interpreter written in C++.  
It reads Brainfuck code from a file, executes it, and supports input and output operations.

## Features

- Supports all 8 Brainfuck commands:
  - `>` : move the pointer to the right
  - `<` : move the pointer to the left
  - `+` : increment the value at the current cell
  - `-` : decrement the value at the current cell
  - `.` : output the value at the current cell
  - `,` : read a value into the current cell
  - `[` : jump past the matching `]` if the current cell is zero
  - `]` : jump back to the matching `[` if the current cell is non-zero
- Handles nested loops
- Reads input from a string buffer
- Produces output as a string buffer
