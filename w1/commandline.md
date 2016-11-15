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

> **Remember:** Linux is a case sensitive operating system. `-n` and `-N` are different options!

Options come in two flavors, they can be a single letter like `-a`. In this case you don't have a clue of what that option is performing. On the other hand you can concatenate sincle letter options. For example `-a -l` can be reduced to `-al`. Some options also have a human readable flavor. Human readable options are prefixed with two dashes and they give you a clue of what that option is doing. For example `-a` becomes `--all` in human readable flavor, giving you the clue that it will list all the files, including the hidden ones which start with a `.` in Linux. 

## Do I need to memorize all of this?
No. You can type `help COMMAND` or `man COMMAND` for a more extended help on how to use the commands.

## Navigating the filesystem
### Where am I
In bash you can see the directory you are. `pwd` command stands for Print Working Directory. It will output the full path of your location in the filesystem.

### Moving around
`cd` command stands for Call Directory and it is used to go to other directories.

### Listing contents
`ls` command

### Creating and removing directories
`mkdir`  

`rmdir`

### Creating, moving, deleting files
`touch`

`cp` for Copy

`mv` for Move

`rm` for Remove

> Warning: There is no trash can. The file is gone.

### Finding files and folders

`find`

### File sizes
One of the things you ~~should~~ must do before pushing your files to the archive is checking your files sizes. That way you make sure you are not accidentally uploading 16Mpx pictures, a large video or huge STL meshes (to name just three of the most common mistakes).

The reason why this is important, has an answer in how version control systems are designed. They are designed to keep history. That's why once you upload something by mistake, even if you delete it, it remains in the history and it is very difficult to remove it.

`du`

### Users, groups and permissions
Linux is a multi-user operating system with users and groups. Different users have different file access levels or privileges (read, write, execute). By default bash tells you what user is logged in. Otherwise you can ask bash _Who am I?_

`whoami` command will tell you who you are.

You can also switch user with `su` command.

`chmod`

### sudo

`sudo` Super User Do



---
[Back to Summary](../summary.md)
