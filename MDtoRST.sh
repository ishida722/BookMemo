#!/bin/sh

for file in *.m*d; do
    pandoc -o ${file%.m*d}.rst $file
    done
