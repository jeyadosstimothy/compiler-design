filename=$1
flex $filename".l"
bison $filename".y"
gcc $filename".tab.c" -lfl