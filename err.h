 #ifndef ERR_LIB_H
 #define ERR_LIB_H

 #include <errno.h>
 #include <string.h>

 /*
 * Result - Error code enum for return values
 */

typedef enum {
    OK,
    ERR_NULL_POINTER,
    ERR_DIV_ZERO,
    ERR_OUT_OF_RANGE,
    ERR_OVERFLOW,
    ERR_UNDERFLOW,
    ERR_INVALID_ARG,

    ERR_ALLOC_FAILED,
    ERR_FILE_NOT_FOUND,
    ERR_PERMISSION_DENIED,
    ERR_IO,
    ERR_SYSTEM, // Used together with errno 
    ERR_MISC // Generic error for prototyping
} Result;

 #define IS_OK(r) ((r) == OK)
 #define IS_ERR(r) ((r) != OK)

 // Returns human readable text from passed Result r
static const char *string_err(Result r) {
    switch(r) {
        case OK: return "Ok";
        case ERR_NULL_POINTER: return "Null pointer error";
        case ERR_DIV_ZERO: return "Division by zero error";
        case ERR_OUT_OF_RANGE: return "Out of range error";
        case ERR_OVERFLOW: return "Overflow error";
        case ERR_UNDERFLOW: return "Underflow error";
        case ERR_INVALID_ARG: return "Invalid argument error";
        case ERR_ALLOC_FAILED: return "Out of memory error";
        case ERR_FILE_NOT_FOUND: return "File not found error";
        case ERR_PERMISSION_DENIED: return "Permission denied error";
        case ERR_IO: return "I/O error";
        case ERR_SYSTEM: return strerror(errno);
        case ERR_MISC: return "Miscellaneous error";
        default: return "Unknown error";
    }
}

 #endif