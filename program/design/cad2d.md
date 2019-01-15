# CAD 2D. Raster and Vector

> :construction: This documentation is WIP

* [Raster](#raster)
* [Graphicsmagick](#graphicsmagick)
* [Vectorizing a raster image](#vectorizing-a-raster-image)

## Raster

## Graphicsmagick

Graphicsmagick swiss army command line tool for image processing. It is an improved and updated variant of the well known [imagemagick](https://www.imagemagick.org/script/index.php). Please refer to the [graphicsmagick website](http://www.graphicsmagick.org/) to find out why.

So to resize an image called `bigimage.jpg` inside a 640x640 envelope, maintaning its aspect ratio and save it to a file named `smallimage.jpg` we would use:

`gm convert bigimage.jpg -resize 640x640 smallimage.jpg`

One of the utilities of graphicsmagick is the ability to compose images in a horizontal strip, which is very useful for documenting processes.

`gm convert image1.jpg image2.jpg -geometry x400 +append stripimage.jpg`

## Vectorizing a raster image

Learn how to vectorize a B/W image in Inkscape. You will need to do this many times.

---
[Back to Summary](../summary.md)
