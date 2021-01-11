true_path="$(dirname "$(realpath "$0")")"

on_error()
{
    echo "Build failed!"
    exit 1
}

printf "\e[93m === Starting Building === \e[39m\n"
bash $true_path/build_code.sh || on_error
printf "\e[93m === Starting Link === \e[39m\n"
make 
printf "\e[93m === Buiding Iso === \e[39m\n"
bash $true_path/build_test.sh || on_error