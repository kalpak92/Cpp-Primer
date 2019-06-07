## Exercise 1.1

> Review the documentation for your compiler and determine what file naming convention it uses. Compile and run the main program from page 2.

### GCC and File Extensions

| Extension                                  | Meaning                                                      |
| ------------------------------------------ | ------------------------------------------------------------ |
| `.h`                                       | C header file (not to be compiled or linked).                |
| `.c`                                       | C source code which must be preprocessed.                    |
| `.i`                                       | C source code which should not be preprocessed.              |
| `.ii`                                      | C++ source code which should not be preprocessed.            |
| `.cc`, `.cp`, `.cxx`, `.cpp`, `.c++`, `.C` | C++ source code which must be preprocessed.                  |
| `.f`, `.for`, `.FOR`                       | Fortran source code which should not be preprocessed.        |
| `.F`, `.fpp`, `.FPP`                       | Fortran source code which must be preprocessed (with the traditional preprocessor). |
| `.r`                                       | Fortran source code which must be preprocessed with a RATFOR preprocessor (not included with GCC). |
| `.s`                                       | Assembler code.                                              |
| `.S`                                       | Assembler code which must be preprocessed.                   |

## Exercise 1.2

> Change the program to return -1. A return value of -1 is often treated as an indicator that the program failed. Recompile and rerun your program to see how your system treats a failure indicator from main.

### Exit Codes With Special Meanings

**Table Reserved Exit Codes**

| Exit Code Number | Meaning                                                      | Example                     | Comments                                                     |
| ---------------- | ------------------------------------------------------------ | --------------------------- | ------------------------------------------------------------ |
| `1`              | Catchall for general errors                                  | let "var1 = 1/0"            | Miscellaneous errors, such as "divide by zero" and other impermissible operations |
| `2`              | Misuse of shell builtins (according to Bash documentation)   | empty_function() {}         | [Missing keyword](http://www.tldp.org/LDP/abs/html/debugging.html#MISSINGKEYWORD) or command, or permission problem (and [*diff* return code on a failed binary file comparison](http://www.tldp.org/LDP/abs/html/filearchiv.html#DIFFERR2)). |
| `126`            | Command invoked cannot execute                               | /dev/null                   | Permission problem or command is not an executable           |
| `127`            | "command not found"                                          | illegal_command             | Possible problem with `$PATH` or a typo                      |
| `128`            | Invalid argument to [exit](http://www.tldp.org/LDP/abs/html/exit-status.html#EXITCOMMANDREF) | exit 3.14159                | **exit** takes only integer args in the range 0 - 255 (see first footnote) |
| `128+n`          | Fatal error signal "n"                                       | *kill -9* `$PPID` of script | `**$?**` returns 137 (128 + 9)                               |
| `130`            | Script terminated by Control-C                               | *Ctl-C*                     | Control-C is fatal error signal 2, (130 = 128 + 2, see above) |
| `255*`           | Exit status out of range                                     | exit -1                     | **exit** takes only integer args in the range 0 - 255        |

## endl vs \n in C++

Although they both seem to do the same thing, there is a subtle difference between them.

```c++
cout << endl  : Inserts a new line and flushes the stream

cout << "\n"  : Only inserts a new line.
```

Therefore,

cout << endl;

can be said equivalent to

cout << ‘\n’ << flush;

So cout << “\n” seems performance wise better than cout << endl; unless flushing of stream is required.

Some other differences between endl and \n are:

1. endl is manipulator while \n is character.
2. endl doesn’t occupy any memory whereas \n is character so It occupy 1 byte memory.
3. We cannot write endl in between double quotation while we can write \n in between double quotation like
   cout<<"\n"; it is right but cout<<"endl"; is is wrong.
4. We can use \n also in C++ but we can't use endl in C language.

**Reference:** 
<http://stackoverflow.com/questions/213907/c-stdendl-vs-n>

## Exercise 1.6

> Explain whether the following program fragment is legal.
>
> std::cout << "The sum of " << v1;
>
> ​				<< " and " << v2 ;
>
> ​				<< " is " << v1 + v2 << std::endl;

It's illegal.

**[Error] expected primary-expression before '<<' token**

Fixed it: remove the spare semicolons.

std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << std::endl;

## Exercise 1.7

> Compile a program that has incorrectly nested comments.

```c++
/*
* comment pairs /* */ cannot nest.
* ''cannot nest'' is considered source code,
* as is the rest of the program
*/
int main()
{
    return 0;
}
```

**Compiled result (g++):**

```shell
PS C:\Users\kseal\Documents\GitHub\Cpp-Primer\ch01> g++ .\ex7.cpp
.\ex7.cpp:3:3: error: empty character constant
 * ''cannot nest'' is considered source code,
   ^~~~~~~~
.\ex7.cpp:3:16: error: empty character constant
 * ''cannot nest'' is considered source code,
                ^~
.\ex7.cpp:2:23: error: 'cannot' does not name a type
 * comment pairs /* */ cannot nest.
```

## Exercise 1.12

> What does the following for loop do? What is the final value of sum?

```
int sum = 0;
for (int i = -100; i <= 100; ++i)
    sum += i;
```

the loop sums the numbers from -100 to 100. the final value of sum is zero.

## Exercise 1.13

> Rewrite the exercises from § 1.4.1 (p. 13) using for loops.

Ex1.9:

```c++
#include <iostream>

int main()
{
    int sum = 0;
    for (int i = 50; i <= 100; ++i) sum += i;
    std::cout << "the sum is: " << sum << std::endl;

    return 0;
}
```

Ex1.10:

```
#include <iostream>

int main()
{
    for (int i = 10; i >= 0; --i)
        std::cout << i << std::endl;
    return 0;
}
```

Ex1.11:

```c++
#include <iostream>

int main()
{
    std::cout << "please input two integers:\n";
    int small = 0, big = 0;
    std::cin >> small >> big;

    if (small > big)
    {
        int tmp = small;
        small = big;
        big = tmp;
    }

    for (int i = small; i != big; ++i)
        std::cout << i << std::endl;

    return 0;
}
```

## Exercise 1.17

> What happens in the program presented in this section if the input values are all equal? What if there are no duplicated values?

If the input values are all equal, it will print a line which shows the count of the number you input.

If there are no duplicated values, when different values are given as input, a new line will be printed if you click `Enter`.

```c++
1 2 3 4 5^D
1 occurs 1 times.
2 occurs 1 times.
3 occurs 1 times.
4 occurs 1 times.
5 occurs 1 times.
```

