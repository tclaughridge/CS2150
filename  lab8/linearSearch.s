; Thomas Laughridge
; tcl5tu@virginia.edu
; 11/2/21
; 
; Parameter 1: arr - rdi
; Parameter 2: size - rsi
; Parameter 3: target - rdx

	global linearSearch

	section .text

linearSearch:
	xor rax, rax 			; zero out the return register
	xor r10, r10			; zero out the counter i

iterate:
	cmp r10, rsi  			; is i > size?
	je notFound				; if so, goto notFound

	mov ebx, [rdi+4*r10]
	cmp rdx, rbx			; does target == arr[i]?
	je found 				; if so, goto found

	inc r10 				; i++
	jmp iterate				; loop

found:
	mov rax, r10			; rax = index
	ret 					; return rax

notFound:
	dec rax					; rax = -1
	ret 					; return rax