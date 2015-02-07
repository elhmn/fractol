# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    check.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcanal <zboub@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/07 01:07:39 by mcanal            #+#    #+#              #
#    Updated: 2015/02/07 01:19:56 by bmbarga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
    
cat -e auteur | grep -v $USER >> auteur_test;
grep -R "   Created: " * | grep -v $USER >> auteur_test;
grep -R "   Updated: " * | grep -v $USER >> auteur_test;
grep -R "   By: " * | grep -v $USER >> auteur_test;
FILE_SIZE=$(du auteur_test | awk '{ print $1 }');
if [ "$FILE_SIZE" = 0 ]; then
	echo "\033[37;01mTesting auteur \033[32;01mOK\033[0m";
else
	echo "\033[37;01mTesting auteur \033[31;01mKO\033[0m";
	cat auteur_test
fi
rm auteur_test;
echo "";

norminette * > norm_test;
cat norm_test | grep -v "Norme: " | grep -v "can't check this file" > norm_test2;
FILE_SIZE=$(du norm_test2 | awk '{ print $1 }');
if [ "$FILE_SIZE" = 0 ]; then
	echo "\033[37;01mTesting norme \033[32;01mOK\033[0m";
else
	echo "\033[37;01mTesting norme \033[31;01mKO\033[0m";
	cat norm_test2 | grep --color=auto "Warning"
	cat norm_test | grep --color=auto -C 1 "Error"
fi
rm norm_test;
rm norm_test2;
echo "";
