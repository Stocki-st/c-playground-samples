
# Tokenizer Program

## Description
This program tokenizes a character input stream based on the following rules:
1. Tokens are delimited by the `#` character.
2. Tokens are limited to a maximum length of `MAX_TOKEN_SIZE` (default: 20).

The tokens are pushed to a message queue and printed asynchronously by a separate thread.

## Features
- Tokenizes input based on the delimiter `#` or `MAX_TOKEN_SIZE`.
- Utilizes POSIX message queues for inter-thread communication.
- Multithreaded implementation using pthreads.

## Requirements
- GCC
- POSIX-compliant system
- Message Queue support (`<mqueue.h>`)

## Usage
1. Compile the program:
   ```bash
   make
   ```

2. Run the program:
   ```bash
   ./tokenizer
   ```

3. Enter a stream of characters when prompted (e.g., `hello#world#this#is#a#test`).

4. The tokens will be printed asynchronously by the program.

5. Clean up the build:
   ```bash
   make clean
   ```

## File Structure
- `tokenizer.c`: Main program source code.
- `Makefile`: Build script.
- `README.md`: Project documentation.

## Notes
- Ensure `/dev/mqueue` is accessible and writable.
- The message queue is cleaned up automatically after execution.
