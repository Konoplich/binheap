#!/bin/sh

gcc -shared -o libbinheap.so -fPIC libbinheap.c

cp libbinheap.so ..
cp libbinheap.h ..
