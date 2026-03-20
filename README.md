# err - Error Handling Library

A small library for error handling. Built by me as a small project to improve my programming skills.

## Features

- **Result enum** — Standardized error codes for common failure scenarios
- **Helper functions** — Convert error codes to human-readable messages
- **Convenience macros** — `IS_OK()` and `IS_ERR()` for quick status checks
- **errno integration** — Support for system errors via `ERR_SYSTEM`

## Error Codes

- `OK` — Successful operation
- `ERR_NULL_POINTER` — Null pointer passed where non-null expected
- `ERR_DIV_ZERO` — Division by zero
- `ERR_OUT_OF_RANGE` — Value outside acceptable range
- `ERR_OVERFLOW` / `ERR_UNDERFLOW` — Arithmetic overflow/underflow
- `ERR_INVALID_ARG` — Invalid function argument
- `ERR_ALLOC_FAILED` — Memory allocation failed
- `ERR_FILE_NOT_FOUND` — File not found
- `ERR_PERMISSION_DENIED` — Permission denied
- `ERR_IO` — I/O operation error
- `ERR_SYSTEM` — System error (check `errno`)
- `ERR_MISC` — Generic error for prototyping

## Usage

```c
#include "err.h" // <- library header
#include <stdio.h>
#include <limits.h> // <- needed for INT_MAX and INT_MIN

Result add(int x, int y, int *result) {
    if (!result) { 
        return ERR_NULL_POINTER; 
    }
    if (x > 0 && y > 0 && x > INT_MAX - y) { 
        return ERR_OVERFLOW; 
    }
    if (x > 0 && y > 0 && x < INT_MIN - y) { 
        return ERR_UNDERFLOW; 
    }
    *result = x + y;
    return OK;
}

int main(void) {
    int a = 5, b = 3, result;
    Result r = add(a, b, &result);
    
    if (IS_ERR(r)) {
        fprintf(stderr, "Error: %s\n", string_err(r));
        return 1;
    }
    
    printf("Result: %d\n", result);
    return 0;
}
```

## Building

```bash
gcc main.c -o main
./main
```
