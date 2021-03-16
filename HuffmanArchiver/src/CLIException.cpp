#include "CLIException.h"

CLIException::CLIException(std::string err_message)
        : err_message(err_message) {}

const char *CLIException::what() const noexcept {
    return err_message.c_str();
}