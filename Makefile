CC = wcc386
CFLAGS = -i. -aa -fp5 -oneaxl -ze -zq 
LINKER = wlink
LFLAGS = option quiet
LIBS = libport.lib libwine.lib

OBJS = mcl.obj mcy.tab.obj po.obj lang.obj utils.obj wmc.obj write.obj

.c.obj : .autodepend
    $(CC) $(CFLAGS) $<

owmc.exe : $(OBJS) $(LIBS)
    $(LINKER) $(LFLAGS) name $@ file { $< }

