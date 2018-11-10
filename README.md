# Simple kernel 
This is my first attempt to write something great (again :D)
I want to learn how does OS work and this is main reason why I've started this project.

At this moment system is working in 32-bit protected mode only

When I started I adhered to the following principles:
---
* I don't want to write my own bootloader
* (maybe smth else)


Features
===
|   Module                              |   Progress    |
|---------------------------------------|---------------|
|   Boot                                |   **DONE**    |
|   Interrupt handling                  |   **DONE**    |
|   Keyboard support                    | *In progress* |
|   POSIX support                       |   `TODO`      |
|   Simple analog `libc`                |   `TODO`      |
|   Memory management                   |   `TODO`      |
|   Filesystem                          |   `TODO`      |
|   Basic shell                         |   `TODO`      |
|   Users                               |   `TODO`      |
|   Simple text edtiro                  |   `TODO`      |
|   Multiple processes and scheduling   |   `TODO`      |
|   Networking                          |   `TODO`      |

### Maybe in future:
* Bash interpreter
* GUI

# Make and run:
* `git clone https://github.com/AnyKeyShik/SimpleKernel.git`
* `make`
* `make run`
If you don't like objects files you can run `make clean`
