#!/usr/bin/bash

./make-mainpage.sh

cd ..
doxygen doc/Doxyfile

