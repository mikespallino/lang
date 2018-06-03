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

## LLVM

I've recently started going through the LLVM tutorial on implementing a language [here](http://releases.llvm.org/6.0.0/docs/tutorial/index.html#kaleidoscope-implementing-a-language-with-llvm). The LLVM folder will be updated as I go through the sections. The code in there is up to the end of chapter 3.

Build that with the following:
```
clang++ -g -O3 kaleidoscope.cpp `llvm-config --cxxflags --ldflags --system-libs --libs core` -o kaleidoscope
```
