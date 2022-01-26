; Thomas Laughridge
; tcl5tu@virginia.edu
; 11/16/21
; 
; Parameter 1 is a pointer to the array :: rdi -> arr
; Parameter 2 is a pointer to the left index of the array :: rsi -> l
; Parameter 3 is a pointer to the right index of the array :: rdx -> r
; Parameter 4 is a pointer to the target :: rcx -> x
;

	global binarySearch

	section .text

binarySearch:
	cmp rsi, rdx 			; if l > r, goto notFound
	jg notFound

	lea rax, [rsi+rdx] 		; rax = mid, mid = (l + r) / 2
	shr rax, 1

	mov r10, [rdi+4*rax] 	; r10 = arr[mid]

	; IF
	cmp r10d, ecx 			; if arr[mid] > x, goto if
	jg if

	; ELIF
	cmp r10d, ecx 			; if arr[mid] < x, goto elif
	jl elif

	; ELSE
	ret 					; return mid

if:
	lea rdx, [rax-1] 		; r = mid-1
	jmp binarySearch 		; loop

elif:
	lea rsi, [rax+1] 		; l = mid+1
	jmp binarySearch 		; loop

notFound:
	mov rax, -1 			; return -1
	ret
