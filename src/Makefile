###############################################################
#GNUSGO = gnugo.exe
GNUSGO = gnugo
#GOGA_T = goga-t.exe

#CC = cl /nologo /DHAVE_CONFIG_H  /DHAVE_VISUAL_C /DMYWINDOWS
#OPTS = ws2_32.lib
#OBJ = obj

CC = gcc -DHAVE_CONFIG_H
OPTS = -lm
OBJ = o

#-------------------------------------

OTHER_LIBS = T/engine.o T/sgf.o T/common.o T/gmp.o T/gtp.o 
PATTERNS_LIB = T/patterns1.o T/patterns2.o T/patterns3.o T/patterns4.o
LIBS = $(OTHER_LIBS) $(PATTERNS_LIB) 
#SOURCES = main.c 

###############################################################
#PROGS = $(GNUSGO) $(GOGA_T) client.dll
PROGS = $(GNUSGO)

all: $(PROGS)

###############################################################

$(GNUSGO): main.c $(LIBS) config.h sgf.h gmp.h gtp.h common.h engine.h 
	$(CC) -o $(GNUSGO) main.c $(LIBS) $(OPTS)
#------------------------------------------------------------- 
#client.dll: client.c client.h 
#	$(CC) /LD client.c
#-------------------------------------
#$(GOGA_T): goga-t.c client.c client.h
#	$(CC) -o $(GOGA_T) goga-t.c client.c
#-------------------------------------
T/common.o: common.c config.h 
	$(CC) -o $@ -c common.c 
#-------------------------------------
T/engine.o: engine.c config.h sgf.h common.h engine.h patterns.h
	$(CC) -o $@ -c engine.c 
#-------------------------------------
T/sgf.o: sgf.c config.h sgf.h common.h 
	$(CC) -o $@ -c sgf.c 
#-------------------------------------
T/gmp.o: gmp.c config.h gmp.h 
	$(CC) -o $@ -c gmp.c 
#-------------------------------------
T/gtp.o: gtp.c gtp.h 
	$(CC) -o $@ -c gtp.c 
#-------------------------------------
T/patterns1.o: patterns1.c config.h sgf.h engine.h patterns.h
	$(CC) -o $@ -c patterns1.c 
T/patterns2.o: patterns2.c config.h sgf.h engine.h patterns.h
	$(CC) -o $@ -c patterns2.c 
T/patterns3.o: patterns3.c config.h sgf.h engine.h patterns.h
	$(CC) -o $@ -c patterns3.c 
T/patterns4.o: patterns4.c config.h sgf.h engine.h patterns.h
	$(CC) -o $@ -c patterns4.c 
#-------------------------------------
###############################################################

clean :                                                                         
	rm -f *.exe *.obj *.dll *.exp *.lib *.o T/*.o *.a $(PROGS)   
#------------------------------------------------------------- 
edit :                                                                           
	xemacs goga-t.c client.c client.h Makefile               
#------------------------------------------------------------- 
save :  
	tar cvf savemin.tar *.c *.h Makefile
	gzip -6 savemin.tar  

###############################################################
