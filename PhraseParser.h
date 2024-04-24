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

private:
    Tokenizer& tokenizer;

    // Some sort of vector to store the various phrase parsers specified via the builder pattern
    // TODO
};