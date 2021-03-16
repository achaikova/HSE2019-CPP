#include "HuffmanTree.h"

HuffmanTree::HuffmanTree(const std::map<char, uint32_t> &freq) {

    if (freq.size() == 1) {
        auto *v = new HuffmanNode(freq.begin()->first, freq.begin()->second, nullptr, nullptr);
        root = new HuffmanNode(0, 0, v, nullptr);
    } else {
        std::vector<char> chars;
        std::vector < HuffmanNode * > nodes;
        std::set <std::pair<uint32_t, uint32_t>> set;
        for (auto it : freq) {
            set.insert(std::make_pair(it.second, chars.size()));
            chars.push_back(it.first);
            auto *v = new HuffmanNode(it.first, it.second, nullptr, nullptr);
            nodes.push_back(v);
        }

        while (set.size() != 2) {
            std::pair <uint32_t, uint32_t> fst = *set.begin();
            set.erase(set.begin());
            std::pair <uint32_t, uint32_t> sec = *set.begin();
            set.erase(set.begin());
            set.insert(std::make_pair(fst.first + sec.first, nodes.size()));
            auto *v = new HuffmanNode(0, fst.first + sec.first, nodes[fst.second], nodes[sec.second]);
            nodes.push_back(v);
        }

        std::pair <uint32_t, uint32_t> fst = *set.begin();
        set.erase(set.begin());
        std::pair <uint32_t, uint32_t> sec = *set.begin();
        root = new HuffmanNode(0, 0, nodes[fst.second], nodes[sec.second]);
    }
}

HuffmanTree::~HuffmanTree() {
    if (root) root->delete_nodes();
}

void HuffmanTree::get_codes(std::map<char, std::vector<char> > &codes) {
    if (root->is_leaf()) {
        codes[root->get_symbol()].push_back(0);
    } else {
        std::vector<char> cur;
        find_codes(root, cur, codes);
    }
}

HuffmanNode *HuffmanTree::get_root() const {
    return root;
}

void HuffmanTree::find_codes(HuffmanNode *v, std::vector<char> &cur, std::map<char, std::vector<char> > &codes) {
    if (v->is_leaf()) {
        codes[v->get_symbol()].insert(codes[v->get_symbol()].end(), cur.begin(), cur.end());
    } else {
        if (v->get_left()) {
            cur.push_back(0);
            find_codes(v->get_left(), cur, codes);
            cur.pop_back();
        }
        if (v->get_right()) {
            cur.push_back(1);
            find_codes(v->get_right(), cur, codes);
            cur.pop_back();
        }
    }
}