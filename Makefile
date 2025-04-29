CFLAGS = -Wall -c

src_dir = ./src/
obj_dir = ./obj/

vpath %.cpp $(src_dir)
vpath %.o $(obj_dir)

modules = simulator

objs =$(addprefix $(obj_dir), $(addsuffix .o, $(modules)))

all: simulator

simulator: $(objs)
	$(CXX) $(LDFLAGS) $^ -o $@

$(obj_dir)%.o: %.cpp
	$(CXX) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f assembler
	rm -f $(obj_dir)*
