[org 0x0100]

jmp start
num1: dd 40000, 0
num2: dd 20000
num3: dd 0, 0

start:

mov cx, 32	; N bit multiplication (Minimum 16)

mov dx, cx
shr dx, 2

l1:
mov bx, dx
shr bx, 1
sub bx, 2
mov si, 0

loop1:
shr si, 1
rcr word [num2+bx], 1
rcl si, 1
sub bx, 2
cmp bx, 0
jge loop1

mov bx, 0

check:
shr si, 1
jnc loop3

loop2:
shr si, 1
mov word ax, [num1+bx]
adc word [num3+bx], ax
rcl si, 1
add bx, 2
cmp bx, dx
jb loop2

mov bx, 0
mov si, 0

loop3:
shr si, 1
rcl word [num1+bx], 1
rcl si, 1
add bx, 2
cmp bx, dx
jb loop3
dec cx
cmp cx, 0
jnz l1

mov ax, 0x4c00
int 0x21
