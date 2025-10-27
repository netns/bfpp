#include <stdexcept>

#include "brainfuck.hpp"

using std::string;
using std::vector;

BrainfuckInterpreter::BrainfuckInterpreter(size_t tapeSize)
    : tape(tapeSize, 0), pointer(0), inputPos(0) {}

void BrainfuckInterpreter::run(const string &code)
{
    size_t pc = 0;
    while (pc < code.size())
    {
        executeToken(code[pc], code, pc);
        pc++;
    }
}

void BrainfuckInterpreter::executeToken(const char token, const string &code, size_t &pc)
{
    switch (token)
    {
    case BRAINFUCK_TOKEN_NEXT: // >
        pointer++;
        if (pointer >= tape.size())
            pointer = 0;
        break;
    case BRAINFUCK_TOKEN_PREVIOUS: // <
        if (pointer == 0)
            pointer = tape.size() - 1;
        else
            --pointer;
        break;
    case BRAINFUCK_TOKEN_PLUS: // '+'
        ++tape[pointer];
        break;
    case BRAINFUCK_TOKEN_MINUS: // '-'
        --tape[pointer];
        break;
    case BRAINFUCK_TOKEN_OUTPUT: // '.'
        outputBuffer += tape[pointer];
        break;
    case BRAINFUCK_TOKEN_INPUT: // ','
        if (inputPos < inputBuffer.size())
            tape[pointer] = inputBuffer[inputPos++];
        else
            tape[pointer] = 0; // EOF = 0
        break;
    case BRAINFUCK_TOKEN_LOOP_START: // '['
        if (tape[pointer] == 0)
            pc = findMatchingBracket(code, pc);
        break;
    case BRAINFUCK_TOKEN_LOOP_END: // ']'
        if (tape[pointer] != 0)
            pc = findMatchingBracket(code, pc);
        break;
    default:
        break;
    }
}

void BrainfuckInterpreter::setInput(const string &input)
{
    inputBuffer = input;
    inputPos = 0;
}

string BrainfuckInterpreter::getOutput() const
{
    return outputBuffer;
}

size_t BrainfuckInterpreter::findMatchingBracket(const string &code, size_t pc)
{
    char current = code[pc];
    int direction = (current == '[') ? 1 : -1;
    int counter = 1;

    while (counter != 0)
    {
        pc += direction;
        if (pc >= code.size())
            throw std::runtime_error("Error: unclosed square brackets");

        if (code[pc] == '[')
            counter += direction;
        else if (code[pc] == ']')
            counter -= direction;
    }
    return pc;
}
