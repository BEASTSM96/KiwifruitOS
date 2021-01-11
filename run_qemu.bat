@echo off

qemu-system-i386 -cdrom Kiwifruit.iso -debugcon stdio ^  -serial file:log.txt ^ -vga std

exit 0

:error
popd
exit 1

