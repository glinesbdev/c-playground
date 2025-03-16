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
