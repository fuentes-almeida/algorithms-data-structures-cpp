CCOMP=gcc		#compilador
CLINK=gcc		#linkeo
LFLAGS=-std=c99 	#bandera de debuggeo
CFLAGS=-std=c99	-c	#banderas de compilacion
EXEC=ejecutable
PDFDIR=docs
DOCDIR:=latex
OBJDIR:=obj
CFILEDIR:=src
BINDIR:=bin
DOCS:=$(wildcard $(PDFDIR)/*.*)
README:=$(wildcard $(DOCDIR)/*.tex)
CFILES:=$(wildcard $(CFILEDIR)/*.c)
LIBS:=$(wildcard $(CFILEDIR)/*.h)
OBJS:=$(patsubst $(CFILEDIR)/%.c,$(OBJDIR)/%.o,$(CFILES))
PDFS:=$(patsubst $(DOCDIR)/%.tex,$(PDFDIR)/%.pdf,$(README))
DIREXEC:=$(addprefix $(BINDIR)/,$(EXEC))

$(DIREXEC): $(OBJS) $(LIBS) $(PDFS)
	$(CCOMP) $(LFLAGS) -o $@ $(OBJS)

$(OBJDIR)/%.o: $(CFILEDIR)/%.c $(LIBS)
	$(CCOMP) $(CFLAGS) $< -o $@

optimized:
	make CFLAGS="-O2 -Wall -std=c99 -c"; LFLAGS="-O2 -Wall"

debugging:
	make CFLAGS="-g -std=c99 -c"; LFLAGS="-g -std=c99 -o"

clean:
	rm -f $(OBJS) $(DIREXEC) $(DOCS)

readme: $(PDFS)
	@echo $(PDFS)

$(PDFDIR)/%.pdf: $(DOCDIR)/%.tex
	pdflatex -output-directory=./docs $<

run:
	./bin/ejecutable
	
help:
	@echo 	"Archivos a compilar: obj/main.o  obj/listas.o  obj/memo.o y bin/ejecutable\n Opciones de compilacion: make, make optimized, make debugging"
