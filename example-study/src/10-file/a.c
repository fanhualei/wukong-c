/**
 * 文件操作
 * https://www.runoob.com/cprogramming/c-file-io.html
 * C语言中函数返回字符串的四种方法:https://www.cnblogs.com/qingergege/p/6496683.html
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * 得到文件名称
 */
void getFileName(char *ren)
{
   int index = strlen(__FILE__) - strlen(strrchr(__FILE__, '/') + 1);
   char path[index + 1];
   strxfrm(path, __FILE__, index);
   path[index] = '\0';

   //得到文件名
   char fileName[] = "test.txt";
   char fullFileName[strlen(path) + strlen(fileName) + 1];
   strcpy(fullFileName, path);
   strcat(fullFileName, fileName);

   //将数据返回给指针
   strcpy(ren, fullFileName);
}

/**
 * 写文件
 */
void writeFile()
{
   char filename[265];
   getFileName(filename);
   printf("%s\n", filename);
   // 写入文件
   FILE *fp = NULL;
   fp = fopen(filename, "w+");
   fprintf(fp, "This is testing for fprintf...\n");
   fputs("This is testing for fputs...\n", fp);
   fclose(fp);
   return 0;
}

/**
 * 读文件
 */
void readFile()
{
   char filename[256];
   getFileName(filename);
   printf("%s\n", filename);
   int c;
   FILE *fp;
   fp = fopen(filename, "r");
   fpos_t position;
   while (1)
   {
      c = fgetc(fp);
      if (feof(fp))
      {
         break;
      }
      printf("%c", c);
   }

   fclose(fp);
}

/**
 * 得到文件的大小
 */
int getFileSize()
{
   char filename[256];
   getFileName(filename);
   int size;
   FILE *fp;
   fp = fopen(filename, "r");
   fseek(fp, 0, SEEK_END);
   size = ftell(fp);
   fclose(fp);
   return size;
}

int main()
{

   //writeFile();
   readFile();
   printf("%d\n", getFileSize());
   printf("--------------------\n");
   return 0;
}