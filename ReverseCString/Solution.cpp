/* Reverse a c style string in place */

class Solution
{
    void reverse(char* str)
    {
       if ( *str == '\0')
       {
            return;
       }
       char* end = str;
       while( *end != '\0')
       {
            ++end;
       }
       //end points to \0
       --end;
       char tmp;
       while (str < end) 
       {//swap head & end 
            tmp = *str;
            *str = *end;
            *end = tmp;
            --end;
            ++str; 
       }
    
    }
}


