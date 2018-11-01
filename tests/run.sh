#!/bin/sh
export DYLD_LIBRARY_PATH="/Users/Administrateur/Documents/42/malloc2"
export DYLD_INSERT_LIBRARIES="/Users/Administrateur/Documents/42/malloc2/libft_malloc.so"
export DYLD_FORCE_FLAT_NAMESPACE=1
$@
