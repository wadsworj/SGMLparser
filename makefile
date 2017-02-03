
CC = g++
CFLAGS = -Iinclude -Itest_suite

OBJ_DIR = ./obj/
SRC_DIR = ./src/

OBJS = $(OBJ_DIR)lex.yy.o\
	   $(OBJ_DIR)scanner.o\
	   $(OBJ_DIR)tag.o\
	   $(OBJ_DIR)util.o

TEST_OBJS = $(OBJ_DIR)lex.yy.o\
			$(OBJ_DIR)test_scanner.o\
			$(OBJ_DIR)tag.o\
			$(OBJ_DIR)test.o\
			$(OBJ_DIR)util.o


scanner: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o scanner -ll

test: testSuite scanner

testSuite: $(TEST_OBJS)
	$(CC) $(CFLAGS) $(TEST_OBJS) -o testSuite -ll


lex.yy.c: $(SRC_DIR)parser.flex
	flex $(SRC_DIR)parser.flex

$(OBJ_DIR)lex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) lex.yy.c -c -ll -o $@

# Test Suite Options
$(OBJ_DIR)test.o: ./test_suite/test.cpp
	$(CC) $(CFLAGS) $< -c -o $@

$(OBJ_DIR)test_scanner.o:
	$(CC) -DTEST_SUITE $(CFLAGS) $(SRC_DIR)scanner.cpp -c -o $@


# General Object Target
$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm scanner lex.yy.c lex.yy.o $(OBJS)