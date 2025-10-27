#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_TOKEN_LENGTH 100
#define MAX_NUM_TOKENS 100
#define MAX_SOURCE_LENGTH 1024

typedef enum {
    TOKEN_KEYWORD,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_UNKNOWN
} TokenType;

typedef struct {
    TokenType type;
    char value[MAX_TOKEN_LENGTH];
} Token;

const char *keywords[] = {"if", "else", "while", "return", "int", "float", "void", NULL};

int is_keyword(const char *word) {
    for (int i = 0; keywords[i] != NULL; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void add_token(Token *tokens, int *token_count, TokenType type, const char *value) {
    tokens[*token_count].type = type;
    strncpy(tokens[*token_count].value, value, MAX_TOKEN_LENGTH);
    (*token_count)++;
}

void lex(const char *source, Token *tokens, int *token_count) {
    char current_token[MAX_TOKEN_LENGTH];
    int index = 0;

    for (int i = 0; source[i] != '\0'; i++) {
        if (isspace(source[i])) {
            if (index > 0) {
                current_token[index] = '\0';
                if (is_keyword(current_token)) {
                    add_token(tokens, token_count, TOKEN_KEYWORD, current_token);
                } else if (isdigit(current_token[0])) {
                    add_token(tokens, token_count, TOKEN_NUMBER, current_token);
                } else {
                    add_token(tokens, token_count, TOKEN_IDENTIFIER, current_token);
                }
                index = 0;
            }
        } else if (isalpha(source[i]) || source[i] == '_') {
            current_token[index++] = source[i];
        } else if (isdigit(source[i])) {
            current_token[index++] = source[i];
        } else {
            if (index > 0) {
                current_token[index] = '\0';
                if (is_keyword(current_token)) {
                    add_token(tokens, token_count, TOKEN_KEYWORD, current_token);
                } else if (isdigit(current_token[0])) {
                    add_token(tokens, token_count, TOKEN_NUMBER, current_token);
                } else {
                    add_token(tokens, token_count, TOKEN_IDENTIFIER, current_token);
                }
                index = 0;
            }
            current_token[0] = source[i];
            current_token[1] = '\0';
            add_token(tokens, token_count, TOKEN_OPERATOR, current_token);
        }
    }

    if (index > 0) {
        current_token[index] = '\0';
        if (is_keyword(current_token)) {
            add_token(tokens, token_count, TOKEN_KEYWORD, current_token);
        } else if (isdigit(current_token[0])) {
            add_token(tokens, token_count, TOKEN_NUMBER, current_token);
        } else {
            add_token(tokens, token_count, TOKEN_IDENTIFIER, current_token);
        }
    }
}

void print_tokens(Token *tokens, int token_count) {
    for (int i = 0; i < token_count; i++) {
        const char *type;
        switch (tokens[i].type) {
            case TOKEN_KEYWORD: type = "KEYWORD"; break;
            case TOKEN_IDENTIFIER: type = "IDENTIFIER"; break;
            case TOKEN_NUMBER: type = "NUMBER"; break;
            case TOKEN_OPERATOR: type = "OPERATOR"; break;
            default: type = "UNKNOWN"; break;
        }
        printf("Token Type: %s\t, Value: %s\n", type, tokens[i].value);
    }
}

int main() {
    char source_code[MAX_SOURCE_LENGTH];
    Token tokens[MAX_NUM_TOKENS];
    int token_count = 0;

    printf("Enter source code (end with a blank line):\n");

    // Read multiple lines of input until a blank line is entered
    while (1) {
        fgets(source_code, MAX_SOURCE_LENGTH, stdin);
        if (strcmp(source_code, "\n") == 0) {
            break;
        }
        lex(source_code, tokens, &token_count);
    }

    print_tokens(tokens, token_count);

    return 0;
}
