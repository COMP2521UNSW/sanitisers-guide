[Back to top](..)

# About Sanitisers
- [What is a sanitiser?](#what-is-a-sanitiser)
  - [Error Reporting](#error-reporting)
  - [Error Checking](#error-checking)
- [What sanitisers are there?](#what-sanitisers-are-there)
- [How do I use sanitisers?](#how-do-i-use-sanitisers)
  - [Switching between sanitisers](#switching-between-sanitisers)

## What is a sanitiser?

Sanitisers are tools you can compile along with your code to add additional error checking and reporting.

### Error Reporting

Their most important use is giving detailed error messages to aid debugging. Consider the following C program which dereferences a NULL pointer:
```c
int main(void) {
    int *ptr = NULL;
    printf("%d\n", *ptr);
}
```

If we compile and run this program without sanitisers, you will get the following output, which is not very helpful:

![Segmentation fault](segfault.png)

However, with sanitisers included, we get the following much more helpful output that tells us exactly what went wrong and where:

![Sanitiser error](sanerr1.png)

### Error Checking

Sanitisers can also reveal errors that may have gone unnoticed otherwise and help keep your code bug free. For example, consider this C program that accesses an array after it has been freed:

```c
int main(void) {
    int *a = calloc(100, sizeof(int));
    free(a);
    printf("%d\n", a[5]);
}
```

If we compile and run this program without sanitisers, this will run without issues:

![Runs successfully and prints 0](invalid.png)

However, we know accessing memory after it has been freed is invalid, and our sanitisers can catch this error:

![img.png](sanerr2.png)

Now, a keen eye might notice that running `./prog2` without sanitisers does exactly what we would expect it to do. We allocate an array of zeroes with `calloc()`, then printed an element of this array, which output a 0 - so what's the problem?

Well, what happens when you access freed memory is **undefined behaviour**. Sometimes doing so will work (like it does here), and other times it won't (depending on factors such as the state of the program, the compiler used, the operating system run on etc.). Ideally, we want our program to run correctly *every* time, so we want to avoid doing things that result in undefined behaviour. This is why the sanitisers throw errors when you try to do so.

## What sanitisers are there?

* **AddressSanitizer** or **ASan** is for catching various memory errors such as accessing unallocated memory. A full list of checks can be found [here](https://clang.llvm.org/docs/AddressSanitizer.html#introduction). You can use it with `-fsanitize=address`.
* **LeakSanitizer** or **LSan** is for catching memory leaks. You can use it with `-fsanitize=leak`.
* **MemorySanitizer** or **MSan** is for detecting reads of uninitialised memory - that is, trying to read memory before it is written. You can use it with `-fsanitize=memory`.
  * If you would like MSan to also output where the uninitialised memory originated, you can add the `-fsanitize-memory-track-origins` flag.
* **UndefinedBehaviorSanitizer** or **UBSan** is for catching various kinds of undefined behavior such as dividing by zero. A full list of checks can be found [here](https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html#ubsan-checks). You can use it with `-fsanitize=undefined`.

## How do I use sanitisers?

To compile your code with sanitizers, you need to the add `-fsanitize` flag to your compilation command. In order for line numbers to be displayed in the errors, you will also need the `-g` flag. Most of the Makefiles we provide already have these flag added for you.

For example, to compile with ASan, LSan and UBSan you would do something like

```
clang -g -fsanitize=address,leak,undefined -o myProgram myProgram.c
```

As shown above, multiple sanitisers are chained together with commas.

**Note:** If you're working locally on a Mac you may get an error when trying to compile with LeakSanitizer as it is not installed by default. Please follow [these steps](https://stackoverflow.com/a/55778432) to install it. There is no way to use MemorySanitizer on Mac.

### Switching between sanitisers

Some sanitisers are not compatible with each other. Specifically, MSan is incompatible with ASan and LSan, so to check for the entire range of errors you would need to compile once with ASan and LSan (and UBSan), and compile again with MSan. You might also want to switch to MSan to get more helpful errors in some cases.

To switch between sanitisers, you will need to change which sanitisers are used in the compilation command.

For example,
```
clang ... -fsanitize=address,leak,undefined ...
```
currently uses ASan and LSan. To switch to MSan, change it to
```
clang ... -fsanitize=memory,undefined -fsanitize-memory-track-origins ...
```
and change it back to the original if you want to switch back.

Most Makefiles provided in the course will already have predefined options you can use, which look like this:
```makefile
########################################################################

asan: CFLAGS += -fsanitize=address,leak,undefined
asan: all

msan: CFLAGS += -fsanitize=memory,undefined -fsanitize-memory-track-origins
msan: all

nosan: all

########################################################################
```
To use these, you can use either
- `make asan` to compile with ASan, LSan and UBSan (this is also the default if you just write `make`)
- `make msan` to compile with MSan and UBSan
- `make nosan` to compile with no sanitisers

Make sure to run `make clean` before switching to another sanitiser, otherwise the program(s) will not be recompiled.

A full example Makefile can be found [here](./make).
