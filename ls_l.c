#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>
int main(int argc, char *argv[]){
struct dirent *dir;
struct stat fs;
struct passwd *pw;
struct group *gp;
stat(argv[1],&fs);
DIR *d = opendir(argv[1]);
if (d) {
while ((dir = readdir(d)) != NULL){
printf("%ld ",dir->d_ino);
stat(dir->d_name,&fs);
printf( (S_ISDIR(fs.st_mode)) ? "d" : "-");
printf( (fs.st_mode & S_IRUSR) ? "r" : "-");
printf( (fs.st_mode & S_IWUSR) ? "w" : "-");
printf( (fs.st_mode & S_IXUSR) ? "x" : "-");
printf( (fs.st_mode & S_IRGRP) ? "r" : "-");
printf( (fs.st_mode & S_IWGRP) ? "w" : "-");
printf( (fs.st_mode & S_IXGRP) ? "x" : "-");
printf( (fs.st_mode & S_IROTH) ? "r" : "-");
printf( (fs.st_mode & S_IWOTH) ? "w" : "-");
printf( (fs.st_mode & S_IXOTH) ? "x" : "-");
printf(" ");
pw=getpwuid(fs.st_uid);
printf("%s ",pw->pw_name);
gp=getgrgid(fs.st_gid);
printf("%s ",gp->gr_name);
printf("%ld ",fs.st_size);
char *c=ctime(&fs.st_mtime);
for(int i =5; i<17; i++) {printf("%c",c[i-1]);}
printf(" ");
printf("%s ",dir->d_name);
printf("\n");
}
closedir(d);
}
return(0);
}
