# include <iostream>
# include <string>
# include <cstdio>
# include <cstring>
# include <vector>
# include <algorithm>
# include <cctype>
# include <iterator>
# include <sstream>
# include <assert.h>
# include <limits>
using namespace std;

// �Ĳ�����, ÿ��ͼƬ�����Ա��зֳ�4���� 2 1 , ֱ��ĳһ����ɫ��ȫ��ͬ, �Ͳ����з�
//                                       3 4 
// һ��ͼƬΪ 32*32 �� 1024 pixels, �ú�ɫ��ռ��ɫ�������, ���������ɫ����ռ�� pixels
// ����ͼƬ����, ֻҪ��һ�����Ǻڵ�, ������Ǻڵ�
// ���һ���ڵ�û���ӽڵ㶼��ͬ����ɫ��, ��ô�Ͳ���Ҫ��ֳ�4���ӽڵ�
// ֱ���� parent �ڵ����ɫ������
// ����ͼƬ��Ӻ�, �����ɫ pixels �ĸ���


const int PIX_NUM = 1024;
const int CHILD_NUM = 4;

// ��ȡ��ɫ��ĸ���, ������Ϊ f �Ŀ�
int getBlackNum(char* image1, char* image2) {
  int cnt = 0;
  for (int i=0; i<PIX_NUM; i++) {
    if (image1[i] == 'f' || image2[i] == 'f') ++cnt;
  }
  return cnt;
}

// �� image[indexStartImg, indexEndImg) ֮����� line 
// �� indexStr ����ʼ�ķ��Ž��б�ɫ
// ����ֵ����ִ�в�����֮�� line ��һ�������� index
int markPixels(char* image, int indexStartImg, int indexEndImg, 
               const string& line, int indexStr) {
  if (indexStr >= line.size()) return indexStr;

  // ������� p, ��˵���ǵ�һɫ, �����һ��ȫ�����������ɫ
  if (line[indexStr] == 'e' || line[indexStr] == 'f') {
    memset(image + indexStartImg, 
           line[indexStr], 
           (indexEndImg-indexStartImg) * sizeof(line[indexStr]));
    return indexStr + 1;
  }

  // line[indexStr] == 'p', �� 4 �ν��в���
  int segmentLength = (indexEndImg - indexStartImg) / CHILD_NUM;
  int index = indexStr + 1;
  for (int i=0; i<CHILD_NUM; i++) {
    index = markPixels(image, indexStartImg + i*segmentLength,
                       indexStartImg + (i+1)*segmentLength, line, index);
  }

  return index;
} 

int main(int argc, char const *argv[])
{

    freopen("test_input.txt", "r", stdin);  
//    freopen("uva_o.txt", "w", stdout); 
  
  
  int numCase;
  cin >> numCase;
  cin.ignore();

  // ��� image ����������, 'e' ����հ�, 'f' �����ɫ
  char image1[PIX_NUM];
  char image2[PIX_NUM];

  string line1;
  string line2;
  while (numCase--) {
    getline(cin, line1);
    getline(cin, line2);

    memset(image1, '\0', sizeof(image1));
    memset(image2, '\0', sizeof(image2));

    // ������ͼ��ֱ��ɫ
    markPixels(image1, 0, PIX_NUM, line1, 0);
    markPixels(image2, 0, PIX_NUM, line2, 0);

    // ����, �����ɫ���ص����
    int num = getBlackNum(image1, image2);
    printf("There are %d black pixels.\n", num);

  }

  return 0;
}