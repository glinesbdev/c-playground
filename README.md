# C Language Playground

This project is a playground for learning more about the C language, data structues, and algorithms. Building a debug build with the `make` command will produce a `./bin/debug/reverse` binary. Building for release is similar: `make release`, which will build a binary into `./bin/release/reverse`. This little tool will reverse any number of arguments for you.
All the code can be found in the `src` directory.

You'll notice that this code is suspiciously free from using C's standard library -- and that's on purpose! Besides using `malloc` and `free`, this code aims to do everything on its own; for learning!

## Running Tests

The tests use the `Unity` testing framework. It's included as a git submodule for this project run the following command to pull it down.

```bash
git clone --recurse-submodules
```

To run the tests, you can run the `make run_tests` command to build and run the test suite.

## Memory Checks

```bash
# ./memcheck.txt

==79310== Memcheck, a memory error detector
==79310== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==79310== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==79310== Command: ./tests/bin/tests
==79310== Parent PID: 61748
==79310== 
==79310== 
==79310== HEAP SUMMARY:
==79310==     in use at exit: 0 bytes in 0 blocks
==79310==   total heap usage: 28 allocs, 28 frees, 1,499 bytes allocated
==79310== 
==79310== All heap blocks were freed -- no leaks are possible
==79310== 
==79310== For lists of detected and suppressed errors, rerun with: -s
==79310== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```
