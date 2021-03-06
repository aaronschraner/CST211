#!/bin/bash
author="Aaron Schraner"
labno="" #lab number
assno="" #assignment number
tempargs=""
tempnames=""

openheader()
{
	echo "/********************************************************************************"
}

fileheader()
{
	#only parameter is filename
	openheader
	echo " * Author:            $author"
	echo " * Date Created:      $(date "+%B %e, %Y")"
	echo " * Last Modified:     $(date "+%B %e, %Y")"
	[ -n "$labno" ] && 
	echo " * Lab Number:        $labno" ||
		echo " * Assignment number: $assno"
	echo " * Filename:          $1"
	echo " * "
}

lpref=""

ioheader()
{
	#only parameter is output filename
	[ -n "$lpref" ] || lpref=" * 	"
	outfile="$1"
	shift
	fields=($*)

	echo "Please keep comments behind this line  (^D to move to next section)--------------|"
	for n in $(seq 0 $(($# - 1)))
	do
		echo "${lpref}${fields[n]}: " | tee -a "$outfile"
		echo -n "${lpref}	"
		cat | while read ln
	do
		echo "${lpref}	$ln" >> "$outfile"
		echo -n "${lpref}	"
	done
	echo ""
	echo "$lpref" >> "$outfile"
done
}

closeheader()
{
	echo " ********************************************************************************/"
}

includefiles()
{
	echo "#include <iostream>"

}

classheader()
{
	#TODO: interactively ask for method headers
	#first arg is dec file
	if [ ! -d ".doc" ]
	then
		mkdir .doc
	fi
	echo -e "Enter each member function for $classname in the format
	FunctionName( arg1name: arg1type, arg2name: arg2type): returnType"
	echo " * Class: $classname" >> "$1"
	echo " * " >> "$1"
	echo " * Methods: " >> "$1"
	echo -ne "Please keep comments behind this line  (^D to move to next section)--------------|\n> "
	cat | while read fnname
	do
		decname="$(echo "$fnname" | sed -r "s/ / /g;s/^(.*)(\(.*\)):(.*)/\3 \1 \2/g;s/([a-zA-Z0-9_]*)\:([^,\:\)]*)/\2 \1/g;s/, ?/, /g")"
		implname="$(echo "$decname" | sed -r "s/([a-zA-Z_0-9]*) \(/${classname}${tempnames}::\1 \(/g")"
		echo "$decname" >> .doc/_${classname}_dec_methods

		if [ $template == y ]
		then
			echo -n "$tempargs" >> .doc/_${classname}_impl_methods
		fi
		echo "$implname" >> .doc/_${classname}_impl_methods
		echo " *     $decname:" >> "$1"
		echo "What does it do? (one line description)"
		echo -n " *         "
		read ln
		echo -ne " *         $ln\n * \n" >> "$1"
		echo -ne "Added to class\n> "
	done
	echo " * " >> "$1"
}

mkclass()
{
		#get the name of the class
		classname=""
		[ -n "$1" ] && classname="$1" || {

		echo -en "Enter name of class (should be CamelCase, ex: MyClassName)\n> "; 
		read cn
		classname="$cn"
	}

	echo -en "Is this class a templated class? (y/n)\n[y|n]> "
	read resp
	[[ $resp =~ ^[yY] ]] && template="y" || template="n"

	#set the name of the class declaration file
	classdecfile="${classname}.h"

	#set the name of the class implementation file
	classimplfile=""
	if [ "$template" == "y" ]
	then
		classimplfile="${classname}_impl.h"
	else
		classimplfile="${classname}.cpp"
	fi

	echo "Class name: \"$classname\", Declaration file: \"$classdecfile\", Implementation file: \"$classimplfile\""

	#comment block header for declaration and implementation
	fileheader "$classdecfile" > "$classdecfile"
	fileheader "$classimplfile" > "$classimplfile"
	classheader "$classdecfile" 
	closeheader | tee -a "$classdecfile" "$classimplfile"


	#ifdef blocks
	defname="$(echo ${classdecfile} | sed 's/\./_/g;s/\(.*\)/\U\1/g')"
	echo "#ifndef $defname" >> "$classdecfile"
	echo "#define $defname" >> "$classdecfile"

	if [ "$template" == "y" ]
	then
		impldefname="$(echo "${classimplfile}" | sed -r 's/\./_/g;s/(.*)/\U\1/g')"
		echo "#ifndef $impldefname" >> "$classimplfile"
		echo "#define $impldefname" >> "$classimplfile"
	fi

	#includes
	echo "List the files / libraries you want to include in the implementation. (<libname> for external libs and \"filename\" for local files)"
	[ "$template" == "y" ] || echo "#include \"$classdecfile\"" |  tee -a "$classimplfile"
	echo -n "#include "
	while read incfile
	do
		echo "#include $incfile" >> "$classimplfile"
		echo -n "#include "
	done
	echo "" | tee -a "$classimplfile"

	#template arguments
	if [ "$template" == "y" ]
	then
		echo -ne "List the template argument names for this class (space separated)\n> "
		read tempnames
		tempargs="template < typename $(echo $tempargs | sed 's/ /, typename /g') >"
		tempnames="<$(echo "$tempnames" | sed 's/ /, /g' )>"
		echo "$tempargs" >> "$classdecfile"
	fi

	#class declaration
	(
	echo -e "class $classname\n{" 
	echo -e "    private:"
	echo -e "        //TODO: add member variables\n" 
	echo -e "    public:"
	) >> "$classdecfile"
	cat .doc/_${classname}_dec_methods | 
	while read method
	do
		echo "        //TODO: brief description" >> "$classdecfile"
		echo -e "        $method;\n" >> "$classdecfile"
	done

	echo -e "};" >> "$classdecfile"

	cat .doc/_${classname}_impl_methods |
	while read method
	do
		echo "//TODO: make method comment blocks" >> "$classimplfile"
		[ "$template" == "y" ] && echo "$tempargs" >> "$classimplfile"
		echo -e "$method\n{\n    //TODO\n}\n"  >> "$classimplfile"
	done


	#footer stuff
	[ "$template" == "y" ] && 
		echo -e "#include \"$classimplfile\"\n" >> "$classdecfile"  && 
		echo -e "#endif\n" >> "$classimplfile"

	echo -e "#endif\n" >> "$classdecfile"
	


}

#echo -ne "Is this a lab or assignment?\n> "
#{
#
#	read resp
#	if [[ $resp =~ ^[lL] ]]
#	then
#		echo -ne "What is the name/number of this lab?\n> "
#		read labno
#	else
#		echo -ne "What is the name/number of this assignment?\n> "
#		read assno
#	fi
#}
#mkclass

for class in Iterator Node LinkedList
do
	mkdir -p .doc/funcs/$class; cat "${class}.h" | grep -o "^\t*.*(.*).*;" | sed "s/^\t\t//g" | while read x; do echo -e "$x" > ".doc/funcs/$class/$(echo "$x" | grep -o "[\~a-zA-Z_=*+\-]* \?(.*) \(const\)\?")"; done
done

for x in .doc/funcs/*/*
do
	sig="$(cat "$x")"
	echo "Documentation for $sig"
	openheader > "$x"
	echo " * $sig" >> "$x"
	ioheader "$x" Purpose Entry Exit
	closeheader >> "$x"
done

