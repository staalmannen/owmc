CC = wcc386
CFLAGS = -i. -aa -fp5 -oneaxl -ze -zq -zw -bt=nt
LINKER = wlink
LFLAGS = option quiet
LIBS = libport/libport.lib libwine/libwine.lib
OBJ=".obj"

OBJS = mcl.obj mcy.tab.obj po.obj lang.obj utils.obj wmc.obj write.obj

.c.obj : .autodepend
	$(CC) $(CFLAGS) -fo=$*.obj $< 
	
default: libwine.lib libport.lib owmc.exe .symbolic

libwine.lib: .symbolic
	cd libwine && wmake
	
libport.lib : .symbolic
	cd libport && wmake
	
owmc.exe : $(OBJS) $(LIBS)
	$(LINKER) $(LFLAGS) name $@ file { $< }

clean : .symbolic
	rm -f *.obj *.exe *.err
	rm -f libwine/*.obj libwine/*.lib libwine/*.err
	rm -f libport/*.obj libport/*.lib libport/*.err
	