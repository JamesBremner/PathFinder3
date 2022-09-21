#source file search paths
VPATH = ./src 

	# compiler include search paths
INCS = -I./include \
	-I../ravencode/pub/src \
	-I../raven-set \
	-I../boost/boost1_78 

LIBS = \
	-lgdiplus -lgdi32 -lcomdlg32 -lstdc++fs \
	-L../boost/boost1_78/lib \
		-lboost_system-mgw11-mt-x64-1_78 \
		-lboost_program_options-mgw11-mt-x64-1_78 \
		# -lboost_thread-mgw11-mt-x64-1_7 \
	#-mwindows

static_link_flags = -static-libstdc++ -static-libgcc -static

# folders
ODIR = ./.vscode/obj
RDIR = ../ravencode/pub/src

OPT = -g
CCflags = -std=c++17 $(OPT) -D_mingw_

# sources
OBJ_pathtest = \
	$(ODIR)/pathtest.o \
	 $(ODIR)/cPathFinder.o $(ODIR)/cPathFinderReader.o $(ODIR)/cGraph.o \
	 $(ODIR)/cMaze.o $(ODIR)/Karger.o \
	 $(ODIR)/cRunWatch.o

OBJ_pathgui = \
	$(ODIR)/pathgui.o \
	 $(ODIR)/cPathFinder.o $(ODIR)/cPathFinderReader.o $(ODIR)/cGraph.o \
	 $(ODIR)/cMaze.o $(ODIR)/cRunWatch.o

### COMPILE

$(ODIR)/cRunWatch.o :
	g++ -o $@ -c ../raven-set/cRunWatch.cpp \
	$(INCS) $(CCflags) 

$(ODIR)/%.o: %.cpp cGraph.h
	g++  $(CCflags) \
	-c -o $@ $< $(INCS)

pathtest: $(OBJ_pathtest)
	g++ $(OPT) \
	-o bin/pathtest.exe $^  \
	$(static_link_flags) $(LIBS)

pathgui: $(OBJ_pathgui)
	g++ $(OPT) \
	-o bin/pathgui.exe $^  \
	$(static_link_flags) $(LIBS)

.PHONY: clean
clean:
	del /q .vscode\\obj\\*.o

