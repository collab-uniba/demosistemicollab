#!/bin/sh
##
# Author:      Bateman
# Date:      Jan. 28, 2015
# Ver:          0.1
## 

#Set Script Name variable
SCRIPT="filebot.sh"

# set default vars
PATH=""
LOG="/var/log/filebot.txt"
LANG="it"
FORMAT="srt"
TYPE=""


# print help instructions
print_help() {
        echo "Help documentation $SCRIPT"
        echo "Basic usage:"
        echo "Command line switches are mandatory. The following switches are recognized."
        echo "-t tv|movie  --Type of media to look subtitle for, admitted values are tv|movie. No default value is set."
        echo "-p path  --Sets the path where to look for media. No default value is set."
        echo "-h  --Displays this help message. No further functions are performed."
        echo "Example: $SCRIPT -t tv -p /volume1/video/tvshows"
        exit 1
}
                                                                                                

#Check the number of arguments. If none are passed, print help and exit.
#NUMARGS=$#
#if [ $NUMARGS -eq 0 ]; then
#  help;
#  fi

# parse args
#while getopts "t:p:h" FLAG; do
#      case $FLAG in
#       t) $TYPE = $OPTARG;;
#       p) PATH = $OPTARG;;
#       h) print_help;;
#      \?) #unrecognized option - show help
#                 echo "Use $SCRIPT -h to see the help documentation."
#              exit 2;;
#        esac
#done
#shift $((OPTIND-1))  #This tells getopts to move on to the next argument.
### end getopts code ###


# get new or missing subs
get_missing_subs() {
     echo "Finding missing subtitles from $TVPATH"
     filebot -script fn:suball -get-missing-subtitles --lang $LANG --format $FORMAT $TVPATH >> $LOG
     echo "Done"
        echo "\n------------------------\n" >> $LOG
}

# rename to chosen format
rename_in_path() {
     echo "Reneming new subtitles"
     filebot -r -script fn:replace --def "e=.ita.srt" "r=.it.srt" $TVPATH >> $LOG
     echo "Done"
     echo "\n------------------------\n" >> $LOG
}


### main loop to process files ###

# ...
#print_help;
echo "ciao"
### end main loop ###

exit 0
