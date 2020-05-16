#include <stdio.h>
#include <io.h>

int wordcount()//计算单词个数
{
	int ch;
	int word_num = 0;
	int flag = 0;
	char filename[] = "G://GitBase//WordCount//WordCount.txt";
	FILE* fp;
	if ((fp = fopen(filename, "r")) == NULL)//检验文本文档是否存在
	{
		printf("%s open failure", filename);
		return 0;
	}
	while (!feof(fp))//文档未到末尾
	{
		ch = fgetc(fp);//读取一个字符
		if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
			flag = 0;
		else if (flag == 0)
		{
			word_num++;
			flag = 1;
		}
	}
	fclose(fp);
	return word_num;
}
int littercount()
{
	int ch;
	int litter_num = 0;
	char filename[] = "G://GitBase//WordCount//WordCount.txt";
	FILE* fp;
	if ((fp = fopen(filename, "r")) == NULL)//检验文本文档是否存在
	{
		printf("%s open failure", filename);
		return 0;
	}
	while (!feof(fp))//文档未到末尾
	{
		ch = fgetc(fp);//读取一个字符
		if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
		{
			litter_num++;
		}
	}
	fclose(fp);
	return litter_num;
}
int main()
{
	int word_num = wordcount();//单词数
	int litter_num = littercount();//字母数
	printf("字母有%d个.\n", litter_num);
	printf("单词有%d个.\n", word_num);
}
