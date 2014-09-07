#!/bin/sh
echo Open Watcom Build Environment on Linux
echo cross compilation settings for NT target

export WATCOM=/opt/watcom
# WATCOM path is based on the location of
# Arch linux packages. Adjust if needed
export PATH=$WATCOM/binl:$PATH
export INCLUDE=$WATCOM/h:$WATCOM/h/nt:$INCLUDE
export EDPATH=$WATCOM/eddat
export WIPFC=$WATCOM/wipfc
