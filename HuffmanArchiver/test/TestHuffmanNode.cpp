#include "HuffmanNode.h"
#include "doctest.h"

TEST_CASE ("test HuffmanNode") {
    SUBCASE ("test is_leaf()") {
        HuffmanNode node('a', 47, nullptr, nullptr);
        bool test = node.is_leaf();
        CHECK(test);
    }
    SUBCASE("test can_move") {
        HuffmanNode child_node('b', 23, nullptr, nullptr);
        HuffmanNode node('a', 10, &child_node, nullptr);
        bool test = node.can_move(0);
        CHECK(test);
    }
    SUBCASE("test get_symbol") {
        HuffmanNode node('q', 15, nullptr, nullptr);
        char test = node.get_symbol();
        CHECK(test == 'q');
    }
    SUBCASE("test get_frequency") {
        HuffmanNode node('a', 1289, nullptr, nullptr);
        uint32_t test = node.get_frequency();
        CHECK(test == 1289);
    }
    SUBCASE("test get_left") {
        HuffmanNode child_node('b', 23, nullptr, nullptr);
        HuffmanNode node('a', 10, &child_node, nullptr);
        HuffmanNode *test = node.get_left();
        CHECK(test == &child_node);
    }
    SUBCASE("test get_right") {
        HuffmanNode child_node('b', 23, nullptr, nullptr);
        HuffmanNode node('a', 10, nullptr, &child_node);
        HuffmanNode *test = node.get_right();
        CHECK(test == &child_node);
    }
    SUBCASE("test move") {
        HuffmanNode child_node('b', 23, nullptr, nullptr);
        HuffmanNode node('a', 10, nullptr, &child_node);
        HuffmanNode *test = node.move(1);
        CHECK(test == &child_node);
    }
}