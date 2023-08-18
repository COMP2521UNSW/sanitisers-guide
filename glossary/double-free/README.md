[Back to glossary](..)

# attempted double-free

An `attempted double-free` occurs when you try to free memory that has already been freed.

This can easily happen on accident, especially in complicated functions with many if/else cases where some cases require freeing memory and others don't. We might accidentally double up on a free in some case.

Another potential cause is storing the same data in two parallel data structures. It might be useful to store two versions of the same data in different representations for optimisation reasons, where certain operations would be relatively cheap in one operation compared to the other. However, this can complicate freeing if both data structures try to free the data they hold.

## Reading the error message

This is a typical `attempted double-free` message:

![img.png](simple/error.png)

Here is the useful information you can get from this error message:

### Error Location
The first stack trace describes where (which line/function/file) the error occurred i.e. where we tried to access the memory. See [here](../../errmsg#stack-traces) for a guide on reading stack traces.

### Free Location
The second stack trace below `freed by...` describes where (which line/function/file) the memory we tried to free was first freed. See [here](../../errmsg#stack-traces) for a guide on reading stack traces.

### Initial Allocation Location

The third stack trace below `previously allocated by...` describes where (which line/function/file) the memory we tried to access was initially allocated. See [here](../../errmsg#stack-traces) for a guide on reading stack traces.

## Examples

- [Simple](simple)
- [Parallel data structures](parallel)
