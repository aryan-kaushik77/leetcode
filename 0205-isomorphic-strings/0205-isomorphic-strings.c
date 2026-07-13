
bool isIsomorphic(char* s, char* t) {
    char mapST[256] = {0};
    char mapTS[256] = {0};

    for(int i = 0; s[i] != '\0'; i++)
    {
        int h1 = (unsigned char)s[i] % 256;
        int h2 = (unsigned char)t[i] % 256;

        if(mapST[h1] == 0 && mapTS[h2] == 0)
        {
            mapST[h1] = t[i];
            mapTS[h2] = s[i];
        }
        else if(mapST[h1] != t[i] || mapTS[h2] != s[i])
        {
            return false;
        }
    }
    return true;
}