#include "Writer.h"

Writer::Writer(std::ostream &out) : out(out) {}

int Writer::flush() {
    if (buf.empty()) return 0;
    while (buf.size() % byte != 0) buf.push_back(0);

    int size = buf.size() / byte;
    char c[size];

    for (int i = 0; i < size; i++) {
        c[i] = 0;
        for (int j = 0; j < 8; j++) c[i] += buf[byte * i + j] << j;
    }

    out.write(c, size);
    buf.clear();
    return size;
}

int Writer::write(bool b) {
    buf.push_back(b);
    if (buf.size() == static_cast<uint32_t>(1 << (byte * 2 - 1))) return flush();
    return 0;
}

Writer::~Writer() {
    flush();
}