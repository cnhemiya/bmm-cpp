#!/usr/bin/bash

mainpage=mainpage.md
doxyfile=doc/Doxyfile

echo "@mainpage 使用说明" > $mainpage
cat ../README.md >> $mainpage

cd ..
doxygen $doxyfile

