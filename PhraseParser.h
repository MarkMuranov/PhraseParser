//
// Created by Mark on 4/23/2024.
//

#pragma once

#include <vector>
#include <string>
#include <functional>
#include "Tokenizer.h"

class PhraseParser {
public:
    PhraseParser(Tokenizer& t) : tokenizer(t) {}

    static PhraseParser newPhrase(Tokenizer& tokenizer) {
        return PhraseParser(tokenizer);
    }

    // Builder methods

    PhraseParser& keyword(Keywords keyword) {
        phrases.emplace_back([keyword, this]() {
            if (!tokenizer.exists() || tokenizer.current().keyword != keyword)
                return false;

            tokenizer.next();
            return true;
        });
        return *this;
    }

    PhraseParser& word(std::string& output) {
        phrases.emplace_back([&output, this]() {
            if (!tokenizer.exists())
                return false;

            output = tokenizer.current().string;
            return true;
        });
        return *this;
    }

    PhraseParser& commaSeparatedWords(std::vector<std::string>& output) {
        phrases.emplace_back([&output, this]() {
            // Logic to parse and set 'output'
            return true;
        });
        return *this;
    }

    // End builder
    bool parse() {
        for (auto& phrase : phrases)
            if (!phrase())
                return false;

        return true;
    }

private:
    Tokenizer& tokenizer;
    // Some sort of vector to store the various phrase parsers specified via the builder pattern
    std::vector<std::function<bool()>> phrases;
};