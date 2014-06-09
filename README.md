Y/N
---

Y/N (Yes/No) is a simple utility to allow humans to quickly filter images within a shell script. Each image is displayed to the user, who presses Y (for yes), N (for no) or Esc to quit.

Every file name which Y is pressed for is printed out. This allows, for example, selection of a subset of screen captures.

Compilation
===========
The utility requires opencv. On Debian, this can be installed with:

        apt-get install libopencv-dev

Then clone and compile via the included Makefile:

        git clone https://github.com/mike42/yn
        cd yn && make

Although only tested on UNIX, the program should run on Windows without modification.

Example usage
=============

A bash script which takes matching images and produces thumbnails (via ImageMagick), outputting HTML for blogging:

        #!/bin/bash
        
        # Basic options
        source=source
        dest=images
        ext=".png"
        geometry="150"
        
        # Make dest and find out what images to keep
        mkdir -p "$dest"
        keep=`./yn "$source"/*$ext`
        for orig in $keep
        do
        	# Figure out image parameters
        	slug=`basename "$orig" "$ext"`
        	large="$dest/$slug$ext"
        	thumb="$dest/$slug-small$ext"
            
        	# Copy over to dest and make thumbnail
        	cp "$orig" "$large"
        	convert "$large" -resize "${geometry}x" "$thumb"
            
        	# Make some HTML that could be blogged to include these
        	echo "<a href=\"$large\"><img alt=\"$slug\" width=\"${geometry}px\" src=\"$thumb\" /></a>"
        done

