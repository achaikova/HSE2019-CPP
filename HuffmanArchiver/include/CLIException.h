#ifndef HuffmanArchiver_CLIEXCEPTION_H
#define HuffmanArchiver_CLIEXCEPTION_H

#include <exception>
#include <string>

class CLIException : public std::exception {
public:
    CLIException(std::string err_message);

    const char *what() const noexcept override;

private:
    const std::string err_message;
};

#endif //HuffmanArchiver_CLIEXCEPTION_H