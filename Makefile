# the compiler: gcc for C program
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# the build target executable:
TARGET = transform

# build an executable named transform from transform.c
all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object files
clean:
	$(RM) $(TARGET)
