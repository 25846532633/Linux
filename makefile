processbar:Main.c Processbar.c
	gcc $^ -o $@
.PHONY:clean
clean:
	rm -rf processbar
