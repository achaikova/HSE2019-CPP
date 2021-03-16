#include "CLI.h"
#include "CLIException.h"

#include <iostream>

CLI::CLI(int argc, char *argv[]) {
    if (argc == 6) {
        parse_args(1, 2, 4, argv);
        parse_args(3, 1, 4, argv);
        parse_args(5, 1, 3, argv);
    } else throw CLIException("Invalid number of arguments. Expected 6.");
}

void CLI::call_huffman_archiver() {
    if (flag_ == 'c') {
        HuffmanArchiver ar;
        std::ifstream in(fin_, std::ifstream::binary);
        std::ofstream out(fout_, std::ofstream::binary);
        if (!in.is_open() || !out.is_open()) {
            throw CLIException("File problem");
        } else {
            ar.compress(in, out);
            ar.print();
        }
    } else if (flag_ == 'u') {
        HuffmanArchiver ar;
        std::ifstream in(fin_, std::ifstream::binary);
        std::ofstream out(fout_, std::ofstream::binary);
        if (!in.is_open() || !out.is_open()) {
            throw CLIException("File problem");
        } else {
            ar.extract(in, out);
            ar.print();
        }
    }
}

void CLI::parse_args(int a, int b, int c, char *argv[]) {
    if (!strcmp(argv[a], "-c")) {
        flag_ = 'c';

        if (!strcmp(argv[b], "-f") || !strcmp(argv[b], "--file")) fin_ = argv[b + 1];
        else if (!strcmp(argv[c], "-f") || !strcmp(argv[c], "--file")) fin_ = argv[c + 1];

        if (!strcmp(argv[c], "-o") || !strcmp(argv[c], "--output")) fout_ = argv[c + 1];
        else if (!strcmp(argv[b], "-o") || !strcmp(argv[b], "--output")) fout_ = argv[b + 1];

        if (strcmp(argv[b], "-f") && strcmp(argv[b], "--file") && strcmp(argv[c], "-f") &&
            strcmp(argv[c], "--file")) {
            throw CLIException("Unknown flag. Use -f or --file.");
        }

        if (strcmp(argv[c], "-o") && strcmp(argv[c], "--output") && strcmp(argv[b], "-o") &&
            strcmp(argv[b], "--output")) {
            throw CLIException("Unknown flag. Use -o or --output.");
        }

    } else if (!strcmp(argv[a], "-u")) {
        flag_ = 'u';

        if (!strcmp(argv[b], "-f") || !strcmp(argv[b], "--file")) fin_ = argv[b + 1];
        else if (!strcmp(argv[c], "-f") || !strcmp(argv[c], "--file")) fin_ = argv[c + 1];

        if (!strcmp(argv[c], "-o") || !strcmp(argv[c], "--output")) fout_ = argv[c + 1];
        else if (!strcmp(argv[b], "-o") || !strcmp(argv[b], "--output")) fout_ = argv[b + 1];

        if (strcmp(argv[b], "-f") && strcmp(argv[b], "--file") && strcmp(argv[c], "-f") &&
            strcmp(argv[c], "--file")) {
            throw CLIException("Unknown flag. Use -f or --file.");
        }

        if (strcmp(argv[c], "-o") && strcmp(argv[c], "--output") && strcmp(argv[b], "-o") &&
            strcmp(argv[b], "--output")) {
            throw CLIException("Unknown flag. Use -o or --output.");
        }
    }
}