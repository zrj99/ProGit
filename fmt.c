#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* files[] = {
	"D:\\GitApp\\ProGit\\0-ProGit.html",
	"D:\\GitApp\\ProGit\\1-Git起步.html",
	"D:\\GitApp\\ProGit\\2-Git基础.html",
	"D:\\GitApp\\ProGit\\3-Git分支.html",
	"D:\\GitApp\\ProGit\\4-服务器上的Git.html",
	"D:\\GitApp\\ProGit\\5-分布式Git.html",
	"D:\\GitApp\\ProGit\\6-Git工具.html",
	"D:\\GitApp\\ProGit\\7-自定义Git.html",
	"D:\\GitApp\\ProGit\\8-Git与其他系统.html",
	"D:\\GitApp\\ProGit\\9-Git内部原理.html"
};

// 显示各个标签及所在id
void printTags(const char *buf, int id)
{
	char *p1 = strchr(buf, '<');
	while (p1 != NULL){
		char *p2 = strchr(p1, '>');
		if (p2 != NULL){
			printf("%.*s (%d)\n", p2-p1+1, p1, id);

			p1 = strchr(p2+1, '<');
		}
		else {
			break;
		}
	}
}

void doit(int fid)
{
	FILE *fp = fopen(files[fid], "rb");
	if (!fp) return;

	long int fsize = 0;
	fseek(fp, 0, SEEK_END);
	fsize = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	char *buf = (char *)malloc(fsize + 1);
	fread(buf, 1, fsize, fp);
	buf[fsize] = 0;
	printTags(buf, fid);
	free(buf);

	fclose(fp);
}

int main(int argc, char *argv[])
{
	for (int i = 0; i < 10; ++i)
		doit(i);
	
	return 0;
}
