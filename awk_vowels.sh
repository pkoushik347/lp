count=0
awk '$0!~/[aeiou]/{ count++ }
END{print "The number of lines that do not contain vowels are: ",count}' $1
