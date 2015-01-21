# fibo

A Fibonacci sequence and modulo experiment in C.

## What and Why?

At college, I attend Maths club, whenever dental appointments happen not to coincide with it. This is what led to me creating *fibo*, which finds information about the Fibonacci sequence when each term is divided by a number and the remainder is considered. This operation of finding the remainder, called modulus, produces some interesting results.

In order to explain, let's start with the first few digits of the Fibonnaci sequence:

>1, 1, 2, 3, 5, 8, 13, 21, 34, 55

Now if we write each digit `mod 2`, we get a pattern emerging.

| Fib. seq.	| 1 | 1 | 2 | 3 | 5 | 8 | 13 | 21 | 34 | 55 |
|-----------|--:|--:|--:|--:|--:|--:|---:|---:|---:|---:|
| `mod 2`	| 1 | 1 | 0 | 1 | 1 | 0 |  1 |  1 |  0 |  1 |

Every zero we find we mark as the end of a cycle. Every time the whole pattern starts to repeat, we mark the end of a period. In the example of `mod 2`, there is only one cycle per period, with a cycle length of three digits. Let's try the same with `mod 3`:

| Fib. seq. | 1 | 1 | 2 | 3 | 5 | 8 | 13 | 21 | 34 | 55 |
|-----------|--:|--:|--:|--:|--:|--:|---:|---:|---:|---:|
| `mod 3`	| 1 | 1 | 2 | 0 | 2 | 2 |  1 |  0 |  1 |  1 |

This time, there are two different cycles; 1, 1, 2, 0 and 2, 2, 1, 0. If you were to continue the sequence further, you'd find that the modulus sequence would alternate between the two. This means there is a cycle length of four, a cycle count of two-per-period, and a period length of eight. Consider the table below:

| `mod x`	| cycles/period	| cycle length	|
|----------:|--------------:|--------------:|
| 2			| 1				| 3				|
| 3			| 2				| 4				|
| 4			| 1				| 6				|
| 5			| 4				| 5				|
| ...		| ...			| ...			|

## Documentation

At the time of writing, the program is designed to accept one number as a maximum. Because I'm using C's `unsigned int` type to store numbers, the program will currently not accept any number above 2^16 - 1, or 65,535. I may well switch to using the `unsigned long` type, which will support up to 4,294,967,295.

Once the program has a number (which we'll call *x*), it finds the cycle count and cycle length of the Fibonacci sequence `mod x`. It then drops the original number by one, and repeats the process, until it reaches 2. The program doesn't bother with 1 for some reason. I think it was causing problems earlier. The number *x* is referred to as the limit.

In future, I'd like to implement some kind of range system when specifying the number, and some proper argument parsing. I also need to improve the way memory is handled, I think.

### Usage

Assuming the program can be called with `fibo`, the following commands should work:

* `fibo` &ndash; Run the program without arguments. You will be prompted to enter a number.

* `fibo x` &ndash; Run the program with a limit of `x`. See above for more information.

* `fibo x -s` &ndash; As above, while also printing the sequences that the program generates.

* `fibo -h` &ndash; Show basic help text.

## Installation

If you'd like to use *fibo* yourself, the easiest way to get a working copy &ndash; granted you have the tools available &ndash; is to clone the repository and compile from source. There are also precompiled binary and source packages available.

### Linux

If you're running Linux, installation could be as simple as:

	cd ~/downloads
	git clone https://github.com/blieque/fibo
	cd fibo
	gcc -o fibo fibo.c

If you want a slightly smaller and better optimised binary, you could install [Clang](http://clang.llvm.org/) and run `clang -o fibo fibo.c` for the last line instead.

Once it's compiled, you can run it from the directory you're in with `./fibo`. Place the executable in a directory included in your path variable, and you'll be able to use it anywhere, just by calling `fibo`.

If you would rather just download the executable, I have bundled it with the source for Linux. To download, click [here](http://file.blieque.co.uk/git/fibo/fibo-0.1-linux.tar.gz).

### Windows

For Windows, I have compiled an `.exe` file. You can download a `.zip` file from my website using the link below. The archive includes the following:

* `fibo.exe` &ndash; The main executable, compiled with MinGW GCC.

* `prompt.bat` &ndash; A batch file to open a command window and provide some instructions.

* `fibo.c` &ndash; The main source code file.

* `functions.h` &ndash; A source code header file containing functions.

To download, click [here](http://file.blieque.co.uk/git/fibo/fibo-0.1-win.zip).

### OS X

Enlighten me. I don't have a Mac to compile it on.
