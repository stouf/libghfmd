# VARIABLES:
#
#	* DBG_FLAG		:	give the debug flags to use for GCC compilation
#	* DBG_CMD		:	give the binary to the desired debugger




all: test


################################################################################
# RUNS


# Launch all tests
test: test_ghfmd



# Test ghfmd
test_ghfmd: build_test_ghfmd
	$(DBG_CMD) ./bin/tests/ghfmd


################################################################################
# BUILDS


# Compile, without linking, the ghfmd.c
ghfmd.o: bin_directory
	gcc -Wall $(DBG_FLAG) -c\
		-o bin/ghfmd.o\
		sources/ghfmd.c
	
# Compile the test for ghfmd.c
build_test_ghfmd: ghfmd.o
	gcc -Wall $(DBG_FLAG)\
		-o bin/tests/ghfmd\
		bin/ghfmd.o tests/ghfmd.c tests/minunit.h


################################################################################
# UTILS


# Create the bin directory if it does not already exist
bin_directory:
	./utils/create_bin_directory

# Remove the binary directory
clean:
	rm -rf bin