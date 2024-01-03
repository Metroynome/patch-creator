all:
	$(MAKE) -f ./Makefile.ntscu clean
	$(MAKE) -f ./Makefile.ntscu
	$(MAKE) -f ./Makefile.pal clean
	$(MAKE) -f ./Makefile.pal
	$(MAKE) -f ./Makefile.ntscu-proto clean
	$(MAKE) -f ./Makefile.ntscu-proto
	$(MAKE) -f ./Makefile.ntscj clean
	$(MAKE) -f ./Makefile.ntscj
	$(MAKE) -f ./Makefile.korean clean
	$(MAKE) -f ./Makefile.korean
	$(MAKE) -f ./Makefile.pal-proto clean
	$(MAKE) -f ./Makefile.pal-proto
	
clean:
	$(MAKE) -f ./Makefile.ntscu clean
	$(MAKE) -f ./Makefile.pal clean
	$(MAKE) -f ./Makefile.ntscu-proto clean
	$(MAKE) -f ./Makefile.ntscj clean
	$(MAKE) -f ./Makefile.korean clean
	$(MAKE) -f ./Makefile.pal-proto
	rm -f *.bin *.elf *.o
	rm -f -r bin/
	rm -f -r obj/