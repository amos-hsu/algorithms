/**
 * 方法一：正向逻辑，匹配则出栈，需要将所有字符都遍历一遍。
 * - 元素个数为偶数
 * - 栈为空且为左括号，入栈
 * - 栈不为空时，为右括号且与上一个元素匹配则出栈
 * - 以上条件都不符合，入栈
 * 最后栈为空则匹配成功。
 * */

bool isValid(char * s){
    if (s == NULL || strlen(s) == 0) return true;
    if (strlen(s) % 2 == 1) return false;  // 边界条件
    char stack[strlen(s)];
    int i, top = -1;
    for (i = 0; s[i] != '\0'; i++) {
        if (top == -1 && (s[i] == '(' || s[i] == '{' || s[i] == '[')) {
            stack[++top] = s[i];
            continue;
        }
        if (top > -1 && s[i] == ')' && stack[top] == '(') {
            top--;
            continue;
        }
        if (top > -1 && s[i] == ']' && stack[top] == '[') {
            top--;
            continue;
        }
        if (top > -1 && s[i] == '}' && stack[top] == '{') {
            top--;
            continue;
        }
        stack[++top] = s[i];
    }
    if (top == -1) return true;
    return false;
}
/**
 * 方法二：反向逻辑，出现不匹配则退出
 * - 右括号，栈为空 || 与栈顶元素不匹配，退出；否则入栈
 * - 最后栈为空则匹配成功
 * */
bool isValid(char * s){
    if (s == NULL || strlen(s) == 0) return true;
    if (strlen(s) % 2 == 1) return false;  // 边界条件
    char stack[strlen(s)];
    int i, top = -1;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == '}' || s[i] == ']' || s[i] == ')') {
            if (top == -1) return false;
            if (s[i] == ')' && stack[top] != '(') return false;
            if (s[i] == ']' && stack[top] != '[') return false;
            if (s[i] == '}' && stack[top] != '{') return false;
            top--;
        } else {
            stack[++top] = s[i];
        }
    }
    return (top == -1) ? true : false;
}

/**
 * 进一步优化：
 * 左括号入栈
 * 右括号，栈为空，则不匹配返回;
 *        栈不为空，则判断栈顶元素是否匹配，不匹配则返回false
 **/
bool isValid(char * s){
    if (s == NULL || strlen(s) == 0) return true;
    if (strlen(s) % 2 == 1) return false;
    int stack[strlen(s)];
    int top = -1;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        } else {
            if (top == -1) {
                return false;
            } 
            if ((s[i] == ')' && stack[top] == '(') ||
                (s[i] == ']' && stack[top] == '[') ||
                (s[i] == '}' && stack[top] == '{')) {
                top--;
                continue;
            }
            return false;
        }
    }
    return (top == -1) ? true : false;
}
