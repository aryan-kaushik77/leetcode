char *temp = malloc(2 * len + 1);
strcpy(temp, s);
strcat(temp, s);

return strstr(temp, goal) != NULL;