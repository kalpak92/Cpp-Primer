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
