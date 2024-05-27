# advanced-programming-in-the-linux-environment
This is my personal repository notes for the cs631 course on Advanced Programming in the UNIX Environment [link](https://www.youtube.com/@cs631apue).

![Logo](https://i.imgur.com/89AULhB.jpeg)

## Bookmarks
- [Course website](https://stevens.netmeister.org/631/)

## Commands
### netBSD startup using QEMU
```bash
qemu-system-aarch64 -M virt -cpu cortex-a72 -m 1024 -smp 2 -bios /opt/homebrew/share/qemu/edk2-aarch64-code.fd -drive file=netbsd.qcow2,if=none,id=hd0 -device virtio-blk-device,drive=hd0 -boot c -nographic
```

## Installation
### 0 - Requirements
> This is a list of requirements for macOS, the recommended way is using a VM but I'm using QEMU to run netBSD on my Mac.

#### 0.1 - Homebrew
```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

#### 0.2 - QEMU
```bash
brew install qemu
```

### 1 - netBSD Installationm using QEMU
#### 1.1 - Download the netBSD image
```bash
curl -LO https://cdn.netbsd.org/pub/NetBSD/NetBSD-10.0/images/NetBSD-10.0-evbarm-aarch64.iso
```

#### 1.2 - Create a disk image
```bash
qemu-img create -f qcow2 netbsd.qcow2 10G
```

#### 1.3 - Start the VM with the netBSD image
```bash
qemu-system-aarch64 -M virt -cpu cortex-a72 -m 1024 -smp 2 -bios /opt/homebrew/share/qemu/edk2-aarch64-code.fd -drive file=netbsd.qcow2,if=none,id=hd0 -device virtio-blk-device,drive=hd0 -cdrom ./NetBSD-10.0-evbarm-aarch64.iso -boot d -nographic
```

#### 1.4 - Install netBSD
> Follow the installation steps, the default options are fine.
