#ifndef TOKEN_TYPE_H
#define TOKEN_TYPE_H

typedef enum {
    END_FILE,
    OPEN_TAG,
    CLOSE_TAG,
    WORD,
    NUMBER,
    APOSTROPHIZED,
    HYPHENATED,
    PUNCTUATION,
    NEW_LINE
} TOKEN;

#endif