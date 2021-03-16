#include <sstream>

#include "HuffmanArchiver.h"
#include "doctest.h"

TEST_CASE ("test HuffmanArchiver") {
    SUBCASE ("test compress") {
        HuffmanArchiver ar;
        std::stringstream ss_in;
        std::stringstream ss_out;
        ss_in << "Hello world!";
        ar.compress(ss_in, ss_out);
        CHECK(ar.get_size() == 12);
        CHECK(ar.get_after_size() == 5);
        CHECK(ar.get_table_size() == 53);
    }
    SUBCASE ("test extract") {
        HuffmanArchiver ar;
        std::stringstream ss_in;
        std::stringstream ss_out;
        ss_in << "Hello world!";
        ar.compress(ss_in, ss_out);
        ar.extract(ss_out, ss_in);
        CHECK(ar.get_size() == 5);
        CHECK(ar.get_after_size() == 12);
        CHECK(ar.get_table_size() == 53);
    }
}