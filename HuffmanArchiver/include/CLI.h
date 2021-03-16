#ifndef HuffmanArchiver_CLI_H
#define HuffmanArchiver_CLI_H

#include <cstdlib>
#include <cstdio>
#include <cstring>

#include "HuffmanArchiver.h"

class CLI {
public:

    explicit CLI(int argc, char *argv[]);

    void call_huffman_archiver();

private:

    void parse_args(int a, int b, int c, char *argv[]);

    std::string fin_;

    std::string fout_;

    char flag_;

};

#endif //HuffmanArchiver_CLI_H