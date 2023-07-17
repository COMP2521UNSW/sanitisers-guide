# Runtime Errors

Runtime errors all follow the same general format, they give the file and line the error occurred in, then a description  of the error.

## index out of bounds
This is probably the most descriptive and 'plain English' error out there. If you've got an array that's a certain size `N`, then the valid range of indexes is `0` up to `N - 1`. Accessing anything besides these gives you an error like the one below:

![index out of bounds error](index.png)

Typically, this error comes along with a [SEGV on unknown address](../SEGV-unknown-address), or [stack-buffer-overflow](../stack-buffer-overflow) error, so see the explanations and examples there for more information on debugging.

**Note**: If the index in the error message is `-1094795586` then this is definitely an uninitialised value, since this is the default value used for uninitialised values. See an example [here](../SEGV-unknown-address/uninitialised-idx).


## misaligned address
For efficiency reasons, the compiler will align data along certain boundaries. This means that data will always be stored at addresses that are a multiple of this boundary. For example, in the screenshot above we can see that `int` requires 4-byte alignment, so the memory address of an `int` should always be a multiple of 4.

If you try access an address that is not aligned correctly, then the sanitiser knows that this must be an invalid address, so it raises an error like the one below:

![misaligned address error](misaligned.png)

Typically, this error comes along with a [SEGV on unknown address](../SEGV-unknown-address) error, so see the explanations and examples there for more information on debugging.

**Note**: If the address in the error message is `0xbebebebebebebebe` then this is definitely an uninitialised pointer, since this is the default value used for uninitialised values. See an example [here](../SEGV-unknown-address/uninitialised-ptr).

## null pointer
Hopefully this error is pretty straightforward - it occurs when you try to access a NULL pointer. Below is an example:
![null pointer error](null.png)

Typically, this error comes along with a [SEGV on unknown address](../SEGV-unknown-address) error, so see the explanations and examples there for more information on debugging. A specific example can be found [here](../SEGV-unknown-address/nullptr).