; EXTRN
extern	$_prints
; EXTRN
extern	$_printi
; EXTRN
extern	$_println
; EXTRN
extern	$_atoi
; DATA
segment	.data
; ALIGN
align	4
; LABEL
$cnt:
; INTEGER
	dd	0
; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$ackermann:function
; LABEL
$ackermann:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 1
; LOCAL
	lea	eax, [ebp+0]
	push	eax
; IMM
	push	dword 1
; ADD
	pop	eax
	add	dword [esp], eax
; COPY
	push	dword [esp]
; LOCAL
	lea	eax, [ebp+0]
	push	eax
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; TRASH
	add	esp, 4
; LOCAL
	lea	eax, [ebp+-4]
	push	eax
; POP
	pop	eax
; LEAVE
	leave
; RET
	ret
