#ifndef BRAINFUCK_HPP
#define BRAINFUCK_HPP

#include <cstddef>
#include <string>
#include <vector>

#define BRAINFUCK_TAPE_SIZE 30000

#define BRAINFUCK_TOKEN_PLUS '+'
#define BRAINFUCK_TOKEN_MINUS '-'
#define BRAINFUCK_TOKEN_PREVIOUS '<'
#define BRAINFUCK_TOKEN_NEXT '>'
#define BRAINFUCK_TOKEN_OUTPUT '.'
#define BRAINFUCK_TOKEN_INPUT ','
#define BRAINFUCK_TOKEN_LOOP_START '['
#define BRAINFUCK_TOKEN_LOOP_END ']'

using std::string;
using std::vector;

class BrainfuckInterpreter
{
private:
    vector<unsigned char> tape; // memory tape
    size_t pointer;             // actual position
    string inputBuffer;         // data input
    string outputBuffer;        // data output
    size_t inputPos;            // actual position on input

public:
    BrainfuckInterpreter(size_t tapeSize = BRAINFUCK_TAPE_SIZE)
        : tape(tapeSize, 0), pointer(0), inputPos(0) {}

    // Executes bf code
    void run(const string &code);

    // Get token ',' input
    void setInput(const string &input);

    // Returns token '.' output
    std::string getOutput() const;

private:
    void executeToken(const char token, const string &code, size_t &pc);

    size_t findMatchingBracket(const string &code, size_t pc);
};

#endif // BRAINFUCK_HPP
