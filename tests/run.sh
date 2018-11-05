#!/bin/sh
export DYLD_LIBRARY_PATH="/sgoinfre/goinfre/Perso/sbonnefo/Documents/malloc2"
export DYLD_INSERT_LIBRARIES="/sgoinfre/goinfre/Perso/sbonnefo/Documents/malloc2/libft_malloc.so"
export DYLD_FORCE_FLAT_NAMESPACE=1
$@
