CC = wcc386
CFLAGS = -i. -i.. -aa -fp5 -oneaxl -ze -zq -zw -bt=nt -d__WINESRC__
AR = wlib
ARFLAGS = -n

OBJS = ffs.obj fstatvfs.obj getopt1.obj lstat.obj memcpy_unaligned.obj mkstemps.obj pread.obj pwrite.obj readlink.obj statvfs.obj symlink.obj

.c.obj : .autodepend
    $(CC) $(CFLAGS) -fo=$*.obj $< 
    
libport.lib: $(OBJS)
    $(AR) $(ARFLAGS) -o $@ $(OBJS)
    
    
    
    
