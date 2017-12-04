cc=g++
exe=triangle_count.a
obj=triangle_count.o
dbg=gdb
$(exe):$(obj)
	$(cc) -o $(exe) $(obj)
$(obj): triangle_count.cpp
	$(cc) -c triangle_count.cpp
run:
	./triangle_count.a
clean:
	rm *.a
	rm *.o
	rm -r *.dSYM