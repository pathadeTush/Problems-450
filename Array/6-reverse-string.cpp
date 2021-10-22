string reverseWord(string str)
{

    for (int i = 0, j = str.length() - 1; i < j; i++, j--)
        swap(str[i], str[j]);

    return str;
}