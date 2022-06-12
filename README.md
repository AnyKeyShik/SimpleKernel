# Simple kernel

<a href="https://github.com/AnyKeyShik/SimpleKernel/blob/master/LICENSE">
<img src ="https://img.shields.io/github/license/AnyKeyShik/SimpleKernel.svg" />
</a>
<a href="https://github.com/AnyKeyShik/SimpleKernel/stargazers">
<img src ="https://img.shields.io/github/stars/AnyKeyShik/SimpleKernel.svg" />
</a>
<a href="https://github.com/AnyKeyShik/SimpleKernel/network">
<img src ="https://img.shields.io/github/forks/AnyKeyShik/SimpleKernel.svg" />
</a>

[![Build Status](https://travis-ci.com/AnyKeyShik/SimpleKernel.svg?branch=master)](https://app.travis-ci.com/github/AnyKeyShik/SimpleKernel)

This is my first attempt to write something great (again :D)
I want to learn how does OS work and this is main reason why I've started this project. At this moment system is working
in 32-bit protected mode only

## Features

| Module                            | Progress      |
|-----------------------------------|---------------|
| Boot                              | **DONE**      |
| Basic work with screen            | **DONE**      |
| System journal                    | `TODO`        |
| Boot in x86_64                    | `TODO`        |
| Dynamic memory                    | `TODO`        |
| Switch to Protected Mode          | `TODO`        |
| Memory management                 | `TODO`        |
| Plug-n-Play support               | `TODO`        |
| Filesystem                        | `TODO`        |
| Multiple processes and scheduling | `TODO`        |
| Basic shell                       | `TODO`        |
| Simple analog `libc`              | `TODO`        |
| POSIX support                     | `TODO`        |
| Users                             | `TODO`        |
| Simple bootloader                 | `TODO`        |
| Networking                        | `TODO`        |

## Getting started

#### Requirements

To compile and run this project, you will need:

* the NASM assembler
* the GNU linker
* the GNU make
* GRUB bootloader
* xorriso
* a Linux x64 operating system

#### Running the code

Simply use the following commands in a terminal:

```
git clone https://github.com/AnyKeyShik/SimpleKernel.git
cd SimpleKernel
make
```
