//
// Created by Mark Muranov on 4/9/24.
//

#pragma once

#include <vector>
#include <string>

enum class Keywords {
    help, about, version, create, drop, database, table, row, insert, into, values, unknown,
    openParens, closeParens, comma, semicolon // ...
};

struct Token {
    Keywords keyword;
    std::string string;
};

class Tokenizer {
public:
    Tokenizer() = default;

    bool exists() { return currentIndex < tokenList.size(); }
    bool more() { return currentIndex + 1 < tokenList.size(); }
    Token& current() { return tokenList[currentIndex]; }
    Token& next() { return tokenList[++currentIndex]; }
    bool peekEquals(const Keywords keyword) {
        if (!more())
            return false;

        return tokenList[currentIndex + 1].keyword == keyword;
    }

    std::vector<Token> tokenList;

private:
    size_t currentIndex = 0;

};