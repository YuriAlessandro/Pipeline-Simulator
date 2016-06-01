# ----------------------
# MACROS
# ----------------------

# DIRS
INCDIR = include
BINDIR = bin
SRCDIR = src
BUILDDIR = build
LIBDIR = lib
# LIB OPTIONS
# TARGET
TARGET = $(BINDIR)/drive_pipeline
# EXTENSIONS
SRCEXT = cpp
HEADEREXT = h
# SOURCES LIST
SOURCES = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
# OBJECTS
OBJS = $(patsubst $(SRCDIR)/%, $(BUILDDIR)/%, $(SOURCES:.$(SRCEXT)=.o))  
# COMPILER
CC = g++ 
# FOR CLEANING
RM = /bin/rm
# WARNING FLAG
# WARN = -Wall
# DEBUG FLAGS
DEBUG = -g
# LINKING FLAGS
#LIBOPTS = -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
#LIBFLAG = -L $(LIBDIR) $(LIBOPTS)
INCFLAG = -I $(INCDIR)
LFLAGS = $(DEBUG) $(WARN) $(INCFLAG) 
#$(LIBFLAG)
# COMPILATION FLAGS
CFLAGS = $(DEBUG) -c $(WARN) -std=c++11

# ----------------------
# ENTRIES
# ----------------------

$(TARGET): $(OBJS)
	@echo "Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LFLAGS)"; $(CC) $^ -o $(TARGET) $(LFLAGS)
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INCFLAG) -o $@ $<"; $(CC) $(CFLAGS) $(INCFLAG) -o $@ $<	

# DUMMY ENTRIES
clean:
	@echo "Cleaning..."
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

.PHONY: clean

