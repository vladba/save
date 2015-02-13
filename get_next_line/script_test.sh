echo "                                                                               ";
sleep 0.1
echo "\033[0;31m        GGGGGGGGGGGGG     NNNNNNNN        NNNNNNNN     LLLLLLLLLLL             ";
sleep 0.1
echo "     GGG::::::::::::G     N:::::::N       N::::::N     L:::::::::L             ";
sleep 0.1
echo "   GG:::::::::::::::G     N::::::::N      N::::::N     L:::::::::L             ";
sleep 0.1
echo "  G:::::GGGGGGGG::::G     N:::::::::N     N::::::N     LL:::::::LL             ";
sleep 0.1
echo " G:::::G       GGGGGG     N::::::::::N    N::::::N       L:::::L               ";
sleep 0.1
echo "G:::::G                   N:::::::::::N   N::::::N       L:::::L               ";
sleep 0.1
echo "G:::::G                   N:::::::N::::N  N::::::N       L:::::L               ";
sleep 0.1
echo "G:::::G    GGGGGGGGGG     N::::::N N::::N N::::::N       L:::::L               ";
sleep 0.1
echo "G:::::G    G::::::::G     N::::::N  N::::N:::::::N       L:::::L               ";
sleep 0.1
echo "G:::::G    GGGGG::::G     N::::::N   N:::::::::::N       L:::::L               ";
sleep 0.1
echo "G:::::G        G::::G     N::::::N    N::::::::::N       L:::::L               ";
sleep 0.1
echo " G:::::G       G::::G     N::::::N     N:::::::::N       L:::::L         LLLLLL";
sleep 0.1
echo "  G:::::GGGGGGGG::::G     N::::::N      N::::::::N     LL:::::::LLLLLLLLL:::::L";
sleep 0.1
echo "   GG:::::::::::::::G     N::::::N       N:::::::N     L::::::::::::::::::::::L";
sleep 0.1
echo "     GGG::::::GGG:::G     N::::::N        N::::::N     L::::::::::::::::::::::L";
sleep 0.1
echo "        GGGGGG   GGGG     NNNNNNNN         NNNNNNN     LLLLLLLLLLLLLLLLLLLLLLLL";
sleep 0.1
echo "                                                                               ";
sleep 0.1
echo "\033[0;32m===============================================================================\033[0m"
sleep 0.1
echo "\033[0;32m   Tests Norme\033[0m"
sleep 0.1
echo "\033[0;32m===============================================================================\033[0m"
sleep 0.1
norminette get_next_line.c get_next_line.h
echo "-----"
echo "\033[0;32m===============================================================================\033[0m"
sleep 0.1
echo "\033[0;32m   Compilation libft\033[0m"
sleep 0.1
echo "\033[0;32m===============================================================================\033[0m"
make -C libft/ fclean > /dev/null
make -C libft/ > /dev/null
echo "-----"
sleep 0.1
echo "\033[0;32m===============================================================================\033[0m"
sleep 0.1
echo "\033[0;32m   Compilation Get_Next_Line\033[0m"
sleep 0.1
echo "\033[0;32m===============================================================================\033[0m"
sleep 0.1
gcc -Wall -Wextra -Werror -I libft/includes/ -c get_next_line.c
gcc -Wall -Wextra -Werror -I libft/includes/ -c main.c
gcc -o test_gnl get_next_line.o main.o -L libft/ -lft
sleep 1
echo "-----"
echo "\033[0;32m===============================================================================\033[0m"
sleep 0.1
echo "\033[0;32m   Tests Basiques\033[0m"
sleep 0.1
echo "\033[0;32m===============================================================================\033[0m"
sleep 0.1
echo "-----"
echo "\033[0;34m1 ligne de 8 caracteres depuis l'entree standard\033[0m"
echo "1234567" | ./test_gnl
echo "-----"
sleep 2
echo "\033[0;34m2 lignes de 8 caractere depuis l'entree standard\033[0m"
echo "1234567\n7654321" | ./test_gnl
echo "-----"
sleep 2
echo "\033[0;34m5 lignes de 8 caracteres depuis l'entree standard\033[0m"
echo "1234567\n7654321\nbonjour\nqwertee\nandroid" | ./test_gnl
echo "-----"
sleep 2
echo "\033[0;34m1 ligne de 8 caracteres depuis un fichier\033[0m"
echo "1234567" > test; ./test_gnl test
echo "-----"
sleep 2
echo "\033[0;34m2 ligne de 8 caracetres depuis un fichier\033[0m"
echo "1234567\n7654321" > test; ./test_gnl test
echo "-----"
sleep 2
echo "\033[0;34m5 ligne de 8 caracteres depuis un fichier\033[0m"
echo "1234567\n7654321\nbonjour\nqwertee\nandroid" > test; ./test_gnl test
echo "-----"
sleep 2
echo "\033[0;32m===============================================================================\033[0m"
sleep 0.1
echo "\033[0;32m   Tests Intermediaires\033[0m"
sleep 0.1
echo "\033[0;32m===============================================================================\033[0m"
sleep 0.1
echo "-----"
echo "\033[0;34m1 Ligne de 16 caracteres depuis un fichier\033[0m"
echo "jesuisunepatate" > test; ./test_gnl test
echo "-----"
sleep 2
echo "\033[0;34m2 Lignes de 16 caracteres depuis un fichier\033[0m"
echo "jesuisunepatate\nmynameisglados." > test; ./test_gnl test
echo "-----"
sleep 2
echo "\033[0;34m5 Lignes de 5 caracteres depuis un fichier\033[0m"
echo "jesuisunepatate\nmynameisglados.\n123456789123456\nabcdefghijklmn\nqwertyuiopasdfg" | ./test_gnl
echo "-----"
sleep 2
echo "\033[0;34m1 Ligne de 16 caracteres depuis l’entree stantard\033[0m"
echo "jesuisunepatate" > test; ./test_gnl test
echo "-----"
sleep 2
echo "\033[0;34m2 Lignes de 16 caracteres depuis l’entre standard\033[0m"
echo "jesuisunepatate\nmynameisglados." | ./test_gnl
echo "-----"
sleep 2
echo "\033[0;34m5 Lignes de 5 caracteres depuis l’entree standard\033[0m"
echo "jesuisunepatate\nmynameisglados.\n123456789123456\nabcdefghijklmn\nqwertyuiopasdfg" | ./test_gnl
echo "-----"
sleep 2
echo "\033[0;32m===============================================================================\033[0m"
sleep 0.1
echo "\033[0;32m   Tests Avances\033[0m"
sleep 0.1
echo "\033[0;32m===============================================================================\033[0m"
sleep 0.1
echo "-----"
echo "\033[0;34m1 ligne de 4 caracteres depuis un fichier\033[0m"
echo "123" > test; ./test_gnl test
echo "-----"
sleep 2
echo "\033[0;34m2 ligne de 4 caracetres depuis un fichier\033[0m"
echo "123\n321" > test; ./test_gnl test
echo "-----"
sleep 2
echo "\033[0;34m5 ligne de 4 caracteres depuis un fichier\033[0m"
echo "123\n321\nyop\nlol\nhey" > test; ./test_gnl test
echo "-----"
sleep 2
echo "\033[0;34m1 ligne de 4 caracteres depuis l'entree standard\033[0m"
echo "123" | ./test_gnl
echo "-----"
sleep 2
echo "\033[0;34m2 lignes de 4 caractere depuis l'entree standard\033[0m"
echo "123\n765" | ./test_gnl
echo "-----"
sleep 2
echo "\033[0;34m5 lignes de 4 caracteres depuis l'entree standard\033[0m"
echo "123\n765\nbon\nqwe\nand" | ./test_gnl
echo "-----"
sleep 2
echo "\033[0;34m1 ligne de 4 caracteres sans \\\n depuis un fichier\033[0m"
echo "1234\c" > test; ./test_gnl test
echo "-----"
sleep 2
echo "\033[0;34m1 ligne de 8 caracetres sans \\\n depuis un fichier\033[0m"
echo "12345678\c" > test; ./test_gnl test
echo "-----"
sleep 2
echo "\033[0;34m1 ligne de 16 caracteres sans \\\n depuis un fichier\033[0m"
echo "jesuisunepatate.\c" > test; ./test_gnl test
echo "-----"
sleep 2
echo "\033[0;34m1 ligne vide depuis l'entree standard\033[0m"
echo "" | ./test_gnl
echo "-----"
sleep 2
echo "\033[0;34m1 ligne vide depuis un fichier\033[0m"
echo "" > test; ./test_gnl test
echo "-----"
echo "\033[0;32mBy kefleury & tbeldame\033[0m"
rm test
