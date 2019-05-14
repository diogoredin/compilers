; EXTRN
extern	$_println
; EXTRN
extern	$_prints
; EXTRN
extern	$_printi
; TEXT
segment	.text
; ALIGN
align	8
; LABEL
$x:
; INTEGER
	dd	12
; TEXT
segment	.text
; ALIGN
align	8
; LABEL
$y:
; INTEGER
	dd	45
; TEXT
segment	.text
; ALIGN
align	8
; LABEL
$s:
; STR
	db	' = ', 0
; TEXT
segment	.text
; ALIGN
align	8
; GLOBL
global	$_main:function
; LABEL
$_main:
; RODATA
segment	.rodata
; ALIGN
align	8
; LABEL
$_#i1:
; STR
	db	'x', 0
; TEXT
segment	.text
; ADDR
	mov	rax, $_#i1
	push	rax
; ARG1
	mov	rdi, [rsp+0]
; CALL
	call	$_prints
; TRASH
	add	rsp, 8
; ADDR
	mov	rax, $s
	push	rax
; ARG1
	mov	rdi, [rsp+0]
; CALL
	call	$_prints
; TRASH
	add	rsp, 8
; ADDRV
	mov	rax, [abs qword $x]
	push	rax
; ARG1
	mov	rdi, [rsp+0]
; CALL
	call	$_printi
; TRASH
	add	rsp, 8
; CALL
	call	$_println
; RODATA
segment	.rodata
; ALIGN
align	8
; LABEL
$_#i2:
; STR
	db	'y', 0
; TEXT
segment	.text
; ADDR
	mov	rax, $_#i2
	push	rax
; ARG1
	mov	rdi, [rsp+0]
; CALL
	call	$_prints
; TRASH
	add	rsp, 8
; ADDR
	mov	rax, $s
	push	rax
; ARG1
	mov	rdi, [rsp+0]
; CALL
	call	$_prints
; TRASH
	add	rsp, 8
; ADDRV
	mov	rax, [abs qword $y]
	push	rax
; ARG1
	mov	rdi, [rsp+0]
; CALL
	call	$_printi
; TRASH
	add	rsp, 8
; CALL
	call	$_println
; RODATA
segment	.rodata
; ALIGN
align	8
; LABEL
$_#i3:
; STR
	db	'x+y', 0
; TEXT
segment	.text
; ADDR
	mov	rax, $_#i3
	push	rax
; ARG1
	mov	rdi, [rsp+0]
; CALL
	call	$_prints
; TRASH
	add	rsp, 8
; ADDR
	mov	rax, $s
	push	rax
; ARG1
	mov	rdi, [rsp+0]
; CALL
	call	$_prints
; TRASH
	add	rsp, 8
; ADDRV
	mov	rax, [abs qword $x]
	push	rax
; ADDRV
	mov	rax, [abs qword $y]
	push	rax
; ADD
	pop	rax
	add	qword [rsp], rax
; ARG1
	mov	rdi, [rsp+0]
; CALL
	call	$_printi
; TRASH
	add	rsp, 8
; CALL
	call	$_println
; RODATA
segment	.rodata
; ALIGN
align	8
; LABEL
$_#i4:
; STR
	db	'x+y+7', 0
; TEXT
segment	.text
; ADDR
	mov	rax, $_#i4
	push	rax
; ARG1
	mov	rdi, [rsp+0]
; CALL
	call	$_prints
; TRASH
	add	rsp, 8
; ADDR
	mov	rax, $s
	push	rax
; ARG1
	mov	rdi, [rsp+0]
; CALL
	call	$_prints
; TRASH
	add	rsp, 8
; ADDRV
	mov	rax, [abs qword $x]
	push	rax
; ADDRV
	mov	rax, [abs qword $y]
	push	rax
; ADD
	pop	rax
	add	qword [rsp], rax
; IMM
	mov	rax, qword 7
	push	rax
; ADD
	pop	rax
	add	qword [rsp], rax
; ARG1
	mov	rdi, [rsp+0]
; CALL
	call	$_printi
; TRASH
	add	rsp, 8
; CALL
	call	$_println
; RODATA
segment	.rodata
; ALIGN
align	8
; LABEL
$_#i5:
; STR
	db	'dozen = ', 0
; TEXT
segment	.text
; ADDR
	mov	rax, $_#i5
	push	rax
; ARG1
	mov	rdi, [rsp+0]
; CALL
	call	$_prints
; TRASH
	add	rsp, 8
; IMM
	mov	rax, qword 12
	push	rax
; ARG1
	mov	rdi, [rsp+0]
; CALL
	call	$_printi
; TRASH
	add	rsp, 8
; CALL
	call	$_println
; IMM
	mov	rax, qword 0
	push	rax
; POP
	pop	rax
; RET
	ret
