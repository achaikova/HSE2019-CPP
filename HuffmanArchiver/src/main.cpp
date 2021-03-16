#include <cstdlib>
#include <cstdio>
#include <cstring>

#include "CLI.h"

int main(int argc, char *argv[]) {

    CLI parser(argc, argv);
    parser.call_huffman_archiver();

    return 0;
}