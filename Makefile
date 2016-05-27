AT:=@
CXXFLAGS:=-std=c++14 -I/usr/local/crpcut/include -I$(HOME)/srcdl/trompeloeil -I.
LDFLAGS:=-L/usr/local/crpcut/lib64 -lcrpcut -ldl
LD:=g++

BINS:=exempel

SRCS:=test/main.cpp
SRCS+=test/simple_test.cpp
SRCS+=test/fixt.cpp test/mocking.cpp test/mock_free.cpp
SRCS+=sut/myclass.cpp
SRCS+=sut/extuser.cpp

OBJS:=$(addprefix .obj/,$(SRCS:.cpp=.o))

all: $(BINS)

$(BINS): %: $(OBJS)
	@echo '  [LD]' $@
	$(AT)$(LD) $(LDFLAGS) -o $@ $^

$(OBJS): .obj/%.o: %.cpp
	@echo ' [C++]' $<
	@mkdir -p $(dir $@)
	$(AT)$(CXX) $(CXXFLAGS) -MMD -c -o $@ $<

-include $(OBJS:.o=.d)

clean:
	$(AT)rm -rf .obj $(BINS)
