; EXTRN
extern	$_prints
; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_entry:function
; LABEL
$_entry:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i1:
; CHAR
	db	0x48
; CHAR
	db	0x65
; CHAR
	db	0x6C
; CHAR
	db	0x6C
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x57
; CHAR
	db	0x6F
; CHAR
	db	0x72
; CHAR
	db	0x6C
; CHAR
	db	0x64
; CHAR
	db	0x21
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i1
; CALL
	call	$_prints
; TRASH
	add	esp, -4
; IMM
	push	dword 0
; LOCAL
	lea	eax, [ebp+-4]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; POP
	pop	eax
; LEAVE
	leave
; RET
	ret
