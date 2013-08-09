gtmalloc
========

Malloc library based on SQLite's memory allocation subsystem

Features:

1. low fragmentation
2. low metadata overhead, even on a system with mostly small allocations
3. minimal locking. maybe we can leverage thread local storage or synchronization free containers.
4. self-learning mode. each additional run will allow the application to learn the allocation strategies and use it to optimize future runs.
5. efficient multi core support. closely related to (3).
6. memory leak detection
6. support for c++ new
7. logging support
8. user defined callbacks. for example: OnMemoryLimitReached, OnAllocation, etc.
9. support user provided memory blocks
10. statistics :
	used memory
	free memory
	fragmentation level
	number of allocations/deallocation in current run
	run time control over feature activation
11.configuration through an interface and/or file
12.multi platform - windows & linux
13. allow the user to receive a memory allocation graph after the process exits
14. history : 
	allocation count
	deallocation count
	overall allocated bytes
	overall deallocated bytes
	memory leak count
	optional : provide a list of unique allocation locations, for comparison.

see :

	http://www.readability.com/articles/hbgiitam
	http://phk.freebsd.dk/pubs/malloc.pdf
