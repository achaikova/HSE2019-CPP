#ifndef HuffmanArchiver_HUFFMANARCHIVER_H
#define HuffmanArchiver_HUFFMANARCHIVER_H

#include <ostream>
#include <istream>
#include <fstream>
#include <iostream>

#include "HuffmanTree.h"
#include "Writer.h"

class HuffmanArchiver {
public:
    void compress(std::istream &in, std::ostream &out);

    void extract(std::istream &in, std::ostream &out);

    uint32_t get_size() const;

    uint32_t get_after_size() const;

    uint32_t get_table_size() const;

    void print();

private:

    void read_table(std::istream &in, std::map<char, uint32_t> &freq);

    void write_table(std::ostream &out, const std::map<char, uint32_t> &freq);

    const int bytes = 4;

    uint32_t size_ = 0, after_size_ = 0, table_size_ = 0;
};

#endif //HuffmanArchiver_HUFFMANARCHIVER_H

