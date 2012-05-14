CC_HOST = g++
CC_TARGET = bfin-uclinux-g++

CCFLAG_T = -Wall -c -Ihilaris/oscar/includes -Ihilaris/includes -DOSC_TARGET -02
CCFLAG_H = -Wall -c -m32 -Ihilaris/oscar/includes -Ihilaris/includes -DOSC_HOST

AR_HOST := ar -rcs
AR_TARGET := bfin-uclinux-ar -rcs

BUILD = hilaris/build/
LIBRARY = app/library/
BINARY = app/

OSCAR_HOST_LIB = hilaris/oscar/library/libosc_host.a
OSCAR_OVERLAY_HOST_LIB = hilaris/oscar/library/libosc_overlay_host.a
OSCAR_TARGET_LIB = hilaris/oscar/library/libosc_target.a
OSCAR_OVERLAY_TARGET_LIB = hilaris/oscar/library/libosc_overlay_target.a

SOURCES    := $(patsubst hilaris/%.cpp,%,$(wildcard hilaris/*.cpp)) 
PROCESSORS := $(patsubst hilaris/processors/%.cpp,%,$(wildcard hilaris/processors/*.cpp))
DEBAYER    := $(patsubst hilaris/debayer/%.cpp,%,$(wildcard hilaris/debayer/*.cpp))
DRAWABLES  := $(patsubst hilaris/drawables/%.cpp,%,$(wildcard hilaris/drawables/*.cpp))
IMAGES     := $(patsubst hilaris/images/%.cpp,%,$(wildcard hilaris/images/*.cpp))

all: host target test
notest: host target

host: $(addsuffix .o, $(addprefix hilaris/build/host_, $(SOURCES))) $(addsuffix .o, $(addprefix hilaris/build/processors/host_, $(PROCESSORS))) $(addsuffix .o, $(addprefix hilaris/build/debayer/host_, $(DEBAYER))) $(addsuffix .o, $(addprefix hilaris/build/drawables/host_, $(DRAWABLES))) $(addsuffix .o, $(addprefix hilaris/build/images/host_, $(IMAGES)))
	$(AR_HOST) $(addsuffix libhilaris_host.a, $(LIBRARY)) $^
	@ mkdir -p app/includes
	@ mkdir -p app/includes/oscar
	@ cp -R hilaris/includes/* app/includes/
	@ cp -R hilaris/oscar/includes/* app/includes/oscar/
	@ cp $(OSCAR_HOST_LIB) app/library/
	@ cp $(OSCAR_OVERLAY_HOST_LIB) app/library/

target: $(addsuffix .o, $(addprefix hilaris/build/target_, $(SOURCES))) $(addsuffix .o, $(addprefix hilaris/build/processors/target_, $(PROCESSORS))) $(addsuffix .o, $(addprefix hilaris/build/debayer/target_, $(DEBAYER))) $(addsuffix .o, $(addprefix hilaris/build/drawables/target_, $(DRAWABLES))) $(addsuffix .o, $(addprefix hilaris/build/images/target_, $(IMAGES)))
	$(AR_TARGET) $(addsuffix libhilaris_target.a, $(LIBRARY)) $^
	@ mkdir -p app/includes
	@ mkdir -p app/includes/oscar
	@ cp -R hilaris/includes/* app/includes/
	@ cp -R hilaris/oscar/includes/* app/includes/oscar/
	@ cp $(OSCAR_TARGET_LIB) app/library/
	@ cp $(OSCAR_OVERLAY_TARGET_LIB) app/library/

test: 
	make -C hilaris/tests -f Makefile
	./hilaris/tests/test

doc:
	doxygen

docs:
	doxygen
	
#building sources
hilaris/build/target_%.o: hilaris/%.cpp
	$(CC_TARGET) $(CCFLAG_T) $? -o $@
	
hilaris/build/host_%.o: hilaris/%.cpp
	$(CC_HOST) $(CCFLAG_H) $? -o $@
	
#building images
hilaris/build/images/target_%.o: hilaris/images/%.cpp
	$(CC_TARGET) $(CCFLAG_T) $? -o $@
	
hilaris/build/images/host_%.o: hilaris/images/%.cpp
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

#builing drawables
hilaris/build/drawables/target_%.o: hilaris/drawables/%.cpp
	$(CC_TARGET) $(CCFLAG_T) $? -o $@
	
hilaris/build/drawables/host_%.o: hilaris/drawables/%.cpp
	$(CC_HOST) $(CCFLAG_H) $? -o $@

clean:
	rm -f $(BUILD)*.o $(BUILD)debayer/*.o $(BUILD)processors/*.o $(BUILD)drawables/*.o $(BUILD)images/*.o
	rm -f $(LIBRARY)*


