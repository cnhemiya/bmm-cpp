#!/usr/bin/bash

mainpage=mainpage.md
echo "@mainpage 使用说明" > $mainpage
cat ../README.md >> $mainpage
