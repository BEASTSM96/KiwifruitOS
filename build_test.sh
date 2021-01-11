cp grub.cfg isodir/boot/grub/grub.cfg
cp KiwifruitOS.bin isodir/boot/Kiwifruit.bin

grub-mkrescue -o Kiwifruit.iso isodir