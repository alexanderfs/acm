/*
ʵ��һ���ַ�����ĸ�ֵ���� 


*/
	

	
class CMyString {
public:
	CMyString(char * pData = NULL);
	CMyString(const CMyString &cms);
	~CMyString(void);
	
private:
	char *m_pData;
};


CMyString &CMyString::operator=(const CMyString &cms) 