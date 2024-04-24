cmake_minimum_required(VERSION 3.2)
project(PhaseParsing)

set(CMAKE_CXX_STANDARD 17)

add_executable(PhaseParsing main.cpp
        Tokenizer.h
        InsertRowsCommand.h
        PhraseParser.h
)
