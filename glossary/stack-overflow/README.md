[Back to glossary](..)

# stack-overflow

Everybody's favourite. A `stack-overflow` occurs when you have an infinite recursion. Every time a function is called, it gets pushed on to the "function call stack" and gets popped from the stack when it returns. The stack is only so large though, and if you're continuously call functions (push to the stack) without returning, you overflow the stack.

## Reading the error message

This is (the start of) a typical `stack-overflow` message:

![img.png](error.png)

Here is the useful information you can get from this error message:

### Error Location
The first stack trace describes where (which line/function/file) the error occurred. See [here](../../errmsg#stack-traces) for a guide on reading stack traces.

This will tell you which function is stuck in the infinite recursion, and also how you got there, but unfortunately there isn't much to help determine the cause here.

## Examples

- [Self-recursion](recurse-self)
- [BST cycle](bst-cycle)
