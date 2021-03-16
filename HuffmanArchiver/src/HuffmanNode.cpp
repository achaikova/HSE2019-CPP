#include "HuffmanNode.h"

HuffmanNode::HuffmanNode(char symbol, uint32_t frequency, HuffmanNode *l, HuffmanNode *r) :
        symbol(symbol), frequency(frequency), left(l), right(r) {}

bool HuffmanNode::is_leaf() const {
    return (left == nullptr && right == nullptr);
}

bool HuffmanNode::can_move(bool bit) const {
    if (bit == 0) return (left != nullptr);
    else return (right != nullptr);
}

char HuffmanNode::get_symbol() const {
    return symbol;
}

uint32_t HuffmanNode::get_frequency() const {
    return frequency;
}

HuffmanNode *HuffmanNode::get_left() const {
    return left;
}

HuffmanNode *HuffmanNode::get_right() const {
    return right;
}

HuffmanNode *HuffmanNode::move(bool bit) const {
    if (bit == 0) return left;
    else return right;
}

void HuffmanNode::delete_nodes() {
    if (left) left->delete_nodes();
    if (right) right->delete_nodes();
    delete this;
}