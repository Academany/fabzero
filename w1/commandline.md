# Linux Command line 101

## Command line?
We are all familiar with programs that have a **Graphical User Interface** (GUI), but in reality this is just an interface for showing us information and interact with the actual program. The actual programs are running in the background.

But programs can also be run without the GUI and actually many programs come without a GUI. So the way to interact with these programs is through the **Command Line**.

The enviroment we use is the Shell or command-line interpreter. There are many shells. The one that comes with most distributions is **Bash** (Bourne Again Shell).

[SHELL ENVIRONMENT IMAGE PLACEHOLDER]

## The Unix philosophy
It is important to understand the [Unix philosophy](https://en.wikipedia.org/wiki/Unix_philosophy) before you move forward. Programs in Unix were written following this philosophy:

* Unix programs do one thing and do it well.
* Unix programs are designed to work together.
* Unix programs are designed to handle text streams, because that is a universal interface.

So Unix (and Linux programs) usually perform a single task only. They are not multipulpose complex programs. To achieve complex behaviours the output of a program can be piped (more on this later) to another program. keep this is mind.

## Basic syntax
The command line syntax is a mandatory `COMMAND` with optional `OPTIONS` and optional `ARGUMENTS`. For example, copy the following and paste it in the command line:
```
ls -a /usr/local/bin
```

> ### Something's wrong! Copy and paste keys are not working
The usual copy and paste key combinations have different functions in Bash. To copy text in Bash, select it and press `CONTROL`+`SHITFT`+`C`. To paste text in Bash use the arrow keys to go to the desired location and use `CONTROL`+`SHITFT`+`V`.

`ls` is a command which lists files and folders. `-a` is an option to display hidden files and `/usr/local/bin` is the argument telling where to operate the command. If the argument was not present it would list the current directory.

>### Wait, wait, wait... Do I need to memorize all of this?
No. Just use the `man` COMMAND (for Manual) everytime you need help on how to use the commands. Yes, I know. We all hate manuals. But in Unix/Linux world you will find a lot of references about [RTFM](https://en.wikipedia.org/wiki/RTFM).

> Exercise: Have a quick look at the manual for `ls` command. We will need this in a while.

Options come in two flavors, one is called **short option**, a single letter like `-a`. In this case you don't have a clue of what that option is performing. On the other hand you can concatenate short options. For example `-a -l` can be reduced to `-al`.

> **Remember:** Linux is a case sensitive operating system. `-n` and `-N` are different things!

Some options also have a human readable flavor called **long option**. Human readable options are prefixed with two dashes `--` and they give you a clue of what that option is doing. For example the long option of `-a` is `--all`, giving you the clue that it will list all the files and folders, including the hidden ones. Long options cannot be concatenated.

> Exercise: List the files of your home folder. Display them as a list. Display the hidden files also. What other options can be useful?

## Navigating the filesystem
### Where am I?
The information displayed in Bash varies from distribution to distribution. In Ubuntu you can see at every moment what is the current directory and the full path. Otherwise `pwd` command (_Print Working Directory_) will output the full path of your location in the filesystem.

> Exercise: Open a new terminal window. Where are you now? What is ~?

### Moving around
`cd` command stands for Call Directory and it is used to go to other directories.

> Exercise: Navigate to your root folder `/`

### Tab completion
A very handy keyboard shorcut is the `TAB` key. It will autocomplete the name of the file or the folder name.

> Exercise: From the root folder, navigate to your Documents folder. Use `TAB` to keep autocompleting.


### Listing contents
We have seen the `ls` command already. Most of the time you will use `ls -lh` (with optional `-a`) which gives you a long list with human readable file sizes.

The first column tells you if the item is a file `-`, a directory `d`, or a link `l`. Then you can see the permissions, owner, group, date, file size, and name.

> Exercise: List and analyse the contents of your `/usr/bin`. What do you see?

### Creating, moving and deleting files and folders
`mkdir` is used to create a directory

> Exercise: Create a personal folder using this scheme `surname.name` in your `~/Documents` folder.

`touch` command is used to create an empty file.

> Exercise: create a file named `readme.md` inside your personal folder. Check that the file is there.

`rmdir` removes empty directories.

> Exercise: Try to remove your personal folder. Ouch. What's the problem?

`cp` is a command used to copy files and folder. It has many options but the basic usage is `cp origin destination`.

> Exercise: Copy your `readme.md` to `day1.md`

`mv` is used for moving files but can also me used as a rename tool.

> Exercise: Rename `day1.md` to `week1day1.md`. Remember to use `man` if you don't know how to use a certain command.

`rm` can be used to remove files and folders

> **Warning:** There is no trash can in the command line. You delete a file and the file is gone. Be be careful with this command.

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
