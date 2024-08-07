#!/bin/bash

rm ./ok

gcc main.c -o ok -L. -lbinheap -Wl,-rpath,.
