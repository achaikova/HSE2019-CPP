#ifndef HuffmanArchiver_HUFFMANTREE_H
#define HuffmanArchiver_HUFFMANTREE_H

#include <map>
#include <set>
#include <vector>
#include <iostream>

#include "HuffmanNode.h"

class HuffmanTree {
public:

    HuffmanTree(const std::map<char, uint32_t> &freq);

    ~HuffmanTree();

    void get_codes(std::map<char, std::vector<char> > &codes);

    HuffmanNode *get_root() const;

    void find_codes(HuffmanNode *v, std::vector<char> &cur, std::map<char, std::vector<char> > &codes);

private:

    HuffmanNode *root;
};


#endif //HuffmanArchiver_HUFFMANTREE_H