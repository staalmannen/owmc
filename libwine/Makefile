CC = wcc386
CFLAGS = -i. -i.. -aa -fp5 -oneaxl -ze -zq -zw -bt=nt -d__WINESRC__ 
AR = wlib
ARFLAGS = -n 
OBJ=".obj"

C_OBJS = c_037.obj c_10000.obj c_10006.obj c_10007.obj c_10029.obj c_1006.obj c_10079.obj c_10081.obj c_1026.obj c_1250.obj c_1251.obj c_1252.obj c_1253.obj c_1254.obj c_1255.obj c_1256.obj c_1257.obj c_1258.obj c_1361.obj c_20127.obj c_20866.obj c_20932.obj c_21866.obj c_28591.obj c_28592.obj c_28593.obj c_28594.obj c_28595.obj c_28596.obj c_28597.obj c_28598.obj c_28599.obj c_28600.obj c_28603.obj c_28604.obj c_28605.obj c_28606.obj c_424.obj c_437.obj c_500.obj c_737.obj c_775.obj c_850.obj c_852.obj c_855.obj c_856.obj c_857.obj c_860.obj c_861.obj c_862.obj c_863.obj c_864.obj c_865.obj c_866.obj c_869.obj c_874.obj c_875.obj c_878.obj c_932.obj c_936.obj c_949.obj c_950.obj
OBJS = $(C_OBJS) casemap.obj collation.obj compose.obj cptable.obj fold.obj mbtowc.obj sortkey.obj string.obj utf8.obj wctomb.obj wctype.obj

#excluded debug.obj for now

.c.obj : .autodepend
    $(CC) $(CFLAGS) -fo=$*.obj $< 
    
libwine.lib: $(OBJS)
    $(AR) $(ARFLAGS) -o $@ $(OBJS)