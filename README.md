# Doom for Apple A/UX

##### The Doom port you never asked for

## About

This is the source code for Doom for Apple A/UX, an AT&T System V-based operating system written by Apple and supported until the mid-1990s. It is based on the original [Doom source](https://github.com/id-Software/DOOM) released in December 1997.

The port was written by [Cariad Heather Keigher](https://cariad.keigher.ca) ([Twitter](https://twitter.com/KateLibC), [Twitch](https://twitch.tv/KateLibC) and [GitHub](https://github.com/katelibc)) in June 2022 with all code modifications being written in a manner where this should only really compile on any A/UX 3.1.1 (maybe earlier) systems with GCC 2.7.2 and associated tools installed. She is not a C developer so enjoy her decisions in changes to make the game "work".

It was only tested in the A/UX Finder using 32-bit mode running MacX 2.0 on a Quadra 800 with 64 MB of RAM and a Radius graphics accelerator. 

It is expected that this software and OS configuration should work on virtually any A/UX supported system, but you may have similar results with earlier versions. It wasn't tested in pure X11 mode, but it is likely that it works there as well and will probably be less of a slideshow.

## Details about this port

This port should be considered a "proof of concept" and is only supported on a limited basis. 

Patches via pull requests or forks of the project are encouraged, but do at least attribute me and you must keep the original licence Doom's source comes with (see `DOOMLIC.TXT` for details).

With that, here are some details about my janky version:

* Doom launches with a shareware or retail release of the WAD file
* The WAD file must have a lower case extension (so "wad" instead of "WAD")
* Sound and music is completely disabled
* There is no network functionality
* Keybindings in MacX prevent you from shooting a weapon, so enjoy pacifist mode? 
* It maybe gets 2-3 frames per second, but this has only been tested in MacX
* There are no flags enabled when compiling to produce optimised code due to weird graphical issues when using them

This game likely runs better under X11 itself as opposed to the sandwich that is MacX atop of System 7.0's Finder which itself is atop of A/UX.

## Requirements and setup

These requirements are loosely defined but this is what I had available to me when I got it to all run:

* [Any Mac capable of running A/UX](https://www.aux-penelope.com/hardware.htm) 
* "Enough" RAM (this was tested on 64 MB)
* A copy of `DOOM.WAD` or `DOOM1.WAD` renamed to lowercase
* A/UX 3.1.1
* MacX 2.0
* Installation of build tools (GCC, Make, et cetera) from the [Jagubox mirror](http://polysoft.fr/jagubox/)

You might have some luck running this in QEMU or Shoebill too.

If you are looking for a prebuilt image that gets rid of the hard work installing A/UX and the tools you need, I recommend looking at this [GitHub](https://github.com/unxmaal/aux_sdcard) repo as a start. It's a bit of a chore to get this all set up from the ground up, so you might want to just save yourself the effort.

Once you have this on your A/UX system, you'll need to either copy or symlink `/usr/include/sys/errno.h` as both `errno.h` and `errnos.h` (or just place directory in your `PATH`). This is not included with the source code for copyright reasons.

When ready, type `make` in the console and it will take a few minutes to compile. It should place an executable named `auxdoom` in `./appleunix`.

To launch it, place the renamed `doom.wad` or `doom1.wad` in the same directory as `auxdoom` and then in that directory from a shell, type `./auxdoom`.

## Pre-compiled binary

Check the releases page of this repository.

## Thanks

Thanks to [NCommander](https://github.com/ncommander) for his [YouTube video about porting Doom to AIX](https://www.youtube.com/watch?v=XzhCGSE7KKw) which led me to port the game to A/UX.

Also to my Twitch followers for providing me input and guidance on getting this to work. This was not a solo effort at all so I appreciate you all!

