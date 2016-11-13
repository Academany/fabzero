# Writing damn good documentation

## The computer

### Writing documentation in markdown
This is an example of documentation written in HTML code. It takes time because there are all these tags that you have to open and remember to close like:
```html
<h1>This is the title</h1>
<p>This is a paragraph with some <strong>bold</strong> text.</p>
<ul>
    <li>This is first item of unordered list</li>
    <li>This is second item</li>
</ul>
```
There is a rising tendence to write documentation in **markdown** format. The same thing as above looks like this in markdown:
```md
# This is the title
This is a paragraph with some **bold** text.
* This is first item of unordered list
* This is second item
```

Markdown is very **easy to write**, very **easy to read** and you can also **easily export to HTML** and other formats. In markdown you focus more in the content and much less in code tags which are prone to syntax errors.

A Markdown document is just a plain text file usually appended with a `.md` extension. It will only take you about 10 minutes to learn the basics following [this tutorial](https://help.github.com/articles/markdown-basics/).

> Exercise: Create a markdown page with a text editor and introduce yourself. Use header titles, bold text, italic text, link, bullets and a image.

#### Documentation Workflow
The process of writing the documentation involves typing the documentation in markdown, exporting to HTML, and pushing the documentation to github. You can do all of these things manually but they can automated them in a shell script.

An alternative workflow would be using an online tool like [Stackedit.io](https://stackedit.io/). This is not described here, but is it worth having a look at it.


#### What is needed
You first need a text editor. I use [Atom](https://atom.io/) because it is Open Source and also has built in markdown preview. To activate the markdown preview in Atom clic on _Packages/Markdown Preview/Toggle Preview_.

![](./img/doc/atom.png)

> Exercise: Install atom

To convert `.md` files to `.html` files ~~you need~~ I use a command line tool called **pandoc**. In Ubuntu you can install pandoc by typing this in the terminal:

`sudo apt-get install pandoc`

> Exercise: Install pandoc

When you export to HTML, by default pandoc will export it unstyled, just like a normal HTML file written from scratch. But you can style your HTML using CSS. Styling HTML is recommended not only because it looks nicer but also because styling can make it easier and more pleasant to read. Which I consider an important feature for the documentation. Instead of writing your own `css` file from scratch, what I recommend is modifying one of the many available `css` files for pandoc, or use [the one I use](http://git.fabcloud.io/francisco/beach-lab-htgaa-2015/blob/master/students/sanchez.francisco/base.css).

>### Some tips learned the hard way
> Standard markdown syntax does not require a blank line before a header. Pandoc  does  require  this (except, of course, at the beginning of the document). The reason for the requirement is that it is all  too  easy for  a  #  to  end  up  at the beginning of a line by accident (perhaps through line wrapping).
>
> If you need a hard line break, put two or more spaces at the end of a line.

#### Automating everything
Some people tells me why I keep using command line tools like pandoc. It is because I consider automation the **real power of comand line tools**. You want to automate ~~because you are lazy bastard like me, admit it~~ in order to avoid typing all these commands in terminal over and over and also in order to speed up the process of file conversion and uploading to the server.

All you need to do is to create a new plain text file and name it something like `auto.sh` (for _shell script_) where you will write a sequence of commands. Those will be the very same commands that you would type in the terminal one by one.

This tutorial assumes that you have all the markdown `.md` and css `.css` files together in the root of your student folder - which is inside the lab folder containing the github repository. Otherwise just adjust the paths accordingly. The contents of the `auto.sh` file should be similar to this:

```bash
# Automation file
# Step 1. File conversion from .md to .html
FILES=*.md
for f in $FILES
do
  # extension="${f##*.}"
  filename="${f%.*}"
  echo "Converting $f to $filename.html"
  `pandoc -s -c base.css $f -t html -o $filename.html`
done
# Step 2. Uploading everything to github
# If there is commit message then upload
if [ "$#" -gt 0 ]
then
    git pull
    git add --all
    git commit -m "$*"
    git push
    # git ftp push -u <user> -P ftp://host.example.com/fab2016 # Uncomment this line to upload to ftp. Replace <user> and server to your settings
else
    echo "Not uploading (Empty commit message)"
fi
```

> Note 1: Please note that the `git commit` line contains a `$*`. This is important since we will [pass the commit message as an argument](http://osr600doc.sco.com/en/SHL_automate/_Passing_to_shell_script.html) when we execute the script.
>
> Note 2: This script includes a commented line that also uploads at the same time to a ftp server. If you want to do the same proceed to install [git-ftp](https://github.com/git-ftp/git-ftp) before uncommenting the line.

Now it comes the easy part. After you type all your documentation you open a new terminal inside your student folder that contains `auto.sh` file and type:

`sh auto.sh`

And it search for all the `.md` files in your folder and will convert them to HTML, overwriting if they already existed. But **if you also write a commit message** like this:

`sh auto.sh this will be the commit message`

This will convert all the markdown documentation to HTML **and** upload the documentation to your repository (if you uncommented the ftp line it will also ask you the ftp password).

> Exercise: Write a script to automate the conversion of your files to the repository.

### Audio and video

* Selfie video: Many incubators and accelerators will ask you to record a video where you show you and your team. If you are planning to start a [kickstarter](https://www.kickstarter.com) campaign for a product you want to sell you will also have to do the same. Try to record a 10 to 15 seconds video presenting yourself. Do you think it's easy? Let's see how many times you have to repeat the scene until you are satisfied.
* Screen recording: Sometimes the best way to show something that you are doing in a computer is with a screen capture video (with or without voice over). A good screen recorder for GNU/Linux is [SimpleScreenRecorder](http://www.maartenbaert.be/simplescreenrecorder/). Record a 30 seconds video showing something you do on screen.
* Do not underestimate the legacy `.gif` format. It is very useful to show short videos (2 to 5 seconds) like a led blinking. It also shows your emotions and helps the people understand how do you feel doing fab academy. It does not require autoplay. There are a number of resources for downloading, manipulating or converting to `.gif` like [Giphy](http://giphy.com/), [Ezgif](http://ezgif.com/video-to-gif) and many more. Try them.  
<iframe src="http://giphy.com/embed/j5QcmXoFWl4Q0" width="480" height="300" frameBorder="0" class="giphy-embed" allowFullScreen></iframe>
* Experiment with adding titles and subtitles to your videos (in another language or for people with disabilities for example). Subtitles can be hardcoded or softcoded, find out the difference. You can create subtitles with YouTube Creator Studio.
---
[Back to Summary](../summary.md)
