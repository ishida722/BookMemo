#!/bin/sh
echo title > index.rst
echo =================== >> index.rst
echo .. toctree:: >> index.rst
echo "    :maxdepth: 2" >> index.rst
echo " " >> index.rst

for file in *.rst; do
    echo "    ${file%.rst}" >> index.rst
    done
