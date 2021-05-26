SUBDIRS := a_mod b_mod

all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

#TO DO
#clean:


.PHONY: all clean $(SUBDIRS)

