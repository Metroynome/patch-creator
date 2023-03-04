all:
	$(MAKE) -f ./Makefile.ntsc clean
	$(MAKE) -f ./Makefile.ntsc
	$(MAKE) -f ./Makefile.pal clean
	$(MAKE) -f ./Makefile.pal
	
clean:
	$(MAKE) -f ./Makefile.ntsc clean
	$(MAKE) -f ./Makefile.pal clean
	rm -f *.bin *.elf *.o
	rm -rf linkfile
	rm -f -r bin/
	rm -f -r obj/