# Circular Queue

A circular queue implementation in C.

## Table of Contents

- [Circular Queue](#circular-queue)
  - [Table of Contents](#table-of-contents)
  - [Description](#description)
  - [Usage](#usage)
  - [Building and Testing](#building-and-testing)
  - [Contributing](#contributing)

## Description

This project provides a circular queue implementation in C. A circular queue, also known as a ring buffer, is a data structure that follows the FIFO (First In, First Out) principle. It has a fixed size and efficiently handles inserting and removing elements from both ends of the queue.

The circular queue is implemented using a struct called `Queue`, which contains control variables, function pointers, and data events. The `createQueue` function is provided to create a new instance of the queue.

## Usage

To use the circular queue in your C project, follow these steps:

1. Clone the repository or download the `circular_queue.c` and `circular_queue.h` files.
2. Include the `circular_queue.h` header file in your C source file.
3. Implement your application logic using the circular queue functions.
4. Compile and run your program.

## Building and Testing

This project uses CMake as the build system and provides an example CMakeLists.txt file.

To build and test the circular queue, follow these steps:

1. Install CMake and a C compiler if you haven't already.
2. Create a new directory for the build files: `mkdir build && cd build`
3. Generate the build files with CMake: `cmake ..`
4. Build the project: `cmake --build .`
5. Run the tests: `ctest`

The provided CMakeLists.txt file includes a test that performs memory analysis using either Intel Inspector or Valgrind, depending on the operating system. Make sure to have the corresponding tools installed to run the memory analysis.

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.
