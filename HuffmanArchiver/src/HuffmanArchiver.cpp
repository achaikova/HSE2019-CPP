#include "HuffmanArchiver.h"

void HuffmanArchiver::compress(std::istream &in, std::ostream &out) {
    in.seekg(0, in.end);
    int size = in.tellg();

    size_ = size;
    after_size_ = 0;

    in.seekg(0, in.beg);

    char symbol;

    std::map<char, uint32_t> frequency;

    for (int i = 0; i < size; i++) {
        in.read(&symbol, 1);
        frequency[symbol]++;
    }

    write_table(out, frequency);

    if (!frequency.empty()) {
        HuffmanTree tree(frequency);

        out.write((char *) &size, bytes);

        table_size_ += 4;

        std::map<char, std::vector<char> > codes;
        Writer writer(out);
        tree.get_codes(codes);
        in.seekg(0, in.beg);

        std::vector<char> gt[256];
        for (auto &code : codes)
            gt[code.first + 128] = code.second;

        for (int i = 0; i < size; i++) {
            in.read(&symbol, 1);
            std::vector<char> &code = gt[symbol + 128];
            for (char j : code) after_size_ += writer.write(j);
        }
        after_size_ += writer.flush();
    }
}

void HuffmanArchiver::extract(std::istream &in, std::ostream &out) {
    after_size_ = 0;
    size_ = 0;
    std::map<char, uint32_t> freq;
    read_table(in, freq);
    if (freq.empty()) {
        size_ = after_size_ = 0;
        print();
        return;
    }

    HuffmanTree t(freq);
    HuffmanNode *v = t.get_root();

    uint32_t size;
    in.read((char *) &size, bytes);
    table_size_ += bytes;

    char symbol;
    bool bit;
    while (size) {
        in.read(&symbol, 1);
        size_++;
        for (int j = 0; size && j < bytes * 2; j++) {
            bit = (symbol & (1 << j));
            v = v->move(bit);
            if (v->is_leaf()) {
                after_size_++;
                char c = v->get_symbol();
                out.write(&c, 1);
                v = t.get_root();
                size--;
            }
        }
    }
}

uint32_t HuffmanArchiver::get_size() const {
    return size_;
}

uint32_t HuffmanArchiver::get_after_size() const {
    return after_size_;
}

uint32_t HuffmanArchiver::get_table_size() const {
    return table_size_;
}

void HuffmanArchiver::print() {
    std::cout << size_ << "\n";
    std::cout << after_size_ << "\n";
    std::cout << table_size_ << "\n";
}

void HuffmanArchiver::read_table(std::istream &in, std::map<char, uint32_t> &freq) {
    uint32_t num;
    in.read((char *) &num, bytes);
    char symbol;
    uint32_t f;
    for (uint32_t i = 0; i < num; i++) {
        in.read(&symbol, 1);
        in.read((char *) &f, bytes);
        freq[symbol] = f;
    }
    table_size_ = 5 * num + bytes;
}

void HuffmanArchiver::write_table(std::ostream &out, const std::map<char, uint32_t> &freq) {
    uint32_t num = freq.size();
    out.write((char *) &num, bytes);
    for (auto it : freq) {
        out.write(&it.first, 1);
        out.write((char *) &it.second, bytes);
    }
    table_size_ = 5 * num + bytes;
}