#pragma once
#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

using namespace std;
struct Exception {
private:
    string message;
public:
    Exception(string message);
    virtual string getMessage();
};

struct NoSuchElementException : Exception {
    NoSuchElementException(string message) : Exception(message) {}
};

struct WrongInputException : Exception {
    WrongInputException(string message) : Exception(message) {}
};

#endif //EXCEPTION_H