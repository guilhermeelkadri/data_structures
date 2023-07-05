
SRCDIR = src
INCDIR = inc
OBJDIR = obj
BINDIR = bin

CC = g++
CFLAGS = -Wall -Wextra -I$(INCDIR)

EXECUTABLE = $(BINDIR)/heap_program

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

.PHONY: all clean

define print_vars
	@echo '$$@ = $(1)'
	@echo '$$^ = $(2)'
	@echo '$$< = $(3)'
	@echo '$$% = $(4)'
	@echo '$$? = $(5)'
endef

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $@
	@echo 'Turning %.o into $@'
	$(call print_vars, $@, $^, $<, $%, $?)
	@echo '$(CC) $(CCFLAGS) $^ -o $@'

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo 'Turning %.cpp into $@'
	$(call print_vars, $@, $^, $<, $%, $?)
	@echo '$(CC) $(CCFLAGS) $^ -o $@'

clean:
	rm -rf $(OBJDIR) $(BINDIR)