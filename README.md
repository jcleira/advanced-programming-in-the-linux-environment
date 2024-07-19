# advanced-programming-in-the-linux-environment
This is my personal repository notes for the cs631 course on Advanced Programming in the UNIX Environment [link](https://www.youtube.com/@cs631apue).

![Logo](https://i.imgur.com/89AULhB.jpeg)

## Bookmarks
- [Course website](https://stevens.netmeister.org/631/)

## Commands
### netBSD startup using QEMU
#### macOS
```bash
qemu-system-aarch64 -M virt -cpu cortex-a72 -m 1024 -smp 2 -bios /opt/homebrew/share/qemu/edk2-aarch64-code.fd \
-drive file=netbsd.qcow2,if=none,id=hd0 -device virtio-blk-device,drive=hd0 \
-cdrom ./NetBSD-10.0-evbarm-aarch64.iso -boot d -nographic

```

#### arch
```bash
qemu-system-x86_64 -enable-kvm -cpu host -m 2048 -smp 2 \
-drive file=netbsd.qcow2,if=virtio,format=qcow2 -netdev user,id=hn0,hostfwd=tcp::2222-:22,hostfwd=tcp::8080-:80 \
-device virtio-net,netdev=hn0 -cdrom NetBSD-10.0-amd64.iso -boot d -nographic --no-reboot

qemu-system-x86_64 -enable-kvm -M pc -cpu host -m 2048 -smp 2 \
-drive file=netbsd.qcow2,if=virtio,format=qcow2 -netdev user,id=hn0,hostfwd=tcp::2222-:22,hostfwd=tcp::8080-:80 \
-device virtio-net,netdev=hn0 -cdrom NetBSD-10.0-amd64.iso -boot d -nographic --no-reboot

sshPort=9696; qemu-system-x86_64 -machine pc,smm=off,vmport=off -nodefaults -no-user-config -parallel none -serial mon:stdio -cpu qemu64 -m 2048M -vga none -nographic -drive file=./netbsd.qcow2,if=virtio,discard=unmap,cache-size=16M,cache=writethrough -device virtio-net-pci,netdev=diktyo0 -netdev user,id=diktyo0,hostfwd=tcp:127.0.0.1:$sshPort-:22 -name "NetBSD 10" -cdrom NetBSD-10.0-amd64.iso -boot d -D qemu.log
```

## Installation
### 0 - Requirements
> This is a list of requirements for macOS or arch, the recommended way is using a VM but I'm using QEMU to run netBSD on my Mac.

#### macOS
##### 0.1 - Homebrew
```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```
##### 0.2 - QEMU
```bash
brew install qemu
```
##### 0.3 - Download the netBSD image
```bash
curl -LO https://cdn.netbsd.org/pub/NetBSD/NetBSD-10.0/images/NetBSD-10.0-evbarm-aarch64.iso
```

#### arch
##### 0.1 - Pacman
```bash
sudo pacman -S qemu qemu-system-aarch64 edk2-armvirt
```

##### 0.3 - Download the netBSD image
```bash
curl -LO http://cdn.netbsd.org/pub/NetBSD/NetBSD-10.0/images/NetBSD-10.0-amd64.iso
```

### 1 - netBSD Installationm using QEMU
#### 1.1 - Create a disk image
```bash
qemu-img create -f qcow2 netbsd.qcow2 10G
```

#### 1.2 - Start the VM with the netBSD image
##### macOS
```bash
qemu-system-aarch64 -M virt -cpu cortex-a72 -m 1024 -smp 2 -bios /opt/homebrew/share/qemu/edk2-aarch64-code.fd -drive file=netbsd.qcow2,if=none,id=hd0 -device virtio-blk-device,drive=hd0 -cdrom ./NetBSD-10.0-evbarm-aarch64.iso -boot d -nographic
```

##### arch
```bash
qemu-system-x86_64 -enable-kvm -M q35 -cpu host -m 2048 -smp 2 -bios /usr/share/edk2-ovmf/x64/OVMF.fd \
-drive file=netbsd.qcow2,if=virtio,format=qcow2 -netdev user,id=hn0,hostfwd=tcp::2222-:22,hostfwd=tcp::8080-:80 \
-device virtio-net,netdev=hn0 -cdrom NetBSD-10.0-amd64.iso -boot d -nographic --no-reboot

qemu-system-x86_64 -enable-kvm -M pc -cpu host -m 2048 -smp 2 \
-drive file=netbsd.qcow2,if=virtio,format=qcow2 -netdev user,id=hn0,hostfwd=tcp::2222-:22,hostfwd=tcp::8080-:80 \
-device virtio-net,netdev=hn0 -cdrom NetBSD-10.0-amd64.iso -boot d -nographic --no-reboot


```

#### 1.4 - Install netBSD
> Follow the installation steps, the default options are fine.
