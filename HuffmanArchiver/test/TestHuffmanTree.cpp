#include "HuffmanTree.h"
#include "doctest.h"

TEST_CASE ("test HuffmanTree") {
    SUBCASE("test get_codes") {
        std::map<char, std::vector<char>> codes;
        std::map<char, uint32_t> freq;
        freq['a'] = 5;
        HuffmanTree tree(freq);
        tree.get_codes(codes);
        uint32_t test = codes['a'].size();
        CHECK(test == 1);
    }
    SUBCASE("test get_root") {
        std::map<char, uint32_t> freq;
        freq['b'] = 7;
        HuffmanTree tree(freq);
        HuffmanNode *node = tree.get_root();
        HuffmanNode *test = node->get_left();
        CHECK(test->get_symbol() == 'b');
        CHECK(test->get_frequency() == 7);
    }
    SUBCASE("test find_codes") {
        std::map<char, std::vector<char>> codes;
        std::map<char, uint32_t> freq;
        freq['a'] = 5;
        freq['b'] = 7;
        HuffmanTree tree(freq);
        std::vector<char> cur;
        tree.find_codes(tree.get_root(), cur, codes);
        std::vector<char> vec1 = codes['a'];
        std::vector<char> vec2 = codes['b'];
        CHECK(vec1.size() == 1);
        CHECK(vec1[0] == 0);
        CHECK(vec2.size() == 1);
        CHECK(vec2[0] == 1);
    }
}