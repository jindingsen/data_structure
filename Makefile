tree: tree.o
	gcc tree.o -o tree

recurse: recurse.o
	gcc recurse.o -o recurse

pos_test: pos_test.o
	gcc pos_test.o -o pos_test
tree_test: tree_test.o
	gcc tree_test.o -o tree_test
tree_test2: tree_test2.o
	gcc tree_test2.o -o tree_test2

recurse_test: recurse_test.o
	gcc recurse_test.o -o recurse_test
tree_test4: tree_test4.o
	gcc tree_test4.o -o tree_test4

%.o: %.c
	gcc -c $< -o $@

.PHONY: clean

clean: 
	rm *.o

