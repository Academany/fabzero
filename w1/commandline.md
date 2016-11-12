# Linux Command line 101

## Command line?
We are used to use a program that has a **Graphical User Interface** (GUI), but in reality this is just an interface for showing us information and interact with the program. The actual programs are running in the background.

But some programs can also be run without the GUI. So one way to interact with these programs is through the **Command Line**.

The enviroment we use is the Shell or command-line interpreter. There are many shells. The one that comes with most distributions is **Bash** (for Bourne Again Shell).

## Basic syntax
The command line syntax is

A mandatory `COMMAND` with optional `OPTIONS` and optional `ARGUMENTS`. For example:
```
ls -a /usr/local/bin
```
`ls` is a command which lists files and folders. `-a` is an option to display hidden files and `/usr/local/bin` is the argument telling where to operate the command. If the argument was not present it would list the current directory.

## Do I need to memorize all of this?
No. You can type `help COMMAND` or `man COMMAND` for a more extended help on how to use the commands.

---
[Back to Summary](../summary.md)
