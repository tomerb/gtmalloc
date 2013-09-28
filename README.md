gtmalloc
========

Malloc library based on SQLite's memory allocation subsystem

Features:

1. Low fragmentation.
2. Low metadata overhead, even on a system with mostly small allocations.
3. Minimal locking. maybe we can leverage thread local storage or synchronization free containers.
4. Self-learning mode. each additional run will allow the application to learn the allocation strategies and use it to optimize future runs.
5. Efficient multi core support. closely related to (3).
6. Memory leak detection.
6. Support for C++ new.
7. Logging support.
8. User defined callbacks. for example: OnMemoryLimitReached, OnAllocation, etc.
9. Support user provided memory blocks.
10. Statistics:
	used memory
	free memory
	fragmentation level
	number of allocations/deallocation in current run
	run time control over feature activation
11. Configuration through an interface and/or file.
12. Multi platform - Windows & Linux.
13. Allow the user to receive a memory allocation graph after the process exits.
14. History:
	allocation count
	deallocation count
	overall allocated bytes
	overall deallocated bytes
	memory leak count
	optional : provide a list of unique allocation locations, for comparison

See:

	http://www.readability.com/articles/hbgiitam
	http://phk.freebsd.dk/pubs/malloc.pdf
