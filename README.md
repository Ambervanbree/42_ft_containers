To test ft_containers you have 2 options at your disposal:

1. 	The main provided with the project. A binary for ft_containers and
	a binary for std_containers will be created. To launch and compare,
	execute the following commands in the root folder:

	make all                         // <--- creates both binaries (to make just one, execute "make ft" or "make std")
	time ./ft_containers <seed>
	time ./std_containers <seed>

2.	The tester that I have created with Googletest. It is a typed test,
	which means that for every test different types are passed, including
	both ft and stl types. There is also a performance test that is first
	run seperately with ft and stl types.
	
	To launch, execute the following commands in the root folder:

	git submodule update --init --recursive
	cd testing && mkdir build && cd build
	cmake .. -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles"
	make all
	./tests/ft_containers_tst

	To run subtests, the gtest filter can be used, below are some example 
	commands:
	./tests/ft_containers_tst --gtest_filter='Stack*'
	./tests/ft_containers_tst --gtest_filter='Vector*'
	./tests/ft_containers_tst --gtest_filter='Map*'
	./tests/ft_containers_tst --gtest_filter='Set*'
	./tests/ft_containers_tst --gtest_filter='*Performance*'

	You can find the executed tests for containers, iterators and other
	functions in their respective folders in "/testing/tests/"