#include <iostream>
#include "Tokenizer.h"
#include "InsertRowsCommand.h"

int main() {
    Tokenizer tokenizer;
    tokenizer.tokenList = {
        { Keywords::insert, "insert" },
        { Keywords::into, "into" },
        { Keywords::unknown, "users" },
        { Keywords::openParens, "(" },
        { Keywords::unknown, "name" },
        { Keywords::comma, "," },
        { Keywords::unknown, "email" },
        { Keywords::comma, "," },
        { Keywords::unknown, "username" },
        { Keywords::closeParens, ")" },
        { Keywords::values, "values" },
        { Keywords::openParens, "(" },
        { Keywords::unknown, "\"Mark\"" },
        { Keywords::comma, "," },
        { Keywords::unknown, "\"mmuranov@ucsd.edu\"" },
        { Keywords::comma, "," },
        { Keywords::unknown, "\'mork_man\'" },
        { Keywords::closeParens, ")" },
        { Keywords::semicolon, ";" }
    };

    tokenizer.tokenList = {
            { Keywords::create, "create" },
            { Keywords::database, "database" },
            { Keywords::unknown, "my_database" },
    };

    InsertRowsCommand command;
    command.parse(tokenizer);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
