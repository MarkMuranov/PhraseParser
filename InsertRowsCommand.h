//
// Created by Mark on 4/23/2024.
//

#pragma once

#include <string>
#include <vector>
#include "Tokenizer.h"
#include "PhraseParser.h"

class InsertRowsCommand {
public:
    bool parse(Tokenizer& tokenizer) {
        return PhraseParser::newPhrase(tokenizer)
            .keyword(Keywords::insert)
            .keyword(Keywords::into)
            .word(tableName) // Sets 'tableName' to the word
            .commaSeparatedWords(tableColumns) // Extracts table columns
            .keyword(Keywords::values)
            .commaSeparatedWords(rowValues) // Extracts row values. This will NOT account for multiple rows.
            .parse(); // Ends the builder
    }

private:
    std::string tableName;
    std::vector<std::string> tableColumns;
    std::vector<std::string> rowValues;

};
