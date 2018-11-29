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
If you want to running in `qemu` you can just run `make run`

If you want to add this system to GRUB (at this moment it did not recomended because system boot works only from BIOS and adding was released with not-effective method):
* If you have GRUB older than 2.0 run `make old-install` as root
* If your GRUB is 2.0 or higher run `make install` as root
