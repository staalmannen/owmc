#!/bin/sh
echo Open Watcom Build Environment on Linux
echo cross compilation settings for NT target
# WATCOM path is based on the location of
# Arch linux packages. Adjust if needed
export PATH=/opt/watcom/binl:$PATH
export INCLUDE=/opt/watcom/h:/opt/watcom/h/nt:$INCLUDE
export WATCOM=/opt/watcom
export EDPATH=/opt/watcom/eddat
export WIPFC=/opt/watcom/wipfc
