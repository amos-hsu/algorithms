/*
请实现一个函数，将一个字符串中的空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/
/*
特殊测试用例：
空字符串：nullptr  空字符串  只有一个空格  连续多个空格
*/
void replaceSpace(char string[], int length)
{
    if(string==nullptr || length<=0)
        return;
    int originalLen = 0;
    int numOfBlank = 0;
    for(int i=0; string[i]!='\0'; i++)
    {
        ++ originalLen;
        if(string[i] == ' ')
            ++ numOfBlank;
    }
    int newLen = originalLen + numOfBlank*2;
    if(newLen > length)
        return;
    int indexOfOriginal = originalLen;
    int indexOfNew = newLen;
    while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
    {
        if(string[indexOfOriginal] != ' ')
        {
            string[indexOfNew --] = string[indexOfOriginal];
        }
        else
        {
            string[indexOfNew --] = '0';
            string[indexOfNew --] = '2';
            string[indexOfNew --] = '%';
        } 
        -- indexOfOriginal;
    }

}