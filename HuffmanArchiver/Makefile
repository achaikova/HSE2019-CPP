CFLAGS =-std=c++17 -Wall -Werror -Wextra -Iinclude

all: HuffmanArchiver test_HuffmanArchiver

HuffmanArchiver: obj obj/main.o obj/Writer.o obj/HuffmanArchiver.o obj/HuffmanTree.o obj/HuffmanNode.o obj/CLI.o obj/CLIException.o
	g++ obj/main.o obj/Writer.o obj/HuffmanArchiver.o obj/HuffmanTree.o obj/HuffmanNode.o obj/CLI.o obj/CLIException.o -o HuffmanArchiver

test_HuffmanArchiver: obj/TestMain.o obj/TestHuffmanNode.o obj/HuffmanNode.o obj/TestHuffmanTree.o obj/HuffmanTree.o obj/TestHuffmanArchiver.o obj/HuffmanArchiver.o obj/Writer.o
	g++ obj/TestMain.o obj/TestHuffmanNode.o obj/HuffmanNode.o obj/TestHuffmanTree.o obj/HuffmanTree.o obj/TestHuffmanArchiver.o obj/HuffmanArchiver.o obj/Writer.o -o test_HuffmanArchiver

obj:
	mkdir obj

obj/main.o: src/main.cpp  obj/CLI.o include/CLI.h | obj
	g++ -c -o obj/main.o $(CFLAGS) src/main.cpp

obj/Writer.o: src/Writer.cpp include/Writer.h | obj
	g++ -c -o obj/Writer.o $(CFLAGS) src/Writer.cpp

obj/HuffmanArchiver.o: src/HuffmanArchiver.cpp obj/HuffmanTree.o include/HuffmanTree.h obj/Writer.o include/Writer.h | obj
	g++ -c -o obj/HuffmanArchiver.o $(CFLAGS) src/HuffmanArchiver.cpp

obj/HuffmanTree.o: src/HuffmanTree.cpp obj/HuffmanNode.o include/HuffmanNode.h | obj
	g++ -c -o obj/HuffmanTree.o $(CFLAGS) src/HuffmanTree.cpp

obj/HuffmanNode.o: src/HuffmanNode.cpp | obj
	g++ -c -o obj/HuffmanNode.o $(CFLAGS) src/HuffmanNode.cpp

obj/CLI.o: src/CLI.cpp obj/HuffmanArchiver.o include/HuffmanArchiver.h | obj
	g++ -c -o obj/CLI.o $(CFLAGS) src/CLI.cpp

obj/CLIException.o: src/CLIException.cpp include/CLIException.h | obj
	g++ -c -o obj/CLIException.o $(CFLAGS) src/CLIException.cpp

obj/TestHuffmanNode.o: test/TestHuffmanNode.cpp src/HuffmanNode.cpp include/HuffmanNode.h | obj
	g++ -c -o obj/TestHuffmanNode.o $(CFLAGS) test/TestHuffmanNode.cpp

obj/TestHuffmanTree.o: test/TestHuffmanTree.cpp src/HuffmanTree.cpp include/HuffmanTree.h | obj
	g++ -c -o obj/TestHuffmanTree.o $(CFLAGS) test/TestHuffmanTree.cpp

obj/TestHuffmanArchiver.o: test/TestHuffmanArchiver.cpp src/HuffmanArchiver.cpp include/HuffmanArchiver.h | obj
	g++ -c -o obj/TestHuffmanArchiver.o $(CFLAGS) test/TestHuffmanArchiver.cpp

obj/TestMain.o: test/TestMain.cpp test/TestHuffmanNode.cpp test/TestHuffmanTree.cpp test/TestHuffmanArchiver.cpp | obj
	g++ -c -o obj/TestMain.o $(CFLAGS) test/TestMain.cpp

clean:
	rm -rf HuffmanArchiver obj test_HuffmanArchiver