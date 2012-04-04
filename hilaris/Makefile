CC_HOST = g++
CC_TARGET = bfin-uclinux-g++

CCFLAG_T = -Wall -c -Ihilaris/oscar/includes -Ihilaris/includes -DOSC_TARGET
CCFLAG_H = -Wall -c -m32 -Ihilaris/oscar/includes -Ihilaris/includes -DOSC_HOST

AR_HOST := ar -rcs
AR_TARGET := bfin-uclinux-ar -rcs

BUILD = hilaris/build/
LIBRARY = app/library/
BINARY = app/

OSCAR_HOST_LIB = hilaris/oscar/library/libosc_host.a
OSCAR_TARGET_LIB = hilaris/oscar/library/libosc_target.a

SOURCES    := $(patsubst hilaris/%.cpp,%,$(wildcard hilaris/*.cpp)) 
PROCESSORS := $(patsubst hilaris/processors/%.cpp,%,$(wildcard hilaris/processors/*.cpp))
DEBAYER    := $(patsubst hilaris/debayer/%.cpp,%,$(wildcard hilaris/debayer/*.cpp))

all: host target test
notest: host target

host: $(addsuffix .o, $(addprefix hilaris/build/host_, $(SOURCES))) $(addsuffix .o, $(addprefix hilaris/build/processors/host_, $(PROCESSORS))) $(addsuffix .o, $(addprefix hilaris/build/debayer/host_, $(DEBAYER)))
	$(AR_HOST) $(addsuffix libhilaris_host.a, $(LIBRARY)) $^
	@ mkdir -p app/includes
	@ mkdir -p app/includes/oscar
	@ cp -R hilaris/includes/* app/includes/
	@ cp -R hilaris/oscar/includes/* app/includes/oscar/
	@ cp $(OSCAR_HOST_LIB) app/library/

target: $(addsuffix .o, $(addprefix hilaris/build/target_, $(SOURCES)))
	$(AR_TARGET) $(addsuffix libhilaris_target.a, $(LIBRARY)) $^
	@ mkdir -p app/includes
	@ mkdir -p app/includes/oscar
	@ cp -R hilaris/includes/* app/includes/
	@ cp -R hilaris/oscar/includes/* app/includes/oscar/
	@ cp $(OSCAR_TARGET_LIB) app/library/

test: 
	make -C hilaris/tests -f Makefile
	./hilaris/tests/test
	
#building sources
hilaris/build/target_%.o: hilaris/%.cpp
	$(CC_TARGET) $(CCFLAG_T) $? -o $@
	
hilaris/build/host_%.o: hilaris/%.cpp
	$(CC_HOST) $(CCFLAG_H) $? -o $@

#building debayer
hilaris/build/debayer/target_%.o: hilaris/debayer/%.cpp
	$(CC_TARGET) $(CCFLAG_T) $? -o $@
	
hilaris/build/debayer/host_%.o: hilaris/debayer/%.cpp
	$(CC_HOST) $(CCFLAG_H) $? -o $@

#builing processors
hilaris/build/processors/target_%.o: hilaris/processors/%.cpp
	$(CC_TARGET) $(CCFLAG_T) $? -o $@
	
hilaris/build/processors/host_%.o: hilaris/processors/%.cpp
	$(CC_HOST) $(CCFLAG_H) $? -o $@

clean:
	rm -f $(BUILD)/*.o $(BUILD)/debayer/*.o $(BUILD)/processors/*.o
	rm -f $(LIBRARY)*


