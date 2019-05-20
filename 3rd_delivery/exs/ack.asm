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
global	$_ackermann:function
; LABEL
$_ackermann:
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
	lea	eax, [ebp+0]
	push	eax
; IMM
	push	dword 0
; EQ
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	sete	cl
	mov	[esp], ecx
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i1
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
; JMP
	jmp	dword $_i2
; LABEL
$_i1:
; LOCAL
	lea	eax, [ebp+0]
	push	eax
; IMM
	push	dword 0
; EQ
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	sete	cl
	mov	[esp], ecx
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i3
; IMM
	push	dword 1
; LOCAL
	lea	eax, [ebp+0]
	push	eax
; IMM
	push	dword 1
; SUB
	pop	eax
	sub	dword [esp], eax
; CALL
	call	$_ackermann
; TRASH
	add	esp, -4
; PUSH
	push	eax
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
; JMP
	jmp	dword $_i4
; LABEL
$_i3:
; LOCAL
	lea	eax, [ebp+0]
	push	eax
; IMM
	push	dword 1
; SUB
	pop	eax
	sub	dword [esp], eax
; LOCAL
	lea	eax, [ebp+0]
	push	eax
; CALL
	call	$_ackermann
; TRASH
	add	esp, -4
; PUSH
	push	eax
; LOCAL
	lea	eax, [ebp+0]
	push	eax
; IMM
	push	dword 1
; SUB
	pop	eax
	sub	dword [esp], eax
; CALL
	call	$_ackermann
; TRASH
	add	esp, -4
; PUSH
	push	eax
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
; LABEL
$_i4:
; LABEL
$_i2:
; LOCAL
	lea	eax, [ebp+-4]
	push	eax
; POP
	pop	eax
; LEAVE
	leave
; RET
	ret
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
	sub	esp, 1
; LOCAL
	lea	eax, [ebp+0]
	push	eax
; IMM
	push	dword 2
; GT
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setg	cl
	mov	[esp], ecx
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i5
; LOCAL
	lea	eax, [ebp+0]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 2
; IMM
	push	dword 4
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; ADD
	pop	eax
	add	dword [esp], eax
; CALL
	call	$_atoi
; TRASH
	add	esp, -4
; PUSH
	push	eax
; LOCAL
	lea	eax, [ebp+0]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 1
; IMM
	push	dword 4
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; ADD
	pop	eax
	add	dword [esp], eax
; CALL
	call	$_atoi
; TRASH
	add	esp, -4
; PUSH
	push	eax
; CALL
	call	$_ackermann
; TRASH
	add	esp, -4
; PUSH
	push	eax
; CALL
	call	$_printi
; TRASH
	add	esp, -4
; PUSH
	push	eax
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i6:
; CHAR
	db	0x20
; CHAR
	db	0x23
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i6
; CALL
	call	$_prints
; TRASH
	add	esp, -4
; PUSH
	push	eax
; TRASH
	add	esp, 4
; LOCAL
	lea	eax, [ebp+0]
	push	eax
; CALL
	call	$_printi
; TRASH
	add	esp, -4
; PUSH
	push	eax
; TRASH
	add	esp, 4
; CALL
	call	$_println
; TRASH
	add	esp, -1658557504
; TRASH
	add	esp, 4
; JMP
	jmp	dword $_i7
; LABEL
$_i5:
; IMM
	push	dword 0
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
