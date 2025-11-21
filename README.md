# C Lexical Analyzer

A simple lexical analyzer implemented in **C**, capable of scanning a given source program and breaking it into tokens such as **keywords, identifiers, numbers, and operators**.  
This project was developed as part of an academic assignment and demonstrates the fundamentals of lexical analysis used in compiler design. 

---

## 🚀 Features

- Identifies common C-language **keywords**
- Detects **identifiers**, **numbers**, and **operators**
- Handles multi-line input until a blank line is encountered
- Prints token type + value in a readable format
- Works on simple C-like code fragments

---

## 🧠 How It Works

The analyzer scans the input source code one character at a time and forms tokens based on:

- Alphabet/underscore sequences → Identifiers / Keywords
- Digit sequences → Numbers
- Any other single character → Operators
- Whitespace acts as a delimiter

Token categories are defined using an enum:

- `TOKEN_KEYWORD`
- `TOKEN_IDENTIFIER`
- `TOKEN_NUMBER`
- `TOKEN_OPERATOR`
- `TOKEN_UNKNOWN`

(Refer to the full implementation for exact logic.)

---

## 📝 Supported Keywords

The following keywords are recognized:

int, float, void, if, else, while, return

---

## 📌 Sample Input

```c
int main()
{
    int a=1, b=2, c;
    c = a + b;
}
```

---

## 📌 Sample Output

```
Token Type: KEYWORD     , Value: int
Token Type: IDENTIFIER  , Value: main
Token Type: OPERATOR    , Value: (
Token Type: OPERATOR    , Value: )
Token Type: OPERATOR    , Value: {
Token Type: KEYWORD     , Value: int
Token Type: IDENTIFIER  , Value: a
Token Type: OPERATOR    , Value: =
Token Type: NUMBER      , Value: 1
Token Type: OPERATOR    , Value: ,
Token Type: IDENTIFIER  , Value: b
Token Type: OPERATOR    , Value: =
Token Type: NUMBER      , Value: 2
Token Type: OPERATOR    , Value: ,
Token Type: IDENTIFIER  , Value: c
Token Type: OPERATOR    , Value: ;
Token Type: IDENTIFIER  , Value: c
Token Type: OPERATOR    , Value: =
Token Type: IDENTIFIER  , Value: a
Token Type: OPERATOR    , Value: +
Token Type: IDENTIFIER  , Value: b
Token Type: OPERATOR    , Value: ;
Token Type: OPERATOR    , Value: }
```

---

## 📂 File Structure

```
/C-Lexical-Analyzer

│── lexical_analyzer.c

│__ README.md
```

---

## ▶️ Compilation & Usage

Compile and Run on IDE like Code blocks

or Using the Command Prompt

```
gcc lexical_analyzer.c -o lex
./lex
```
---
