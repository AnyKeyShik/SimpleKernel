# Simple kernel 
This is my first attempt to write something great (again :D)

I want to learn how does OS work and this is main reason why I've started this project.

At this moment system is working in 32-bit protected mode only

When I started I adhered to the following principles:
---
* I don't want to write my own bootloader
* In start I support legacy only (like BIOS, non-gaming[3-buttons] mouse, 128-keybaord, etc)
* (maybe smth else)


Features
===
| Module                            | Progress      |
|-----------------------------------|---------------|
| Boot in BIOS                      | **DONE**      |
| Interrupt handling                | **DONE**      |
| Keyboard support                  | *In progress* |
| Boot in EFI                       | `TODO`        |
| POSIX support                     | `TODO`        |
| Simple analog `libc`              | `TODO`        |
| Memory management                 | `TODO`        |
| Filesystem                        | `TODO`        |
| Basic shell                       | `TODO`        |
| Users                             | `TODO`        |
| Simple text edtiro                | `TODO`        |
| Multiple processes and scheduling | `TODO`        |
| Networking                        | `TODO`        |

### Maybe in future:
* Bash interpreter
* GUI

# Running:
You can running this project with `qemu`. For this you can just run `make run`
