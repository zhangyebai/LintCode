cc=clang++
exe=k_closest_points
obj=k_closest_points.o
dbg=lldb
$(exe):$(obj)
	$(cc) -o $(exe) $(obj)
k_closest_points.o: k_closest_points.cpp
	$(cc) -g -c -Wall -O2 -std=c++11 -stdlib=libc++ k_closest_points.cpp -o k_closest_points.o
clean:
	rm -fr *.o k_closest_points
	rm -fr *.dSYM k_closest_points
run:
	./k_closest_points
debug:
	$(dbg) k_closest_points