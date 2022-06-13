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
I want to learn how does OS work and this is main reason why I've started this project. At this moment system is targeted for Intel i80386 (Real mode).

## Versioning

### Version 0.1:
- [x] Boot
- [x] Basic work with screen
### Version 0.2:
- [ ] System journal
- [ ] Dynamic memory
### Version 0.3:
- [ ] Switch to Protected Mode
- [ ] Memory management
### Version 0.4:
- [ ] Switch to Long Mode
- [ ] Memory management
### Version 0.5:
- [ ] Plug-n-Play support
- [ ] Filesystem
### Version 0.6:
- [ ] Simple analog `libc`
- [ ] POSIX support 
### Version 0.7:
- [ ] Multiple processes and scheduling
- [ ] POSIX support 
### Version 0.8:
- [ ] Basic shell
- [ ] Users
### Version 0.9:
- [ ] Simple bootloader
### Version 0.9:
- [ ] Network

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
