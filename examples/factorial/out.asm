; EXTRN
extern	$prints
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
	sub	esp, 8
; IMM
	push	dword 1
; COPY
	push	dword [esp]
; LOCAL
	lea	eax, [ebp+-8]
	push	eax
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; TRASH
	add	esp, 4
; LABEL
$_c5:
; LOCAL
	lea	eax, [ebp+-8]
	push	eax
; INCR
	pop	eax
	add	dword [eax], 1
; TRASH
	add	esp, 4
; LABEL
$_c5:
; LOCAL
	lea	eax, [ebp+-8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 3
; JLE
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jle	near $_i1
; JMP
	jmp	dword $_c2
; LABEL
$_i1:
; LABEL
$_c5:
; JMP
	jmp	dword $_c1
; IMM
	push	dword 0
; JNZ
	pop	eax
	cmp	eax, byte 0
	jne	near $_c5
; LABEL
$_c6:
; IMM
	push	dword 0
; JNZ
	pop	eax
	cmp	eax, byte 0
	jne	near $_c5
; LABEL
$_c6:
; IMM
	push	dword 0
; JNZ
	pop	eax
	cmp	eax, byte 0
	jne	near $_c5
; LABEL
$_c6:
; IMM
	push	dword 0
; COPY
	push	dword [esp]
; LOCAL
	lea	eax, [ebp+-4]
	push	eax
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; TRASH
	add	esp, 4
; LEAVE
	leave
; RET
	ret
