all:
	$(MAKE) -f ./Makefile.ntscu clean
	$(MAKE) -f ./Makefile.ntscu
	$(MAKE) -f ./Makefile.pal clean
	$(MAKE) -f ./Makefile.pal
	$(MAKE) -f ./Makefile.proto clean
	$(MAKE) -f ./Makefile.proto
	$(MAKE) -f ./Makefile.ntscj clean
	$(MAKE) -f ./Makefile.ntscj
	
clean:
	$(MAKE) -f ./Makefile.ntscu clean
	$(MAKE) -f ./Makefile.pal clean
	$(MAKE) -f ./Makefile.proto clean
	$(MAKE) -f ./Makefile.ntscj clean
	rm -f *.bin *.elf *.o
	rm -f -r bin/
	rm -f -r obj/