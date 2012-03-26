
CC_HOST = g++
CC_TARGET = bfin-uclinux-g++

CCFLAG_T = -Wall -c -Ihilaris/oscar/include -Ihilaris/includes -DOSC_TARGET
CCFLAG_H = -Wall -c -Ihilaris/oscar/include -Ihilaris/includes -DOSC_HOST

AR_HOST := ar -rcs
AR_TARGET := bfin-uclinux-ar -rcs

BUILD = hilaris/build/
LIBRARY = app/library/
BINARY = app/

OSCAR_HOST_LIB = hilaris/oscar/library/libosc_host.a
OSCAR_TARGET_LIB = hilaris/oscar/library/libosc_target.a

SOURCES := $(patsubst hilaris/%.cpp,%,$(wildcard hilaris/*.cpp))

all: host target

host: $(addsuffix .o, $(addprefix hilaris/build/host_, $(SOURCES)))
	$(AR_HOST) $(addsuffix libhilaris_host.a, $(LIBRARY)) $^
	@ mkdir -p app/includes
	@ mkdir -p app/includes/oscar
	@ cp -R hilaris/includes/* app/includes/
	@ cp -R hilaris/oscar/include/* app/includes/oscar/
	@ cp $(OSCAR_HOST_LIB) app/library/

target: $(addsuffix .o, $(addprefix hilaris/build/target_, $(SOURCES)))
	$(AR_TARGET) $(addsuffix libhilaris_target.a, $(LIBRARY)) $^
	@ mkdir -p app/includes
	@ mkdir -p app/includes/oscar
	@ cp -R hilaris/includes/* app/includes/
	@ cp -R hilaris/oscar/include/* app/includes/oscar/
	@ cp $(OSCAR_TARGET_LIB) app/library/
	
hilaris/build/target_%.o: hilaris/%.cpp
	$(CC_TARGET) $(CCFLAG_T) $? -o $@
	
hilaris/build/host_%.o: hilaris/%.cpp
	$(CC_HOST) $(CCFLAG_H) $? -o $@

clean:
	rm -f $(BUILD)*
	rm -f $(LIBRARY)*


