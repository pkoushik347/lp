awk '{w+=NF ; c+=length($0)}
END{print("Lines,Words,Characters:",NR,w,c)}' $1
