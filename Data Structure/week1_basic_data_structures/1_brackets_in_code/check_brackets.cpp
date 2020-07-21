#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position = 0;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    int pos = 0;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            opening_brackets_stack.push(Bracket(next, position + 1));
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if(opening_brackets_stack.empty()){
                pos = position + 1;
                break;
            }
            Bracket top = opening_brackets_stack.top();
            opening_brackets_stack.pop();

            if(!top.Matchc(next)){
                pos = position + 1;
                break;
            }


        }
    }

    // Printing answer, write your code here
    if(pos )
        std::cout<<pos;
    else if(opening_brackets_stack.empty() == false){
        Bracket top = opening_brackets_stack.top();
        opening_brackets_stack.pop();
        std::cout<<top.position;
    }
    else
        std::cout<<"Success";

    return 0;
}
