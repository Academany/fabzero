# Linux Command Line

> **Note:** As you go through this topic, do not try to memorize, learn by usage.

## Command Line? Like in 1983?
We are all familiar with programs that have a **Graphical User Interface (GUI)**, but in reality this is just an interface for showing us information and interact with **the actual programs** in an *user friendly* way. The actual programs **are running underneath**, in the background.

Programs can also be run without a GUI. Actually many programs come without a GUI. So the way to interact with these programs is through the **Command Line Interface (CLI)**.

The enviroment we use is the *Shell or command-line interpreter*. There are many CLI interpreters. The one that comes with most distributions is **Bash** (Bourne Again Shell).

![](img/bash/bash.png)

## The Unix philosophy
It is important to understand the [Unix philosophy](https://en.wikipedia.org/wiki/Unix_philosophy) before you move forward. Programs in Unix were written following this philosophy:

* Unix programs do one thing and do it well.
* Unix programs are designed to work together.
* Unix programs are designed to handle text streams, because that is a universal interface.

So Unix (and Linux programs) usually perform a single task only. They are not multipulpose tools programs. To achieve complex behaviours the output of a program can be *piped* (more on this later) to another program. Keep this is mind.

## Basic syntax
The command line syntax is a `command` with optional `options` and optional `arguments`. For example, copy the following and paste it in the command line:
```
ls -a /usr/local/bin
```
`ls` is a command which lists files and folders. `-a` is an option to display hidden files and `/usr/local/bin` is the argument telling where to operate the command. If the argument was not present it would list the current directory.

> **Something's wrong! Copy and paste keys are not working**
The usual copy and paste key combinations have different functions in Bash. To copy text in Bash, select it and press `CONTROL`+`SHITFT`+`C`. To paste text in Bash use the arrow keys to go to the desired location and use `CONTROL`+`SHITFT`+`V`.

Options come in two flavors, one is called **short option**, a single letter like `-a`. In this case you don't have a clue of what that option is performing. On the other hand you can concatenate short options. For example `-a -l` can be reduced to `-al`.

> **Remember:**
Linux is a case sensitive operating system. `-n` and `-N` are different things!

Some options also have a human readable flavor called **long option**. Human readable options are prefixed with two dashes `--` and they give you a clue of what that option is doing. For example the long option of `-a` is `--all`, giving you the clue that it will list all the files and folders, including the hidden ones. Long options cannot be concatenated.

> Exercise: List the files of your home folder. Display them as a list. Display the hidden files also. What other options can be useful?

## The manual
Wait, wait, wait... Do I need to memorize all of this?
No. Just use the `man` command (for Manual) everytime you need help on how to use the commands. Yes, I know. We all hate manuals.

> Exercise: Have a quick look at the manual for `ls` command. Get familiarised, you will need it a lot.

## Navigating the filesystem

### Where am I?
The information displayed in Bash varies from distribution to distribution. In Ubuntu you can see at every moment what is the current directory and the full path. Otherwise `pwd` command (_Print Working Directory_) will output the full path of your location in the filesystem.

> Exercise: Open a new terminal window. Where are you now? What is ~?

### Moving around
`cd` command stands for *change directory* and it is used to go to other directories.

> Exercise: Navigate to your root folder /

If you need to navigate to a folder with spaces like *My Documents* use the escape character `\` to tell bash that the space is part of the name and not another argument:

`cd My\ Documents`

If you need to go back to the last directory you were you can use the command `cd -`. This is very useful to go back and forward between 2 directories.

### Tab completion
A very handy keyboard shorcut is the `TAB` key. It will autocomplete the name of the file or the folder name.

> Exercise: From the root folder, navigate to your Documents folder. Use `TAB` to keep autocompleting.

When two or more options are available the first `TAB` will not autocomplete, a second `TAB` will show you the available options for you to type a few extra letters to diferenciate. After that another `TAB` will autocomplete.

### Listing contents
We have seen the `ls` command already. Most of the time you will use `ls -lh` (with optional `-a`) which gives you a long list with human readable file sizes.

The first column tells you if the item is a file `-`, a directory `d`, or a link `l`. Then you can see the permissions, owner, group, date, file size, and name.

> Exercise: List and analyse the contents of your `/usr/bin`. What do you see?

### Creating, moving and deleting files and folders
`mkdir` is used to create a directory

> Exercise: Create a personal folder using this scheme `surname.name` in your `~/Documents` folder.

If you need to create a folder structure you can use the option `-p` which will create all the required parent folders.

> Create `~/Documents/surname.name/week1/img`

`touch` command is used to create an empty file.

> Exercise: create a file named `readme.md` inside your personal folder. Check that the file is there.

`rmdir` removes empty directories.

> Exercise: Try to remove your personal folder. Ouch. What's the problem?

`cp` is a command used to copy files and folder. It has many options but the basic usage is `cp origin destination`.

> Exercise: Copy your `readme.md` to `day1.md`

`mv` is used for moving files but can also me used as a rename tool.

> Exercise: Rename `day1.md` to `week1day1.md`. Remember to use `man mv` if you don't know how to use the command.

When moving files from other directories to the current directory you can use the shortcut `.`

> Example: `mv ~/Downloads/somefile.zip .`

At all time we can use wildcards like `*` that represents any number of any characters and `?` that represent one of any character.

`rm` can be used to remove files and folders

> **Warning:** There is no trash can in the command line. You delete a file and the file is gone forever. Be be careful with this command.

You can use `rm` recursively to delete files and folders

> Example `rm -r ~/Documents/surname.name/` will delete the folder and everything inside it. Extreme caution!

### Finding files and folders
`find` will recursively search for files and folders inside a specified starting location. For example, to find files and folders anywhere inside your home folder which contains "1":

`find ~ -name "*1*"`

This command has many other options, explore the manual if you want to learn more.

### File sizes
One of the things you ~~should~~ must do before pushing your files to the archive is checking your files sizes. That way you make sure you are not accidentally uploading 16Mpx pictures, a large video or huge STL meshes (to name just three of the most common mistakes).

The reason why this is important, has an answer in how version control systems are designed. They are designed to keep history. That's why once you upload something by mistake, even if you delete it, it remains in the history and it is very difficult to remove it. So we use the `du` (disk usage) command to check the size of alll files and folders (*) inside the current folder with summarize option `-s` and human readable format `-h`.

`du -sh foldername`

If we have a group of files and folders and we want to check the size of all of them, we can specify all files and folders instead of a specific folder `*` and optionally *pipe* the result `|` to the `sort` command to sort the results by human numerical value `-h` and in reverse order `-r` so that bigger files appear first.

`du -sh * | sort -rh`

> **Remember** Always check your folder size before pushing to the archive! A normal archive should grow at a rate of 1-2 mb per week.

![](img/bash/slap.jpg)

### Looking inside files

`cat` will display your file on the screen. You can also use option `-n` to number the lines.

`cat -n somefile.txt`

You can also count the number of lines of a file by *piping* the output to `wc` (word count) command

`cat file.txt | wc -l`

`wc` can count characters, words, and lines. Check the man page.

`head` and `tail` commands will show the first and lastest 10 lines of a file. You can change this number of lines displayed by using the option `-n`

`tail -n 5 somefile.txt`

`less` is used for browsing long files, it will display the file you specify using the same viewer as `man` command.

`grep` is a very useful command. It looks for text inside files and display the line of text that contains the search pattern. Some useful options are:

```
-r # recursive search
-i # case insensitive search pattern
-n # show the text line number than contains the search pattern
```

So for if you want to seach for "openscad" anywhere inside the current folder you would do:

`grep -rin "openscad" .`

### The `echo` command

#### Display text on the screen
`echo` displays its parameters in the stdout (screen). It is usefull when creating our scripts `echo hello world` will display `hello world` on screen.

#### Writing to files
If you want to write text to a file you can use `echo hello world > file.txt` but **warning!**, it will overwrite the contents of the file.

```
echo hello me > file.txt
echo hello you > file.txt
cat file.txt

hello you
```

If you want to append text to an existing file (add a new line of text) use the `>>` operator instead.

```
echo hello me >> file.txt
echo hello you >> file.txt
cat file.txt

hello me
hello you
```

### Understanding users
Linux is a multi-user operating system with users and groups. Different users have different file access levels or privileges (read, write, execute). By default bash tells you what user is logged in. Otherwise you can ask bash _Who am I?_

`whoami` command will tell you who you are.

There are 2 kinds of users in Linux. Normal users and _superusers_. Supersers can perfom administrative tasks and will be able to look into other users folders. Even if you are a normal user you can perform superuser tasks using the `sudo` command. `sudo` stands for _Super User Do_ and it will perform tasks as if you were the root user. For instance, if you want to move one file out of your home folder you will be denied permission. To do that you will have to execute the command as if you were a superuser like `root` user.

`sudo mv somefile.txt /`

As soon as you have performed you administrative tasks you should revert back to your normal user privileges. You can withdraw yourself from admin privileges with `sudo -k`.

You can also switch user to root with `su`, but you need superuser privileges for that you must use `sudo su`. Exit to your normal user as soon as you finish with `exit` command.

Files are owned by the user who created them. You can change the owner with the `chown` command:

`sudo chown myuser file` will change the owner to a user called `myuser`.

### Understanding permissions
Permissions are arranged in groups of 3 letters that represents the access level for the current user, group and others.

![](img/bash/perm1.png)

Each group of 3 letters represents the the read/write/execute access to a file or folder.

![](img/bash/perm2.png)

Permissions of a specific file or device are changed with the `chmod` command. For example, if you want to change the permission of the file `script.sh` you could do:

`sudo chmod 666 script.sh`

But what does 666 mean? It's about time to talk about the octal notation.

#### Octal notation
In octal notation, permissions are represented by 3 numbers. Each one of these three numbers represent the user/group/others access and the value of the number itself the read/write/execute value. Given than read access is 4, write access is 2 and execute access is 1, all combinations of these three result in an unique number from 0 to 7.

Who? | Read (4) | Write (2) | Execute (1) | Result
---|---|---|---|---
User | 4 | 2 | 0 | **6**
Group | 4 | 2 | 0 | **6**
Others | 4 | 2 | 0 | **6**

With a little bit of math all the permissions are easily derived. Otherwise you can also use this table:

Octal Value | Mode | Octal Value | Mode
---|---|---|---
**0** | - - - | **4** | r - -
**1** | - - x | **5** | r - x
**2** | - w - | **6** | r w -
**3** | - w x | **7** | r w x

This method is recommended when you want to set all permissions at once.

> Exercise: Derive the following permissions 755, 644, 600, 660

#### Symbolic notation
The symbolic notation is more intuitive and it is useful when only a few permissions settings want to be changed. The notation is as follows, `+` stands for add a permission, `-` for removing a permission, and `=` for adding a specific permission but removing the others.

 Who? | Read (r) | Write (w) | Execute (x) | Result
---|---|---|---|---
User (u) | + | + |  | **u+rw**
Group (g) |  | - | + | **g+x-w**
Others (o) | = |  |  | **o=r**
All (a) | - | - | - | **a-rwx**

#### Octal _vs_ Symbolic Notation

Octal Value | Symbolic  | Result
---|---|---
755 | u+rwx,g+rx,o+rx | rwxr-xr-x
777 | a+rwx | rwxrwxrwx
644 | u+rw,g=r,o=r | rw-r--r--
700 | u+rwx,g-rwx,o-rwx | rwx------

---
[Back to Summary](../summary.md)
