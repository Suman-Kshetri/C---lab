st STRING& another)
    {
        length=another.length;
        string=new char[length+1];
        strcpy(string,another.string);
    }