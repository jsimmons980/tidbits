all: info cmeCodeGen libtinyxml2.a

info :
	@echo "program to generate c-structs from cme template file"

rebuild: clean all

cmeCodeGen: cmedecoder.cpp libtinyxml2.a
	g++ -std=c++14 -ggdb cmedecoder.cpp -L./ -l tinyxml2 -o $@

clean:
	$(RM) *.o cmeCodeGen libtinyxml2.a
	
run: all
	./cmeCodeGen templates_FixBinary.xml

libtinyxml2.a: tinyxml2.o
	$(AR) $(ARFLAGS)s $@ $^
	
tinyxml2.o: tinyxml2-master/tinyxml2.cpp tinyxml2-master/tinyxml2.h
	g++ -std=c++14 -ggdb -c tinyxml2-master/tinyxml2.cpp -o $@
