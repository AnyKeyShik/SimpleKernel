global load_gdt

gdt:
gdt_null:
	dq 0
	
gdt_code:
	dw 0FFFFh
	dw 0	
	db 0
	db 10011010b
	db 11001111b
	db 0
	
gdt_data:
	dw 0FFFFh
	dw 0	
	db 0
	db 10010010b
	db 11001111b
	db 0

gdt_end:
gdt_desc:
	dw gdt_end - gdt - 1
	dd gdt

load_gdt:
	lgdt [gdt_desc]
	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax

	jmp 0x08:flush

flush:
	retn
