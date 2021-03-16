#ifndef HuffmanArchiver_WRITER_H
#define HuffmanArchiver_WRITER_H

#include <fstream>
#include <vector>

class Writer {
public:
    explicit Writer(std::ostream &out);

    Writer &operator=(const Writer &) = delete;

    Writer(const Writer &) = delete;

    ~Writer();

    int write(bool bit);

    int flush();

private:

    const int byte = 8;

    std::ostream &out;

    std::vector<char> buf;
};

#endif //HuffmanArchiver_WRITER_H