#ifndef HuffmanArchiver_NODE_H
#define HuffmanArchiver_NODE_H

#include <cstdint>

class HuffmanNode {
public:

    HuffmanNode() {};

    HuffmanNode(char symbol, uint32_t frequency, HuffmanNode *l, HuffmanNode *r);

    bool is_leaf() const;

    bool can_move(bool bit) const;

    char get_symbol() const;

    uint32_t get_frequency() const;

    HuffmanNode *get_left() const;

    HuffmanNode *get_right() const;

    HuffmanNode *move(bool bit) const;

    void delete_nodes();

private:

    char symbol = 'a';

    uint32_t frequency = 0;

    HuffmanNode *left = nullptr;

    HuffmanNode *right = nullptr;

};


#endif //HuffmanArchiver_NODE_H