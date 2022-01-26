; Thomas Laughridge
; tcl5tu@virginia.edu
; 11/1/21
; 
; Parameter 1 in rdi
; Parameter 2 in rsi
;

	global product, power

	section .text

product:
	; Subroutine body:
	xor rax, rax 		; zero out the return register
	xor r10, r10		; zero out the counter i

pro_iterate:
	cmp	r10, rsi		; does i == n?
	je	pro_done		; if so, we are done with the loop
	add	rax, rdi		; add rdi to rax
	inc	r10		 		; increment our counter i
	jmp	pro_iterate		; we are done with this loop iteration

pro_done:
	; return value is already in rax
	; no callee-saved registers to restore
	; no local variables to deallocate
	ret


; ------------------------------------------------------------


power:
	; Subroutine body:
	xor rax, rax 		; zero out the return register
	mov rax, 1 			; set rax to one

pow_start:
	cmp rsi, 0 			; does rsi == 0?
	je pow_done 		; if so, return rax

pow_recurse:
	dec rsi 			; rsi -= 1
	call power 			; recursive call, return register = power(rdi, rsi-1)
	mov rsi, rax 		; move rax into rsi
	call product 		; call product to multiply rsi and rdi

pow_done:
	; return value is already in rax
	; no callee-saved registers to restore
	; no local variables to deallocate
	ret