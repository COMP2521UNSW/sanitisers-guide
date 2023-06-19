[Back to glossary](..)

# use-of-uninitialized-value

Hopefully it's clear that `use-of-uninitialized-value` occurs when you try to use uninitialised values.

This can happen when you declare a variable/allocate memory but never assign a value to it before using it for something.

**Note**: This error only appears if compiled with MSan (which is usually disabled in favour of ASan for most tasks). See how to switch [here](../../sanitisers#switching-between-sanitisers).

## Reading the error message

This is a typical `use-of-uninitialized-value` message:

![img.png](uninitialised-idx/error.png)

Here is the useful information you can get from this error message:

### Error Location
The first stack trace describes where (which line/function/file) the error occurred.

### Origin of Uninitialised Value
The other stack traces tell you where the uninitialised value originated.

**Note**: Origins are only shown if compiled with `-fsanitize-memory-track-origins`

#### Created by...
This stack trace shows where (which line/function/file) the memory/variable was initially created.

#### Stored to memory at...
There may be one or more stack traces that track each place (line/function/file) the uninitialised value was stored into a variable before it was finally used.

## Examples

- [Uninitialised pointer](uninitialised-ptr)
- [Uninitialised index](uninitialised-idx)
- [Accessing unused array elements](unused-elements)
