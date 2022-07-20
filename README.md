STILL UNDER CONSTRUCTION ........ 

To test ft_containers you have 2 options at your disposal:

1. 	The main provided with the projects. A binary for ft_containers and
	a binary for stl_containers will be created. To launch and compare,
	execute the following commands in the root folder:

	make
	./ft_containers > ft.txt && stl_containers > stl.txt
	diff ft.txt stl.txt

2.	The tester that I have created with Googletest. It is a typed test,
	which means that for every test different types are passed, including
	both ft and stl types. To launch, execute the following commands
	in the root folder:

	git submodule update --init --recursive
	mkdir build && cd build
	cmake .. -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles"
	make all
	./tests/ft_containers_tst

	You can find the executed tests for containers, iterators and other
	functions in their respective folders in "/testing/tests/"