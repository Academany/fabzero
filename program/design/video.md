# Video tools

## youtube-dl

`youtube-dl` is a tool to download videos from Youtube, vimeo and many other platforms. A comprehensive list can be found [here](http://ytdl-org.github.io/youtube-dl/supportedsites.html)

`sudo apt install youtube-dl` in Linux/WSL or `brew install youtube-dl` for macOS.

Examples:

Download the best quality of audio and video:  
`youtube-dl https://www.youtube.com/watch?v=gEsHsMu7Tfg`

Check what qualities are there:  
`youtube-dl -F https://www.youtube.com/watch?v=gEsHsMu7Tfg`

Will output:  
```
[youtube] gEsHsMu7Tfg: Downloading webpage
[info] Available formats for gEsHsMu7Tfg:
format code  extension  resolution note
249          webm       audio only tiny   51k , webm_dash container, opus @ 51k (48000Hz), 918.56KiB
250          webm       audio only tiny   68k , webm_dash container, opus @ 68k (48000Hz), 1.19MiB
140          m4a        audio only tiny  129k , m4a_dash container, mp4a.40.2@129k (44100Hz), 2.26MiB
251          webm       audio only tiny  134k , webm_dash container, opus @134k (48000Hz), 2.34MiB
394          mp4        256x144    144p   67k , mp4_dash container, av01.0.00M.08@  67k, 24fps, video only, 1.17MiB
160          mp4        256x144    144p   68k , mp4_dash container, avc1.4d400c@  68k, 24fps, video only, 1.19MiB
278          webm       256x144    144p   92k , webm_dash container, vp9@  92k, 24fps, video only, 1.62MiB
395          mp4        426x240    240p  127k , mp4_dash container, av01.0.00M.08@ 127k, 24fps, video only, 2.23MiB
133          mp4        426x240    240p  131k , mp4_dash container, avc1.4d4015@ 131k, 24fps, video only, 2.29MiB
242          webm       426x240    240p  140k , webm_dash container, vp9@ 140k, 24fps, video only, 2.45MiB
396          mp4        640x360    360p  231k , mp4_dash container, av01.0.01M.08@ 231k, 24fps, video only, 4.04MiB
134          mp4        640x360    360p  238k , mp4_dash container, avc1.4d401e@ 238k, 24fps, video only, 4.15MiB
243          webm       640x360    360p  249k , webm_dash container, vp9@ 249k, 24fps, video only, 4.35MiB
135          mp4        854x480    480p  382k , mp4_dash container, avc1.4d401e@ 382k, 24fps, video only, 6.68MiB
244          webm       854x480    480p  390k , webm_dash container, vp9@ 390k, 24fps, video only, 6.82MiB
397          mp4        854x480    480p  412k , mp4_dash container, av01.0.04M.08@ 412k, 24fps, video only, 7.19MiB
136          mp4        1280x720   720p  612k , mp4_dash container, avc1.4d401f@ 612k, 24fps, video only, 10.69MiB
247          webm       1280x720   720p  685k , webm_dash container, vp9@ 685k, 24fps, video only, 11.95MiB
398          mp4        1280x720   720p  841k , mp4_dash container, av01.0.05M.08@ 841k, 24fps, video only, 14.67MiB
399          mp4        1920x1080  1080p 1475k , mp4_dash container, av01.0.08M.08@1475k, 24fps, video only, 25.74MiB
248          webm       1920x1080  1080p 1716k , webm_dash container, vp9@1716k, 24fps, video only, 29.94MiB
137          mp4        1920x1080  1080p 1983k , mp4_dash container, avc1.640028@1983k, 24fps, video only, 34.60MiB
18           mp4        640x360    360p  527k , avc1.42001E, 24fps, mp4a.40.2 (44100Hz), 9.21MiB
22           mp4        1280x720   720p  741k , avc1.64001F, 24fps, mp4a.40.2 (44100Hz) (best)
```

Now you can select which one you want to download. I want just audio so:  
`youtube-dl -f 251 https://www.youtube.com/watch?v=gEsHsMu7Tfg`

## losslesscut

`losslesscut` is a tool to quickly trim videos without having to reencode them. 

<https://github.com/mifi/lossless-cut>

## ffmpeg

`sudo apt install ffmpeg` in Linux/WSL or `brew install ffmpeg` in macOS
 
