# Working with git repositories

- [Goal of this unit](#goal-of-this-unit)
- [The community effect](#the-community-effect)
- [Downloading a repository from Github](#downloading-a-repository-from-github)
- [Installing git](#installing-git)
- [Configuring git](#configuring-git)
- [Cloning a repository using HTTPS connection](#cloning-a-repository-using-https-connection)
- [Generating a SSH Keypair](#generating-a-ssh-keypair)
- [Cloning a repository using a SSH connection](#cloning-a-repository-using-a-ssh-connection)
- [Before you upload. Check file size](#before-you-upload-check-file-size)
- [Basic git workflow](#basic-git-workflow)
- [Advanced git workflow](#advanced-git-workflow)
- [Branching. Testing new things without making a mess](#branching-testing-new-things-without-making-a-mess)
  - [What's a branch and why would I want one](#whats-a-branch-and-why-would-i-want-one)
  - [Creating and navigating through branches](#creating-and-navigating-through-branches)
  - [Merging and deleting branches](#merging-and-deleting-branches)
- [Keeping your forked repositories up to date](#keeping-your-forked-repositories-up-to-date)
- [Troubleshooting](#troubleshooting)
  - [Problem 1: I don't know what to do next](#problem-1-i-dont-know-what-to-do-next)
  - [Problem 2: Panic! Push error!](#problem-2-panic-push-error)

> **Note:** As you go through this topic, do not try to memorize, learn by usage.

## Goal of this unit

The goal of this unit is learning just the **fundamentals of git** version control to get things done.

## The community effect

Imagine a community of 4 people, where everyone has a design and shares it. The balance is positive for all of them, since each one gives one and receives 3. The **most important** feature in sharing communities is that knowledge is amplified and **you always receive more that you give**.

![the sharing economy](../diagrams/sharing-economy.png)

In Fab Academy **we are working with git repositories**. Every lab has a git repository where students push their work and pull other people's work. The advantages of working with repositories rather than simple file sharing are countless: you can create branches, roll back changes, delete other people's files and many other things that you will ~~hate~~ love very soon.

## Downloading a repository from Github

[Github](github.com) is a web-based Git repository hosting. You don't need a github account or any software to download a zipped repository.

> **Learning by doing:** Visit GitHub and download a repository in zip format. Think of the inconveniences of proceeding that way.

## Installing git

For the next part of the course we will need to install [git](https://git-scm.com/). In Ubuntu type in a terminal window:

`sudo apt install git`

> **Learning by doing:** Install git in your laptop.

## Configuring git

Set some basic config and tell git who you are. I might not have to remind that, but please remember gentle reader, to replace **yourname** with your actual name and **youremail** with your actual email address.

```bash
cd ~/folder_name # replace this with your repository folder
git config --global user.name "yourname" #set name for commits
git config --global user.email "youremail" #set email for commits
git config --global push.default simple #default push only the current branch
git config --global core.editor nano #set the editor
```

> **Learning by doing:** Configure git with your personal data

## Cloning a repository using HTTPS connection

> **Note:** From now on you will need your [fablabs.io](fablabs.io) account.

To clone a repository you must type in a terminal window:

`git clone REPOSITORY_ADDRESS`

You can specify 2 kind of address depending on the connection used: HTTPS or SSH.

HTTPS connection is commonly used when you are cloning a repository that you will not be modifiying but you want to receive changes. It will not require login/password for each connection if the project is public.

> **Learning by doing:** Clone the class fab zero archive in gitlab using the https address. Your mentor will provide you with the address.
Did you need to authenticate? What does it mean?

Hopefully you will now have a folder containing the archive somewhere in your computer. But the problem is that if we want to push changes now it will require our login/password for each time we connect. Which is very inconvenient. So we will change the connection to SSH.

> **Learning by doing:** Delete the local folder containing the class repository. We will clone it again later

## Generating a SSH Keypair

We usually use SSH connection in git, that way we are not dealing with logins and passwords. A SSH connection needs a SSH keypair, one public key and one private key. These two together will allow you to establish an encripted connection. You can generate a ssh keypair by following [this tutorial](https://docs.github.com/es/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent).

If you decide to define a passphrase at the time of generating the keypair, you will have to type it every-single-time you push to the archive. And this is going to be a lot of times. You have been warned.

After creating the ssh keypair, and adding it to the ssh-agent, you have to upload the public key to github/gitlab. For copying the contents of the public key to the clipboard you can just open it in any text editor, select all of it contents and copy it. I will use a command line tool called **cat**. 

Say our public key name is `id_rsa.pub`, to display its contents we do

`cat ~/.ssh/id_rsa.pub`

And it is just a matter copying and pasting in the SSH Keys section of github/gitlab. A piece of advice. Name that key in github/gitlab as the computer you are using. If you loose that computer or you feel that the key is compromised you will know what key to delete.

> **Think about it:** Can you have more than one key? Can you copy the keys to another computer?

## Cloning a repository using a SSH connection

This time locate the SSH address to clone the repository. In your computer, inside a terminal window, navigate to where you want to clone the repository (**recommended your home directory**):

```bash
cd  # this goes to home folder
git clone paste-the-address-here.git
```

> **Learning by doing:** Clone the Fab Zero class repository in your computer using the SSH connection.

## Before you upload. Check file size

One of the things you ~~should~~ must do before pushing your files to the archive is checking your files sizes. That way you make sure you are not accidentally uploading 16Mpx pictures, a large video or huge STL meshes (to name just three of the most common mistakes).

The reason why this is important, has an answer in how version control systems are designed. They are designed to keep history. That's why once you upload something by mistake, even if you delete it, it remains in the history and it is very difficult to remove it. So we use the `du` (disk usage) command to check the size of alll files and folders (*) inside the current folder with summarize option `-s` and human readable format `-h`.

`du -sh foldername`

If we have a group of files and folders and we want to check the size of all of them, we can specify all files and folders instead of a specific folder `*` and optionally *pipe* the result `|` to the `sort` command to sort the results by human numerical value `-h` and in reverse order `-r` so that bigger files appear first.

`du -sh * | sort -rh`

> **Remember** Always check your folder size before pushing to the archive! A normal archive should grow at a rate of 1-2 mb per week.

## Basic git workflow

This is the basic git workflow. Once you have made all changes to your website (hopefully daily), upload those changes to the repository. **Very important:** Do not miss any step, and do them in order.

```bash
cd ~/repositoryfolder     # go to the local repository folder
du -sh personalsubfolder  # check your subfolder size
git pull                  # pull other students changes
git add --all             # add your changes
git commit -m "message"   # write a meaningful message
git push                  # push to the archive
```

This is the manual workflow of updating your page. You can also write a script and [automate this process](doc.md).

> **Learning by doing:** What happens if you move the folder to another location? What happens if you rename the folder? Try to pull and push some changes after you rename or move the repository folder.

## Advanced git workflow

![git workflow](img/git/git.jpg)

## Branching. Testing new things without making a mess

### What's a branch and why would I want one

One day, you will have (let's say) a piece of code that is working. People can download it and everybody is happy. If you want to add new features and you start messing the code, it is likely that you will break the functionality. That is a bad practice, because until you fix all the problems, people will download something that does not work anymore. What `git` allows you is to create a **branch**, which is a separate copy of your repository. In there you can test new features while maintaining the **main** branch (the original one).

### Creating and navigating through branches

You can create a new branch by doing:

```bash
git branch nameofthebranch
```

> **Learning by doing:** Create a new branch for your repository

You have created that branch, but you are still working in the main one. To switch to another branch you use the checkout command.

```bash
git checkout nameofthebranch
```

> **Learning by doing:** Practice switching between branches. How do you know at any given point in what branch are you?

You can commit changes and push as you normally do. It is a good practice to **commit before you switch branches**. Because when you switch to another branch your working directory will look like it did the last time you committed on that branch.

### Merging and deleting branches

Once your new features are functional, it is time to incorporate that work into the main branch. This is called **merging** in `git`. For that, you first go to the main branch and then **merge** the changes.

```bash
git checkout main
git merge nameofthebranch
```

Congratulations! Now you should have a main branch with the new features! We don't need the testing branch anymore, let's delete it.

```bash
git branch -d nameofthebranch
```

## Keeping your forked repositories up to date

When you clone your fork `origin` points to your github/gitlab address. But you migh also incorporate the changes from the original repository. For that add the original repository as an `upstream`. Go to your local cloned respository and type:

```bash
git remote add upstream REPO-ADDRESS-YOU-FORKED-FROM
git fetch upstream
```

And then update your fork from original repo to keep up with their changes

`git pull upstream main`


## Troubleshooting

### Problem 1: I don't know what to do next

Solution: Do a `git status` and read

### Problem 2: Panic! Push error!

Solution: Stay calm. Read. The most common error at the push step is that after you pulled, and while you were typing the rest of the commands, someone (or several people) pushed their content to the archive. Just pull and push again. You can do that at the same time using `git pull && git push`

---
[Back to Summary](../summary.md)
