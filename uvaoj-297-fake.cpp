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

// 四叉树树, 每个图片都可以被切分成4部分 2 1 , 直至某一块颜色完全相同, 就不再切分
//                                       3 4 
// 一个图片为 32*32 共 1024 pixels, 用黑色块占总色块的总数, 即可算出黑色块所占的 pixels
// 两个图片叠加, 只要有一部分是黑的, 总体就是黑的
// 如果一个节点没的子节点都是同样颜色的, 那么就不需要拆分成4个子节点
// 直接以 parent 节点的颜色代表即可
// 两个图片相加后, 输出黑色 pixels 的个数


const int PIX_NUM = 1024;
const int CHILD_NUM = 4;

// 获取黑色块的个数, 即被标为 f 的块
int getBlackNum(char* image1, char* image2) {
  int cnt = 0;
  for (int i=0; i<PIX_NUM; i++) {
    if (image1[i] == 'f' || image2[i] == 'f') ++cnt;
  }
  return cnt;
}

// 在 image[indexStartImg, indexEndImg) 之间根据 line 
// 从 indexStr 处开始的符号进行标色
// 返回值就是执行操作完之后 line 下一步操作的 index
int markPixels(char* image, int indexStartImg, int indexEndImg, 
               const string& line, int indexStr) {
  if (indexStr >= line.size()) return indexStr;

  // 如果不是 p, 则说明是单一色, 则把这一段全部标成它的颜色
  if (line[indexStr] == 'e' || line[indexStr] == 'f') {
    memset(image + indexStartImg, 
           line[indexStr], 
           (indexEndImg-indexStartImg) * sizeof(line[indexStr]));
    return indexStr + 1;
  }

  // line[indexStr] == 'p', 分 4 段进行操作
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

  // 存放 image 的所有像素, 'e' 代表空白, 'f' 表代黑色
  char image1[PIX_NUM];
  char image2[PIX_NUM];

  string line1;
  string line2;
  while (numCase--) {
    getline(cin, line1);
    getline(cin, line2);

    memset(image1, '\0', sizeof(image1));
    memset(image2, '\0', sizeof(image2));

    // 对两个图像分别标色
    markPixels(image1, 0, PIX_NUM, line1, 0);
    markPixels(image2, 0, PIX_NUM, line2, 0);

    // 计算, 输出黑色像素点个数
    int num = getBlackNum(image1, image2);
    printf("There are %d black pixels.\n", num);

  }

  return 0;
}