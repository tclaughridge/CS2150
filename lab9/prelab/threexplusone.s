; Thomas Laughridge
; tcl5tu@virginia.edu
; 11/5/21
; 
; Parameter 1 (rdi) positive integer x to pass into subroutine
; 
; Optimizations: bit-shift used for division, lea used for multiplication and addition in one instr.
; 

	global threexplusone

	section .text

threexplusone:
	xor rax, rax 			; zero out rax

	cmp rdi, 1 				; base case, if x = 1 goto done
	je done

	push rdi 				; store x
	and rdi, 01 			; if x is even, goto even
	jz even

odd:
	pop rdi 				; revert x
	lea rdi, [rdi*3+1]		; x = 3x + 1
	call threexplusone 		; recursive call
	inc rax
	jmp done

even:
	pop rdi 				; revert x
	shr rdi, 1 				; x = x/2
	call threexplusone 	; recursive call
	inc rax

done:
	ret