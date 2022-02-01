# CAD 2D. Raster and Vector

> :construction: This documentation is WIP

## Raster

### Screenshots

We recommend [Flameshot](https://flameshot.org)

### Imagemagick CLI

`sudo apt install imagemagick` in Linux/WSL or `brew install imagemagick` in macOS

[Imagemagick](https://www.imagemagick.org/script/index.php) is swiss army command line tool for image processing. 

So to resize an image called `bigimage.jpg` inside a 640x640 envelope, maintaning its aspect ratio and save it to a file named `smallimage.jpg` we would use:

`convert bigimage.jpg -resize 640x640 smallimage.jpg`

Or you could modify them in place (overwrite original image). The following will resize all the `.jpg` files of your current folder:

`mogrify -resize 640x640 *.jpg`

One of the utilities of graphicsmagick is the ability to compose images in a horizontal strip, which is very useful for documenting processes.

`montage image1.jpg image2.jpg -tile 2x1 -geometry x400+10+0 stripimage.jpg`

### Vectorizing a raster image

Learn how to vectorize a B/W image in Inkscape. You will need to do this many times.

---
[Back to Summary](../summary.md)
