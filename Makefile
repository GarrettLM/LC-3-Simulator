CFLAGS = -Wall -c

src_dir = ./src/
obj_dir = ./obj/
test_dir = ./test/

vpath Test%.cpp $(test_dir)
vpath %.cpp $(src_dir)
vpath %.o $(obj_dir)

modules = simulator memorymanagementunit
test_modules = $(addprefix Test, $(modules))

objs =$(addprefix $(obj_dir), $(addsuffix .o, $(modules)))
test_objs = $(addprefix $(obj_dir), $(addsuffix .o, $(test_modules)))

all: simulator

simulator: $(objs)
	$(CXX) $(LDFLAGS) $^ -o $@

$(obj_dir)%.o: %.cpp
	$(CXX) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f assembler
	rm -f $(obj_dir)*
