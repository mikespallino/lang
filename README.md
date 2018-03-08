# lang

This is a repo for my work on developing a language. Most of the begining will be me going back through [Language Implementation Patterns by Terrance Parr](https://pragprog.com/book/tpdsl/language-implementation-patterns). I'm currently writing this in C++ to refresh my brain and learn more about implementing software in C++.

Current progress is an LL(1) Recursive-Descent Parser for the following grammar:
```
list     : '[' elements ']' ;
elements : element (',' element)* ;
element  : NAME | list ;
NAME     : ([a-zA-Z]+)+ ;
WS       : ([\ \t\r\n]+)+ ;
```

## Dependencies
* [CppUnit](https://freedesktop.org/wiki/Software/cppunit/)

## Building
```
make
```

## Tests
```
make test_lang
```

## Usage
```
./lang '[a, b]'
./lang '[asdf,sdf,[ert,sdf],dfs]'
./lang '[asdf,]'
./lang '341'
```
