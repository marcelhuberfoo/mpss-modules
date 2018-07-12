Intel MPSS 3.8.2 for Linux <= 4.10.x
====================================

This repository contains Intel MPSS 3.8.2 modules.
The source is patched to work with Linux Kernels up to 4.10.x.
It was tested using Kernel version 4.10.13 (not tested with newer kernel versions).

Requirements
------------

Before building the kernel modules, make sure you have all tools necessary to
build the Linux Kernel (e.g., GCC, Make, etc.) and the kernel source or
headers.

Building and Installing
-----------------------

To build, simply run make:

`$ make`

To install, you must be logged in as root or use sudo:

`# make install`
`$ sudo make install`
