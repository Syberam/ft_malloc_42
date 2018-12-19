#!/bin/sh
export DYLD_LIBRARY_PATH=`pwd`"/malloc2"
export DYLD_INSERT_LIBRARIES=`pwd`"/libft_malloc.so"
export DYLD_FORCE_FLAT_NAMESPACE=1
$@
