CFLAGS = -Wall -c

test_ldflags = $(LDFLAGS) -L /usr/local/lib/ -Wl,-Bstatic -lgtest -Wl,-Bdynamic

src_dir = ./src/
obj_dir = ./obj/
test_dir = ./test/

gtestlib_dir=/usr/local/lib/

vpath test%.cpp $(test_dir)
vpath %.cpp $(src_dir)
vpath %.o $(obj_dir)

program = simulator
modules = memorymanagementunit

test_runner = test$(program)
test_modules = $(addprefix test, $(modules))

objs =$(addprefix $(obj_dir), $(addsuffix .o, $(modules)))
test_objs =$(obj_dir)$(test_runner).o $(addprefix $(obj_dir), $(addsuffix .o, $(test_modules)))

all: $(program) test

$(program): $(obj_dir)$(program).o $(objs)
	$(CXX) $(LDFLAGS) $^ -o $@

$(test_runner): $(objs) $(test_objs)
	$(CXX) $(LDFLAGS) $^ -o $@ $(gtestlib_dir)libgtest.a 

$(obj_dir)%.o: %.cpp
	$(CXX) $(CFLAGS) $< -o $@

.PHONY: test
test: $(test_runner)
	./$(test_runner)

.PHONY: clean
clean:
	rm -f assembler
	rm -f $(obj_dir)*
