/*
请实现一个函数，将一个字符串中的空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/
class RepalceSpace{
    public String replceSpace(StringBuffer str){
        if(str == null) return null;
        int originalLen = str.length();
        for(int i = 0; i < originalLen; i++)
            if(str.charAt(i) == ' ')
                str.append(' ');
        int newLen = str.length();
        int indexOfOriginal = originalLen - 1;
        int indexOfNew = newLen - 1;
        while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal){
            if(str.charAt(indexOfOriginal) == ' '){
                str.setCharAt(indexOfNew --, '0');
                str.setCharAt(indexOfNew --, '2');
                str.setCharAt(indexOfNew --, '%');
            }
            else{
                str.setCharAt(indexOfNew--, str.charAt(indexOfOriginal));
            }
            -- indexOfOriginal;
        }
        return str.toString();
    }
    /*
    public String replceSpace_2(StringBuffer str){
        if(str == null) return null;
        int originalLen = str.length();
        int spaceNum = 0;
        for(int i = 0; i < originalLen; i++)
            if(str.charAt(i) == ' ')
                spaceNum ++;
        int newLen = ( originalLen + spaceNum*2 ) -1;
        str.setLength(newLen);
        int indexOfOriginal = originalLen - 1;
        int indexOfNew = newLen - 1;
        while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal){
            if(str.charAt(indexOfOriginal) == ' '){
                str.setCharAt(indexOfNew --, '0');
                str.setCharAt(indexOfNew --, '2');
                str.setCharAt(indexOfNew --, '%');
            }
            else{
                str.setCharAt(indexOfNew--, str.charAt(indexOfOriginal));
            }
            -- indexOfOriginal;
        }
        return str.toString();
    }
    */
}

