void reverse(char *start,char *end)
{
    while(end > start)
    {
        char temp = *start;
        (*start) = (*end);
        (*end) = temp;
        start++;
        end--;
    }
}

void reverseWords(char *s) {
    
    int i = 0;
    int j = 0;
    int size = strlen(s);
    while(i < size) {
        while(i < size && s[i] == ' ')
            i++;
        if (i < size && j > 0)
            s[j++] = ' ';
        int start = j;
        while(i < size && s[i] != ' ') {
            s[j++] = s[i++];
        }
        reverse(s + start, s + j - 1);
    }
    s[j] = '\0';
    reverse(s, s + j - 1);
}