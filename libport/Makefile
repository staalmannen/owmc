CC = wcc386
CFLAGS = -i. -i.. -aa -fp5 -oneaxl -ze -zq -d__WINESRC__
AR = wlib
ARFLAGS = -n

OBJS = ffs.obj fstatvfs.obj getopt.obj getopt1.obj isinf.obj isnan.obj lstat.obj memcpy_unaligned.obj memmove.obj mkstemps.obj pread.obj pwrite.obj readlink.obj statvfs.obj strcasecmp.obj strerror.obj strncasecmp.obj symlink.obj usleep.obj

# interlocked.obj - not built, depends on pthread.h
#temporary disable spawn.obj and poll.obj

.c.obj : .autodepend
    $(CC) $(CFLAGS) $<
    
libport.lib: $(OBJS)
    $(AR) $(ARFLAGS) -o $@ $(OBJS)
    
    
    
    
