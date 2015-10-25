echo "Total LOC for all files (including generated documentation files): $(find . -type f -exec cat {} \; | wc -l)"
echo "Total LOC for only .h files:                                       $(cat *.h | wc -l)"
echo "Total LOC for only .cpp files:                                     $(cat *.cpp | wc -l)"
echo "Total non-comment LOC for only .h files:                           $(cat *.h | grep -vE '^[[:blank:]]*[/\*]' | wc -l)"
echo "Total non-comment LOC for only .cpp files:                         $(cat *.cpp | grep -vE '^[[:blank:]]*[/\*]' | wc -l)"
echo "Total lines of block comments for .h and .cpp files:               $(cat *.cpp *.h  | grep -oE '^[ /]\*' | wc -l)"
echo "Total lines of single-line comments for .h and .cpp files:         $(cat *.cpp *.h  | grep -oE '^[[:blank:]]*//' | wc -l)"
echo "Total lines of non-comment code for .h and .cpp files:             $(cat *.cpp *.h  | grep -vE '^[[:blank:]]*[/\*]' | wc -l)"

