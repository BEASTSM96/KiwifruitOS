true_path="$(dirname "$(realpath "$0")")"

on_error()
{
    echo "Build failed!"
    exit 1
}


echo ==============BuildingBoot==============
i686-elf-as $true_path/Boot/kiwiboot.s -o bin/kiwiboot.o || on_error

echo ==============BuildingKernel==============
echo ==============BuildingKernelBase[1/3]==============
echo ==============BuildingKernelBase[2/3]==============
i686-elf-g++ -c $true_path/Kernel/kernel.cpp -o bin/kernel.o -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti || on_error
echo ==============BuildingKernelBase[3/3]==============